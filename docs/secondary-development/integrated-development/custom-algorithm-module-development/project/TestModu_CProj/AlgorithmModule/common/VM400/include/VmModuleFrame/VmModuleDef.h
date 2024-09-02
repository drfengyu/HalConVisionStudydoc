/************************************************************************
* ��Ȩ��Ϣ����Ȩ����(c) 2018, ���ݺ��������˼������޹�˾.��������Ȩ��.
*
* �ļ����ƣ�VmModuleDef.h
* ժ   Ҫ:  ����SDK�������ݽṹ
*
* ��   ��:  fenghuapeng5
* ��   �ڣ� 2018-09-10
* ��   ע�� 
************************************************************************/ 

#ifndef _VM_MODULE_DEF_H_
#define _VM_MODULE_DEF_H_

#ifdef _MSC_VER
typedef __int32          int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64          int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

#ifndef _WIN32
#define __stdcall
#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#ifndef NULL
#define NULL 0
#endif

//����������Ƴ���
#define MAX_IO_NAME_LEN  128

//�ؼ������Ƴ���
#define MAX_KEY_NAME_LEN 260

//ģ�����ֵ��󳤶�
#define PARAM_VALUE_LEN 1024

//ģ������������
#define MAX_PARAM_NUM  256

//�������Ƴ���
#define PROCEDURE_NAME_LEN 64

//ģ�����Ƴ���
#define MODULE_NAME_LEN 64

//ģ����ʾ���Ƴ���
#define MODULE_DISPLAY_NAME_LEN 64

//ģ����ʾ���Ƴ���
#define MODULE_DISPLAY_NAME_LEN_EX 256

//ģ���̽ڵ������Ŀ
#define MAX_SUCCESSOR_NUM 256

//��������ֵ��󳤶�
#define MAX_CONSTANT_VALUE_LEN 256

//�Զ��������в�������
#define MAX_ARG_STRING_LEN 256

//�û����������ݿ��������
#define MAX_USER_BINARY_BLOCK_BUM 128

//���ζ������鳤��
#define SUBSCRIBE_NUM 128

//�Զ�������ֶ��б��С
#define CUSTOM_OUTPUT_PAGE_SIZE 10

//ģ�������Ϣ�б��С
#define MODULE_ERRLIST_SIZE 128

//���CPU���ĸ���
#define MAX_CORE_NUM 64

//�������в��������С
#define MAX_RUN_POLICY_NUM 32

//GUID���鳤��
#define GUID_LEN 40

// ÿ�β�ѯ����ʷ�������
#define HISTORY_RST_PAGE_SIZE 50

// ���̴��������
#define TRIGGER_CMD_LEN 16

// �����ڴ����Ƴ���
#define SHARED_MEM_NAME_LEN 64

typedef struct
{
	char byParamName[MAX_KEY_NAME_LEN]; // ������
	char byReserve[128];                // ����
}PARAM_INFO;

//VM�汾��Ϣ
enum eVmVersion : int
{
	VM_VERSION_INVALID = 0,
	VM_VERSION_310     = 1,
	VM_VERSION_320     = 2,
	VM_VERSION_330     = 3,
	VM_VERSION_331     = 4,
	VM_VERSION_340     = 5,
	VM_VERSION_400     = 6,
	VM_VERSION_420     = 7,
    VM_VERSION_421     = 8,
    VM_VERSION_4220    = 9,
    VM_VERSION_430     = 10,
	VM_VERSION_DEFAULT = 127
};

//VM����ģʽ
enum eVmProcessMode : int
{
    VM_PROCESS_MODE_MULTI  = 0,     //�����ģʽ
    VM_PROCESS_MODE_SINGLE = 1      //������ģʽ
};

typedef struct
{
	char         byModulePath[512]; // ģ����Ŀ¼��Ϊ��ʱ����Ĭ���ڵ�ǰSDK·����SDK_PATH/Module�²���ģ�顣
	char         byLogPath[512];    // ��־���Ŀ¼��Ϊ��ʱ����Ĭ���ڵ�ǰSDK·���¡�
	char         byCharset;         // 0-ansi�ַ���1-utf8�ַ���
    char         byVersion;         // �����汾���μ�eVmVersion����VMӦ��,��VM_VERSION_DEFAULT���ɡ�
    char         byPreload;         // Ԥ����ģ�飬0-�����ã�1-���á����ر��עģ�鴴��ʱ�������²�Ҫ����������������һЩ�ڴ档
    char         byProcessMode;     // ����ģʽ���μ�eVmProcessMode
    char         byMinCoreNum;      // ���ø����ܵ���С����
    const char*  szLoadModuleDataTempPath;    // ģ�����������ʱ�ļ�·��������ʱͼ�����ѧϰģ��
    char         byLogMode;         // ��־ģʽ 1-�첽 0-ͬ��
    char         byReserve[239];    // ����
}INITIALIZE_PARAM;


typedef struct
{   
	int nNum;                                // ��Ч��������
	PARAM_INFO struParamList[MAX_PARAM_NUM]; // �����б�
	char byReserve[128];                     // ����
}PARAM_INFO_LIST;


typedef struct
{
	char byParamName[MAX_KEY_NAME_LEN]; // ������
	char byParamValue[PARAM_VALUE_LEN]; // ����ֵ
	char byReserve[128];                // ����
}PARAM_VALUE_INFO;


typedef struct
{   
	int nNum;                                       // ��Ч��������
	PARAM_VALUE_INFO paramValueList[MAX_PARAM_NUM]; // �����б�
	char byReserve[128];                            // ����
}PARAM_VALUE_INFO_LIST;


enum eCUSTOM_USERDATA_TYPE : int
{
	USERDATA_INVALID = 0, // ��Ч
	USERDATA_BINARY  = 1, // ����������
};


