/************************************************************************
* ��Ȩ��Ϣ����Ȩ����(c) 2018, ���ݺ��������˼������޹�˾.��������Ȩ��.
*
* �ļ����ƣ�VmModuleBase.h
* ժ   Ҫ:  �ӿڶ��壬�������Զ���ģ��ʹ�á�
*
* ��   ��:  fenghuapeng5
* ��   �ڣ� 2018-09-10

*************************************************************************/


/* �����Զ���ģ����֪��

1���Զ���ģ���Զ�̬�����ʽ���ڣ�.dll�ļ���
2��ģ�����ʵ���������������������ҵ���Լ��Ϊ __stdcall��
   a) CAbstractUserModule* __stdcall CreateModule(void* hModule);
   b) void __stdcall DestroyModule(void* hModule, CAbstractUserModule* pUserModule);
3��������C++���������ڹ������½� .def �ļ��������������ӵ����ӿ�������



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~�����ӿ�˵��~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * @fn     CreateModule
 * @brief  [����ʵ��] ����ģ��ʵ����ģ�鸺��ʵ�֣���SDK���á�
 * @param  hModule    ģ��ʵ�����
 * @remark �ýӿ���SDK���á�ͬһģ�鱻SDK���غ󣬿��ܻᴴ�����ʵ����hModule��ʾÿ��ʵ���ľ����
           �����Ʊ���þ��������SDK��ؽӿ�ʱ���õ���ֵ��

 CAbstractUserModule* __stdcall CreateModule(void* hModule);


 * @fn     DestroyModule
 * @brief  [����ʵ��] ����ģ��ʵ����ģ�鸺��ʵ�֣���SDK���á�
 * @param  hModule    ģ��ʵ�����
 * @param  pUserModule CreateModule���ص��û�ģ��ʵ��
 * @remark �ýӿ���SDK���á�ͬһģ�鱻SDK���غ󣬿��ܻᴴ�����ʵ������ĳ��ʵ����Ҫ����ʱ��SDK��
           ����ô˽ӿڣ�ʹ��ģ���л����ͷŸ�ʵ����ռ�õ���Դ��

 void __stdcall DestroyModule(void* hModule, CAbstractUserModule* pUserModule);



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ʾ��~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifdef __cplusplus
extern "C"
{
#endif

    // ����__stdcall����Լ����������.def�ļ������ӽӿ�������
    LINEMODULE_API CAbstractUserModule* __stdcall CreateModule(void* hModule);
    LINEMODULE_API void __stdcall DestroyModule(void* hModule, CAbstractUserModule* pUserModule);

#ifdef __cplusplus
};
#endif

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef _VM_MODULE_BASE_H_
#define _VM_MODULE_BASE_H_
#include "VmModuleDef.h"

#ifdef _WIN32
#ifdef  VMMODULEFRAME_EXPORTS
#    define VMMODULEFRAME_API __declspec(dllexport)
#else
#    define VMMODULEFRAME_API __declspec(dllimport)
#endif
#else
#    define VMMODULEFRAME_API  __attribute__((visibility("default")))
#    define __stdcall
#endif

class VMMODULEFRAME_API CAbstractUserModule
{
public:
	CAbstractUserModule();
	virtual ~CAbstractUserModule();

public:
	/** @fn     CAbstractUserModule::Process
     *  @brief  [����ʵ��] ����ģ��ҵ���߼���
     *  @param  hInput     ��ȡ������
     *  @param  hOutput    ����������
     *  @remark 1����ȡ���룬�μ�VM_M_GetString��VM_M_GetInt��VM_M_GetFloat��VM_M_GetImage��
                2������������μ�VM_M_SetString��VM_M_SetInt��VM_M_SetFloat��VM_M_SetImage��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	virtual int Process(IN void* hInput, IN void* hOutput) = 0;


    /** @fn     CAbstractUserModule::GetParam
     *  @brief  [��ѡʵ��]   ��ȡ����ֵ��Ĭ��ʵ�ֲ����κ����飬�򵥷��� IMVS_EC_NOT_IMPLEMENTED��
     *  @param  szParamName  ������
     *  @param  pBuff        ���������ָ��
     *  @param  nBuffSize    �����������С
     *  @param  pDataLen     ʵ�����ݳ���
     *  @remark ʵ��ʱ��ע�⣬��nBuffSize��Сʱ����������뷵��IMVS_EC_PARAM_BUF_LEN���ҽ�ʵ�ʴ�С��ֵ��pDataLen��
	            SDK����pDataLenָ���Ĵ�С���·���ռ䣬�ٴε��øýӿ�ȡֵ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	virtual int GetParam(IN const char* szParamName, OUT char* pBuff, IN int nBuffSize, OUT int* pDataLen);


    /** @fn     CAbstractUserModule::SetParam
     *  @brief  [��ѡʵ��]   ���ò���ֵ��Ĭ��ʵ�ֲ����κ����飬�򵥷��� IMVS_EC_NOT_IMPLEMENTED��
     *  @param  szParamName  ������
     *  @param  pData        ����
     *  @param  nDataLen     ���ݳ���
     *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	virtual int SetParam(IN const char* szParamName, IN const char* pData, IN int nDataLen);


	/** @fn     CAbstractUserModule::GetAllParamList
     *  @brief  [��ѡʵ��]   ��ȡ���йؼ��ֲ����б�ֵ��Ĭ��ʵ�ֲ����κ����飬�򵥷��� IMVS_EC_NOT_IMPLEMENTED��
     *  @param  pParamValueList  �����б�
     *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	virtual int GetAllParamList(OUT PARAM_VALUE_INFO_LIST* pParamValueList);


    /** @fn     CAbstractUserModule::SaveModuleData
     *  @brief  [��ѡʵ��] ����ģ�����ݣ�Ĭ��ʵ�ֻ���� GetAllParamList ��ȡ���в���ֵ�������������
	            SAVE_MODULE_DATA_PARAM->struModuleData->struParamValueList֮�С������ڱ��淽��ʱ���޸�
				�ؼ��ֲ������ݡ������ӱ�������ƿ����ݣ�����д�ú�����
     *  @param  pModuleData  ģ������

     *  @remark 1������pModuleData->struModuleData->struCustomUserData�����Ա�����������ݣ�
	            2������SAVE_MODULE_DATA_PARAM�еĳ�Ա pFnSigFinishedCallback����ʹ�õ�ǰSDK���øýӿڻ�
				ȡģ�����ݡ���ʹ�����ʱ���л���֪ͨģ��ò�������ɣ�ʹģ���л����ͷ���Դ��

     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	virtual int SaveModuleData(OUT SAVE_MODULE_DATA_PARAM* pModuleData);


    /** @fn     CAbstractUserModule::LoadModuleData
     *  @brief  [��ѡʵ��]  ����ģ�����ݣ�Ĭ��ʵ�ֲ����κβ�������������д�ú������Ի�ȡģ�����ݡ�
     *  @param  pModuleData ģ������
     
	 *  @remark �������д����Զ�����������ݣ�����д�ú��������������ݴ洢��
	            pModuleData->struModuleData->struCustomUserData�С�

     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	virtual int LoadModuleData(IN const LOAD_MODULE_DATA_PARAM* pModuleData);

public:
	void* m_hModule;   // ģ����, ����VM_M_ReportData��VM_M_TryRunProcedureOnce�Ƚӿ�ʱʹ��
};



#ifdef __cplusplus
extern "C" 
{
#endif 

	/** @fn     VM_M_GetString
     *  @brief  ��ȡ�����ַ�����
     *  @param  [IN]  hInput    ������
                [IN]  szName    ��������
				[IN]  nIndex    ��������
				[IN]  pBuff     ���������ָ��
				[IN]  nBuffLen  �����������С
				[OUT] pDataLen  ����ʵ�����ݴ�С
				[OUT] pCount    ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	 *  @remark ��������pBuff̫С��SDK���� IMVS_EC_PARAM_BUF_LEN����ʱ����pDataLenָ��Ĵ�С�����·���ռ䲢�ٴε��øýӿ�ȡֵ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_GetString(IN const void* hInput, IN const char* szName, IN int nIndex, 
		OUT char* pBuff, IN int nBuffLen, OUT int* pDataLen, OUT int* pCount);



    /** @fn     VM_M_GetInt
     *  @brief  ��ȡ��������ֵ
     *  @param  [IN]  hInput    ������
                [IN]  szName    ��������
				[IN]  nIndex    ��������
				[OUT] pValue    �������ָ��
				[OUT] pCount    ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	 *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_GetInt(IN const void* hInput, IN const char* szName, IN int nIndex, 
		OUT int* pValue, OUT int* pCount);



    /** @fn     VM_M_GetFloat
     *  @brief  ��ȡ���븡��ֵ
     *  @param  [IN]  hInput    ������
                [IN]  szName    ��������
				[IN]  nIndex    ��������
				[OUT] pValue    �������ָ��
				[OUT] pCount    ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	 *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_GetFloat(IN const void* hInput, IN const char* szName, IN int nIndex, 
		OUT float* pValue, OUT int* pCount);



	/** @fn     VM_M_GetImage
     *  @brief  ��ȡ����ͼ������
     *  @param  [IN]  hInput     ������
                [IN]  szName     ��������
				[IN]  nIndex     ��������
				[OUT] pImageData ͼ��������Ϣ��ͼ��������SDK����ռ䣬����ʱ�򵥴���IMAGE_DATA�սṹ�弴�ɡ�
				[OUT] pCount     ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	 *  @remark IMAGE_DATA �е�ͼ�����ݣ���SDK����ռ䣬�ⲿ����ʱ�뾡��ʹ�ã�process�˳�ʱSDK����ո�ͼ����ռ�ڴ档
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_GetImage(IN const void* hInput, IN const char* szName, IN int nIndex, 
		OUT IMAGE_DATA* pImageData, OUT int* pCount);


    /** @fn     VM_M_GetImageEx
     *  @brief  ��ȡ����ͼ������ָ��͹����ڴ��ʶ
     *  @param  [IN]  hInput     ������
                [IN]  szName     ��������
                [IN]  nIndex     ��������
                [OUT] pImageData ͼ��������Ϣ��ͼ��������SDK����ռ䣬����ʱ�򵥴���IMAGE_DATA�սṹ�弴�ɡ�
                [OUT] pCount     ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
     *  @remark IMAGE_DATA �е�ͼ�����ݣ���SDK����ռ䣬�ⲿ����ʱ�뾡��ʹ�ã�process�˳�ʱSDK����ո�ͼ����ռ�ڴ档
     *  @return �����룬�μ�ErrorCodeDefine.h
    */
    VMMODULEFRAME_API int __stdcall VM_M_GetImageEx(IN const void* hInput, IN const char* szName, IN int nIndex,
        OUT IMAGE_DATA_V2* pImageData, OUT int* pCount);


	/** @fn     VM_M_GetPointset
     *  @brief  ��ȡ����㼯���ݡ�����˽ӿ���Ҫ��Ϊ�˼��ݶ���̰汾sdk��pDataָ��ĵ㼯���ݽṹ���㷨ģ�鶨�壬
	            һ��ָ��IMVS_CONTOUR_POINT_INFO�ṹ�����顣
     *  @param  [IN]  hInput   ������
                [IN]  szName   ��������
				[IN]  nIndex   ��������
				[OUT] pData    �㼯����
				[OUT] nDataLen ���ݴ�С
				[OUT] pCount   ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	 *  @remark pData�е����ݣ���SDK����ռ䣬�ⲿ����ʱ�뾡��ʹ�ã�process�˳�ʱSDK����ոñ�����ռ�ڴ档
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_GetPointset(IN const void* hInput, IN const char* szName, IN int nIndex,
		OUT void** pData, OUT int* pDataLen, OUT int* pCount);


	/** @fn     VM_M_GetBytes
	 *  @brief  ��ȡ��������������
	 *  @param  [IN]  hInput   ������
	            [IN]  szName   ��������
	            [IN]  nIndex   ��������
	            [OUT] pData    ���������ݿ�ָ���ַ
	            [OUT] nDataLen ���ݴ�С
	            [OUT] pCount   ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark pData�е����ݣ���SDK����ռ䣬�ⲿ����ʱ�뾡��ʹ�ã�process�˳�ʱSDK����ոñ�����ռ�ڴ档
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetBytes(IN const void* hInput, IN const char* szName, IN int nIndex,
		OUT void** pData, OUT int* pDataLen, OUT int* pCount);


    /** @fn    VM_M_BatchGetString
    *  @brief  ������ȡ�����ַ�����
    *  @param  [IN]  hInput    ������
               [IN]  szName    ��������
               [OUT] pBuff     ���������ָ��
               [IN]  nBuffLen  �������������
               [IN]  pDataLen  ÿ�����������ȣ�����ÿ��������ʵ�ʳ���
               [OUT] pCount    �������ݵ�����������ֵС�ڻ�ȡ�����ݴ�С����ֻ�ܻ�ȡ��pCount����������
    *  @remark ��������pBuff̫С��SDK���� IMVS_EC_PARAM_BUF_LEN����ʱ����pBuffLenָ��Ĵ�С�����·���ռ䲢�ٴε��øýӿ�ȡֵ��
    *  @return �����룬�μ�ErrorCodeDefine.h
    */
    VMMODULEFRAME_API int __stdcall VM_M_BatchGetString(IN const void* hInput, IN const char* szName, OUT char** pBuff, 
        IN int nBuffCount, IN int* pBuffLen, OUT int* pCount);


    /** @fn    VM_M_BatchGetInt
    *  @brief  ������ȡ��������ֵ
    *  @param  [IN]  hInput    ������
               [IN]  szName    ��������
               [IN]  nCount    ��ȡ����
               [OUT] pValue    �������
               [OUT] pCount    �������ݵ�����������ֵС�ڻ�ȡ�����ݴ�С����ֻ�ܻ�ȡ��pCount����������
    *  @remark ��
    *  @return �����룬�μ�ErrorCodeDefine.h
    */
    VMMODULEFRAME_API int __stdcall VM_M_BatchGetInt(IN const void* hInput, IN const char* szName, IN int nCount,
        OUT int* pValue, OUT int* pCount);



    /** @fn    VM_M_BatchGetFloat
    *  @brief  ������ȡ���븡��ֵ
    *  @param  [IN]  hInput    ������
               [IN]  szName    ��������
               [IN]  nCount    ��������
               [OUT] pValue    �������
               [OUT] pCount    ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
               [OUT] pCount    �������ݵ�����������ֵС�ڻ�ȡ�����ݴ�С����ֻ�ܻ�ȡ��pCount����������
    *  @remark ��
    *  @return �����룬�μ�ErrorCodeDefine.h
    */
    VMMODULEFRAME_API int __stdcall VM_M_BatchGetFloat(IN const void* hInput, IN const char* szName, IN int nCount,
        OUT float* pValue, OUT int* pCount);



	/** @fn     VM_M_SetString
     *  @brief  ��������ַ�����
     *  @param  [IN]  hOutput     ������
                [IN]  szName      ��������
				[IN]  nIndex      ��������
				[IN]  pValue      ����ֵ������'\0'�ַ���β
	 *  @remark ��һ����������ܴ��ڶ��ֵ��������index����ֵʱ���Ḳ����ǰֵ������SDK���������������ֵ������б�ĩβ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_SetString(IN const void* hOutput, IN const char* szName, IN int nIndex, IN const char* pValue);



	/** @fn     VM_M_SetInt
     *  @brief  ���������������
     *  @param  [IN]  hOutput     ������
                [IN]  szName      ��������
				[IN]  nIndex      ��������
				[IN]  nValue      ����ֵ
	 *  @remark ��һ����������ܴ��ڶ��ֵ��������index����ֵʱ���Ḳ����ǰֵ������SDK���������������ֵ������б�ĩβ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_SetInt(IN const void* hOutput, IN const char* szName, IN int nIndex, IN int nValue);



	/** @fn     VM_M_SetFloat
     *  @brief  ���������������
     *  @param  [IN]  hOutput     ������
                [IN]  szName      ��������
				[IN]  nIndex      ��������
				[IN]  fValue      ����ֵ
	 *  @remark ��һ����������ܴ��ڶ��ֵ��������index����ֵʱ���Ḳ����ǰֵ������SDK���������������ֵ������б�ĩβ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_SetFloat(IN const void* hOutput, IN const char* szName, IN int nIndex, IN float fValue);

	/** @fn     VM_M_SetImage
     *  @brief  �������ͼ������
     *  @param  [IN]  hOutput     ������
                [IN]  szName      ��������
				[IN]  nIndex      ������������0
				[IN]  pImageData  ͼ������
	 *  @remark ͼ��֧�������ʽ�����nIndex��Ч����Ϊ0����
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_SetImage(IN const void* hOutput, IN const char* szName, IN int nIndex,
		IN const IMAGE_DATA* pImageData);

    /** @fn     VM_M_SetImageEx
    *  @brief  �������ͼ�������빲���ڴ�
    *  @param  [IN]  hOutput     ������
               [IN]  szName      ��������
               [IN]  nIndex      ������������0
               [IN]  pImageData  ͼ������
               [IN]  szSharedMemoryName �����ڴ�����
    *  @remark ͼ��֧�������ʽ�����nIndex��Ч����Ϊ0����
    *  @return �����룬�μ�ErrorCodeDefine.h
    */
    VMMODULEFRAME_API int __stdcall VM_M_SetImageEx(IN const void* hOutput, IN const char* szName, IN int nIndex,
        IN const IMAGE_DATA* pImageData, IN const char* szSharedMemoryName);

	/** @fn     VM_M_SetPointset
     *  @brief  ��������㼯���ݡ�����˽ӿ���Ҫ��Ϊ�˼��ݶ���̰汾sdk��pDataָ��ĵ㼯���ݽṹ���㷨ģ�鶨�壬
	            һ��ָ��IMVS_CONTOUR_POINT_INFO�ṹ�����顣
     *  @param  [IN]  hOutput  ������
                [IN]  szName   ��������
				[IN]  nIndex   ������������0
				[IN]  pData    �㼯����
				[IN]  nDataLen ���ݴ�С
	 *  @remark �㼯��֧�������ʽ�����nIndex��Ч����Ϊ0����
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_SetPointset(IN const void* hOutput, IN const char* szName, IN int nIndex,
		IN void* pData, IN int nDataLen);


	/** @fn     VM_M_SetBytes
	 *  @brief  ���ö������������
	 *  @param  [IN]  hOutput  ������
	            [IN]  szName   ��������
	            [IN]  nIndex   ������������0
	            [IN]  pData    ���������ݿ�ָ���ַ
	            [IN]  nDataLen ���ݴ�С
	*  @remark ���������ݲ�֧�������ʽ�����nIndex��Ч����Ϊ0����
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_SetBytes(IN const void* hOutput, IN const char* szName, IN int nIndex,
		IN void* pData, IN int nDataLen);



	/** @fn     VM_M_BatchSetString
     *  @brief  ��������ַ������ݣ�֧��ͬʱ���ö��ֵ
     *  @param  [IN]  hOutput     ������
                [IN]  szName      ��������
				[IN]  pArryValue  �ַ������飬�����char*ָ����ַ������飬����'\0'��β
				[IN]  nCount      �ַ����������������С
	 *  @remark ��ε���ʱ�������õ�ֵ�Ḳ����ǰֵ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_BatchSetString(IN const void* hOutput, IN const char* szName, IN char** pArryValue, IN int nCount);



	/** @fn     VM_M_BatchSetInt
     *  @brief  ��������������ݣ�֧��ͬʱ���ö��ֵ
     *  @param  [IN]  hOutput     ������
                [IN]  szName      ��������
				[IN]  pArryValue  ��������
				[IN]  nCount      �����С
	 *  @remark ��ε���ʱ�������õ�ֵ�Ḳ����ǰֵ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_BatchSetInt(IN const void* hOutput, IN const char* szName, IN int* pArryValue, IN int nCount);



	/** @fn     VM_M_BatchSetFloat
     *  @brief  ��������������ݣ�֧��ͬʱ���ö��ֵ
     *  @param  [IN]  hOutput     ������
                [IN]  szName      ��������
				[IN]  pArryValue  ��������
				[IN]  nCount      �����С
	 *  @remark ��ε���ʱ�������õ�ֵ�Ḳ����ǰֵ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
    VMMODULEFRAME_API int __stdcall VM_M_BatchSetFloat(IN const void* hOutput, IN const char* szName, IN float* pArryValue, IN int nCount);



	/** @fn     VM_M_TryRunProcedureOnce
     *  @brief  ����һ������ִ�У���Ҫ�ṩ��������ģ����á�
     *  @param  [IN]  hModule        ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
                [IN]  pszTriggerCmd  �����ַ���
	 *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_TryRunProcedureOnce(IN const void* hModule, IN const char* pszTriggerCmd, void* pNotUsed = 0);



	/** @fn     VM_M_TryRunProcedureOnceById
	 *  @brief  ��������ID������һ������ִ��
	 *  @param  [IN]  nProcedureId  ����ID
	            [IN]  pszTriggerCmd �����ַ���
	 *  @remark ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_TryRunProcedureOnceById(IN int nProcedureId, IN const char* pszTriggerCmd, void* pNotUsed = 0);



	/** @fn     VM_M_GetNextModuleList
     *  @brief  ��ȡ��ǰģ��ĺ�̽ڵ��б���Ҫ����֧ģ��ʹ��
     *  @param  [IN]  hModule              ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
                [OUT] pNextModuleInfoList  ���ģ��ڵ��б�
	 *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_GetNextModuleList(IN const void* hModule, OUT NEXT_MODULE_INFO_LIST* pNextModuleInfoList);
	VMMODULEFRAME_API int __stdcall VM_M_GetNextModuleListEx(IN const void* hModule, OUT NEXT_MODULE_INFO_LIST_EX* pNextModuleInfoList);



	/** @fn     VM_M_SetNextModuleList
     *  @brief  ���õ�ǰģ��ĺ�̽ڵ��б���Ҫ����֧ģ��ʹ��
     *  @param  [IN] hModule             ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
                [IN] pNextModuleInfoList ���ģ��ڵ��б�
	 *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_SetNextModuleList(IN const void* hModule, IN const NEXT_MODULE_INFO_LIST* pNextModuleInfoList);
	VMMODULEFRAME_API int __stdcall VM_M_SetNextModuleListEx(IN const void* hModule, IN const NEXT_MODULE_INFO_LIST_EX* pNextModuleInfoList);



	/** @fn     VM_M_ReportData
     *  @brief  ģ���ϱ��Զ����ݣ�SDKֻ��͸��
     *  @param  [IN]  hModule   ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
                [IN]  nType     �������ͣ��Զ���
				[IN]  szData    �Զ������ݣ����2K�ֽ�
				[IN]  nDataLen  �Զ������ݳ���
	 *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_ReportData(IN const void* hModule, IN int nType, IN const char* szData, IN int nDataLen);



	/** @fn     VM_M_EnableForceProcess
     *  @brief  ����ǰ���ڵ��Ƿ�����쳣��������������process���á��׳Ƹ�ʽ���ϲ���
     *  @param  [IN]  hModule   ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
                [IN]  bForce    �Ƿ���
	 *  @remark Ĭ������£���ĳһģ��ִ�г����쳣ʱ�����ģ�鲻���ٽ���processִ�У�
	            ���ô˽ӿڣ���ʹ�������Ƿ����쳣���������ɽ���processִ�����̡�
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_EnableForceProcess(IN const void* hModule, IN bool bForce);



    /** @fn     VM_M_SetModuleRuntimeInfo
     *  @brief  ��¼ģ��ʱ���е�һЩ��Ϣ�����㷨ʱ�䡢get��setʱ��ȡ�
     *  @param  [IN]  hModule       ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
                [IN]  pRuntimeInfo  ����ʱ��¼��Ϣ
	 *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_SetModuleRuntimeInfo(IN const void* hModule, IN const MODULE_RUNTIME_INFO* pRuntimeInfo);



	/** @fn     VM_M_GetModuleRuntimeInfo
     *  @brief  ��ȡģ������ʱһЩ��Ϣ�����㷨ʱ�䡢ģ�鿪ʼ������ִ��ʱ�䡣
     *  @param  [IN]  hModule       ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
                [OUT] pRuntimeInfo  ����ʱ��¼��Ϣ
	 *  @remark ��
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleRuntimeInfo(IN const void* hModule, OUT MODULE_RUNTIME_INFO* pRuntimeInfo);


	/** @fn     VM_M_GetModuleId
     *  @brief  ��ȡģ��ID
     *  @param  [IN]  hModule    ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
                [OUT] pModuleId  ģ��ID
	 *  @remark 
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleId(IN const void* hModule, OUT int* pModuleId);


	/** @fn     VM_M_GetModuleHandleById
     *  @brief  ����ģ��ID��ȡģ����
     *  @param  [IN]  nModuleId     ģ��ID
                [OUT] pModuleHandle ģ����
	 *  @remark 
     *  @return �����룬�μ�ErrorCodeDefine.h
     */
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleHandleById(IN int nModuleId, OUT void** pModuleHandle);


	/** @fn    VM_M_SetLastError
	*  @brief  ����ģ�������
	*  @param  [IN]  hModule      ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	           [IN]  nLastErrCode ������
	*  @remark
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_SetLastError(IN const void* hModule, IN int nLastErrCode);


	/** @fn     VM_M_GetCreateModuleCause
	 *  @brief  ��ȡ��ǰ����ģ���ԭ��
	 *  @param  [IN]  hModule      ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	 *  @param  [OUT] pCreateCause ģ�鴴��ԭ�򣬲μ� eCREATE_MODULE_CAUSE
	 *  @remark
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetCreateModuleCause(IN const void* hModule, OUT int* pCreateCause);



	/** @fn     VM_M_SetGlobalVarInt
	 *  @brief  ����ģ��ȫ���������
	 *  @param  [IN]  hModule  ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  szName   ��������
	            [IN]  nIndex   ��������
	            [IN]  nValue   ����ֵ
	 *  @remark ��һ����������ܴ��ڶ��ֵ��������index����ֵʱ���Ḳ����ǰֵ������SDK���������������ֵ������б�ĩβ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_SetGlobalVarInt(IN const void* hModule, IN const char* szName, IN int nIndex, IN int nValue);



	/** @fn     VM_M_SetGlobalVarFloat
	 *  @brief  ����ģ��ȫ�ָ������
	 *  @param  [IN]  hModule ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  szName  ��������
	            [IN]  nIndex  ��������
	            [IN]  fValue  ����ֵ
	 *  @remark ��һ����������ܴ��ڶ��ֵ��������index����ֵʱ���Ḳ����ǰֵ������SDK���������������ֵ������б�ĩβ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_SetGlobalVarFloat(IN const void* hModule, IN const char* szName, IN int nIndex, IN float fValue);


	/** @fn     VM_M_SetGlobalVarString
	 *  @brief  ����ģ��ȫ���ַ������
	 *  @param  [IN]  hModule ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  szName  ��������
	            [IN]  nIndex  ��������
	            [IN]  pValue  ����ֵ������'\0'�ַ���β
	*  @remark ��һ����������ܴ��ڶ��ֵ��������index����ֵʱ���Ḳ����ǰֵ������SDK���������������ֵ������б�ĩβ��
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_SetGlobalVarString(IN const void* hModule, IN const char* szName, IN int nIndex, IN const char* pValue);



	/** @fn     VM_M_GetGlobalVarInt
	 *  @brief  ��ȡģ��ȫ���������
	 *  @param  [IN]  hModule ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  szName  ��������
	            [IN]  nIndex  ��������
	            [OUT] pValue  �������ָ��
	            [OUT] pCount  ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark ��
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetGlobalVarInt(IN const void* hModule, IN const char* szName, IN int nIndex,
		OUT int* pValue, OUT int* pCount);



	/** @fn     VM_M_GetGlobalVarFloat
	 *  @brief  ��ȡģ��ȫ�ָ������
	 *  @param  [IN]  hModule ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  szName  ��������
	            [IN]  nIndex  ��������
	            [OUT] pValue  �������ָ��
	            [OUT] pCount  ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark ��
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetGlobalVarFloat(IN const void* hModule, IN const char* szName, IN int nIndex,
		OUT float* pValue, OUT int* pCount);



	/** @fn     VM_M_GetGlobalVarString
	 *  @brief  ��ȡģ��ȫ���ַ������
	 *  @param  [IN]  hModule ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  szName  ��������
	            [IN]  nIndex  ��������
	            [OUT] pValue  �������ָ��
	            [OUT] pCount  ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark ��
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetGlobalVarString(IN const void* hModule, IN const char* szName, IN int nIndex,
		OUT char* pBuff, IN int nBuffLen, OUT int* pDataLen, OUT int* pCount);



	/** @fn     VM_M_DelGlobalVar
	 *  @brief  ɾ��ģ��ȫ�ֱ���
	 *  @param  [IN]  hModule ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  szName  ��������
	 *  @remark ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_DelGlobalVar(IN const void* hModule, IN const char* szName);


	/** @fn     VM_M_GetOwnerProcedureRunningPolicy
	 *  @brief  ��ȡģ�������������в��Բ���
	 *  @param  [IN]  hModule        ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [OUT] pRunningPolicy ģ�������������в���
	 *  @remark  ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetOwnerProcedureRunningPolicy(IN const void* hModule, OUT MODULE_OWNER_PROCEDURE_RUNNING_POLICY* pRunningPolicy);



	/** @fn     VM_M_GetBinayData
	 *  @brief  ��ȡָ��ģ�����
	 *  @param  [IN]  nModuleId    ģ��ID
	            [IN]  pszName      ��������
				[OUT] pDataBuf     ���뻺����
				[IN]  nDataBuffLen ���뻺������С
				[OUT] pRealDataLen ʵ�����ݴ�С
	 *  @remark �����ش�����Ϊ IMVS_EC_PARAM_BUF_LENʱ��pRealDataLen�洢ʵ�����ݳ��ȡ���ʱ��ΪpDataBuf���·����ڴ棬�ٴε��á�
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetBinayData(IN int nModuleId, IN const char* pszName, IN char* pDataBuf, IN int nDataBuffLen, OUT int* pRealDataLen);



	/** @fn     VM_M_SetBinayData
	 *  @brief  ����ָ��ģ�����
	 *  @param  [IN]  nModuleId    ģ��ID
	            [IN]  pszName      ��������
	            [IN]  pData        ʵ������
	            [IN]  nDataLen     ���ݴ�С
	*  @remark  ��
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_SetBinayData(IN int nModuleId, IN const char* pszName, IN const char* pData, IN int nDataLen);


	/** @fn     VM_M_GetModuleNodeInfo
	 *  @brief  ��ȡģ����Ϣ
	 *  @param  [IN]  nModuleId    ģ��ID
	            [OUT] pModuleInfo  ģ����Ϣ
	 *  @remark  ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleNodeInfo(IN int nModuleId, OUT MODULE_INFO* pModuleInfo);



	/** @fn     VM_M_SetNotifyEventCallback
	 *  @brief  �����¼�֪ͨ�ص�
	 *  @param  [IN] hModule ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN] pEventCallback �¼��ص�
				[IN] pUserData      �û��Զ�������
	 *  @remark  ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_SetNotifyEventCallback(IN const void* hModule, IN pFnNotifyEventCallback pEventCallback, IN void* pUserData);


	/** @fn     VM_M_SetModuleParam
	 *  @brief  ����ָ��ģ�����
	 *  @param  [IN]  nModuleId       ģ��ID
	            [IN]  pParamValueList ����ֵ�б�
	 *  @remark  ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_SetModuleParam(IN int nModuleId, IN const PARAM_VALUE_INFO_LIST* pParamValueList);


	/** @fn     VM_M_GetModuleParam
	 *  @brief  ��ȡָ��ģ�����
	 *  @param  [IN]  nModuleId       ģ��ID
	            [IN]  pParamInfoList  �������б�
	            [OUT] pParamValueList ����ֵ�б�
	 *  @remark  ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleParam(IN int nModuleId, IN const PARAM_INFO_LIST* pParamInfoList, OUT PARAM_VALUE_INFO_LIST* pParamValueList);


	/** @fn     VM_M_GetOwnerProcedureRunningParam
	 *  @brief  ��ȡģ�������������в���
	 *  @param  [IN]  hModule        ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [OUT] pRunningParam  �������в���
	 *  @remark ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetOwnerProcedureRunningParam(IN const void* hModule, OUT PROCEDURE_RUNNING_PARAM* pRunningParam);


	/** @fn     VM_M_StopOwnerProcedure
	 *  @brief  ģ������ǰ����ֹͣ����
	 *  @param  [IN]  hModule        ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	 *  @remark ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_StopOwnerProcedure(IN const void* hModule);


	/** @fn     VM_M_GetModuleHandleByName
	 *  @brief  ����ģ�����ƻ�ȡģ����
	 *  @param  [IN]  hModule         ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  pModuleNamePath ģ������·����������ÿһ��Ԫ�ر�ʾһ��·�������һ��Ԫ���ñ���ΪNULL��
	            [OUT] pModuleHandle   Ҫ��ȡ��ָ�����Ƶ�ģ����
	 *  @remark V3.4������ģ������ʹ����ʾ���ơ�
	            1����ģ�鲻������Ƕ�׽ṹ�У�����ʾ����Ϊ Module1,��ô��
				   pModuleNamePath[0] = "Module1"
				   pModuleNamePath[1] = NULL.
				2����ģ�������Ƕ��Group�У���·��ΪGroup1-->Group2-->Module1,��ô��
				   pModuleNamePath[0] = "Group1",
				   pModuleNamePath[1] = "Group2"
				   pModuleNamePath[2] = "Module1"
				   pModuleNamePath[3] = NULL.
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleHandleByName(IN const void* hModule, IN char** pModuleNamePath, OUT void** pModuleHandle);


	/** @fn     VM_M_GetOutputString
	 *  @brief  ��ȡ�����ַ�����
	 *  @param  [IN]  hModule   ģ����
	            [IN]  szName    ��������
	            [IN]  nIndex    ��������
	            [IN]  pBuff     ���������ָ��
	            [IN]  nBuffLen  �����������С
	            [OUT] pDataLen  ����ʵ�����ݴ�С
	            [OUT] pCount    ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark ��������pBuff̫С��SDK���� IMVS_EC_PARAM_BUF_LEN����ʱ����pDataLenָ��Ĵ�С�����·���ռ䲢�ٴε��øýӿ�ȡֵ��
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetOutputString(IN const void* hModule, IN const char* szName, IN int nIndex,
		OUT char* pBuff, IN int nBuffLen, OUT int* pDataLen, OUT int* pCount);



	/** @fn      VM_M_GetOutputInt
	  *  @brief  ��ȡ��������ֵ
	  *  @param  [IN]  hModule   ģ����
	             [IN]  szName    ��������
	             [IN]  nIndex    ��������
	             [OUT] pValue    �������ָ��
	             [OUT] pCount    ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark ��
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetOutputInt(IN const void* hModule, IN const char* szName, IN int nIndex,
		OUT int* pValue, OUT int* pCount);



	/** @fn    VM_M_GetOutputFloat
	*  @brief  ��ȡ���븡��ֵ
	*  @param  [IN]  hModule   ģ����
	           [IN]  szName    ��������
	           [IN]  nIndex    ��������
	           [OUT] pValue    �������ָ��
	           [OUT] pCount    ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark ��
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetOutputFloat(IN const void* hModule, IN const char* szName, IN int nIndex,
		OUT float* pValue, OUT int* pCount);


	/** @fn     VM_M_GetOutputImage
	*  @brief  ��ȡ����ͼ������
	*  @param  [IN]  hModule    ģ����
	           [IN]  szName     ��������
	           [IN]  nIndex     ��������
	           [OUT] pImageData ͼ��������Ϣ��ͼ��������SDK����ռ䣬����ʱ�򵥴���IMAGE_DATA�սṹ�弴�ɡ�
	           [OUT] pCount     ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark IMAGE_DATA �е�ͼ�����ݣ���SDK����ռ䣬�ⲿ����ʱ�뾡��ʹ�ã�process�˳�ʱSDK����ո�ͼ����ռ�ڴ档
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetOutputImage(IN const void* hModule, IN const char* szName, IN int nIndex,
		OUT IMAGE_DATA* pImageData, OUT int* pCount);


	/** @fn     VM_M_GetOutputPointset
	 *  @brief  ��ȡ����㼯���ݡ�����˽ӿ���Ҫ��Ϊ�˼��ݶ���̰汾sdk��pDataָ��ĵ㼯���ݽṹ���㷨ģ�鶨�壬
	һ��ָ��IMVS_CONTOUR_POINT_INFO�ṹ�����顣
	*  @param  [IN]  hModule  ģ����
	           [IN]  szName   ��������
	           [IN]  nIndex   ��������
	           [OUT] pData    �㼯����
	           [OUT] nDataLen ���ݴ�С
	           [OUT] pCount   ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark pData�е����ݣ���SDK����ռ䣬�ⲿ����ʱ�뾡��ʹ�ã�process�˳�ʱSDK����ոñ�����ռ�ڴ档
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetOutputPointset(IN const void* hModule, IN const char* szName, IN int nIndex,
		OUT void** pData, OUT int* pDataLen, OUT int* pCount);


	/** @fn     VM_M_GetOutputBytes
	*  @brief  ��ȡ��������������
	*  @param  [IN]  hModule  ģ����
	           [IN]  szName   ��������
	           [IN]  nIndex   ��������
	           [OUT] pData    ���������ݿ�ָ���ַ
	           [OUT] nDataLen ���ݴ�С
	           [OUT] pCount   ���������ڶ��ֵ����Ϊ���������£�������ֵ�ĸ���
	*  @remark pData�е����ݣ���SDK����ռ䣬�ⲿ����ʱ�뾡��ʹ�ã�process�˳�ʱSDK����ոñ�����ռ�ڴ档
	*  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_GetOutputBytes(IN const void* hModule, IN const char* szName, IN int nIndex,
		OUT void** pData, OUT int* pDataLen, OUT int* pCount);

    /** @fn     VM_M_GetFreePort
    *  @brief  ��ȡ���ö˿�
    *  @param  [IN]  hModule  ģ����
    *  @param  [out] nFreePort  ���ö˿ں�
    *  @remark
    *  @return �����룬�μ�ErrorCodeDefine.h
    */
    VMMODULEFRAME_API int __stdcall VM_M_GetFreePort(IN const void* hModule, int& nFreePort);

#ifdef __cplusplus
};
#endif 

#endif //end of _VM_MODULE_BASE_H_
