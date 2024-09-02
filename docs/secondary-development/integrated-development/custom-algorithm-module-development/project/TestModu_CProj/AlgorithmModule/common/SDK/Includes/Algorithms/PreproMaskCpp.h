/***************************************************************************************************
* File��PreproMaskCpp.h
* Note��Interface for the mask image creating tool.
*
* Version��3.4.0.3
* Date��2021-01-05
***************************************************************************************************/
#ifndef _PREPRO_MASK_CPP_H_
#define _PREPRO_MASK_CPP_H_

#include <string>
#include "MVDImageCpp.h"
#include "MVDShapeCpp.h"


namespace VisionDesigner
{
    namespace PreproMask
    {
        /*  Note: This is the class for the PreproMaskTool. The PreproMaskTool encapsulates all of
            the classes required to perform a mask creating process.  */
        class IPreproMaskTool
        {
        protected:
            ///< Constructor and Destructor
            explicit IPreproMaskTool() {}
            virtual ~IPreproMaskTool() {}

        public:
            /**
             * @par ˵��
             * ����ͼ��Ĭ��ֵNULL
             * @par Ȩ��
             * ��д
             */
            virtual IMvdImage* GetInputImage() = 0;
            /**
             * @par ˵��
             * ����ͼ��
             * @par Ȩ��
             * ��д
             */
            virtual void SetInputImage(IMvdImage *pInputImage) = 0;

            /**
             * @par ˵��
             * ���ͼ��Ĭ��ֵNULL
             * @par Ȩ��
             * ֻ��
             */
            virtual IMvdImage* GetOutputImage() = 0;

            /**
             * @brief ִ�����Ӵ���
             * @param ��
             * @return �ޣ�����ʱ�׳��쳣
             * @par ע��
             * ��
             */
            virtual void Run() = 0;

            /**
             * @brief ��ӵ�������
             * @param pRegion [IN] �����ӵ�����Χͼ��
             * @param bRegionInterest [IN] ������ı���\��������;��trueʱΪ����Ȥ���򣬷���Ϊ��������
             * @return �ޣ�����ʱ�׳��쳣
             * @par ע��
             * ��֧�־��Ρ�Բ���Ȼ��Ͷ����
             */
             virtual void AddRegion(IMvdShape* pRegion, bool bRegionInterest) = 0;
            /**
             * @brief ��ȡ�������������
             * @return ����ͼ������;����ʱ�׳��쳣
             * @par ע��
             * ��
             */
            virtual unsigned int GetNumOfRegions() = 0;
            /**
             * @brief ����������ѯ���������ͼ����Ϣ
             * @param nIndex [IN] ͼ����������Χ[0, NumOfRegions)
             * @param ppRegion [IN][OUT] ������ͼ����Ϣ
             * @param pRegionInterest [IN][OUT] ������ı���\��������
             * @return �ޣ�����ʱ�׳��쳣
             * @par ע��
             * ppRegionָ���ڲ���ͼ��ʵ��,�ڲ�buffer
             */
            virtual void GetRegionAt(unsigned int nIndex, IMvdShape** ppRegion, bool* pRegionInterest) = 0;
            /**
             * @brief ���������������������ͼ����Ϣ
             * @param nIndex [IN] ͼ����������Χ[0, NumOfRegions)
             * @param pRegion [IN] �����Ϊ������ͼ����Ϣ
             * @param bRegionInterest [IN] ������ı���\��������;��trueʱΪ����Ȥ���򣬷���Ϊ��������
             * @return �ޣ�����ʱ�׳��쳣
             * @par ע��
             * ֧���޸�ͼ������
             */
            virtual void UpdateRegionAt(unsigned int nIndex, IMvdShape* pRegion, bool bRegionInterest) = 0;
            /**
             * @brief ���������Ƴ����������ͼ��
             * @param nIndex [IN] ͼ����������Χ[0, NumOfRegions)
             * @return �ޣ�����ʱ�׳��쳣
             * @par ע��
             * ��
             */
            virtual void RemoveRegionAt(unsigned int nIndex) = 0;
            /**
             * @brief �����������������
             * @return �ޣ�����ʱ�׳��쳣
             * @par ע��
             * ��
             */
            virtual void ClearRegions() = 0;
            /**
            * @par ˵��
            * ��Ĥͼ��Ĭ��ֵNULL
            * @par Ȩ��
            * ��д
            */
            virtual IMvdImage* GetMaskImage() = 0;
            /**
            * @par ˵��
            * ��Ĥͼ��
            * @par Ȩ��
            * ��д
            */
            virtual void SetMaskImage(IMvdImage *pMaskImage) = 0;

        private:
            IPreproMaskTool(IPreproMaskTool&);
            IPreproMaskTool& operator=(IPreproMaskTool&);
        };
    }
}


/*  Note:Interfaces to export.  */
#ifdef __cplusplus
extern "C" {
#endif

    /*  Note: Create tool instance for PreproMaskTool tool.  */
    MVD_CPP_API int __stdcall CreatePreproMaskToolInstance(VisionDesigner::PreproMask::IPreproMaskTool** ppToolInstance);
    /*  Note: Destroy tool instance for PreproMaskTool tool.  */
    MVD_CPP_API int __stdcall DestroyPreproMaskToolInstance(VisionDesigner::PreproMask::IPreproMaskTool* pToolInstance);

#ifdef __cplusplus
}
#endif 


#endif    ///< _PREPRO_MASK_CPP_H_
