/***************************************************************************************************
* 
* ��Ȩ��Ϣ����Ȩ���� (c) 2010-2018, ���ݺ�������������޹�˾, ��������Ȩ��
*
* �ļ����ƣ�hka_types.h
* ժ    Ҫ�����������㷨����������ݽṹ�������ļ�
* 
* ��ǰ�汾��1.2.5
* ��    �ߣ�������
* ��    �ڣ�2019��3��1��
* ��    ע����enum������������NONE���壬��֤��ƽ̨����������
* 
* ��ʷ�汾��1.2.4
* ��    �ߣ�������
* ��    �ڣ�2018��6��20��
* ��    ע������յ�enum�������ͣ���֤HKA_MEM_TAB_V2ʹ�ã�
* 
* ��ʷ�汾��1.2.3
* ��    �ߣ�������
* ��    �ڣ�2018��6��14��
* ��    ע������HKA_MEM_TAB_V2��ͳһ����ƽ̨��������ã�
* 
* ��ʷ�汾��1.2.2
* ��    �ߣ�������
* ��    �ڣ�2018��6��12��
* ��    ע�����ӵ�ͨ��16λ������ͼ���32λ������ͼ��
* 
* ��ʷ�汾��1.2.1
* ��    �ߣ�������
* ��    �ڣ�2018��5��14��
* ��    ע��֧��ASIC C ModelҪ����ڴ�ṹ��1. ����1byte���롢����Ҫ����ꣻ2. ����ASIC MEM_TAB����
*           �ڴ�������˳���ٶ��壬���㷨�����ж��壻
* 
* ��ʷ�汾��1.1.1
* ��    �ߣ�������
* ��    �ڣ�2017��9��1��
* ��    ע��1 ����unknownͼ���ʽ�����û�����
* 
* ��ʷ�汾��1.1.0
* ��    �ߣ�������
* ��    �ڣ�2017��8��1��
* ��    ע��1 ����ͼ���ʽ���ḻYUV���ͣ�����CMYK��YCCK��ʽ��
*           2 ��չ��ƽ̨�����
* 
* ��ʷ�汾��1.0.1
* ��    �ߣ�������
* ��    �ڣ�2017��5��23��
* ��    ע��1 ����HKA_IMG_YUV_YUYVͼ���ʽ
*           2 ��֮ǰ�汾����
* 
* ��ʷ�汾��1.0.0
* ��    �ߣ�����
* ��    �ڣ�2015��5��26��
* ��    ע��1 �޸�HKA_MEM_TAB_LISTΪHKA_MEM_TAB_TYPE
*           2 �������������ϸע��
* 
* ��ʷ�汾��0.9.0
* ��    �ߣ����� ������ �ݺ��� ��Ρΰ
* ��    �ڣ�2015��5��20��
* ��    ע��1 ����64λƽ̨�궨��
*           2 ���Ӽ�����ش����붨��
*           3 ���Ӿ�����������ö�ٶ���
*           4 ������x86��arm��dspƽ̨��HKA_MEM_TAB_LIST����
*
* ��ʷ�汾��0.2.0
* ��    �ߣ���Ρΰ
* ��    �ڣ�2015��4��21��
* ��    ע����vca_base.hΪ�������������ݽṹ�ĸ����Զ����ʼ�汾
*
* ��ʷ�汾��0.1.0
* ��    �ߣ�ȫ���� ������
* ��    �ڣ�2014��10��10��
* ��    ע����ʼ�汾
***************************************************************************************************/
#ifndef _HKA_TYPES_H_
#define _HKA_TYPES_H_


#ifdef __cplusplus
extern "C" {
#endif
    

/***************************************************************************************************
* ��ƽ̨64λ�궨��
***************************************************************************************************/
#if (defined (_WIN64)                    \
    || defined (_LINUX64)                \
    || defined (_MAC64)                  \
    || defined (_IOS64)                  \
    || defined (_ANDROID64)              \
    || defined (ARCHS_STANDARD_64_BIT))  \
	|| defined(_AMD64_)
#define _HKA_SYS64
#endif


/***************************************************************************************************
* �����������͵Ķ���
***************************************************************************************************/
typedef signed char         HKA_S08;
typedef unsigned char       HKA_U08;
typedef signed short        HKA_S16;
typedef unsigned short      HKA_U16;
typedef signed int          HKA_S32;
typedef unsigned int        HKA_U32;
typedef float               HKA_F32;
typedef double              HKA_F64;

#if defined(_WIN32) || defined (_WIN64)
    typedef signed __int64      HKA_S64;
    typedef unsigned __int64    HKA_U64;
#else
    typedef signed long long    HKA_S64;
    typedef unsigned long long  HKA_U64;
#endif

#if defined (_HKA_SYS64)
    typedef HKA_U64      HKA_SZT;
#else
    typedef HKA_U32      HKA_SZT;
#endif

#ifndef HKA_VOID
#define HKA_VOID         void
#endif


