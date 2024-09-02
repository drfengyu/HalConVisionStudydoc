#if (defined _WIN32 || defined _WIN64)
#define WIN32_LEAN_AND_MEAN  //���winsock.h��winsock2.h�����ض�������
#include <Windows.h>
#include <tchar.h>
#else
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#endif
#include "SharedMemory.h"
#include "HSlog/HSlog.h"
#include <io.h>
#include "ErrorCodeDefine.h"
#include "string.h"

#ifdef _UNICODE
    #define _T(x) L##x
#else
	#define _T(x) x
#endif

#pragma warning(disable:4996)
/** @fn:    SHM_CreateMapping
* @brief:   ���������ڴ�
* @param:   const char * pName   �����ڴ�����
* @param:   int nMappingLen      �����ڴ泤��
* @return:  SHM_HANDLE �����ڴ���
*/
SHM_HANDLE SHM_CreateMapping(const char* pName, size_t nMappingLen)
{
	SHM_HANDLE hMapping = INVALID_SHM_HANDLE;
    if (nMappingLen <= 0)
    {
        return hMapping;
    }
#ifdef _WIN32
    DWORD dLow = (DWORD)(nMappingLen & 0xffffffff);
    DWORD dHigh = (DWORD)(nMappingLen >> 32);
    hMapping = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, dHigh, dLow, pName);
    //nError = GetLastError();
#else
	hMapping = shm_open(pName, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	int nRet = ftruncate(hMapping, nMappingLen);
    //nError = errno;
    if (IMVS_EC_OK != nRet)
    {
        SHM_DestroyWriteMapping(hMapping, pName);
        return INVALID_SHM_HANDLE;
    }
#endif
	return hMapping;
}


/** @fn:    SHM_OpenMapping
* @brief:   �򿪹����ڴ�
* @param:   const char * pName  �����ڴ�����
* @return:  SHM_HANDLE �����ڴ���
*/
SHM_HANDLE SHM_OpenMapping(const char* pName)
{
	SHM_HANDLE hMapping = INVALID_SHM_HANDLE;
#ifdef _WIN32
	hMapping = OpenFileMappingA(FILE_MAP_ALL_ACCESS, 0, pName);
#else
	hMapping = shm_open(pName, O_RDWR, S_IRUSR | S_IWUSR);
#endif
	return hMapping;
}


/** @fn:    SHM_WriteMapView
* @brief:   д�����ڴ�ʱ����ȡӳ��ָ��
* @param:   SHM_HANDLE hMapping   �����ڴ���
* @param:   int nMappingLen       ӳ�䳤��
* @return:  void* ӳ��ָ��
*/
void*  SHM_WriteMapView(SHM_HANDLE hMapping, size_t nMappingLen)
{
	void* pView = NULL;
#ifdef _WIN32
	pView = MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
#else
	pView = mmap(NULL, nMappingLen, PROT_READ | PROT_WRITE, MAP_SHARED, hMapping, 0);
#endif
	return pView;
}

/** @fn:    SHM_ReadMapView
* @brief:   ������ʱ����ȡӳ��ָ��
* @param:   SHM_HANDLE hMapping
* @return:  void* ӳ��ָ��
*/
void*  SHM_ReadMapView(SHM_HANDLE hMapping)
{
    void* pView = NULL;
#ifdef _WIN32
    pView = MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
#else
    //1��Linux�ȶ�һ��ͷ�ĳ���
    pView = mmap(NULL, SHARED_MEMORY_HEADER_LEN, PROT_READ, MAP_SHARED, hMapping, 0);
    SHM_uint64 nTotalLen = *((SHM_uint64 *)pView) + SHARED_MEMORY_HEADER_LEN;//��Ҫ����ͷ
    size_t nLen = (size_t)nTotalLen;
    int nRet = SHM_UnMapView(pView, SHARED_MEMORY_HEADER_LEN);
    if (0 != nRet)
    {
        return NULL;
    }
    //2��Linux�����Ȼ�ȡӳ��ָ��
    pView = mmap(NULL, nLen, PROT_READ, MAP_SHARED, hMapping, 0);
    if (NULL == pView)
    {
        LOG_ERROR("mmap fail, error[%d]", SYSTEM_ERROR);
    }
#endif
    return pView;
}