typedef struct 
{
	char  byName[MAX_KEY_NAME_LEN]; // ���ݿ�����
	char* pUserData;                // ����������           
	int   nDataLen;                 // ���������ݳ���
}USER_BINARY_DATA;


typedef struct  
{
	int nNum;                                                    // ���ݿ�����
	USER_BINARY_DATA struBinaryData[MAX_USER_BINARY_BLOCK_BUM];  // �û��Զ�����������ݿ�
	char byReserve[64];                                          // ����
}USER_BINARY_DATA_LIST;


// ���淽�����ݽ���ʱ��֪ͨ�ص�
typedef int (__stdcall *pFnSigFinishedCallback)(void* pUserData);

typedef struct 
{
	eCUSTOM_USERDATA_TYPE eUserDataType; // �û��Զ������ݸ�ʽ��ȡֵ�μ�CUSTOM_USERDATA_TYPE����û���Զ������ݣ���ΪUSERDATA_INVALID��
	union
	{
        USER_BINARY_DATA_LIST struBinaryDataList;  // �û��Զ������������
		char byReserved[34372];                    // �������С
	}uUserData;
}CUSTOM_USER_DATA;


typedef struct
{   
	PARAM_VALUE_INFO_LIST struParamValueList;   // �㷨�����б�
	CUSTOM_USER_DATA      struCustomUserData;   // �û��Զ�������
	char*                 pszAttachmentsDir;    // �����еĸ����ļ�·�����籣��ʱ�ɽ�ͼƬ�������ļ���������Ŀ¼�£�
	                                            // ����ʱ���ٴӴ�Ŀ¼�¶�ȡ������ļ���ע���ж��Ƿ�ΪNULL��ΪNULLʱ��
	                                            // �뽫�ļ����ݱ�����struCustomUserData��ʶ���Զ������ݿ�����С�
	char                  byReserved[56];       // ����
}MODULE_DATA;


typedef struct  
{
	MODULE_DATA struModuleData;            // ģ������
	pFnSigFinishedCallback pfnSigCallback; // ���淽�����ʱ��֪ͨ�ص��������ڴ˺������ͷ��򱣴淽�����������Դ�������ã���ΪNULL���ɡ�
	void* pSigUserData;                    // Ϊ�ص�����������Զ������ݡ������ã���ΪNULL���ɡ�
	char byReserved[128];                  // ����
}SAVE_MODULE_DATA_PARAM;


typedef struct  
{
	MODULE_DATA struModuleData;  // ģ������
	char byReserved[128];        // ����
}LOAD_MODULE_DATA_PARAM;


typedef struct
{
	char*        pImgData;        // ͼƬ����
	unsigned int nImgDataLen;     // ͼƬ����
	char         byCopyMode;      // 0-�����1-ǳ����
	char         byReserved[127]; // ����     
}IMAGE_DATA;

typedef struct
{
    char*        pImgData;        // ͼƬ����
    unsigned int nImgDataLen;     // ͼƬ����
    char         byCopyMode;      // 0-�����1-ǳ����
    char         chSharedMemoryName[SHARED_MEM_NAME_LEN];
    char         byReserved[127]; // ����     
}IMAGE_DATA_V2;

typedef struct 
{
	int  nProcedureId;                        // ����ID
	char byProcedureName[PROCEDURE_NAME_LEN]; // ��������
	char byReserve[256];                      // ����
}CREATE_PROCEDURE_PARAM;


typedef struct 
{
	char byProcedureName[PROCEDURE_NAME_LEN]; // ��������
	char byExcludeFromAll;                    // �������Σ�0-�رգ�1-����
	char byReserve[255];                      // ����
}UPDATE_PROCEDURE_PARAM;


typedef struct 
{
	int  nProcedureId;                           // ����ID
	int  nModuleId;                              // ģ��ID
	char byModuleName[MODULE_NAME_LEN];          // ģ������
	char byDisplayName[MODULE_DISPLAY_NAME_LEN]; // ģ����ʾ����
	char byGuid[GUID_LEN];                       // guid��Ϣ
	char byReserve[472];                         // ����
}ADD_MODULE_PARAM;


typedef struct
{
	int  nProcedureId;                           // ����ID
	int  nModuleId;                              // ģ��ID
	char byModuleName[MODULE_NAME_LEN];          // ģ������
	char byDisplayName[MODULE_DISPLAY_NAME_LEN]; // ģ����ʾ����
	char byReserve[512];                         // ����
}MODULE_INFO;


typedef struct 
{
	char byDisplayName[MODULE_DISPLAY_NAME_LEN]; // ģ����ʾ����
	char byReserve[256];                         // ����
}UPDATE_MODULE_PARAM;

typedef struct
{
	char byEnable;        // ģ���Ƿ���ã�0-���ã���0-����  
	char byUploadRst;     // �Ƿ��ϱ������0-���ã���0-�ϱ�
	char byReserve[254];  // ����
}MODULE_STATE;

typedef struct  
{
	ADD_MODULE_PARAM struModuleParam; // ģ�����
	MODULE_STATE     struModuleState; // ģ��״̬
	char             byReserve[256];  // ����
}BATCH_ADD_MODULE_PARAM;

typedef struct  
{
	int  nProcedureId;     // ����Id
	int  nLoopId;          // ѭ��Id
	char byEnable;         // �����ԣ�0-���ã���0-����  
	char byGuid[GUID_LEN]; // GUID
	char byReserve[215];   // ����
}BATCH_ADD_LOOP_PARAM;

typedef struct
{
	int  nProcedureId;     // ����Id
	int  nLoopId;          // ѭ��Id
	char byGuid[GUID_LEN]; // GUID
	char byReserve[512];   // ����
}ADD_LOOP_PARAM_EX;

