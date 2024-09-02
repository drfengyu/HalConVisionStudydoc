#include "stdafx.h"
#include "AlgorithmModule.h"
#include <stdlib.h>
#include <fstream>
#include "ErrorCodeDefine.h"
#include "iMVS-6000PixelFormatDefine.h"


CAlgorithmModule::CAlgorithmModule()
{
	//======�Զ��������ʼ��======//
}

CAlgorithmModule::~CAlgorithmModule()
{

}

int CAlgorithmModule::Init()
{

	int nRet = VM_M_GetModuleId(m_hModule, &m_nModuleId);
	if (IMVS_EC_OK != nRet)
	{
		m_nModuleId = -1;
		return nRet;
	}

	nRet = ResetDefaultParam();
	if (nRet != IMVS_EC_OK)
	{
		OutputDebugStringA("###Call ResetDefaultParam failed.");
	}

	return nRet;
}

int CAlgorithmModule::Process(IN void* hInput, IN void* hOutput, IN MVDSDK_BASE_MODU_INPUT* modu_input)
{
	OutputDebugStringA("###Call CAlgorithmModule::Proces -->begin\n");
	int nErrCode = 0;

// 1.��ȡ����
	
	/************************************************/

	//ToDo Code...............

	/************************************************/

// 2.�㷨����
	OutputDebugStringA("###Call CAlgorithmModule::Proces --> do algorighm process\n");

	/************************************************/

	//ToDo Code...............

	/************************************************/


// 3.������
	
	/************************************************/

	//ToDo Code...............

    //���ͼ��(��Ⱦ�ؼ�ֻ����ʾ�����ڴ��е�ͼ������)
        //char* pSharedName = NULL;
        //HKA_IMAGE stImage;
        //stImage.height = heightValue;
        //stImage.width = widthValue;
        //stImage.step[0] = widthValue;
        //int nRet = AllocateSharedMemory(m_nModuleId, stImage.height*stImage.width, (char**)(&stImage.data), &pSharedName);
        //if (nRet == IMVS_EC_OK && stImage.data != NULL)
        //{
        //    memcpy_s(......);
        //    VmModule_OutputImageByName_8u_C1R(hOutput, 
		//		  status, 
		//		  OUTIMAGE, 
		//		  OUTIMAGEWIDTH, 
		//		  OUTIMAGEHEIGHT, 
		//		  OUTIMAGEPIXELFORMAT, 
		//		  &stImage, 
		//		  0, 
		//		  pSharedName);
        //}


	/************************************************/

	if (nErrCode != IMVS_EC_OK)
	{
		return IMVS_EC_PARAM;
	}

	/************************************************/
	//Ĭ���㷨ʱ��20ms������ʵ��ʱ�����
	MODULE_RUNTIME_INFO struRunInfo = { 0 };
	struRunInfo.fAlgorithmTime = 20;
	VM_M_SetModuleRuntimeInfo(m_hModule, &struRunInfo);

	OutputDebugStringA("###Call CAlgorithmModule::Proces end\n");

	return IMVS_EC_OK;
}


int CAlgorithmModule::GetParam(IN const char* szParamName, OUT char* pBuff, IN int nBuffSize, OUT int* pDataLen)
{
	OutputDebugStringA("###Call CAlgorithmModule::GetParam");

	int nMsgLen = 0;
	int nErrCode = IMVS_EC_OK;
	if (szParamName == NULL || strlen(szParamName) == 0 || pBuff == NULL || nBuffSize <= 0 || pDataLen == NULL)
	{
		return IMVS_EC_PARAM;
	}
 	//memset(pBuff, 0, nBuffSize);
	
	//======�Զ���GetParam start======//
	//if(0 == strcmp(szParamName, "paramA"))
	//{
	//	  sprintf(pBuff, nBuffSize, "", ..);
	//}
	
	return nErrCode;
}

int CAlgorithmModule::SetParam(IN const char* szParamName, IN const char* pData, IN int nDataLen)
{
	OutputDebugStringA("###Call CAlgorithmModule::SetParam");

	int nErrCode = IMVS_EC_OK;
	if (szParamName == NULL || strlen(szParamName) == 0 || pData == NULL || nDataLen == 0)
	{
		return IMVS_EC_PARAM;
	}

	//======�Զ���SetParam start======//

	return nErrCode;
}


/////////////////////////////ģ���뵼���Ľӿڣ�ʵ�ֿ�ʼ��//////////////////////////////////////////

LINEMODULE_API CAbstractUserModule* __stdcall CreateModule(void* hModule)
{
	assert(hModule != NULL);
   

	// �����û�ģ�飬����¼ʵ����
	CAlgorithmModule* pUserModule = new(nothrow) CAlgorithmModule;

	if (pUserModule == NULL)
	{
		return NULL;
	}

	pUserModule->m_hModule = hModule;

	int nRet = pUserModule->Init();
	if (IMVS_EC_OK != nRet)
	{
		delete pUserModule;
		return NULL;
	}

	OutputDebugStringA("###Call CreateModule");

	return pUserModule;
}


LINEMODULE_API void __stdcall DestroyModule(void* hModule, CAbstractUserModule* pUserModule)
{
	assert(hModule != NULL);
	OutputDebugStringA("###Call DestroyModule");

	if (pUserModule != NULL)
	{
		delete pUserModule;
	}
}
/////////////////////////////ģ���뵼���Ľӿڣ�ʵ�ֽ�����//////////////////////////////////////////
//////======�ļ�β======//