/** @fn:    SHM_UnMapView
* @brief:   ȡ��ӳ��
* @param:   void * pView
* @param:   int nMappingLen
* @return:  int �ɹ�����0�����󷵻�����ֵ
*/
int SHM_UnMapView(void* pView, size_t nMappingLen)
{
    if (NULL == pView)
    {
        return 0;
    }
	int nRst = 0;
#ifdef _WIN32
	if (!UnmapViewOfFile(pView))
	{
		nRst = GetLastError();
	}
#else
	if (munmap(pView, nMappingLen) != 0)
	{
		nRst = errno;
	}
#endif
	return nRst;
}


/** @fn:    SHM_CloseMapping
* @brief:   �رչ����ڴ���
* @param:   SHM_HANDLE hMapping
* @param:   const char * pName
* @return:  int �ɹ�����0�����󷵻�����ֵ
*/
int SHM_CloseReadMapping(SHM_HANDLE hMapping)
{
    if (INVALID_SHM_HANDLE == hMapping)
    {
        return 0;
    }
	int nRst = 0;
#ifdef _WIN32
	if (!CloseHandle(hMapping))
	{
		nRst = GetLastError();
	}
#else
    close(hMapping);
#endif
	return nRst;
}

//�رն���Դ
void SHM_CloseReadShm(SHM_HANDLE& hMapping, void*& pBuffView)
{
#if (defined _WIN32 || defined _WIN64)
    if (pBuffView != NULL)
    {
        UnmapViewOfFile(pBuffView);
        pBuffView = NULL;
    }

    if (hMapping != NULL)
    {
        CloseHandle(hMapping);
        hMapping = NULL;
    }
#else
    if (pBuffView != NULL)
    {
        SHM_uint64 nImageLenTmp = *((SHM_uint64 *)pBuffView) + SHARED_MEMORY_HEADER_LEN;
        size_t nImageLen = (size_t)nImageLenTmp;
        SHM_UnMapView(pBuffView, nImageLen);
        pBuffView = NULL;
    }

    if (INVALID_SHM_HANDLE != hMapping)
    {
        SHM_CloseReadMapping(hMapping);
        hMapping = INVALID_SHM_HANDLE;
    }
#endif
}

//ɾ�������ڴ�
int SHM_DestroyWriteMapping(SHM_HANDLE hMapping, const char* pName)
{
    int nRst = 0;
#ifdef _WIN32
    if (!CloseHandle(hMapping))
    {
        nRst = GetLastError();
    }
#else
    if (shm_unlink(pName) == 0)
    {
        close(hMapping);
    }
    else
    {
        nRst = errno;
    }
#endif
    return nRst;
}



//����д��Դ
void SHM_DestroyWriteShm(SHM_HANDLE& hMapping, void*& pBuffView, const char* pShmName/* = NULL*/)
{
#if (defined _WIN32 || defined _WIN64)
    if (pBuffView != NULL)
    {
        UnmapViewOfFile(pBuffView);
        pBuffView = NULL;
    }

    if (hMapping != NULL)
    {
        CloseHandle(hMapping);
        hMapping = NULL;
    }
#else
    if (pBuffView != NULL)
    {
        SHM_uint64 nImageLenTmp = *((SHM_uint64 *)pBuffView) + SHARED_MEMORY_HEADER_LEN;
        size_t nImageLen = (size_t)nImageLenTmp;
        SHM_UnMapView(pBuffView, nImageLen);
        pBuffView = NULL;
    }

    if (INVALID_SHM_HANDLE != hMapping)
    {
        SHM_DestroyWriteMapping(hMapping, pShmName);
        hMapping = INVALID_SHM_HANDLE;
    }
#endif
}


