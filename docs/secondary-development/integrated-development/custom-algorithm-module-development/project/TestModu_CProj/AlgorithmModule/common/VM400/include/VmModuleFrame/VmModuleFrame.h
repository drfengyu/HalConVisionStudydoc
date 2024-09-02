/************************************************************************
* ��Ȩ��Ϣ����Ȩ����(c) 2018, ���ݺ��������˼������޹�˾.��������Ȩ��.
*
* �ļ����ƣ�VmModuleFrame.h
* ժ   Ҫ:  SDK��ܽӿڶ��壬����������������С�
*
* ��   ��:  fenghuapeng5
* ��   �ڣ� 2018-09-10
* ��   ע�� 
************************************************************************/ 

#ifndef _VM_MODULE_FRAME_H_
#define _VM_MODULE_FRAME_H_
#include "VmModuleDef.h"

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

	//***��ʼ��������ʼ��***
	VMMODULEFRAME_API int __stdcall VM_M_Initialize(IN INITIALIZE_PARAM* pInitParam = NULL);
	VMMODULEFRAME_API int __stdcall VM_M_UnInitialize();

	
	//***�������***
	VMMODULEFRAME_API int __stdcall VM_M_CreateProcedure(IN const CREATE_PROCEDURE_PARAM* pCreateParam);
	VMMODULEFRAME_API int __stdcall VM_M_UpdateProcedure(IN int nProcedureId, IN const UPDATE_PROCEDURE_PARAM* pUpdateParam);
	VMMODULEFRAME_API int __stdcall VM_M_DeleteProcedure(IN int nProcedureId);
	// ��ȡ��ǰ����״̬��pStatusȡֵΪePROCEDURE_STATUS
	VMMODULEFRAME_API int __stdcall VM_M_GetProcedureStatus(IN int nProcedureId, OUT int* pStatus);
	VMMODULEFRAME_API int __stdcall VM_M_ExportProcedureData(IN int nProcedureId, IN const char* pPath);
	VMMODULEFRAME_API int __stdcall VM_M_ImportProcedureData(IN int nProcedureId, IN const char* pPath);
	VMMODULEFRAME_API int __stdcall VM_M_CancelExportProcedureData(IN int nProcedureId);
	VMMODULEFRAME_API int __stdcall VM_M_CancelImportProcedureData(IN int nProcedureId);
    

	//***ģ�����***
	// �˲���Ϊ�첽����������������¼�EVENT_ADD_MODULE_FINISHED�ϱ�
	VMMODULEFRAME_API int __stdcall VM_M_AddModuleNode(IN const ADD_MODULE_PARAM* pAddModuleParam);
	VMMODULEFRAME_API int __stdcall VM_M_AddModuleNodeEx(IN const ADD_MODULE_PARAM_EX* pAddModuleParam);
	VMMODULEFRAME_API int __stdcall VM_M_AddModuleNodeSync(IN const ADD_MODULE_PARAM_EX* pAddModuleParam);

	// �˲���Ϊ�첽����������������¼�EVENT_BATCH_ADD_MODULE_FINISHED�ϱ�
	VMMODULEFRAME_API int __stdcall VM_M_BatchAddModuleNode(IN const BATCH_ADD_MODULE_PARAM* pArryModuleParam, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_BatchAddModuleNodeEx(IN const BATCH_ADD_MODULE_PARAM_EX* pArryModuleParam, IN int nArrySize);

	VMMODULEFRAME_API int __stdcall VM_M_UpdateModuleNode(IN int nModuleId, IN const UPDATE_MODULE_PARAM* pUpdateModuleParam);
	VMMODULEFRAME_API int __stdcall VM_M_UpdateModuleNodeEx(IN int nModuleId, IN const UPDATE_MODULE_PARAM_EX* pUpdateModuleParam);
	VMMODULEFRAME_API int __stdcall VM_M_DeleteModuleNode(IN int nModuleId);
	VMMODULEFRAME_API int __stdcall VM_M_SetModuleNodeState(IN int nModuleId, IN const MODULE_STATE* pModuleState);
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleNodeState(IN int nModuleId, OUT MODULE_STATE* pModuleState);
	VMMODULEFRAME_API int __stdcall VM_M_CopyModuleNodeParam(IN int nSrcModuleId, IN int nDstModuleId);
	VMMODULEFRAME_API int __stdcall VM_M_CopyModuleNodeAlgParam(IN int nSrcModuleId, IN int nDstModuleId);
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleNodeInfo(IN int nModuleId, OUT MODULE_INFO* pModuleInfo);
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleNodeInfoEx(IN int nModuleId, OUT MODULE_INFO_EX* pModuleInfo);


	//***ģ���������***
	VMMODULEFRAME_API int __stdcall VM_M_SetModuleParam(IN int nModuleId, IN const PARAM_VALUE_INFO_LIST* pParamValueList);
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleParam(IN int nModuleId, IN const PARAM_INFO_LIST* pParamInfoList, OUT PARAM_VALUE_INFO_LIST* pParamValueList);
	VMMODULEFRAME_API int __stdcall VM_M_GetModuleAllParam(IN int nModuleId, OUT PARAM_VALUE_INFO_LIST* pParamValueList);

	
	//***�����ƿ��������***
	VMMODULEFRAME_API int __stdcall VM_M_SetBinayData(IN int nModuleId, IN const char* pszName, IN const char* pData, IN int nDataLen);

	
	// �����ش�����Ϊ IMVS_EC_PARAM_BUF_LENʱ��pRealDataLen�洢ʵ�����ݳ��ȡ���ʱ��ΪpDataBuf���·����ڴ棬�ٴε��á�
    VMMODULEFRAME_API int __stdcall VM_M_GetBinayData(IN int nModuleId, IN const char* pszName, IN char* pDataBuf, IN int nDataBuffLen, OUT int* pRealDataLen);
	

	//***����ģ��***
	VMMODULEFRAME_API int __stdcall VM_M_ConnectModule(IN int nSrcModuleId, IN int nDstModuleId);
	VMMODULEFRAME_API int __stdcall VM_M_DisConnectModule(IN int nSrcModuleId, IN int nDstModuleId);

   
	//***����***
	VMMODULEFRAME_API int __stdcall VM_M_SubScribe(IN const SUBSCRIBE_PARAM_LIST* pSubscribeParam);
	VMMODULEFRAME_API int __stdcall VM_M_UnSubScribe(IN int nModuleId, IN char* pszInputName, void* pNotUsed = 0);
    

	//***ִ������***
	VMMODULEFRAME_API int __stdcall VM_M_RunProcedureOnce(IN int nProcedureId, IN const char* pszTriggerCmd);
	VMMODULEFRAME_API int __stdcall VM_M_RunProcedureContinuously(IN int nProcedureId, IN int nInterval, IN const char* pszTriggerCmd);
	VMMODULEFRAME_API int __stdcall VM_M_StopRunProcedure(IN int nProcedureId);
	VMMODULEFRAME_API int __stdcall VM_M_RunModuleSelf(IN int nModuleId);
    VMMODULEFRAME_API int __stdcall VM_M_BatchRunModuleSelf(IN int* pModuleIds, IN int nModuleNum);
	VMMODULEFRAME_API int __stdcall VM_M_SetProcedureRunningParam(IN int nProcedureId, IN const PROCEDURE_RUNNING_PARAM* pRunningParam);
	VMMODULEFRAME_API int __stdcall VM_M_GetProcedureRunningParam(IN int nProcedureId, OUT PROCEDURE_RUNNING_PARAM* pRunningParam);
	//pInputΪ�����������������pOutputΪ���������Ϣ������ʱ��ΪNULL���ɡ�
	VMMODULEFRAME_API int __stdcall VM_M_RunProcedureOnceEx(IN int nProcedureId, IN const RUN_PROCEDURE_INPUT* pInput = NULL, OUT RUN_PROCEDURE_OUTPUT* pOutput = NULL);
	
	//***����***
	VMMODULEFRAME_API int __stdcall VM_M_SaveSolutionToFile(const char* szFilePath);
	VMMODULEFRAME_API int __stdcall VM_M_LoadSolutionFromFile(const char* szFilePath);
	VMMODULEFRAME_API int __stdcall VM_M_CancelLoadSolution();
	VMMODULEFRAME_API int __stdcall VM_M_CancelSaveSolution();
	VMMODULEFRAME_API int __stdcall VM_M_CloseSolution();
	VMMODULEFRAME_API int __stdcall VM_M_AsyncCloseSolution();
	//nLoadState: 0-δ���ط�����1-���ڼ��ط���״̬
	VMMODULEFRAME_API int __stdcall VM_M_SetLoadSolutionState(int nLoadState);
    
	
	//***ѭ������***
	VMMODULEFRAME_API int __stdcall VM_M_AddLoop(IN int nProcedureId, IN int nLoopId);
	VMMODULEFRAME_API int __stdcall VM_M_UpdateLoop(IN int nLoopId, IN const LOOP_INFO* pLoopInfo);
	VMMODULEFRAME_API int __stdcall VM_M_DeleteLoop(IN int nLoopId);
	VMMODULEFRAME_API int __stdcall VM_M_BatchAddLoop(IN const BATCH_ADD_LOOP_PARAM* pArryLoopParam, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_AddLoopEx(IN const ADD_LOOP_PARAM_EX* pAddLoopParam);


	//***Group�����***
	VMMODULEFRAME_API int __stdcall VM_M_AddGroup(IN const ADD_GROUP_PARAM* pAddGroupParam);
	VMMODULEFRAME_API int __stdcall VM_M_AddGroupEx(IN const ADD_GROUP_PARAM_EX* pAddGroupParam);
	VMMODULEFRAME_API int __stdcall VM_M_AddGroupSync(IN const ADD_GROUP_PARAM_EX* pAddGroupParam);
	VMMODULEFRAME_API int __stdcall VM_M_MoveIntoGroup(IN int nGroupId, IN int nNodeId);
	VMMODULEFRAME_API int __stdcall VM_M_MoveOutFromGroup(IN int nGroupId, IN int nNodeId);
	VMMODULEFRAME_API int __stdcall VM_M_DeleteGroup(IN int nGroupId);
	VMMODULEFRAME_API int __stdcall VM_M_ExportGroupData(IN int nGroupId, IN const char* pPath);
	VMMODULEFRAME_API int __stdcall VM_M_ImportGroupData(IN int nGroupId, IN const char* pPath);
	VMMODULEFRAME_API int __stdcall VM_M_CancelExportGroupData(IN int nGroupId);
	VMMODULEFRAME_API int __stdcall VM_M_CancelImportGroupData(IN int nGroupId);
	VMMODULEFRAME_API int __stdcall VM_M_BatchAddGroup(IN const BATCH_ADD_GROUP_PARAM* pArryAddGroupParam, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_BatchAddGroupEx(IN const BATCH_ADD_GROUP_PARAM_EX* pArryAddGroupParam, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_BatchMoveIntoGroup(IN int nGroupId, IN const int* pArryNodeId, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_BatchMoveOutFromGroup(IN int nGroupId, IN const int* pArryNodeId, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_SetGroupIO(IN int nGroupId, IN const GROUP_IO_FIELD_PARAM* pArryGroupInput, IN int nInputSize, IN const GROUP_IO_FIELD_PARAM* pArryGroupOutput, IN int nOutputSize);

	
	//***ִ�н���ص�***
	VMMODULEFRAME_API int __stdcall VM_M_SetResultCallback(IN pFnResultCallback fResultCallback, IN void* pUserData);


	//***������ˣ������̼��������Զ����������ѡ�������������ڸ���ģ��Ľ��***
	VMMODULEFRAME_API int __stdcall VM_M_SetCustomOutput(IN int nProcedureId, IN const CUSTOM_OUTPUT_RECORD* pCustomOutput);
	VMMODULEFRAME_API int __stdcall VM_M_GetCustomOutput(IN int nProcedureId, IN int nIndex, OUT CUSTOM_OUTPUT_RECORD_LIST* pCustomOutputList, OUT int* pTotalNum);
	VMMODULEFRAME_API int __stdcall VM_M_DelCustomOutput(IN int nProcedureId, IN const char* pOutputName);
	VMMODULEFRAME_API int __stdcall VM_M_ClearCustomOutput(IN int nProcedureId);


	//***�¼�֪ͨ�ص�***
	VMMODULEFRAME_API int __stdcall VM_M_SetEventCalBack(IN pFnEventCallback pEventCallback, IN void* pUserData);

    //***ģ���Զ������ݻص�***
    VMMODULEFRAME_API int __stdcall VM_M_SetCustomDataCallBack(IN pFnCustomDataTransCallback pDataCallback, IN void* pUserData);

	//***��ѯģ��������Ϣ***
    VMMODULEFRAME_API int __stdcall VM_M_QueryModuleConfigParam(IN char* szModuleName, OUT MODULE_CONFIG_PARAM* pModuleConfigParam);
	VMMODULEFRAME_API int __stdcall VM_M_QueryModuleConfigParamEx(IN char* szModuleName, OUT MODULE_CONFIG_PARAM_EX* pModuleConfigParam);

	
	//***������־����***
	VMMODULEFRAME_API int __stdcall VM_M_SetLogLevel(IN eLOG_LEVEL nLogLevel);


	//***��������ʱ���Ʋ���***
	VMMODULEFRAME_API int __stdcall VM_M_SetRunningControlParam(IN const RUNNING_CONTROL_PARAM* pRunControlParam);


	//***�������в���***
	VMMODULEFRAME_API int __stdcall VM_M_SetProcedureRunningPolicy(IN const PROCEDURE_RUNNING_POLICY* pRunPolicy);
	VMMODULEFRAME_API int __stdcall VM_M_GetProcedureRunningPolicy(OUT PROCEDURE_RUNNING_POLICY* pRunPolicy);


	// ***��ȡ��������Ϣ***
	VMMODULEFRAME_API int __stdcall VM_M_GetProcessorInfo(OUT PROCESSOR_INFO* pProcessorInfo);


	// ***ȫ�ֱ���***
	VMMODULEFRAME_API int __stdcall VM_M_BindGlobalVar(IN const BIND_GLOBALVAR_PARAM* pArryBindGlobaVar, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_UnBindGlobalVar(IN const UNBIND_GLOBALVAR_PARAM* pArryUnBindGlobalVar, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_GetGlobalVarBindingList(IN int nGlobalModuleId, IN int nIndex, IN int nArrySize, OUT BIND_GLOBALVAR_PARAM* pArryBindList, OUT int* pReturnCount, OUT int* pTotalNum);


	// ***�����ڴ����Ƿ�����globalǰ׺***
	VMMODULEFRAME_API int __stdcall VM_M_EnableSharedMemGlobalPrefix(IN bool bEnable);


	// ***���������������***
	VMMODULEFRAME_API int __stdcall VM_M_SetProcedureIO(IN int nProcedureId, IN const PROCEDURE_IO_FIELD_PARAM* pArryInput, IN int nInputSize, IN const PROCEDURE_IO_FIELD_PARAM* pArryOutput, IN int nOutputSize);
	

	// ***�������̡�ģ������ֵ��nId��Ϊ��ͨģ��id������id��***
	VMMODULEFRAME_API int __stdcall VM_M_SetInputString(IN int nId, IN const char* szName, IN int nIndex, IN const char* pValue);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputInt(IN int nId, IN const char* szName, IN int nIndex, IN int nValue);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputFloat(IN int nId, IN const char* szName, IN int nIndex, IN float fValue);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputImage(IN int nId, IN const char* szName, IN int nIndex, IN const IMAGE_DATA* pImageData);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputPointset(IN int nId, IN const char* szName, IN int nIndex, IN void* pData, IN int nDataLen);
	VMMODULEFRAME_API int __stdcall VM_M_SetInputBytes(IN int nId, IN const char* szName, IN int nIndex, IN void* pData, IN int nDataLen);


	// pArryName��ʾҪ��ȡ��ģ�������������飬pArryInputState����Ԫ�ظ���������pArryName����һ�£��Ҷ�ΪnSize
	VMMODULEFRAME_API int __stdcall VM_M_GetInputState(IN int nModuleId, IN const char** pArryName, int nSize, OUT MODULE_INPUT_STATE* pArryInputState);


	// ***ѡ���ϴ�ָ����ģ����***
	VMMODULEFRAME_API int __stdcall VM_M_SelectModuleResult(IN const SELECTED_MODULE* pArrySelectModules, IN int nArrySize);
	VMMODULEFRAME_API int __stdcall VM_M_SelectAllModuleResult();
	VMMODULEFRAME_API int __stdcall VM_M_SelectNoneModuleResult();

	// ***��ѯ/���ģ������ÿ�β�ѯ֮��Ṳ���棬��Ҫ���̵߳���***
	VMMODULEFRAME_API int __stdcall VM_M_QueryModuleHistoryResult(IN int nModuleId, IN const MODULE_HISTORY_INPUT* pInput, OUT MODULE_HISTORY_RESULT* pHistoryRst);
	VMMODULEFRAME_API int __stdcall VM_M_ClearModuleHistoryResult(IN int nModuleId);


    // * 
    VMMODULEFRAME_API int __stdcall VM_M_GetModuleIOBeSubjectByModulesRunParam(IN int nModuleId, IN const char* pszVarParamName, IN OUT VARPARAM_BESUBJECT_MODULES_RUNPARAM_LIST* pRunParamModulesList);
    VMMODULEFRAME_API int __stdcall VM_M_DelModuleIOBeSubectByRunParamRelation(IN int nModuleId, IN const char* pszVarParamName);

    VMMODULEFRAME_API int __stdcall VM_M_SetExcludeModuleName(IN const char* szModuleName);
    VMMODULEFRAME_API int __stdcall VM_M_SetGlobalProcedureDelayTime(IN int nDelayTime);

#ifdef __cplusplus
};
#endif 

#endif //end of _VM_MODULE_FRAME_H_