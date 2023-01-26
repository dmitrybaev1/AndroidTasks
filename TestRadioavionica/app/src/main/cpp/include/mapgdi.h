/****** MAPGDI.H *************** Kruzhkov A.E.   ****** 27/05/16 ***
******* MAPGDI.H *************** Belenkov O.V.   ****** 28/05/15 ***
******* MAPGDI.H *************** Panteleeva N.A. ****** 26/05/16 ***
******* MAPGDI.H *************** Kruzhkova E.A.  ****** 19/03/08 ***
******* MAPGDI.H *************** Dishlenko S.G.  ****** 26/03/12 ***
******* MAPGDI.H *************** Derevyagina Zh.A.***** 12/01/16 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2016              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*      �������� ���������� ������� ������������ ������������       *
*             ����������� ��'����� ����������� �����               *
*                                                                  *
*******************************************************************/

#ifndef MAPGDI_H
#define MAPGDI_H

#ifndef MAPTYPE_H
 #include "maptype.h"
#endif

#pragma pack(push,1)

// ����� ���������������� ������� (������������ ��� Image ������ IMG_OBJECT)

#define IM_PRESS       0x00000000  // ������� ��� ���������� ����� (�� ���������)
#define IM_DONTPRESS   0x04000000  // �� ������� ��� ����������

#define IM_SCALE       0x01000000  // ��������������
#define IM_DONTSCALE   0x02000000  // �� ��������������

#define IM_SCALEDONTPRESS  (IM_SCALE | IM_DONTPRESS)  // ������ �����������

#define IM_CLEARSCALE 0x0F8FFFFFF  // ������ ����� ���������������

//-----------------------------------------------------------------
// �������� ������� ����������� ������������ ��'����
//-----------------------------------------------------------------

#if defined(_M_X64) || defined(BUILD_DLL64)       // 28/07/09

typedef struct PAINTPARM
{
  int Image;       // ��� ������� �����������
  int Mode ;       // ������� ����������� � ���������������
                   //   R2_COPYPEN   - ����������� ������
                   //   R2_NOT       - ����������� ��������� ���� (���� ������������)
                   //   IM_SCALE, IM_DONTSCALE, ... - �������� ����������������
                   //    (������������ ��� Image ������ IMG_OBJECT)
                   // ������ �������������: Mode = R2_NOT | IM_SCALE
  char *   Parm ;  // ��������� ����������� ��� ��������������� �������.
                   // ������������ ��� Image ������ IMG_OBJECT (���������
                   // � ����� ������� ��������������� �� ��������������)
}
  PAINTPARM;

#else

typedef struct PAINTPARM
{
  int Image;       // ��� ������� �����������
  char *   Parm ;  // ��������� ����������� ��� ��������������� �������.
                   // ������������ ��� Image ������ IMG_OBJECT (���������
                   // � ����� ������� ��������������� �� ��������������)
  int Mode ;       // ������� ����������� � ���������������
                   //   R2_COPYPEN   - ����������� ������
                   //   R2_NOT       - ����������� ��������� ���� (���� ������������)
                   //   IM_SCALE, IM_DONTSCALE, ... - �������� ����������������
                   //    (������������ ��� Image ������ IMG_OBJECT)
                   // ������ �������������: Mode = R2_NOT | IM_SCALE
}
  PAINTPARM;

#endif

//-----------------------------------------------------------------
// �������� ���������� ������
//-----------------------------------------------------------------
// �������� ����� ������ ����� ���� ������ ����� ������.
// ����������� ����� ������ - 5 ����: 4 ����� - ����� = 5 � 1 ���� = 0
// ���� � ������ ����������� '\n',
// �� ����������� ������� �� ��������� ������
//-----------------------------------------------------------------

typedef struct TEXTRECORD
{
  int  Length ;                  // ����� ������, ������� ���� Length
  char Text[256];                // �����, ��������������� �������� 0
}                                // ����� ������ � ��������� WINDOWS
  TEXTRECORD;


//-----------------------------------------------------------------
// �������� ��������� ������������ ��'����
//-----------------------------------------------------------------
// ������� ��������� � ��� ������� ���������
// �������� � ���������� ������� ������������
//-----------------------------------------------------------------

typedef struct PLACEDATA         // ���������� � ������������ �������
{
  DOUBLEPOINT * Points    ;      // ������ ��������� ��������� ��������
  int *         PolyCounts;      // ������ ���������� ����� ��������
  int           Count     ;      // ���������� �������� ��� �������� TEXTRECORD
                                 // ��� ������� ���� IMG_TEXT :
#if defined(_M_X64) || defined(BUILD_DLL64)       // 12/01/16
  int           Reserv    ;      // ������ ���� ����� 0
#endif
  TEXTRECORD *  PolyText  ;      // ������� ��������������� �������������
                                 // ������� ���� TEXTRECORD, ������� �������
                                 // ����� ���� �������, �� �� ������ 5 ����,
                                 // ����� �������� ����� Count !
}
  PLACEDATA;


//-----------------------------------------------------------------
// ��������� ����������� ������� ���� �������
//-----------------------------------------------------------------

typedef struct PAINTEXAMPLE
{
  HDC       Hdc;       // �������� ����������
  RECT*     Rect;      // ������� ����������� � ��������

  int       Func;      // ����� ������� (IMG_LINE, IMG_DOT, ...)
  char*     Parm;      // ��������� �� ��������� �������

  POLYDATAEX* Data;    // �������
                       //   (���� Data != 0, �� text ������������)
                       //   (���� Data == 0, �� ��������� �������������)

  char*     Text;      // ����� ������ � ��������� WINDOWS
                       //   (���� Text == 0, �� ��������� �������������)

  int       Local;     // ����������� (LOCAL_LINE, LOCAL_SQUARE, ...)
                       //   (������������ ��� Data == 0)

  float     Factor;    // ����������� ���������� (Factor >= 0.0)
                       //  0.0 - �������������� �������������

  int       Colors;    // ����� ������ �������
  COLORREF* Palette;   // ��������� �� �������

  int       VisualType;     // ��� ������������ (VT_SCREEN, VT_PRINT, ...)
                            //    0 - �������

  int       FillIntensity;  // ������������� ������� (0,100)
                            //    0 - �������
                            //  100 - � �������� ������
  char      Reserve[16];
}
  PAINTEXAMPLE;


//******************************************************************
// ���� ������� ������������ ������������ ����������� ��'����� �� ��
//******************************************************************

#define IMG_EMPTY             127  // ������ ������� - ��� ����������

#define IMG_LINE              128  // �����
#define IMG_DOT               129  // �������

#define IMG_SQUARE            135  // �������

#define IMG_CIRCLE            140  // ����������

#define IMG_TEXT              142  // �������

#define IMG_MULTIMARK         143  // ������������ �������� ����
#define IMG_MULTISQUAREMARK   144  // �������, ����������� ��������� �������

#define IMG_DRAW              147  // ����� ��������� ����������

#define IMG_DOTSHIFT          148  // ��������� �������

#define IMG_VECTOREX          149  // ��������� ����

#define IMG_TEMPLATE          150  // ������ (���������� ���)

#define IMG_TRUETYPE          151  // ���� TrueType

#define IMG_TRUETEXT          152  // �������

#define IMG_HATCHSQUARE       153  // �������������� �������

#define IMG_SQUAREGLASS       154  // �������-������

#define IMG_SQUAREVECTOR      155  // �������, ����������� ���������� �������
#define IMG_VECTOREXTURN      156  // ��������� ���� (���������)

#define IMG_DECORATE          157  // ����� � ����������� ���������� �������
#define IMG_DASH              158  // �������� �����
#define IMG_LINESHIFT         159  // ��������� �����
#define IMG_VECTORTEXT        160  // ������� � ��������� �����
#define IMG_VECTORNODE        161  // ��������� � ����� (IMGVECTOREX)
#define IMG_THICKENLINE       162  // ������������ �����
#define IMG_MIDDLETHICKENLINE 163  // ������������ ����� � �������� �� ������
#define IMG_GRAPHICMARK       165  // ���� �� ����� (���, Metafile )
#define IMG_HATCHSQUARESHIFT  166  // ����������� ��������� �� ��������� ��������� // 31/03/08
#define IMG_POLYGONGLASS      167  // �������-������ � ��������� ������������  // 19/01/09
#define IMG_LINEGLASS         168  // �����-������ � ��������� ������������    // 23/01/09
#define IMG_DOTGLASS          169  // ��������� �����-������ � ��������� ������������ // 15/02/09
#define IMG_MULTIMARKGLASS    170  // ��������-������ � ��������� ������������ // 14/02/09
#define IMG_PICTURE           171  // ����������� ���� (PNG) ��������� � ��������������

#define IMG_VECTORGRADIENT    199  // ��������� �������
#define IMG_VECTORMIX         200  // ��������� �������
#define IMG_DRAWMIX           201  // ��������� �������

#define IMG_DOCITEM           248  // ��������� IMGDOCITEM ��� �������� ����������
#define IMG_PERCENT           249  // ��������� ���� IMG_LONG
#define IMG_LIBRARY           250  // ���� IML

#define IMG_SEMANTIC          251  // ��������� ���� IMG_LONG
#define IMG_COLOR             252  // ��������� ���� IMG_LONG
#define IMG_DOUBLE            253  // ���� ���� DOUBLE
#define IMG_LONG              254  // ���� ���� LONG

#define IMG_OBJECT            255  // ����� ������� ���������������
                                   // �� ��������������

// ���������� ���� (��� IMG_SQUAREMARK, IMG_MULTISQUAREMARK,
//                      IMG_SQUARECROSS, IMG_FONT, IMG_SQUAREGLASSCOLOR)
#define IMGC_TRANSPARENT  0xFFFFFFFF
#define IMGC_NOMARK       0xFFFFFFFF   // �� �������� (��� IMG_OBJECT)

// ����� ��� ����������� ������� ����� (������|IMGC_INDEX, RGB)
#define IMGC_INDEX        0x0F0000000  // ���� ����� �� ������� �����
#define IMGC_CLEARINDEX   0x0FF000000  // ��� ������� ����� ����� (& IMGC_CLEARINDEX)
#define IMGC_CLEARCOLOR   0x000FFFFFF  // ���� ������� �����      (& IMGC_CLEARCOLOR)

// ���������� ������ �����
// color - ����� ����� � ������� RSC, ������� � 0 !!!
// ���� ���� IMGC_INDEX �� ����������, ���� � ������� RGB
#define SETCOLORINDEX(color)   (((int)(color))|IMGC_INDEX)

#define IMGC_SYSTEM       0x0F1000000L  // ���� ����� �� ��������� ������� (LINUX)  // 16/10/03
#define SETCOLORSYSTEM(color)  (((int)(color))|IMGC_SYSTEM)

// ���������� ������ ����� (����������: 0 - RGB, 1 - ������ �� �������)
#define TESTCOLORINDEX(color)  ((((int)(color))&IMGC_CLEARINDEX)==IMGC_INDEX)

// ���������� ������ ����� (����������: 0 - RGB, 1 - ������ �� ��������� �������)
#define TESTCOLORSYSTEM(color) ((((int)(color))&IMGC_CLEARINDEX)==IMGC_SYSTEM)  // 16/10/03

// ��� ����� ���������� 4x4 (16 ���) (��� IMG_SQUAREMARK, IMG_MULTISQUAREMARK)
//  1 - ����������� �������� �����
//  0 - �������������
// �������� ����� �����:
//  0000(0)  1111(F)  1010(A)  0101(5)
//  0000(0)  1111(F)  0101(5)  1010(A)
//  0000(0)  1111(F)  1010(A)  0101(5)
//  0000(0)  1111(F)  0101(5)  1010(A)
#define IMGK_REGULAR0     0x00000000L  // ���������� (��������� ���)
#define IMGK_REGULAR      0x0000FFFFL  // ���������� (��������� ���)
#define IMGK_ONECHESS     0x0000A5A5L  // ���������
#define IMGK_TWOCHESS     0x00005A5AL  // ��������� ���������

// ����������� ������� (��� IMG_OBJECT)
#define IMGL_LINE      0  // ��������
#define IMGL_SQUARE    1  // ���������
#define IMGL_POINT     2  // ��������
#define IMGL_TITLE     3  // �������
#define IMGL_VECTOR    4  // ���������
#define IMGL_MIXED     5  // ������� ������� (������)

// ��� ��p������ (��� IMG_SQUARECROSS)
#define SC_HORIZONTAL  1  // ��p������������ �������
#define SC_VERTICAL    2  // ��p���a������ �������
#define SC_QUADRATIC   3  // �����a��
#define SC_CROSS45     4  // ��� ����� 45 ��������
#define SC_CROSS135    5  // ��� ����� 135 ��������

// ���� ��������� ������� (��� SCR_VECTOR)
#define VT_THICK2      2  // ����� ������� 2
#define VT_THICK3      3  // ����� ������� 3
#define VT_THICK4      4  // ����� ������� 4
#define VT_THICK5      5  // ����� ������� 5
#define VT_CIRCLE2     8  // ���������� ������� 2
#define VT_CIRCLE3     9  // ���������� ������� 3
#define VT_CIRCLE4    10  // ���������� ������� 4
#define VT_CIRCLE5    11  // ���������� ������� 5