int SharedMemory2Data(const std::string& strSm, std::string& strData)
{
	//���ļ�ӳ��
	SHM_HANDLE hFileMapping = SHM_OpenMapping(strSm.c_str());
	if (INVALID_SHM_HANDLE == hFileMapping)
	{
		LOG_ERROR("SharedMemory2Data fail, OpenFileMapping error[%d]", SYSTEM_ERROR);
		return IMVS_EC_RESOURCE_CREATE;
	}

	//ӳ����ͼ����ù����ڴ��ַ
	void * hMapView = SHM_ReadMapView(hFileMapping);
	if (NULL == hMapView)
	{
		LOG_ERROR("SharedMemory2Data fail, MapViewOfFile error[%d]", SYSTEM_ERROR);
		if (INVALID_SHM_HANDLE != hFileMapping)
		{
			SHM_CloseReadMapping(hFileMapping);
		}
		return IMVS_EC_RESOURCE_CREATE;
	}

	//�ӹ����ڴ濽������
    SHM_uint64 nImageLenTmp = *((SHM_uint64 *)hMapView);
    size_t nImageLen = nImageLenTmp;

	try
	{//��ֵ
		strData.assign((char *)hMapView + SHARED_MEMORY_HEADER_LEN, nImageLen);//�������쳣
	}
	catch (...)
	{
		LOG_ERROR("SharedMemory2Data catch exception.");
		if (hMapView)
		{
			SHM_UnMapView(hMapView, nImageLen);
			hMapView = NULL;
		}

		if (INVALID_SHM_HANDLE != hFileMapping)
		{
            SHM_CloseReadMapping(hFileMapping);
			hFileMapping = INVALID_SHM_HANDLE;
		}
		return IMVS_EC_OUTOFMEMORY;
	}


	if (hMapView)
	{
		SHM_UnMapView(hMapView, nImageLen);
		hMapView = NULL;
	}

	if (INVALID_SHM_HANDLE != hFileMapping)
	{
        SHM_CloseReadMapping(hFileMapping);
		hFileMapping = INVALID_SHM_HANDLE;
	}
	return IMVS_EC_OK;
}

//�����ڴ��е�����д���ļ�
int ShareMemory2File(const char* pszShareMemName, const SHM_tchar* pszFileName, bool bFlush/* = true*/)
{
	if (NULL == pszShareMemName || NULL == pszFileName)
	{
		return IMVS_EC_PARAM;
	}
	int nRet = IMVS_EC_OK;
	SHM_HANDLE hFileMapping = INVALID_SHM_HANDLE;
	void * hMapView = NULL;
	size_t nImageLen = 0;
	FILE* pFile = NULL;
	do
	{
		//���ļ�ӳ��
		hFileMapping = SHM_OpenMapping(pszShareMemName);
		if (INVALID_SHM_HANDLE == hFileMapping)
		{
			LOG_ERROR("ShareMemory2File fail, OpenFileMapping error[%d]", SYSTEM_ERROR);
			nRet = IMVS_EC_RESOURCE_CREATE;
			break;
		}

		//ӳ����ͼ����ù����ڴ��ַ
		hMapView = SHM_ReadMapView(hFileMapping);
		if (NULL == hMapView)
		{
			LOG_ERROR("ShareMemory2File fail, MapViewOfFile error[%d]", SYSTEM_ERROR);
			nRet = IMVS_EC_RESOURCE_CREATE;
			break;
		}

		//�ӹ����ڴ濽������
        SHM_uint64 nImageLenTmp = *((SHM_uint64 *)hMapView);
        nImageLen = (size_t)nImageLenTmp;
		char* pData = (char *)hMapView + SHARED_MEMORY_HEADER_LEN;//������ʼ��ַ
#if (defined _WIN32 || defined _WIN64)
		pFile = _tfopen(pszFileName, _T("wb"));
#else
		pFile = fopen(pszFileName, _T("wb"));
#endif
		if (NULL == pFile)
		{
			//LOG_ERROR("Open file[%s] fail, err[%d]", ToMultibyte(pszFileName).c_str(), SYSTEM_ERROR);
            LOG_ERROR("Open file fail, err[%d]", SYSTEM_ERROR);
			nRet = IMVS_EC_FILE_OPEN;
			break;
		}

		const size_t nOnceWriteLen = 16 * 1024;//ÿ��д���С
		size_t nDataLen = nImageLen;
		while (nDataLen > 0)
		{
			if (nDataLen < nOnceWriteLen)
			{
				if (nDataLen != fwrite(pData, 1, nDataLen, pFile))
				{
					//LOG_ERROR("fwrite[%s] fail, len[%lu] err[%d]", ToMultibyte(pszFileName).c_str(), nDataLen, SYSTEM_ERROR);
                    LOG_ERROR("fwrite fail, len[%lu] err[%d]", nDataLen, SYSTEM_ERROR);
                    nRet = IMVS_EC_FILE_SAVE;
					break;
				}
				else
				{
					//д������
					break;
				}
			}
			else
			{//ÿ��д��nOnceWriteLen
				if (nOnceWriteLen != fwrite(pData, 1, nOnceWriteLen, pFile))
				{
					//LOG_ERROR("fwrite[%s] fail, len[%lu] err[%d]", ToMultibyte(pszFileName).c_str(), nOnceWriteLen, SYSTEM_ERROR);
                    LOG_ERROR("fwrite fail, len[%lu] err[%d]", nOnceWriteLen, SYSTEM_ERROR);
                    nRet = IMVS_EC_FILE_SAVE;
					break;
				}
				else
				{
					nDataLen -= nOnceWriteLen;
					pData += nOnceWriteLen;
				}
			}//end else

		}//end while

		if (bFlush)
		{
			fflush(pFile);
#if (defined _WIN32 || defined _WIN64)
			//ȷ���ļ���ϵͳ������д�뵽�����ļ�
			_commit(_fileno(pFile));
#else
			::fsync(::fileno(pFile));
#endif
		}

	} while (0);

	if (hMapView)
	{
		SHM_UnMapView(hMapView, nImageLen);
		hMapView = NULL;
	}

	if (INVALID_SHM_HANDLE != hFileMapping)
	{
        SHM_CloseReadMapping(hFileMapping);
		hFileMapping = INVALID_SHM_HANDLE;
	}

	if (NULL != pFile)
	{
		fclose(pFile);
		pFile = NULL;
	}

	return nRet;
}



