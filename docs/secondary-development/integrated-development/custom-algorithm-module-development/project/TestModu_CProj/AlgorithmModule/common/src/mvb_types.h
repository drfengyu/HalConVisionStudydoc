/***************************************************************************************************
* ��Ȩ��Ϣ��Copyright (c) 2010-2018, ���ݺ����������ּ����ɷ����޹�˾����������Ȩ��
* 
* �ļ����ƣ�mvb_types.h
* 
* ժ    Ҫ���ӿ��������Ͷ���
* 
* ��ǰ�汾��0.7.0
* ��    �ߣ���־��
* ��    �ڣ�2018��10��12��
* ��    ע��1�����������������ѧϰ
*
* ��ʷ�汾��0.6.0
* ��    �ߣ���־��
* ��    �ڣ�2017��4��4��
* ��    ע��1�����Ӷ����������ݽṹ
*
* ��ʷ�汾��0.5.0
* ��    �ߣ���־��
* ��    �ڣ�2017��1��12��
* ��    ע��1�����ӿ��ߡ�blob������ݽṹ
*
* ��ʷ�汾��0.4.0
* ��    �ߣ���־��
* ��    �ڣ�2016��11��30��
* ��    ע��1��MVBI_BOX�޸�ΪMVBI_BOX_F
*           2��MVB_CIRCLE_F��MVB_CIRCLE_Iɾ��circleness��Ա
*           3��MVB_LINE_F��MVB_LINE_Iɾ��straightness��Ա
* ��ʷ�汾��0.3.0
* ��    �ߣ���־��
* ��    �ڣ�2016��1��23��
* ��    ע������Բ��ֱ�ߡ���Բ��ģ��ƥ��Ƚṹ��
*
* ��ʷ�汾��0.2.0
* ��    �ߣ���־��
* ��    �ڣ�2016��1��19��
* ��    ע�����ӱ�Ե���͡�Բ�������͡�ֱ�߲������͡�ģ��ƥ����Ϣ��
*
* ��ʷ�汾��0.1.0
* ��    �ߣ��޴���
* ��    �ڣ�2015��08��04��
* ��    ע����ʼ�汾
***************************************************************************************************/

#ifndef MVB_TYPES_H_
#define MVB_TYPES_H_

#include "hka_defs.h"