/***************************************************************************************************
* ����, re: ʵ��, im: �鲿
***************************************************************************************************/
typedef struct _HKA_SC08
{
    HKA_S08  re;
    HKA_S08  im;
}HKA_SC08;

typedef struct _HKA_SC16
{
    HKA_S16  re;
    HKA_S16  im;
}HKA_SC16;

typedef struct _HKA_UC16
{
    HKA_U16  re;
    HKA_U16  im;
}HKA_UC16;

typedef struct _HKA_SC32
{
    HKA_S32  re;
    HKA_S32  im;
}HKA_SC32;

typedef struct _HKA_FC32
{
    HKA_F32  re;
    HKA_F32  im;
}HKA_FC32;

typedef struct _HKA_FC64
{
    HKA_F64  re;
    HKA_F64  im;
}HKA_FC64;


/***************************************************************************************************
* ��
***************************************************************************************************/
//��(�����ͣ�
typedef struct _HKA_POINT_S
{
    HKA_S16 x;          // x����
    HKA_S16 y;          // y����
}HKA_POINT_S;

//��(����) 
typedef struct _HKA_POINT_I
{
    HKA_S32 x;          // x����
    HKA_S32 y;          // y����
}HKA_POINT_I;

//��(������) 
typedef struct _HKA_POINT_F
{
    HKA_F32 x;          // x����
    HKA_F32 y;          // y����
}HKA_POINT_F;


/***************************************************************************************************
* ����
***************************************************************************************************/
//����(������)
typedef struct _HKA_RECT_S
{
    HKA_S16 x;          //�������Ͻ�X������
    HKA_S16 y;          //�������Ͻ�Y������
    HKA_S16 width;      //���ο��
    HKA_S16 height;     //���θ߶�
}HKA_RECT_S;

//����(����)
typedef struct _HKA_RECT_I
{
    HKA_S32 x;          //�������Ͻ�X������
    HKA_S32 y;          //�������Ͻ�Y������
    HKA_S32 width;      //���ο��
    HKA_S32 height;     //���θ߶�
}HKA_RECT_I;

//����(������)
typedef struct _HKA_RECT_F
{
    HKA_F32 x;          //�������Ͻ�X������
    HKA_F32 y;          //�������Ͻ�Y������
    HKA_F32 width;      //���ο��
    HKA_F32 height;     //���θ߶�
}HKA_RECT_F;


/***************************************************************************************************
* ��Χ��
***************************************************************************************************/
//��Χ��(������),���Ϊ(right - left + 1), �߶�Ϊ(bottom - top + 1)
typedef struct _HKA_BOX_S
{
    HKA_S16 left;       //��߽�
    HKA_S16 top;        //�ϱ߽�
    HKA_S16 right;      //�ұ߽�
    HKA_S16 bottom;     //�±߽�
}HKA_BOX_S;

//��Χ��(����)
typedef struct _HKA_BOX_I
{
    HKA_S32 left;       //��߽�
    HKA_S32 top;        //�ϱ߽�
    HKA_S32 right;      //�ұ߽�
    HKA_S32 bottom;     //�±߽�
}HKA_BOX_I;

//��Χ��(������)
typedef struct _HKA_BOX_F
{
    HKA_F32 left;       //��߽�
    HKA_F32 top;        //�ϱ߽�
    HKA_F32 right;      //�ұ߽�
    HKA_F32 bottom;     //�±߽�
}HKA_BOX_F;


/***************************************************************************************************
* �����
***************************************************************************************************/
//�������󶥵���
#define HKA_MAX_VERTEX_NUM   (10)

//�����(������)
typedef struct _HKA_POLYGON_S
{
    HKA_S32       vertex_num;                  //������
    HKA_POINT_S   point[HKA_MAX_VERTEX_NUM];   //����
}HKA_POLYGON_S;

//�����(����)
typedef struct _HKA_POLYGON_I
{
    HKA_S32       vertex_num;                  //������
    HKA_POINT_I   point[HKA_MAX_VERTEX_NUM];   //����
}HKA_POLYGON_I;

//�����(������)
typedef struct _HKA_POLYGON_F
{
    HKA_S32       vertex_num;                  //������
    HKA_POINT_F   point[HKA_MAX_VERTEX_NUM];   //����
}HKA_POLYGON_F;


/***************************************************************************************************
* ʸ��
***************************************************************************************************/
//ʸ���������ͣ�
typedef struct _HKA_VECTOR_S
{
    HKA_POINT_S   start_point;  //���
    HKA_POINT_S   end_point;    //�յ�
}HKA_VECTOR_S;

//ʸ�������ͣ�
typedef struct _HKA_VECTOR_I
{
    HKA_POINT_I   start_point;  //���
    HKA_POINT_I   end_point;    //�յ�
}HKA_VECTOR_I;