typedef struct
{
	char byDisplayName[MODULE_DISPLAY_NAME_LEN]; // ģ����ʾ����
	int  nType;                                  // ģ������
	char byReserve[256];                         // ����
}MODULE_CONFIG_PARAM;


typedef enum : int
{
	FIELD_TYPE_INVALID   = 0,  // ��Ч
	FIELD_TYPE_INT       = 1,  // ����
	FIELD_TYPE_FLOAT     = 2,  // ����
	FIELD_TYPE_STRING    = 3,  // �ַ���
	FIELD_TYPE_IMAGE     = 4,  // ͼ��
	FIELD_TYPE_POINTSET  = 5,  // �㼯
	FIELD_TYPE_BYTEARRAY = 6   // �����ƿ�
}eFIELD_TYPE;


struct  MODULE_PARAM
{  
	int  nModuleId;                     // ģ��ID
	char byParamName[MAX_IO_NAME_LEN];  // ������
	char byReserve[64];                 // ����
};

typedef MODULE_PARAM MODULE_SRC_PARAM;


// ������ģ���������������
enum eVAR_INDEX_TYPE : int
{
	VAR_INDEX_INVALID  = 0,  // ��Ч
	VAR_INDEX_ALL      = 1,  // ����ȫ��
	VAR_INDEX_CONSTANT = 2,  // ��������
	VAR_INDEX_VARIABLE = 3   // ����
};

// �����ı���ֵ����
enum eVAR_TYPE_TYPE : int
{
	VAR_VALUE_INVAlID  = 0,  // ��Ч
	VAR_VALUE_CONSTANT = 1,  // ����
	VAR_VALUE_GLOBAL   = 2,  // ȫ���ַ���
	VAR_VALUE_VARIABLE = 3   // ����
};

typedef struct
{   
	eVAR_INDEX_TYPE eIndexType;    // �������ͣ����鶩��ʱ��Ч����ΪVAR_INDEX_INVALIDʱ����ʾ�����鶩�ģ��ֶ�uVarIndex��Ч��
	union
	{
		int nConstant;            // ��������ֵ
		MODULE_PARAM indexVar;    // ��������ֵ
	}uVarIndex;
	MODULE_PARAM struModuleParam; // ������ģ�����
}VARIABLE_VALUE;


typedef struct
{
	eVAR_TYPE_TYPE eVarType;                           // �����ı�������
	union
	{
		char szConstantValue[MAX_CONSTANT_VALUE_LEN]; // ����
		VARIABLE_VALUE struVariableValue;             // ����
	}uVarValue;
	char byReserve[64];                               // ����
}MODULE_DST_PARAM;


typedef struct  
{
	MODULE_SRC_PARAM struSrcParam; // Դ����
	MODULE_DST_PARAM struDstParam; // �����ı���
	char byReserve[64];            // ����
}SUBSCRIBE_PARAM;


typedef struct  
{
	int nNum;                                             // ��Ч���ĵ��ֶθ���
	SUBSCRIBE_PARAM subscribeParamList[SUBSCRIBE_NUM];    // �����ֶ��б�
	char byReserve[128];                                  // ����
}SUBSCRIBE_PARAM_LIST;


typedef struct  
{
	int nNum;                             // ��ЧID����
	int nModuleIdList[MAX_SUCCESSOR_NUM]; // ģ��ID�б�
	char byReserve[64];                   // ����
}LOOP_NODE_LIST;


typedef struct
{
	int nParentLoopId;                    // ��ѭ��ID
	int nStartIndex;                      // ��ʼ��������0��ʼ
	int nStopIndex;                       // ��������
	int nInterval;                        // ѭ�����м������λ�����룩
	LOOP_NODE_LIST struInnerHeadList;     // ѭ���ڲ��׽ڵ��б�
	LOOP_NODE_LIST struInnerTailList;     // ѭ���ڲ��׽ڵ��б�
	LOOP_NODE_LIST struOuterHeadList;     // ѭ���ⲿ�׽ڵ��б�
	LOOP_NODE_LIST struOuterTailList;     // ѭ���ⲿβ�ڵ��б�
	char byReserve[128];                  // ����
}LOOP_INFO;


typedef struct 
{
	int  nModuleId;                              // ģ��ID
	char byModuleName[MODULE_NAME_LEN];          // ģ������
	char byDisplayName[MODULE_DISPLAY_NAME_LEN]; // ģ����ʾ����
}NEXT_MODULE_INFO;


typedef struct  
{
	int nNum;                                           // ��Ч����
	NEXT_MODULE_INFO struModuleList[MAX_SUCCESSOR_NUM]; // ���ģ���б�
	char byReserve[128];                                // ����
}NEXT_MODULE_INFO_LIST;


typedef struct
{
	char byValid;           // �Ƿ���Ч��0-��Ч��1-��Ч
	char byReserve1[3];     // ����
	int  nLoopIndex;        // ѭ����ǰ��ִ�д���
	int  nLoopTimes;        // ѭ���ܴ�������nLoopIndex=nLoopTimesʱ��ʾѭ������
	char byReserve2[128];   // ����           
}LOOP_RUN_INFO;


typedef struct  
{
	float fAlgorithmTime;       // �㷨ʱ��
	float fGetTime;             // Process getʱ��
	float fSetTime;             // Process setʱ��
	double fRunBeginTime;       // ģ�鿪ʼ����ʱ�������λ�����루ֻ������ȡʱ��Ч��
	double fRunEndTime;         // ģ���������ʱ�������λ�����루ֻ������ȡʱ��Ч��
	LOOP_RUN_INFO struLoopInfo; // ģ��ֱ��ѭ����Ϣ��ֻ������ȡʱ��Ч��
	unsigned int nExecuteId;    // ��ǰ����ִ��ID(ֻ����
	char  byReserve[512];       // ����
}MODULE_RUNTIME_INFO;