// ���� ��������� ������� (IMG_VECTOREX)
#define VT_SQUARE      0  // �������
#define VT_LINE        1  // �����
#define VT_ROUND       6  // ���� (�������)
#define VT_CIRCLE      7  // ����������
#define VT_FREE       12  // ������� �� ����������

// ���� ��������� ������� (IMG_VECTOREX)
#define VT_ELLIPSE    64  // ������
#define VT_OVAL       65  // ������ (�������)
#define VT_ARC        66  // ������� ���� ����
#define VT_PIE        67  // ������ (�������)
#define VT_TEXT       68  // ������� ���� ����� (����������)
#define VT_STEXT      69  // ������� ���� ����� (�� ���������)
#define VT_ARC_REVERT 70  // ������� ���� ����

// ���� ��������� ������� ��� �������� ��������� �����
#define VT_OBJECT    101  // ������ �����
#define VT_SUBJECT   102  // ������ ����������
#define VT_END       103  // ����� �����

// �������� ��������� �������� � ������� � �������
#define MKMINPIX     250  //  1000 * 25.4 / 96 = 264.583333
#define PIX2MKM(pixel)  (((int)(pixel))  * MKMINPIX)
#define MKM2PIX(metric) (((int)(metric)) / MKMINPIX)

//------------------------------------------------------------------
// ��� IMG_FONT
//------------------------------------------------------------------

// ���������� ���� (���� ��� ����)
#define UNIC_TRANSPARENT  255

// ������������� ������ �������
#define UNIW_NORMAL       0  // ����������
#define UNIW_NARROW       1  // �������
#define UNIW_WIDE         2  // �������

// ������������ �� ���������
#define UNIA_BASELINE     0  // �� ������� �����
#define UNIA_TOP          1  // �� �����
#define UNIA_BOTTOM       2  // �� ����

// ������������ �� �����������
#define UNIA_LEFT         0  // �� ������ ����
#define UNIA_CENTER       1  // �� ������
#define UNIA_RIGHT        2  // �� ������� ����

// ���������� ���������� ������ ������� � ��������
#define CharMin  5  // ������� ������� < CharMin, �� ������������
                    // 5 - 25/10/99

// ������������� ������ ������� (mapgds.h)
//  UNIW_NORMAL     - ����������
//  UNIW_NARROW     - �������
//  UNIW_WIDE       - �������

#ifdef LINUXAPI  // 23/04/01
// ��� ������, ������� ������� (Windows-���������)
//  FW_THIN         - ������
//  FW_ULTRALIGTH   - ������
//  FW_NORMAL       - �������
//  FW_MEDIUM       - ����������
//  FW_BOLD         - �������
#define FW_DONTCARE         0
#define FW_THIN             100
#define FW_EXTRALIGHT       200
#define FW_LIGHT            300
#define FW_NORMAL           400
#define FW_MEDIUM           500
#define FW_SEMIBOLD         600
#define FW_BOLD             700
#define FW_EXTRABOLD        800
#define FW_HEAVY            900

#define FW_ULTRALIGHT       FW_EXTRALIGHT
#define FW_REGULAR          FW_NORMAL
#define FW_DEMIBOLD         FW_SEMIBOLD
#define FW_ULTRABOLD        FW_EXTRABOLD
#define FW_BLACK            FW_HEAVY

#endif // LINUXAPI


// ������������ �� ����������� (Windows-���������)
#define FA_LEFT      0     // ����� = TA_LEFT       // 14/09/00
#define FA_RIGHT     2     // ������ = TA_RIGHT     // 14/09/00
#define FA_CENTER    6     // �� ������ = TA_CENTER // 14/09/00

// ������������ �� ��������� (Windows-���������)
#define FA_TOP       0     // ������ = TA_TOP       // 14/09/00
#define FA_BOTTOM    8     // ����� = TA_BOTTOM     // 14/09/00
#define FA_BASELINE  24    // �� ������� ����� = TA_BASELINE  // 14/09/00
#define FA_MIDDLE    4120  // �� ������� ����� = (TA_BASELINE|0x01000) // 14/09/00

// ����� ������� ������������
#define FA_MASK     (FA_CENTER | FA_MIDDLE)         // 23/04/03


// ���� ������������ ������ (����������, � ������� �������)
#define CA_BASELINE_LEFT          20
#define CA_BASELINE_RIGHT         21
#define CA_BASELINE_CENTER        22

#define CA_MIDDLE_LEFT            23
#define CA_MIDDLE_RIGHT           24
#define CA_MIDDLE_CENTER          25

#define CA_TOP_LEFT               26
#define CA_TOP_RIGHT              27
#define CA_TOP_CENTER             28

#define CA_BOTTOM_LEFT            29
#define CA_BOTTOM_RIGHT           30
#define CA_BOTTOM_CENTER          31

// �������� ����� ������������ ������
#define CA_MINCODE  CA_BASELINE_LEFT
#define CA_MAXCODE  CA_BOTTOM_CENTER

// ������� �������� (Windows-���������)
//  RUSSIAN_CHARSET - ��� ������ (ANSI/WINDOWS)
//  OEM_CHARSET     - ��� ������ (OEM/866/DOS)
//------------------------------------------------------------------

//******************************************************************
//               ��������� ���������� ������������                 *
//******************************************************************
//      ��� ������� (�������, �����, ���������� ...) � ��������    *
//                 (� �������� ����� ����������)                   *
//******************************************************************
// ����������:                                                     *
//  1. ���� � ������� COLORREF (0x00BBGGRR) ��� ����� �������      *
//     ������� ����� � ������� �����, ���� ������� ���� ����� 0x0F *
//  2. ��� �������� �������� � ������ ������ (��������)            *
//     ������������ �������� PIX2MKM(����� ��������):              *
//     Parm->Thick = PIX2MKM(2);  (������� 2 �������)              *
//******************************************************************

typedef struct IMGLINE           // (128) �����
{                                //      (size = 8)
  unsigned int  Color;           // ���� ����� (COLORREF)
  unsigned int  Thick;           // ������� �����
}
  IMGLINE;

typedef struct IMGTHICKENLINE    // (162,163) ������������ �����
{                                //      (size = 12)
  unsigned int  Color;           // ���� ����� (COLORREF)
  unsigned int  Thick;           // ������� �����������
  unsigned int  Thick2;          // ������� ������������ (���������)
}
  IMGTHICKENLINE;

typedef struct IMGDOT            // (129) ���������� �����
{                                //      (size = 16)
  unsigned int  Color;           // ���� �����
  unsigned int  Thick;           // ������a ��p���
  unsigned int  Dash ;           // ����� ��p���
  unsigned int  Blank;           // ����� �p�����
}
  IMGDOT;

typedef struct IMGSQUARE         // (135) ��������� ��'���
{                                //      (size = 4)
  unsigned int  Color;           // ���� �������
}
  IMGSQUARE;

