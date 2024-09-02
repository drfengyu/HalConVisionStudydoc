/***************************************************************************************************
* File:  MVD_ErrorDefine_Exp.h
* Note:  ch: �㷨��ص�״̬�붨�壬������SDK V3.1�汾�С�
         En: Algorithm-related status code definition in namespace VisionDesigner. Only for SDK 3.1 version.
*
* Version:  V3.1.0.0
****************************************************************************************************/


#ifndef _MVD_ERROR_DEFINE_EXP_H_
#define _MVD_ERROR_DEFINE_EXP_H_

// �㷨ͨ��״̬��:��Χ0x80100100-0x801001FF
const static int MVD_ALGORITHM_E_ALGORITHM_CPUID           = 0x80100100;    ///< ch: cpu��֧���Ż������е�ָ� | en: CPU does not support optimizing instruction sets in code
const static int MVD_ALGORITHM_E_ALGORITHM_STEP            = 0x80100101;    ///< ch: ����step����ȷ����HKA_IMAGE�ṹ��֮�⣩ | en: Wrong with the 'step' of data
const static int MVD_ALGORITHM_E_ALGORITHM_DATA_SIZE       = 0x80100102;    ///< ch: ���ݴ�С����ȷ��һά����len����ά���ݵ�HKA_SIZE�� | en: Incorrect length or size of data
const static int MVD_ALGORITHM_E_ALGORITHM_BAD_ARG         = 0x80100103;    ///< ch: ������Χ����ȷ | en: Incorrect parameter range
const static int MVD_ALGORITHM_E_ALGORITHM_EXPIRE          = 0x80100104;    ///< ch: �㷨��ʹ�����޴��� | en: Error in limit of use of the Algorithmic Library
const static int MVD_ALGORITHM_E_ALGORITHM_ENCRYPT         = 0x80100105;    ///< ch: ���ܴ��� | en: Encryption error
const static int MVD_ALGORITHM_E_ALGORITHM_CALL_BACK       = 0x80100106;    ///< ch: �ص��������� | en: Wrong with the callback function
const static int MVD_ALGORITHM_E_ALGORITHM_OVER_MAX_MEM    = 0x80100107;    ///< ch: ����HKA�޶�����ڴ� | en: Exceeding the maximum memory limit
const static int MVD_ALGORITHM_E_ALGORITHM_NULL_PTR        = 0x80100108;    ///< ch: ��������ָ��Ϊ�գ����ã� | en: Empty function pointer is not allowed
const static int MVD_ALGORITHM_E_ALGORITHM_PARAM_NUM       = 0x80100109;    ///< ch: param_num��������ȷ | en: Incorrect name of the parameter
const static int MVD_ALGORITHM_E_ALGORITHM_PARAM_VALUE     = 0x8010010a;    ///< ch: value��������ȷ���߳�����Χ | en: Incorrect value of the parameter
const static int MVD_ALGORITHM_E_ALGORITHM_PARAM_INDEX     = 0x8010010b;    ///< ch: index��������ȷ | en: Incorrect index of the parameter
const static int MVD_ALGORITHM_E_ALGORITHM_FUNC_SIZE       = 0x8010010c;    ///< ch: �Ӵ���ʱ���롢���������С����ȷ | en: Incorrect size of I/O parameter for sub-processing
const static int MVD_ALGORITHM_E_ALGORITHM_FUNC_TYPE       = 0x8010010d;    ///< ch: �Ӵ������Ͳ���ȷ | en: Incorrect sub-processing type
const static int MVD_ALGORITHM_E_ALGORITHM_PRC_SIZE        = 0x8010010e;    ///< ch: ����ʱ���롢���������С����ȷ | en: Incorrect size of I/O parameter for processing
const static int MVD_ALGORITHM_E_ALGORITHM_PRC_TYPE        = 0x8010010f;    ///< ch: �������Ͳ���ȷ | en: Incorrect processing type
const static int MVD_ALGORITHM_E_ALGORITHM_CFG_SIZE        = 0x80100110;    ///< ch: ���á���ȡ�������롢����ṹ���С����ȷ | en: Incorrect size of the I/O structure for setting or getting parameter
const static int MVD_ALGORITHM_E_ALGORITHM_CFG_TYPE        = 0x80100111;    ///< ch: ���á���ȡ�������Ͳ���ȷ | en: Incorrect type of the I/O structure for setting or getting parameter
const static int MVD_ALGORITHM_E_ALGORITHM_IMG_DATA_NULL   = 0x80100112;    ///< ch: ͼ�����ݴ洢��ַΪ�գ�ĳ�������� | en: Empty address of the image data channel
const static int MVD_ALGORITHM_E_ALGORITHM_IMG_STEP        = 0x80100113;    ///< ch: ͼ������step������ƥ�䣨����ߺ�������ȣ� | en: Mismatch between image width and height and 'step' parameters
const static int MVD_ALGORITHM_E_ALGORITHM_IMG_SIZE        = 0x80100114;    ///< ch: ͼ���߲���ȷ���߳�����Χ | en: Incorrect or out-of-range image width or height
const static int MVD_ALGORITHM_E_ALGORITHM_IMG_FORMAT      = 0x80100115;    ///< ch: ͼ���ʽ����ȷ���߲�֧�� | en: Incorrect or out-of-range pixel format
const static int MVD_ALGORITHM_E_ALGORITHM_MEM_ADDR_ALIGN  = 0x80100116;    ///< ch: �ڴ��ַ���������Ҫ�� | en: Memory address does not meet alignment requirements
const static int MVD_ALGORITHM_E_ALGORITHM_MEM_SIZE_ALIGN  = 0x80100117;    ///< ch: �ڴ�ռ��С���������Ҫ�� | en: Memory space size does not meet alignment requirements
const static int MVD_ALGORITHM_E_ALGORITHM_MEM_LACK        = 0x80100118;    ///< ch: �ڴ�ռ��С���� | en: Insufficient memory space
const static int MVD_ALGORITHM_E_ALGORITHM_MEM_ALIGN       = 0x80100119;    ///< ch: �ڴ���벻����Ҫ�� | en: Memory alignment does not meet requirements
const static int MVD_ALGORITHM_E_ALGORITHM_MEM_NULL        = 0x8010011a;    ///< ch: �ڴ��ַΪ�� | en: Empty address of the memory
const static int MVD_ALGORITHM_E_ALGORITHM_ABILITY_ARG     = 0x8010011b;    ///< ch: ABILITY������Ч����(���Initʱ��ͼ�������) | en: Wrong with the algorithm ability(e.g. not supported)
const static int MVD_ALGORITHM_E_ALGORITHM_UNKNOW          = 0x8010011c;    ///< ch: �㷨��δ֪���� | en: Unknown Error in Algorithmic Library
const static int MVD_ALGORITHM_E_ALGORITHM_WARNING         = 0x8010011d;    ///< ch: �㷨����ֵ | en: Warning in Algorithmic Library

