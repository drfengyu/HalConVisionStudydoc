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

#ifndef _HIK_SPEED_LOG_ASYNC_DEFINE_H_
#define _HIK_SPEED_LOG_ASYNC_DEFINE_H_


#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN  //���winsock.h��winsock2.h�����ض�������
#include <windows.h>
#include <string>
#endif

#ifdef _UNICODE
#define HSLOG_CHAR                 wchar_t/*WCHAR*/
#define HSLOG_string               std::wstring
#define HSLOG_PATH_DIVIDE_STRING   L"\\"  //·���ָ�����Unicode��
#define HSLOG_PATH_POSTFIX         L"."  //��׺��ʶ��Unicode��
#define HSLOG_STRING_PREFIX(s)     L##s
#else
#define HSLOG_CHAR                 char
#define HSLOG_string               std::string
#define HSLOG_PATH_DIVIDE_STRING   "/"
#define HSLOG_PATH_POSTFIX         "."
#define HSLOG_STRING_PREFIX(s)     s
#endif


enum HSlog_Level
{
    HSlog_trace = 0,
    HSlog_debug,
    HSlog_info,
    HSlog_warn,
    HSlog_err,
    HSlog_critical,
    HSlog_off,
};



//��ȡģ�������࣬������ͷ�ļ��ж��壬�����ǵ����ࡣ
//ʹ�ø���־���ģ���ֱ�ӽ�����ʵ�ֱ��뵽�����У��ܹ�������ʱ��ȡģ��Ķ�̬������
class CHSlogModuleName
{
public:
    CHSlogModuleName()
    {
    }

    ~CHSlogModuleName()
    {
    }

    //��̬��ȡģ�����ƽӿڣ���֤һ��ģ��ֻ�е�һ�δ���־ʱִ��
    static std::string& GetModuleName()
    {
        //ģ������
        static std::string HSlog_s_strModuleName = GetDllFileNameUtf8();
        return HSlog_s_strModuleName;
    }

    static std::string GetDllFileNameUtf8()
    {
        //OutputDebugStringA("TEST  ");
        HSLOG_string strTmp;
        GetDllFileName(strTmp);
        std::string strName = HSlog_ToUtf8(strTmp);
        //std::string strddd = "TEST  " + strName;
        //OutputDebugStringA(strddd.c_str());
        return strName;
    }

    //�ڲ��ӿڣ���ȡdll�ļ�����
    static const HSLOG_CHAR* GetDllFileName(HSLOG_string& strModuleName)
    {
        //HSLOG_string strModuleName;
        strModuleName.clear();
#if _WIN32
        wchar_t chszModuleName[MAX_PATH] = { 0 };
        HMODULE hModule = NULL;
        GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            (LPCWSTR)&CHSlogModuleName::GetDllFileName, //���Ǻ�������ǿת
            &hModule);
        DWORD len = GetModuleFileName(hModule, chszModuleName, MAX_PATH);
        strModuleName = chszModuleName;

#else
        Dl_info dl_info;
        dladdr((void*)GetDllFilePath, &dl_info);
        strModuleName = dl_info.dli_fname;
        //ע���������ڿ�ִ�г���ͬ��Ŀ¼����Ŀ¼�µ��ã���õ�·��������ڿ�ִ�г��򣬷���õ��Ӹ�Ŀ¼��ľ���·��

#endif

        do
        {
            size_t nn = strModuleName.rfind(HSLOG_PATH_DIVIDE_STRING);
            if (strModuleName.npos == nn)
            {
                break;
            }
            strModuleName = strModuleName.substr(nn + 1);

            //ȥ����׺
            nn = strModuleName.rfind(HSLOG_PATH_POSTFIX);
            if (strModuleName.npos == nn)
            {
                break;
            }
            strModuleName = strModuleName.substr(0, nn);
        } while (0);
        return strModuleName.c_str();
    }

    //�ڲ��ӿڣ�Unicodeת��utf8
    static std::string HSlog_ToUtf8(const HSLOG_string str)
    {
#ifdef UNICODE
        if (str.length() == 0)
        {
            return "";
        }

        int  nCodePage = CP_UTF8;
        char*  pOutBuff = NULL;
        std::string strRst = "";
        const  int nTmpBuffLen = 256;
        char   pTmpBuff[nTmpBuffLen] = { 0 };
        bool   bHeapMem = false;

        try
        {
            do
            {
                int nOutLen = WideCharToMultiByte(nCodePage, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
                if (nOutLen <= 0)
                {
                    break;
                }

                // ����С�ַ���������ʹ��ջ�ڴ�
                if (nOutLen <= nTmpBuffLen)
                {
                    pOutBuff = pTmpBuff;
                }
                else
                {
                    pOutBuff = new char[nOutLen];
                    bHeapMem = true;
                }

                nOutLen = WideCharToMultiByte(nCodePage, 0, str.c_str(), -1, pOutBuff, nOutLen, NULL, NULL);
                if (nOutLen <= 0)
                {
                    break;
                }
                strRst = pOutBuff;

            } while (false);
        }
        catch (...)
        {
           
        }

        if (bHeapMem && pOutBuff != NULL)
        {
            delete[] pOutBuff;
        }
        return strRst;
#else
        return str;
#endif
    }


};