typedef struct IMGCIRCLE         // (140) ����������
{                                //      (size = 12)
  unsigned int  Color ;          // ���� ����������
  unsigned int  Thick ;          // ������� �����
  unsigned int  Radius;          // ������ ����������
}
  IMGCIRCLE;


typedef struct IMGTEXT           // (142) �����                   // 30/01/01
{                                //      (size = 32)
  unsigned int   Color       ;   // ���� ������
  unsigned int   BkgndColor  ;   // ���� ���� (IMGC_TRANSPARENT - ����������)
  unsigned int   ShadowColor ;   // ���� ���� (IMGC_TRANSPARENT - ����������)
  unsigned int   Height      ;   // ������ (��� ������������ �� �������
                                 // �� ��������� 1800 ���)
  unsigned short Weight      ;   // ��� ������, ������� ������� (FW_THIN, ...)
  unsigned char  Outline     ;   // ������� ������ ���� � ���� ������� // 17/07/07
                                 // 0 - �� ��������. 1 - ������ ������, 2 - �������
  unsigned char  Interval    ;   // ����������� �������� � ��������� (�� 50 �� 255)  // 17/03/16
                                 // ���� �������� �� ������ (0), �� ������������� 100%
  unsigned short Align       ;   // ������������ (FA_LEFT|FA_BASELINE, ...)
  unsigned short Service     ;   // ����� 0

  unsigned char  Wide        ;   // ������������� ������ ������� (UNIW_NORMAL, ...)
  unsigned char  Horizontal  ;   // ������� ��������������� ������������ (0/1)
  unsigned char  Italic      ;   // ������� ������� �������� (0/1)
  unsigned char  Underline   ;   // ������� �������������    (0/1)
  unsigned char  StrikeOut   ;   // ������� ��������������   (0/1)
  unsigned char  Type        ;   // ��� ������ (����� � �������: 0,1,2,3...)
  unsigned char  CharSet     ;   // ������� �������� (RUSSIAN_CHARSET, ...)
  unsigned char  Flag        ;   // �������� ����������� ������ (IMGTEXT_SCALE, ...)
}
  IMGTEXT;

// �������� ����������� ������ (��� ���� Flag ��������� IMGTEXT)
#define IMGTEXT_SCALE       1    // ������� ������������ �� ������� (������ �����������)
#define IMGTEXT_SHOWCODE    2    // ���������� �������� �������� �������������� ���������
#define IMGTEXT_SHORTCLS    4    // ���������� ��������� �������� �������������� ���������
#define IMGTEXT_EXPANDED    8    // ���������� ����� �� �������� ��������: "Abc" -> "A b c"
#define IMGTEXT_UPPERCASE  16    // ���������� ����� � ������� ��������: Abc -> "ABC"  // 24/11/15

typedef IMGTEXT IMGFONT;


typedef struct IMGMARKCHAIN      // �������� ��������� ��'��� �������
{                                //      (size = 4 + 128 = 132)
  unsigned int  Color    ;       // ���� �����
  unsigned char Bits[128];       // ��������� ����������� 32x32 � �������� ����
}
  IMGMARKCHAIN;


typedef struct IMGMULTIMARK      // (143) ������������ ��������
{                                //      (size = 20 + 132*Count)
  unsigned int  Length;          // ������ ����� ������ �������� �������
  unsigned int  Count ;          // ����� ������ � �����
  unsigned int  Size  ;          // ������ � �������� (��� ������)
  unsigned int  PosV  ;          // ����� �������� ����� PosV,PosH  <  Size
  unsigned int  PosH  ;          //  (��� IMGMULTISQUAREMARK - ��� ����� >= Size)
                                 // �����: Count �������� ���� IMGMARKCHAIN
}
  IMGMULTIMARK;


typedef struct IMGMULTISQUAREMARK// (144) ��������� + ������������ ��������
{                                //      (size = 4 + 20+132*Count )
  unsigned short Kind    ;       // ��� ����� ���������� 4x4 (16 ���)
                                 //  (IMGK_REGULAR, ...)
  unsigned char  FullMark;       // ���� ����������
                                 //  0 - �� ���� �������
                                 //  1 - ������ ������� �������
  unsigned char  Weight  ;       // ��� �����, ������� �������   // 27/04/00
                                 //  0 - ������
                                 //  1 - ����������
  IMGMULTIMARK   Mark    ;       // (143) ������������ ��������
                                 // �����: Count �������� ���� IMGMARKCHAIN
}
  IMGMULTISQUAREMARK;


typedef struct IMGDECOR          // ��������� ����� ����������
{
  unsigned short Length;         // ����� ���������� >= 4
                                 // (������� sizeof(IMGDECOR))
  unsigned short Number;         // ����� �������
}
  IMGDECOR;

// ����� ��� ������ ����������   // 28/07/00
#define IMGD_SPLINE       0x0001 // ���� ��������� �� ���������� �������

typedef struct IMGDRAW           // (147) ����� ����������
{
  unsigned int  Ident   ;        // ������������� ������ 0x7FFF7FFE
  unsigned int  Length  ;        // ������ ����� ������ �������� �������
  unsigned short Count  ;        // ���������� ����������
  unsigned short Flags  ;        // ������ ���� 0
  IMGDECOR      Image   ;        // ��������� ������� ���������
  unsigned int  Parm[1] ;        // ��������� ��������� �� ����
                                 // ����� ��������� � ���������
                                 // ��������� ����������
} IMGDRAW;

typedef IMGDRAW  SCRDRAW ;

typedef struct IMGDOTSHIFT       // (148) ������� ���������
{                                //
  IMGDOT    Dot   ;              // �������
  int       Shift ;              // ����������� � �������� ������
                                 // 0 - ������� ����� ������ �������� � ���
                                 // > 0 ���������� ������ �� ���,����� �����
                                 // ��� ������ = - ������ ������� ����� �����
                                 // �������� �  ���
}
 IMGDOTSHIFT;

typedef IMGDOTSHIFT SCRDOTSHIFT;

typedef struct IMGVECTPOINT      // ��� (149) �������� ����� �������
{                                //      (size = 8)
  int Hor;                       // ���������� �� ����� ��������
  int Ver;                       // ������ � ���� � ������������
                                 // � ����� �������:
                                 //  �����  �������  ����� ������ � ���������
                                 // Circle, Round  (h,v)  (dh,dh)
                                 // Ellipse, Oval  (h,v)  (dh,dv)
                                 // Arc,      Pie  (h,v)  (dh,dv) (h1,v1)(h2,v2)
}
  IMGVECTPOINT;


