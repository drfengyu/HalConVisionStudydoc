/************************************************************************
* ��Ȩ��Ϣ����Ȩ����(c) 2018, ���ݺ��������˼������޹�˾.��������Ȩ��.
*
* �ļ����ƣ�CrossPlatformFunc.h
* ժ   Ҫ:  ��װһЩ��ƽ̨�ĺ���ʵ�֡�
*
* ��   ��:  
* ��   �ڣ� 2021-10-25
* ��   ע�� ��ƽ̨���ú�����װʵ��
************************************************************************/
#ifndef _CROSSFLATFORM_FUNC_H_
#define _CROSSFLATFORM_FUNC_H_

// Windows Header Files:
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#else
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/statfs.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <dlfcn.h>
//#include <codecvt>
#include <locale>
#include <time.h>
#include <dirent.h>
#include <stdlib.h>
//#include <pthread.h>
//#include <signal.h>
//#include <semaphore.h>
//#include <arpa/inet.h>
//#include <netinet/in.h>
//#include <sys/socket.h>
#endif

#include <string>
#include <spdlog/spdlogApi.h>
#include "ErrorCodeDefine.h"
#include "VmModuleDef.h"
#include "CrossPlatformDef.h"


#ifndef _WIN32

#ifndef GetLastError
	int GetLastError();
#endif

#ifndef _tfopen
	FILE* _tfopen(const tchar* file, const tchar* mode);
#endif

#ifndef fopen_s
	int fopen_s(FILE** pFile, const char *filename, const char *mode);
#endif

#ifndef _ftime64_s
	int _ftime64_s(struct __timeb64 *tp);
#endif

// #ifndef _taccess_s
// int _taccess_s(const tchar *path, int mode);
// #endif

#ifndef _access
	int _access(const char *path, int mode);
#endif

#ifndef _access_s
	int _access_s(const char *path, int mode);
#endif

#ifndef _waccess_s
	int _waccess_s(const tchar *path, int mode);
#endif

// #ifndef _tmkdir
// int _tmkdir(const tchar *path);
// #endif

#ifndef _mkdir
	int _mkdir(const char *path);
#endif

#ifndef _stricmp
	int _stricmp(const char * dst, const char * src);
#endif

#ifndef stricmp
	int stricmp(const char * dst, const char * src);
#endif

#ifndef Sleep
	void Sleep(int nMillisecond);
#endif

#ifndef GetCurrentProcessId
	int GetCurrentProcessId();
#endif

#ifndef memcpy_s
	int memcpy_s(void *det, size_t detSize, const void * src, size_t srcSize);
#endif

#ifndef strcpy_s
	char* strcpy_s(char *dst, unsigned int size, const char *src);
#endif

#ifndef strncpy_s
	char* strncpy_s(char *dst, unsigned int detSize, const char *src, unsigned int srcSize);
#endif

#ifndef OutputDebugStringA
	void OutputDebugStringA(char* _chszLog);
#endif

#endif

#endif