typedef struct
{
	int  nProcedureId;                           // ģ����������ID
	int  nModuleId;                              // ģ��ID
	char szModuleName[MODULE_NAME_LEN];          // ģ������
	char szDisplayName[MODULE_DISPLAY_NAME_LEN]; // ��ʾ����
	char szGuid[GUID_LEN];                       // GUID
	char byReserve1[216];                        // ����
	int  nType;                                  // ģ������
	int  nErrCode;                               // ģ���ʼ����ɣ�������
	char byReserve2[128];                        // ����
}ADD_MODULE_FINISHED_PARAM;


typedef struct 
{
	int  nErrCode;                       // ������
	int  nModuleId;                      // ģ��ID
	char byModuleName[MODULE_NAME_LEN];  // ģ������
	char byReserve[128];                 // ����
}MODULE_ERR_INFO;

typedef struct  
{
	int nNum;                                          // ��Ч��Ϣ����
	MODULE_ERR_INFO struErrInfo[MODULE_ERRLIST_SIZE];  // ������Ϣ�б�;
	char byReserve[128];                               // ����
}MODULE_ERR_INFO_LIST;


typedef struct  
{
	int                  nFrameErrCode;      // ģ���ܴ����룬��0ʱ��ʾ���ɼ����Ĵ���ģ����������Ϣ����ĳ�ԱstruModuleErrList
	MODULE_ERR_INFO_LIST struModuleErrList;  // ģ�������Ϣ�б�
	char                 byReserve[256];     // ����
}BATCH_ADD_MODULE_FINISHED_PARAM;


enum ePROCEDURE_STATUS : int
{
	PROCEDURE_STATUS_INVALID   = 0, // ��Ч��δ֪
	PROCEDURE_STATUS_FREE      = 1, // ����
	PROCEDURE_STATUS_BUSY      = 2, // æµ
	PROCEDURE_STATUS_STOPPED   = 3  // ֹͣ
};

enum ePROCEDURE_STOP_ACTION : int
{
	PROCEDURE_STOPPED_INVALID   = 0, //  ��Ч
	PROCEDURE_STOPPED_NORMAL    = 1, //  ����ֹͣ
	PROCEDURE_STOPPED_NG        = 2, //  ����NG
	PROCEDURE_STOPPED_BYMODULE  = 3  //  ģ������ֹͣ����
};

typedef struct  
{
	int nProcedureId;                   // ����ID
	ePROCEDURE_STATUS nProcedureStatus; // ����״̬
	float  fProcedureTime;              // ����ִ�к�ʱ����λ�����루��nProcedureStatusΪ PROCEDURE_STATUS_FREE ʱ��Ч��
	unsigned int nExecuteCount;         // ����ִ�д���
	ePROCEDURE_STOP_ACTION nStopAction; // ����ֹͣ��ԭ�򣨵�nProcedureStatusΪ PROCEDURE_STATUS_STOPPED ʱ��Ч��
	char byTriggerCmd[TRIGGER_CMD_LEN]; // ���̴�������
	char byReserve[104];                // ����
}PROCEDURE_STATUS_PARAM;


typedef struct
{
	int   nModuleId;       // ģ��ID
	int   nType;           // �������ͣ����û����壬SDK͸��
	char* pData;           // �û����ݣ��ռ���SDK����
	int   nDataLen;        // �û����ݳ���
	char  byReserve[128];  // ����
}MODULE_REPORT_DATA_PARAM;

typedef struct
{
	int  nInterval;       // �������м������λ�����룩
	char byContinuousRun; // �Ƿ����������У�1-�ǣ�0-��(ֻ��)
	char byStopWhenNG;    // ����NGʱֹͣ����,1-�ǣ�0-��
	int  nFlag;           // ��ʾ��Щֵ��Ч����λȡ��ֵ��0x00-��ʾ���У�0x01-nInterval��Ч��0x02-byContinuousRun��Ч��0x04-byStopWhenNG��Ч��0x08-nWaitTime��Ч��
	int  nWaitTime;       // ���̳�ʱʱ�䣨��λ�����룩��Ĭ��Ϊ0��ʾ���賬ʱ�޶�
	char byReserve[502];  // ����
}PROCEDURE_RUNNING_PARAM;

typedef struct  
{
	int  nModuleId;                      // ģ��ID
	char szModuleName[MODULE_NAME_LEN];  // ģ������
	int  nErrCode;                       // ������
	char byReserve[256];                 // ����
}LOAD_MODULE_FINISHED_PARAM;

typedef struct  
{
	int  nModuleId;                      // ģ��ID
	char szModuleName[MODULE_NAME_LEN];  // ģ������
	int  nErrCode;                       // ������
	char byReserve[256];                 // ����
}SAVE_MODULE_FINISHED_PARAM;


typedef struct  
{
	int  nErrCode;                       // ������
	char byReserve[256];                 // ����
}LOAD_SOLUTION_FINISHED_PARAM;

//�����ļ�ʱ�Ĳ�������
typedef struct
{
    char     szName[256]; // ���ƣ��ڲ�ʹ�õ���wchar[128]
    char*    pData;       // ����������
    int      nDataLen;    // ���ݳ���
}EXPORT_DATA_IN_FILE;

typedef struct  
{
	int                  nErrCode;       // ������
    char                 szHeader[8];    // ͷ��Ϣ�������汾������
    int                  nDataNum;       // ���ݸ���
    EXPORT_DATA_IN_FILE* pstData;        // ����������ָ��
	char byReserve[236];                 // ����
}SAVE_SOLUTION_FINISHED_PARAM;