/** @fn     Data2ShareMemory()
*  @brief  ������д�빲���ڴ棬Ҫ��֤ÿ�ι����ڴ��������hMappingһ��
*  @return �ɹ�,����IMVS_EC_OK;ʧ��,���ش�����
*/
int Data2ShareMemory(const char* pData, const size_t nSize, const char* strShareMemName, SHM_HANDLE& hMapping, void*& pBuffView)
{
	int nRet = IMVS_EC_UNKNOWN;
	try
	{
		if ((NULL == pData) || (0 >= nSize) || (NULL == strShareMemName))
		{
			nRet = IMVS_EC_PARAM;
			throw nRet;
		}

		// Ԥ��
        const size_t CM_RESERVER_LEN = 0;

		// ӳ���ܳ���
		size_t nMappingLen = nSize + SHARED_MEMORY_HEADER_LEN + CM_RESERVER_LEN;

		SHM_DestroyWriteShm(hMapping, pBuffView, strShareMemName);

		// ��������ӳ��
		hMapping = SHM_CreateMapping(strShareMemName, nMappingLen);
		if (INVALID_SHM_HANDLE == hMapping)
		{
			LOG_ERROR("CreateFileMapping fail, Len[%d]. LastError:[%d]", nMappingLen, SYSTEM_ERROR);
			nRet = IMVS_EC_OPEN_FILEMAPPING;
			throw nRet;
		}

		// ӳ�乲�����򵽽�����
		pBuffView = SHM_WriteMapView(hMapping, nMappingLen);
		if (NULL == pBuffView)
		{
			LOG_ERROR("MapViewOfFile fail. LastError:[%d]", SYSTEM_ERROR);
			nRet = IMVS_EC_OPEN_FILEMAPPING;
			throw nRet;
		}

		// ǰ8�ֽ�Ϊ�㼯���ݴ�С
        *(SHM_uint64*)(pBuffView) = (SHM_uint64)nSize;
		// ������������
		memcpy((char*)pBuffView + SHARED_MEMORY_HEADER_LEN, pData, nSize);
	}
	catch (...)
	{
		LOG_ERROR("catch... nRet = [%x]", nRet);
		SHM_DestroyWriteShm(hMapping, pBuffView, strShareMemName);
		return nRet;
	}

	return IMVS_EC_OK;
}

