/***************************************************************************************************
*
* ��Ȩ��Ϣ����Ȩ���� (c) 2020, ���ݺ��������˼������޹�˾, ��������Ȩ��
*
* �ļ����ƣ�VmModuleSharedMemoryBase.h
* ժ    Ҫ�������ڴ����
*
* ��ǰ�汾��
* ��    ��:  �Ӿ�ƽ̨С��
* ��    �ڣ�2022-08-14
* ��    ע���½�
****************************************************************************************************/

#ifndef _IMVS_MVDSDK_SHARED_MEMORY_BASE_H_
#define _IMVS_MVDSDK_SHARED_MEMORY_BASE_H_

#include "VmModuleDef.h"
#include <map>
#include <memory>
#include <list>
#include <string>

#define IMAGE_MAPPING_HEADER_LEN  (sizeof(SHARED_MEM_HEADER))  // �����ڴ�ӳ����Ϣͷ����,�����ӱ���һ��
#define SHAREDMEMORY_NODE_NUM     1

typedef std::shared_ptr<SharedMemoryMappingInfo> CMappingInfoPtr;
typedef std::list<CMappingInfoPtr> CMappingInfoList;
typedef std::map<int, CMappingInfoList> CMappingInfoMap;

class CModuleSharedMemoryBase
{
public:
    CModuleSharedMemoryBase();
    virtual ~CModuleSharedMemoryBase();

protected:

    /**  @fn    AllocateSharedMemory
    *   @brief  ģ���������빲���ڴ�
    *   @param  [IN]  nModuleId       ģ��ID
                [IN]  nLen            �����ڴ泤��
                [OUT] pMemory         ���ڽ����ڴ�ָ��ı�����ָ�����ڴ�����ݣ��贫���ָ��
                [OUT] chSharedName    �����ڴ�����
                [IN]  nUsageType      ʹ�����ͣ���ģ�鶨�壬ͬһģ����ͬ���͵�����������������ڴ��н���ʹ��
    *   @remark
    *   @return �����룬�μ�ErrorCodeDefine.h
    */
    virtual int AllocateSharedMemory(IN int nModuleId, IN unsigned int nLen, IN OUT char** pMemory, IN OUT char** pSharedName, IN int nUsageType = 0);

    /**  @fn    ReleaseSharedMemory
    *   @brief  ���������ͷŹ����ڴ�,ģ��ɾ��ʱ���Զ��Ƿ��ģ������Ĺ����ڴ�
    *   @param  [IN]  nModuleId       ģ��ID
                [IN]  chSharedName    �����ڴ�����
    *   @remark
    *   @return �����룬�μ�ErrorCodeDefine.h
    */
    virtual int ReleaseSharedMemory(IN int nModuleId, IN char* pSharedName);

    /**  @fn    SetNodeNum
    *   @brief  ���ù����ڴ�ڵ���
    *   @param  [IN]  pData       ����
                [IN]  nDataLen    ���ݳ���
    *   @remark
    *   @return �����룬�μ�ErrorCodeDefine.h
    */
    virtual int SetNodeNum(IN const char* pData, IN int nDataLen);

    /**  @fn    SetNodeNum
    *   @brief  ��ȡ�����ڴ�ڵ���
    *   @param  [IN][OUT]  pData       ����
                [IN][OUT]  pDataLen    ���ݳ���
    *   @remark
    *   @return �����룬�μ�ErrorCodeDefine.h
    */
    virtual int GetNodeNum(IN OUT char** pData, IN OUT int* pDataLen);

private:
    int   CloseMapping(int nMdouleId, void* spMapping);
    int   CreateOpenMapping(int nMdouleId, void* spMapping);
    char* GetGuidStr();
    int   ParseSharedName(char* pSharedName, int& nModuleId, int& nUseType);

private:
    int   m_nNodeNum;
    char  m_chGuid[64];
    char  m_chNodeNum[16];
    CMappingInfoMap m_mapSharedMemoryInfo;
};

#endif