typedef EXPORT_DATA_IN_FILE IMPORT_DATA_IN_FILE;

typedef struct
{
    int nSolVersion;
    int nModuleNum;
    IMPORT_DATA_IN_FILE* pstData;
    char byReserve[128];
}FILE_IMPORT_DATA;

typedef struct
{
	int  nErrCode;                       // ������
	char byReserve[256];                 // ����
}IMPORT_GROUP_FINISHED_PARAM;

typedef struct
{
    int                  nErrCode;       // ������
    char                 szHeader[8];    // ͷ��Ϣ�������汾������
    int                  nDataNum;       // ���ݸ���
    EXPORT_DATA_IN_FILE* pstData;        // ����������ָ��
    char byReserve[236];                 // ����
}EXPORT_GROUP_FINISHED_PARAM;


typedef struct
{
	int  nErrCode;                       // ������
	char byReserve[256];                 // ����
}IMPORT_PROCEDURE_FINISHED_PARAM;

typedef struct
{
    int                  nErrCode;       // ������
    char                 szHeader[8];    // ͷ��Ϣ�������汾������
    int                  nDataNum;       // ���ݸ���
    EXPORT_DATA_IN_FILE* pstData;        // ����������ָ��
    char byReserve[236];                 // ����
}EXPORT_PROCEDURE_FINISHED_PARAM;

enum eCLOSE_SOLUTION_STATE : int
{
	CLOSE_SOLUTION_INVALID = 0,          // ��Ч
	CLOSE_SOLUTION_BEIGN   = 1,          // �رտ�ʼ
	CLOSE_SOLUTION_FINISH  = 2           // �ر����
};

enum eCREATE_MODULE_CAUSE : int
{
	CREATE_CAUSE_INVALID  = 0,  // ��Ч
	CREATE_CAUSE_ADDONE   = 1,  // ��ͨ���
	CREATE_CAUSE_LOADSOL  = 2   // ���ط���
};

typedef struct  
{
	eCLOSE_SOLUTION_STATE nState;       // �رշ���״̬
	char byReserve[256];                // ����
}CLOSE_SOLUTION_STATE_PARAM;

typedef struct 
{
	eFIELD_TYPE nOutputType;             // ����ֶ�����
	char byOutputName[MAX_IO_NAME_LEN];  // ����ֶ���
	MODULE_DST_PARAM  struDstParam;      // ����ֵ
	char byReserve[64];                  // ����
}CUSTOM_OUTPUT_RECORD;

typedef struct
{
	int nNum;                                                     // ��Ч����
	CUSTOM_OUTPUT_RECORD struOutputList[CUSTOM_OUTPUT_PAGE_SIZE]; // �Զ�������ֶ��б�
}CUSTOM_OUTPUT_RECORD_LIST;

typedef struct
{
	char byEnableUploadRst; // �Ƿ��ϴ�ģ������0-��1-��
	char byEnableBranch;    // �Ƿ����÷�֧���ܣ�0-��1-��
	char byReserve1[6];     // ����1
	char byReserve2[1024];  // ����2
}RUNNING_CONTROL_PARAM;

typedef struct
{
	char* pszTriggerCmd;   // �����ַ���
	char  byReserve[256];  // ����
}RUN_PROCEDURE_INPUT;

typedef struct
{
	unsigned int nExecuteCount; // ��ǰ����ִ�д���
	char  byReserve[256];       // ����
}RUN_PROCEDURE_OUTPUT;

typedef struct
{
	char byCpuCore[MAX_CORE_NUM]; // CPU�����飬0-��Ч��1-��Ч��
	                              // byCpuCore[0]��ʾcpu0��byCpuCore[1]��ʾcpu1, byCpuCore[2]��ʾcpu2...
	char byReserve[32];           // ����
}CPU_AFFINITY;

typedef struct
{
	int          nProcedureId;     // ����id
	int          nThreadNum;       // �������(id=nProcedureId),ָ����ִ���߳���Ŀ
	CPU_AFFINITY struCpuAffinity;  // �������(id=nProcedureId),ָ�����е�CPU���ġ�
	char         byReserve[64];    // ����
}PROCEDURE_CUSTOM_RUNNING_POLICY;

typedef struct
{
	int nNum;                                           // ��Ч����
	PROCEDURE_CUSTOM_RUNNING_POLICY struPolicyList[MAX_RUN_POLICY_NUM]; // ��������
	char byReserve[256];                                // ����
}PROCEDURE_CUSTOM_RUNNING_POLICY_LIST;


enum ePROCEDURE_RUN_POLICY : int
{
	PROCEDURE_RUN_POLICY_INVALID         = 0, // ��Ч
	PROCEDURE_RUN_POLICY_HIGH_SPEED      = 1, // ��������ģʽ��Ĭ�ϣ�
	PROCEDURE_RUN_POLICY_CUSTOM          = 2, // �û��Զ������з�ʽ
	PROCEDURE_RUN_POLICY_TIME_STABILITY  = 3  // ��֤��ʱ�ȶ���
};

typedef struct  
{
	ePROCEDURE_RUN_POLICY nRunPolicy; // �������з�ʽ
	union
	{
		PROCEDURE_CUSTOM_RUNNING_POLICY_LIST struCustom; // ��nRunPolicyΪ PROCEDURE_RUN_POLICY_CUSTOM ʱ��Ч
	}uPolicy;
	int  nCustomIndex;   // ��nRunPolicyΪ PROCEDURE_RUN_POLICY_CUSTOMʱ��Ч����ȡʱ����������������MAX_RUN_POLICY_NUMʱ��ָ��ȡֵ��ʼ����
	char byReserve[252]; // ����
}PROCEDURE_RUNNING_POLICY;