//����꣬��ȡģ��Ķ�̬�����ƣ�������־�������鿴
#define  HSlog_ModuleName   CHSlogModuleName::GetModuleName().c_str()

//�㷨ģ��/�߼�ģ��printf��ʽ��ӡ��־�����봫��ģ��ID
//������LOG_INFO(m_nModuId, "test log: cmd[%d] out[%s] file[%s]", nCmd, chTmp, strTmp.c_str());
#if (defined _WIN32 || defined _WIN64)
#pragma   warning(error:4003)//���������moduID����
#define MLOG_ERROR(mid, fmt, ...)        if(HSlog_ShouldLog(HSlog_err))   HSlog_LogPrint(HSlog_err,  "[%s] [ModuId:%d] [%s@%d] "fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define MLOG_WARN(mid, fmt, ...)         if(HSlog_ShouldLog(HSlog_warn))  HSlog_LogPrint(HSlog_warn, "[%s] [ModuId:%d] [%s@%d] "fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##__VA_ARGS__)    
#define MLOG_INFO(mid, fmt, ...)         if(HSlog_ShouldLog(HSlog_info))  HSlog_LogPrint(HSlog_info, "[%s] [ModuId:%d] [%s@%d] "fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##__VA_ARGS__)    
#define MLOG_DEBUG(mid, fmt, ...)        if(HSlog_ShouldLog(HSlog_debug)) HSlog_LogPrint(HSlog_debug,"[%s] [ModuId:%d] [%s@%d] "fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##__VA_ARGS__)    
#define MLOG_TRACE(mid, fmt, ...)        if(HSlog_ShouldLog(HSlog_trace)) HSlog_LogPrint(HSlog_trace,"[%s] [ModuId:%d] [%s@%d] "fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##__VA_ARGS__)   
#else
#define MLOG_ERROR(mid, fmt, args...)    if(HSlog_ShouldLog(HSlog_err))   HSlog_LogPrint(HSlog_err,  "[%s] [ModuId:%d] [%s@%d] " fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##args)
#define MLOG_WARN(mid, fmt, args...)     if(HSlog_ShouldLog(HSlog_warn))  HSlog_LogPrint(HSlog_warn, "[%s] [ModuId:%d] [%s@%d] " fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##args)
#define MLOG_INFO(mid, fmt, args...)     if(HSlog_ShouldLog(HSlog_info))  HSlog_LogPrint(HSlog_info, "[%s] [ModuId:%d] [%s@%d] " fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##args)
#define MLOG_DEBUG(mid, fmt, args...)    if(HSlog_ShouldLog(HSlog_debug)) HSlog_LogPrint(HSlog_debug,"[%s] [ModuId:%d] [%s@%d] " fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##args)
#define MLOG_TRACE(mid, fmt, args...)    if(HSlog_ShouldLog(HSlog_trace)) HSlog_LogPrint(HSlog_trace,"[%s] [ModuId:%d] [%s@%d] " fmt, HSlog_ModuleName, mid, __FUNCTION__, __LINE__, ##args)
#endif

#define LOG_ERROR(fmt, ...)         MLOG_ERROR(-1, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)          MLOG_WARN(-1, fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)          MLOG_INFO(-1, fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...)         MLOG_DEBUG(-1, fmt, ##__VA_ARGS__)
#define LOG_TRACE(fmt, ...)         MLOG_TRACE(-1, fmt, ##__VA_ARGS__)

#endif //end of _HIK_SPEED_LOG_ASYNC_DEFINE_H_