int File2ShareMemory(const SHM_tchar* pszFileName, const char* strShareMemName, SHM_HANDLE& hMapping, void*& pBuffView)
{
	if ((NULL == pszFileName) || (NULL == strShareMemName))
	{
		return IMVS_EC_PARAM;
	}

	FILE* pFile = NULL;
	char* pBuffer = NULL;
	size_t nFileLen = 0;//�ļ�����
	size_t nReadLen = 0;//�ļ�����
	const size_t nOnceReadLen = 8 * 1024;//ÿ�ζ�ȡ����
#if (defined _WIN32 || defined _WIN64)
	pFile = _tfopen(pszFileName, _T("rb"));
#else
	pFile = fopen(pszFileName, _T("rb"));
#endif
	if (NULL == pFile)
	{
		//LOG_ERROR("Open file[%s] fail, err[%u]", ToMultibyte(pszFileName).c_str(), SYSTEM_ERROR);
        LOG_ERROR("Open file fail, err[%u]", SYSTEM_ERROR);
        return IMVS_EC_FILE_OPEN;
	}

	int nRet = IMVS_EC_OK;
	try
	{
		pBuffer = new(std::nothrow) char[nOnceReadLen];
		if (NULL == pBuffer)
		{
			LOG_ERROR("New buffer[%u] fail.", nOnceReadLen);
			nRet = IMVS_EC_OUTOFMEMORY;
			throw nRet;
		}

		SHM_DestroyWriteShm(hMapping, pBuffView, strShareMemName);

        //if (fseek(pFile, 0, SEEK_END) < 0)
#ifdef _WIN32
        if (_fseeki64(pFile, 0, SEEK_END) < 0)
#else
        if (fseeko64(pFile, 0, SEEK_END) < 0)
#endif
		{
			LOG_ERROR("SEEK_END fail[%u].", SYSTEM_ERROR);
			nRet = IMVS_EC_FILE_OPEN;
			throw nRet;
		}
		//nFileLen = ftell(pFile);//�ļ�����
#ifdef _WIN32
        nFileLen = _ftelli64(pFile);
#else
        nFileLen = ftello64(pFile);
#endif
		if (nFileLen < 0)
		{
			LOG_ERROR("ftell fail[%u].", SYSTEM_ERROR);
			nRet = IMVS_EC_FILE_OPEN;
			throw nRet;
		}

		//if (fseek(pFile, 0, SEEK_SET) < 0)
#ifdef _WIN32
        if (_fseeki64(pFile, 0, SEEK_SET) < 0)
#else
        if (fseeko64(pFile, 0, SEEK_SET) < 0)
#endif
		{
			LOG_ERROR("fseek SEEK_SET fail, error[%d].", SYSTEM_ERROR);
			nRet = IMVS_EC_FILE_OPEN;
			throw nRet;
		}

		// ���������ݴ��빲���ڴ�
		const size_t CM_RESERVER_LEN = 0;//Ԥ������

		// ӳ���ܳ���
		size_t nMappingLen = nFileLen + SHARED_MEMORY_HEADER_LEN + CM_RESERVER_LEN;
		// ��������ӳ��
		hMapping = SHM_CreateMapping(strShareMemName, nMappingLen);
		if (INVALID_SHM_HANDLE == hMapping)
		{
			LOG_ERROR("CreateFileMapping fail, Len[%d]. LastError:[%d]", nMappingLen, SYSTEM_ERROR);
			nRet = IMVS_EC_OPEN_FILEMAPPING;
			throw nRet;
		}

		// ӳ�乲�����򵽽�����
		pBuffView = SHM_WriteMapView(hMapping, nMappingLen);
		if (NULL == pBuffView)
		{
			LOG_ERROR("MapViewOfFile fail. LastError:[%d]", SYSTEM_ERROR);
			nRet = IMVS_EC_OPEN_FILEMAPPING;
			throw nRet;
		}

		// ǰ4�ֽ�Ϊ�㼯���ݴ�С
        *(SHM_uint64*)(pBuffView) = (SHM_uint64)nFileLen;
		char* pDestView = (char*)pBuffView + SHARED_MEMORY_HEADER_LEN;
		size_t nOffset = 0;

		do
		{
			nReadLen = fread(pBuffer, 1, nOnceReadLen, pFile);
			// ������������
			memcpy(pDestView + nOffset, pBuffer, nReadLen);
			nOffset += nReadLen;
		} while (nReadLen == nOnceReadLen && !feof(pFile));

		if (nFileLen != nOffset)
		{
			LOG_ERROR("File len[%d] read len[%d]", nFileLen, nOffset);
		}
	}
	catch (...)
	{
		LOG_ERROR("catch... nRet = [%x]", nRet);
		SHM_DestroyWriteShm(hMapping, pBuffView, strShareMemName);
	}

	if (NULL != pFile)
	{
		fclose(pFile);
	}

	if (NULL != pBuffer)
	{
		delete[] pBuffer;
	}

	return IMVS_EC_OK;
}