typedef struct
{
	ePROCEDURE_RUN_POLICY nRunPolicy; // �������з�ʽ
	union
	{
		PROCEDURE_CUSTOM_RUNNING_POLICY struCustom; // ��nRunModeΪ PROCEDURE_RUN_POLICY_CUSTOM ʱ��Ч
	}uPolicy;
	char byReserve[256]; // ����
}MODULE_OWNER_PROCEDURE_RUNNING_POLICY;


typedef struct  
{
	int  nLogicProcessorNum; // �߼�����������
	char byReserve1[4];      // ����
	char byReserve2[512];    // ����
}PROCESSOR_INFO;


typedef struct
{
	int  nProcedureId;                           // ����ID
	int  nGroupId;                               // Group ID
	char byDisplayName[MODULE_DISPLAY_NAME_LEN]; // ��ʾ����
	char byGuid[GUID_LEN];                       // guid��Ϣ
	char byReserve[512];                         // ����
}ADD_GROUP_PARAM;


typedef struct
{
	ADD_GROUP_PARAM  struGroupParam; // Group����
	MODULE_STATE     struGroupState; // Group״̬
	char             byReserve[256];  // ����
}BATCH_ADD_GROUP_PARAM;

typedef struct 
{
	int nGlobalModuleId;                    // ȫ�ֱ���ģ��ID
	eFIELD_TYPE nGlobalVarType;             // ȫ�ֱ�������
	char byGlobalVarName[MAX_IO_NAME_LEN];  // ȫ�ֱ�������
	MODULE_DST_PARAM struDstValue;          // ȫ�ֱ�����ֵ
	char byReserve[256];                    // ����
}BIND_GLOBALVAR_PARAM;

typedef struct  
{
	int nGlobalModuleId;                    // ȫ�ֱ���ģ��ID
	eFIELD_TYPE nGlobalVarType;             // ȫ�ֱ�������
	char byGlobalVarName[MAX_IO_NAME_LEN];  // ȫ�ֱ�������
	char byReserve[256];                    // ����
}UNBIND_GLOBALVAR_PARAM;

typedef struct  
{
	eFIELD_TYPE nVarType;   // IO����
	char byName[MAX_IO_NAME_LEN]; // IO����
	char byReserve[256];          // ����
}GROUP_IO_FIELD_PARAM;

typedef GROUP_IO_FIELD_PARAM PROCEDURE_IO_FIELD_PARAM;


typedef struct
{
	int  nSize;          // �����ڴ��С,�ֽ���
	int  nAlignment;     // �������ֽڶ���(4 / 8 / 16 / 32 / 64 / 128 / 256)
	int  nAttrs;         // ���㷨�ⶨ��ȡֵ��0-�ɸ����ڴ�, 1-���ɸ����ڴ�, 2-��̬�ڴ�Dynamic DDR
	int  nPlat;          // ���㷨�ⶨ��ȡֵ��1-CPU�ڴ�,2-GPU�ڴ�
	char byReserve[256]; // ����
}ALLOC_MEM_IN_POOL_INPUT;


typedef struct
{
	int  nProcedureId;                              // ����ID
	int  nModuleId;                                 // ģ��ID
	char byModuleName[MODULE_NAME_LEN];             // ģ������
	char byGuid[GUID_LEN];                          // guid��Ϣ
	char byDisplayName[MODULE_DISPLAY_NAME_LEN_EX]; // ģ����ʾ����
	char byReserve[512];                            // ����
}ADD_MODULE_PARAM_EX;


typedef struct
{
	ADD_MODULE_PARAM_EX struModuleParam; // ģ�����
	MODULE_STATE        struModuleState; // ģ��״̬
	char                byReserve[256];  // ����
}BATCH_ADD_MODULE_PARAM_EX;


typedef struct
{
	int  nProcedureId;                              // ����ID
	int  nModuleId;                                 // ģ��ID
	char byModuleName[MODULE_NAME_LEN];             // ģ������
	char byDisplayName[MODULE_DISPLAY_NAME_LEN_EX]; // ģ����ʾ����
	char byReserve[512];                            // ����
}MODULE_INFO_EX;


typedef struct
{
	char byDisplayName[MODULE_DISPLAY_NAME_LEN_EX]; // ģ����ʾ����
	char byReserve[256];                            // ����
}UPDATE_MODULE_PARAM_EX;

typedef struct
{
	int  nType;                                     // ģ������
	char byDisplayName[MODULE_DISPLAY_NAME_LEN_EX]; // ģ����ʾ����
	char byReserve[256];                            // ����
}MODULE_CONFIG_PARAM_EX;


typedef struct
{
	int  nModuleId;                                 // ģ��ID
	char byModuleName[MODULE_NAME_LEN];             // ģ������
	char byDisplayName[MODULE_DISPLAY_NAME_LEN_EX]; // ģ����ʾ����
	char byReserve[256];                            // ����
}NEXT_MODULE_INFO_EX;

typedef struct
{
	int nNum;                                              // ��Ч����
	NEXT_MODULE_INFO_EX struModuleList[MAX_SUCCESSOR_NUM]; // ���ģ���б�
	char byReserve[128];                                   // ����
}NEXT_MODULE_INFO_LIST_EX;


typedef struct
{
	int  nProcedureId;                              // ģ����������ID
	int  nModuleId;                                 // ģ��ID
	char szModuleName[MODULE_NAME_LEN];             // ģ������
	int  nType;                                     // ģ������
	char szGuid[GUID_LEN];                          // GUID
	char szDisplayName[MODULE_DISPLAY_NAME_LEN_EX]; // ��ʾ����
	int  nErrCode;                                  // ģ���ʼ����ɣ�������
	char byReserve[512];                            // ����
}ADD_MODULE_FINISHED_PARAM_EX;


