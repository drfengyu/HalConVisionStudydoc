/***************************************************************************************************
* File:  MVD_CoreParamDefine.h
* Note:  Common parameter and data struct definition in namespace VisionDesigner.
*
* Version:  V3.2.0.3
****************************************************************************************************/

#ifndef _MVD_CORE_PARAM_DEFINE_H__
#define _MVD_CORE_PARAM_DEFINE_H__

#include <exception>
#include <iostream>
#include "MVD_ErrorDefine.h"
#include "MVD_Export.h"

namespace VisionDesigner
{
    #ifndef MVD_NULL
    #ifdef __cplusplus
        #define MVD_NULL    0
    #else
        #define MVD_NULL    ((void *)0)
    #endif
    #endif

    typedef __int32  MVD_BOOL;

    #ifndef MVD_TRUE
        #define MVD_TRUE 1
    #endif

    #ifndef MVD_FALSE
        #define MVD_FALSE 0
    #endif

    #ifndef MVD_ALGO_RUN_PARAM_MAX_LEN
        #define MVD_ALGO_RUN_PARAM_MAX_LEN (256)
    #endif

    #ifndef MVD_FLOAT_EPS
        #define MVD_FLOAT_EPS (0.0001)    ///< �����ж����
    #endif

    /** @struct MVD_MODULE_TYPE
    *  @brief  Enumeration definition for module type in the VisionDesigner namespace.
    */
    typedef enum _MVD_MODULE_TYPE_
    {
        MVD_MODULE_UNDEFINE = 0,     ///< ch: δָ����ģ�� | en: Unspecified module
        MVD_MODULE_ALGOR = 1,          ///< ch: �㷨��ص�ģ�� | en: Algorithm module
        MVD_MODUL_IMAGE = 2,             ///< ch: ͼ��ģ�� | en: Image module
        MVD_MODUL_SHAPE = 3,             ///< ch: ͼ��ģ�� | en: Shape module
        MVD_MODUL_TOOL = 4,              ///< ch: ����ģ�� | en: Algorithm tool module
        MVD_MODUL_RENDER = 5,         ///< ch: ��Ⱦģ�� | en: Render module
        MVD_MODUL_APP = 6,                  ///< ch: Ӧ�ó���ģ��(��ʾ������) | en: Application module (e.g. Demo)
        MVD_MODUL_ALGOR_INTEG = 7,         ///< ch: �㷨���ɿ�ģ��
        MVD_MODUL_CAMERA = 8               ///<ch: ��ҵ���ģ��
    }MVD_MODULE_TYPE;

    /** @struct MVD_PLATFORM_TYPE
    *  @brief  Enumeration definition for platform type.
    */
    typedef enum MVD_PLATFORM_TYPE
    {
        MVD_PLATFORM_UNDEFINE = 0,     ///< ch: δ����ƽ̨ | en: Unspecified platform
        MVD_PLATFORM_CPU = 1,          ///< ch: CPUƽ̨ | en: CPU platform
        MVD_PLATFORM_GPU = 2,          ///< ch: GPUƽ̨ | en: GPU platform
        MVD_PLATFORM_VDB = 4,          ///< ch: VDBƽ̨��������SDK340ϵͳ���Է�Χ | en: VDB platform,not included in the system test
    }MVD_PLATFORM_TYPE;


    // �쳣�ӿ��ඨ��
    class IMVDException : public std::exception
    {
    public:
        /*  note: Constructs a new instance of this class.  */
        IMVDException(MVD_MODULE_TYPE enModule, int enErrCode)
        {
            m_enErrorCode = enErrCode;
            m_enModuleType = enModule;
            InitDefaultDescription();
        }
        IMVDException(MVD_MODULE_TYPE enModule, int enErrCode, const char pcMsg[256])
        {
            memset(m_strDescription, 0, 256);
            memcpy_s(m_strDescription, 256, pcMsg, strlen(pcMsg));
            m_enErrorCode = enErrCode;
            m_enModuleType = enModule;
        }
        /*  note: Constructs a new instance of this class as a deep copy of the given instance.  */
        virtual ~IMVDException(void)
        {
            
        }

