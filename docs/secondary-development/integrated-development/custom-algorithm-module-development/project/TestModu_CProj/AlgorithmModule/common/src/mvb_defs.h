/***************************************************************************************************
* ��Ȩ��Ϣ��Copyright (c) 2010-2018, ���ݺ����������ּ����ɷ����޹�˾����������Ȩ��
* 
* �ļ����ƣ�mvb_defs.h
* 
* ժ    Ҫ��mvb ��غ궨��
* 
* ��ǰ�汾��0.1.0
* ��    �ߣ��޴���
* ��    �ڣ�2015��08��03��
* ��    ע����ʼ�汾
***************************************************************************************************/

#ifndef MVB_DEFS_H_
#define MVB_DEFS_H_

#include <memory.h>
#include <string.h> //memmove
#include <math.h>
#include <float.h>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include <memory.h>
#include <limits.h>
#if defined(__GNUC__)
#include <stdint.h>
#endif
#include "hka_defs.h"

#ifdef __cplusplus        
extern "C" 
{
#endif

/***************************************************************************************************
//���嶯̬�⵼�뵼��
***************************************************************************************************/
#if defined (WIN32) || defined (_WIN32) || defined (_WIN64)
#  define MVB_CDECL __cdecl
#  define MVB_STDCALL __stdcall
#else
#  define MVB_CDECL
#  define MVB_STDCALL
#endif

#if defined (WIN32) || defined (_WIN32) || defined (_WIN64)
#  if defined MVBAPI_EXPORTS
#    define MVB_EXPORTS __declspec(dllexport)
#  elif defined MVBAPI_DLL
#    define MVB_EXPORTS __declspec(dllimport)
#  else
#    define MVB_EXPORTS
#  endif
#else
#  define MVB_EXPORTS
#endif

#ifndef MVBAPI
#  define MVBAPI(rettype) MVB_EXPORTS rettype MVB_CDECL
#endif

/***************************************************************************************************
//����inline
***************************************************************************************************/
#if defined __cplusplus
#  define MVB_INLINE inline
#elif (defined (WIN32) || defined (_WIN32) || defined (_WIN64)) && !defined __GNUC__
#  define MVB_INLINE static __inline
#elif defined __GNUC__
#   define MVB_INLINE __inline__
#else
#  define MVB_INLINE static
#endif

#if defined(__GNUC__)
#define MVB_ALIGN(x) __attribute__ ((aligned (x)))
#elif defined(_MSC_VER)
#define MVB_ALIGN(x) __declspec(align(x))
#else
#define inline
#define MVB_ALIGN(x)
#endif
 
/***************************************************************************************************
//���帡�㳣��
***************************************************************************************************/
#define MVB_PIF    ( 3.14159265358979323846f )  // ANSI C does not support M_PI
#define MVB_2PIF   ( 6.28318530717958647692f )  // 2*pi
#define MVB_PI2F   ( 1.57079632679489661923f )  // pi/2
#define MVB_PI4F   ( 0.78539816339744830961f )  // pi/4
#define MVB_PI180F ( 0.01745329251994329577f )  // pi/180
#define MVB_180PIF ( 57.29577951308232f )       // 180/pi
#define MVB_RPIF   ( 0.31830988618379067154f )  // 1/pi
#define MVB_SQRT2F ( 1.41421356237309504880f )  // sqrt(2)
#define MVB_SQRT3F ( 1.73205080756887729353f )  // sqrt(3)
#define MVB_LN2F   ( 0.69314718055994530942f )  // ln(2)
#define MVB_LN3F   ( 1.09861228866810969139f )  // ln(3)
#define MVB_EF     ( 2.71828182845904523536f )  // e
#define MVB_REF    ( 0.36787944117144232159f )  // 1/e

#define MVB_PI    ( 3.14159265358979323846 )  // ANSI C does not support M_PI
#define MVB_2PI   ( 6.28318530717958647692 )  // 2*pi
#define MVB_PI2   ( 1.57079632679489661923 )  // pi/2
#define MVB_PI4   ( 0.78539816339744830961 )  // pi/4
#define MVB_PI180 ( 0.01745329251994329577 )  // pi/180
#define MVB_180PI ( 57.29577951308232 )       // 180/pi
#define MVB_RPI   ( 0.31830988618379067154 )  // 1/pi
#define MVB_SQRT2 ( 1.41421356237309504880 )  // sqrt(2)
#define MVB_SQRT3 ( 1.73205080756887729353 )  // sqrt(3)
#define MVB_LN2   ( 0.69314718055994530942 )  // ln(2)
#define MVB_LN3   ( 1.09861228866810969139 )  // ln(3)
#define MVB_E     ( 2.71828182845904523536 )  // e
#define MVB_RE    ( 0.36787944117144232159 )  // 1/e

//�ڴ����
#define MVB_MALLOC             malloc
#define MVB_FREE               free
#define MVB_MEMSET             memset
#define MVB_MEMCPY             memcpy
#define MVB_MEMMOVE            memmove
#define MVB_MEMCMP             memcmp

//�����
#define MVB_SRAND              srand
#define MVB_RAND               rand
#define MVB_RAND_MAX           RAND_MAX

//ʱ�亯��
#define MVB_TIME               time

//˫����
#define MVB_FABS(x)            fabs(x)
#define MVB_SQRT(x)            sqrt(x)
#define MVB_LOG(x)             log(x)
#define MVB_LOG10(x)           log10(x)
#define MVB_POW(x,y)           pow((x),(y))
#define MVB_EXP(x)             exp(x)
#define MVB_FLOOR(x)           floor(x)
#define MVB_CEIL(x)            ceil(x)

#define MVB_SIN(x)             sin(x)
#define MVB_COS(x)             cos(x)
#define MVB_TAN(x)             tan(x)
#define MVB_ASIN(x)            asin(x)
#define MVB_ACOS(x)            acos(x)
#define MVB_ATAN(x)            atan(x)
#define MVB_ATAN2(y, x)        atan2((y), (x))
#define MVB_SINH(x)            sinh(x)
#define MVB_COSH(x)            cosh(x)
#define MVB_TANH(x)            tanh(x)
#define MVB_FREXP(x, y)        frexp((x), (y))  // ��һ���������ֽ�Ϊβ����ָ��������
#define MVB_LDEXP(x, y)        ldexp((x), (y))  // ����value����2��exp���� 
#if defined(_WIN32) || defined (_WIN64)
#define MVB_HYPOT(x, y)        _hypot((x), (y))  //  ����ֱ�������ε�б�߳�
#define MVB_ISNAN(x)           _isnan((x))
#else
#define MVB_HYPOT(x, y)        hypot((x), (y))  //  ����ֱ�������ε�б�߳�
#define MVB_ISNAN(x)           isnan((x))
#endif

//������
#define MVB_FABSF(x)           fabsf(x)
#define MVB_SQRTF(x)           sqrtf(x)
#define MVB_LOGF(x)            logf(x)
#define MVB_LOG10F(x)          log10f(x)
#define MVB_POWF(x,y)          powf((x),(y))
#define MVB_EXPF(x)            expf(x)
#define MVB_FLOORF(x)          floorf(x)
#define MVB_CEILF(x)           ceilf(x)

#define MVB_SINF(x)            sinf(x)
#define MVB_COSF(x)            cosf(x)
#define MVB_TANF(x)            tanf(x)
#define MVB_ASINF(x)           asinf(x)
#define MVB_ACOSF(x)           acosf(x)
#define MVB_ATANF(x)           atanf(x)
#define MVB_ATAN2F(y, x)       atan2f((y), (x))
#define MVB_SINHF(x)           sinhf(x)
#define MVB_COSHF(x)           coshf(x)
#define MVB_TANHF(x)           tanhf(x)
#define MVB_FREXPF(x, y)       frexpf((x), (y))  // ��һ���������ֽ�Ϊβ����ָ��������
#define MVB_LDEXPF(x, y)       ldexpf((x), (y))  // ����value����2��exp���� 
#if defined(_WIN32) || defined (_WIN64)
#define MVB_HYPOTF(x, y)       _hypotf((x), (y)) //  ����ֱ�������ε�б�߳�
#define MVB_ISNANF(x)          _isnan((x))
#else
#define MVB_HYPOTF(x, y)       hypotf((x), (y)) //  ����ֱ�������ε�б�߳�
#define MVB_ISNANF(x)          isnan((x))
#endif

//����ȡģ
#define MVB_MODD(x,y)          fmod(x,y)
#define MVB_MODF(x,y)          fmodf(x,y)
#define MVB_ROUNDF(x)          (((x) < 0.0f) ? (HKA_S32)((x) - 0.5f) : (HKA_S32)((x) + 0.5f))
#define MVB_ROUND(x)          (((x) < 0.0) ? (HKA_S32)((x) - 0.5) : (HKA_S32)((x) + 0.5))

//ͼ�������С�ߴ�
#define MVB_IMG_WIDTH_MIN    (8)
#define MVB_IMG_WIDTH_MAX    (65535)
#define MVB_IMG_HEIGHT_MIN   (8)
#define MVB_IMG_HEIGHT_MAX   (65535)
#define MVB_IMG_MAX_PEL_NUM  (0x07ffffff) //���ͼ��ֱ���

#define MVB_HOMO_MIN_POINT_NUM        (4) // homograph������С��Ը���
#define MVB_CIRCLE_MIN_POINT_NUM      (3) // Բ�����С�����
#define MVB_LINE_MIN_POINT_NUM        (2) // ֱ�������С�����

#define MVBI_LINE_DETECT_RAY_NUM_MAX  (1000)   // �����������
#define MVBI_CALIPER_MAX_EDGE_PAIR_NUM  (1000) // ���߹�������Ե�����

#ifdef __cplusplus        
}
#endif
#endif // MVB_DEFS_H_