typedef struct
{
	int  nProcedureId;                              // ����ID
	int  nGroupId;                                  // Group ID
	char byGuid[GUID_LEN];                          // guid��Ϣ
	char byDisplayName[MODULE_DISPLAY_NAME_LEN_EX]; // ��ʾ����
	char byReserve[512];                            // ����
}ADD_GROUP_PARAM_EX;

typedef struct
{
	ADD_GROUP_PARAM_EX  struGroupParam; // Group����
	MODULE_STATE        struGroupState; // Group״̬
	char                byReserve[256];  // ����
}BATCH_ADD_GROUP_PARAM_EX;

typedef struct
{
	int  nErrCode;                                   // ������
	int  nModuleId;                                  // ģ��ID
	char byModuleName[MODULE_NAME_LEN];              // ģ������
	char byDispalyName[MODULE_DISPLAY_NAME_LEN_EX];  // ��ʾ����
	char byReserve[128];                             // ����
}MODULE_ERR_INFO_EX;

typedef struct
{
	int nNum;                                          // ��Ч��Ϣ����
	MODULE_ERR_INFO_EX struErrInfo[MODULE_ERRLIST_SIZE];  // ������Ϣ�б�;
	char byReserve[128];                               // ����
}MODULE_ERR_INFO_LIST_EX;


typedef struct
{
	int                     nFrameErrCode;      // ģ���ܴ����룬��0ʱ��ʾ���ɼ����Ĵ���ģ����������Ϣ����ĳ�ԱstruModuleErrList
	MODULE_ERR_INFO_LIST_EX struModuleErrList;  // ģ�������Ϣ�б�
	char                    byReserve[256];     // ����
}BATCH_ADD_MODULE_FINISHED_PARAM_EX;


typedef struct  
{
	int  nModuleId;      // ��ǰģ��Id
	int  nOriModuleId;   // ӳ��ǰģ��Id
	char byReserve[128]; // ���� 
}MODULE_MAPPING;


typedef struct
{
	int  nModuleId;     // ģ��ID
	char byReserve[4];  // ����
}SELECTED_MODULE;


typedef struct
{
	int  nIndex;         // ��ʼ����
	int  nRequestNum;    // ����������ÿ�β�Ҫ����HISTORY_RST_PAGE_SIZE��С
    bool bRetImageData;  // ��ѯ���Ƿ񷵻�ͼ������
    char byReserve[28];  // ����
}MODULE_HISTORY_INPUT;

typedef struct
{
	char* pData;         // �������
	int   nLen;          // ����
	char  byReserve[4];  // ����
}SINGLE_MODULE_RESULT;

typedef struct
{
	SINGLE_MODULE_RESULT struModuleRst[HISTORY_RST_PAGE_SIZE]; // ��ʷ�������
	int   nReturnNum;        // ���صĽ������
	int   nTotalNum;         // �������
    bool  bRetImageData;     // �Ƿ񷵻�Image��������
    char  byReserve[28];     // ����
}MODULE_HISTORY_RESULT;


// ����ģ���ִ�н��
enum eMODULE_STATE : int
{
	MODULE_STATE_OK           = 0, // ִ����ɣ�OK
	MODULE_STATE_ERROR        = 1, // ִ����ɣ�ERROR
	MODULE_STATE_BRACH_IGNORE = 2, // ���֧�߼�δִ��
	MODULE_STATE_DISABLED     = 3  // ����
};

typedef struct
{
	int   nModuleId;             // ģ��ID
	eMODULE_STATE nProcessState; // ģ��ִ��״̬
	int   nModuleStatus;         // ģ����״̬
	float fAlgorithmTime;        // �㷨ʱ��
	float fProcessTime;          // ģ��processʱ��
	float fModuleTime;           // ģ���ܺ�ʱ
	char  byRunFlag;             // 0-����ִ��,1-��ִ��
	char  byReserve[15];         // ����
}MODULE_STATE_INFO;

typedef struct 
{
    int nProcedureId;// ģ����������ID
	int nNum; // �����С
	MODULE_STATE_INFO* pModuleInfoList; // ģ��״̬��Ϣ���飬�����СΪnNumָ����С
}MODULE_STATE_INFO_LIST;


typedef struct  
{
	char szInputName[MAX_IO_NAME_LEN]; // ��������
	char byUserSet;                    // 0-�ⲿδ����ȡֵ; 1-ȡֵ���ⲿ����
	char byReserve[15];
}MODULE_INPUT_STATE;


typedef struct 
{
	char szSolPath[1024]; // ����·��
	char szSolPwd[64];    // ��������
	char byReserve[128];  // ����
}REQUEST_CHANGE_SOL_PARAM;


typedef struct
{
	int  nDogStatus;    // 0-����������ֵ�쳣
	int  nCameraLimit;  // �����������
	char byReserve[32]; // ����
}CHECK_RUNNING_STATUS;


typedef struct  
{
	int nCameraNum;         // �������
	int cameraIdList[256];  // ���id�б�
}GLOBAL_CAMERA_LIST;


typedef struct
{
	int nModuleId;                      // ģ��ID
	char byParamName[MAX_IO_NAME_LEN];  // ��������
	eFIELD_TYPE nDstValueType;          // �����ֶ�����
	MODULE_DST_PARAM struDstValue;      // ������ֵ
	char byReserve[64];                 // ����
}MODULE_PARAM_BINDING;


typedef struct
{
	int nModuleId;                      // ģ��ID
	char byParamName[MAX_IO_NAME_LEN];  // ��������
	char byReserve[64];                 // ����
}MODULE_PARAM_UNBINDING;

typedef struct 
{
    int nModuleID;
    int nModuleStatus;
}MODULE_EXECUTE_STATUS;