//ʸ��(������)
typedef struct _HKA_VECTOR_F
{
    HKA_POINT_F   start_point;  //���
    HKA_POINT_F   end_point;    //�յ�
}HKA_VECTOR_F;


/***************************************************************************************************
* ͼ����
***************************************************************************************************/
//�ߴ�(������)
typedef struct _HKA_SIZE_S
{
    HKA_S16 width;      // ���
    HKA_S16 height;     // �߶�
}HKA_SIZE_S;

//�ߴ�(����)
typedef struct _HKA_SIZE_I
{
    HKA_S32  width;     // ���
    HKA_S32  height;    // �߶�
}HKA_SIZE_I;

//�ߴ�(������)
typedef struct _HKA_SIZE_F
{
    HKA_F32  width;     // ���
    HKA_F32  height;    // �߶�
}HKA_SIZE_F;


/***************************************************************************************************
* �ڴ������HKA_MEM_TAB�ṹ�嶨��
***************************************************************************************************/
//�ڴ��������
typedef enum _HKA_MEM_ALIGNMENT
{
    HKA_MEM_ALIGN_NULL     = 0,   // ����Ҫ���룬������HKA_SIZE_ALIGN����ʹ��
    HKA_MEM_ALIGN_1BYTE    = 1,
    HKA_MEM_ALIGN_4BYTE    = 4,
    HKA_MEM_ALIGN_8BYTE    = 8,
    HKA_MEM_ALIGN_16BYTE   = 16,
    HKA_MEM_ALIGN_32BYTE   = 32,
    HKA_MEM_ALIGN_64BYTE   = 64,
    HKA_MEM_ALIGN_128BYTE  = 128,
    HKA_MEM_ALIGN_256BYTE  = 256
}HKA_MEM_ALIGNMENT; 

#if ((defined DSP) || (defined _HIK_DSP_APP_))
//�ڴ����ԣ����㷨Ӧ�ýǶȵĸ����Զ��ڴ���з��ࣩ
typedef enum _HKA_MEM_ATTRS
{
    HKA_MEM_SCRATCH,                 //�ɸ����ڴ棬���ڶ�·�л�ʱ����������  
    HKA_MEM_PERSIST                  //���ɸ����ڴ�
}HKA_MEM_ATTRS;

//�ڴ����ռ䣨���ڴ���������λ�������ࣩ
typedef enum _HKA_MEM_SPACE
{
    HKA_MEM_EXTERNAL_PROG,           //�ⲿ����洢�� 
    HKA_MEM_INTERNAL_PROG,           //�ڲ�����洢�� 
    HKA_MEM_EXTERNAL_TILERED_DATA,   //�ⲿTilered���ݴ洢�� 
    HKA_MEM_EXTERNAL_CACHED_DATA,    //�ⲿ��Cache�洢�� 
    HKA_MEM_EXTERNAL_UNCACHED_DATA,  //�ⲿ����Cache�洢��
    HKA_MEM_INTERNAL_DATA,           //�ڲ��洢�� 
    HKA_MEM_EXTERNAL_TILERED8 ,      //�ⲿTilered���ݴ洢��8bit��Netra/Centaurus���� 
    HKA_MEM_EXTERNAL_TILERED16,      //�ⲿTilered���ݴ洢��16bit��Netra/Centaurus���� 
    HKA_MEM_EXTERNAL_TILERED32 ,     //�ⲿTilered���ݴ洢��32bit��Netra/Centaurus���� 
    HKA_MEM_EXTERNAL_TILEREDPAGE     //�ⲿTilered���ݴ洢��page��ʽ��Netra/Centaurus���� 
}HKA_MEM_SPACE;

//�ڴ����ṹ�� --> �������HKA_MEM_TAB_V2�汾
typedef struct _HKA_MEM_TAB
{
    HKA_SZT             size;        //��BYTEΪ��λ���ڴ��С
    HKA_MEM_ALIGNMENT   alignment;   //�ڴ��������, ����Ϊ128
    HKA_MEM_SPACE       space;       //�ڴ����ռ� 
    HKA_MEM_ATTRS       attrs;       //�ڴ����� 
    HKA_VOID           *base;        //��������ڴ�ָ�� 
}HKA_MEM_TAB;

//�ڴ��ĸ������Ƽ����ڴ������˳����������粻����Ҫ�󣬿����㷨��ͷ�ļ������ж��壩
typedef enum _HKA_MEM_TAB_TYPE
{
    HKA_MEM_TAB_PERSIST      = 0,
    HKA_MEM_TAB_SCRATCH      = 1,
    HKA_MEM_TAB_SCRATCH_IRAM = 2,
    HKA_MEM_TAB_NUM          = 3
}HKA_MEM_TAB_TYPE;

#elif( (defined ARM) || (defined _HIK_ARM_APP_))