typedef struct IMGPOLYDESC       // ��� (149) �������� �������
{                                //      (size = 12 + 8*Count + Length)
  unsigned char  Type    ;       // ��� ������� (VT_SQUARE, ...)
                                 // ��� ��������� ����� VT_OBJECT,
                                 // VT_SUBJECT, VT_END)
  unsigned char  Image   ;       // ��� ����������
                                 // (IMG_SQUARE, IMG_LINE, IMG_DOT,
                                 // IMG_VECTORTEXT)                 // 11/04/05
  unsigned short Length  ;       // ����� ���������� (>= 4)
  unsigned int   Parm    ;       // ��������� ������� �� �� ����
  unsigned int   Count   ;       // ����� ����� � �������
  IMGVECTPOINT   Point[1];       // ���������� �� 512 �����
}
  IMGPOLYDESC;

typedef struct IMGVECTOREX       // (149,156) ��������� ���������� ��'����
{                                //      (size = 20 + ...)
  int  Length      ;             // ������ ����� ������ �������� �������
  int  PosV        ;             // ����� �������� ����� �� ���������
  int  PosH        ;             //  � ����������� (��������� ������ �����)
  int  Base        ;             // ����� ������� ������ ����� �����
  int  VLine1      ;             // ������ ������� �� ���������  (0)
  int  VLine2      ;             // �����  ������� �� ���������  (VSize)
  int  VSize       ;             // ��������� ������ ������� �� ���������
  int  HLine1      ;             // ������ ������� �� ����������� (0)
  int  HLine2      ;             // ����� ������� �� �����������  (HSize)
  int  HSize       ;             // ��������� ������ ������� �� �����������
  char Static      ;             // 1 - �������������� ������������
                                 // 0 - �� �������
  char Mirror      ;             // ���� ����������� ����������� �����
                                 // � ����������� ������ ����� �������
  char NoPress     ;             // ������� ������� ������ �����
  char Scale       ;             // ������� ������������ �� �������
  char Centre      ;             // ������� ������������� �� �������
  char  NoChangeColor ;  // 1 - �� ���������� ���� �� ��������� SEMIMAGECOLOR     
  char Reserve[2]  ;             // ������
  int  Border      ;             // �������� ����� �� ������� � ��� ��� 0
  int  Count       ;             // ����� ����������,����������� ����
  IMGPOLYDESC  Desc;             // �������� ���������
}
  IMGVECTOREX;                   // �� �� ��� IMG_VECTOREXTURN (156)

typedef struct TABLETEMPLATE     // ���������� ����� ���������� �������
{
  int  Length  ;                 // ����� ���������
  int Order[12];                 // ������ � ����������
                                 // 0-������ ������
                                 // -1 �����  -2 ����
                                 // >0  ����� ��������� �������  (�����)
  int  Origin  ;                 // ����� ������ ��������
  int  Static  ;                 // 1 - �������������� ������������
                                 // 0 - �� �������
}
  TABLETEMPLATE;

typedef struct IMGTEMPLATE       // (150) ��������� ���������� �������
{                                //      (size = 20 + ...)
  int  Length               ;    // ������ ����� ������ �������� �������
  TABLETEMPLATE Table       ;    // ���������� ����� ���������� �������
  int           Count       ;    // ���������� ����������
  IMGDECOR      Text        ;    // ��������� ������
  unsigned int  Parmtext[1] ;    // ��������� ������
  IMGDECOR      Line        ;    // ��������� �����
  unsigned int  Parmline[1] ;    // ��������� �����
  IMGDECOR      Mark        ;    // ��������� �����
  unsigned int  Parmmark[1] ;    // ��������� �����
}
  IMGTEMPLATE;

typedef struct IMGTRUETYPE       // (151) ��������� ����� �� TRUETYPE ������
{
  IMGTEXT Text     ;             // ��������� ������
  char FontName[32];             // �������� �������� ������
  int  Number      ;             // ����� ����� � ������
  int  MinV        ;             // �������� �����
  int  MinH        ;             //  ������������ ����� ��������
  int  MaxV        ;             // (0,0)
  int  MaxH        ;             // (H,H/2) - ��������� ��������
  int  PosV        ;             // ����� �������� ����� �� ���������
  int  PosH        ;             // � ����������� (0,0)
}
  IMGTRUETYPE;

typedef struct IMGTRUETEXT       // (152) �����
{                                //      (size = 64)
  IMGTEXT Text     ;             // ��������� ������ (���� Type - �����������)
  char FontName[32];             // �������� �������� ������
}
  IMGTRUETEXT;

typedef struct IMGSQUAREGLASS    // (154) ��������� ��'��� - ������
{                                //      (size = 8)
  signed int Bright;            // ������� ��������� ������� (+/- 100)
  signed int Contrast;          // ������� ��������� ��������� (+/- 100)
}
  IMGSQUAREGLASS;

typedef struct IMGSQUAREVECTOR   // (155) ��������� + ���������
{                                //
  int            Length  ;       // ����� ���������
  unsigned short Kind    ;       // ��� ����� ���������� 4x4 (16 ���)
                                 //  (IMGK_REGULAR, ...)
  unsigned char  FullMark;       // ���� ����������
                                 //  0 - �� ���� �������
                                 //  1 - ������ ������� �������
  unsigned char  Reserv  ;       // ������ ���� 0
  int            StepHor ;       // ���������� ����� ������� �� �����������
  int            StepVer ;       // ���������� ����� ������� �� ���������
  int            Angle   ;       // ���� �������� ����� �� ��������� �� �������
  IMGVECTOREX    Mark    ;       // �������� �����
}
  IMGSQUAREVECTOR;


#define DO_BASE      1           // ������� ������ (����� ���� �������)
                                 // ������� ����������� �������
#define DO_FIRST     2           // �� ������ �����
#define DO_END       3           // �� ��������� �����
#define DO_LEFT      4           // ����� �� ������ �����
#define DO_RIGHT     5           // ������ �� ������ �����
#define DO_MIDDLE1   6           // ����� ����� (1 - �����������)
#define DO_MIDDLE2   7           // ����� ����� (2 - �����������)


typedef struct IMGDECORHEAD      // ��������� ������������ ���������
{
  unsigned int  Length      ;    // ������ ����� ������ �������� �������
           int  Begin       ;    // ����� ������ �����
           int  End         ;    // ����� ����� �����
           int  Left        ;    // ����� ������ �������
           int  Right       ;    // ����� ����� �������
           int  First       ;    // ����� ������� ������������ �����
           int  Second      ;    // ����� ������� ������������ �����
           char Equidistant ;    // ���������� ��������� �� ���� �����
           char Reserv[3]   ;    // ������ - ����� 0
}
  IMGDECORHEAD;

