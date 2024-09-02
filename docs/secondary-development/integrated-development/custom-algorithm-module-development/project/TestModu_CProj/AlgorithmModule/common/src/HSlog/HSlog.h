/************************************************************************
* ��Ȩ��Ϣ����Ȩ����(c) 2022, ���ݺ��������˼������޹�˾.��������Ȩ��.
*
* �ļ����ƣ�HSlog.h
* ժ   Ҫ: hik spdlog �첽��־��
*
* ��   ��:  songzhenlong
* ��   �ڣ� 2022-06-15
* ��   ע��
************************************************************************/

#ifndef _HIK_SPEED_LOG_ASYNC_H_
#define _HIK_SPEED_LOG_ASYNC_H_
#include "HSlogDefine.h"

#ifdef _WIN32

#ifdef  HIK_SPDLOG_EXPORTS
#    define HSLOG_API __declspec(dllexport)
#else
#    define HSLOG_API __declspec(dllimport)
#endif
#else
#    define HSLOG_API __attribute__((visibility("default")))
#    define __stdcall
#endif

#ifndef LOG_FILE_SIZE_MAX
#define  LOG_FILE_SIZE_MAX                  (1048576 * 10)  //��־�ļ���С
#endif // !LOG_FILE_SIZE_MAX

#ifndef LOG_FILE_ROTATE_COUNT_DEFAULT
#define  LOG_FILE_ROTATE_COUNT_DEFAULT      (10)             //Ĭ����־�ļ��ع�����
#endif


#ifdef __cplusplus
extern "C"
{
#endif 

    /** @fn:    HSlog_Init_Module
    * @brief:   ģ���첽��־��ʼ�����ýӿ�Ŀǰ��ģ������е��á�VMģ���в�Ҫʹ�á�ģ��ֱ��ʹ���·�����־��ӡ��
    * @param:   pchFileName   ��־�ļ�����·��
    * @return:  int �ɹ�����0�����󷵻�����ֵ
    */
    HSLOG_API int __stdcall HSlog_Init_Module(const HSLOG_CHAR* pchFileName, bool bFlushOnTimer = true, unsigned int nFileSize = LOG_FILE_SIZE_MAX, unsigned int nRotateCount = LOG_FILE_ROTATE_COUNT_DEFAULT);

    /** @fn:    HSlog_Deinit_Module
    * @brief:   ģ���첽��־����ʼ�����ýӿ�Ŀǰ��ģ������е��á�VMģ���в�Ҫʹ��
    * @param:   pchFileName   ��־�ļ�����·��
    * @return:  int �ɹ�����0�����󷵻�����ֵ
    */
    HSLOG_API int __stdcall HSlog_Deinit_Module();

    /** @fn:    HSlog_ShouldLog
    * @brief:   �ж��Ƿ���Ҫ��ӡ��־
    * @param:   nlogLevel   ��־�ȼ�
    * @return:  bool ��Ҫ����true������false
    */
    HSLOG_API bool __stdcall HSlog_ShouldLog(HSlog_Level nlogLevel);

    /** @fn:    HSlog_LogPrint
    * @brief:   ��־��ӡ�ӿڣ�ģ�鲻����ã�ֱ��ʹ���·�����־��ӡ��
    * @param:   pchFileName   ��־�ļ�����·��
    * @return:  int �ɹ�����0�����󷵻�����ֵ
    */
    HSLOG_API void __stdcall HSlog_LogPrint(HSlog_Level nlogLevel, const char* format, ...);

    /** @fn:    HSlog_GetCurrentLevel
    * @brief:   ��ȡ��ǰ��־�ȼ�
    * @return:  ���ص�ǰ��־�ȼ�
    */
    HSLOG_API HSlog_Level __stdcall HSlog_GetCurrentLevel();

    /** @fn:    HSlog_ResetLevel
    * @brief:   ������־�ȼ���ģ���в�Ҫ���á�ģ���������ɶ�̬��������ȼ�
    * @param:   pchFileName   ��־�ļ�����·��
    * @return:  int �ɹ�����0�����󷵻�����ֵ
    */
    HSLOG_API void __stdcall HSlog_ResetLevel(HSlog_Level nlogLevel);

#ifdef __cplusplus
};
#endif 


#endif //end of _HIK_SPEED_LOG_ASYNC_H_