//�ڴ����ԣ����㷨Ӧ�ýǶȵĸ����Զ��ڴ���з��ࣩ����Ϊ�գ����MEM_TAB_V2ʹ��
typedef enum _HKA_MEM_ATTRS
{
    HKA_MEM_ATTRS_NONE  = -1          //���������ͣ�����ʹ��

}HKA_MEM_ATTRS;

//�ڴ����ռ䣨���ڴ���������λ�������ࣩ����Ϊ�գ����MEM_TAB_V2ʹ��
typedef enum _HKA_MEM_SPACE
{
    HKA_MEM_SPACE_NONE  = -1          //���������ͣ�����ʹ��

}HKA_MEM_SPACE;

//�ڴ����ṹ�� --> �������HKA_MEM_TAB_V2�汾
typedef struct _HKA_MEM_TAB
{
    HKA_SZT             size;        //��BYTEΪ��λ���ڴ��С
    HKA_MEM_ALIGNMENT   alignment;   //�ڴ��������, ����Ϊ128 
    HKA_VOID           *base;        //��������ڴ�ָ�� 
}HKA_MEM_TAB;

//�ڴ��ĸ������Ƽ����ڴ������˳����������粻����Ҫ�󣬿����㷨��ͷ�ļ������ж��壩
typedef enum _HKA_MEM_TAB_TYPE
{
    HKA_MEM_TAB_PERSIST    = 0,
    HKA_MEM_TAB_SCRATCH    = 1,
    HKA_MEM_TAB_IVE_PHY    = 2,
    HKA_MEM_TAB_NUM        = 3
}HKA_MEM_TAB_TYPE;

#elif( (defined ASIC) || (defined _HIK_ASIC_MODEL_))

//�ڴ����ԣ����㷨Ӧ�ýǶȵĸ����Զ��ڴ���з��ࣩ
typedef enum _HKA_MEM_ATTRS
{
    HKA_MEM_SCRATCH,                 //�ɸ����ڴ棬���ڶ�·�л�ʱ����������  
    HKA_MEM_PERSIST                  //���ɸ����ڴ�
}HKA_MEM_ATTRS;

//�ڴ����ռ䣨���ڴ���������λ�������ࣩ
typedef enum _HKA_MEM_SPACE
{
    HKA_MEM_INTERNAL_RAM,            //Ƭ�������д�洢��
    HKA_MEM_INTERNAL_ROM,            //Ƭ��ֻ���洢��
    HKA_MEM_EXTERNAL_DDR             //Ƭ��DDR�洢��
}HKA_MEM_SPACE;

//�ڴ����ṹ�� --> �������HKA_MEM_TAB_V2�汾
typedef struct _HKA_MEM_TAB
{
    HKA_SZT             size;        //ASIC�п���BYTE�����룬C Model��ΪBYTE��λ�Ĵ洢����С
    HKA_MEM_ALIGNMENT   alignment;   //�ڴ��������, һ��RAM/ROM����Ҫ���Ƕ������⣬DDR��Ҫ��16BYTE����
    HKA_MEM_SPACE       space;       //�ڴ����ռ� 
    HKA_MEM_ATTRS       attrs;       //�ڴ����� 
    HKA_VOID           *base;        //��������ڴ�ָ�� 
}HKA_MEM_TAB;

#else//Ĭ��x86������

//�ڴ����ԣ����㷨Ӧ�ýǶȵĸ����Զ��ڴ���з��ࣩ����Ϊ�գ����MEM_TAB_V2ʹ��
typedef enum _HKA_MEM_ATTRS
{
    HKA_MEM_ATTRS_NONE  = -1          //���������ͣ�����ʹ��

}HKA_MEM_ATTRS;

//�ڴ����ռ䣨���ڴ���������λ�������ࣩ����Ϊ�գ����MEM_TAB_V2ʹ��
typedef enum _HKA_MEM_SPACE
{
    HKA_MEM_SPACE_NONE  = -1          //���������ͣ�����ʹ��

}HKA_MEM_SPACE;

//�ڴ����ṹ�� --> �������HKA_MEM_TAB_V2�汾
typedef struct _HKA_MEM_TAB
{
    HKA_SZT             size;        //��BYTEΪ��λ���ڴ��С
    HKA_MEM_ALIGNMENT   alignment;   //�ڴ��������, ����Ϊ128 
    HKA_VOID           *base;        //��������ڴ�ָ�� 
}HKA_MEM_TAB;

//�ڴ��ĸ������Ƽ����ڴ������˳����������粻����Ҫ�󣬿����㷨��ͷ�ļ������ж��壩
typedef enum _HKA_MEM_TAB_TYPE
{
    HKA_MEM_TAB_PERSIST    = 0,
    HKA_MEM_TAB_SCRATCH    = 1,
    HKA_MEM_TAB_NUM        = 2
}HKA_MEM_TAB_TYPE;

#endif//((defined DSP) || (defined _HIK_DSP_APP_)) 