typedef struct IMGDECORATE        // (157) ����������� ��������
{
  IMGDECORHEAD   Head         ;   // ���������
  IMGDECOR       Base         ;   // ��������� ������� �������
  unsigned int   BaseParm[1]  ;   // ��������� ������� �� ����
  IMGDECOR       Begin        ;   // ��������� ���������� ����� �����
  unsigned int   BeginParm[1] ;   // ��������� �� ����
  IMGDECOR       End          ;   // ��������� ���������� ����� �����
  unsigned int   EndParm[1]   ;   // ��������� �� ����
  IMGDECOR       Left         ;   // ��������� ���������� ����� �������
  unsigned int   LeftParm[1]  ;   // ��������� �� ����
  IMGDECOR       Rigth        ;   // ��������� ���������� ����� �������
  unsigned int   RigthParm[1] ;   // ��������� �� ����
  IMGDECOR       First        ;   // ��������� ������� ����� ����� �������
  unsigned int   FirstParm[1] ;   // ��������� �� ����
  IMGDECOR       Second       ;   // ��������� ������� ����� ����� �������
  unsigned int   SecondParm[1];   // ��������� �� ����
}
  IMGDECORATE;

typedef struct IMGSECTION     // �������� ��������� ������ ��� (158)
{
  unsigned int  Length;       // ����� ���������� (������� IMGSECTION)
  unsigned int  Number;       // ����� �������(IMG_EMPTY, IMG_LINE, IMG_VECTOREX,
                              //               IMG_TRUETYPE)
  unsigned int  Base;         // ����� �������, ���������� �������
  unsigned int  Parm[1];      // ���������
}
  IMGSECTION;

typedef struct IMGDASH           // (158) �������� ��������� �����
{
       int    Length;            // ������ ����� ������ �������� �������,
       int    Count;             // ����� ��������� ������ (�������, ��������, ������)
       int    Last;              // ���������� ����� ������ (�� 0 �� Count-1),
                                 // ����������� ������ �������
       int    Border;            // ������������ ������� ������
       int    Reserve;           // ������
  IMGSECTION  Section[1];        // �������� ��������� ������
}
  IMGDASH;

typedef struct IMGLINESHIFT      // (159) C�������� �����
{
       int    Length;            // ������ ����� ������ �������� �������,
       int    Shift;             // ����������� � �������� ������
                                 // = 0 - ����� ����� ����� ��� �������
                                 // > 0 - ����� ������ �� ���, ����� �����
  IMGDECOR    Head;              // ��������� �����
       int    Parm[1];           // ��������� ����� �� �� ����
}
  IMGLINESHIFT;

typedef struct IMGVECTORTEXT     // (160) ��������� ������� ���������� (VT_TEXT)
{                                // (size = 68)
  IMGTEXT  Text     ;            // ��������� ������
       int Code     ;            // ��� ��������� �������, ��� ������ �����������
                                 // ������ ��� 0 ��� ����������� ������
  char     Title[32];            // ���������� �����
}
  IMGVECTORTEXT;

typedef struct IMGGRAPHICMARKEX    // (165) �������� ���� - ����������� �����������
{                                  // (size = 312)
       int Length   ;              // ������ ����� ������ �������� �������
       int Ident    ;              // ������������� ����������� = 0
  char     Name[256];              // ��� ����� �����������
       int Type     ;              // ��� ����� (1 - BMP, 2 - JPEG, 3 - Metafile)
       int Height   ;              // �������� ����� (������, ������)
       int Width    ;              //
       int PosH     ;              // ����� �������� ����� �� �����������
       int PosV     ;              // � ��������� (�� ������ ��������� �����)
       int Shift        ;          // �������� ����
  IMGLINE  Contour      ;          // ��������� �������
  char     ContourFlag  ;          // ���� ������� �������
  char     ShadeFlag    ;          // ���� ������� ����
  char     TransparentFlag;        // ���� ������������ �������� �����     // 29/10/09
                                   // (������ ������ �������� - ����� ������ ���� BMP)
  char     Reserve[13]  ;          // ������
}
 IMGGRAPHICMARKEX;

typedef IMGGRAPHICMARKEX IMGGRAPHICMARK;   

typedef struct IMGHATCHSQUARESHIFT  // (166) ������������ ��������� �� ��������� ���������
{                                   // 04/04/08
       int Length;               // ������ ����� ������ �������� �������,
                                 // ������� ��������� ����� ���������
       int Angle ;               // ���� ������� ��������� � �������� (0,45,90,135,180,225,270,315)
                                 // ������ ������� ������� �� �����������
       int Step  ;               // ���������� ����� ����� ����� ���������
       int Number;               // ����� ������� ����� ��������� (IMGLINE, IMGDOT, IMGDASH)
       int Shift ;               // �������� ��� ������ ����� ���������
                                 // �����: ��������� ����� ���������
} IMGHATCHSQUARESHIFT;

typedef struct IMGPOLYGONGLASS   // (167) ��������� ��'��� - ������� ������ C ��������� ������������
{                                // (size = 16) (������ IMGSQUAREGLASSCOLOR)
         int  Color;             // ���� ����������� (IMGC_TRANSPARENT - ����������, ����)
  signed int Bright;            // ������� ��������� ������� (+/- 100)
  signed int Contrast;          // ������� ��������� ��������� (+/- 100)
         int  Transparency;      // ������� ������������ (�� 0 - �� ������������, �� 100 - �������� ����)
}
  IMGPOLYGONGLASS;


typedef struct IMGLINEGLASS      // (168) �������� ��'��� - ������� ������ C ��������� ������������
{                                // (size = 20) (������ IMGSQUAREGLASSCOLOR)
           int  Color;           // ���� ����������� (IMGC_TRANSPARENT - ����������, ����)
  unsigned int  Thick;           // ������� �����
  signed   int  Bright;          // ������� ��������� ������� (+/- 100)
  signed   int  Contrast;        // ������� ��������� ��������� (+/- 100)
           int  Transparency;    // ������� ������������ (�� 0 - �� ������������, �� 100 - �������� ����)
}
  IMGLINEGLASS;

typedef struct IMGDOTGLASS       // (169) ��������� ����� - ������� ������ C ��������� ������������
{                                // (size = 28)
           int  Color;           // ���� ����������� (IMGC_TRANSPARENT - ����������, ����)
  unsigned int  Thick;           // ������a ��p���
  unsigned int  Dash ;           // ����� ��p���
  unsigned int  Blank;           // ����� �p�����
  signed   int  Bright;          // ������� ��������� ������� (+/- 100)
  signed   int  Contrast;        // ������� ��������� ��������� (+/- 100)
           int  Transparency;    // ������� ������������ (�� 0 - �� ������������, �� 100 - �������� ����)
}
  IMGDOTGLASS;

