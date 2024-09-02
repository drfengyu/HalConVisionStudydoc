/***************************************************************************************************
* File:  MVD_ErrorDefine.h
* Note:  ch: �㷨��SDK����ص�״̬�붨�塣
         En: SDK-related status code definition in namespace VisionDesigner.
*
* Version:  V3.2.0.3
****************************************************************************************************/


#ifndef _MVD_ERROR_DEFINE_H_
#define _MVD_ERROR_DEFINE_H_

#include "MVD_ErrorDefine_Exp.h"
#include "MVD_ErrorDefine_Algo.h"
#include "MVD_ErrorDefine_Cam.h"


// ch:��ȷ�붨�� | en:Definition of correct code
const static int MVD_OK                      = 0x00000000;    ///< �ɹ����޴��� | en:Successed, no error
const static int MVD_E_MIN                   = 0x80100000;    ///< �㷨��SDK�Ĵ�������Сֵ | en:Minimum value of the SDK-releated error code.
const static int MVD_E_MAX                   = 0x8010FFFF;    ///< �㷨��SDK�Ĵ��������ֵ | en:Maximum value of the SDK-releated error code.

//�㷨��ͨ�ô����붨��:��Χ0x80100000-0x801000FF | en:Common error 
const static int MVD_E_HANDLE                = 0x80100000;    ///< �������Ч�ľ�� | en:Error or invalid handle
const static int MVD_E_SUPPORT               = 0x80100001;    ///< ��֧�ֵĹ��� | en:Not supported function
const static int MVD_E_OVER_ABILITY          = 0x80100002;    ///< �������Ƶ�������Χ | en: Beyond the limits of capacity
const static int MVD_E_CALLORDER             = 0x80100003;    ///< ��������˳����� | en:Function calling order error
const static int MVD_E_PRECONDITION          = 0x80100004;    ///< ǰ���������� | en:Precondition error
const static int MVD_E_PARAMETER_RANGE       = 0x80100005;    ///< ����������Χ���� | en:Parameter out of range limit
const static int MVD_E_PARAMETER_ILLEGAL     = 0x80100006;    ///< �����Ƿ� | en:Illegal parameter. Such as a null pointer
const static int MVD_E_PARAMETER_MATCH       = 0x80100007;    ///< �������಻ƥ�� | en:Parameters do not match each other
const static int MVD_E_PARAMETER_GENERIC     = 0x80100008;    ///< ͨ�ò������� | en:General parameter error
const static int MVD_E_RESOURCE              = 0x80100009;    ///< ��Դ����ʧ�� | en:Applying resource failed
const static int MVD_E_BUFOVER               = 0x8010000A;    ///< �������� | en:Out of memory
const static int MVD_E_NOOUTBUF              = 0x8010000B;    ///< û�п�����Ļ��� | en:No Avaliable Buffer
const static int MVD_E_NOENOUGH_BUF          = 0x8010000C;    ///< ������ڴ�ռ䲻�� | en:Insufficient memory prepared
const static int MVD_E_FILE_PATH             = 0x8010000D;    ///< ��֧�ֵ��ļ�·�� | en: Unsupported file path
const static int MVD_E_FILE_FORMAT           = 0x8010000E;    ///< ��֧�ֵ��ļ���ʽ | en: Unsupported file format
const static int MVD_E_FILE_CORRUPTED        = 0x8010000F;    ///< �ļ��� | en: Corrupted file
const static int MVD_E_FILE_GENERIC          = 0x80100010;    ///< ͨ���ļ����� | en: General file error
const static int MVD_E_NODATA                = 0x80100011;    ///< ������ | en:No data
const static int MVD_E_ABNORMAL_IMAGE        = 0x80100012;    ///< �쳣ͼ�� | en:Abnormal image
const static int MVD_E_VERSION               = 0x80100013;    ///< �汾��ƥ�� | en:Version mismatches
const static int MVD_E_LOAD_LIBRARY          = 0x80100014;    ///< ��̬����DLLʧ�� | en:Load library failed
const static int MVD_E_RUNTIME               = 0x80100015;    ///< ���л������� | en: Wrong with running environment
const static int MVD_E_NO_AVAILABLE_DEVICE   = 0x80100016;    ///< û�п����豸�������ڿ��õ��Կ������Կ�����δ����| en: No avaliable device
const static int MVD_E_UNKNOW                = 0x801000FF;    ///< δ֪�Ĵ��� | en:Unknown error

// �㷨�����������:��Χ0x80100200-0x801002FF
const static int MVD_ALGORITHM_E_ALGORITHM   = 0x80100201;    ///< ch: �㷨�汾���� | en:Unknown error on algorithms
const static int MVD_ALGORITHM_E_CONFIG      = 0x80100202;    ///< ch: �㷨���ô��� | en: Wrong configuration
const static int MVD_ALGORITHM_E_UNKNOW      = 0x80100203;    ///< ch: �㷨δ֪���� | en:Unknown error on algorithm SDK

// �ַ�ȱ�ݼ���㷨���
const static int MVD_ALGORITHM_E_MKINSP_ROUGH_MATCH_FAILED          = 0x80100204;    ///< ch: �ַ�ȱ�ݼ��ֶ�λʧ��
const static int MVD_ALGORITHM_E_MKINSP_MODEL_VERSION_NOT_SUPPORT   = 0x80100205;    ///< ch: �ַ�ȱ�ݼ��ģ��汾�Ų�֧��

#endif //_MVD_ERROR_DEFINE_H_