#ifdef __cplusplus        
extern "C" 
{
#endif

//��ֵ�㷨���� (interpolation)
typedef enum _MVBI_INTER_TYPE
{
    MVBI_INTER_TYPE_MIN = 1,
    MVBI_INTER_NN       = 1,
    MVBI_INTER_LINEAR   = 2,
    MVBI_INTER_CUBIC    = 4,
    MVBI_INTER_LANCZOS2 = 8,
    MVBI_INTER_LANCZOS3 = 16,
    MVBI_INTER_TYPE_MAX = 16
}MVBI_INTER_TYPE;

//�������� (normalizeType)
typedef enum _MVBI_NORM_TYPE
{
    MVBI_NORM_TYPE_MIN = 0,
    MVBI_NORM_C        = 0,
    MVBI_NORM_L1       = 1,
    MVBI_NORM_L2       = 2,
    MVBI_NORM_TYPE_MAX = 2
}MVBI_NORM_TYPE;

//bayer�������� (bayerType)
typedef enum _MVBI_BAYER_TYPE
{
    MVBI_BAYER_TYPE_MIN = 0,
    MVBI_BAYER_GRBG     = 0,
    MVBI_BAYER_GBRG     = 1,
    MVBI_BAYER_RGGB     = 2,
    MVBI_BAYER_BGGR     = 3,
    MVBI_BAYER_TYPE_MAX = 3
}MVBI_BAYER_TYPE;

//��ɢ���� (diffusionMode)
typedef enum _MVBI_DIFFUSION_TYPE
{
    MVBI_DIFFUSION_TYPE_MIN = 1, 
    MVBI_DIFFUSION_1        = 1,
    MVBI_DIFFUSION_2        = 2,
    MVBI_DIFFUSION_3        = 3,
    MVBI_DIFFUSION_TYPE_MAX = 3
}MVBI_DIFFUSION_TYPE;

// �������� (directionType)
typedef enum _MVBI_DIRECT_TYPE
{
    MVBI_DIRECT_TYPE_MIN = 0, 
    MVBI_DIRECT_0        = 0,
    MVBI_DIRECT_45       = 1,
    MVBI_DIRECT_90       = 2,
    MVBI_DIRECT_135      = 3,
    MVBI_DIRECT_TYPE_MAX = 3
}MVBI_DIRECT_TYPE;

//��Ȩ��ֵ�˲�Mask���� (maskType)
typedef enum _MVBI_MASKTYPE_TYPE
{
    MVBI_MASKTYPE_TYPE_MIN = 0,
    MVBI_MASKTYPE_GAUSS    = 0,
    MVBI_MASKTYPE_INNER    = 1,
    MVBI_MASKTYPE_TYPE_MAX = 1
}MVBI_MASKTYPE_TYPE;

//�ڿ�����ƽ��ͼ��������������������ֵ�滻���� (replacementMode)
typedef enum _MVBI_REPLACEMENT_TYPE
{
    MVBI_REPLACEMENT_TYPE_MIN = 0, 
    MVBI_REPLACEMENT_NEXT     = 0,
    MVBI_REPLACEMENT_MEAN     = 1,
    MVBI_REPLACEMENT_MEDIAN   = 2,
    MVBI_REPLACEMENT_TYPE_MAX = 2
}MVBI_REPLACEMENT_TYPE;

//��ͨ����
typedef enum _MVBI_CONNECTIVITY
{
    MVBI_CONNECTIVITY_MIN = 4,
    MVBI_CONNECTIVITY_4   = 4,      // 4��ͨ  4-����
    MVBI_CONNECTIVITY_6   = 6,      // 6��ͨ  6-����
    MVBI_CONNECTIVITY_8   = 8,      // 8��ͨ  8-����
    MVBI_CONNECTIVITY_MAX = 8
} MVBI_CONNECTIVITY;

//��ͨ���������ͣ�_MVBI_SortDomainArray����ʹ��
typedef enum _MVBI_REG_DOMAIN_ARRAY_SORT_TYPE
{
    MVBI_REG_SORT_TYPE_MIN  = 0,
    MVBI_REG_SORT_TYPE_AREA = 0,  //���������
    MVBI_REG_SORT_TYPE_YMIN = 1,  //�����κ��ϱ�Ե����
    MVBI_REG_SORT_TYPE_YMAX = 2,  //�����κ��±�Ե����
    MVBI_REG_SORT_TYPE_XMIN = 3,  //�����κ����Ե����
    MVBI_REG_SORT_TYPE_XMAX = 4,  //�����κ��ұ�Ե����
    MVBI_REG_SORT_TYPE_MAX  = 4
}MVBI_REG_DOMAIN_ARRAY_SORT_TYPE;

// ��������
typedef enum _MVBI_DIST_TYPE
{
    MVBI_DIST_TYPE_MIN       = 0, 
    MVBI_DIST_TYPE_BLOCK     = 0,	  // ��������
    MVBI_DIST_TYPE_CHESS     = 1,	  // ���̾���
    MVBI_DIST_TYPE_EUCLIDEAN = 2, 	  // ŷʽ����
    MVBI_DIST_TYPE_MAX       = 2
}MVBI_DIST_TYPE;

// �ṹԪ����������
typedef enum _MVBI_MORPH_STRUCTURE
{
    MVBI_MORPH_STRUCTURE_MIN     = 0x0000,  // ��С����
    MVBI_MORPH_STRUCTURE_RECT    = 0x0000,  // ����
    MVBI_MORPH_STRUCTURE_ELLIPSE = 0x0001,  // ��Բ
    MVBI_MORPH_STRUCTURE_CROSS   = 0x0002,  // ʮ����
    MVBI_MORPH_STRUCTURE_CUSTOM  = 0x0003,  // ö��(�Զ���)
    MVBI_MORPH_STRUCTURE_MAX     = 0x0003  // �������

}MVBI_MORPH_STRUCTURE;

// ֡ƽ��ģʽ
typedef enum _MVBI_FRAME_AVG_TYPE
{
    MVBI_FRAME_AVG_STANDARD    = 0, // ��׼ģʽ
    MVBI_FRAME_AVG_ROLLING_AVG = 1, // Rolling����ƽ��ģʽ

}MVBI_FRAME_AVG_TYPE;

// ��Ե��������
typedef enum _MVBI_EDGE_POLARITY
{
    MVBI_EDGE_POLARITY_MIN            = 0x0001,
	MVBI_EDGE_POLARITY_DARK_TO_BRIGHT = 0x0001, // �ɺڵ��ױ�
	MVBI_EDGE_POLARITY_BRIGHT_TO_DARK = 0x0002, // �ɰ׵��ڱ�
	MVBI_EDGE_POLARITY_BOTH           = 0x0003, // �������ͱ�
    MVBI_EDGE_POLARITY_MAX            = 0x0003
}MVBI_EDGE_POLARITY;

// ��Եģ��
typedef enum _MVBI_EDGE_MODE
{
    MVBI_EDGE_MODE_MIN         = 0x0001,
    MVBI_EDGE_MODE_SIGNLE_EDGE = 0x0001, // ������Ե
    MVBI_EDGE_MODE_EDGE_PAIR   = 0x0002, // ��Ե��
    MVBI_EDGE_MODE_MAX         = 0x0002
}MVBI_EDGE_MODE;

// ��Ե����ģ��
typedef enum _MVBI_EDGE_SCORE_MODE
{
    MVBI_EDGE_SCORE_MODE_MIN         = 0x0001,
    MVBI_EDGE_SCORE_MODE_CONTRAST    = 0x0001, // �Աȶ�����
    MVBI_EDGE_SCORE_MODE_POSITION    = 0x0002, // λ������
    MVBI_EDGE_SCORE_MODE_SIZE        = 0x0003, // ��Ե�Լ������(����Ե��ʹ��)
    MVBI_EDGE_SCORE_MODE_STRADDLE    = 0x0004, // ��Ե�԰�������(����Ե��ʹ��)
    MVBI_EDGE_SCORE_MODE_MAX         = 0x0004
}MVBI_EDGE_SCORE_MODE;

//����ͶӰ����
typedef enum _MVBI_CALIPER_PROJECTION_TYPES
{
    MVBI_CALIPER_PROJECTION_TYPE_MIN  = 0x0000,
    MVBI_CALIPER_PROJECTION_TO_HEIGHT = 0x0000, // Ͷ���(����ͶӰ)
    MVBI_CALIPER_PROJECTION_TO_WIDTH  = 0x0001, // Ͷ���(����ͶӰ)
    MVBI_CALIPER_PROJECTION_TO_RADIUS = 0x0002, // Ͷ��뾶(����ͶӰ)
    MVBI_CALIPER_PROJECTION_TO_ARC    = 0x0003, // Ͷ��Բ��(����ͶӰ)
    MVBI_CALIPER_PROJECTION_TYPE_MAX  = 0x0003

}MVBI_CALIPER_PROJECTION_TYPES;

//���߶Աȶ���ֵ����
typedef enum _MVBI_CALIPER_THRESHOLD_TYPES
{
    MVBI_CALIPER_THRESHOLD_TYPE_MIN  = 0x0000,
    MVBI_CALIPER_THRESHOLD_ABSOLUTE  = 0x0000, // ������ֵ���̶���ֵ��
    MVBI_CALIPER_THRESHOLD_RELATIVE  = 0x0001, // �����ֵ����԰ٷֱȣ�
    MVBI_CALIPER_THRESHOLD_TYPE_MAX  = 0x0001

}MVBI_CALIPER_THRESHOLD_TYPES;

//Բ��������
typedef enum _MVBI_CIRCLE_FIND_MODES
{
    MVBI_CIRCLE_FIND_MODES_MIN = 0x0001, // ��СԲ��������
    MVBI_CIRCLE_FIND_BEST      = 0x0001, // �������Բ
    MVBI_CIRCLE_FIND_LARGEST   = 0x0002, // ��������Բ
    MVBI_CIRCLE_FIND_SMALLEST  = 0x0003, // ������С��Բ
    MVBI_CIRCLE_FIND_MODES_MAX = 0x0003  // ���Բ��������
}MVBI_CIRCLE_FIND_MODES;

//Բɨ�跽��
typedef enum _MVBI_CIRCLE_SCAN_TYPES
{
    MVBI_CIRCLE_SCAN_TYPES_MIN       = 0x0001, // ��СԲɨ�跽��
    MVBI_CIRCLE_SCAN_INNER_TO_OUTER  = 0x0001, // ��������
    MVBI_CIRCLE_SCAN_OUTER_TO_INNER  = 0x0002, // ��������
    MVBI_CIRCLE_SCAN_TYPES_MAX       = 0x0002  // ���Բɨ�跽��
}MVBI_CIRCLE_SCAN_TYPES;

//ֱ�߲�������
typedef enum _MVBI_LINE_FIND_MODES
{
    MVBI_LINE_FIND_MODES_MIN = 0x0001,
    MVBI_LINE_FIND_BEST      = 0x0001, // �������ֱ��
    MVBI_LINE_FIND_FIRST     = 0x0002, // ���ҵ�һ��ֱ��
    MVBI_LINE_FIND_LAST      = 0x0003, // �������һ��ֱ��
    MVBI_LINE_FIND_MODES_MAX = 0x0003
}MVBI_LINE_FIND_MODES;

//��Ե��������
typedef enum _MVBI_EDGE_FIND_MODES
{
    MVBI_EDGE_FIND_MODES_MIN = 0x0001,
    MVBI_EDGE_FIND_BEST      = 0x0001, // ������ǿ��Ե
    MVBI_EDGE_FIND_FIRST     = 0x0002, // ���ҵ�һ����Ե
    MVBI_EDGE_FIND_LAST      = 0x0003, // �������һ����Ե
    MVBI_EDGE_FIND_ALL       = 0x0004, // �������б�Ե
    MVBI_EDGE_FIND_MODES_MAX = 0x0004
}MVBI_EDGE_FIND_MODES;

//��Ե�Բ�������
typedef enum _MVBI_EDGE_PAIR_FIND_MODES
{
    MVBI_EDGE_PAIR_FIND_MODES_MIN = 0x0001,
    MVBI_EDGE_PAIR_FIND_WIDEST    = 0x0001, // ��������Ե��
    MVBI_EDGE_PAIR_FIND_NARROWEST = 0x0002, // ������խ��Ե��
    MVBI_EDGE_PAIR_FIND_STRONGEST = 0x0003, // ������ǿ��Ե��
    MVBI_EDGE_PAIR_FIND_WORST     = 0x0004, // ����������Ե��
    MVBI_EDGE_PAIR_FIND_FIRST     = 0x0005, // ���ҵ�һ����Ե��
    MVBI_EDGE_PAIR_FIND_LAST      = 0x0006, // �������һ����Ե��
    MVBI_EDGE_PAIR_FIND_NEAREST   = 0x0007, // ������ӽ���Ե��
    MVBI_EDGE_PAIR_FIND_FARTHEST  = 0x0008, // ������ӽ���Ե��
    MVBI_EDGE_PAIR_FIND_ALL       = 0x0009, // �������б�Ե��
    MVBI_EDGE_PAIR_FIND_MODES_MAX = 0x0009
}MVBI_PAIR_FIND_FIND_MODES;

// ֱ�߲��ҷ���
typedef enum _MVBI_LINE_FIND_ORIENT
{
    MVBI_LINE_FIND_ORIENT_MIN           = 0x0001,
    MVBI_LINE_FIND_ORIENT_UP_TO_DOWN    = 0x0001,  //���ϵ�������
    MVBI_LINE_FIND_ORIENT_LEFT_TO_RIGHT = 0x0002,  //����������
    MVBI_LINE_FIND_ORIENT_DOWN_TO_UP    = 0x0003,  //���µ�������
    MVBI_LINE_FIND_ORIENT_RIGHT_TO_LEFT = 0x0004,  //���ҵ�������
    MVBI_LINE_FIND_ORIENT_MAX           = 0x0004
}MVBI_LINE_FIND_ORIENT;

// ��Ե���ҷ���
typedef enum _MVBI_EDGE_FIND_ORIENT
{
    MVBI_EDGE_FIND_ORIENT_MIN             = 0x0001,
    MVBI_EDGE_FIND_ORIENT_UP_TO_DOWN      = 0x0001, //���ϵ�������
    MVBI_EDGE_FIND_ORIENT_LEFT_TO_RIGHT   = 0x0002, //����������
    MVBI_EDGE_FIND_ORIENT_DOWN_TO_UP      = 0x0003, //���µ�������
    MVBI_EDGE_FIND_ORIENT_RIGHT_TO_LEFT   = 0x0004, //���ҵ�������
    MVBI_EDGE_FIND_ORIENT_INNER_TO_OUTER  = 0x0005, //������������
    MVBI_EDGE_FIND_ORIENT_OUTER_TO_INNER  = 0x0006, //������������
    MVBI_EDGE_FIND_ORIENT_CLOCKWISE       = 0x0007, //˳ʱ������
    MVBI_EDGE_FIND_ORIENT_ANCLOCKWISE     = 0x0008, //��ʱ������
    MVBI_EDGE_FIND_ORIENT_MAX             = 0x0008
}MVBI_EDGE_FIND_ORIENT;


//��Ե�Ʒַ�ʽΪǰ���֣���Ե�ԼƷַ�ʽȫ������
typedef enum _MVBI_CALIPER_SCORE_TYPE
{
    MVBI_CALIPER_SCORE_TYPES_MIN           = 0x00000001, // ���߱�Ե�ԼƷ�������С���
    MVBI_CALIPER_SCORE_CONSTRAST           = 0x00000001, // �Աȶ����֣�����Ե�ԱȶȻ�߶ԶԱȶȾ�ֵ�Ʒ�
    MVBI_CALIPER_SCORE_POSITION            = 0x00000002, // λ�����֣�����Ե��߶Ե����������BOX�����ߵľ��Դ�ֱ����
    MVBI_CALIPER_SCORE_POSITION_NEG        = 0x00000004, // λ�����֣�����Ե��߶Ե����������BOX�����ߵĴ�ֱλ�ò�����ɸ���
    MVBI_CALIPER_SCORE_POSITION_NORM       = 0x00000008, // λ�����֣����߶Ե����������BOX�����ߵľ��Դ�ֱ��һ�����룬��һ����ĸΪ���߶Կ�ȣ��������edge_pair_width��
    MVBI_CALIPER_SCORE_POSITION_NORM_NEG   = 0x00000010, // λ�����֣����߶Ե����������BOX�����ߵĴ�ֱ��һ��λ�ò�����ɸ�������һ����ĸΪ���߶Կ��
    MVBI_CALIPER_SCORE_SIZE_DIFF_NORM      = 0x00000020, // ��Ե�Լ�����֣���|(�߶Ծ���-���߶Կ��)/���߶Կ��|�����߼Ʒַ�ʽ
    MVBI_CALIPER_SCORE_SIZE_DIFF_NORM_ASYM = 0x00000040, // ��Ե�Լ�����֣���(�߶Ծ���-���߶Կ��)/���߶Կ�ȣ�˫�߼Ʒַ�ʽ
    MVBI_CALIPER_SCORE_SIZE_NORM           = 0x00000080, // ��Ե�Լ�����֣����߶Ծ���/���߶Կ��
    MVBI_CALIPER_SCORE_STRADDLE            = 0x00000100, // ��Ե�԰������֣�����ȼƷ֣�������������box����������
    MVBI_CALIPER_SCORE_GRAY                = 0x00000200, // �ҶȼƷ֣�����Ե�ҶȻ�߶ԻҶȾ�ֵ�Ʒ�
    MVBI_CALIPER_SCORE_TYPES_MAX           = 0x000003FF, // ���߱�Ե�ԼƷ������

}MVBI_CALIPER_SCORE_TYPE;

// ģ��ģ������
typedef enum _MVBI_PAT_MODEL_TYPES
{
    MVBI_PAT_MODEL_TYPE_MIN   = 0x0001, // ��Сģ��ģ������
    MVBI_PAT_MODEL_TYPE_GRAY  = 0x0002, // �Ҷ�ģ��ģ��
    MVBI_PAT_MODEL_TYPE_EDGE  = 0x0003, // ��Եģ��ģ��
    MVBI_PAT_MODEL_TYPE_PROBE = 0x0004, // ̽��ģ��ģ��
    MVBI_PAT_MODEL_TYPE_MAX   = 0x0004  // ���ģ��ģ������
}MVBI_PAT_MODEL_TYPES;

// blob��������(MVBI_BlobSort/_MVBI_BlobSortʹ��)
typedef enum _MVBI_BLOBSORT_TYPE
{
    MVBI_BLOB_SORT_TYPE_MIN           = 0x00000001, // blob����ʽ��Сֵ
    MVBI_BLOB_SORT_TYPE_BY_AREA       = 0x00000001, // ������Ӵ�С��������
    MVBI_BLOB_SORT_TYPE_UP_TO_DOWN    = 0x00000002, // ���ϵ������� ��Y
    MVBI_BLOB_SORT_TYPE_LEFT_TO_RIGHT = 0x00000003, // ���������� ��X
    MVBI_BLOB_SORT_TYPE_TWO_DIMENSION = 0x00000004, // ��ά����
    MVBI_BLOB_SORT_TYPE_ANGLE_ASCEND  = 0x00000005, // box�Ƕ�����
    MVBI_BLOB_SORT_TYPE_NO_SORT       = 0x00000006, // ��������
    MVBI_BLOB_SORT_TYPE_MAX           = 0x00000006, // blob����ʽ���ֵ

}MVBI_BLOBSORT_TYPE;

// blob��������
typedef enum _MVBI_BLOBSORT_FEATURE
{
    MVBI_BLOB_SORT_FEATURE_MIN                  = 0x00000001, // blob�������������Сֵ
    MVBI_BLOB_SORT_FEATURE_AREA                 = 0x00000001, // ���
    MVBI_BLOB_SORT_FEATURE_PERIMETER            = 0x00000002, // �ܳ�
    MVBI_BLOB_SORT_FEATURE_CIRCULARITY          = 0x00000003, // Բ�ζ�
    MVBI_BLOB_SORT_FEATURE_RECTANGULARITY       = 0x00000004, // ���ζ�
    MVBI_BLOB_SORT_FEATURE_CENTROID_X           = 0x00000005, // ��ͨ������x
    MVBI_BLOB_SORT_FEATURE_CENTROID_Y           = 0x00000006, // ��ͨ������y
    MVBI_BLOB_SORT_FEATURE_BOX_ANGLE            = 0x00000007, // box�Ƕ�
    MVBI_BLOB_SORT_FEATURE_BOX_LONG_AXIS        = 0x00000008, // box���ᣨ��
    MVBI_BLOB_SORT_FEATURE_BOX_SHORT_AXIS       = 0x00000009, // box����(��)
    MVBI_BLOB_SORT_FEATURE_RECT_X               = 0x0000000A, // rect.x
    MVBI_BLOB_SORT_FEATURE_RECT_Y               = 0x0000000B, // rect.y
    MVBI_BLOB_SORT_FEATURE_PRINCIPAL_AXIS_ANGLE = 0x0000000C, // �������ľ�����Ƕ�
    MVBI_BLOB_SORT_FEATURE_AXIS_RATIO           = 0x0000000D, // ��ȣ�box���� / box����
    MVBI_BLOB_SORT_FEATURE_MAX                  = 0x0000000D, // blob��������������ֵ

}MVBI_BLOBSORT_FEATURE;

// blob����ʽ
typedef enum _MVBI_BLOBSORT_MODE
{
    MVBI_BLOB_SORT_MODE_MIN          = 0x00000001, // blob����ʽ��Сֵ
    MVBI_BLOB_SORT_MODE_ASCEND       = 0x00000001, // ����
    MVBI_BLOB_SORT_MODE_DESCEND      = 0x00000002, // ����
    MVBI_BLOB_SORT_MODE_NO_SORT      = 0x00000003, // ��������
    MVBI_BLOB_SORT_MODE_MAX          = 0x00000003, // blob����ʽ���ֵ

}MVBI_BLOBSORT_MODE;


//ʹ�ܱ�ǣ��������ɸѡ����
typedef enum _MVBI_BLOBSELECT_ENABLES
{
    MVBI_BLOBSELECT_ENABLE_MIN            = 0x00000000,  // ��С���
    MVBI_BLOBSELECT_ENABLE_CLOSED         = 0x00000000,  // ʹ�ܹر�
    MVBI_BLOBSELECT_ENABLE_AREA           = 0x00000001,  // ���ʹ��
    MVBI_BLOBSELECT_ENABLE_PERIMETER      = 0x00000002,  // ������ʹ��
    MVBI_BLOBSELECT_ENABLE_SHORTAXIS      = 0x00000004,  // ����ʹ��
    MVBI_BLOBSELECT_ENABLE_LONGAXIS       = 0x00000008,  // ����ʹ��
    MVBI_BLOBSELECT_ENABLE_CIRCULARITY    = 0x00000010,  // Բ�ζ�ʹ��
    MVBI_BLOBSELECT_ENABLE_RECTANGULARITY = 0x00000020,  // ���ζ�ʹ��
    MVBI_BLOBSELECT_ENABLE_CENTRABIAS     = 0x00000040,  // ��������ھ������ĵ�ƫ��ʹ��
    MVBI_BLOBSELECT_ENABLE_AXIS_RATIO     = 0x00000080,  // ���ʹ��(����/����)
    MVBI_BLOBSELECT_ENABLE_MAX            = 0x000000FF,  // �����

}MVBI_BLOBSELECT_ENABLES;

//blob������Ч���
typedef enum _MVBI_BLOB_VALID_FEATURE_FLAG
{
    MVBI_BLOB_VALID_MIN            = 0x00000001,  // ��С���
    MVBI_BLOB_VALID_AREA           = 0x00000001,  // �����Ч
    MVBI_BLOB_VALID_RECT           = 0x00000002,  // ��Χ����Ч
    MVBI_BLOB_VALID_CENTROID       = 0x00000004,  // ��ͨ�����ģ����ģ���Ч
    MVBI_BLOB_VALID_PERIMETER      = 0x00000008,  // ��������Ч
    MVBI_BLOB_VALID_CIRCULARITY    = 0x00000010,  // Բ�ζ���Ч
    MVBI_BLOB_VALID_BOX            = 0x00000020,  // ��С�����Ӿ���Ч
    MVBI_BLOB_VALID_SHORTAXIS      = 0x00000040,  // ������Ч
    MVBI_BLOB_VALID_LONGAXIS       = 0x00000080,  // ������Ч
    MVBI_BLOB_VALID_ANGLE          = 0x00000100,  // �Ƕ���Ч
    MVBI_BLOB_VALID_RECTANGULARITY = 0x00000200,  // ���ζ���Ч
    MVBI_BLOB_VALID_CENTRABIAS     = 0x00000400,  // ��������ھ������ĵ�ƫ����Ч
    MVBI_BLOB_VALID_AXIS_RATIO     = 0x00000800,  // ��ȣ����� / ���ᣩ��Ч
    MVBI_BLOB_VALID_MAX            = 0x00000FFF,  // �����

}MVBI_BLOB_VALID_FEATURE_FLAG;


//֧�ֵ�ROI���ͣ���Ĥ����ģ���ڴ����ӿ�MVBI_GenRoiMaskBufferSize_opt_prʹ��
typedef enum _MVBI_GEN_ROI_MASK_TYPE
{
    MVBI_GEN_ROI_MASK_TYPE_MIN       = 0x0001, // ��Сֵ
    MVBI_GEN_ROI_MASK_TYPE_RECT      = 0x0001, // ��С��Χ����
    MVBI_GEN_ROI_MASK_TYPE_BOX       = 0x0002, // ��С��Χ��
    MVBI_GEN_ROI_MASK_TYPE_CIRCLE    = 0x0004, // Բ
    MVBI_GEN_ROI_MASK_TYPE_ANNULUS   = 0x0008, // Բ��
    MVBI_GEN_ROI_MASK_TYPE_POLYGON_I = 0x0010, // �����
    MVBI_GEN_ROI_MASK_TYPE_MAX       = 0x001F, // ���ֵ

}MVBI_GEN_ROI_MASK_TYPE;

// Բ��Բ��λ�ù�ϵ
typedef enum _MVB_CIRCLE_TO_CIRCLE_TYPES
{
    MVB_CIRCLE_TO_CIRCLE_TYPES_MIN = 0x00000001,
    MVB_CIRCLE_TO_CIRCLE_CONTAIN   = 0x00000001,     // �ں�
    MVB_CIRCLE_TO_CIRCLE_INSCRIBE  = 0x00000002,     // ����
    MVB_CIRCLE_TO_CIRCLE_INTERSECT = 0x00000003,     // �ཻ
    MVB_CIRCLE_TO_CIRCLE_EXCIRCLE  = 0x00000004,     // ����
    MVB_CIRCLE_TO_CIRCLE_DEVIATION = 0x00000005,     // ����
    MVB_CIRCLE_TO_CIRCLE_TYPES_MAX = 0x00000005,
}MVB_CIRCLE_TO_CIRCLE_TYPES;


// RGBת�Ҷȴ��������
typedef enum _MVBI_RGB_TO_GRAY_TYPE
{
    MVBI_RGB_TO_GRAY_TYPE_MIN            = 0x00000001,  // ��С��������
    MVBI_RGB_TO_GRAY_GENERAL_RATIO       = 0x00000001,  // ͨ��ת������ 0.299r + 0.587g + 0.114b
    MVBI_RGB_TO_GRAY_AVERAGE_RATIO       = 0x00000002,  // ƽ��ת������ (r + g + b) / 3
    MVBI_RGB_TO_GRAY_MAX_CHANNEL_VALUE   = 0x00000003,  // ͨ�����ֵ max(r, g, b)
    MVBI_RGB_TO_GRAY_MIN_CHANNEL_VALUE   = 0x00000004,  // ͨ����Сֵ min(r, g, b)
    MVBI_RGB_TO_GRAY_TYPE_MAX            = 0x00000004,  // ���������

}MVBI_RGB_TO_GRAY_TYPE;

#define MVB_BINARY_TRUE  (0xff) // ��ֵͼtrue
#define MVB_BINARY_FALSE (0)   // ��ֵͼfalse

// ���̸�
#define MVBI_CHESSBOARD_FLT_MAX       (1000000.0f) // ���̸�֮���������pixel^2
#define MVBI_CHESSBOARD_MAX_ERODENUM  (6)          // ���ʴ��������
#define MVBI_CHESSBOARD_WIDTH_MIN     (64)         // ֧����Сͼ���
#define MVBI_CHESSBOARD_HEIGHT_MIN    (64)         // ֧����Сͼ���
#define MVBI_CHESSBOARD_PATTERN_WMIN  (4)          // ֧����Сģ���
#define MVBI_CHESSBOARD_PATTERN_HMIN  (4)          // ֧����Сģ���
#define MVBI_CHESSBOARD_PATTERN_WMAX  (25)         // ֧�����ģ���
#define MVBI_CHESSBOARD_PATTERN_HMAX  (25)         // ֧�����ģ���
#define MVBI_CHESSBOARD_BORDER        (8.0f)       // �ǵ���ͼ���Ե����С����
#define MVBI_CHESSBOARD_NUM_MAX       (800)        // ֧����󷽸����
#define MVBI_CHESSBOARD_CORNUM_MAX    (3200)       // ֧����󷽸�ǵ����
#define MVBI_CHESSBOARD_THRESH_GLOBAL (1)          // �ֲ���ֵ
#define MVBI_CHESSBOARD_THRESH_LOCAL  (0)          // ȫ����ֵ
#define MVBI_CHESSBOARD_MIN_WINWIDTH  (2)        // �����ؽǵ���ȡ��С����һ����
#define MVBI_CHESSBOARD_MIN_WINHEIGHT (2)        // �����ؽǵ���ȡ��С����һ��߶�
#define MVBI_CHESSBOARD_MAX_WINWIDTH  (50)       // �����ؽǵ���ȡ��󴰿�һ����
#define MVBI_CHESSBOARD_MAX_WINHEIGHT (50)       // �����ؽǵ���ȡ��󴰿�һ��߶�

#define  MVB_SWAP(TYPE, a, b) \
{                             \
    TYPE c = a;               \
    a = b;                    \
    b = c;                    \
    }

// λ�ò���ģʽ
typedef enum _MVBI_POS_FIX_MODE
{
    MVBI_POS_FIX_MODE_MIN       = 0x00000001,  // ��С���
    MVBI_POS_FIX_MODE_NONE      = 0x00000001,  // ������
    MVBI_POS_FIX_MODE_HORI      = 0x00000002,  // ˮƽ����
    MVBI_POS_FIX_MODE_VERT      = 0x00000003,  // ��ֱ����
    MVBI_POS_FIX_MODE_HV        = 0x00000004,  // ˮƽ��ֱ����
    MVBI_POS_FIX_MODE_HVA       = 0x00000005,  // ˮƽ��ֱ�ǶȲ���
	MVBI_POS_FIX_MODE_HVAS      = 0x00000006,  // ˮƽ��ֱ�Ƕȳ߶Ȳ���
    MVBI_POS_FIX_MODE_MAX       = 0x00000006,  // �����
}MVBI_POS_FIX_MODE;

// ��ֵ���ָ�����
typedef enum _MVBI_LINE_SCAN_SEGMENT_TYPE
{
    MVBI_LINE_SCAN_SEGMENT_BRIGHT  = 0x00000001,    // �ָ���ȱ������Ķ���
    MVBI_LINE_SCAN_SEGMENT_DARK    = 0x00000002,    // �ָ���ȱ������Ķ���

}MVBI_LINE_SCAN_SEGMENT_TYPE;

// ��ɨ�跽ʽ����
typedef enum _MVBI_LINE_SCAN_MODE_TYPE
{
    MVBI_LINE_SCAN_HORIZONTAL_MODE          = 0x00000001,    // ˮƽ������ɨ�裬�ʺϷָֱ����Ķ���
    MVBI_LINE_SCAN_VERTICAL_MODE            = 0x00000002,    // ��ֱ������ɨ�裬�ʺϷָ�ˮƽ����Ķ���
    MVBI_LINE_SCAN_HORIZONTAL_VERTICAL_MODE = 0x00000003,    // ˮƽ�Ӵ�ֱ������ɨ��

}MVBI_LINE_SCAN_MODE_TYPE;

// �ع麯��(regression function)
typedef enum _MVB_REGRESSION_FUN
{
    MVB_REGRESSION_FUN_LEAST_SQUARE = 1, // ��С����
    MVB_REGRESSION_FUN_HUBER        = 2, // huber
    MVB_REGRESSION_FUN_TUKEY        = 3, // tukey
}MVB_REGRESSION_FUN;

//���ڻع���Ƶļ�����ϳ�ʼ������
typedef enum _MVBI_GEOFIT_INIT_TYPE
{
    MVBI_GEOFIT_INIT_TYPE_MIN           = 0x0001,
    MVBI_GEOFIT_INIT_TYPE_LEAST_SQUARE  = 0x0001,  // һ��ȫ����С����
    MVBI_GEOFIT_INIT_TYPE_LS_EXHAUSTION = 0x0002,  // ��پֲ���С���ˣ�ȡ���
    MVBI_GEOFIT_INIT_TYPE_OUTSIDE       = 0x0003,  // �ⲿ����
    MVBI_GEOFIT_INIT_TYPE_MAX           = 0x0003
}MVBI_GEOFIT_INIT_TYPE;

// ȱ�ݹ�������
typedef enum _MVBI_DEFECT_FILTER_TYPE
{
    MVBI_DEFECT_FILTER_TYPE_NONE  = 0, // �����й���
    MVBI_DEFECT_FILTER_TYPE_INNER = 1, // �����ұ�/�±ߣ��ڲ���ȱ��,
    MVBI_DEFECT_FILTER_TYPE_OUTER = 2, // �������/�ϱ�,�ⲿ��ȱ��,
    
}MVBI_DEFECT_FILTER_TYPE;

// ȱ����������
typedef enum _MVBI_DEFECT_SORT_TYPE
{
    MVBI_DEFECT_SORT_BY_SIZE = 1, // ���ճߴ��������
    MVBI_DEFECT_SORT_BY_POS  = 2, // ����λ�ý�������
    MVBI_DEFECT_SORT_BY_AREA = 3, // ���������������
}MVBI_DEFECT_SORT_TYPE;

// ���ⷽ����νṹ��
/*
*         1.��Ӿ��νǶȷ�Χ[-pi/2��pi/2]����ʾ�������᷽����ˮƽx��ļн�.
*         2.���εĿ��Ϊ���ᣬ�߶�Ϊ����.
*         3.�˴�����С��Ӿ����ǽ����ص㰴�㴦����[1,1]����Ӿ��ο����1.
*           ���ʱ���ζ�ʱ�����ô˺����õ�width��height�������sqrt(2)���ڽ���.
*           ʵ�ʿ�ȵķ�Χ��[width+1~width+sqrt(2)].
*/
typedef struct _MVBI_BOX_F
{
    HKA_F32 center_x;           // ���ĵ�������
    HKA_F32 center_y;           // ���ĵ�������
    HKA_F32 width;              // ���ο�ȡ����Ϊ������
    HKA_F32 height;             // ���θ߶ȡ��߶�Ϊ�̰���
    HKA_F32 angle;              // ���νǶȡ�
} MVBI_BOX_F;

typedef struct _MVBI_BOX_I
{
    HKA_S32 center_x;           // ���ĵ�������
    HKA_S32 center_y;           // ���ĵ�������
    HKA_S32 width;              // ���ο�ȡ����Ϊ������
    HKA_S32 height;             // ���θ߶ȡ��߶�Ϊ�̰���
    HKA_F32 angle;              // ���νǶȡ�
} MVBI_BOX_I;

typedef MVBI_BOX_F MVBI_BOX;

// �������ص������
typedef struct _MVBI_CONTOUR_32F
{
    HKA_POINT_F       *data;     // ���ص��ڴ�
    HKA_S32            count;    // ��������ӵ�е����ظ���  

}MVBI_CONTOUR_F;

// ��ͨ������
typedef struct _MVBI_CONTOUR_S
{
    HKA_POINT_S *point;     // �������㼯
    HKA_S32      point_num; // ��������

}MVBI_CONTOUR_S;

// �ſ�����
typedef struct _MVBI_BLOB_PROP
{
    MVBI_BOX_F  box;
    HKA_POINT_F centroid;
    HKA_S32     area;
}MVBI_BLOB_PROP;

//����BLOB��Ϣ���
typedef struct _MVBI_BLOB_PROPS
{
    HKA_F32        area;               // ���
    HKA_RECT_I     rect;               // ����ͨ���Χ��
    HKA_POINT_F    centroid;           // ��ͨ�����ģ����ģ�

    HKA_F32        perimeter;          // �ܳ�
    HKA_F32        circularity;        // Բ�ζ�

    MVBI_BOX_F     box;                // ��С�����Ӿ�
    HKA_F32        shortaxis;          // ���᳤��
    HKA_F32        longaxis;           // ���᳤��
    HKA_F32        axis_ratio;         // ��ȣ�����/���ᣩ
    HKA_F32        rectangularity;     // ���ζ�

    HKA_F32        centra_bias;        // �����������Ӿ����ĵ�ƫ��ֵ

    HKA_F32        angle;              // �Ƕ�(�������ľ�����Ƕ�)

    HKA_F32        score;              // ����

    HKA_VOID      *domain;             // ����ͨ����
    HKA_S32        domain_index;       // ��ͨ���и�blob��λ�������ţ�0,1,2,3,4,����
    MVBI_CONTOUR_S domain_contour;     // ����ͨ������

    HKA_S32        label_id;           // ��ǩֵ������ǰblob�ĻҶ�ֵ

}MVBI_BLOB_PROPS;

// ���ߵ�����Ե�������Ϣ
typedef struct _MVBI_CALIPER_INFO
{
    HKA_POINT_F edge_point;   // ���������ĵ�����
    HKA_F32     bias;         // �������box��������Ծ��루�����ɸ���
    HKA_S32     polarity;     // ���߼��ԣ�1���ڵ��׵ı��ߣ�2���׵��ڵı���
    HKA_F32     score;        // �÷�
}MVBI_CALIPER_INFO;

// ���߼���Ե��Ϣ����Ե����ʹ�ã�
typedef struct _MVBI_CALIPER_EDGE
{
    HKA_POINT_F edge_point;   // ���������ĵ�����
    HKA_F32     bias;         // �������box��������Ծ��루�����ɸ���
    HKA_S32     polarity;     // ���߼��ԣ�1���ڵ��׵ı��ߣ�2���׵��ڵı���
}MVBI_CALIPER_EDGE;

// ���߼����߶���Ϣ���
typedef struct _MVBI_CALIPER_PAIR_INFO
{
    MVBI_CALIPER_EDGE caliper[2]; // ��Ե0���Ե1��Ϣ
    HKA_POINT_F       centre;     // ��Ե�����ĵ�
    HKA_F32           position;   // ��Ե��λ�ã���Ե�����ģ�����ƽ��������������ĵľ��룬�����ɸ���
    HKA_F32           dist;       // ��Ե�Լ��
    HKA_F32           score;      // �÷�
}MVBI_CALIPER_PAIR_INFO;

// ģ��ƥ����Ϣ
typedef struct _MVBI_PAT_MATCH_INFO
{
    MVBI_BOX_F     match_box;    // ģ��ƥ�������Χ��
    HKA_POINT_F    match_point;  // ģ��ƥ���
    HKA_F32        match_scale;  // ģ��ƥ��߶�
    HKA_F32        match_score;  // ���Ʒ���
}MVBI_PAT_MATCH_INFO;

// Բϵ��(����)
typedef struct _MVB_CIRCLE_I
{
    HKA_POINT_I center;       // Բ���ĵ�
    HKA_F32     radius;       // Բ�뾶
}MVB_CIRCLE_I;

// Բϵ��(������)
typedef struct _MVB_CIRCLE_F
{
    HKA_POINT_F center;        // Բ���ĵ�
    HKA_F32     radius;        // Բ�뾶
}MVB_CIRCLE_F;

// Բ��(������)
typedef struct _MVB_ARC_F
{
    HKA_POINT_F center;        // Բ���ĵ�
    HKA_F32     radius;        // Բ�뾶
    HKA_F32     start_angle;   // ��ʼ�Ƕ�
    HKA_F32     end_angle;     // ��ֹ�Ƕ�
}MVB_ARC_F;

//ֱ�ߵ�ϵ��
typedef struct _MVB_LINE_COE_
{
    HKA_F32 a;
    HKA_F32 b;
    HKA_F32 c;
}MVB_LINE_COE;

// ֱ��ϵ��(����)
typedef struct _MVB_LINE_F
{
    HKA_POINT_F point_start;   // ֱ�����
    HKA_POINT_F point_end;     // ֱ���յ�
    HKA_F32     angle;         // ֱ�߽Ƕ�
}MVB_LINE_F;

// ֱ��ϵ��(������)
typedef struct _MVB_LINE_I
{
    HKA_POINT_I point_start;   // ֱ�����
    HKA_POINT_I point_end;     // ֱ���յ�
    HKA_F32     angle;         // ֱ�߽Ƕ�
}MVB_LINE_I;

// ��Բ����(������)
typedef struct _MVB_ELLIPSE_F
{
    HKA_POINT_F center;        // ��Բ����
    HKA_POINT_F focus1;        // ��Բ����1
    HKA_POINT_F focus2;        // ��Բ����2
    HKA_F32     major_axis;    // ��Բ���᳤��
    HKA_F32     minor_axis;    // ��Բ���᳤��
    HKA_F32     angle;         // ��Բ�Ƕ�
}MVB_ELLIPSE_F;

//��Բ��ϵ��
typedef struct _MVB_ELLIPSE_COE_F
{
    HKA_F32 a;
    HKA_F32 b;
    HKA_F32 c;
    HKA_F32 d;
    HKA_F32 e;
    HKA_F32 f;
}MVB_ELLIPSE_COE_F;

// rhomboid ƽ���ı��νṹ��
typedef struct _MVBI_RHOMBOID_F 
{
    HKA_F32 center_x;            // ���ĵ�������
    HKA_F32 center_y;            // ���ĵ�������
    HKA_F32 width;               // ƽ���ı��ο���߳�
    HKA_F32 height;              // ƽ���ı��θ���߳�
    HKA_F32 rotation;            // ��ת�Ƕ�
    HKA_F32 skew;                // ��б�Ƕ�
} MVBI_RHOMBOID_F;

typedef struct _MVBI_RHOMBOID_I 
{
    HKA_S32 center_x;            // ���ĵ�������
    HKA_S32 center_y;            // ���ĵ�������
    HKA_S32 width;               // ƽ���ı��ο���߳�
    HKA_S32 height;              // ƽ���ı��θ���߳�
    HKA_F32 rotation;            // ��ת�Ƕ�
    HKA_F32 skew;                // ��б�Ƕ�
} MVBI_RHOMBOID_I;

// �Ƕȷ���
typedef enum _MVBI_ANGLE_DIR_TYPE
{
    MVBI_ANGLE_DIR_ANTI_CLOCKWISE = 1, // ��ʱ��
    MVBI_ANGLE_DIR_CLOCKWISE      = 2, // ˳ʱ��

}MVBI_ANGLE_DIR_TYPE;

// �뾶����
typedef enum _MVBI_POLAR_RADIUS_DIR
{
    MVBI_POLAR_RADIUS_DIR_INNER_TO_OUTER = 1, // ��������
    MVBI_POLAR_RADIUS_DIR_OUTER_TO_INNER = 2, // ��������

}MVBI_POLAR_RADIUS_DIR;

// annulus��Բ����
typedef struct _MVBI_ANNULUS_I
{
    HKA_POINT_I center;        // ���ĵ�
    HKA_S32     inner_radius;  // ��Բ�뾶
    HKA_S32     outer_radius;  // ��Բ�뾶
    HKA_F32     start_angle;   // Բ����ʼ�Ƕ�
    HKA_F32     angle_extend;  // Բ���Ƕȷ�Χ
}MVBI_ANNULUS_I;

// annulus
typedef struct _MVBI_ANNULUS_F
{
    HKA_POINT_F center;        // ���ĵ�
    HKA_F32     inner_radius;  // ��Բ�뾶
    HKA_F32     outer_radius;  // ��Բ�뾶
    HKA_F32     start_angle;   // Բ����ʼ�Ƕ�
    HKA_F32     angle_extend;  // Բ���Ƕȷ�Χ
}MVBI_ANNULUS_F;

// Բ��
typedef struct _MVBI_ARC
{
    HKA_POINT_F center;      // Բ�����ĵ�
    HKA_F32     radius;      // Բ���뾶
    HKA_F32     start_angle; // Բ����ʼ�Ƕ�
    HKA_F32     angle_extend; // Բ���Ƕȷ�Χ
}MVBI_ARC;

//�����(������)
typedef struct _MVB_POLYGON_S
{
    HKA_S32       vertex_num;     //������
    HKA_POINT_S  *vertex_points;  //����
}MVB_POLYGON_S;

//�����(����)
typedef struct _MVB_POLYGON_I
{
    HKA_S32       vertex_num;      //������
    HKA_POINT_I  *vertex_points;   //����
}MVB_POLYGON_I;

//�����(������)
typedef struct _MVB_POLYGON_F
{
    HKA_S32       vertex_num;      //������
    HKA_POINT_F  *vertex_points;   //����
}MVB_POLYGON_F;

// ROI��Ԫ
typedef union _MVB_ROI_LET
{
    HKA_RECT_I     roi_rect;    // ��С��Χ����
    MVBI_BOX_F     roi_box;     // ��С��Χ��
    MVB_CIRCLE_F   roi_circle;  // Բ
    MVBI_ANNULUS_F roi_annulus; // Բ��
    MVB_POLYGON_I  roi_polygon; // ����α�ʾ
}MVB_ROI_LET;

// ROI����
typedef struct _MVB_ROI_PARAM
{
    MVB_ROI_LET  roi_let;       // ROI��Ԫ
    HKA_S32      type;          // ROI����
}MVB_ROI_PARAM;

// ROI����
typedef enum _MVB_ROI_TYPE
{
    MVB_ROI_TYPE_RECT      = 0x0000, // ��С��Χ����
    MVB_ROI_TYPE_BOX       = 0x0001, // ��С��Χ��
    MVB_ROI_TYPE_CIRCLE    = 0x0002, // Բ
    MVB_ROI_TYPE_ANNULUS   = 0x0003, // Բ��
    MVB_ROI_TYPE_POLYGON_I = 0x0004, // �����
    MVB_ROI_TYPE_NUM       = 0x0005,
}MVB_ROI_TYPE;

typedef struct _MVBI_EDGELET
{
    HKA_POINT_F position;   // λ��
    HKA_F32     angle;      // ����
    HKA_F32     magnitude;  // ��ֵ
}MVBI_EDGELET;

// EdgeLet Chain����Ե������
typedef struct _MVBI_EDGELET_CHAIN
{
    MVBI_EDGELET *edgelets;        // ��Ե��(EdgeLet)����
    HKA_S32       edgelet_count;    // ��Ե�����
}MVBI_EDGELET_CHAIN;

// EdgeLet Chain Set����Ե������
typedef struct _MVBI_EDGELET_CHAIN_SET
{
    MVBI_EDGELET    *edgelets;           // ��Ե��(EdgeLet)����
    HKA_S32         *chain_start_index;  // ÿ����Ե����(FeatureLet Chain)�ڱ�Ե��(EdgeLet)�������ʼλ��
    HKA_S32         *chain_length;       // ÿ����Ե����(FeatureLet Chain)����    
    HKA_S32         chain_count;         // ��Ե��������
    HKA_S32         edgelet_count;       // ��Ե�����
    HKA_S32         edgelet_capacity;    // ����Ե�����
    HKA_S32         chain_capacity;      // ����Ե��������
}MVBI_EDGELET_CHAIN_SET;

// FeatureLet��Ԫ������
typedef struct _MVBI_FEATURELET
{
    HKA_POINT_F position;   // λ��
    HKA_F32     angle;      // ����
    HKA_F32     magnitude;  // ��ֵ/��Գ߶�����
    HKA_F32     weight;     // Ȩ��(��ʾ��Ҫ�̶ȣ�Ĭ��ֵ1)
    HKA_S32     is_mod_180; // ����ΧΪ360����180
        
}MVBI_FEATURELET;

// FeatureLet Chain��Ԫ��������
typedef struct _MVBI_FEATURELET_CHAIN
{
    MVBI_FEATURELET *featurelets;        // Ԫ����(FeatureLet)����
    HKA_S32          feature_count;       // Ԫ��������
}MVBI_FEATURELET_CHAIN;

// FeatureLet Chain Set��Ԫ���������ϣ�
typedef struct _MVBI_FEATURELET_CHAIN_SET
{
    MVBI_FEATURELET *featurelets;        // Ԫ����(FeatureLet)����
    HKA_S32         *chain_start_index;  // ÿ��Ԫ������(FeatureLet Chain)��Ԫ����(FeatureLet)�������ʼλ��
    HKA_S32         *chain_length;       // ÿ��Ԫ������(FeatureLet Chain)����    
    HKA_S32         *cholse_chain;       // ÿ��Ԫ������(FeatureLet Chain)�ǿ��������Ǳ�������ǩ
    HKA_S32          chain_count;         // Ԫ����������
    HKA_S32          feature_count;       // Ԫ��������
    HKA_S32          featurelet_capacity; // ���Ԫ��������
    HKA_S32          chain_capacity;      // ���Ԫ����������
}MVBI_FEATURELET_CHAIN_SET;

// ��״
typedef union _MVBI_SHAPE
{
    MVB_LINE_F    line;
    MVB_CIRCLE_F  circle;
    MVB_ARC_F     arc;
    MVB_ELLIPSE_F ellipse;
    
}MVBI_SHAPE;

// λ������ʱ�Ļ�׼��
typedef struct _MVBI_FIDUCIAL_POSE
{
    HKA_POINT_F basis_point;     // ��׼��
    HKA_F32     basis_angle;     // ��׼�Ƕ�
	HKA_F32     basis_scale_x;   // x����߶�
	HKA_F32     basis_scale_y;   // y����߶�
	HKA_S32     reserved[6];     // �����ֽ�

	//����� == ����
	bool operator==(const _MVBI_FIDUCIAL_POSE &FixInfo)
	{
		return((basis_point.x == FixInfo.basis_point.x)
			&& (basis_point.y == FixInfo.basis_point.y)
			&& (basis_angle == FixInfo.basis_angle)
			&& (basis_scale_x == FixInfo.basis_scale_x)
			&& (basis_scale_y == FixInfo.basis_scale_y));
	}
}MVBI_FIDUCIAL_POSE;

//Բ����/���״̬
typedef enum _MVBI_CIRCLE_STATUS
{
    MVBI_CIRCLE_STATUS_FAILURE = 0x0000,  // ����/���ʧ��
    MVBI_CIRCLE_STATUS_SUCCESS = 0x0001,  // ����/��ϳɹ������Բ���
    MVBI_CIRCLE_STATUS_LIMITED = 0x0002,  // ����/��ϡ��ɹ�����Բ������������Ҫ����뾶����

}MVBI_CIRCLE_STATUS;

//���α�Ե��״̬
typedef enum _MVBI_GEOEDGET_STATUS
{
    MVBI_GEOEDGET_STATUS_USED    = 0x0001,  // ���ҳɹ���ʹ��
    MVBI_GEOEDGET_STATUS_NO_USED = 0x0002,  // ���ҳɹ�������ʹ��
    MVBI_GEOEDGET_STATUS_NO_FIND = 0x0003   // ����ʧ��

}MVBI_GEOEDGET_STATUS;

// ���α�Ե����Ϣ
typedef struct _MVBI_GEOEDGE_INFO
{
    HKA_POINT_F edge_point;   // ��Ե��
    HKA_F32     score;        // ��Ե�÷�
    HKA_S32     polarity;     // ��Ե����
    HKA_F32     dist;         // ��Ե����
    HKA_S32     status;       // ��Ե�����״̬
}MVBI_GEOEDGE_INFO; 

//���α�Ե�����Ϣ
typedef struct _MVBI_GEOEDGE_WIDTH_INFO
{
    HKA_POINT_F edge0_point;  // ��Ե��0
    HKA_POINT_F edge1_point;  // ��Ե��1
    HKA_F32     score;        // ��Ե�÷�
    HKA_S32     polarity0;    // ��Ե0����
    HKA_S32     polarity1;    // ��Ե1����
    HKA_F32     dist;         // ��Ե����
    HKA_S32     status;       // ��Ե�����״̬
}MVBI_GEOEDGE_WIDTH_INFO; 

//PARALLEL�����α�Ե����Ϣ�б�
typedef struct _MVBI_GEOEDGE_INFO_LIST
{
    MVBI_GEOEDGE_INFO *edge_info; // ��Ե����Ϣ
    HKA_S32            edge_num;  // ��Ե�����
}MVBI_GEOEDGE_INFO_LIST; 

//���߲��ң�PARALLEL�����������Ե����Ϣ
typedef struct _MVBI_PARALLEL_INFO
{
    MVB_LINE_F             line;           //ֱ�߶�
    HKA_S32                line_idx;       //ֱ�߶��������
    HKA_S32                line_sts;       //ֱ�߶�״̬
    HKA_F32                line_fit_err;   //ֱ�߶�������
    HKA_F32                line_intensity; //ֱ�߱�Եǿ�ȣ�ֱ�����ڱ�ԵԽ��������ֵԽ��
    MVBI_GEOEDGE_INFO_LIST edge;           //ֱ�߶α�Ե����Ϣ

}MVBI_PARALLEL_INFO;

//���߲��ң�PARALLEL��������������
typedef enum _MVBI_PARALLEL_SORT_TYPE
{
    MVBI_PARALLEL_SORT_TYPE_MIN          = 0x0001,
    MVBI_PARALLEL_SORT_NEAR_TO_FAR       = 0x0001, // �ɽ���Զ�����������һ�������£�
    MVBI_PARALLEL_SORT_FAR_TO_NEAR       = 0x0002, // ��Զ�����������������������ϣ�
    MVBI_PARALLEL_SORT_ERROR_ASCEND      = 0x0003, // ������������С����
    MVBI_PARALLEL_SORT_INTENSITY_DESCEND = 0x0004, // ��Եǿ�Ƚ�����ǿ������
    MVBI_PARALLEL_SORT_TYPE_MAX          = 0x0004
}MVBI_PARALLEL_SORT_TYPE;

//���߲��ң�PARALLEL������
typedef enum _MVBI_PARALLEL_FIND_MODE
{
    MVBI_PARALLEL_FIND_TYPE_MIN  = 0x0001,
    MVBI_PARALLEL_FIND_FIRST     = 0x0001, // ��һ��
    MVBI_PARALLEL_FIND_LAST      = 0x0002, // ���һ��
    MVBI_PARALLEL_FIND_STRONGEST = 0x0003, // ��Ե��ǿ
    MVBI_PARALLEL_FIND_INDEX     = 0x0004, // ָ����ţ�һ����
    MVBI_PARALLEL_FIND_ALL       = 0x0005, // ����
    MVBI_PARALLEL_FIND_TYPE_MAX  = 0x0005
}MVBI_PARALLEL_FIND_MODE;

// ���߲��ң�MULTILINE���е�ֱ�߱�Ե����
typedef enum _MVBI_MULTILINE_LINE_POLARITY
{
    MVBI_MULTILINE_LINE_POLARITY_MIN            = 0x0001,
    MVBI_MULTILINE_LINE_POLARITY_DARK_TO_BRIGHT = 0x0001, // �ɺڵ���
    MVBI_MULTILINE_LINE_POLARITY_BRIGHT_TO_DARK = 0x0002, // �ɰ׵���
    MVBI_MULTILINE_LINE_POLARITY_MIXED          = 0x0003, // �ɺڵ��� & �ɰ׵���(ͬһ���߶��е㼯�����ּ��Ե�)
    MVBI_MULTILINE_LINE_POLARITY_EITHER         = 0x0004, // �ɺڵ��� | �ɰ׵���(ͬһ���߶��е㼯��һ�ּ��Ե�)
    MVBI_MULTILINE_LINE_POLARITY_MAX            = 0x0004

}MVBI_MULTILINE_LINE_POLARITY;

//MULTILINE:ֱ�����ģʽ
typedef enum _MVBI_MULTILINE_FIT_MODE
{
    MVBI_MULTILINE_FIT_MODE_RANSAC    = 0x0001,  // RANSAC
    MVBI_MULTILINE_FIT_MODE_EXHAUST   = 0x0002,  // ���

}MVBI_MULTILINE_FIT_MODE;

//MULTILINE:��Ե����Ϣ
typedef struct _MVBI_MULTILINE_EDGE_INFO
{
    HKA_POINT_F edge_point;      // ��Ե��
    HKA_S32     polarity;        // ��Ե����
    HKA_F32     magnitude;       // �ݶȷ�ֵ
    HKA_F32     orientation;     // �ݶȷ���
    HKA_F32     dist;            // ��Ե���루��������
    HKA_S32     status;          // ��Ե��״̬
    HKA_S32     caliper_index;   // ͶӰ��������
    HKA_S32     line_index;      // �����߶�����
}MVBI_MULTILINE_EDGE_INFO;

//MULTILINE:���߲������������Ե����Ϣ
typedef struct _MVBI_MULTILINE_INFO
{
    MVB_LINE_F line;           // ��ǰֱ�߶�
    HKA_F32    line_fit_err;   // ��ǰֱ�߶�������
    HKA_F32    line_intensity; // ��ǰֱ�߶ζԱȶ�ǿ��
    HKA_F32    coverage_score; // �����ʷ���
    HKA_S32    inliers_num;    // ��Ⱥ������
    HKA_S32    line_index;     // �߶�����

}MVBI_MULTILINE_INFO;

// ��ά�任����
typedef struct _MVBI_TRANSFORM_2D_PARAM
{
    HKA_F32 scale;  // �߶�
    HKA_F32 tx;     // x����ƽ��
    HKA_F32 ty;     // y����ƽ��
    HKA_F32 rotate; // ��ת�������ƣ�
    HKA_F32 aspect; // y�����x�������
    HKA_F32 skew;   // ��б��
}MVBI_TRANSFORM_2D_PARAM;

// ȱ������
typedef enum _MVBI_EDGE_DEFECT_TYPE
{
    MVBI_EDGE_DEFECT_TYPE_NONE = 0, // ��ȱ��
    MVBI_EDGE_DEFECT_TYPE_FLAW = 1, // ȱ��
    MVBI_EDGE_DEFECT_TYPE_GAP  = 2, // ����
}MVBI_EDGE_DEFECT_TYPE;

// ��Եȱ����Ϣ
typedef struct _MVBI_EDGE_DEFECT_INFO
{
    MVBI_BOX_F defect_box;    // ȱ�ݰ�Χ��
    HKA_F32    defect_size;   // ȱ��/�������
    HKA_F32    defect_area;   // ȱ��/������
    HKA_S32    caliper_start; // ȱ�ݿ�����ʼ����
    HKA_S32    caliper_end;   // ȱ�ݿ�����ֹ����
    HKA_S32    defect_type;   // ȱ������
}MVBI_EDGE_DEFECT_INFO;

// ������Ϣ
typedef struct _MVB_DEBUG_INFO
{
    HKA_VOID  *debug_data;    // debug���
    HKA_S32    debug_size;    // ��Ϣ��С
    HKA_S32    debug_enable;  // debugʹ��
    HKA_S32    debug_index;   // debug������
    HKA_S32    pos_index;     // λ������
    HKA_S32    status;        // ״̬    
}MVB_DEBUG_INFO;

/***************************************************************************************************
* ͼ��ṹ�嶨��
***************************************************************************************************/
//ͼ���ʽ���µ��������������棬����ǰ����ݣ�ÿ�ָ�ʽ���γ���100���֣�
typedef enum _MVB_IMAGE_FORMAT
{
	//δ֪�ģ�δ�������ݸ�ʽ���û����Ը���Ӧ��������ⶨ���ʽ����
	MVB_IMG_UNKNOWN = 0,

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
	MVB_IMG_MONO_08 = 1,    //| 8b   | U08  |        D0           |         S0          |
	//mono12                            //----------------------------------------------------------
	MVB_IMG_MONO_12 = 2,    //| 12b  | U16  |        D0           |         S0          |
	//mono16                            //----------------------------------------------------------
	MVB_IMG_MONO_16 = 3,    //| 16b  | U16  |        D0           |         S0          |
	//mono float 16bit                  //----------------------------------------------------------
	MVB_IMG_MONO_F16 = 4,    //| 16b  | F16  |        D0           |         S0          |
	//mono float 32bit                  //----------------------------------------------------------
	MVB_IMG_MONO_F32 = 5,    //| 32b  | F32  |        D0           |         S0          |
    //mono float 64bit                  //----------------------------------------------------------
    MVB_IMG_MONO_F64 = 6,    //| 64b  | F64  |        D0           |         S0          |
    //mono float 32bit                  //----------------------------------------------------------
    MVB_IMG_MONO_FC32 = 7,    //| 32b  | FC32  |        D0           |         S0          |
    //mono float 64bit                  //----------------------------------------------------------
    MVB_IMG_MONO_FC64 = 8,    //| 64b  | F64  |        D0           |         S0          |
    //mono10                            //----------------------------------------------------------
    MVB_IMG_MONO_10 = 9,      //| 14b  | U16  |        D0           |         S0          |
	//mono14                            //----------------------------------------------------------
	MVB_IMG_MONO_14 = 10,      //| 14b  | U16  |        D0           |         S0          |
    //----------------------------------//----------------------------------------------------------
	//YUV (100~199)                     //| bit  | type |   store position    |        step         |
	//YUV420 Sx(U,V) = 2 Sy(U,V) = 2    //----------------------------------------------------------
	//I420 planar
	MVB_IMG_YUV_I420 = 100,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
	//YUV420                            //----------------------------------------------------------
	//YV12 planar
	MVB_IMG_YUV_YV12 = 101,  //| 8b   | U08  |    Y:D0,V:D1,U:D2   |  Y:S0,V:S1,U:S2     |
	//YUV420                            //----------------------------------------------------------
	//NV12 UV packed
	MVB_IMG_YUV_NV12 = 102,  //| 8b   | U08  |    Y:D0,UV:D1       |  Y:S0,UV:S1         |
	//YUV422 Sx(U,V) = 1 Sy(U,V) = 2    //----------------------------------------------------------
	//planar
	MVB_IMG_YUV_422 = 103,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
	//YUV422                            //----------------------------------------------------------
	//UYVY packed
	MVB_IMG_YUV_UYVY = 104,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
	//YUV444  Sx(U,V) = 1 Sy(U,V) = 1   //----------------------------------------------------------
	//planar
	MVB_IMG_YUV_444 = 105,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
	//YUV422                            //----------------------------------------------------------
	//YUYV (YUY2) packed
	MVB_IMG_YUV_YUYV = 106,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
	//YUV422                            //----------------------------------------------------------
	//YVYU packed
	MVB_IMG_YUV_YVYU = 107,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
	//YUV422                            //----------------------------------------------------------
	//VYUY
	MVB_IMG_YUV_VYUY = 108,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
	//YUV420                            //----------------------------------------------------------
	//NV21 VU packed
	MVB_IMG_YUV_NV21 = 109,  //| 8b   | U08  |    Y:D0,VU:D1       |  Y:S0,VU:S1         |
	//YUV411 Sx(U,V) = 4 Sy(U,V) = 1    //----------------------------------------------------------
	//planar
	MVB_IMG_YUV_YUV411 = 130,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
	//YUV411                            //----------------------------------------------------------
	//Y411 (Y41P) packed: U0 Y0 V0 Y1 U4 Y2 V4 Y3 Y4 Y5 Y6 Y8 
	MVB_IMG_YUV_Y41P = 131,  //| 8b   | U08  |    YUV:D0           |  YUV:S0             |
	//YVU9 Sx(U,V) = 4 Sy(U,V) = 4      //----------------------------------------------------------
	//planar
	MVB_IMG_YUV_YVU9 = 140,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
	//AYUV                              //----------------------------------------------------------
	//planar
	MVB_IMG_YUV_AYUV = 150,  //| 8b   | U08  | A:D0,Y:D1,U:D2,V:D3 | A:S0,Y:S1,U:S2,V:S3 |
	//YUV440  Sx(U,V) = 1 Sy(U,V) = 2   //----------------------------------------------------------
	//planar
	MVB_IMG_YUV_440 = 180,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
	//YUV424  Sx(U) = 2 Sy(V) = 2       //----------------------------------------------------------
	//planar
	MVB_IMG_YUV_424 = 181,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
	//YUV442  Sy(U) = 2 Sx(V) = 2       //----------------------------------------------------------
	//planar
	MVB_IMG_YUV_442 = 182,  //| 8b   | U08  |    Y:D0,U:D1,V:D2   |  Y:S0,U:S1,V:S2     |
	//----------------------------------//----------------------------------------------------------
	//RGB (200~299)                     //| bit  | type |   store position    |        step         |
	//RBG 3 plane                       //----------------------------------------------------------
	MVB_IMG_RGB_RGB24_P3 = 200,  //| 8b   | U08  |    R:D0,G:D1,B:D2   |  R:S0,G:S1,B:S2     |
	//RGB 3 RGBRGB...                   //----------------------------------------------------------
	MVB_IMG_RGB_RGB24_C3 = 201,  //| 8b   | U08  |    RGB:D0           |  RGB:S0             |
	//RGB 4 plane(alpha)                //----------------------------------------------------------
	MVB_IMG_RGB_RGBA_P4 = 202,  //| 8b   | U08  | R:D0,G:D1,B:D2,A:D3 | R:S0,G:S1,B:S2,A:S3 |
	//RGB 4 RGBARGBA...(alpha)          //----------------------------------------------------------
	MVB_IMG_RGB_RGBA_C4 = 203,  //| 8b   | U08  |    RGBA:D0          |  RGBA:S0            |
	//RGB 4 plane(depth)                //----------------------------------------------------------
	MVB_IMG_RGB_RGBD_P4 = 204,  //| 8b   | U08  | R:D0,G:D1,B:D2,A:D3 | R:S0,G:S1,B:S2,A:S3 |
	//RGB 4 RGBDRGBD...(depth)          //----------------------------------------------------------
	MVB_IMG_RGB_RGBD_C4 = 205,  //| 8b   | U08  |    RGBA:D0          |  RGBA:S0            |
	//RBG 3 plane                       //----------------------------------------------------------
	MVB_IMG_RGB_RGB48_P3 = 206,  //| 16b   | U16  |    R:D0,G:D1,B:D2   |  R:S0,G:S1,B:S2     |
	//RGB 3 RGBRGB...                   //----------------------------------------------------------
	MVB_IMG_RGB_RGB48_C3 = 207,  //| 16b   | U16  |    RGB:D0           |  RGB:S0             |
	//RGB 4 plane(alpha)                //----------------------------------------------------------
	MVB_IMG_RGB_RGBA48_P4 = 208,  //| 16b   | U16  | R:D0,G:D1,B:D2,A:D3 | R:S0,G:S1,B:S2,A:S3 |
	//RGB 4 RGBARGBA...(alpha)          //----------------------------------------------------------
	MVB_IMG_RGB_RGBA48_C4 = 209,  //| 16b   | U16  |    RGBA:D0          |  RGBA:S0            |
	MVB_IMG_RGB_BGR24_P3  = 210,  //| 8b   | U08  |    B:D0,G:D1,R:D2   |  B:S0,G:S1,R:S2     |
	//RGB 3 RGBRGB...                   //----------------------------------------------------------
	MVB_IMG_RGB_BGR24_C3 = 211,  //| 8b   | U08  |    BGR:D0           |  BGR:S0             |
	//RGB 4 plane(alpha)                //----------------------------------------------------------
	MVB_IMG_RGB_BGRA_P4 = 212,  //| 8b   | U08  | B:D0,G:D1,R:D2,A:D3 | B:S0,G:S1,R:S2,A:S3 |
	//RGB 4 RGBARGBA...(alpha)          //----------------------------------------------------------
	MVB_IMG_RGB_BGRA_C4 = 213,  //| 8b   | U08  |    BGRA:D0          |  BGRA:S0            |
	//RGB 4 plane(depth)                //----------------------------------------------------------
	MVB_IMG_RGB_BGRD_P4 = 214,  //| 8b   | U08  | B:D0,G:D1,R:D2,D:D3 | B:S0,G:S1,R:S2,D:S3 |
	//RGB 4 RGBDRGBD...(depth)          //----------------------------------------------------------
	MVB_IMG_RGB_BGRD_C4 = 215,  //| 8b   | U08  |    BGRD:D0          |  BGRD:S0            |
	//RBG 3 plane                       //----------------------------------------------------------
	MVB_IMG_RGB_BGR48_P3 = 216,  //| 16b   | U16  |    B:D0,G:D1,R:D2   |  B:S0,G:S1,R:S2     |
	//RGB 3 RGBRGB...                   //----------------------------------------------------------
	MVB_IMG_RGB_BGR48_C3 = 217,  //| 16b   | U16  |    BGR:D0           |  BGR:S0             |
	//RGB 4 plane(alpha)                //----------------------------------------------------------
	MVB_IMG_RGB_BGRA48_P4 = 218,  //| 16b   | U16  | B:D0,G:D1,R:D2,A:D3 | B:S0,G:S1,R:S2,A:S3 |
	//RGB 4 RGBARGBA...(alpha)          //----------------------------------------------------------
	MVB_IMG_RGB_BGRA48_C4 = 219,  //| 16b   | U16  |    BGRA:D0          |  BGRA:S0            |
	//----------------------------------//----------------------------------------------------------
	//bayer (300~399)                   //| bit  | type |   store position    |        step         |
	//bayer GRGB 10bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_GRBG_10 = 300,  //| 10b  | U16  |    GRBG:D0          |  GRBG:S0            |
	//bayer RGGB 10bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_RGGB_10 = 301,  //| 10b  | U16  |    RGGB:D0          |  RGGB:S0            |
	//bayer RGGB 10bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_BGGR_10 = 302,  //| 10b  | U16  |    BGGR:D0          |  BGGR:S0            |
	//bayer RGGB 10bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_GBRG_10 = 303,  //| 10b  | U16  |    GBRG:D0          |  GBRG:S0            |
	//bayer RGGB 12bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_GRBG_12 = 304,  //| 12b  | U16  |    GRBG:D0          |  GRBG:S0            |
	//bayer RGGB 12bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_RGGB_12 = 305,  //| 12b  | U16  |    RGGB:D0          |  RGGB:S0            |
	//bayer RGGB 12bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_BGGR_12 = 306,  //| 12b  | U16  |    BGGR:D0          |  BGGR:S0            |
	//bayer RGGB 12bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_GBRG_12 = 307,  //| 12b  | U16  |    GBRG:D0          |  GBRG:S0            |
	//bayer RGGB 8bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_GRBG_8  = 308,  //| 8b  | U8  |    GRBG:D0          |  GRBG:S0            |
	//bayer RGGB 8bit                 //----------------------------------------------------------
	MVB_IMG_BAYER_RGGB_8  = 309,  //| 8b  | U8  |    RGGB:D0          |  RGGB:S0            |
	//bayer RGGB 8bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_BGGR_8  = 310,  //| 8b  | U8  |    BGGR:D0          |  BGGR:S0            |
	//bayer RGGB 8bit                  //----------------------------------------------------------
	MVB_IMG_BAYER_GBRG_8  = 311,  //| 8b  | U8  |    GBRG:D0          |  GBRG:S0            |
    //bayer RGGB 16bit                  //----------------------------------------------------------
    MVB_IMG_BAYER_GRBG_16 = 312,  //| 16b  | U16  |    GRBG:D0          |  GRBG:S0            |
    //bayer RGGB 16bit                 //----------------------------------------------------------
    MVB_IMG_BAYER_RGGB_16  = 313,  //| 16b  | U16  |    RGGB:D0          |  RGGB:S0            |
    //bayer RGGB 16bit                  //----------------------------------------------------------
    MVB_IMG_BAYER_BGGR_16  = 314,  //| 16b  | U16  |    BGGR:D0          |  BGGR:S0            |
    //bayer RGGB 16bit                  //----------------------------------------------------------
    MVB_IMG_BAYER_GBRG_16  = 315,  //| 16b  | U16  |    GBRG:D0          |  GBRG:S0            |
    //bayer RGGB 14bit                  //----------------------------------------------------------
    MVB_IMG_BAYER_GRBG_14  = 316,  //| 16b  | U16  |    GRBG:D0          |  GRBG:S0            |
    //bayer RGGB 14bit                 //----------------------------------------------------------
    MVB_IMG_BAYER_RGGB_14  = 317,  //| 16b  | U16  |    RGGB:D0          |  RGGB:S0            |
    //bayer RGGB 14bit                  //----------------------------------------------------------
    MVB_IMG_BAYER_BGGR_14  = 318,  //| 16b  | U16  |    BGGR:D0          |  BGGR:S0            |
    //bayer RGGB 14bit                  //----------------------------------------------------------
    MVB_IMG_BAYER_GBRG_14  = 319,  //| 16b  | U16  |    GBRG:D0          |  GBRG:S0            |
	//----------------------------------//----------------------------------------------------------
	//YCbCr (400~499)                   //| bit  | type |   store position    |        step         |
	//YCCK Sx(U,V) = 1 Sy(U,V) = 1      //----------------------------------------------------------
	//planar                            //----------------------------------------------------------
	MVB_IMG_YCCK_P4 = 400,  //| 8b   | U08  |Y:D0,Cb:D1,Cr:D2,K:D3|Y:S0,Cb:S1,Cr:S2,K:S3|
	//packed  C0 M0 Y0 K0 C1 M1 Y1 K1   //----------------------------------------------------------
	MVB_IMG_YCCK_C4 = 401,  //| 8b   | U08  |    YCCK:D0          |  YCCK:S0            |
	//----------------------------------//----------------------------------------------------------
	//CMYK (500~519)                    //| bit  | type |   store position    |        step         |
	//planar                            //----------------------------------------------------------
	MVB_IMG_CMYK_P4 = 500,  //| 8b   | U08  | C:D0,M:D1,Y:D2,K:D3 | C:S0,M:S1,Y:S2,K:S3 |
	//packed  C0 M0 Y0 K0 C1 M1 Y1 K1   //----------------------------------------------------------
	MVB_IMG_CMYK_C4 = 501   //| 8b   | U08  |    CMYK:D0          |  CMYK:S0            |
	//----------------------------------//----------------------------------------------------------
}MVB_IMAGE_FORMAT;

// �㷨������ͼ��ṹ��
typedef struct _MVB_IMAGE
{
	MVB_IMAGE_FORMAT    format;              // ͼ���ʽ��������������HKA_IMAGE_FORMAT��ֵ
	HKA_S32             width;               // ͼ����
	HKA_S32             height;              // ͼ��߶�
	HKA_S32             step[4];             // �м��
	HKA_VOID           *vir_base[4];         // ���ݴ洢�����ַ
	HKA_VOID           *phy_base[4];         // ���ݴ洢�����ַ

} MVB_IMAGE;

//�������ò������ͣ�cfg_type����MVBXXX_SetConfig����ʹ��
typedef enum _MVB_SET_CFG_TYPE
{
    MVB_SET_CFG_SINGLE_PARAM    = 0x0001,    //��������
    MVB_SET_CFG_PARAM_LIST      = 0x0002,    //�����б�
    MVB_SET_CFG_DEFAULT_PARAM   = 0x0003,    //Ĭ�ϲ���
    MVB_SET_CFG_RESTART_LIB     = 0x0004,    //�����㷨��
    MVB_SET_CFG_CALLBACK        = 0x0005,    //�ص�����
    MVB_SET_CFG_CHECK_PARAM     = 0x0006,    //�����������
    MVB_SET_CFG_CPU_COREID_MASK = 0x0007,    // ���߳�ʹ�ú���Դ����Ĥ
    MVB_SET_CFG_MEM_FUNC_PT     = 0x0008,    // �ڴ�������ͷź���ָ��
}MVB_SET_CFG_TYPE;

//��ȡ���ò������ͣ�cfg_type����MVBXXX_GetConfig����ʹ��
typedef enum _MVB_GET_CFG_TYPE
{
    MVB_GET_CFG_SINGLE_PARAM    = 0x0001,    //��������
    MVB_GET_CFG_PARAM_LIST      = 0x0002,    //����������
    MVB_GET_CFG_VERSION         = 0x0003,    //�汾��Ϣ
    MVB_GET_CFG_ABILITY         = 0x0004,    //�㷨��������
    MVB_GET_CFG_CPU_COREID_MASK = 0x0005,    //���߳�ʹ�ú���Դ����Ĥ
	MVB_GET_CFG_MEM_FUNC_PT     = 0x0006,    // �ڴ�������ͷź���ָ��
}MVB_GET_CFG_TYPE;

// ���̺߳���Ϣ
typedef struct _MVB_CPU_CORE_INFO
{
	HKA_U64 coreid_mask; // ��id��Ĥ,bit[0]��ʾCPU0��bit[1]��ʾCPU1���Դ�����
	HKA_U32 reserved[8]; // reserved
}MVB_CPU_CORE_INFO;

// AES������غ�
#define MVB_AES_SOFT_FEATURE_LEN  (16)  // AES���������Ϣ����
#define MVB_AES_HARD_FEATURE_LEN  (16)  // AESӲ��������Ϣ����
#define MVB_AES_ENC_STR_LEN       (MVB_AES_SOFT_FEATURE_LEN + MVB_AES_HARD_FEATURE_LEN)  // AES��Ϣ����

#if defined(_WIN64) || defined(__x86_64__) || defined(__amd64__) || defined(__aarch64__)
typedef HKA_U64      MVB_SZT;
#else
typedef HKA_U32      MVB_SZT;
#endif

#ifdef __cplusplus        
}
#endif
#endif // MVB_TYPES_H_