typedef struct IMGMULTIMARKGLASS // (170) ������������ �������� - ������� ������
{                                //      (size = 20 + 132*Count)
  signed   int  Bright;          // ������� ��������� ������� (+/- 100)
  signed   int  Contrast;        // ������� ��������� ��������� (+/- 100)
           int  Transparency;    // ������� ������������ (�� 0 - �� ������������, �� 100 - �������� ����)
  IMGMULTIMARK  Mark;            // ��������� ��������� �����
}
  IMGMULTIMARKGLASS;

typedef struct IMGPICTURE        // 171  ����������� ���� ��������� � ��������������
{
  int  Length;                   // ������ ����� ������ �������� �������
  int  Height;                   // �������� ����� (������, ������)
  int  Width;                    //
  int  PosH;                     // ����� �������� ����� �� �����������
  int  PosV;                     // � ��������� (�� ������ ��������� �����)
  int  Shift;                    // �������� ����

  int  PixelHeight;              // �������� ����� (������, ������)
  int  PixelWidth;               // ���������� � ��������

  IMGLINE Contour;               // ��������� �������

  char ContourFlag;              // ���� ������� �������
  char ShadeFlag;                // ���� ������� ����
  char TransparentFlag;          // ���� ������������ �������� �����
                                 // (������ ������ �������� - ����� ������ ���� BMP)
  char Type;                     // ��� ����� (0 - PNG, 1 - BMP, 2 - JPG,
                                 //   3 - TIF, 4 - ICO, 5 - WMF, 6 - EMF)
                                 // ������ ��������������� ������� �����������
  char Reserve[16];              // ������

  // ����� ���������� ����� ����������� � ������������ � ����� Type
}
 IMGPICTURE;

#define IMGDOCITEMIDENT  0x7F7F7F7E

typedef struct IMGDOCITEM
{
  unsigned int  Ident   ;        // ������������� ������ 0x7F7F7F7E
  unsigned int  Length  ;        // ������ ����� ������
  unsigned int  HeadLength;      // ����� ��������� - �������� �� ������ ��������� (������ 4)
  unsigned int  DocLength;       // ����� ���������, ������� �� �������� �� ��������, ��� 0 (���� ������)
  unsigned int  ImageLength;     // ����� ����������� ��������� ��� 0 (���� ����������� ����)
  unsigned int  NameLength;      // ����� �������� ���������, ������� ���������� 0 (������ 4, �������� ����������� �������� �������)
  unsigned int  Date;            // ���� ��������\���������� ��������� ����� ��������� (YYYYMMDD)
  unsigned int  Time;            // ����� ��������\���������� ��������� ����� ��������� (����� ��� � 00:00)
  unsigned int  Flags;           // ����������� ������ (1 - �������� �������� �� ������, Name �������� ���� ��� �����)
  unsigned int  ImageFormat;     // ������ ����������� ��� 0 (FILE_PNG, FILE_JPEG, FILE_EMF, FILE_BMP) 
  WCHAR         Name[1];         // �������� ��������� (���� ���������� �����)
// ����� ����������� �������� � ��� ����������� � �������� �������, ���� ���� ����������� 
}
  IMGDOCITEM;

typedef struct IMGLIBRARY        // (250) ��������� ��'����(������ ������������)
{
       int Length  ;             // ������ ����� ������ �������� �������
       int Code    ;             // ��� DLL (IML)
       int Index   ;             // ������ DLL � ������ ���������
       int Function;             // ��� �������
  IMGDRAW  Draw    ;             // ���������
}
  IMGLIBRARY;

typedef struct IMGDOUBLE         // (253) ��������� ��������� ���� DOUBLE
{
  double Value;
}
  IMGDOUBLE;

typedef struct IMGLONG           // (254) ��������� ��������� ���� LONG
{
  int  Value;
}
  IMGLONG;

typedef struct IMGOBJECT         // (255) ����������/�������� ��'���
{                                //  � �������� ������ ��������������
                                 //      (size = 16)
  unsigned int  Color ;          // ���� ��������� ������� �� �����
                                 //  (IMGC_NOMARK - �� ��������)
  unsigned int  Incode;          // ���������� ��� �������
                                 //  (0 - ��������������� �� Excode � Local)
  unsigned int  Excode;          // ������� ��� �������
  unsigned int  Local ;          // ����������� ������� (IMGL_LINE, ...)

  // ��� ������� ���� PaintMapObject(...) Incode ���������������
  // �������������. ���� ��������� ������ �� �����, �� ������
  // ������ ��������� ����� ��������� ����.
}
  IMGOBJECT;



typedef struct IMGVECTORGRADIENT    // ��������������� ���������
{
  unsigned int  Color;        // ���� ����������� ������� (COLORREF)
  unsigned int  Left;         // ������� ���������� ��������� �����
  unsigned int  Right;        // ������� ���������� ��������� ������
  unsigned int  Bright;       // ������� ��������� ������� �������
}
  IMGVECTORGRADIENT;

typedef struct VECTORMIX
{
  unsigned int  Color;        // ���� ����� (COLORREF) ��� 0xFFFFFFFF
  signed   int  Bright;       // ������� ��������� ������� (+/- 100) ��� 0
  signed   int  Contrast;     // ������� ��������� ��������� (+/- 100) ��� 0
  signed   int  Transparency; // ������� ������������ (�� 0 - �� ������������, �� 100 - �������� ����)
  unsigned int  Exclusion;    // ����, ������� �� �������� (COLORREF, ������ 0x0FFFFFF) ��� 0xFFFFFFFF
  unsigned int  Scale;        // ������� ��������� �������� ����� ��� 1
}
  VECTORMIX;

typedef struct IMGVECTORMIX   // ��������������� ��������� (200)    // 12/04/12
{
  IMGVECTOREX * Vector;       // ��������� �� ��������� ���������� �����
  VECTORMIX     Mixing;       // ��������� ����������� ����������� �����
}
  IMGVECTORMIX;

typedef struct IMGDRAWMIX     // ��������������� ���������  (201)   // 18/04/12
{
  IMGDRAW *     Draw;         // ��������� �� ��������� ���������� �����
  VECTORMIX     Mixing;       // ��������� ����������� ����������� �����
}
  IMGDRAWMIX;

typedef struct LEGENDESC      // �������� �������� �������          // 21/04/15
{      
  COLORREF    FillColor;      // ���� ����, �� ������� ����������� �������� ������� (IMGC_TRANSPARENT - ����������)
  COLORREF    ContourColor;   // ���� ������� �������� ����������� (IMGC_TRANSPARENT - ����������)    
  int         ColumnCount;    // ����� �������� (1 � �����)
  int         ElHeight;       // ������ �������� ������� �� ������ � ��� �� ����� � ������� ��������
  int         ElWidth;        // ������ �������� ������� �� ������ (����������� ���� �������) � ���
  int         ElHeightImage;  // ������ ����������� ��������� ����� �� ������ � ���
  int         ElWidthImage;   // ������ ����������� ��������� ���� �� ������ � ���
  int         Reserve;        // ������, ����� ����
  IMGTRUETEXT ImageFont;      // �������� �������
}
  LEGENDESC;  

