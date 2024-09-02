#ifdef EXAMPLEMODULE_EXPORTS
#define LINEMODULE_API __declspec(dllexport)
#else
#define LINEMODULE_API __declspec(dllimport)
#endif
#include "VmModuleBase.h"
#include "VmAlgModuBase.h"
#include "ErrorCodeDefine.h"
#include "VmModuleSharedMemoryBase.h"

// This class is exported from the LineModule.dll
class LINEMODULE_API CAlgorithmModule : public CVmAlgModuleBase, public CModuleSharedMemoryBase
{
public:
	// ����
	explicit CAlgorithmModule();
	
	// ����
	virtual ~CAlgorithmModule();

public:

	// ��ʼ��
	int Init();

	// �����㷨
	int Process(IN void* hInput, IN void* hOutput, IN MVDSDK_BASE_MODU_INPUT* modu_input);

	// ��ȡ�㷨����
	int GetParam(IN const char* szParamName, OUT char* pBuff, IN int nBuffSize, OUT int* pDataLen);

	// �����㷨����
	int SetParam(IN const char* szParamName, IN const char* pData, IN int nDataLen);

public:
	//void* m_hModule;   // ģ���� - 4.3 �ڻ����ж�����


private:

	//======�Զ������======//

};


/////////////////////////////ģ���뵼���Ľӿڣ�ʵ�ֿ�ʼ��//////////////////////////////////////////
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
/////////////////////////////ģ���뵼���Ľӿڣ�ʵ�ֽ�����//////////////////////////////////////////
//////======�ļ�β======//