//�ڴ����ṹ��V2������ƽ̨������ʹ�øýṹ��
typedef struct _HKA_MEM_TAB_V2
{
    HKA_SZT             size;        //��BYTEΪ��λ���ڴ��С
    HKA_MEM_ALIGNMENT   alignment;   //�ڴ��������
    HKA_MEM_SPACE       space;       //�ڴ����ռ������λ�� 
    HKA_MEM_ATTRS       attrs;       //�ڴ�ʹ������ 
    HKA_VOID           *base;        //��������ڴ�ָ�� 
}HKA_MEM_TAB_V2;


/***************************************************************************************************
* ͼ��ṹ�嶨��
***************************************************************************************************/
//ͼ���ʽ���µ��������������棬����ǰ����ݣ�ÿ�ָ�ʽ���γ���100���֣�
typedef enum _HKA_IMAGE_FORMAT
{
    //δ֪�ģ�δ�������ݸ�ʽ���û����Ը���Ӧ��������ⶨ���ʽ����
    HKA_IMG_UNKNOWN             = 0,

    //----------------------------------------------------------------------------------------------
    //ע�����widthԭ������ָ����ͼ��ˮƽ���ص������
    //����YUVͼ���ȶ���Y�������Ϊ׼��
    //RGB��RGBD��RGBA����һ�������Ŀ��Ϊ׼��
    //��bayer��ʽ������һ��ͨ���������Ϊһ�����ݸ�������Ⱥ͡�
    //ע���м����ָ����ƽ�����п�ʼ��������ݸ�����
    //����RGB 3ƽ���ʽ��ÿ��ƽ����Ϊwidth�����м��step >= width;
    //����RGB 3ͨ����֯��ʽ��ÿ��ƽ����Ϊwidth�����м��step >= width*3;
    //----------------------------------//----------------------------------------------------------
    //mono (0~99)                       //| bit  | type |   store position    |        step         |
    //mono8                             //----------------------------------------------------------
    HKA_IMG_MONO_08             = 1,    //| 8b   | U08  |        D0           |         S0          |
    //mono12                            //----------------------------------------------------------
    HKA_IMG_MONO_12             = 2,    //| 12b  | S16  |        D0           |         S0          |
    //mono16                            //----------------------------------------------------------
    HKA_IMG_MONO_16             = 3,    //| 16b  | U16  |        D0           |         S0          |
    //mono float 16bit                  //----------------------------------------------------------
    HKA_IMG_MONO_F16            = 4,    //| 16b  | F16  |        D0           |         S0          |
    //mono float 32bit                  //----------------------------------------------------------
    HKA_IMG_MONO_F32            = 5,    //| 32b  | F32  |        D0           |         S0          |
    //----------------------------------//----------------------------------------------------------
    //YUV (100~199)                     //| bit  | type |   store position    |        step         |
    //YUV420 Sx(U,V) = 2 Sy(U,V) = 2    //----------------------------------------------------------
    //I420 planar
    HKA_IMG_YUV_I420            = 100,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
    //YUV420                            //----------------------------------------------------------
    //YV12 planar
    HKA_IMG_YUV_YV12            = 101,  //| 8b   | U08  |    Y:D0,V:D1,U:D2   |  Y:S0,V:S1,U:S2     |
    //YUV420                            //----------------------------------------------------------
    //NV12 UV packed
    HKA_IMG_YUV_NV12            = 102,  //| 8b   | U08  |    Y:D0,UV:D1       |  Y:S0,UV:S1         |
    //YUV422 Sx(U,V) = 1 Sy(U,V) = 2    //----------------------------------------------------------
    //planar
    HKA_IMG_YUV_422             = 103,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
    //YUV422                            //----------------------------------------------------------
    //UYVY packed
    HKA_IMG_YUV_UYVY            = 104,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
    //YUV444  Sx(U,V) = 1 Sy(U,V) = 1   //----------------------------------------------------------
    //planar
    HKA_IMG_YUV_444             = 105,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
    //YUV422                            //----------------------------------------------------------
    //YUYV (YUY2) packed
    HKA_IMG_YUV_YUYV            = 106,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
    //YUV422                            //----------------------------------------------------------
    //YVYU packed
    HKA_IMG_YUV_YVYU            = 107,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
    //YUV422                            //----------------------------------------------------------
    //VYUY
    HKA_IMG_YUV_VYUY            = 108,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
    //YUV420                            //----------------------------------------------------------
    //NV21 VU packed
    HKA_IMG_YUV_NV21            = 109,  //| 8b   | U08  |    Y:D0,VU:D1       |  Y:S0,VU:S1         |
    //YUV411 Sx(U,V) = 4 Sy(U,V) = 1    //----------------------------------------------------------
    //planar
    HKA_IMG_YUV_YUV411          = 130,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
    //YUV411                            //----------------------------------------------------------
    //Y411 (Y41P) packed: U0 Y0 V0 Y1 U4 Y2 V4 Y3 Y4 Y5 Y6 Y8 
    HKA_IMG_YUV_Y41P            = 131,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
    //YVU9 Sx(U,V) = 4 Sy(U,V) = 4      //----------------------------------------------------------
    //planar
    HKA_IMG_YUV_YVU9            = 140,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
    //AYUV                              //----------------------------------------------------------
    //planar
    HKA_IMG_YUV_AYUV            = 150,  //| 8b   | U08  | A:D0,Y:D1,U:D2,V:D3 | A:S0,Y:S1,U:S2,V:S3 |
    //YUV440  Sx(U,V) = 1 Sy(U,V) = 2   //----------------------------------------------------------
    //planar
    HKA_IMG_YUV_440             = 180,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
    //YUV424  Sx(U) = 2 Sy(V) = 2       //----------------------------------------------------------
    //planar
    HKA_IMG_YUV_424             = 181,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
    //YUV442  Sy(U) = 2 Sx(V) = 2       //----------------------------------------------------------
    //planar
    HKA_IMG_YUV_442             = 182,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
    //----------------------------------//----------------------------------------------------------
    //RGB (200~299)                     //| bit  | type |   store position    |        step         |
    //RBG 3 plane                       //----------------------------------------------------------
    HKA_IMG_RGB_RGB24_P3        = 200,  //| 8b   | U08  |    R:D0,G:D1,B:D2   |  R:S0,G:S1,B:S2     |
    //RGB 3 RGBRGB...                   //----------------------------------------------------------
    HKA_IMG_RGB_RGB24_C3        = 201,  //| 8b   | U08  |    RGB:D0           |  RGB:S0             |
    //RGB 4 plane(alpha)                //----------------------------------------------------------
    HKA_IMG_RGB_RGBA_P4         = 202,  //| 8b   | U08  | R:D0,G:D1,B:D2,A:D3 | R:S0,G:S1,B:S2,A:S3 |
    //RGB 4 RGBARGBA...(alpha)          //----------------------------------------------------------
    HKA_IMG_RGB_RGBA_C4         = 203,  //| 8b   | U08  |    RGBA:D0          |  RGBA:S0            |
    //RGB 4 plane(depth)                //----------------------------------------------------------
    HKA_IMG_RGB_RGBD_P4         = 204,  //| 8b   | U08  | R:D0,G:D1,B:D2,A:D3 | R:S0,G:S1,B:S2,A:S3 |
    //RGB 4 RGBDRGBD...(depth)          //----------------------------------------------------------
    HKA_IMG_RGB_RGBD_C4         = 205,  //| 8b   | U08  |    RGBA:D0          |  RGBA:S0            |
    //----------------------------------//----------------------------------------------------------
    //bayer (300~399)                   //| bit  | type |   store position    |        step         |
    //bayer GRGB 10bit                  //----------------------------------------------------------
    HKA_IMG_BAYER_GRBG_10       = 300,  //| 10b  | S16  |    GRBG:D0          |  GRBG:S0            |
    //bayer RGGB 10bit                  //----------------------------------------------------------
    HKA_IMG_BAYER_RGGB_10       = 301,  //| 10b  | S16  |    RGGB:D0          |  RGGB:S0            |
    //bayer RGGB 10bit                  //----------------------------------------------------------
    HKA_IMG_BAYER_BGGR_10       = 302,  //| 10b  | S16  |    BGGR:D0          |  BGGR:S0            |
    //bayer RGGB 10bit                  //----------------------------------------------------------
    HKA_IMG_BAYER_GBRG_10       = 303,  //| 10b  | S16  |    GBRG:D0          |  GBRG:S0            |
    //bayer RGGB 10bit                  //----------------------------------------------------------
    HKA_IMG_BAYER_GRBG_12       = 304,  //| 12b  | S16  |    GRBG:D0          |  GRBG:S0            |
    //bayer RGGB 10bit                  //----------------------------------------------------------
    HKA_IMG_BAYER_RGGB_12       = 305,  //| 12b  | S16  |    RGGB:D0          |  RGGB:S0            |
    //bayer RGGB 10bit                  //----------------------------------------------------------
    HKA_IMG_BAYER_BGGR_12       = 306,  //| 12b  | S16  |    BGGR:D0          |  BGGR:S0            |
    //bayer RGGB 10bit                  //----------------------------------------------------------
    HKA_IMG_BAYER_GBRG_12       = 307,  //| 12b  | S16  |    GBRG:D0          |  GBRG:S0            |
    //----------------------------------//----------------------------------------------------------
    //YCbCr (400~499)                   //| bit  | type |   store position    |        step         |
    //YCCK Sx(U,V) = 1 Sy(U,V) = 1      //----------------------------------------------------------
    //planar                            //----------------------------------------------------------
    HKA_IMG_YCCK_P4             = 400,  //| 8b   | U08  |Y:D0,Cb:D1,Cr:D2,K:D3|Y:S0,Cb:S1,Cr:S2,K:S3|
    //packed  C0 M0 Y0 K0 C1 M1 Y1 K1   //----------------------------------------------------------
    HKA_IMG_YCCK_C4             = 401,  //| 8b   | U08  |    YCCK:D0          |  YCCK:S0            |
    //----------------------------------//----------------------------------------------------------
    //CMYK (500~519)                    //| bit  | type |   store position    |        step         |
    //planar                            //----------------------------------------------------------
    HKA_IMG_CMYK_P4             = 500,  //| 8b   | U08  | C:D0,M:D1,Y:D2,K:D3 | C:S0,M:S1,Y:S2,K:S3 |
    //packed  C0 M0 Y0 K0 C1 M1 Y1 K1   //----------------------------------------------------------
    HKA_IMG_CMYK_C4             = 501   //| 8b   | U08  |    CMYK:D0          |  CMYK:S0            |
    //----------------------------------//----------------------------------------------------------
}HKA_IMAGE_FORMAT;

