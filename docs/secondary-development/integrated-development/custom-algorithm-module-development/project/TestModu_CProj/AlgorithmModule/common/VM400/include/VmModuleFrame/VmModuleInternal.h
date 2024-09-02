/************************************************************************
* ��Ȩ��Ϣ����Ȩ����(c) 2019, ���ݺ��������˼������޹�˾.��������Ȩ��.
*
* �ļ����ƣ�VmModuleInternal.h
* ժ   Ҫ:  �ڲ��ӿڶ��壬�����⡣�˴��ṩ�Ľӿ�ֻ��Ϊ�������㷨ģ�顢
            ������̵������Ҫ���ṩ��
*
* ��   ��:  fenghuapeng5
* ��   �ڣ� 2019-12-18
* ��   ע��
************************************************************************/
#ifndef _VMMODULE_INTERNAL_H_
#define _VMMODULE_INTERNAL_H_

#ifdef _WIN32
#ifdef  VMMODULEFRAME_EXPORTS
#    define VMMODULEFRAME_API __declspec(dllexport)
#else
#    define VMMODULEFRAME_API __declspec(dllimport)
#endif
#else
#    define VMMODULEFRAME_API __attribute__((visibility("default")))
#    define __stdcall
#endif

#ifdef __cplusplus
extern "C"
{
#endif 

	/** @fn     VM_M_GetDefaultConfigByFile
	 *  @brief  ͨ�������ļ�����ȡģ��Ĭ�ϵĲ�������

	            ע���˽ӿڽ�����Ϊ��ͳһ���������ļ��ṩ������ʵ����Ҫ��ѡʹ�ã�
	            ��ͨ���ýӿ���ģ���ʼ���ɹ��󣬻�ȡģ��Ĭ�ϲ�����

	 *  @param  [IN]  hModule         ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  szAlgFile       ���в�����������Ĭ��ֵ���ļ����˽ӿڽ����ļ��ж�ȡ��������Ĭ��ֵ
	            [OUT] pParamValueList ����������Ϣ
	 *  @remark  szAlgFileָ�����ļ�������ϸ�ʽԼ����
	            ��szAlgFile��Ϊ�ļ�����������·����ʱ��SDKĬ�ϻ���ģ��dll·���²��Ҵ��ļ�����������£���ָ������·����
	 *  @return  �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetDefaultConfigByFile(IN const void* hModule, IN const char* szAlgFile, OUT PARAM_VALUE_INFO_LIST* pParamValueList, void* pNotUsed = 0);



	/** @fn    VM_M_GetCurrentConfigByFile
	 *  @brief ͨ�������ļ�����ȡģ�鵱ǰ�Ĳ������á�

	           ע���˽ӿڽ�����Ϊ��ͳһ���������ļ��ṩ������ʵ����Ҫ��ѡʹ�ã�
	           Ŀǰֻ��CAbstractUserModule::GetAllParamList��ʹ�õ���

	 *  @param  [IN]  hModule         ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  szAlgFile       ���в�����������Ĭ��ֵ���ļ����˽ӿڴ��ļ��л�ȡ�������󣬻��ģ���л�ȡ��ǰ����ֵ
	            [OUT] pParamValueList ����������Ϣ
	 *  @remark szAlgFileָ�����ļ�������ϸ�ʽԼ����
	            ��szAlgFile��Ϊ�ļ�����������·����ʱ��SDKĬ�ϻ���ģ��dll·���²��Ҵ��ļ�����������£���ָ������·����
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetCurrentConfigByFile(IN const void* hModule, IN const char* szAlgFile, OUT PARAM_VALUE_INFO_LIST* pParamValueList, void* pNotUsed = 0);


	/** @fn     VM_M_AllocateAlgMemory
	 *  @brief  �������㷨�����ڴ棬����ͨ���ڴ��������ʹ�ô˽ӿ�
	 *  @param  [IN]  hModule     ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  nSize       ���в�����������Ĭ��ֵ���ļ����˽ӿڴ��ļ��л�ȡ�������󣬻��ģ���л�ȡ��ǰ����ֵ
	            [IN]  nAlignment  �������ֽڶ���(4/8/16/32/64/128/256)
	            [OUT] pData       �����ڴ���׵�ַ
	 *  @remark ��������дCAbstractUserModule::Process�����е��ã����������߳���ʹ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_AllocateAlgMemory(IN const void* hModule, IN int nSize, IN int nAlignment, OUT void** pData);
	VMMODULEFRAME_API int __stdcall VM_M_AllocateAlgMemory64(IN const void* hModule, IN uint64_t nSize, IN int nAlignment, OUT void** pData);


	/** @fn     VM_M_ReleaseAlgMemory
	 *  @brief  �ͷ��ѷ�����㷨�����ڴ棬����ͨ���ڴ��ͷ�����ʹ�ô˽ӿ�
	 *  @param  [IN]  hModule    ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  pData      �����ڴ���׵�ַ
	 *  @remark ��������дCAbstractUserModule::Process�����е��ã����������߳���ʹ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_ReleaseAlgMemory(IN const void* hModule, IN const void* pData);



	/** @fn     VM_M_AllocateMemoryInPool
	 *  @brief  ��ȫ���ڴ���з����ڴ�
	 *  @param  [IN]  hModule   ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  pInput    �����ڴ����
	            [OUT] pBaseAddr �����ڴ���׵�ַ
	 *  @remark ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_AllocateMemoryInPool(IN const void* hModule, IN const ALLOC_MEM_IN_POOL_INPUT* pInput, OUT void** pBaseAddr);



	/** @fn     VM_M_ReleaseMemoryInPool
	 *  @brief  ��ȫ���ڴ�����ͷ��ڴ�
	 *  @param  [IN]  hModule    ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	            [IN]  pBaseAddr  �����ڴ���׵�ַ
	 *  @remark ��
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_ReleaseMemoryInPool(IN const void* hModule, IN void* pBaseAddr);



	/**  @fn     VM_M_ReleaseSolSharedMemory
	  *  @brief  �ͷŷ�����صĹ����ڴ�
	  *  @param  
	  *  @remark 
	  *  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_ReleaseSolSharedMemory();
    VMMODULEFRAME_API int __stdcall VM_M_ReleaseSolSharedMemorySp();



	/**  @fn    VM_M_ReleaseGroupDataSharedMemory
	 *  @brief  �ͷ�Group��صĹ����ڴ�
	 *  @param  [IN] nGroupId       ģ��Id
	            [IN] pSharedMemName �����ڴ�����
	 *  @remark
	 *  @return �����룬�μ�ErrorCodeDefine.h
	*/
    VMMODULEFRAME_API int __stdcall VM_M_ReleaseGroupDataSharedMemory(IN int nGroupId, const char* pSharedMemName);
    VMMODULEFRAME_API int __stdcall VM_M_ReleaseGroupDataSharedMemorySp(IN int nGroupId, const char* pSharedMemName);



	/**  @fn    VM_M_ReleaseProcedureDataSharedMemory
	 *  @brief  �ͷ�������صĹ����ڴ�
	 *  @param  [IN] nProcedureId   ����Id
	            [IN] pSharedMemName �����ڴ�����
	 *  @remark
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
    VMMODULEFRAME_API int __stdcall VM_M_ReleaseProcedureDataSharedMemory(IN int nProcedureId, const char* pSharedMemName);
    VMMODULEFRAME_API int __stdcall VM_M_ReleaseProcedureDataSharedMemorySp(IN int nProcedureId, const char* pSharedMemName);



	/**  @fn    VM_M_ResetModuleNodeAlgParam
	 *  @brief  ����ģ��ؼ��ֲ���
	 *  @param  nModuleId ģ��Id
	 *  @remark
	 *  @return �����룬�μ�ErrorCodeDefine.h
	*/
	VMMODULEFRAME_API int __stdcall VM_M_ResetModuleNodeAlgParam(IN int nModuleId);



	/** @fn     VM_M_NotifyEvent
	 *  @brief  ��֪֪ͨ�¼�
	 *  @param  nNotifyEvent ֪ͨ�¼����ͣ��μ�eNOTIFY_EVENT_TYPE
	 *  @param  pData        �¼����ݣ���ΪNULL
	 *  @remark
	 *  @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_NotifyEvent(IN int nNotifyEvent, IN void* pData);



	/**  @fn     IsUploadRstEnabled
	 *   @brief  �жϵ�ǰ�ϴ�����Ƿ�����
	 *   @param  
	 *   @remark ��ģ����������ģ���ܣ���ʹ�ô˽ӿ��ж��Ƿ��ͽ����
	 *   @return true or false
	 */
	VMMODULEFRAME_API bool __stdcall VM_M_IsUploadRstEnabled();



	/**  @fn     VM_M_RunModuleById
	 *   @brief  ��ģ����ִ������ģ��
	 *   @param  [IN] hModule    ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	             [IN] nModuleId  Ҫ���е�ģ��ID
				 [IN] pErrCode   ��ִ�е�ģ��process����ֵ
	 *   @remark �˲���Ϊͬ��ִ�У��˽ӿ�ֻ���ڱ�ִ��ģ����ɺ�ŷ���
	 *   @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_RunModuleById(IN const void* hModule, IN int nRunModuleId, IN int* pErrCode);


	/**  @fn     VM_M_GetModuleMapping
	 *   @brief  ��ģ����ִ������ģ��
	 *   @param  [IN]  hModule             ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	             [OUT] pArryModuleMapping  ģ��ӳ����Ϣ����
	             [IN]  nArrySize           pArryModuleMapping���ݴ�С
				 [OUT] nRealNum            ������ʵ���ݳ��ȡ�
	 *   @remark ��pArryModuleMappingΪNULL��nArrySizeС����ʵ�����Сʱ������IMVS_EC_PARAM_BUF_LEN������nRealNum������ʵ��С�������·����ڴ���ٴε��á�
	 *   @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleMapping(IN const void* hModule, OUT MODULE_MAPPING* pArryModuleMapping, IN int nArrySize, OUT int* pRealNum);


	/**  @fn     VM_M_ExportModuleDataToSharedMem
	 *   @brief  ����ģ������
	 *   @param  [IN] pSharedMemName �����ڴ�����
	             [IN] pArryModuleId  ������ģ��Id
	             [IN] nSize          ����pArryModuleId��С
	 *   @remark 
	 *   @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_ExportModuleDataToSharedMem(IN const char* pSharedMemName, IN const int* pArryModuleId, IN int nSize);


	/**  @fn     VM_M_ImportModuleDataFromSharedMem
	 *   @brief  ����ģ������
	 *   @param  [IN] pData    ģ������
	 *   @param  [IN] nDataLen ���ݳ���
	 *   @remark
	 *   @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_ImportModuleDataFromSharedMem(IN const char* pData, IN int nDataLen, IN const int* pArryModuleId, IN int nSize);


	/**  @fn     VM_M_RelaseSharedMemory
	 *   @brief  �ͷŹ����ڴ�
	 *   @param  [IN] pSharedMemName �����ڴ�����
	 *   @remark
	 *   @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_RelaseSharedMemory(IN const char* pSharedMemName);


	// ***�������̡�ģ������ֵ��nId��Ϊ��ͨģ��id������id��***
	VMMODULEFRAME_API int __stdcall VM_M_SetInputString(IN int nId, IN const char* szName, IN int nIndex, IN const char* pValue);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputInt(IN int nId, IN const char* szName, IN int nIndex, IN int nValue);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputFloat(IN int nId, IN const char* szName, IN int nIndex, IN float fValue);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputImage(IN int nId, IN const char* szName, IN int nIndex, IN const IMAGE_DATA* pImageData);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputPointset(IN int nId, IN const char* szName, IN int nIndex, IN void* pData, IN int nDataLen);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputBytes(IN int nId, IN const char* szName, IN int nIndex, IN void* pData, IN int nDataLen);


	/**  @fn     VM_M_RequestChangeSol
	 *   @brief  ģ�����������л�����
	 *   @param  [IN]  hModule         ģ��������SDK���䣬����CreateModuleʱ��Ϊ��������
	             [IN]  pChangeSolParam �л���������
	 *   @remark
	 *   @return �����룬�μ�ErrorCodeDefine.h
	 */
	VMMODULEFRAME_API int __stdcall VM_M_RequestChangeSol(IN const void* hModule, IN const REQUEST_CHANGE_SOL_PARAM* pChangeSolParam);

	// ***ά��ȫ���������***
	VMMODULEFRAME_API int __stdcall VM_M_NotifyIncGlobalCameraNum(IN const void* hModule, IN int nNum, IN int nFlag);
	VMMODULEFRAME_API int __stdcall VM_M_NotifyDecGlobalCameraNum(IN const void* hModule, IN int nNum, IN int nFlag);
	VMMODULEFRAME_API int __stdcall VM_M_GetGlobalCameraList(OUT GLOBAL_CAMERA_LIST* pGlobalCameraList);


	// ***�������м��״̬***
	VMMODULEFRAME_API int __stdcall VM_M_SetCheckRunningStatus(IN const CHECK_RUNNING_STATUS* pCheckRunningStatus);


	// ***��ȡ������ģ��Ĺؼ��ֲ���������Ϣ***
	VMMODULEFRAME_API int __stdcall VM_M_GetCurrentConfigOfSolution(IN char* pDataBuf, IN int nDataBuffLen, OUT int* pRealDataLen);


	//***��ģ��ִ�н����ģ�����в�����***
	VMMODULEFRAME_API int __stdcall VM_M_SetModuleParamBinding(IN const MODULE_PARAM_BINDING* pArryBinding, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_DelModuleParamBinding(IN const MODULE_PARAM_UNBINDING* pArryUnBinding, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleParamBindingList(IN int nModuleId, IN int nIndex, IN int nArrySize, OUT MODULE_PARAM_BINDING* pArryBindList, OUT int* pReturnCount, OUT int* pTotalNum);

	//***�������뵼������, pArryProcedureId��ʾ����id���飬nProcedureNum��ʾ�����С***
	VMMODULEFRAME_API int __stdcall VM_M_BatchExportProcedureData(IN const int* pArryProcedureId, int nProcedureNum, IN const char* pPath);
	VMMODULEFRAME_API int __stdcall VM_M_BatchImportProcedureData(IN const int* pArryProcedureId, int nProcedureNum, IN const char* pPath);
	VMMODULEFRAME_API int __stdcall VM_M_BatchCancelExportProcedureData(void* pReserved = NULL);
	VMMODULEFRAME_API int __stdcall VM_M_BatchCancelImportProcedureData(void* pReserved = NULL);
	VMMODULEFRAME_API int __stdcall VM_M_BatchReleaseProcedureDataSharedMemory(void* pReserved = NULL);

	//***���̼�����***
	VMMODULEFRAME_API int __stdcall VM_M_ConnectProcedure(IN int nSrcProcedureId, IN int nDstProcedureId);
	VMMODULEFRAME_API int __stdcall VM_M_DisConnectProcedure(IN int nSrcProcedureId, IN int nDstProcedureId);

	//***���ÿ�����***
	VMMODULEFRAME_API int __stdcall VM_M_EnableReentrant(IN bool bEnable);

	//***���ò�֧�ֿ������ģ���б�***
	VMMODULEFRAME_API int __stdcall VM_M_SetUnsupportReentrantModules(IN const char* pData);

	//***���������������***
	VMMODULEFRAME_API int __stdcall VM_M_SetReentrantMaxTimes(IN int nMaxTimes);

	//***�����ڲ�����ڵ�����***
	VMMODULEFRAME_API int __stdcall VM_M_SetBufferNodeNum(IN int nBufferNum);

    //***��ȡ�ڲ�����ڵ�����***
    VMMODULEFRAME_API int __stdcall VM_M_GetBufferNodeNum(IN int* nBufferNum);

	//***��ѯģ��״̬, ��������ѯ��nArrySize��ʾpArryModuleId��pArryStateInfoָ���������С***
	VMMODULEFRAME_API int __stdcall VM_M_QueryModuleRunningState(IN const int* pArryModuleId, IN int nArrySize, OUT MODULE_STATE_INFO* pArryStateInfo);

	// ***�����ϴν�����䣬������ģ�鲻�ᱻִ��***
	VMMODULEFRAME_API int __stdcall VM_M_KeepLastResultUnchange(IN int nNodeId, IN bool bKeep);

	// ***����ͼ�񻺴�ڵ�������������������ʱ����***
	VMMODULEFRAME_API int __stdcall VM_M_SetImageBufferNodeNum(IN int nNodeId, IN int nNum);

	// ***ǿ�����***
	VMMODULEFRAME_API int __stdcall VM_M_ForceDeepCopyImage(IN bool bForce);

};

#endif