    public:
        virtual const int GetErrorCode(void) const throw()
        {
            return m_enErrorCode;
        }

        virtual const MVD_MODULE_TYPE GetModuleType(void) const throw()
        {
            return m_enModuleType;
        }

        virtual const char* GetDescription(void) const throw()
        {
            return m_strDescription;
        }

        virtual const char * what(void) const throw()
        {
            return m_strDescription;  // Todo:ϸ��
        }

    private:
        /*  note: Constructs a new instance of this class.  */
        explicit IMVDException(void)
        {
            m_enErrorCode = MVD_E_UNKNOW;
            m_enModuleType = MVD_MODULE_UNDEFINE;
            InitDefaultDescription();
        }

#pragma region
        void InitDefaultDescription(void)
        {
            memset(m_strDescription, 0, 256);
            if ((m_enErrorCode >= 0x10000000) && (m_enErrorCode <= 0x10FFFFFF))
            {
                memcpy(m_strDescription, "Algorithm error.", strlen("Algorithm error."));
                return;
            }

            if ((m_enErrorCode >= 0x80000000) && (m_enErrorCode <= 0x800004FF))
            {
                memcpy(m_strDescription, "Camera error.", strlen("Camera error."));
                return;
            }

            switch(m_enErrorCode)
            {
            case MVD_E_SUPPORT:
                {
                    memcpy(m_strDescription, "Not supported function.", strlen("Not supported function."));
                    break;
                }
            case MVD_E_OVER_ABILITY:
                {
                    memcpy(m_strDescription, "Beyond the limits of ability.", strlen("Beyond the limits of ability."));
                    break;
                }
            case MVD_E_CALLORDER:
                {
                    memcpy(m_strDescription, "Function call order is wrong.", strlen("Function call order is wrong."));
                    break;
                }
            case MVD_E_PRECONDITION:
                {
                    memcpy(m_strDescription, "Precondition error for current processing.", strlen("Precondition error for current processing."));
                    break;
                }
            case MVD_E_PARAMETER_RANGE:
                {
                    memcpy(m_strDescription, "Parameter out of range limit.", strlen("Parameter out of range limit."));
                    break;
                }
            case MVD_E_PARAMETER_ILLEGAL:
                {
                    memcpy(m_strDescription, "Illegal parameter. Such as a null pointer. ", strlen("Illegal parameter. Such as a null pointer."));
                    break;
                }
            case MVD_E_PARAMETER_MATCH:
                {
                    memcpy(m_strDescription, "Parameters do not match each other.", strlen("Parameters do not match each other."));
                    break;
                }
            case MVD_E_PARAMETER_GENERIC:
                {
                    memcpy(m_strDescription, "General parameter error.", strlen("General parameter error."));
                    break;
                }
            case MVD_E_RESOURCE:
                {
                    memcpy(m_strDescription, "Applying resource failed.", strlen("Applying resource failed."));
                    break;
                }
            case MVD_E_BUFOVER:
                {
                    memcpy(m_strDescription, "Out of memory.", strlen("Out of memory."));
                    break;
                }
            case MVD_E_NOOUTBUF:
                {
                    memcpy(m_strDescription, "No Avaliable Buffer.", strlen("No Avaliable Buffer."));
                    break;
                }
            case MVD_E_NOENOUGH_BUF:
                {
                    memcpy(m_strDescription, "Insufficient memory prepared.", strlen("Insufficient memory prepared."));
                    break;
                }
            case MVD_E_FILE_PATH:
                {
                    memcpy(m_strDescription, "Unsupported file path.", strlen("Unsupported file path."));
                    break;
                }
            case MVD_E_FILE_FORMAT:
                {
                    memcpy(m_strDescription, "Unsupported file format.", strlen("Unsupported file format."));
                    break;
                }
            case MVD_E_FILE_CORRUPTED:
                {
                    memcpy(m_strDescription, "Corrupted file.", strlen("Corrupted file."));
                    break;
                }
            case MVD_E_FILE_GENERIC:
                {
                    memcpy(m_strDescription, "General file error.", strlen("General file error."));
                    break;
                }
            case MVD_E_NODATA:
                {
                    memcpy(m_strDescription, "No data.", strlen("No data."));
                    break;
                }
            case MVD_E_ABNORMAL_IMAGE:
                {
                    memcpy(m_strDescription, "Abnormal image.", strlen("Abnormal image."));
                    break;
                }
            case MVD_E_VERSION:
                {
                    memcpy(m_strDescription, "Version mismatches.", strlen("Version mismatches."));
                    break;
                }
            case MVD_E_LOAD_LIBRARY:
                {
                    memcpy(m_strDescription, "Load library failed.", strlen("Load library failed."));
                    break;
                }
            case MVD_E_RUNTIME:
                {
                    memcpy(m_strDescription, "Wrong with running environment.", strlen("Wrong with running environment."));
                    break;
                }
            case MVD_E_NO_AVAILABLE_DEVICE:
            {
                memcpy(m_strDescription, "No available device.", strlen("No available device."));
                break;
            }
            case MVD_ALGORITHM_E_ALGORITHM:
                {
                    memcpy(m_strDescription, "Unknown error on algorithms.", strlen("Unknown error on algorithms."));
                    break;
                }
            case MVD_ALGORITHM_E_CONFIG:
                {
                    memcpy(m_strDescription, "Wrong configuration.", strlen("Wrong configuration."));
                    break;
                }
            default:
                {
                    memcpy(m_strDescription, "Undefined application error.", strlen("Undefined application error."));
                    break;
                }
            }
        }
#pragma endregion

