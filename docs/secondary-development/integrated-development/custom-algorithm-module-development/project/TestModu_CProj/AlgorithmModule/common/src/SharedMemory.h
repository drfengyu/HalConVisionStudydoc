/************************************************************************
* ��Ȩ��Ϣ����Ȩ����(c) 2020, ���ݺ��������˼������޹�˾.��������Ȩ��.
*
* �ļ����ƣ�SharedMemory.h
* ժ   Ҫ:  ֧�ֿ�ƽ̨���������ڴ����ݡ�
*
* ��   ��:  fenghuapeng5
* ��   �ڣ� 2020-09-18
* ��   ע�� Ϊ�˼򻯽ӿڶ��壬Ĭ�϶���RWȨ�޴�����򿪹����ڴ档
************************************************************************/

#ifndef _SHARED_MEMORY_H_
#define _SHARED_MEMORY_H_

#include <string>
#ifdef _WIN32
#define SHM_HANDLE HANDLE
#define INVALID_SHM_HANDLE NULL

#ifndef SYSTEM_ERROR
#define SYSTEM_ERROR     GetLastError()
#endif//SYSTEM_ERROR
typedef unsigned __int64         SHM_uint64;
#else
#define SHM_HANDLE int
#define INVALID_SHM_HANDLE -1
#ifndef SYSTEM_ERROR
#define SYSTEM_ERROR     errno
#endif//SYSTEM_ERROR
typedef unsigned long long       SHM_uint64;
#endif

#ifdef _UNICODE
typedef  wchar_t  SHM_tchar;
#else
typedef  char     SHM_tchar;
#endif

//�����ڴ�ͷ����
#define   SHARED_MEMORY_HEADER_LEN    16

// ����������еĹ����ڴ棬�����ɹ�ʱ����ӳ������ʧ��ʱ����INVALID_SHM_HANDLE
SHM_HANDLE SHM_CreateMapping(const char* pName, size_t nMappingLen);
SHM_HANDLE SHM_OpenMapping(const char* pName);

// ӳ�����ڴ����򣬲����ɹ�ʱ����ӳ���ַ��ʧ��ʱ����NULL
void* SHM_WriteMapView(SHM_HANDLE hMapping, size_t nMappingLen);
void* SHM_ReadMapView(SHM_HANDLE hMapping);

// ȡ���ڴ�ӳ�䡢�ر�ӳ�����������ɹ�ʱ����0��ʧ��ʱ���ض�Ӧ��ϵͳ������
int SHM_UnMapView(void* pView, size_t nMappingLen);
int SHM_CloseReadMapping(SHM_HANDLE hMapping);
//�رն���Դ
void SHM_CloseReadShm(SHM_HANDLE& hMapping, void*& pBuffView);

//ɾ�������ڴ�
int SHM_DestroyWriteMapping(SHM_HANDLE hMapping, const char* pName);

//����д��Դ
void SHM_DestroyWriteShm(SHM_HANDLE& hMapping, void*& pBuffView, const char* pShmName/* = NULL*/);

//�����ڴ�ת����
int SharedMemory2Data(const std::string& strSm, std::string& strData);

//�����ڴ��е�����д���ļ�
int ShareMemory2File(const char* pszShareMemName, const SHM_tchar* pszFileName, bool bFlush = true);


//�ļ�ת�����ڴ�
int File2ShareMemory(const SHM_tchar* pszFileName, const char* strShareMemName, SHM_HANDLE& hMapping, void*& pBuffView);

//����д�빲���ڴ�
int Data2ShareMemory(const char* pData, const size_t nSize, const char* strShareMemName, SHM_HANDLE& hMapping, void*& pBuffView);



#endif