//**********************************************************************
// ���������� ��������� ���������� ������������ (�������� �� IMGDRAW,...)
//**********************************************************************

#define IMG_LINEDOT           130
#define IMG_DOUBLELINE        131
#define IMG_DOTDLINE          132
#define IMG_DOUBLEDOT         133
#define IMG_SHIFTLINEDOT      134
#define IMG_SQUARECROSS       136
#define IMG_MARK              137
#define IMG_SQUAREMARK        138
#define IMG_LEFTLINEDOT       145
#define IMG_DECORATELINE      146
#define IMG_SQUAREGLASSCOLOR  164  


typedef struct IMGLINEDOT        // (130) ������� �� �����
{                                //      (size = 24)
  IMGLINE Line;                  // ������ �����
  IMGDOT  Dot ;                  // ������� �����
}
  IMGLINEDOT;


typedef struct IMGDOUBLELINE     // (131) ����� �� �����
{                                //      (size = 16)
  IMGLINE OneLine;               // ������ �����
  IMGLINE TwoLine;               // ������� �����
}
  IMGDOUBLELINE;


typedef struct IMGDOTDLINE       // (132) ������� ����� �� ��������
{                                //      (size = 32)
  IMGDOT        Dot   ;          // ������ �����
  IMGDOUBLELINE Double;          // ������� �����
}
  IMGDOTDLINE;


typedef struct IMGDOUBLEDOT      // (133) ������� �������
{                                //      (size = 32)
  IMGDOT OneDot;                 // ������ �����
  IMGDOT TwoDot;                 // ������� �����
}
  IMGDOUBLEDOT;


typedef struct IMGSHIFTLINEDOT   // (134) �������, ��������� ������, �� �����
{                                //      (size = 24)
  IMGLINE Line;                  // ������ �����
  IMGDOT  Dot ;                  // ������� �����-�������
}
  IMGSHIFTLINEDOT;


typedef struct IMGSQUARECROSS    // (136) ������������ �������
{                                //      (size = 16)
  unsigned int  Color;           // ���� ��p������ (IMGC_TRANSPARENT - ����������)
  unsigned int  Kind ;           // ��� ��p������ (SC_HORIZONTAL, ...)
  unsigned int  Thick;           // ������a ��p��a
  unsigned int  Blank;           // ������a �p����a
}
  IMGSQUARECROSS;

typedef struct IMGMARK           // (137) �������� ��������� ��'���
{                                //      (size = 16 + 128 = 144)
  unsigned int  Color    ;       // ���� �����
  unsigned int  Size     ;       // ������ � �������� (��� ������)
  unsigned int  PosV     ;       // ����� �������� ����� PosV,PosH < Size
  unsigned int  PosH     ;       //  (��� IMGSQUAREMARK - ��� ����� >= Size
  unsigned char Bits[128];       // ��������� ����������� 32x32 � �������� ����
}
  IMGMARK;

typedef struct IMGSQUAREMARK     // (138) ��������� + ��������
{                                //      (size = 8 + 144 = 152)
  unsigned int   Color   ;       // ���� ���� (IMGC_TRANSPARENT - ����������)
  unsigned short Kind    ;       // ��� ����� ���������� 4x4 (16 ���)
                                 //  (IMGK_REGULAR, ...)
  unsigned char  FullMark;       // ���� ����������
                                 //  0 - �� ���� �������
                                 //  1 - ������ ������� �������
  unsigned char  Weight  ;       // ��� �����, ������� �������   // 27/04/00
                                 //  0 - ������
                                 //  1 - ����������
  IMGMARK        Mark    ;       // �������� �����
}
  IMGSQUAREMARK;



typedef struct IMGLEFTLINEDOT    // (145) �������, ��������� �����, �� �����
{                                //      (size = 24)
  IMGLINE Line;                  // ������ �����
  IMGDOT  Dot ;                  // ������� �����-�������
}
  IMGLEFTLINEDOT;


typedef struct IMGDECHEAD        // ��������� ������������ ���������
{
  unsigned int  Length   ;       // ������ ����� ������ �������� �������
           int  Distance ;       // ���������� ����� ������������ �������.
}
 IMGDECHEAD;
                                 // ������ �� ���������� � ������
                                 //
typedef struct IMGDECORATELINE   // (146) ����������� ��������
{
  IMGDECHEAD     Head        ;   // ���������
  IMGDECOR       Base        ;   // ��������� ������� �������
  unsigned int   BaseParm[1] ;   // ��������� ������� �� ����
  IMGDECOR       First       ;   // ��������� ����������
  unsigned int   FirstParm[1];   // ��������� �� ����
  IMGDECOR       End         ;   // ��������� ���������
  unsigned int   EndParm[1]  ;   // ��������� �� ����
  IMGDECOR       Left        ;   // ��������� ������
  unsigned int   LeftParm[1] ;   // ��������� �� ����
  IMGDECOR       Rigth       ;   // ��������� �������
  unsigned int   RigthParm[1];   // ��������� �� ����
  IMGDECOR       Middle1     ;   // ��������� ������� ������������
  unsigned int   Mid1Parm[1] ;   // ��������� �� ����
  IMGDECOR       Middle2     ;   // ��������� ������� ������������
  unsigned int   Mid2Parm[1] ;   // ��������� �� ����
}
  IMGDECORATELINE;

                                 // ( ) ����������� ��������
typedef IMGDECORATELINE SCRDECORATELINE;
                                 // ����� ��������� ������ ���������
                                 // �������� ��������� �����

typedef struct IMGHATCHSQUARE    // (153) ������������ ���������
{
       int Length;               // ������ ����� ������ �������� �������,
                                 // ������� ��������� ����� ���������
       int Angle ;               // ���� ������� ��������� � �������� (0,45,90,135)
                                 // ������ ������� ������� �� �����������
       int Step  ;               // ���������� ����� ����� ����� ���������
       int Number;               // ����� ������� ��������� ����� (IMGLINE ��� IMGDOT)
                                 // �����: ��������� ����� ���������
} IMGHATCHSQUARE ;


typedef struct IMGSQUAREGLASSCOLOR // (164) ��������� ��'��� - ������� ������
{                                  // (size = 12)
         int  Color;               // ���� ����������� (IMGC_TRANSPARENT - ����������)
  signed int Bright;               // ������� ��������� ������� (+/- 100)
  signed int Contrast;             // ������� ��������� ��������� (+/- 100)
}
  IMGSQUAREGLASSCOLOR;

#pragma pack(pop)

#endif  // MAPGDI_H