//ͼ���ʽ��ʾ�ṹ��
typedef struct _HKA_IMAGE
{
    HKA_IMAGE_FORMAT    format;      //ͼ���ʽ��������������HKA_IMAGE_FORMAT��ֵ
    HKA_S32             width;       //ͼ����
    HKA_S32             height;      //ͼ��߶�
    HKA_S32             step[4];     //�м��
    HKA_VOID           *data[4];     //���ݴ洢��ַ
}HKA_IMAGE;


/***************************************************************************************************
* ����ṹ�嶨��
***************************************************************************************************/
//HKA_MAT_TYPE���ͷֶη���
#define HKA_MAT_TYPE_SIGN   0x80000000

//ͼ���ʽ���µ��������������棬����ǰ����ݣ�
typedef enum _HKA_MAT_TYPE
{
    HKA_MAT_TYPE_01U     = 1,                           //�޷�������λ��1
    HKA_MAT_TYPE_08U     = 8,                           //�޷�������λ��8
    HKA_MAT_TYPE_16U     = 16,                          //�޷�������λ��16
    HKA_MAT_TYPE_32F     = 32,                          //�����ȸ�����λ��32
    HKA_MAT_TYPE_08S     = (HKA_MAT_TYPE_SIGN | 8),     //�з�������λ��8
    HKA_MAT_TYPE_16S     = (HKA_MAT_TYPE_SIGN | 16),    //�з�������λ��16
    HKA_MAT_TYPE_32S     = (HKA_MAT_TYPE_SIGN | 32)     //�з�������λ��32
}HKA_MAT_TYPE;