// �ַ�ʶ��״̬��:��Χ0x80100300-0x801003FF(����Ԥ��)
const static int MVD_ALGORITHM_E_OCR_ROI_TOO_SMALL               = 0x80100301;    ///< ch: ROI������㷨Ҫ�����С��ߡ�ģ��Ҫ�����С����ֵС | en: The ROI area is smaller than the minimum threshold required by the algorithm and the module.
const static int MVD_ALGORITHM_E_OCR_IMG_ABILITY_TOO_SMALL       = 0x80100302;    ///< ch: ͼ��������̫С | en: Beyond the limits of image ability.
const static int MVD_ALGORITHM_E_OCR_CHARACTER_ABILITY_TOO_SMALL = 0x80100303;    ///< ch: �ַ�������̫С | en: Beyond the limits of character ability.
const static int MVD_ALGORITHM_E_OCR_GENERATE_DATA_NUM           = 0x80100304;    ///< ch: �ֿ����Ӵ��������������� | en: Font library failed to increase the number of samples.
const static int MVD_ALGORITHM_E_OCR_NO_FONT_FILE                = 0x80100305;    ///< ch: �ַ�ʶ����ȱʧ�ֿ��ļ� | en: Character recognition processing failed because of missing font files.
const static int MVD_ALGORITHM_E_OCR_NO_TRAIN_DATA               = 0x80100306;    ///< ch: �ֿ�ѵ������ȱʧѵ������ | en: Font training failed because of missing training samples.
const static int MVD_ALGORITHM_E_OCR_TEXT_DETECT_OUT             = 0x80100307;    ///< ch: �ı������������ĵ㲻��ͼ���ڲ� | en: The center point of the area to detect text is not inside the image.
const static int MVD_ALGORITHM_E_OCR_TEXT_BOX_INVALID            = 0x80100308;    ///< ch: �ı��������ĸߡ���С���㷨֧�ֵ���С�ַ���С | en: The width or height of the area to detect text is smaller than the minimum character size supported by the algorithm.
const static int MVD_ALGORITHM_E_OCR_FONT_MISMATCH               = 0x80100309;    ///< ch: �ֿ����Ͳ�ƥ�� | en: Font type does not match.
const static int MVD_ALGORITHM_E_OCR_FONT_NO_MATCHING_TYPE       = 0x80100310;    ///< ch: �ֿ�û�����ʶ���ַ�����һ�µ����� | en: The font does not have a sample that matches the type of character to be recognized.
const static int MVD_ALGORITHM_E_OCR_EXCEED_MAX_LABEL_NUM        = 0x80100311;    ///< ch: ѵ���ַ���ǩ�������������� | en: 

