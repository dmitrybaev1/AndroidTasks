/******* QDMWINA.CPP *********** Dishlenko S.G.  ****** 05/06/15 ***
 ******* QDMWINA.CPP *********** ���������� �.   ****** 15/09/14 ***
 ******* QDMWINA.CPP *********** Savelov A.S.    ****** 07/05/15 ***
 ******* QDMWINA.CPP *********** Korjilov A.     ****** 20/11/14 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2017              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR GIS DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*              ��������� ������� ��������� ������                  *
*              ��������� ����������� ����������                    *
*                                                                  *
*******************************************************************/

#ifndef VISFUNCS_H
#define VISFUNCS_H

typedef struct DRAWFUNCPARM
{
    DRAWFUNCPARM()
    {
        memset(this, 0, sizeof(*this));
        Alpha = 0xff;
        MarkColor = -1;
    }

    unsigned char * Begin;  // ��������� �� ������ ������� DIB

    int Width;              // ������ ������� DIB (� ��������)
    int Height;             // ������ ������� DIB (� ��������)

    int DrawWidth;          // ������ ������� ���������
    int DrawHeight;         // ������ ������� ���������

    int DrawPointX;         // ������������ ������������ ������� � ����
    int DrawPointY;         // (����� ������� ����)

    float Dx, Dy;           // �������� � �������
    float Angle;            // ������� ���������

    int Color;              // ���� ��������� (����, �����, �������)
    int Alpha;              // �����-����� (� ������� �����)

    int MarkColor;          // ���� ���� (�������������)
                            // (-1 - �� ������)
    int MarkType;           // ��� ���������
                            // (0 - ����, 1,2 - ������ � ������� ������ ���������)
    int MarkThick;          // �������� ���� ��� ������� ������� ���������

    HWIDGET hWidget;        // ������ ���������
}
DRAWFUNCPARM;

// �������� �����
typedef void (*DRAWFUNC_SOLIDLINE)(DRAWFUNCPARM& dfp, const POLYDATAEX *data, float thick);

// ��������� �����
typedef void (*DRAWFUNC_DASHLINE)(DRAWFUNCPARM& dfp, const POLYDATAEX *data, float thick, float dash, float space);

// ��������� ������
typedef void (*DRAWFUNC_POLYGON)(DRAWFUNCPARM& dfp, const POLYDATAEX *data);

// ��������� ������ ������
typedef int (*DRAWFUNC_TEXTWIDTH)(DRAWFUNCPARM& dfp, const WCHAR *text,
                                  float height, int italic, int weight, int wide, const char *fontName);

// �������
typedef void (*DRAWFUNC_TEXT)(DRAWFUNCPARM& dfp, const WCHAR *text,
                              float height, int italic, int weight, int wide, const char *fontName);

// ������
typedef void (*DRAWFUNC_ELLIPSE)(DRAWFUNCPARM& dfp, int x, int y, int width, int height,
                                 float thick, float dash, float space,
                                 int imagetype);

// ����
typedef void (*DRAWFUNC_ARC)(DRAWFUNCPARM& dfp, int x, int y, int width, int height,
                             int startAngle, int spanAngle,
                             float thick, float dash, float space,
                             int imagetype);

// ������
typedef void (*DRAWFUNC_PIE)(DRAWFUNCPARM& dfp, int x, int y, int width, int height,
                             int startAngle, int spanAngle);

// ���������� ����������� � ����
typedef void (*DRAWFUNC_SAVEIMAGE)(const char *filename, const char *image, int w, int h);

// ���������� ����������� ������������ ��������� ������ ��������������  � ����
typedef void (*DRAWFUNC_SAVEFILLRECTANGLE)(const char *filename, int w, int h, COLORREF color);

// ������ ���������� ������ ��� ����������� ������� ����������� ��������
typedef int (*DRAWFUNC_FONTMETRICS)(const char *fontName, int height, int italic,
                                    unsigned long* ascent, unsigned long* descent, unsigned long* resultHeight);

// ��������� � ������ ��������
typedef void (*DRAWFUNC_PICTURE)(DRAWFUNCPARM& dfp, IMGPICTURE *imgpict, const char *fileaddr, int picturesize);

extern "C"
{
// ���������� ������ ���������      // 14/11/14
_MAPIMP void _MAPAPI mapSetHWidget(HMAP hMap, HWIDGET hwidget);

// ���������� ������� ���������:
// �������� �����
_MAPIMP void _MAPAPI mapDrawSolidLine(DRAWFUNC_SOLIDLINE func);

// ��������� �����
_MAPIMP void _MAPAPI mapDrawDashLine(DRAWFUNC_DASHLINE func);

// ��������� ������
_MAPIMP void _MAPAPI mapDrawPolygon(DRAWFUNC_POLYGON func);

// �������
_MAPIMP void _MAPAPI mapDrawText(DRAWFUNC_TEXT func);

// 28/10/14 �������
// ������
_MAPIMP void _MAPAPI mapDrawEllipse(DRAWFUNC_ELLIPSE func);

// ����
_MAPIMP void _MAPAPI mapDrawArc(DRAWFUNC_ARC func);

// ������
_MAPIMP void _MAPAPI mapDrawPie(DRAWFUNC_PIE func);

// ��������� ������            // 05/04/16
_MAPIMP void _MAPAPI mapDrawFontMetrics(DRAWFUNC_FONTMETRICS call);

// ��������                    // 27/06/16
_MAPIMP void _MAPAPI mapDrawPicture(DRAWFUNC_PICTURE call);
}

#endif // VISFUNCS_H