//������
typedef struct _HKA_MAT
{
    HKA_MAT_TYPE type;      //����Ԫ�ص��������ͣ�������������HKA_MAT_TYPE��ֵ
    HKA_S32      step;      //�����ݿ�ȣ�ÿ����ռ�ֽ�����
    HKA_S32      rows;      //��
    HKA_S32      cols;      //��

    //����ָ�����Ͻṹ��
    union
    {
        HKA_U08 *ptr;
        HKA_S16 *s;
        HKA_S32 *i;
        HKA_F32 *fl;
        HKA_F64 *db;
    }data;
}HKA_MAT;


/***************************************************************************************************
* ����ӿڳ������ݽṹ���궨��
***************************************************************************************************/
//�㷨��ӿ����á���ȡ���������Ŀ��
#define HKA_MAX_PARAM_NUM    (256)

//�㷨��ӿ����á���ȡ���������ṹ�壬�㷨���ڡ����ⶼʹ�ã�����ģ�鲻ʹ��
typedef struct _HKA_KEY_PARAM
{
    HKA_S32 index;
    HKA_S32 value;
}HKA_KEY_PARAM;

//�㷨��ӿ����á���ȡ��������ṹ�塣�㷨���ڡ����ⶼʹ�ã�����ģ�鲻ʹ��
typedef struct _HKA_KEY_PARAM_LIST
{
    HKA_S32        param_num;
    HKA_KEY_PARAM  param[HKA_MAX_PARAM_NUM];
}HKA_KEY_PARAM_LIST;

//�������ò������ͣ�cfg_type����HKAXXX_SetConfig����ʹ��
typedef enum _HKA_SET_CFG_TYPE
{
    HKA_SET_CFG_SINGLE_PARAM    = 0x0001,    //��������
    HKA_SET_CFG_PARAM_LIST      = 0x0002,    //�����б�
    HKA_SET_CFG_DEFAULT_PARAM   = 0x0003,    //Ĭ�ϲ���
    HKA_SET_CFG_RESTART_LIB     = 0x0004,    //�����㷨��
    HKA_SET_CFG_CALLBACK        = 0x0005,    //�ص�����
    HKA_SET_CFG_CHECK_PARAM     = 0x0006     //�����������
}HKA_SET_CFG_TYPE;