// �ַ�ȱ�ݼ��״̬��:��Χ0x80100400-0x801004FF(����Ԥ��)
const static int MVD_ALGORITHM_E_MKINSP_PRC_TYPE_OR_MODU_ENABLE  = 0x80100401;    ///< ch: ���봦��������ģ��ʹ�ܲ�һ�� | en: Input processing type is inconsistent with the status of ModuleEnable
const static int MVD_ALGORITHM_E_MKINSP_MARK_NUM                 = 0x80100402;    ///< ch: ����box����С��MVBMKINSP_MARK_NUM_MIN��������õ������� | en: The number of boxes input less than MVBMKINSP_MARK_NUM_MIN or greater than the maximum number set
const static int MVD_ALGORITHM_E_MKINSP_MARK_BOX_SCALE           = 0x80100403;    ///< ch: �����ַ�box��С��Χ����ͼ��Χ����֮ǰ����ģ��ʹ�õ�mark_box��С��һ�� | en: The input character box size range is larger than the image range or different from the mark_box size used in the previous generation model.
const static int MVD_ALGORITHM_E_MKINSP_PROC_ORDER               = 0x80100404;    ///< ch: proc_order�����쳣 | en: Input exception
const static int MVD_ALGORITHM_E_MKINSP_MODEL_TYPE               = 0x80100405;    ///< ch: ģ���������Ͳ�һ�� | en: Model input type is inconsistent.
const static int MVD_ALGORITHM_E_MKINSP_MODEL_VERSION            = 0x80100406;    ///< ch: ģ������汾��һ�� | en: Model input version is inconsistent.
const static int MVD_ALGORITHM_E_MKINSP_MODEL_CONFIG             = 0x80100407;    ///< ch: ģ�ͱ���Ĳ����쳣 | en: Abnormal parameter saved by the model.

// ģ��ƥ��״̬��:��Χ0x80100500-0x801005FF(����Ԥ��)
const static int MVD_ALGORITHM_E_PATMATCH_FEATURES_NOT_ENOUGH       = 0x80100501;    ///< ch: �������㣺����ģ������ʧ�� | en: Failed to generate the feature modle
const static int MVD_ALGORITHM_E_PATMATCH_MATCH_TIME_OUT            = 0x80100502;    ///< ch: �㷨��ʱ��ƥ��ʱ����Ԥ������ʱ�� | en: Exceeded the scheduled processing time when matching
const static int MVD_ALGORITHM_E_PATMATCH_MATCH_VERSION_ERROR       = 0x80100503;    ///< ch: �㷨�汾�ų���ģ��汾����ƥ��汾���� | en: Algorithm version error. The version of the feature modle does not match the version of Matching.
const static int MVD_ALGORITHM_E_PATMATCH_MODEL_VERSION_ERROR       = 0x80100504;    ///< ch: ģ�Ͱ汾�ų���ģ��汾���뵱ǰ�汾���� | en: Modle version error. The version of modle input does match the current version.
const static int MVD_ALGORITHM_E_PATMATCH_MALLOC_MODEL_BUFF_FAIL    = 0x80100505;    ///< ch: ��ģʱ��ģ���ڴ�����ʧ�� | en: Model memory allocation failed while modeling.


#endif //_MVD_ERROR_DEFINE_EXP_H_

