/***************************************************************************************************
* File:  MVD_ShapeParamDefine.h
* Note:  Parameter and data struct definition of shape module in namespace VisionDesigner.
*
* Version:  V3.1.0.0
****************************************************************************************************/

#ifndef _MVD_SHAPE_PARAM_DEFINE_H__
#define _MVD_SHAPE_PARAM_DEFINE_H__

namespace VisionDesigner
{
    #define MVD_TEXT_CONTENT_MAX_LEN 4096 //�ı�ͼ����������󳤶�
    #define MVD_TEXT_FONT_FACE_SIZE 32   //�ı�ͼ�������������ַ�����󳤶�

    /** @struct MVD_SHAPE_TYPE
     *  @brief  Shape type designed in this module.
     */
    typedef enum _MVD_SHAPE_TYPE_
    {
        MvdShapeUndefined      = 0,
        MvdShapeStraightLine,
        MvdShapeLineSegment,
        MvdShapeRadialLine,
        MvdShapeTriangle,
        MvdShapeRectangle,
        MvdShapeCircle,
        MvdShapeEllipse,
        MvdShapePointSet,
        MvdShapeText,
        MvdShapeAnnularSector,
        MvdShapePolygon,
        MvdShapeParallelogram,
        MvdShapePolylineSegment,
    }MVD_SHAPE_TYPE;

    /** @struct MVD_DASH_STYLE
     *  @brief  Specifies the style of dashed lines drawn with a System.Drawing.Pen object.
     */
    // Summary:
    typedef enum _MVD_DASH_STYLE_
    {
        MvdDashSolid = 0,         //     Specifies a solid line.
        MvdDashDash = 1,          //     Specifies a line consisting of dashes.
        MvdDashDot = 2,           //     Specifies a line consisting of dots.
        MvdDashDashDot = 3,       //     Specifies a line consisting of a repeating pattern of dash-dot.
        MvdDashDashDotDot = 4,    //     Specifies a line consisting of a repeating pattern of dash-dot-dot.
    }MVD_DASH_STYLE;

    /** @struct MVD_COLOR
     *  @brief  color
     */
    typedef struct _MVD_COLOR_
    {
        unsigned char       nR;
        unsigned char       nG;
        unsigned char       nB;
        unsigned char       nAlpha;
    }MVD_COLOR;

    /** @struct MVD_POINT_S
     *  @brief  a point - signed short type
     */
    typedef struct _MVD_POINT_S
    {
        signed short    sX;
        signed short    sY;
    }MVD_POINT_S;

    /** @struct MVD_POINT_I
     *  @brief  a point - signed int type
     */
    typedef struct MVD_POINT_I__
    {
        signed int    nX;
        signed int    nY;
    } MVD_POINT_I;

    /** @struct MVD_POINT_F
     *  @brief  a point - float type
     */
    typedef struct MVD_POINT_F__
    {
        float    fX;
        float    fY;
    } MVD_POINT_F;

    /** @struct MVD_POINT_DF
     *  @brief  a point - double type
     */
    typedef struct MVD_POINT_DF__
    {
        double    dfX;
        double    dfY;
    } MVD_POINT_DF;

    /** @struct MVD_SIZE_I
     *  @brief  size description - signed int type
     */
    typedef struct MVD_SIZE_I__
    {
        signed int nWidth;
        signed int nHeight;
    } MVD_SIZE_I;

    /** @struct MVD_SIZE_F
     *  @brief  size description - float type
     */
    typedef struct MVD_SIZE_F__
    {
        float fWidth;
        float fHeight;
    }MVD_SIZE_F;
    /** @struct MVD_RECT_I
    *  @brief  rectangle description - signed int type
    */
    typedef struct _MVD_RECT_I_
    {
        int nX;         //the left top x of the rectangle
        int nY;         //the left top y of the rectangle
        int nWidth;     //the width of the rectangle
        int nHeight;    //the height of the rectangle
    }MVD_RECT_I;
    /** @struct MVD_RECT_F
    *  @brief  rectangle description - float type
    */
    typedef struct _MVD_RECT_F_
    {
        float fX;       //the left top x of the rectangle
        float fY;       //the left top y of the rectangle
        float fWidth;   //the width of the rectangle
        float fHeight;  //the height of the rectangle
    }MVD_RECT_F;

    /*
    *  @struct   MVD_TEXT_POSITION_TYPE
    *  @brief    �ı�ͼ��λ������
    */
    typedef enum _MVD_TEXT_POSITION_TYPE_
    {
        MVD_TP_UNDEFINED=0,        ///< δ�����ı�ͼ��λ������
        MVD_TP_TOPLEFT=1,          ///< ���Ͻ�
        MVD_TP_TOPMIDDLE=2,        ///< ����
        MVD_TP_TOPRIGHT=3,         ///< ���Ͻ�
        MVD_TP_MIDDLELEFT=4,       ///< ����
        MVD_TP_CENTER=5,           ///< ����
        MVD_TP_MIDDLERIGHT=6,      ///< ����
        MVD_TP_BOTTOMLEFT=7,       ///< ���½�
        MVD_TP_BOTTOMMIDDLE=8,     ///< ����
        MVD_TP_BOTTOMRIGHT=9,      ///< ���½�
    }MVD_TEXT_POSITION_TYPE;


    /*
    *  @struct   MVD_TEXT_POSITION
    *  @brief    �ı�ͼ��λ�ã�ʾ����fX=100,fY=100,enType=MVD_TP_TOPRIGHT,�����ı����Ͻǵ�����Ϊ(100,100)
    */
    typedef struct _MVD_TEXT_POSITION_
    {
        float fX;                           ///< ����X
        float fY;                           ///< ����Y
        MVD_TEXT_POSITION_TYPE enType;      ///< �ı�ͼ��λ������
    }MVD_TEXT_POSITION;

}

#endif // _MVD_SHAPE_PARAM_DEFINE_H__