//��ȡ���ò������ͣ�cfg_type����HKAXXX_GetConfig����ʹ��
typedef enum _HKA_GET_CFG_TYPE
{
    HKA_GET_CFG_SINGLE_PARAM    = 0x0001,    //��������
    HKA_GET_CFG_PARAM_LIST      = 0x0002,    //����������
    HKA_GET_CFG_VERSION         = 0x0003,    //�汾��Ϣ
    HKA_GET_CFG_ABILITY         = 0x0004     //�㷨��������
}HKA_GET_CFG_TYPE;


/***************************************************************************************************
* ״̬��
***************************************************************************************************/
//״̬����������
typedef int HKA_STATUS;    //����ӿں�������ֵ������Ϊ������

//��������״̬����
//�㷨������ڿ�ͷ�ļ����Զ���״̬���ͣ��Զ���״̬����ֵ < -1000��
typedef enum _HKA_STATUS_CODE
{
    //cpuָ�֧�ִ�����
    HKA_STS_ERR_CPUID           = -29,    //cpu��֧���Ż������е�ָ�

    //�ڲ�ģ�鷵�صĻ�����������
    HKA_STS_ERR_STEP            = -28,    //����step����ȷ����HKA_IMAGE�ṹ��֮�⣩
    HKA_STS_ERR_DATA_SIZE       = -27,    //���ݴ�С����ȷ��һά����len����ά���ݵ�HKA_SIZE��
    HKA_STS_ERR_BAD_ARG         = -26,    //������Χ����ȷ

    //�㷨�������ش����붨��
    HKA_STS_ERR_EXPIRE          = -25,    //�㷨��ʹ�����޴���
    HKA_STS_ERR_ENCRYPT         = -24,    //���ܴ���

    //����Ϊ����ӿں���ʹ�õĴ�������
    HKA_STS_ERR_CALL_BACK       = -23,    //�ص���������
    HKA_STS_ERR_OVER_MAX_MEM    = -22,    //����HKA�޶�����ڴ�
    HKA_STS_ERR_NULL_PTR        = -21,    //��������ָ��Ϊ�գ����ã�

    //���HKA_KEY_PARAM��HKA_KEY_PARAM_LIST��Ա�����Ĵ�������
    HKA_STS_ERR_PARAM_NUM       = -20,    //param_num��������ȷ
    HKA_STS_ERR_PARAM_VALUE     = -19,    //value��������ȷ���߳�����Χ
    HKA_STS_ERR_PARAM_INDEX     = -18,    //index��������ȷ

    //���cfg_type, cfg_size, prc_type, in_size, out_size, func_type�Ƿ���ȷ
    HKA_STS_ERR_FUNC_SIZE       = -17,    //�Ӵ���ʱ���롢���������С����ȷ
    HKA_STS_ERR_FUNC_TYPE       = -16,    //�Ӵ������Ͳ���ȷ
    HKA_STS_ERR_PRC_SIZE        = -15,    //����ʱ���롢���������С����ȷ
    HKA_STS_ERR_PRC_TYPE        = -14,    //�������Ͳ���ȷ
    HKA_STS_ERR_CFG_SIZE        = -13,    //���á���ȡ�������롢����ṹ���С����ȷ
    HKA_STS_ERR_CFG_TYPE        = -12,    //���á���ȡ�������Ͳ���ȷ

    //���HKA_IMAGE��Ա�����Ĵ�������
    HKA_STS_ERR_IMG_DATA_NULL   = -11,    //ͼ�����ݴ洢��ַΪ�գ�ĳ��������
    HKA_STS_ERR_IMG_STEP        = -10,    //ͼ������step������ƥ��
    HKA_STS_ERR_IMG_SIZE        = -9,     //ͼ���߲���ȷ���߳�����Χ
    HKA_STS_ERR_IMG_FORMAT      = -8,     //ͼ���ʽ����ȷ���߲�֧��

    //���HKA_MEM_TAB��Ա�����Ĵ�������
    HKA_STS_ERR_MEM_ADDR_ALIGN  = -7,     //�ڴ��ַ���������Ҫ��
    HKA_STS_ERR_MEM_SIZE_ALIGN  = -6,     //�ڴ�ռ��С���������Ҫ��
    HKA_STS_ERR_MEM_LACK        = -5,     //�ڴ�ռ��С����
    HKA_STS_ERR_MEM_ALIGN       = -4,     //�ڴ���벻����Ҫ��
    HKA_STS_ERR_MEM_NULL        = -3,     //�ڴ��ַΪ��

    //���ability��Ա�����Ĵ�������
    HKA_STS_ERR_ABILITY_ARG     = -2,     //ABILITY������Ч����

    //ͨ������
    HKA_STS_ERR                 = -1,     //��ȷ�����ʹ��󣨽ӿں������ã�
    HKA_STS_OK                  =  0,     //������ȷ���ӿں������ã�
    HKA_STS_WARNING             =  1      //����

}HKA_STATUS_CODE;

#ifdef __cplusplus
}
#endif 

#endif //_HKA_TYPES_H_