    private:
        char m_strDescription[256];
        int m_enErrorCode;
        MVD_MODULE_TYPE m_enModuleType;
    };

    class IMVDPerformanceAssistant
    {
    protected:
        ///< Constructor and Destructor
        explicit IMVDPerformanceAssistant() {}
        virtual ~IMVDPerformanceAssistant() {}

    public:
        /**
        * @par ˵��
        * �̴߳�����
        * @par Ȩ��
        * ��д
        * @note �߳�����Χ[1, 64].Ĭ��Ϊ1
        *
        */
        virtual int GetThreadNum() = 0;

        /**
        * @par ˵��
        * �̴߳�����
        * @par Ȩ��
        * ��д
        * @note �߳�����Χ[1, 64].�������ò�����ϵͳ����.Ĭ��Ϊ1
        *
        */
        virtual void SetThreadNum(int nThreadNum) = 0;

        /**
        * @par ˵��
        * �̰߳󶨺�״̬
        * ��id��Ĥ,bit[0]��ʾCPU0��bit[1]��ʾCPU1
        * @par Ȩ��
        * ��д
        * @note ֵ��Χ[0, 2^p-1](pΪϵͳ����).Ĭ��Ϊ0
        *
        */
        virtual unsigned __int64 GetCoreBinding() = 0;

        /**
        * @par ˵��
        * �߳��̰߳󶨺�״̬
        * ��id��Ĥ,bit[0]��ʾCPU0��bit[1]��ʾCPU1
        * @par Ȩ��
        * ��д
        * @note ���߳�����Ϊ1ʱ��Ч,��0Ϊ����Ӧ�󶨡�
          ����������ĺˣ���Ҫ�󶨵�0�͵�2�ˣ���Ӧ������Ϊ0101��������������Ϊ��0��1��2��3�ˣ���Ҫ��������Ϊ1����תΪ10����Ϊ5�����÷�ʽSetCoreBinding(5)��
        *
        */
        virtual void SetCoreBinding(unsigned __int64 ulCoreBinding) = 0;
    };

}

#endif // _MVD_CORE_PARAM_DEFINE_H__