typedef struct 
{
    int nModuleNum;
    MODULE_EXECUTE_STATUS struModuleStatus[MAX_PARAM_NUM];
    char byReserve[16];                 // ����
}BATCH_RUN_SELF_STATUS;

typedef struct
{
    char*           pMappingView;
    void*           hMapping;
    unsigned int    uiMappingSize;
    char            chMappingName[SHARED_MEM_NAME_LEN];
}SharedMemoryMappingInfo;

struct SHARED_MEM_HEADER
{
    uint64_t       nSize;          // ʵ�����ݴ�С����ͼƬ����
    unsigned char  byLightCopy;     // 0-�����1-ǳ����
    unsigned char  byReserve1[5];  // ����
    unsigned short nHeaderLen;     // ͷ����
    char           szSharedMemName[SHARED_MEM_NAME_LEN]; // �����ڴ�����
    char           byReserve2[48]; // ����
};


struct VARPARAM_BESUBJECT_MODULES_RUNPARAM_LIST
{
    int             nTotalNums;                             //�ܸ���
    MODULE_PARAM*   pSubjectInfo;                           //���в���������Ϣ
    char            byReserve2[128]; // ����
};


// ��־�ȼ�
enum eLOG_LEVEL : int
{
	LOG_LEVEL_NONE    = 0,
	LOG_LEVEL_FATAL   = 1,
	LOG_LEVEL_ERROR   = 2,
	LOG_LEVEL_WARNING = 3,
	LOG_LEVEL_INFO    = 4,
	LOG_LEVEL_DEBUG   = 5,
	LOG_LEVEL_VERBOSE = 6
};


// �¼�����
enum eEVENT_TYPE : int
{
	EVENT_INVALID                      = 0,  // ��Ч
	EVENT_ADD_MODULE_FINISHED          = 1,  // ���ģ����ɣ��¼�����ΪADD_MODULE_FINISHED_PARAM_EX
	EVENT_LOAD_MODULE_FINISHED         = 2,  // ����ģ����ɣ��¼�����ΪLOAD_MODULE_FINISHED_PARAM
	EVENT_SAVE_MODULE_FINISHED         = 3,  // ����ģ����ɣ��¼�����ΪSAVE_MODULE_FINISHED_PARAM
	EVENT_LOAD_SOLUTION_FINISHED       = 4,  // ���ط�����ɣ��¼�����ΪLOAD_SOLUTION_FINISHED_PARAM
	EVENT_SAVE_SOLUTION_FINISHED       = 5,  // ���淽����ɣ��¼�����ΪSAVE_SOLUTION_FINISHED_PARAM
	EVENT_PROCEDURE_STATUS             = 6,  // �ϱ�����״̬���¼�����ΪPROCEDURE_STATUS_PARAM
	EVENT_MODULE_REPORT_DATA           = 7,  // ģ������͸���ӿڣ��¼�����ΪMODULE_REPORT_DATA_PARAM
	EVENT_CLOSE_SOLUTION_STATE         = 8,  // �رշ���״̬���¼�����ΪCLOSE_SOLUTION_STATE_PARAM
	EVENT_BATCH_ADD_MODULE_FINISHED    = 9,  // �������ģ����ɣ��¼�����ΪBATCH_ADD_MODULE_FINISHED_PARAM_EX
	EVENT_IMPORT_GROUP_FINISHED        = 10, // ����Group��ɣ��¼�����ΪIMPORT_GROUP_FINISHED_PARAM
	EVENT_EXPORT_GROUP_FINISHED        = 11, // ����Group��ɣ��¼�����ΪEXPORT_GROUP_FINISHED_PARAM
	EVENT_IMPORT_PROCEDURE_FINISHED    = 12, // ����������ɣ��¼�����ΪIMPORT_PROCEDURE_FINISHED_PARAM
	EVENT_EXPORT_PROCEDURE_FINISHED    = 13, // ����������ɣ��¼�����ΪEXPORT_PROCEDURE_FINISHED_PARAM
	EVENT_REPORT_MODULE_STATE          = 14, // �ϱ�ģ��״̬��Ϣ���¼�����ΪMODULE_STATE_INFO_LIST
	EVENT_REQUEST_CHANGE_SOL           = 15, // ģ�������л��������¼�����ΪREQUEST_CHANGE_SOL_PARAM
    EVENT_BATCH_RUN_MODULE_FINISHED    = 16, // ����ִ��ģ��
    EVENT_REQUEST_FREE_PORT            = 17, // ��ȡ���ö˿ں�
};


// �¼�����
enum eNOTIFY_EVENT_TYPE : int
{
	NOTIFY_EVENT_INVALID          = 0,  // ��Ч
	NOTIFY_EVENT_SERVICE_READY    = 1,  // �ײ�����Ѿ���
	NOTIFY_EVENT_PROCEDURE_STATUS = 2   // ����״̬������ΪPROCEDURE_STATUS_PARAM
};


// ģ��ִ�н���ص�
typedef int (__stdcall *pFnResultCallback)(void* pRstData, int nRstDataLen, void* pUserData);

// �¼�֪ͨ�ص�����Ե��ȿ�ܡ�pEventDataΪ�¼�������ȡֵ����μ� eEVENT_TYPE ˵����
typedef int (__stdcall *pFnEventCallback)(int nEventType, void* pEventData, void* pUserData);

// �¼�֪ͨ�ص��������ͨģ�顣pEventDataΪ�¼�������ȡֵ����μ� NOTIFY_EVENT_TYPE ˵����
typedef int(__stdcall *pFnNotifyEventCallback)(int nEventType, void* pEventData, void* pUserData);

// ģ���Զ�������͸���ص�����Ե��ȿ�ܡ�
typedef int(__stdcall *pFnCustomDataTransCallback)(int nDataType, void* pCustomData, void* pUserData);

#endif
