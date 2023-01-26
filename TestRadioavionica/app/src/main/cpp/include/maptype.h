/****** MAPTYPE.H ************** Belenkov O.V.   ****** 08/08/16 ***
******* MAPTYPE.H ************** Kruzhkov A.E.   ****** 23/10/15 ***
******* MAPTYPE.H ************** Panteleeva N.A  ****** 14/11/14 ***
******* MAPTYPE.H ************** Dishlenko S.G.  ****** 07/06/16 ***
******* MAPTYPE.H ************** Alexeev    S.A. ****** 26/06/12 ***
******* MAPTYPE.H ************** Shabakov D.A.   ****** 21/07/16 ***
******* MAPTYPE.H ************** Gorbunov A.V.   ****** 17/04/13 ***
******* MAPTYPE.H ************** Tarakanova I.R. ****** 19/05/11 ***
******* MAPTYPE.H ************** Borzov A.U.     ****** 22/12/14 ***
******* MAPTYPE.H ************** Nefedieva O.A.  ****** 13/01/12 ***
******* MAPTYPE.H ************** ���������� �.A. ****** 06/05/13 ***
******* MAPTYPE.H ************** Derevyagina Zh.A.***** 05/07/16 ***
******* MAPTYPE.H ************** Korjilov A.      ***** 04/02/16 ***
******* MAPTYPE.H ************** Savelov A.S.     ***** 04/09/15 ***
******* MAPTYPE.H ************** Vitsko D.A.      ***** 27/07/16 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2016              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*               �������� ������� ����� ����������                  *
*                                                                  *
*******************************************************************/

#ifndef MAPTYPE_H
#define MAPTYPE_H

#ifndef MAPMACRO_H
 #include "mapmacro.h"
#endif

#ifndef MAPERR_RH
  #include "maperr.rh"
#endif

#pragma pack(push,1)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ��'������� ���������������
// (�������� ����������� �� ��������������� ������ �++ )
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#if defined(_M_X64) || defined(BUILD_DLL64)

typedef __int64   HMAP;    // ������������� �������� ��������� �����
                           // (��������� �� TMapAccess)
typedef __int64   HSITE;   // ������������� �������� ����������������
                           // ����� (��������� �� ������� �������)
                           // ���� ����� HMAP (��� 0) - �������� �
                           // ������ ��������� (������� ������)
typedef __int64   HOBJ;    // ������������� ��'���� �����
                           // (��������� �� TObjectInfo)
typedef __int64   HSELECT; // ������������� ��������� ������
                           // (��������� �� TMapSelect)
typedef __int64   HRSC;    // ������������� �������������� �����
                           // (��������� �� TMapRsc)
typedef __int64   HMTR3D;  // ������������� ��������� ������
                           // ���������� ������������ ���������
                           // (��������� �� TMtr3D)
typedef __int64   HCROSS;  // (��������� �� TObjectCut)
typedef __int64   HPOINT;  // (��������� �� ��������� CROSSPOINT)
typedef __int64   HDRAW;   // (��������� �� ��������� TDrawEdit)
typedef __int64   HPRINTER;// (��������� �� TPrinter)
typedef __int64   HVECT;   // (��������� �� TVectorImageEdit)    

// ��������� PANTASK/PANACTION
typedef __int64  HPANACTION;   // ��������� �� TPanAction
typedef __int64  HMAPACTION;   // ��������� �� TUserAction

typedef __int64  HPANTASK;     // ��������� �� TPanTask
typedef __int64  HMAPTASK;     // ��������� �� TUserTask

typedef __int64  HMAPDOC;      // ��������� �� TMapWindow

typedef __int64  HOBJSET;      // ��������� �� TObjectSet

typedef __int64  HFORMULA;     // ��������� �� TStrFormula  

typedef __int64  HPARAM;       // �������� ������� ��������� �������

#else

typedef long int  HMAP;    // ������������� �������� ��������� �����
                           // (��������� �� TMapAccess)
typedef long int  HSITE;   // ������������� �������� ����������������
                           // ����� (��������� �� ������� �������)
                           // ���� ����� HMAP (��� 0) - �������� �
                           // ������ ��������� (������� ������)
typedef long int  HOBJ;    // ������������� ��'���� �����
                           // (��������� �� TObjectInfo)
typedef long int  HSELECT; // ������������� ��������� ������
                           // (��������� �� TMapSelect)
typedef long int  HRSC;    // ������������� �������������� �����
                           // (��������� �� TMapRsc)
typedef long int  HMTR3D;  // ������������� ��������� ������
                           // ���������� ������������ ���������
                           // (��������� �� TMtr3D)
typedef long int  HCROSS;  // (��������� �� TObjectCut)
typedef long int  HPOINT;  // (��������� �� ��������� CROSSPOINT)
typedef long int  HDRAW;   // (��������� �� ��������� TDrawEdit)
typedef long int  HPRINTER;// (��������� �� TPrinter)
typedef long int  HVECT;   // (��������� �� TVectorImageEdit)    

// ��������� PANTASK/PANACTION
typedef long int HPANACTION;   // ��������� �� TPanAction
typedef long int HMAPACTION;   // ��������� �� TUserAction

typedef long int HPANTASK;     // ��������� �� TPanTask
typedef long int HMAPTASK;     // ��������� �� TUserTask

typedef long int HMAPDOC;      // ��������� �� TMapWindow

typedef long int HOBJSET;      // ��������� �� TObjectSet

typedef long int HFORMULA;     // ��������� �� TStrFormula       

typedef long int HPARAM;       // �������� ������� ��������� �������
#endif

typedef long int HIMAGE;       // ������������� TCopyImage (������ � ������)
typedef void *   HMAPREG;      // ������������� ������ ���������� ������ �������
typedef void *   HPAINT;       // ������������� TPaintControl


enum KIND                 // ���� �������� �������
{
  IDSHORT2  = 0x7FFF7FFF, // ������������ �������������
  IDLONG2   = 0x7FFE7FFE, // ��������������� �������������
  IDFLOAT2  = 0x7FFD7FFD, // � ��������� �������
  IDDOUBLE2 = 0x7FFC7FFC, // � ��������� ������� ������� ���������
  IDSHORT3  = 0x7FFB7FFB, // ������������ ������������� ����������
  IDLONG3   = 0x7FFA7FFA, // ��������������� ������������� ����������
  IDFLOAT3  = 0x7FF97FF9, // � ��������� ������� ����������
  IDDOUBLE3 = 0x7FF87FF8, // � ��������� ������� ������� ��������� ����������
  IDBAD     = 0x7FF87FF7  // ����������� ���
};


#if defined(__BORLANDC__)              
#ifndef max
 #define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
 #define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
#endif

#define LT left
#define RT right
#define UP top
#define DN bottom

// �������� ��������� ��������� ��� ������������
#define DELTANULL  ((double)(1e-3))   

// �������� ��������� ��������� ��� ���������� ��������
#define DOUBLENULL  ((double)(1e-6))  

// ������� ���������� 
#define ROUND(x)    (((x) < 0) ? (int)((x) - 0.5) : (int)((x) + 0.5))

// ����� �������� � 1 �������
#define DEGREEINRAD  57.29577951308232l

// ����� ������ � 1 �������
#define SECONDINRAD  206264.806247096l

typedef struct SHORTPOINT    // ���������� �����
{
  unsigned short int X;
  unsigned short int Y;
}
  SHORTPOINT;

typedef struct LONGPOINT     // ���������� ����� (������� �������)
{
  union { int X; int x; };               // 26/03/12
  union { int Y; int y; };
}
  LONGPOINT;

typedef struct FLOATPOINT    // ���������� ����� (��������� �������)
{
  float X;
  float Y;
}
  FLOATPOINT;

typedef struct DOUBLEPOINT   // ���������� ����� (��������� �������)
{
  union { double X; double x; };
  union { double Y; double y; };

  void operator  = (double value)  {         x  = value;   y  = value;  }
   int operator != (double value)  { return (x != value || y != value); }
   int operator == (double value)  { return (x == value && y == value); }
}
  DOUBLEPOINT;


typedef struct DRAWPOINT     // ������ TPoint
{
#ifndef WINCE
  union { XYTYPE x; XYTYPE X; };        
  union { XYTYPE y; XYTYPE Y; };
#else
  union { long int x; long int X; };
  union { long int y; long int Y; };
#endif

  void operator  = (int value)  {         x  = value;   y  = value;  }
   int operator != (int value)  { return (x != value || y != value); }
   int operator == (int value)  { return (x == value && y == value); }

  DRAWPOINT& operator - (DRAWPOINT& draw)
    { x -= draw.x;  y -= draw.y;  return *this;}

  DRAWPOINT& operator + (DRAWPOINT& draw)
    { x += draw.x;  y += draw.y;  return *this;}
}
  DRAWPOINT;


typedef struct DRAWSIZE      // ������ TSize
{
  union { int cx; int CX; };
  union { int cy; int CY; };

  void operator  = (int value)  {         cx  = value;   cy  = value;  }
  int operator != (int value)  { return (cx != value || cy != value); }
  int operator == (int value)  { return (cx == value && cy == value); }

  DRAWSIZE& operator - (DRAWSIZE& draw)
    { cx -= draw.cx;  cy -= draw.cy;  return *this;}

  DRAWSIZE& operator + (DRAWSIZE& draw)
    { cx += draw.cx;  cy += draw.cy;  return *this;}
}
  DRAWSIZE;


typedef struct DRAWLINE      // ���������� �����
{
  DRAWPOINT First;
  DRAWPOINT Second;
}
  DRAWLINE;

typedef struct DRAWBOX       // ���������� ���������� ��������������
{
  DRAWPOINT Point1;
  DRAWPOINT Point2;
  DRAWPOINT Point3;
  DRAWPOINT Point4;
}
  DRAWBOX;


//-----------------------------------------------------------------
// ���������� �������������� � ������ �����
// (X �����, Y ������, ������� ����������)
//-----------------------------------------------------------------

typedef struct FRAME         // �����
{
  int X1;                                                   // 26/03/12
  int Y1;
  int X2;
  int Y2;

  void operator = (int value)
  {
    X1 = value;  Y1 = value;
    X2 = value;  Y2 = value;
  }

  FRAME operator = (FRAME& frame)
  {
    X1 = frame.X1;  Y1 = frame.Y1;
    X2 = frame.X2;  Y2 = frame.Y2;  return *this;
  }

  int operator != (int value)
  {
    return ( X1 != value || Y1 != value ||
             X2 != value || Y2 != value );
  }

  int operator == (int value)
  {
    return ( X1 == value && Y1 == value &&
             X2 == value && Y2 == value);
  }
}
  FRAME;


typedef struct DFRAME        // ���������
{
  double X1;
  double Y1;
  double X2;
  double Y2;

  void operator = (double value)
  {
    X1 = value;  Y1 = value;
    X2 = value;  Y2 = value;
  }
}
  DFRAME;


//-----------------------------------------------------------------
// ���������� �������������� � ����
// (X ������, Y ����, ������� ����������)
//-----------------------------------------------------------------

typedef struct BOX           // �����
{
  union { int LT;  int lt; };                 // 26/03/12
  union { int UP;  int up; };
  union { int RT;  int rt; };
  union { int DN;  int dn; };

  void operator = (int value)
  {
    LT = value;  UP = value;
    RT = value;  DN = value;
  }
}
  BOX;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++  ��������� ������� ������� ��'����  +++++++++
//++++++++++++++  � ������� ��������� ����  +++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

// �������� ���� Flags (��� IMLAPI)
#define PF_SKIPNUMBER    2  // ���� �������� ������ � #    
#define PF_UNICODETEXT   4  // ���� ������ � UNICODE       
#define PF_SKIPSEMCOLOR  8  // ���� �������� ����� �� ��������� 
#define PF_SCALETOLEVEL 16  // ���� ��������������� ����� �� �������� �������   // 23/10/14
#define PF_FACTOR10     32  // ���� ������ ��������� �� 10 ������� �����������  // 11/03/16
#define PF_MULTIPOLYGON 64  // ���� ��������� ��������������

#if !defined(_M_X64) && !defined(BUILD_DLL64)       
typedef struct /*_DLLCLASS*/ POLYDATA  // 27/03/13
{
  POLYDATA() { memset(this, 0, sizeof(*this)); }

  DRAWPOINT * Points;  // ����� ������� �������� ���� POINT
                       // � ������������ �����
  int * PolyCounts;    // ����� ������� ���������� �����                  // 26/03/12
  int        Count;    // ����� ������� (���������������, �������)
  char **      Text;   // ��������� �� ������ ������� �������
                       // �������� (���� ������ �����
                       // � �������������� ������� �������)
  int    AlignCode;    // ��� ������������ ��� ����������� ������
  char *   Semantic;   // ��������� �� ��������� ������� (SEMANTIC *)
                       // ���� ��������� �� ����� � ����������� - ����� 0
  BOX        Border;   // ������������� ��������� ������� � ��������
                       // ������������ ������� ���������
  double  ShowScale;   // ������� ������� ����������� ����������� �����
}
  POLYDATA;

typedef struct /*_DLLCLASS */ POLYDATAEX
{
  POLYDATAEX() { memset(this, 0, sizeof(POLYDATAEX)); }

  DRAWPOINT * Points;  // ����� ������� �������� ���� POINT
                       // � ������������ �����
  int * PolyCounts;    // ����� ������� ���������� �����                 // 26/03/12
  int        Count;    // ����� ������� (���������������, �������)
  char **      Text;   // ��������� �� ������ ������� �������
                       // �������� (���� ������ �����
                       // � �������������� ������� �������)
  short   AlignCode;   // ��� ������������ ��� ����������� ������
  short       Flags;   // ����� ��������� ������� - ����� 0          
  char *   Semantic;   // ��������� �� ��������� ������� (SEMANTIC *)
                       // ���� ��������� �� ����� � ����������� - ����� 0
  BOX        Border;   // ������������� ��������� ������� � ��������
                       // ������������ ������� ���������
  double  ShowScale;   // ������� ������� ����������� ����������� �����
  HRSC       MapRsc;   // ������������� �����, ���������� ������������ ������
  float      Height;   // ������ ������ ����� ������� (���� 3D-����������) ��� 0 
  float      DX;       // ���������� �� ������ ����� �� ������ �� �����          
  float      DY;       // � �������� ����� - ��� �������������� ��������� ��������
}
  POLYDATAEX;
#else
typedef struct POLYDATAEX
{
  POLYDATAEX() { memset(this, 0, sizeof(POLYDATAEX)); }

  DRAWPOINT * Points;  // ����� ������� �������� ���� POINT
                       // � ������������ �����
  int * PolyCounts;    // ����� ������� ���������� �����                 // 26/03/12
  char **      Text;   // ��������� �� ������ ������� �������
                       // �������� (���� ������ �����
                       // � �������������� ������� �������)
  char *   Semantic;   // ��������� �� ��������� ������� (SEMANTIC *)
                       // ���� ��������� �� ����� � ����������� - ����� 0
  int        Count;    // ����� ������� (���������������, �������)
  short   AlignCode;   // ��� ������������ ��� ����������� ������
  short       Flags;   // ����� ��������� ������� - ����� 0         
  BOX        Border;   // ������������� ��������� ������� � ��������
                       // ������������ ������� ���������
  double  ShowScale;   // ������� ������� ����������� ����������� �����
  HRSC       MapRsc;   // ������������� �����, ���������� ������������ ������
  float      Height;   // ������ ������ ����� ������� (���� 3D-����������) ��� 0 
  float      DX;       // ���������� �� ������ ����� �� ������ �� �����          
  float      DY;       // � �������� ����� - ��� �������������� ��������� ��������
  float      Zero;     // ������������
}
  POLYDATAEX;

typedef POLYDATAEX POLYDATA;
#endif

// ��������� ����� ����� � DIB
#define SHIFTUP32 0

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ������������ �������� ������������� �������
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#if defined(COMPACTGIS) || defined(MINIDATA)
#define GD_POINTCOUNT  64000L  // ���������� ��������� ���������� �����
                               // ������� �������
#define GD_POLYCOUNT   16000L  // ���������� ��������� ����������
                               // ����������� �������
#define GD_TEXTCOUNT   16000L  // ���������� ��������� ����������
                               // ������� � ������� �������

#define MAXDATALENGTH (1024*1024L) // ������������ ����� �������

#else

#define GD_POINTCOUNT (1024*1024L) // ���������� ��������� ���������� �����
                                   // ������� �������
#define GD_POLYCOUNT   64000L      // ���������� ��������� ����������
                                   // ����������� �������
#define GD_TEXTCOUNT   32000L      // ���������� ��������� ����������
                                   // ������� � ������� �������

#define MAXDATALENGTH (32*1024*1024L) // ������������ ����� �������

#endif

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ��������� �������� ������������� ������� ��������     +++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef struct TEXTDATA      // ����� ������� � �������
{                            // ����� ����� = Length + 2
  unsigned char Length;      // ����� ��������
           char Text[256];   // ����� ���������� �����
  unsigned char Zero;        // ���������� ����
}
  TEXTDATA;

typedef struct TEXTDATAUN    // ����� ������� � ��������� UNICODE � �������
{                            // ����� ����� = Length + 2
  unsigned char  Pass;       // ���� ��� ������������ ������ ���� Text �� 2 �����
  unsigned char  Length;     // ����� ������ � ������ (������ 2)
          WCHAR  Text[127];  // ����� ���������� �����
  unsigned short Zero;       // ���������� ����
}
  TEXTDATAUN;

// ���� �������� ��������� ����� �������
typedef struct
{
  unsigned short int X;
  unsigned short int Y;
}
  XYSHORT;

typedef struct
{
  unsigned short int X;
  unsigned short int Y;
           float     H;
}
  XYHSHORT;

typedef struct
{
  int X;                             // 26/03/12
  int Y;
}
  XYLONG;

typedef struct
{
  int X;
  int Y;
  float    H;
}
  XYHLONG;

typedef struct
{
  float X;
  float Y;
}
  XYFLOAT;

typedef DOUBLEPOINT XYDOUBLE;          // 12/02/10

typedef struct
{
  float X;
  float Y;
  float H;
}
  XYHFLOAT;

typedef struct
{
  double X;
  double Y;
  double H;
}
  XYHDOUBLE;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++ ��������� ���������� MAPAPI +++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// ��������������, ������������ �������� mapCheckFile.

enum  MAPFILES                // �������������� ������ (Intel)
{
    FILE_SXF  = 0x00465853,   // �������� SXF ����
    FILE_TXT  = 0x4658532E,   // ��������� SXF ���� (TXF � ������ .SXF - MAP)
    FILE_TXFMAP = 0x4658532E, // ��������� SXF ���� (TXF � ������ .SXF - MAP)
    FILE_DIR  = 0x524944,     // ��������� DIR ����
    FILE_PCX  = 0x10,         // ���� PCX (������������ �� �����)
    FILE_BMP  = 0x4D42,       // ���� BMP
    FILE_TIFF = 0x4949,       // ���� TIFF
    FILE_BIGTIFF = 0x49492B,  // ���� bigTIFF                    // 18/09/13
    FILE_JPEG = 0xD8FF,       // ���� JPEG
    FILE_MRSID= 0x6469736D,   // ���� MrSid (SID,JPEG2000,NITF)  // 26/09/08
    FILE_MAP  = 0x00505350,   // ������� ������ ����� MAP
    FILE_MAPSIT = 0x00544953, // ������� ������ ����� SIT        // 27/10/08
    FILE_SITX = 0x58544953,   // ���� SITX                       // 12/03/13
    FILE_RSW  = 0x00575352,   // ���� RSW
    FILE_RSWTIFF = 0x54575352,//(RSWT)RSW+TIFF                   // 24/05/11
    FILE_MTW  = 0x0057544D,   // ���� MTW
    FILE_MTL  = 0x004C544D,   // ���� MTL
    FILE_MTD  = 0x0044544D,   // ���� MTD  28/11/07
    FILE_SIT  = 0x5449532E,   // ��������� SXF ���� (TXF � ������ .SIT - SIT)
    FILE_TXFSIT = 0x5449532E, // ��������� SXF ���� (TXF � ������ .SIT - SIT)
    FILE_DXF  = 0x00465844,   // ���� DXF
    FILE_MIF  = 0x0046494D,   // ���� MAPINFO
    FILE_S57  = 0x00003000,   // ���� S57(�������)
    FILE_DGN  = 0x004E4744,   // ���� Macrostation(DGN)    
    FILE_MPT  = 0x0054504D,   // ���� MPT(������)
    FILE_RSC  = 0x00435352,   // ���� RSC
    FILE_MTQ  = 0x0051544D,   // ���� MTQ
    FILE_PLN  = 0x004E4C50,   // ���� PLN (Talka)                
    FILE_SHP  = 0x00504853,   // ���� SHP (ArcView)              
    FILE_PLS  = 0x00534C50,   // ���� PLS (������ �������)       
    FILE_TEXT = 0x00545854,   // ���� TXT(������������� �������) 
    FILE_GPS  = 0x47504724,   // ���� GPS/NMEA ($GPG)            
    FILE_GRD  = 0x00445247,   // ���� GRD (������� ������� FOTOMOD) 
    FILE_DBF  = 0x00464244,   // ���� DBF (���� ������)             
    FILE_TIN  = 0x004E4954,   // ���� TIN                           
    FILE_XLS  = 0x0000CFD0,   // ���� EXCEL                         
    FILE_WMS  = 0x00534D57,   // URL ��� ����������� � WMS-�������  
    FILE_IMG  = 0x00494D47,   // ���� IMG                           // 15/09/12
    FILE_PNG  = 0x00504E47,   // ���� PNG                           // 15/09/12
    FILE_GIF  = 0x00474946,   // ���� GIF                           // 15/09/12
    FILE_WFS  = 0x00221497,   // URL ��� ����������� � WFS-�������  // 29/03/13
    FILE_WCS  = 0x00331924,   // URL ��� ����������� � WCS-�������  // 17/04/13
    FILE_KML  = 0x25FF5621,   // ���� KML                           // 06/05/13
    FILE_GML  = 0x25FF5622,   // ���� GML                           // 06/05/13
    FILE_MP   = 0x25FF5623,   // ���� MP                            // 06/05/13
    FILE_OZF2 = 0x7778,       // ���� OZF2 (������� ��� OziExplorer)// 20/11/13
    FILE_OZFX3= 0x7780,       // ���� OZFX3(������� ��� OziExplorer)// 20/11/13
    FILE_EMF  = 0x00464D45,   // ���� EMF
    FILE_DBM  = 0x3C3F786D,   // ���� SQL-�����                     // 27/07/16
    FILE_XML  = 0x25FF5624,   // ���� XML                           // 08/08/16 


                              // �������������� ������ (Sparc, Mips)

    FILE_MAP_TURN = 0x50535000, // ������� ������ �����
    FILE_MTW_TURN = 0x4D545700, // ���� MTW
    FILE_SXF_TURN = 0x53584600, // �������� SXF ����   
    FILE_DIR_TURN = 0x44495200, // ��������� DIR ����  
    FILE_RSW_TURN = 0x52535700, // ���� RSW  
    FILE_RSC_TURN = 0x52534300, // ���� RSC
    FILE_SIT_TURN = 0x2E534954, // ��������� SXF(.SIT) ���� // 30/06/08
    FILE_MTR_TURN = 0x4D545200, // ���� MTR
    FILE_MTQ_TURN = 0x4D545100, // ���� MTQ
    FILE_RST_TURN = 0x52535400, // ���� RST
};

enum                            // �������������� ������ ����� �����
{
    LABEL_HDR      = 0x00524448L,  // HDR0
    LABEL_DAT      = 0x00544144L,  // DAT0
    LABEL_SEM      = 0x004D4553L,  // SEM0
    LABEL_DRW      = 0x00575244L,  // DRW0
    LABEL_VEC      = 0x00434556L,  // VEC0

    LABEL_HDR_TURN = 0x48445200L,  // 0RDH
    LABEL_DAT_TURN = 0x44415400L,  // 0TAD
    LABEL_SEM_TURN = 0x53454D00L,  // 0MES
    LABEL_DRW_TURN = 0x44525700L,  // 0WRD
    LABEL_VEC_TURN = 0x56454300L,  // 0CEV
};

// ������� � ����� ����� ��� WMS
#define WMAPWMS L"WMS#"
#define MAPWMS "WMS#"
#define WMSSIZE 4

// ������� � ����� ����� ��� WMTS         // 07/02/12
#define WMAPWMTS L"WMTS#"
#define MAPWMTS "WMTS#"
#define WMTSSIZE 5

// ������� � ����� ����� ��� WFS // 29/03/13
#define WMAPWFS L"WFS#"
#define MAPWFS "WFS#"
#define WFSSIZE 4

// ������� � ����� ����� ��� WCS // 17/04/13
#define WMAPWCS L"WCS#"
#define MAPWCS "WCS#"
#define WCSSIZE 4

// ������� �������� ����� �� ����������� ������
#define GENERIC_OVERLAP  0x0AA

typedef struct FRAME MAPFRAME;

typedef struct DFRAME MAPDFRAME;

typedef struct MAPADJACENTSECTION  // �������� �������� �������
{
  int number;                 // ����� �������                          // 26/03/12
  int first;                  // ������ ����� �������
  int last;                   // ��������� ����� �������
}
  MAPADJACENTSECTION;

typedef struct MAPADJACENTLISTEX
{
  char ListName[32];           // ��� �����
  int  List;                   // ����� ����� � ������                 // 26/03/12
  int  Key;                    // ����� �������
  int  Object;                 // ���������������� ����� ������� �� �����
  int  Excode;                 // ����������������� ��� �������
  int  First;                  // ������ ����� �������
  int  Last;                   // ��������� ����� �������
}
  MAPADJACENTLISTEX;

// �������� �������� ������� // 07/02/14
typedef struct CONNECTPATH
{
  int IsForward;      // ����������� ������� �� ������� ����������
                      // (����������� �� �������� ���������� ������ ���������
                      // � ������������ ����������)
  int FirstPoint;     // ������ ����� ������� �� ������� ����������
  int LastPoint;      // ��������� ����� ������� �� ������� ����������
  int NearSubject;    // ����� ��������� ����������
  int NearFirstPoint; // ������ ����� ������� �� �������� ����������
  int NearLastPoint;  // ��������� ����� ������� �� �������� ����������
}
  CONNECTPATH;

typedef enum how       // ���� ������� ������ �� ���������
{
    CMBAD      = 0,    // ������ � ������
    CMPASS     = 0,    // ���������� ���� ��������� 
      LESS     = 1,    // ������
    CMLESS     = 1,    // ������
    CMLESSEQ   = 3,    // ������ ��� �����
      EQUAL    = 2,    // �����
    CMEQUAL    = 2,    // �����
    CMNOTEQ    = 5,    // �� �����
      MORE     = 4,    // ������
    CMMORE     = 4,    // ������
    CMMOREEQ   = 6,    // ������ ��� �����
    CMANY      = 7,    // ����� ��������

    // ���� ���������� �������
    CMOR       = 16,   // "���" - ���� �� ���� �����������
    CMAND      = 32,   // "�"   - ��� ������ �����������
}
    HOW;

// ������, ������������ ������� ������ ��������
// ���� ������� WO_INMAP - ����� ����� ������������
// �� HSELECT !

enum SEEKTYPE        // ������� ������ ��'�����
{
   WO_FIRST  = 0,         // ������ � �������
   WO_LAST   = 2,         // ��������� � �������
   WO_NEXT   = 4,         // ��������� �� ��������� �����
   WO_BACK   = 8,         // ���������� �� ����� ����������
   WO_CANCEL = 16,        // ������� ��������� �������
   WO_INMAP  = 32,        // ������ �� ����� ����� (��������������� HSELECT)
   WO_VISUAL = 64,        // ����� ������ ����� ������� ��������
   WO_VISUALIGNORE = 128, // ����� ����� ���� �������� ��� ����� ���������
   WO_SKIPTEXT = 256,     // ����� ��� ������ �������� ��������� 
};

enum SEEKINAREA                // 26/04/11
{
   SO_SEEKBYDISTANCE     = 0,  // ����� �� ����������
   SO_SEEKINSIDEANDCROSS = 1,  // ����� ������ �������, ������� ����������� ������� �������
   SO_SEEKINSIDEONLY     = 2,  // ����� ������ �������, �������� ����������� �������
   SO_SEEKOUTSIDEONLY    = 4,  // ����� ��� �������, �������� ����������� �������
};

enum SELECTTYPEFLAG  // ������ ��������� ��������
{
   STF_CONTOUR = 0,  // ��������� ��������
   STF_OBJECT  = 1,  // ��������� ����� ����������� �������
};

enum SELECTLISTCODE           // ������� ������������ ������ ������� ������
{
   SELECTLIST_EXCLUSIVE = 0,  // ����������� ������� ������������ � ������
   SELECTLIST_UNION     = 1,  // ������� ��������� ������������ � ����������
   SELECTLIST_CROSS     = 2,  // ������� ��������� ���������� � ����������
};

enum SELECTMEASURE            // ��� ��������� ��"����� ��� ������ 
{
   MEASURE_LENGTH      = 1,   // ����� (�)
   MEASURE_SQUARE      = 2,   // ������� (��.�)
   MEASURE_PERIMETER   = 3,   // �������� (�)
   MEASURE_HEIGHT      = 10,  // ������ (�)
};

enum PPLACE            // ����������� ������� ���������
{
   PP_MAP      = 1,    // ���������� ����� � ������� ����� � ���������
   PP_PICTURE  = 2,    // ���������� ����� � ������� ����������� � ��������
   PP_PLANE    = 3,    // ���������� ����� � ������� ������������� �������
                       // �� ��������� � ������
   PP_GEO      = 4,    // ���������� ����� � ������������� �����������
                       // � ��������
   PP_GEOWGS84 = 8,    // ���������� ����� � ������������� �����������
                       // � �������� � ������� WGS-84
};

enum CURRENTPOINTFORMAT  // ������ ����������� �����  // 09/06/10
{
   PLANEPOINT      = 1,  // � ������ �� ��������� � ������� ���������� �������� ("DocProjection")
                         // ��������� ����������� 1942�. ��-42 ��� ��-95,
                         // ���� ������� ����� � ��-95 
   MAPPOINT        = 2,  // � �������� �������� ����� (���������)
   PICTUREPOINT    = 3,  // � �������� �������� ������� �����������

   GEORAD          = 4,  // � ��������
   GEOGRAD         = 5,  // � ��������
   GEOGRADMIN      = 6,  // � ��������, �������, ��������

                         // ���������� ��������� WGS84
   GEORADWGS84     = 7,  // � ��������
   GEOGRADWGS84    = 8,  // � ��������
   GEOGRADMINWGS84 = 9,  // � ��������, �������, ��������

   PLANE42POINT    = 10, // � ������ �� ��������� �� ��������� ���� � ��-42

                         // ���������� ��������� ��-90.02 (SGS-85)
   GEORADPZ90      = 11, // � ��������
   GEOGRADPZ90     = 12, // � ��������
   GEOGRADMINPZ90  = 13, // � ��������, �������, ��������

   PLANEWORKSYS      = 14, // � ������ �� ��������� � ������� ������� � ������������ � ����������� ("WorkSystem")
   GEORADWORKSYS     = 15, // � �������� � ������� �������
   GEOGRADWORKSYS    = 16, // � �������� � ������� �������
   GEOGRADMINWORKSYS = 17, // � �������� �������, �������� � ������� �������

   PLANE95POINT      = 18, // � ������ �� ��������� �� ��������� ���� � ��-95          // 15/11/10

   LASTPOINTFORMAT   = 18, // ���������� ��������
};

enum CURRENTUNITSFORMAT  // ������� ���������  // 05/07/16
{
   UNITSPLANE        = 0,  // �����
   UNITSFT           = 1,  // ����
   LASTUNITSFORMAT   = 1, // ���������� ��������
};

enum VTYPE               // ��� ����������� �����
{
   // �������� �����
   VT_SCREEN          = 1, // �������� (����� DIB)
   VT_SCREENCONTOUR   = 2, // �������� ���������

   // ���������� ��������� �����
   VT_PRINT           = 3, // ���������� ��������� (����� WIN API)
   VT_PRINTGLASS      = 4, // ���������� ��� ������� ���������
   VT_PRINTCONTOUR    = 5, // ���������� ���������, ��� �������� ������

   // ���������� �������������� �����
   VT_PRINTRST        = 6, // ���������� �������������� (����� WIN API)
   VT_PRINTGLASSRST   = 7, // ���������� ��� ������� ���������
   VT_PRINTCONTOURRST = 8, // ���������� ���������, ��� �������� ������

   // ���������� �������������� (�����������) �����       
   VT_PRINTRSTSQUARE  = 9, // ���������� (������� ���������, ������� � �����,
                           //             ������, �������)
   VT_PRINTRSTLINE    =10, // ���������� (�����, ��������, ���������,
                           //             ������� � �����, ����������������)
   VT_PRINTRSTTEXT    =11, // ���������� (�������, �������)

   // ���������� ��������� (�����������) �����. ������������ ��� ��������
   // ������� (POSTSCRIPT, WMF, EMF)                    
   VT_PRINTEX         =15, // ���������� ��������� (����� WIN API)
};

enum OUTPUTAREA            // ������ ������ ������� ������
{
  AREA_ALL            = 0, // �������� : ������� ������ - ���� �����
                           // �������� : ������� ������ �� ���������

  AREA_FRAME          = 1, // �������� : ������� ������ - �� RectMetr
                           // �������� : ������� ������ -> � RectMetr

  AREA_SELECT_FRAME   = 2, // �������� : ������� ������ - �� RectMetr
                           // �������� : ��� ������ �������������� ���������

  AREA_CHANGE_FRAME   = 3, // �������� : ������� ������ - �� RectMetr
                           // �������� : ��� ��������� ���������

  AREA_MOVE_FRAME     = 4, // �������� : ������� ������ - �� RectMetr
                           // �������� : ��� ����������� ���������

  AREA_SELECT_OBJECT  = 5, // �������� : ������� ������ - �� RectMetr
                           // �������� : ��� ������ ������� ������ �� �������

  AREA_SELECT_CONTOUR = 6, // �������� : ������� ������ - �� RectMetr
                           // �������� :  ��� ������ ������� ������ �� �������

  AREA_OBJECT         = 7, // ���������� ������ �� ������  // 13/02/13
                           // ������� ����������� ����� �� �������

  AREA_CONTOUR        = 8, // ���������� ������ �� ������
                           // ������� ����������� ����� �� �������

  AREA_OBJECTS        = 9, // ��������� ����������� �� ���������� ��������

  AREA_SELECT_TURN_FRAME = 10, // ���� ������ ����������� ���������
};

enum CHARCODE         // �������� ��������� �������
{
  CC_ASCIIZ  = 0  ,   // C����� �������� (ASCIIZ), ������������ �����
  CC_KOI8    = 125,   // C����� (KOI8), ������������ �����
  CC_ANSI    = 126,   // C����� (ANSI, WINDOWS), ������������ �����
  CC_UNICODE = 127,   // C����� �������� (UNICODE), ������������ �����
};

enum SPLINETYPE           // ���� ��������
{
  SPLINETYPE_NONE   = 0,  // ������� �����
  SPLINETYPE_SMOOTH = 2,  // ������������ ������ (������� ����)
  SPLINETYPE_POINTS = 4,  // ��������� ������ (�������� ����� �����)
};

enum POINTPOSITION        // ���������� ����� ������������ �������
{
  PS_FIRST   = 1,         // ��������� � ������ ������ �������
  PS_SECOND  = 2,         // ��������� �� ������ ������ �������
  PS_BEHIND  = 3,         // ����� ������ ������ ����� �������
  PS_BEYOND  = 4,         // ����� ������� ������ ����� �������
  PS_BETWEEN = 5,         // ����� �� ������� (����� �������)
  PS_LEFT    = 6,         // �����
  PS_RIGHT   = 7          // ������
};


typedef struct GEODEGREE   // ���������� ����� � ��������
{
  int   Degree;         // �������
  int   Minute;         // ������
  float Second;         // �������
}
  GEODEGREE;

typedef struct SIGNDEGREE  // ���������� ����� � ��������
{
  int   Degree;       // �������
  int   Minute;       // ������
  float Second;       // �������
  int   Sign;         // ���� ����� (+1 ��� -1)
}
  SIGNDEGREE;

typedef struct MTRDESCRIBE // �������� �������� �������
{
  char   Name[256];      // ��� �����
  double MinValue;       // ����������� �������� �������� � �������
  double MaxValue;       // ������������ �������� �������� � �������
  double ElementInPlane; // ������ �������� � ������ �� ���������
  DFRAME FrameMeters;    // �������� ������� (�����)
  int    ReliefType;     // ��� ������� (0 - ���������� ������,
                         //  1 - ���������� + �������������)
  int    UserType;       // ��� ���������������� ������
  int    View;           // ������� ��������������
}
  MTRDESCRIBE;

#define MTRTILEIDENT      0x7F7F7F7F

typedef struct MTRTILE    // �������� ��������� ������� �� ������� ���������
{
  int  Ident;             // ������������� ������ 0x7F7F7F7F
  int  Length;            // ����� ������ � ������ � ���������� (262208 ����)
  int  Width;             // ����� �������� (256)
  int  Height;            // ����� �����    (256)
  int  Epsg;              // ��� EPSG �������� ������� ��������� (��������, 3857)
  int  Level;             // ������� ������� � �������� ������ (���������� �������� ������)
  int  WidthNumber;       // ����� ������� ������� � �������� ������� ��������� (� ������������ �� -180 �� +180 ��������)
  int  HeightNumber;      // ����� ������ ������� � �������� ������� ��������� (� ������������ �� -90 �� +90 ��������)
  int  Unit;              // ������� ��������� ������ (0 - �����, 1 - ���������, 2 - ����������, 3 - ����������)
  int  UnitPlane;         // ������� ��������� � ����� (0 - �����, 1 - ���������, 2 - ����������, 3 - ����������)
  int  ItemWidth;         // ������ �������� � �������� �������� ��������� � ����� (���������)
  int  ItemHeight;        // ������ �������� � �������� �������� ��������� � ����� (���������)
  int  MinValue;          // ����������� �������� � �������
  int  MaxValue;          // ������������ �������� � �������
  int  Reserve[2];        // ������, �������� ����

  int  Value[256][256];    // �������� ����� � �������� �������� ��������� ������
}
  MTRTILE;

typedef struct MTRTILE2   // �������� ��������� ������� �� ������� ���������
{
  int  Ident;             // ������������� ������ 0x7F7F7F7F
  int  Length;            // ����� ������ � ������ � ���������� (131136 ����)
  int  Width;             // ����� �������� (256)
  int  Height;            // ����� �����    (256)
  int  Epsg;              // ��� EPSG �������� ������� ��������� (��������, 3857)
  int  Level;             // ������� ������� � �������� ������ (���������� �������� ������)
  int  WidthNumber;       // ����� ������� ������� � �������� ������� ��������� (� ������������ �� -180 �� +180 ��������)
  int  HeightNumber;      // ����� ������ ������� � �������� ������� ��������� (� ������������ �� -90 �� +90 ��������)
  int  Unit;              // ������� ��������� ������ (0 - �����, 1 - ���������, 2 - ����������, 3 - ����������)
  int  UnitPlane;         // ������� ��������� � ����� (0 - �����, 1 - ���������, 2 - ����������, 3 - ����������)
  int  ItemWidth;         // ������ �������� � �������� �������� ��������� � ����� (���������)
  int  ItemHeight;        // ������ �������� � �������� �������� ��������� � ����� (���������)
  int  MinValue;          // ����������� �������� � �������
  int  MaxValue;          // ������������ �������� � �������
  int  Reserve[2];        // ������, �������� ����

  unsigned short int Value[256][256];  // �������� ����� � �������� �������� ��������� ������, ������������ MinValue
}
  MTRTILE2;

typedef struct MTRDESCRIBEUN // �������� �������� �������
{
  WCHAR  Name[1024];     // ��� �����
  double MinValue;       // ����������� �������� �������� � �������
  double MaxValue;       // ������������ �������� �������� � �������
  double ElementInPlane; // ������ �������� � ������ �� ���������
  DFRAME FrameMeters;    // �������� ������� (�����)
  int    ReliefType;     // ��� ������� (0 - ���������� ������, 1 - ���������� + �������������)
  int    UserType;       // ��� ���������������� ������
  int    View;           // ������� ��������������
  int    Zero;           // ������
}
  MTRDESCRIBEUN;


typedef struct MTRCOLORDESCEX  // �������� ��������� �����
                               // �������
{
  double MinHeight;            // ����������� ������ ��������
  double MaxHeight;            // ������������ ������ ��������
  COLORREF Color;              // ����,��������������� ��������� �����
}
  MTRCOLORDESCEX;

typedef struct MTR3DVIEW     // ��������� 3D-����������� ������� �����
{
  double AreaCenterX;        // ����� ������������ ������� X,Y
  double AreaCenterY;        //   (� ������ �� ���������)
  double ViewPointX;         // ����� ���������� X,Y,H
  double ViewPointY;         //   (� ������ �� ���������)
  double ViewPointH;         //
  unsigned int  ShowScale;   // ����������� ��������
  unsigned char Style;       // C���� (0 - �����, 1 - �������)
  unsigned char ShowGrid;    // ������� ����� (0 - ���, 1 - ����)
  unsigned char GridStep;    // ��� ����� � �������� (2 - 255)
  unsigned char ModelHeight; // ������ ������ � �������� (2 - 127)
}
  MTR3DVIEW;

enum CUTSHAPE                // ����� �������
{
  CS_NONE          =   0,    // �����������
  CS_VERTICALANGLE =   1,    // ������������ ������� ������
                             //   � �������� � ����� CutX,CutY
  CS_VOLUMETRICAL  =  16,    // �������� �����
                             //   � �������� � ����� CutX,CutY,CutZ
  CS_HORIZONTAL    = 128,    // �������������� ���� �� ������ CutH
};

enum SCALETYPE               // ��� �����
{
  ST_NONE          =   0,    // �����������
  ST_ABSOLUTE      =   1,    // ����������
  ST_FROMRELIEF    =   2,    // ������������� �� �������
  ST_WITHOUTRELIEF =   3,    // ������������� ��� ����� �������
};

#define MTL3D_MAXMODEL 0x01FF  // ������������ ������ ������ ������� �����
                               // (�������� ������ ��������� ������)

typedef struct MTR3DVIEWEX   // ��������� 3D-����������� ������ (MTW � MTL)
{
  double AreaCenterX;        // ����� ������������ ������� X,Y
  double AreaCenterY;        //   (� ������ �� ���������)
  double CutX;               // ���������� ������� �������/������ X,Y,Z
  double CutY;               //   (� ������ �� ���������)      - ��� MTL
  double CutZ;
  double CutH;               // ������ ��������������� ����� (� ������)

    long ShowScale;          // ����������� �������� ����������� ���������
    long ModelHeight;        // ������ ������ � �������� (2 - MTL3D_MAXMODEL)
    long GridStep;           // ��� ����� � �������� (2 - 100)
    long CutShape;           // ����� ������� (��. CUTSHAPE)   - ��� MTL

   short ViewAngle;          // ���� ����������/������� (� ��������)
   short RotationAngle;      // ���� �������� ������������ ������ AreaCenter
                             //   (� ��������)
    char Style;              // C���� (0 - �����, 1 - �������)
    char ShowGrid;           // ������� ����� (0 - ���, 1 - ����)
    char Shadow;             // ������� ���� (0 - ���, 1 - ����)
    char ScaleType;          // ��� ����� (��. SCALETYPE)      - ��� MTL

    char CoverMatrix;        // ������� ������� �����   (0 - ���, 1 - ����)
    char CoverMap;           // ������� �����           (0 - ���, 1 - ����)
    char CoverRaster;        // ������� ������          (0 - ���, 1 - ����)
    char AccordScale;        // ������������ ���������  (0 - ���, 1 - ����)
    char CoverMtq;           // ������� ������� ��������(0 - ���, 1 - ����)  // 06/10/04
    char IsUpdate ;          // ����������� ����������� (0 - ���, 1 - ��)    // 21/10/05

    char Reserve[26];

  double CursorX;            // ���������� ��������� X,Y
  double CursorY;            //   (� ������ �� ���������)

    long Width;              // ������ �����������
    long Height;             // ������ �����������

    char Name[256];          // ��� ����� ������������ �������
                             //   (0 - ��� ������� �����)    - ��� MTL
}
  MTR3DVIEWEX;

                             // ��������� 3D-����������� ������ ����� (MTL)
typedef struct MTR3DVIEWEX MTL3DVIEW;


typedef struct METAFILEBUILDPARM  // ��������� �������� ���������
{
  long CenterX;     // ���������� ������ ��������� �������
  long CenterY;     // (� ������ �� ���������)
  long Width;       // ������ ��������� (� �����������)
  long Height;      // ������ ��������� (� �����������)
  long Scale;       // ������� �����������
  long VisualType;  // ��� ������������ (�� VT_SCREEN �� VT_PRINTEX)
   // �������� �����
   //   VT_SCREEN          = 1, // �������� (����� DIB)
   //   VT_SCREENCONTOUR   = 2, // �������� ���������

   // ���������� ��������� �����
   //   VT_PRINT           = 3, // ���������� ��������� (����� WIN API)
   //   VT_PRINTGLASS      = 4, // ���������� ��� ������� ���������
   //   VT_PRINTCONTOUR    = 5, // ���������� ���������, ��� �������� ������

   // ���������� �������������� �����
   //   VT_PRINTRST        = 6, // ���������� �������������� (����� WIN API)
   //   VT_PRINTGLASSRST   = 7, // ���������� ��� ������� ���������
   //   VT_PRINTCONTOURRST = 8, // ���������� ���������, ��� �������� ������
}
  METAFILEBUILDPARM;


typedef struct METAFILEBUILDPARMEX  // ��������� �������� EMF-�����
{
  DFRAME Frame;     // �������� (�����)
  long Scale;       // ������� �����������
  char VisualType;  // ��� ������������ (�� VT_SCREEN �� VT_PRINTEX)
  char Border;      // ���� ��������� �����
  char Intensity;   // ������������� ������� % (0-100) 
  char Black;       // ���� �����-������ �����������(1 - ����, 0 - ���)

  char DontClip;    // �� �������� ��������� �������� �� ����� (!= 0)
                    // (��������, Corel9 �� �������� ::SelectClipRgn() )
  char Reserve[7];  // ������ (������ ���� �������)
}
  METAFILEBUILDPARMEX;

// ���� ������ ������ ������ ������� � ������
#define RMF_COMPR_LZW    1             // �������� ������ LZW ��� �������
#define RMF_COMPR_JPEG   2             // �������� ������ JPEG ��� 24 ������ �������
#define RMF_COMPR_32     32            // �������� ������ ��� ������


enum RST_STATE                   // ��������� ����� ������                      // 18/04/16
{
  RSTST_NONE              =   0,    // ��� ������; ��� �������� �� � ������ �� �����������
  RSTST_DUPL_JPEG         =   1,    // �������� ���� ������� ��, ������ JPEG ������
  RSTST_DUPL_LZW          =   2,    // �������� ���� ������� ��, ������ LZW ������

  RSTST_DUPL              =   4,    // �������� ���� ������� ��
};


enum MTW_STATE                   // ��������� ����� �������                     // 18/04/16
{
  MTWST_NONE              =   0,    // ��� ������; �������� �� � ������ �� �����������
  MTWST_DUPL_COMPR32      =   3,    // �������� ���� ������� ��, ������ RMF_COMPR_32 �������

  MTWST_DUPL              =   4,    // �������� ���� ������� ��
};

typedef struct XIMAGEDESC   // ��������� ������� ������� XImage
{                           // (��� ���������� � XWindow)   
  char *    Point;          // ����� ������ ������� ��������
  long int  Width;          // ������ ������ � ��������
  long int  Height;         // ����� �����
  long int  Depth;          // ������ �������� � ����� (8,15,16,24,32)
  long int  CellSize;       // ������ ��������(�������) � ������
  long int  RowSize;        // ������ ������ � ������
}
  XIMAGEDESC;


enum GRIDTYPE                // ��� �����
{
  GRT_NONE  =   0,           // �����������
  GRT_LINE  =   1,           // ����� �����
  GRT_NODE  =   2,           // ����� �����
  GRT_CROSS =   3,           // ����� �������
};

typedef struct _DLLCLASS GRIDPARM     // ��������� ���������� ������������� �����
{
  GRIDPARM()  { Step = 1000; Type = GRT_LINE;
                Image.Color = 0x040404; Image.Thick = 250;
                Size = 10*250; Shadow = 0; Under = 0; }

  double    Step;           // ��� ����� � ������ �� ���������
  long int  Type;           // ��� �������� (�����, �����, ������)
  struct
  {
   long int Color;
   long int Thick;
  }
            Image;          // ���� � ������� ����� (RGB, ���)
  long int  Size;           // ������ �������� ���� "�����" � ��� (1:250)
  long int  Shadow;         // ������� ��������������� �����������
  long int  Under;          // ������� ����������� ��� ������
}
  GRIDPARM;

typedef struct /*_DLLCLASS*/ GRIDPARMEX     // ��������� ���������� ������������� �����
{
  GRIDPARMEX()  { Step = 1000; Type = GRT_LINE;
                  Image.Color = 0x040404; Image.Thick = 250;
                  Size = 10*250; Shadow = 0; Under = 0; BeginX = 0; BeginY = 0; }

  double    Step;           // ��� ����� � ������ �� ���������
  long int  Type;           // ��� �������� (�����, �����, ������)
  struct
  {
   long int Color;
   long int Thick;
  }
            Image;          // ���� � ������� ����� (RGB, ���)
  long int  Size;           // ������ �������� ���� "�����" � ��� (1:250)
  long int  Shadow;         // ������� ��������������� �����������
  long int  Under;          // ������� ����������� ��� ������

  double    BeginX;         // ������ ��������� �����
  double    BeginY;
}
  GRIDPARMEX;

// ��������� ���������� ���� ���������
typedef struct TBUILDZONEVISIBILITY
{
  DOUBLEPOINT PointCenter;      // �������� �����
  double      RadiusMeter;      // ���������� (� ������ �� ���������)
  double      Azimuth;          // ����������� (� ��������)
  double      Angle;            // ���� ������ (� ��������)
                                // ��� Azimuth = 0, Angle = 2*M_PI (360 ��������)
                                // �������� �������� ����
  double      DeltaHight;       // ������ ���������� (� ������)
  double      DeltaObservation; // ���������� ����������� ����� (� ������)
  long int    VisionRst;        // ��������� ��� �����������
                                // 0-�� ���� �����, 1-���� �� � �����
  long int    StyleRst;         // ������� ��������� ������
                                // 0-����������, 1-��������������
                                // 2-�����������
  long int    ColorRst;         // ���� ������
  long int    Inversion;        // �������� ���������

}
  TBUILDZONEVISIBILITY;

enum PRECISIONFLAG              // �������� �������� ��������� �� �����
{
  PF_FLOAT  = 0,                // ���������� �������� � ���������
  PF_DOUBLE = 1,                // ���������� �������� � ���������
  PF_METRE  = 2,                // ���������� �������� � ������
  PF_GEO    = 4                 // ���������� �������� � ��������
};


enum TMCMODE               // ������ ������� � ������
{
  TMM_READ         = 1,    // ��������� ������ ������
  TMM_WRITE        = 2,    // ��������� �������������� ������
  TMM_COPY         = 4,    // ��������� ����������� ������ �� �������
  TMM_NOTPRINT     = 8,    // �������� ����� �� ������ �� �������     // 28/08/12
  TMM_CACHECODING  = 16,   // ��������� ��� ������ �������            // 21/09/12
  TMM_STREAMCODING = 32,   // ��������� ��������                      // 21/09/12
  TMM_TEMP         = 64,   // ������� ��������� ����� (������� ��� ��������)
  TMM_HIDEPASP     = 128,  // �������� ����� �������� �����           // 16/11/12
  TMM_RSCEDIT      = 256,  // ��������� �������������� �������������� // 27/12/12
  TMM_DOCSTORAGE   = 512,  // ��������� �������� ���������� � ������  // 09/02/13
  TMM_ADMIN        = 1024, // ��������� ����������������� ������
  TMM_MONITOR      = 2048, // �������� ���������� ��������� �������
  TMM_FOLDEREDIT   = 4096, // ��������� �������������� ������� ������ � �����  // 18/07/14
  TMM_GEODB        = 8192, // ��������� ����������� � ����� ������ �� � ���    // 14/08/15
};

#define TMM_STREAMCODING4K 33

enum OBM_TYPE              // ����� ������� ��������
{
  OBM_RECTANGLE    = 1,    // ������� ����� ����� ��������������� (�������������) ��������������
  OBM_CIRCLE       = 2,    // ������� ����� ����� ����������
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++ ��������� ��� �������� ������, ���� � ++++++++++++++++++
//++++++++ ���������������� ����                 ++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef struct APPENDPLANELIST
{
int  Length;              // ����� ������ ��������� APPENDLIST        // 26/03/12

char Nomenclature[32];    // ������������ �����
char ListName[32];        // �������� �������� �����
char FileName[256];       // ��� ����� �� �������� � ������ �����
                          // ������ ���� � ������ ������ � ������������
                          // HDR,DAT,SEM ...

int  Reserv;              // ������ ��� ������������, ������ ���� 0
                          // 17/10/01

// ������������� ���������� ����� � ������
// (��� ���������������� ����� (SITE) ������ ���� 0)

double XSouthWest   ;  // X �-�
double YSouthWest   ;  // Y �-�
double XNorthWest   ;  // X �-�
double YNorthWest   ;  // Y �-�
double XNorthEast   ;  // X �-�
double YNorthEast   ;  // Y �-�
double XSouthEast   ;  // X �-�
double YSouthEast   ;  // Y �-�
}
  APPENDPLANELIST;


typedef struct CREATEPLANE
{
int Length;              // ����� ������ ��������� CREATEPLANE   // 26/03/12

char MapName[32];         // ��� ������
long Scale;               // ����������� �������� �����

APPENDPLANELIST List;     // �������� ����� �����
}
  CREATEPLANE;


typedef struct CREATESITE
{
 long     Length;             // ����� ������ ��������� CREATESITE (80)
 char     MapName[32];        // ��� ������
 int      MapType;            // ���������� ��� �����
 int      MaterialProjection; // �������� ���. ���������
 int      Scale;              // ����������� �������� �����

                              // � ��������
 double FirstMainParallel;    // ������ ������� ���������
 double SecondMainParallel;   // ������ ������� ���������
 double AxisMeridian;         // ������ ��������
 double MainPointParallel;    // ��������� ������� �����
}
  CREATESITE;

typedef struct CREATESITEEX   // 11/05/07
{
 long     Length;             // ����� ������ ��������� CREATESITE (328)
 char     MapName[256];       // ��� ������ � ��������� ANSI (UNICODE - ��� ������� "Un")
 long int MapType;            // ���������� ��� �����
 long int MaterialProjection; // �������� ���. ���������
 long int EllipsoideKind;     // ��� ���������� (1 - �����������, 9 - WGS84,...)
 long     Scale;              // ����������� �������� �����
 long     Reserve;            // ������ (������ ���� 0)

                              // � ��������
 double FirstMainParallel;    // ������ ������� ���������
 double SecondMainParallel;   // ������ ������� ���������
 double AxisMeridian;         // ������ ��������
 double MainPointParallel;    // ��������� ������� �����
 double PoleLatitude;         // ������ ������ ��������
 double PoleLongitude;        // ������� ������ ��������
}
  CREATESITEEX;

typedef struct CREATESITEUN   // 11/05/07
{
 long     Length;             // ����� ������ ��������� CREATESITE
 WCHAR    MapName[128];       // ��� ������ � ��������� UNICODE (��� ������� "Un")
 long int MapType;            // ���������� ��� �����
 long int MaterialProjection; // �������� ���. ���������
 long int EllipsoideKind;     // ��� ���������� (1 - �����������, 9 - WGS84,...)
 long     Scale;              // ����������� �������� �����
 long     Reserve;            // ������ (������ ���� 0)

                              // � ��������
 double FirstMainParallel;    // ������ ������� ���������
 double SecondMainParallel;   // ������ ������� ���������
 double AxisMeridian;         // ������ ��������
 double MainPointParallel;    // ��������� ������� �����
 double PoleLatitude;         // ������ ������ ��������
 double PoleLongitude;        // ������� ������ ��������
}
  CREATESITEUN;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++ ��������� ���������� 4 ������ �� ������������ ++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef union
{
  struct
  {
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
  }
    Byte;              // ������������� � ���� 8-������� �����

  struct
  {
    unsigned short w1;
    unsigned short w2;
  }
    Word;              // ������������� � ���� 16-������� �����

  unsigned int Long;  // ������������� � ���� 32-�������� ����   // 26/03/12
  float        Float; // ������������� � ���� 32-�������� ����   // 16/08/12

  int Value() { return (int) Long; }

  // ��������� �������� (long)
  int GetLong(int & value)
  {
    return (int)(Long = (unsigned int)value);
  }

  // ��������� �������� (long)
  int GetLong(unsigned int & value)
  {
    return (int)(Long = value);
  }

  // ��������� �������� (long) �� ������ address (4 �����)
  long GetLong(const char* address)
  {
#ifdef RISCCPU
    Byte.b1 = address[0];
    Byte.b2 = address[1];
    Byte.b3 = address[2];
    Byte.b4 = address[3];
#else
    Long = *((unsigned int *)address);
#endif
    return (int)Long;
  }

  // ��������� �������� (long) �� ������ address (4 �����)
  // � �������� ������������������ ����
  int GetTurnLong(int & value)
  {
    return GetTurnLong((char *)&value);
  }

  // ��������� �������� (long) �� ������ address (4 �����)
  // � �������� ������������������ ����
  int GetTurnLong(unsigned int & value)
  {
    return GetTurnLong((char *)&value);
  }

  // ��������� �������� (long) �� ������ address (4 �����)
  // � �������� ������������������ ����
  int GetTurnLong(char* address)
  {
    Byte.b4 = address[0];
    Byte.b3 = address[1];
    Byte.b2 = address[2];
    Byte.b1 = address[3];
    return (int)Long;
  }

  // ���������� �������� (long) �� ������ address (4 �����)
  int PutLong(int & value)
  {
    return (value = (int)Long);
  }

  // ���������� �������� (long) �� ������ address (4 �����)
  int PutLong(unsigned int & value)
  {
    return (int)(value = (unsigned int)Long);
  }

  // ���������� �������� (long) �� ������ address (4 �����)
  int PutLong(char* address)
  {
#ifdef RISCCPU
    address[0] = Byte.b1;
    address[1] = Byte.b2;
    address[2] = Byte.b3;
    address[3] = Byte.b4;
#else
    *((unsigned int *)address) = Long;
#endif
    return (int)Long;
  }

  // ��������� �������� (float)
  float GetFloat(float & value)
  {
    return (Float = value);
  }

  // ��������� �������� (float) �� ������ address (4 �����)
  float GetFloat(const char* address)
  {
#ifdef RISCCPU
    Byte.b1 = address[0];
    Byte.b2 = address[1];
    Byte.b3 = address[2];
    Byte.b4 = address[3];
#else
    Float = *((float *)address);
#endif
    return Float;
  }

  // ���������� �������� (float) �� ������ address (4 �����)   // 16/08/12
  float PutFloat(float & value)
  {
    return (value = Float);
  }

  // ���������� �������� (float) �� ������ address (4 �����)   // 16/08/12
  float PutFloat(char* address)
  {
#ifdef RISCCPU
    address[0] = Byte.b1;
    address[1] = Byte.b2;
    address[2] = Byte.b3;
    address[3] = Byte.b4;
#else
    *((float *)address) = Float;
#endif

    return Float;
  }

  // ��������� �������� (short int)
  int GetShort(short int & value)
  {
    return GetShort((char *)&value);
  }

  // ��������� �������� (short int)
  int GetShort(unsigned short int & value)
  {
    return GetShort((char *)&value);
  }

  // ��������� �������� (int) �� ������ address (2 �����)
  int GetShort(char* address)
  {
    Long = 0;
#ifdef RISCCPU
#ifdef NUMBERTURN              // 04/03/00
    Byte.b3 = address[0];
    Byte.b4 = address[1];
#else
    Byte.b1 = address[0];
    Byte.b2 = address[1];
#endif
#else
    Word.w1 = *((unsigned short *)address);
#endif
    return (int)Long;
  }

  // ��������� �������� (int) �� ������ address (2 �����)
  // � �������� ������������������ ����
  int GetTurnShort(short int & value)
  {
    return GetTurnShort((char *)&value);
  }

  // ��������� �������� (int) �� ������ address (2 �����)
  // � �������� ������������������ ����
  int GetTurnShort(unsigned short int & value)
  {
    return GetTurnShort((char *)&value);
  }

  // ��������� �������� (int) �� ������ address (2 �����)
  // � �������� ������������������ ����
  int GetTurnShort(char* address)
  {
    Long = 0;
#ifdef NUMBERTURN
    Byte.b4 = address[0];
    Byte.b3 = address[1];
#else
    Byte.b2 = address[0];
    Byte.b1 = address[1];
#endif
    return (int)Long;
  }

  // ���������� �������� (short int)
  int PutShort(short int & value)
  {
    return PutShort((char *)&value);
  }

  // ���������� �������� (short int)
  int PutShort(unsigned short int & value)
  {
    return PutShort((char *)&value);
  }

  // ���������� �������� (int) �� ������ address (2 �����)
  int PutShort(char* address)
  {
#ifdef RISCCPU
#ifdef NUMBERTURN              // 04/03/00
    address[0] = Byte.b3;
    address[1] = Byte.b4;
#else
    address[0] = Byte.b1;
    address[1] = Byte.b2;
#endif
#else
    *((unsigned short *)address) = Word.w1;
#endif
    return (int)Long;
  }
}
  REGISTER;

// ����������� ��� � (REGISTER , char*) :

#if defined(__BORLANDC__) // ��� Borland C++

#define LongToRegister(register, point) register.Long = ((long *)point)[0];

#else

#define LongToRegister(register, point) { register.Byte.b1 = ((char *)point)[0]; \
                                          register.Byte.b2 = ((char *)point)[1]; \
                                          register.Byte.b3 = ((char *)point)[2]; \
                                          register.Byte.b4 = ((char *)point)[3]; }
#endif

#define TurnLongToRegister(register, point) { register.Byte.b4 = ((char *)point)[0]; \
                                              register.Byte.b3 = ((char *)point)[1]; \
                                              register.Byte.b2 = ((char *)point)[2]; \
                                              register.Byte.b1 = ((char *)point)[3]; }

// 04/02/16 Korjilov
#define TurnLong24ToRegister(register, point) { register.Byte.b4 = 0; \
                                                register.Byte.b3 = ((char *)point)[0]; \
                                                register.Byte.b2 = ((char *)point)[1]; \
                                                register.Byte.b1 = ((char *)point)[2]; }

#define RegisterToLong(register, point) { ((char *)point)[0] = register.Byte.b1; \
                                          ((char *)point)[1] = register.Byte.b2; \
                                          ((char *)point)[2] = register.Byte.b3; \
                                          ((char *)point)[3] = register.Byte.b4; }

#define TurnRegisterToLong(register, point) { ((char *)point)[0] = register.Byte.b4; \
                                              ((char *)point)[1] = register.Byte.b3; \
                                              ((char *)point)[2] = register.Byte.b2; \
                                              ((char *)point)[3] = register.Byte.b1; }

#ifdef NUMBERTURN
#define ShortToRegister(register, point) {register.Long    = 0;        \
                                          register.Byte.b3 = ((char *)point)[0]; \
                                          register.Byte.b4 = ((char *)point)[1]; }

#define RegisterToShort(register, point) {((char *)point)[0] = register.Byte.b3; \
                                          ((char *)point)[1] = register.Byte.b4; }

#else
#define ShortToRegister(register, point) {register.Long    = 0;        \
                                          register.Byte.b1 = ((char *)point)[0]; \
                                          register.Byte.b2 = ((char *)point)[1]; }

#define RegisterToShort(register, point) {((char *)point)[0] = register.Byte.b1; \
                                          ((char *)point)[1] = register.Byte.b2; }
#endif

#ifdef NUMBERTURN
#define TurnShortToRegister(register, point) {register.Long    = 0;    \
                                          register.Byte.b4 = ((char *)point)[0]; \
                                          register.Byte.b3 = ((char *)point)[1]; }
#else
#define TurnShortToRegister(register, point) {register.Long    = 0;    \
                                          register.Byte.b2 = ((char *)point)[0]; \
                                          register.Byte.b1 = ((char *)point)[1]; }
#endif

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++ ��������� ���������� 8 ������ �� ������������ ++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef union
{
  struct
  {
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
  }
    Byte;              // ������������� � ���� 8-������� �����

  double Double;  //  ������������� � ���� 64-�������� ����

  double Value() { return Double; }

  // ��������� �������� (double) �� ������ address (8 ����)
  double GetDouble(double & value)
  {
    return GetDouble((char *)&value);
  }

  // ��������� �������� (double) �� ������ address (8 ����)
  double GetDouble(const char* address)
  {
#ifdef RISCCPU
    Byte.b1 = address[0];
    Byte.b2 = address[1];
    Byte.b3 = address[2];
    Byte.b4 = address[3];
    Byte.b5 = address[4];
    Byte.b6 = address[5];
    Byte.b7 = address[6];
    Byte.b8 = address[7];
#else
    Double = *((double *)address);
#endif
    return (double)Double;
  }

  // ��������� �������� (double) �� ������ address (8 ����)
  // � �������� ������������������ ����
  double GetTurnDouble(double & value)
  {
    return GetTurnDouble((char *)&value);
  }

  // ��������� �������� (double) �� ������ address (8 ����)
  // � �������� ������������������ ����
  double GetTurnDouble(const char* address)
  {
    Byte.b8 = address[0];
    Byte.b7 = address[1];
    Byte.b6 = address[2];
    Byte.b5 = address[3];
    Byte.b4 = address[4];
    Byte.b3 = address[5];
    Byte.b2 = address[6];
    Byte.b1 = address[7];
    return (double)Double;
  }

  // ���������� �������� (double) �� ������ address (8 ����)
  double PutDouble(double & value)
  {
    return PutDouble((char *)&value);
  }

  // ���������� �������� (double) �� ������ address (8 ����)
  double PutDouble(char* address)
  {
#ifdef RISCCPU
    address[0] = Byte.b1;
    address[1] = Byte.b2;
    address[2] = Byte.b3;
    address[3] = Byte.b4;
    address[4] = Byte.b5;
    address[5] = Byte.b6;
    address[6] = Byte.b7;
    address[7] = Byte.b8;
#else
    *((double *)address) = Double;
#endif
    return (double)Double;
  }
}
  DOUBLEREGISTER;

// ����������� ��� � (DOUBLEREGISTER , char*) :

#define DoubleToRegister(register, point) { register.Byte.b1 = ((char *)point)[0]; \
                                          register.Byte.b2 = ((char *)point)[1]; \
                                          register.Byte.b3 = ((char *)point)[2]; \
                                          register.Byte.b4 = ((char *)point)[3]; \
                                          register.Byte.b5 = ((char *)point)[4]; \
                                          register.Byte.b6 = ((char *)point)[5]; \
                                          register.Byte.b7 = ((char *)point)[6]; \
                                          register.Byte.b8 = ((char *)point)[7]; }

#define TurnDoubleToRegister(register, point) { register.Byte.b8 = ((char *)point)[0]; \
                                              register.Byte.b7 = ((char *)point)[1]; \
                                              register.Byte.b6 = ((char *)point)[2]; \
                                              register.Byte.b5 = ((char *)point)[3]; \
                                              register.Byte.b4 = ((char *)point)[4]; \
                                              register.Byte.b3 = ((char *)point)[5]; \
                                              register.Byte.b2 = ((char *)point)[6]; \
                                              register.Byte.b1 = ((char *)point)[7]; }

#define RegisterToDouble(register, point) { ((char *)point)[0] = register.Byte.b1; \
                                          ((char *)point)[1] = register.Byte.b2; \
                                          ((char *)point)[2] = register.Byte.b3; \
                                          ((char *)point)[3] = register.Byte.b4; \
                                          ((char *)point)[4] = register.Byte.b5; \
                                          ((char *)point)[5] = register.Byte.b6; \
                                          ((char *)point)[6] = register.Byte.b7; \
                                          ((char *)point)[7] = register.Byte.b8; }

// ��������� �������� (short int)

#if !defined(WINCE) && !defined(NUMBERTURN)   
  #define GetWordValue(value) ((int)((unsigned short) value))
#else
  inline int GetWordValue(long int value) 
   {
     REGISTER Register;
     return Register.GetShort((char *)&value);
   }
#endif


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++   C�������� �������� ����������� �������   ++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef struct PALETTE256
{
  WORD         palVersion;
  WORD         palNumEntries;
  PALETTEENTRY palPalEntry[256];
}
  PALETTE256;

// ������ ������������ �������� DIB

typedef unsigned int  CELL;
#define CELLSIZE      4

// ----------------------------------------------------------------
// C�������� �������� � ������� ����������� ��������
// ��� ������� ���� � ���. (��. MAPGDI.H)
// ��� ������� � �������� - ������� ����� �����
// ���� ������ "���������" - TwoPoint = 1, ����� - 0;
// ��� "���������������" ������� - ������� 0;
// ----------------------------------------------------------------

typedef struct IMAGESIZE
{
   unsigned int Number;          // ����� ������� �����������               // 26/03/12
   unsigned int Base  ;          // ������ ���� �������
            int DeltaH;          // ���������� �� ������ ��������
            int DeltaV;          // ���� ��������� �� ����(�����
                                  // �������) �������
   unsigned int HorizontalSize;  // ������� �� �����������
   unsigned int VerticalSize  ;  // ������� �� ���������

   unsigned int Horizontal : 1;  // ���������� �������������
   unsigned int Vertical   : 1;  // ���������� �����������
   unsigned int TwoPoint   : 1;  // ������� �� 2 �����
   unsigned int AlignV     : 2;  // ������������ �� ���������
   unsigned int AlignH     : 2;  // ������������ �� �����������
   unsigned int Wide       : 2;  // ������ ������
   unsigned int Type       : 8;  // ��� ������ (0-4)
   unsigned int Italic     : 1;  // ������ �������� 
   unsigned int Rezerv     :14;  // ������
}
  IMAGESIZE;

// ----------------------------------------------------------------
// C�������� ����������� ���������� ����� ����������� �������
// � ���� ������������ ��������������. ��� ������� ���� � ���
// �� ����������� ����� � ������� �������� ������������ ������
// ����� ������� �������. ����������� ���� ���������������� (X �����,
// Y ������).
// ----------------------------------------------------------------

typedef struct IMAGEFRAME
{
   DOUBLEPOINT LeftTop;          // ���������� ������ ����� � ���
   DOUBLEPOINT RightTop;         // ���������� ������ ����� � ���
   DOUBLEPOINT RightBottom;      // ���������� ������� ����� � ���
   DOUBLEPOINT LeftBottom;       // ���������� ��������� ����� � ���
}
  IMAGEFRAME;

// ----------------------------------------------------------------
// ������� ��������� ������
// ----------------------------------------------------------------

typedef long int (WINAPI * BREAKCALLEX)(void * parm, long int isrepaint); 
typedef long int (WINAPI * EVENTSTATE)(void * parm, long int percent); // 09/03/16
typedef long int (WINAPI * BREAKCALL)(void * parm);                    // 07/06/16
typedef long int (WINAPI * BEFOREPAINT)
                 (void * parm, HDC hdc, RECT * rect);
typedef long int (WINAPI * MASKCALL)(void *  parm);
typedef long int (WINAPI * EVENTCALL)(void * parm, HPARAM value1,
                                      HPARAM value2, HPARAM value3);
typedef long int (WINAPI * MESSAGEBOXCALL)(void * parm, HWND hwnd,
                                           const WCHAR * message, const WCHAR * title,
                                           long int flag);

#ifdef LINUXAPI
// ------------------------------------------------------------------
//  ������� MessageBox ��� LINUX
// ------------------------------------------------------------------
typedef int (WINAPI * MESSAGEBOX)(HWND hwnd, const TCHAR * message,
                           const TCHAR * title, int flag);
#endif

// ----------------------------------------------------------------
//  ���� ������ ��������� � ������� ����
// ----------------------------------------------------------------

enum MAPAPILANGUAGE
{
  ML_ENGLISH   = 1,  // ����������
  ML_RUSSIAN   = 2,  // �������
  ML_FRENCH    = 3,  // �����������
  ML_SPANISH   = 4,  // ���������
  ML_UKRAINIAN = 5,  // ����������
  ML_LAST      = 5,  // ��������� ���  // 23/10/15
};

// ----------------------------------------------------------------
//  �������������� ������ (WM_COMMAND)
// ----------------------------------------------------------------

#define WM_ERRORCOORD   0x583    // ���������� � ������� ��������
#define WM_INFOLIST     0x584    // ���������� � �����
#define WM_OBJECT       0x585    // ����� �������
#define WM_LIST         0x586    // ����� �����
#define WM_ERROR        0x587    // ���������� �� ������� ��� ������ � ���-����
#define WM_MAP          0x588    // ����� ������� �����
#define WM_ERRORSXF     0x589    // ���������� �� ������� ��������� SXF

// ----------------------------------------------------------------
//  �������������� ���������
// ----------------------------------------------------------------
#define WM_PROGRESSBAR  0x590    // ��������� � ��c������ �������� 
                                 // wparam - (-1 - �����), (-2 - ����), % ���������� 
                                 // lparam - ����������� (����� � ��������� ���������� ANSI \ UNICODE)
                                 // ���� ����������� � % ���������� �� �����, �� ������� ESC �� �������� � ������� � ���������� ��������
                                 // ��� ���������� ���������� WM_PROGRESSBAR

#define WM_MAPEVENT     0x591    // ��������� � �������� �����
#define WM_PROGRESSICON 0x592    // ��������� � ��c������ ��������
                                 // ��� ����������� � ������ ���������
                                 // ��� ��������� ������� ����
#define WM_PROGRESSBARUN 0x593   // ��������� � ��c������ �������� 
                                 // wparam - (-1 - �����), (-2 - ����), % ���������� 
                                 // lparam - ����������� (����� � ��������� UNICODE)
                                 // ���� ����������� � % ���������� �� �����, �� ������� ESC �� �������� � ������� � ���������� ��������
                                 // ��� ���������� ���������� WM_PROGRESSBAR


// ----------------------------------------------------------------
//  �������������� ��������� (MESSAGE)
// ----------------------------------------------------------------

#define WM_LEFTTOPPOINT 0x600    // C�������� ���� ����� �� ������
                                 // ������ ��������� �������� ������
                                 // ���� ���� ����� � �������� �����������
                                 // wparam : (POINT * point)        
                                 // lparam : 0
                                 // result : 0x600

#define WM_MOVEDOC      0x601    // C�������� ���� ����� �� ������
                                 // �������� �� �������������
                                 // ����������� ����������� ����� � ��������
                                 // �����, ���������� �������� ������ ���� ����
                                 // ����� � �������� �����������
                                 // wparam : (POINT * point)     
                                 // lparam : 0 ��� (POINT * marker)
                                 // ���������� �������,������������ �� �����������
                                 // result : 0x601

#define WM_OPENDOC      0x602    // C�������� ���� ���������� ��� ����� �� ������
                                 // �������� �� �������������
                                 // ������� ����� �� ����� ����� (MAP,MTW,RSW,...)
                                 // wparam : (const char * name)
                                 // lparam : 0 ��� (DOUBLEPOINT * point),
                                 // ���������� � ������ �����, ������� �����
                                 // �������� � ������ ���� �����
                                 // result : 0x602

#define AW_CLOSEDIALOGNOTIFY 0x610 // C�������� �������� ���� � �������� �������
                                   // �������� �� ������������� ������� �������
                                   // �������� ������� �� ���������
                                   // wparam : 0                    
                                   // lparam : ��������� �������
                                   // result : 0x610   

// --------------------------------------------------------------
//  ��������� ��� ������ ���������� �����
// --------------------------------------------------------------

typedef struct TASKPARM        // ��������� ���������� ������
{
  long int    Language;        // ��� ����� �������� (1 - ENGLISH,
                               // 2 - RUSSIAN, ...)
#if defined(_M_X64) || defined(BUILD_DLL64)      
#ifdef WIN32API
  long int    Zero;            // ������������ ����������
#endif
#endif
  HINSTANCE   Resource;        // ������ �������� ����������
  const char* HelpName;        // ������ ��� ����� ".hlp"
  const char* IniName;         // ������ ��� ����� ".ini" ����������
  const char* PathShell;       // ������� ���������� (exe,dll,...)
  const char* ApplicationName; // ��� ����������
#ifdef WIN32API
  HWND        Handle;          // ������������� �������� ���� ����������
#else
  MSGHANDLER  Handle;          // ������������� ����������� ������ �������� ���� ����������
#endif
}
  TASKPARM;

typedef struct TASKPARMEX      // ��������� ���������� ������
{
  long int    Language;        // ��� ����� �������� (1 - ENGLISH,
                               // 2 - RUSSIAN, ...)
#if defined(_M_X64) || defined(BUILD_DLL64)     
#ifdef WIN32API
  long int    Zero;            // ������������ ����������
#endif
#endif
  HINSTANCE   Resource;        // ������ �������� ����������
  const char* HelpName;        // ������ ��� ����� ".hlp"
  const char* IniName;         // ������ ��� ����� ".ini" ����������
  const char* PathShell;       // ������� ���������� (exe,dll,...)
  const char* ApplicationName; // ��� ����������
#ifdef WIN32API
  HWND        Handle;          // ������������� �������� ���� ����������
#else
  MSGHANDLER  Handle;          // ������������� ����������� ������ �������� ���� ����������
#endif
  HWND        DocHandle;       // ������������� ���� ����� (���������)
  long int    StayOnTop;       // ������� ����������� ����� �������� StayOnTop  
}
  TASKPARMEX;

// --------------------------------------------------------------
//  ��������� ��� �������������� � ���-��������
// --------------------------------------------------------------

#define HOSTALIAS    "HOST#"
#ifdef WIN32API                     // 18/02/13
#define WHOSTALIAS   L"HOST#"
#else
#ifdef BUILD_DLL
#define WHOSTALIAS   L"HOST#"
#else
#define WHOSTALIAS   "H\0O\0S\0T\0#\0"
#endif
#endif
#define HOSTSIZE     5

#define MAPALIAS     "ALIAS#"
#ifdef WIN32API                     // 18/02/13
#define WMAPALIAS    L"ALIAS#"
#else
#ifdef BUILD_DLL
#define WMAPALIAS    L"ALIAS#"
#else
#define WMAPALIAS    "A\0L\0I\0A\0S\0#\0"
#endif
#endif
#define ALIASSIZE    6

#define DOCALIAS     "DOC#"
#ifdef WIN32API                     // 18/02/13
#define WDOCALIAS    L"DOC#"
#else
#ifdef BUILD_DLL
#define WDOCALIAS    L"DOC#"
#else
#define WDOCALIAS    "D\0O\0C\0#\0"
#endif
#endif
#define DOCALIASSIZE 4

typedef struct TMCUSERPARM  // ��������� ������������
{
  char Name[32];            // ��� (��������� ANSI)
  char Password[64];        // ������
}
  TMCUSERPARM;

typedef struct TMCMAPLISTITEM
{
  unsigned int Level;      // ������� ����������� �������� � 1 �� MaxLevel    // 26/03/12
  unsigned int Flags;      // ���� ��������������, 0 - ��� ���� �������������
  unsigned int Type;       // ��� ����� MAPFILES ��� 0 ��� �������������� ������
  unsigned int Size;       // ������ ������ �����                             // 26/06/14
  char Name[256];          // ��� �������� (�����)
}
  TMCMAPLISTITEM;

typedef struct TMCMAPLIST   // ������ ��������� ����
{
  TMCMAPLIST() { Init(); }

  void Init() {  Ident = 0x7F7F7F7F;
                 Length = sizeof(TMCMAPLIST);
                 Count = 0; MaxLevel = 1; }

  int Ident;           // ������������� ������ 0x7F7F7F7F                         // 26/03/12
  int Length;          // ����� ����� ������
  int Count;           // ����� ��������� � ������
  int MaxLevel;        // ������������ ������� ����������� ��������� (������)
  TMCMAPLISTITEM Item[1];   // ������ ��������� ������ ��������� ���� (� ���������� Count)
}
  TMCMAPLIST;

#define TMCDATAIDENT  0x7FFF7FFF

typedef struct TMCDATALISTITEM
{
  unsigned int Ident;      // 0x7FFF7FFF
  unsigned int Length;     // ������ ������ ������
  unsigned int Level;      // ������� ����������� �������� � 1 �� MaxLevel
  unsigned int Flags;      // ���� ��������������, 0 - ��� ���� �������������
  unsigned int Type;       // ��� ����� MAPFILES ��� -1 - ����� ��� 0 - �����������
  unsigned int Size;       // ������ ������ �����
  unsigned int Date;       // ���� ���������� � ������� YYYYMMDD
  unsigned int Time;       // ����� ���������� - ����� ������ �� 00:00:00
  WCHAR        Name[2];    // ��� �������� (����� ��� �����) ���������� �����
}
  TMCDATALISTITEM;

typedef struct TMCDATALIST   // ������ ������ � �����                             // 26/06/14
{
  TMCDATALIST() { Init(); }

  void Init() {  Ident = 0x7F7F7F7F;
                 Length = sizeof(TMCDATALIST);
                 Count = 0; MaxLevel = 1; }

  int Ident;           // ������������� ������ 0x7F7F7F7F       
  int Length;          // ����� ����� ������
  int Count;           // ����� ��������� � ������
  int MaxLevel;        // ������������ ������� ����������� ��������� (������)
  TMCDATALISTITEM Item[1];   // ������ ��������� ������ ��������� ���� (� ���������� Count)
}
  TMCDATALIST;

// ��������� ������ � ��������� ����������� � ��� ������
typedef struct GSMONITOR
{
  int Ident;          // 0x7F7F7F7F                          
  int Length;         // ����� ����� ������ � ������
  int Version;        // ������ ��� ������� 0x0T112233 11.22.33 (T=1,x64)
  int Count;          // ����� ������������ ��������
  int State;          // ��������� ������������ ��������
  char BeginTime[32]; // ����� ������ ��� �������
  char ParmName[256]; // ��� ����� ����������
  int MapEdit;        // ����� ����� ����, �������� �� ��������������
  int MapRead;        // ����� ����� ����, �������� �� ������
  int MapCopy;        // ����� ����� ����, ����������� � �����������
  int RswEdit;        // ����� ����� �������, �������� �� ��������������
  int RswRead;        // ����� ����� �������, �������� �� ������
  int RswCopy;        // ����� ����� �������, ����������� � �����������
  int MtwEdit;        // ����� ����� ������, �������� �� ��������������
  int MtwRead;        // ����� ����� ������, �������� �� ������
  int MtwCopy;        // ����� ����� ������, ����������� � �����������
  int MapNotPrint;    // ����� ����� ����, �� ����������� � ������
  int RswNotPrint;    // ����� ����� �������, �� ����������� � ������
  int MtwNotPrint;    // ����� ����� ������, �� ����������� � ������

//���� ����� ������������� > 32 - ���������� GSMUSERSHORT
//GSMUSEREX    User[1];    // ������ ������ � ����������� �������������
//GSMUSERSHORT  User[1];   // ������ ������ � ����������� �������������
}
  GSMONITOR;

// --------------------------------------------------------------
//  ��������� ��� ������ ������
// --------------------------------------------------------------

enum INSETPLACE      // ������ �������� ������
{
   INP_TOTAL   = 0,  // ���������� ��� ������ � �������� ����
   INP_FRAME   = 1,  // ���������� ��������� �������� � �������� ��������
};

typedef struct INSETDESC    // �������� �������� ������ ������
{
  INSETDESC()
  {
    Ident       = 0;
    Path[0]     = 0;
    Name[0]     = 0;
    Scale       = 100000;
    TopScale    = 40000000;
    BottomScale = 1;
    View        = 1;
    BackColor   = 0x07F7F7F;
    BorderColor = 0;
    Transparence= 0;
    BorderThick = 260;
    BorderView  = 1;
    PlaceFlag   = INP_TOTAL;
    FirstPlace  = 0;
    SecondPlace = 0;
    PlaceType   = PP_PLANE;
    Scheme      = 0; 
  }

  int         Length;       // ������ ������ ���������
  int         Ident;        // ������������� ��������
  WCHAR       Path[1024];   // ������ ���� � ����� ������
  WCHAR       Name[128];    // �������� �������� ������ (������������� �� ������)

                            // ���������� � ������� ��������� ��������� (�����)
  DOUBLEPOINT FirstPlace;   // ���������� �������� ������ �������� ����
  DOUBLEPOINT SecondPlace;  // ���������� �������� ������� ������� ����
                            // ���������� � ������� ������ ������ ��� INP_FRAME (�����)
  DOUBLEPOINT FramePlace;   // ���������� ����� �������� (����� ��������� � ������� ������)
  int         PlaceFlag;    // ������ �������� (INP_TOTAL, INP_FRAME)
  int         PlaceType;    // ������� ��������� ��������
                            // (PP_PLANE - �������������, PP_GEO - �������������� WGS84)

  int         Scale;        // ������� ����������� (������������� �� ������ ��� INP_FRAME)
  int         TopScale;     // ����������� �������� ������� ������� ���������
  int         BottomScale;  // ����������� �������� ������ ������� ���������
  int         View;         // ������� ��������� ������

  int         Scheme;       // ������� ����������� ������ � ���� �����
  int         BackColor;    // ���� ���� ���� ������
  int         Transparence; // ������� ������������ ����
  int         BorderColor;  // ���� ����� ����
  int         BorderThick;  // ������� �����
  int         BorderView;   // ������� ����������� �����
}
  INSETDESC;


// --------------------------------------------------------------
// ������ ��������� �� ������
// code - ��� ������ (��. MAPERR.RH)
// --------------------------------------------------------------
extern "C"
{
  _MAPIMP void _MAPAPI ErrorMessage(int code,const char * filename); 
}

enum MESSAGETYPE
{
  MT_INFO     = 0,    // �������������� ���������
  MT_ERROR    = 1,    // ��������� �� ������
  MT_WARNING  = 2,    // �������������� ���������
  MT_CONTINUE = 4,    // ����������� ����������� ���������
					  // (�� ��� �� ������)
};

// --------------------------------------------------------------
// �������� �������� ��� ������ � ����
// --------------------------------------------------------------

#define MENUEXTENDIDENT   0x7FFF7FFF

typedef struct MENUEXTEND         // �������� ������� ����
{
  long int Ident;                 // ����� ������ ������ 0x7FFF7FFF
  long int Count;                 // ����� ������� ����
  struct
  {
   long int Command;              // ������������� ������� (-1 ��� �����������)
   long int Check;                // ������� ��������� ������ �������� (0/1)
   char     Text[32];             // ����� ������ ����
  }
   Item[32];
}
  MENUEXTEND;

typedef struct COMMANDENABLER     // ������ ��������� ������ ���� ��� ������
{
  const WCHAR * SetText(const WCHAR * text)
  { if (text) WcsCopy(Text, text, sizeof(Text)); else Text[0] = 0;
    return Text; }
 
  long int     Command;           // ������������� ������� (-1 ��� �����������)
  long int     Enable;            // ������� ����������
  long int     Check;             // ������� ����������� "�������" - 1, ������ - 0
#if defined(_M_X64) || defined(BUILD_DLL64)
  long int     Zero;              // ������������
#endif
  MENUEXTEND * Menu;              // ������ ����, ������� ����������� �� �������
  WCHAR        Text[256];         // ����� ����� ������ ����                         // 15/08/14
}
  COMMANDENABLER;

typedef struct VIEWHELPEX         // ������ �� ����������� HELP (AW_VIEWHELPEX)
{
  const char * HelpName;          // ��� ����� HELP
  long int     Topic;             // ����� �������
}
  VIEWHELPEX;


typedef struct CONTROLMENU        // ��������/�������/����������/���������... ����� �������� ���� (AW_MENUCONTROL)
{                                 // WPARAM=MC_APEENDMENU,MC_DELETEMENU...,LPARAM=CONTROLMENU* 
  char Name[32];                  // ��� ������ ���� (�������������)
  char Caption[64];               // �������� ������ ���� (������������ �� ������)     
  char After[32];                 // ��� ������ ����, �� ������� ����������� ������ ����� ("MenuFile","MenuView"...)
}                                 // ���� ����� 0, �� � �����, ���� ������ #, �� �� ��� ���������� ����� � 1,
  CONTROLMENU;                    // ������� ����� �������� ������ �����

typedef struct CONTROLITEM        // ��������/�������... �������� �������� ���� (AW_MENUCONTROL)
{                                 // WPARAM=MC_APPENDMENUITEM..,LPARAM=CONTROLITEM*
  char Name[32];                  // ��� ������ ���� (�������������) ("MenuFile","MenuView"...,"MenuTask"...)
  char Caption[64];               // �������� ��������� ���� (������������ �� ������)    
  long int Item;                  // �������� ������������� ������� (���������� ������ ��� ������ ������ ����)
  long int SubItem;               // �������� ������������� ������� (���������� ������ ��� ������ ��������� ����)
  long int After;                 // ������������� ������/��������� �� ������� ����������� ����� ����,
				  // 0 - � �����, -1 - � ������, -2 - ������ � �.�.
#if defined(_M_X64) || defined(BUILD_DLL64)
  long int     Zero;              // ������������
#endif
}
  CONTROLITEM;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++  �������� �������� �������������� (RSC)                   +++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// ����������� ��'���� (���)
enum OBJECT_LOCAL { LOCAL_LINE = 0,  LOCAL_SQUARE = 1, LOCAL_POINT = 2,
					LOCAL_TITLE = 3, LOCAL_VECTOR = 4, LOCAL_MIXED = 5 };

// ����������� ���������� ��'����
enum OBJECT_DIRECT       // �������� �� 0 �� OD_LAST    // 26/12/12
{
   OD_NONE      = 0,     // ������������. ������������:
						 // - ��� ��������;
						 // - ��� �������� ��������, ����������� �������� �������
						 //   �� ����� �������� (�������� ������);
						 // - ��� ��������� ������, ����������� �������
						 //   ����������� ������������ ������� ����� ����� (�����)

   OD_ALONG     = 1,     // ����������� (����� �������). ������������:
						 // - ��� ��������;
						 // - ��� �������� ��������, ������� ����������� �����������
						 //   �������� (�������� ���� - �� ������ � �����);
                         // - ��� ��������� ������, ������� ����������� �����������

   OD_UNDEFINED = 1,     // �� ����������. ���������� ������� ������� �����������
                         // ������� ������� � ������, ����� ������ ��������� ���
                         // ����� ������� ������� (�������� � ����� ��� ����� "�����")

   OD_RIGHT     = 2,     // ������ ������ �� �������. ������������ ��� ���������:
                         //   �������� ������ - �� ������� �������;
                         //   ����������      - ������ ������� �������

   OD_LOWRIGHT  = 3,     // ������ ����. ������������ ��� ������������.
                         // ��������� ����������� � ������������:
                         // - �� ������� ������� ������������ ���;
                         // - ������ ������� ������� ������������ ����

   OD_LEFT      = 4,     // ������ ����� �� �������. ������������ ��� ���������:
                         //   �������� ������ - ������ ������� �������
                         //   ����������      - �� ������� �������

   OD_CLOCKWISE = 5,     // ��� ������� ������� ��������� �� ������� �������  //23/01/12

   OD_ANTICLOCKWISE = 6, // ��� ������� ������� ��������� ������ ������� �������

   OD_LAST      = 6,     // ��������� ���������� ��� �����������
};

// ������ ��������� ��'����      //01/03/01

enum { ABR_APPEND   = 0,  // �������� ����� � ����� �������
                            // �� ���������, ���� ������ �������
       ABR_LAST     = 1,  // �������� ��������� �����
       ABR_FIRST    = 2,  // �������� ������ �����
       ABR_ADDLAST  = 3,  // �������� ����� � ����� �������
       ABR_ADDFIRST = 4   // �������� ������ �����
     };

#define  OTHERSCALERSC  10000L
#define  MAXSCALERSC  40000000L

// ��������� ��� �������� ��������������
typedef struct RSCCREATE
{
  char Name[32]; // �������� ��������������
  char Type[32]; // ��� ��������������
  char Code[8];  // ��� ��������������
  int  Scale;    // ����������� ��������
  int  Language; // ���� (MAPAPILANGUAGE)
}
  RSCCREATE;

typedef struct RSCCREATEUN
{
  WCHAR Name[32]; // �������� �������������� � UNICODE
  WCHAR Type[32]; // ��� �������������� � UNICODE
  WCHAR Code[8];  // ��� �������������� � UNICODE
  int   Scale;     // ����������� ��������
  int   Language;  // ���� (MAPAPILANGUAGE)
}
  RSCCREATEUN;

// �������� ��'�����
typedef struct RSCOBJECT
{
   unsigned long Length   ; // ������ ���������
   unsigned long Code     ; // ����������������� ���
   unsigned long Local    ; // �������� �����������  (OBJECT_LOCAL)
   unsigned long Segment  ; // �0��� ���� ( �� ����� 255)
   unsigned long Scale    ; // 1 - ��'��� ��������������
                            // 0 - ��'��� �� ��������������
   unsigned long Direct   ; // ����������� ���������� ��'���� (OBJECT_DIRECT)
   unsigned long Bot      ; // ������ ������� ��������� (����������� ��������)
   unsigned long Top      ; // ������� ������� ��������� (����������� ��������)
   char Name[32]          ; // �������� ( �� ����� 30)        // 04/12/14
}
   RSCOBJECT;

typedef struct RSCOBJECTEX                             
{
   unsigned long Length   ; // ������ ���������
   unsigned long Code     ; // ����������������� ���
   unsigned long Local    ; // �������� �����������  (OBJECT_LOCAL)
   unsigned long Segment  ; // �0��� ���� ( �� ����� 255)
   unsigned long Scale    ; // 1 - ��'��� ��������������
                            // 0 - ��'��� �� ��������������
   unsigned long Direct   ; // ����������� ���������� ��'���� (OBJECT_DIRECT)
   unsigned long Bot      ; // ������ ������� ��������� (����������� ��������)
   unsigned long Top      ; // ������� ������� ��������� (����������� ��������)
   unsigned char Name[32] ; // ��������
   unsigned char Key [32] ; // ���������� ���������� ���� �������
}
   RSCOBJECTEX;


// �������� �����
typedef struct RSCSEGMENT
{
   unsigned long Order;     // ������� ������ ���� �� ������
   unsigned char Name[32];  // �������� ( �� ����� 30)
}
   RSCSEGMENT;

// �������� ���������
typedef struct RSCSEMANTICEX  // ����������� �������� �������������
                              // �������������� ��'����
{
  long int Code;         // ������� ���
  long int Type;         // ��� ��������
  long int Reply;        // ����������� ���������� (1)
  long int Enable;       // ����������(1),������������(2)
                         // (��� �������� ��������� ���� �� �����������)
  long int Service;      // ���������,��������� ��� ���� �������� (1)
  long int Reserv;       // ������ (������ ���� ����� 0)
  char     Name[32];     // �������� ��������������
  char     Unit[8];      // ������� ���������
  double   Minimum;      // ����������� ��������
  double   Default;      // ������������ ��������
  double   Maximum;      // ������������ ��������
  long int Size;         // ����� ������ ���� �������� ���������
  long int Decimal;      // �������� ���� �������� ���������
  char     ShortName[16];// �������� ��� ��������� (����� � ����� ��)
}
  RSCSEMANTICEX;


// �������� �������           // 14/11/14
typedef struct RSCFORMULE     // �������� �������
{
  unsigned int Code;          // ���
  unsigned int Semantic;      // ��� ����������� ��������� ��� 0
  unsigned int Length;        // ����� ������ �������
  int          Type;          // ��� ��������������  1 - �������� �������,
                              // 2 - ����������, 4 - ��������������� �������,
                              // 8 - ������� �� ����� LUA
  int          Round;         // 0 - ��� ����������
                              // 1 - ���������� �� ������
                              // 2 - ���������� � �����������
                              // 3 - ���������� � �����������
  int         Precision;      // 3 - �� �����
                              // 2 - �� �����
                              // 1 - �� �������
                              // 0 - �� �����
                              // -1 - �� ������ ����� ����� �������
                              // -2 - �� ���� ������ ����� �������
                              // -3 - �� ���� ������ ����� �������
  int         Index;          // ����� ���������� � ������ ��� Flag=4 ��� 0
  int         Number;         // ����� ������� � ���������� ��� Flag=4 ��� 0
  WCHAR        Name[128];     // �������� �������
}
  RSCFORMULE;


#define SEMLIBIDENT   0x7E7E7E7E

typedef struct SEMLIBLIST
{
  int       Ident;      // ������������� ������ 0x7E7E7E7E
  int       Count;      // ����� ����� �������� � ��������
  struct
  {
    int       Type;     // ��� ���� �������
    int       Zero;     // ������������ �� 8 
    WCHAR * Name[4];    // �������� �������� (����������) �������
                        // Name[0]-ML_ENGLISH, Name[1]-ML_RUSSIAN...
  }
    Element[32];        // �������� �������� ����������� ������� ������ � ���� Count
}
  SEMLIBLIST;


enum FRAMEINCODE    
{
   FIRSTSERVEXCODE  = 1000000000l, // ������ ������� ����� ���������
   LINESERVEXCODE   = 1000000001l, // ������� ��� ���������� ���������
   LINESERVINCODE   = 1          , // ���������� ��� ���������� ���������
   SQUARESERVEXCODE = 1000000002l, // ������� ��� ���������� ����������
   SQUARESERVINCODE = 2          , // ���������� ��� ���������� ����������
   POINTSERVEXCODE  = 1000000003l, // ������� ��� ����������  ���������
   POINTSERVINCODE  = 3          , // ���������� ��� ���������� ���������
   TEXTSERVEXCODE   = 1000000004l, // ������� ��� ���������� ������
   TEXTSERVINCODE   = 4          , // ���������� ��� ���������� ������
   VECTSERVEXCODE   = 1000000005l, // ������� ��� ���������� ����������
   VECTSERVINCODE   = 5          , // ���������� ��� ���������� ����������
   COMSERVEXCODE    = 1000000006l, // ������� ��� ���������� �������
   COMSERVINCODE    = 6          , // ���������� ��� ���������� �������
   SERVOBJECT       = 15         , // ���������� ��������� ��������
};

enum SEMTYPE           // ���� �������� ���������
{
   TUNDEFINED = -1,    // �������� �� �����������
   TSTRING    = 0,     // ���������� ������
   TNUMBER    = 1,     // �������� ��������
   TANYFILE   = 9,     // ��� ����� ������������������� ����
   TBMPFILE   = 10,    // ��� ����� BMP
   TOLEFILE   = 11,    // ��� �����,��������������� OLE-��������
   TREFER     = 12,    // ������ �� ������������ ������ �����
                       // (���������� ����� �������)
   TMAPFILE   = 13,    // ��� �����-�������� ������
   TTXTFILE   = 14,    // ��� ���������� �����
   TPCXFILE   = 15,    // ��� ����� PCX
   TCODE      = 16,    // �������� � ���� ��������� ����
                       // �� �������������� ��������
   TDATE      = 17,    // �������� ���� � �������� ���� (��������)
   TANGLE     = 18,    // ������� �������� � ��������
   TTIME      = 19,    // �������� ������� � �������� ���� (������)
   TFONT      = 20,    // ��� ������ ("Arial", "Courier"...)
   TCOLOR     = 21,    // �������� �������� ����� � RGB
   TFDIGITAL  = 22,    // ��������� ���� ������� �������� (� ������������ ����������)   // 18/02/13
   TFSTRING   = 23,    // ��������� ���� ������� ���������� (� ������������ ����������) // 18/02/13
   TLAST      = 23,    // ������� ������� ������ �����

   TDOCREFMIN = 9,     // ������ ������� ���� ��������� - ������ �� �������� (����������� ����, �����)
   TDOCREFMAX = 15,    // ������ ������� ���� ��������� - ������ �� �������� (����������� ����, �����)
};

// ����������������� ���� ������������� �������������,
// �������� �� ��� �����                                 
// ---------------------------------------------------
#define EXTSEMANTIC        31001  // ������ ��������� ��������� ��������
#define SEMIMAGESCALE      31001  // ������� ����������� ����� � ���������
#define SEMIMAGECOLOR      31002  // ���� ����������� ����� RGB
#define SEMIMAGEHIGHT      31003  // ������ ������         
#define SEMIMAGEFONT       31004  // �������� ������       
#define SEMIMAGETHICK      31005  // ������� ����� � ��          
#define SEMIMAGETHICK2     31006  // ������� ��������� ����� � �� 
#define SEMCOLORWEIGHT     31007  // ��� ����� ������� � ���������
#define SEMLINETHICK       31008  // ������� ����� � �������      
#define SEMLINECOLOR       31009  // ���� ����� 
                                  // �������� �������� ����� RGB
#define SEMLINEPATTERN     31010  // ����� ������� ������� ����� � MAPINFOW.PEN
                                  //  (1-255)
#define SEMMARKSIZE        31011  // ������ ������� ����� � ������� (1-48) 

#define SEMMARKCOLOR       31012  // ���� �����, �������
                                  // �������� �������� ����� RGB
#define SEMFONCOLOR        31013  // ���� ���� 
                                  // �������� �������� ����� RGB
#define SEMMARKSHAPE       31014  // ����� ������� ����� � ���������������
                                  // TRUETYPE ������ (������ 31), 
                                  // ��������� � ��������� SEMIMAGEFONT
#define SEMSQUAREPATTERN   31015  // ����� ������� ������� ������� � MAPINFOW.PEN
                                  // (1-255)
#define SEMFONTSTYLE       31016  // ����� ������ (����� ���������:
                                  // 0 - �������, 1 - T������, 16 - � �����,
                                  // 32 - � �����, 256 - ����� �����)
#define EXTSEMANTICEND     31016  // ����� ���������

// ����������������� ���� ������������� �������������,
// ��� ������                                               
// ---------------------------------------------------
#define ADRSEMANTIC        31201  // ������ ��������� �������� ��������
#define SEMADRSTREET       31201  // �������� �����
#define SEMADRHOUSE        31202  // ����� ����
#define SEMADRTRUNK        31203  // ����� �������
#define SEMADRBUILD        31204  // ����� ��������
#define SEMADRESTATE       31205  // ����� ��������
#define SEMADRSTREETCODE   31206  // ��� �����
#define SEMADRTOWN         31207  // �������� ������ (����������� ������)
#define SEMADRTOWNCODE     31208  // ��� ������ (����������� ������) �� �����
#define SEMADRPOSTCODE     31209  // �������� ������        
#define ADRSEMANTICEND     31209  // ����� ���������

// ����������������� ���� ������������� �������������
// ---------------------------------------------------
#define OBJEXCODEINSEMANTIC 32800  // ����������������� ��� �������
#define SEMOBJEXCODE        32800  // ����������������� ��� �������

#define GROUPLEADER         32801  // ������� �������, �������� ������
#define SEMGROUPLEADER      32801  // �� ����������� ������

#define GROUPSLAVE          32802  // ������� �������, �� �������
#define SEMGROUPSLAVE       32802  // ������� ������ �� �������� �������;

#define GROUPPARTNER        32803  // ������� �������, ���������
#define SEMGROUPPARTNER     32803  // � ������ ������������ ��������

#define SEMOBJECTTOTEXT     32804  // ������ �� ������� �� �������
                                   // (���� �������-������� �� ��� �� �����)
#define SEMOBJECTFROMTEXT   32805  // ������ �� ������ �� �������
                                   // (���� ��������� ������� �� ��� �� �����)
#define SEMOBJECTTOTEXTFAR  32806  // ������ �� ������� �� �������               // 31/05/16
                                   // (���� �������-������� �� ������� �����)
#define SEMOBJECTFROMTEXTFAR 32807 // ������ �� ������ �� �������                // 31/05/16
                                   // (���� ��������� ������� �� ������� �����)

#define SEMRSCNAME          32809  // ��� ����� �������������� RSC 
#define SEMLAYERSHORTNAME   32810  // �������� ��� ���� �������
#define SEMOBJECTSHORTNAME  32811  // �������� ��� ������� (����)
#define SEMOBJECTIDENT      32812  // ������������� �������  
#define SEMOBJECTBASESCALE  32814  // ������� ������� ��������� ��������� ����� �������  

// ��������� ��������� �� ������������� !
#define SEMHIDEFIRST        32800  // ������ ��������� ��������� ��������
#define SEMHIDELAST         32800  // �����  ��������� ��������� ��������

#define SEMLONWGS84         32201  // ������������� ���������� �� ������� � �������� �� WGS-84
#define SEMLATWGS84         32202  // ������������� ���������� �� ������ � �������� �� WGS-84

#define SEMOBJECTDATE       32850  // ���� �������� �������
#define SEMOBJECTTIME       32851  // ����� �������� �������
#define SEMOBJECTAUTHOR     32852  // ��� ���������
#define SEMOBJECTREDATE     32853  // ���� ���������� �������
#define SEMOBJECTRETIME     32854  // ����� ���������� �������
#define SEMOBJECTREAUTHOR   32855  // ��� ��������� ����������

// DATUM PARAMETERS
#define SEMDATUMDX          32871  // ����� �� X
#define SEMDATUMDY          32872  // ����� �� Y
#define SEMDATUMDZ          32873  // ����� �� Z
#define SEMDATUMRX          32874  // ������� �� X
#define SEMDATUMRY          32875  // ������� �� Y
#define SEMDATUMRZ          32876  // ������� �� Z
#define SEMDATUMM           32877  // ���������� �������
#define SEMDATUMTYPE        32878  // ��� �������������� (0, 3, 7, 14)
#define SEMSCALEFACTOR      32879  // ������� �� ������ ���������             // 13/05/15

// USER ELLIPSOID PARAMETERS
#define SEMUSELLAXIS        32880  // SEMIMAJORAXIS
#define SEMUSELLINFL        32881  // INVERSEFLATTENING

#define SEMCRSIDENT         32882  // CRS Ident (String)
#define SEMSHEETNAME        32883  // ��� ����� �����
#define SEMNOMENCLATURE     32884  // ������������ ����� �����  // 16/10/14
#define SEMMAINNAME         32885  // �������� ������           // 16/10/14
#define SEMDATAIDENT        32886  // GUID ������ ������        // 11/01/16

// ����������������� ���� ������������� �������������,
// ��� ������                                               
// ---------------------------------------------------

#define SEMNETRIB           32812  // ����� �������-����� (��� ����)
#define SEMNETKNOTFIRST     32813  // ����� �������-���� ������ ����� (��� �����)
#define SEMNETKNOTLAST      32814  // ����� �������-���� ��������� ����� (��� �����)
#define SEMNETNUMBER        32815  // ����� ����
#define SEMNETTOOBJECT      32816  // ������ �� ������ �����
#define SEMNETVDIRECT       32817  // �������� ������ (��� �����)
#define SEMNETVUNDIRECT     32818  // �������� �������� (��� �����)
#define SEMNETCOSTRIB       32819  // ��������� �����
#define SEMNETRANKRIB       32820  // ���� �����
#define SEMNETBAN           32821  // ����� �����, �� ������� �������� ������� (���� ����� ��������� � ����� ����)
#define SEMNETTURN          32822  // ������� ������� ��������� (1-� ������ �����,2-� �����,3-� ������ � � �����)
#define SEMSELFID           32823  // ����������� ������������� ������ GDF
#define SEMNETCOSTRIBBACK   32824  // ��������� ����� ��������
#define SEMNETRANKRIBBACK   32825  // ���� ����� ��������
#define SEMNETBANBEGIN      32826  // ����� �����, �� ������� �������� ������� �� ������ �����
#define SEMNETBANEND        32827  // ����� �����, �� ������� �������� ������� �� ����� �����
#define SEMNETINLIST        32828  // ������ �� ����� �������� �����
#define SEMNETNOMECLATURE   32829  // ������������ �����

#define SEMSERVICEFIRST     32800  // ������ ��������� ����������� ��������
#define SEMSERVICELAST      33000  // �����  ��������� ����������� ��������

#define SHEETFRAMEINCODE    15l       // ���������� ��� ����� ����� 
#define SHEETFRAMEEXCODE    91000000l // ������� ��� ����� �����

enum SEMANTIC_FOR_OBJECT   // ������������� ��������� ��� ��������
{
  NONE_SEMANTIC     = 0,   // �� ������������
  POSSIBLE_SEMANTIC = 1,   // ���������
  MUST_SEMANTIC     = 2,   // ������������
  IMAGE_SEMANTIC    = 3,   // ������ �� ��� �����������
  ALL_SEMANTIC      = 4    // ��� ���������
};


// �������� ������������� ��������� ��� ��'�����
typedef struct APPLYSEMANTIC
{                           // ���������� ��'�����,������������ ���������
  long Possible;            // ��� ������������
  long Must;                // ��� ���������
  long Image;               // ��������� ������������ ��� ��������� ����
}
  APPLYSEMANTIC;

// �������� ������
typedef struct RSCFONT
{
  char    Font[32];     // ��������
  char    Name[32];     // �������� ��������
  long    CharSet ;     // ������� ��������
}
  RSCFONT;

// �������� ������� �� ���� �� �������� ��������� ("����� ��'����")
typedef struct RSCRELATION                              
{
  unsigned long  ObjectCode   ; // ���������� ��� ������� ���������
  unsigned long  SemanticCode ; // ��� ������������� ���������
  char           Prefix[7]    ; // ���������� ������� (�����) ��� �������
  char           Decimal      ; // ���������� ������ ����� �������
}
  RSCRELATION;

// ����� ������ �������� ��������������                 
enum SEEK_RSCOBJECT
{
   SEEK_EXCODE = 1,        // ����� �� ����
   SEEK_KEY    = 2,        // ����� �� �����
   SEEK_NAME   = 4,        // ����� �� �����
};

// ���� �������� ������ �������
enum COLORMODEL
{
   MODEL_RGB       = 0,
   MODEL_CMYKINDEX = 1,     // ����������� ��������� ������ CMYK �������
   MODEL_CMYKCOLOR = 2,     // ����������� ������� CMYK �������
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++ ��������������� ��������� +++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// ��������� ������
#define ERRORHEIGHT  -111111.0

// ��������� �������� ����
#define ERRORPOWER   -1111111.0

// ��������� �������� ������� �����(MTW), ������� �������(MTQ), ������ �������(RSW)
// ��� ������� mapCreateMtw, mapCreateMtq, mapBuildRsw ������ ���� ������:
// StructSize, BeginX,BeginY,Width,Height,ElemSizeMeters,ElemSizeBytes,Scale.
// ��� ������� mapCreateMtw ����� ������ ���� ������: Unit, ReliefType.
typedef struct BUILDMTW
{
  int StructSize;          // ������ ������ ��������� : sizeof (BUILDMTW)

  int NotCheckDiskFreeSpace;  // ���� - �� ��������� ������� ���������� ����� �� �����  17/04/13
                              // ��� �������� ����� ������� :
                              //   0 - ��������� ������� ���������� �����
                              //   1 - �� ��������� ������� ���������� �����

  double   BeginX;         // ������������� ���������� ������
  double   BeginY;         // (���-��������� ����) ������� � ������

  double   Width;          // ������ ������� � ������
  double   Height;         // ������ ������� � ������

  double   ElemSizeMeters; // ������ ������� ������������� �������
                           // � ������ �� ���������

  int ElemSizeBytes;       // P����� �������� ������� � ������
                           // (���������� �������� : 1,2,4,8)
                           // ��� �������� ������� ����� MTW �� ��������� ����� ��������
                           // mapBuildMtw �������� ������� ���� ������ ���� ����� 4
                           // �������� 1 ������������� ���� "unsigned char" (��� ���������� ������ = 0)
                           // �������� 2 ������������� ���� "short int" (��� ���������� ������ = -32767)
                           // �������� 4 ������������� ���� "long int" (��� ���������� ������ = -32767000)
                           // �������� 8 ������������� ���� "double" (��� ���������� ������ = -32767000)

  int Unit;                // E������ ��������� ������ ������� ����� MTW
                           // (0 - �����, 1 - ���������,
                           //  2 - ����������, 3 - ���������� )

  int ReliefType;          // ��� ������� ����� MTW (0 - ���������� ������,
                           //  1 - ���������� + �������������,
                           //  2 - �������������)

  int UserType;            // ������������ �����, �����������
                           // � ����������� ��������

  int Scale;               // ����������� �������� �����������
                           // ��������� ����� (��� �������� ������� ����� MTW
                           // �� ��������� ����� �������� mapBuildMtw ��������
                           // ������� ���� ����� �������� �� �����������
                           // �������� ��������� �����)

  int HeightSuper;         // ���� ��������� ������ � ������� ��� �������� �������
                           // ����� MTW �� ��������� ����� �������� mapBuildMtw � ��� ���������
                           // � ������� ����� ������ ������� � ���������� ������� :
                           //  0 - �������� ������� ������
                           //  1 - �������� ������������ ������
                           //  2 - �������� ����������� ������

  int FastBuilding;        // ���������� ����
                           // ����� �������� ������� (��� Method = 0) :
                           //  0 - ���������������� ������������ �� 16 ������������,
                           //    ��� ������������ ��������� �����������
                           //  1 - ���������������� ������������ �� 8 ������������,
                           //    ��� ������������ ��������� �����������
                           //  2 - ���������������� ������������ �� 16 ������������,
                           //    � ������������� ��������� �����������
                           //  3 - ���������������� ������������ �� 8 ������������,
                           //    � ������������� ��������� �����������

 int Method;          // ����� ���������� ����������� ��� �������� ������� ����� MTW
                      // �� ��������� ����� �������� mapBuildMtw :
                      //  0 - ����� ������������ ������� FastBuilding
                      //  1 - ���������������� ������������ �� 16 ������������
                      //  2 - ���������������� ������������ �� 8 ������������
                      //  3 - ���������������� ������������ �� 16 ������������,
                      //      ����������� �����������
                      //  8 - �������� ������������ �� ����� �������������
                      //     (� ������ ������������ ������ �������� �������)
                      //  16 - ������� ����������� � ������� �������
                      //       ��� ReliefType = 2

  int Extremum;       // ���� ������������ ��������� �����������
                      //
                      // �������� mapBuildMtw (��� Method = 1,2,3) :
                      //  0 - ��������� ���������� �� �����������
                      //  1 - ��������� ���������� �����������

#ifdef _M_X64
  int Free;           // ������������  // 21/07/16
#endif // _M_X64

  HOBJ Border;        // ������������� ���������� ������� ��� ��������
                      // ������� ����� MTW �� ��������� ����� �������� mapBuildMtw.
                      // �� ������� ������� ��������������� ����� ����������� �������
                      // (���� ������ ���������� ��� ��������� �������,
                      // ������������ ���������� ����� BeginX, BeginY, Width, Height
                      // ������ ���������, �� ����� �� ���������������)

  int LimitMatrixFrame;
                      // ���� ����������� ��������� ��� �������� ������� MTW
                      // �� ��������� ����� �������� mapBuildMtw ��� Method = 1,2,3,8
                      // (�������� ������� ������������ ���������� �����
                      // BeginX, BeginY, Width, Height ������ ���������) :
                      //  0 - ����������� �� �����������
                      //  1 - �������� ������� ��������������
                      //      ���������� ������
                      //  2 - �������� ������� ��������������
                      //      ���������� ������� ������������
                      //      �������� � ���������� �������


  int NotUse3DMetric;
                      // ���� - �� ������������ ���������� ������� ��������
                      // ��� �������� ������� MTW �� ��������� ����� �������� mapBuildMtw:
                      //  0 - ���������� ������� ������������
                      //  1 - ���������� ������� �� ������������

  int SurfaceSquare3DObject;
                      // ���� ��� �������� ������� MTW �� ��������� ����� �������� mapBuildMtw -
                      // ������� ����������� ������ ����������
                      // ������� �� ��� ���������� ������� :
                      //  0 - �� ������� �����������
                      //  1 - ������� �����������
                      // ���� �������� NotUse3DMetric ����� 1,
                      // �� ����������� �� ��������

  int AltitudeMarksNet;
                      // ���� �������������� ��������� �������� ����� ���
                      // �������� ������� MTW �� ��������� ����� �������� mapBuildMtw ���
                      // ���������������� ������������ (Method = 1,2,3) :
                      //  0 - ��� ������ �������� ����� ����������� ���������� �
                      //      ��������� � ������� ����� ������� ������ (��� �������
                      //      ������ - 3D-�������,��������� �� ����� �� ������ ��
                      //      16 ���������� �����������; ������ ��������� �������
                      //      ������������ ������� ����� � �������, ��������� ���
                      //      ������������ ������� �� ����� �� ������� �����������.
                      //      ���� ������� ������ ������������ ������� ���� �����
                      //      � ���������� ������� ��� ������ �������� ����� � ��������
                      //      ���������� ������������ ��������� �������.
                      //  1 - �� ������ �������� ����� ��������� ������������,
                      //      ����� ������������ (��� ����� �����) ��������� � �������
                      //      � ���� 3D-�������� (���� ����� �� ���������� �������
                      //      � ���������� �������, �� ��� ��������� �������,
                      //      ���� ����������, �� ��������� ����� �����, ������������
                      //      ��� �������� � ������ ����������� � ��������);
                      //  2 - �������������� ��������� �������� ����� �� �����������,
                      //      ������ ����� ��������� � ���� ������� �������,
                      //      ������ ����������� ��� ���������� �����������
                      //      �� ������ ������� �����

  int LimitMatrixByFramesOfSheets;
                      // ���� ����������� ������� ������� ������ ��� ��������
                      // ������� MTW �� ��������� ����� �������� mapBuildMtw (��� Method = 1,2,3,8):
                      //  0 - ����������� ������� �� �����������,
                      //      ������������� �������� ����� �������������
                      //      ��� ����� ������
                      //  1 - ����������� ������� �����������,
                      //      ������������� �������� �������������
                      //      ������ ������ ��������� ����� ������

  char Reserve[20];   // ������ ���� ����
}
  BUILDMTW;


typedef struct MTRPROJECTIONDATA  //  ��������� �������� ������� �����
{                                 //   (������ � ��������)
  int  StructSize;              // ������ ������ ��������� : 128 ����
                                //  sizeof (MTRPROJECTIONDATA)

  int  Free;                    // ������ ���� ����

  int  MapType;                 // ��� ����� (�������� � ������������
                                //   � MAPTYPE, ���� MAPCREAT.H)

  int  ProjectionType;          // ��� �������� (�������� � ������������
                                //   � MAPPROJECTION, ���� MAPCREAT.H)
                                // long  MaterialProjection; // �������� ���. ���������

                                // � ��������
  double    FirstMainParallel;  // ������ ������� ���������
  double    SecondMainParallel; // ������ ������� ���������
  double    AxisMeridian;       // ������ ��������
  double    MainPointParallel;  // ��������� ������� �����
  double    PoleLatitude;       // ������ ������ ��������          
  double    PoleLongitude;      // ������� ������ ��������         

  int       EllipsoideKind;     // ��� ����������           
  int       HeightSystem;       // ������� �����            
  int       CoordinateSystem;   // ������� ���������        
  int       ZoneNumber;         // ����� ���� ���������     

  double    FalseEasting;    // �������� ��������� �� ��� Y            // 05/07/10
  double    FalseNorthing;   // �������� ��������� �� ��� X            // 05/07/10
  double    ScaleFactor;     // ���������� �����������                 // 05/07/10
  double    TurnAngle;       // ���� ��������� ���� ��� ��������� ������ (���)   // 05/07/10
  int       ZoneIdent;       // ������������� ������ (��� ��� 63: A-X ��� 0)     // 26/04/11

  char      Reserve[12];     // ������ ���� ����

}
  MTRPROJECTIONDATA;

// ��������� ���������� ������� ����������� (������� ������� ��� ������� �����)

typedef struct BUILDSURFACE  // 15/06/11
{
 unsigned
     int StructSize; // ������ ������ ��������� : sizeof (BUILDSURFACE) = 320 ����
     int FileMtw;    // ���� ���������� ������������ ����� :
                     //   0 - �������� ����� ������� ������� (*.mtq)
                     //   1 - �������� ����� ������� ����� (*.mtw)

 double BeginX;    // ������������� ���������� ������
 double BeginY;    // (���-��������� ����) ������� � ������

 double Width;     // ������ ������� � ������
 double Height;    // ������ ������� � ������

 double MinValue;  // �������� �������� �������������� �������� ����������� �������,
 double MaxValue;  // ���� MinValue >= MaxValue � ������� ��������� ����������� �������� ��������

 double ElemSizeMeters;  // ������ ������� ������������� �������
                         // � ������ �� ��������� (������� �������)

 int UserType;           // ������������ �����, ����������� � ����������� ��������
                         //  (���, �������������� �������)

 int SearchSectorCount;  // ���������� �������� ��� ������ �������� ����� (��� Method = 9,11,12) // 09/06/11
                             // 1 - �� �����
                             // 4 - �� 4 ��������
                             // 8 - �� 8 ��������

 char UserName[32];      // �������� ��� ������� (�������� �������������� ��������)

 HOBJ Border;  // ������������� ���������� ������� �����, ��������������� �������
               // ����������� ��������� ������� (���� ����� ����, �� �� ������������)
               // ���� ������ ���������� ��� ��������� �������, ������������ ����������
               // ����� BeginX, BeginY, Width, Height ������ ���������, �� �� ������������

 HWND Handle;  // ������������� ���� �������, �������� ����������
               // ��������� 0x0581 � �������� ����������� ����� (� WPARAM),
               // ���� ������� ������ ���� ������������� ��������, � �����
               // ������ ��������� �������� 0x0581.
               // ���� Handle ����� ���� - ��������� �� ����������.

 COLORREF* Palette;      // ����� ������� ����������� ������� �������(*.mtq),
                         // ���� ����� ���� - ������������ ������� �� ���������
 int PaletteCount;       // K��������� ������ � ������� (�� 1 �� 256)

 int Method;             // ����� ���������� ����������� :
                         //  8 - �������� ������������ �� ����� �������������
                         //      ( ������������ ����� ������� PointArray )
                         //  9 - ��������������� ������������ �� ��������� �����������
                         //       ������ ������������� ��������
                         //      ( ������������ ����� ������� �������� ����� )
                         // 10 - �������� ������������ �� ����� �������������
                         //      ( ������������ ����� ������� �������� ����� )
                         // 11 - �������
                         // 12 - ��������� // 19/11/12

 XYHDOUBLE* PointArray;  // ����� ������� �������� �������������� �������� (��� Method = 8)
 int PointCount;    // ����� ����� � ������� PointArray (��� Method = 8)

 int SemanticCode;  // ��� ��������� ������������ ��������������
                         // ���� = 0, �� �� ������������ 

 int LocalSurfacePointCount;  // K��������� ����� ��� ���������� ��������� �����������
                              // ������ ������������� �������� (��� Method = 9,11,12)
                                   // ���� SearchSectorCount = 4, �� LocalSurfacePointCount ������ ���� ������ 4
                                   // ���� SearchSectorCount = 8, �� LocalSurfacePointCount ������ ���� ������ 8

 int LocalSurfaceRebuildPointCount;  // K��������� ����������� ����� ��� ��������
                                          // � ���������� ������������� ��������,
                                          // ��� ������� ��������������� ���������
                                          // ����������� (��� Method = 9)
 double MaxMetricCutLength;  // ��� ���������� ����� �� ������� �������� � ��������� �������� (��� Method = 9,11,12)
                             // ������������ ���� IsMetricCutLength = 1

 int Use3DMetric;            // ���� ������������� ����� �� ���������� ������� �������� :  // 06/11/07
                             //  0 - ������ �� ���������� ������� �� ������������
                             //  1 - ������ �� ���������� ������� ������������
                             

 int SemanticCode2;          // ��� ��������� �������������� �������������� ��� ���������� (��� Method = 12) // 13/02/13

 int FillBorderType;         // ��� ���������� ������� ������ ��������������� ������� Border
                             // 0 - ����������� ���� ������
                             // 1 - ����������� ������ ��� �����������
                             // 2 - ����������� ������ � ����������
                             // 3 - ����������� ������ ����������

 int IsMetricCutLength; // ��������� ����� �� ������� �������� � ��������� �������� (��� Method = 9,11,12) // 09/06/11
                             // ����� ����������� � ����� MaxMetricCutLength

 int IsAddPointsInEmptyRegion; // ��������� ����� � ������ �������� (��� Method = 9,11,12) // 09/06/11

 int IsLimitHeight;      // ���� ��������, �� ������ �������� ������� �� ����� ���� ������ ��� ������ ����� (��� Method = 9,11,12) // 09/06/11
                         // �������� �����, �� ������� �������� �����������, �� LimitOffset

 double   DistBeforePointsInEmptyRegion; // ���������� ����� ������� � ������ �������� (��� Method = 9,11,12) // 09/06/11
                                         // �������� ������ (��������������) � ����
                                         // ������ ������������ ������� ������������ �� 8 ������������.
                                         // ��� ����� ����������� ��� ����, ����� � ������ �������� ��������� �� ���������
                                         // ��� � �� � ������� ����� �� ������� ������ �������� ���� ������������ ���������.
 double   LimitOffset; // ���� �������� IsLimitHeight �� ����������� ���������� ������������  (��� Method = 9,11,12) // 09/06/11
                       // �������� ������� �� ������������, ������������� �������� ����� �������� �����

 char Reserve[128];    // ������ ���� ����
}
  BUILDSURFACE;


// ��������� ���������� �������    // 10/02/10

typedef struct PROFBUILDPARM
{
  DOUBLEPOINT Point;               // ���������� ������� ����� �� �������
  HOBJ        Object;              // ������ ��� ���������� �������
  long int    ProfStepVertical;    // ��� ����� �� ��������� (�)
  long int    ProfStepHorizontal;  // ��� ����� �� ����������� (�)

} 
  PROFBUILDPARM;

  
// ��������� ���������� �������    // 23/04/10

typedef struct PROFBUILDPARMEX
{
  DOUBLEPOINT Point;               // ���������� ������� ����� �� �������
  HOBJ        Object;              // ������ ��� ���������� �������
  long int    ProfStepVertical;    // ��� ����� �� ��������� (�)
  long int    ProfStepHorizontal;  // ��� ����� �� ����������� (�)
  double      DeltaRight;          // ���������� � �������� �����
  double      DeltaCurrent;        // ���������� � ������� �����
  double      DeltaLeft;           // ���������� � ��������� �����
  long        ColorProf;           // ���� �������
  long        ColorLine;           // ���� �����
  long int    IsCurvatureEarth;    // ���� ����� ��������  �����  0 - �� ���������,
                                   //                             1 - ���������;
  long int    IsMiddleHeight;      // ���� ����� ���������� ����� 0 - �� ���������,
                                   //                             1 - ���������;
  long int    IsLineFL;            // ���� ����������� ����� (������ - ��������� �����)
                                   // 0 - ����������,   1 - �� ����������;
  long int    IsLineFCL;           // ���� ����������� ����� (������ - �������- ��������� �����)
                                   // 0 - ����������,   1 - �� ����������;
  long int    IsLineCross;         // ���� ����������� ����� (����������� �� ������� �����)
                                   // 0 - ����������,   1 - �� ����������;
  long int    IsLineNet;           // ���� ����������� ����� �������
                                   // 0 - ����������,   1 - �� ����������;
  long int    IsLineRelief;        // ���� ����������� �������
                                   // 0 - �������,   1 - ������;
}
  PROFBUILDPARMEX;


// ����������� �������� ���������� ��'����  // 01/02/02

typedef struct
{
   int         ListNumber;        // ����� ����� ���������� ��'����
   int         ObjectNumber;      // ����� ���������� ��'���� � �����
   HSITE       Map;               // �������� ����������� �����
}
  MAPOBJDESCEX;

typedef struct
{
  DOUBLEPOINT XY;     // ���������� ����� �����������
  double       H;     // ������ ����� �����������
                      // (�� �������)
  HOBJ Info1;
  long int Number1;   // �� ����� ������ ������� Info1
                      // ��������� ����� �����������
  long int Subject1;  // ����� �������/���������� ������� info2
  HOBJ Info2;
  long int Number2;   // �� ����� ������ ������� Info2
                      // ��������� ����� �����������
  long int Subject2;  // ����� �������/���������� ������� info2
}
  CROSSPOINT;


// ��������� ����������� ������ ���������� ������
// ��������� �� ��� ������������ � �������� �������
// ��������� � ��������� AW_CREATETASKPANEL

typedef struct PANELINFO
{
  HINSTANCE hInst;     // ������������� ���������� ���������� ������ ������
  long int  Count;     // ���������� ������������ ���������������(������) �
                       // ������ ��������� ��������� AW_CREATETASKPANEL
  char      Name[32];  // ����������� �������� ������
}
  PANELINFO;

typedef struct PANELPOS   // �������� LPARAM ��������� AW_MOVEPANEL
{
  RECT      Rect;         // ���������� ������ ��������� ������
  long int  Position;     // ������������ ������ � ���� (��. LOCAL)
  long int  Layout;       // ������� ������������ ���������� ����
}
  PANELPOS;

typedef struct BUTTONINFO   // �������� LPARAM ��������� AW_INSERTBUTTON
{
  long int Command;         // ������������� ����������� ������,
                            // ���� Command = (-1) - ����������� �����������
  HBITMAP  hBitmap;         // ������������� �������� �� ������
                            // ��� Linux - ��������� �� ��������� BUTTONINFOLX
  long int Sibling;         // ������������� ������ � ������ ������������,
                            // ����� ������� ����������� ����������� ������.
                            // ���� Sibling = NULL - ����������� � �����
}
  BUTTONINFO;

  
typedef struct TASKBUTTONINFO // �������� LPARAM ��������� AW_INSERTTASKBUTTON     // 05/06/10
{
  HINSTANCE hTask;          // ������������� ���������� ������, ������� ����� ��������� ������� ��� 0
                            // ���� ����� ������������� ������, �� Command �����
                            // ������������ �� ��������� ���������� ������
  long int Command;         // ������������� ������,
                            // ���� Command = (-1) - ����������� �����������
  long int Sibling;         // ������������� ������ � ������ ������������,
                            // ����� ������� ����������� ����������� ������.
                            // ���� Sibling ����� 0, �� ��� �������� ������ ����������� � ����� ������
  HBITMAP  hBitmap;         // ������������� �������� �� ������ ��� 0
  long int Background;      // ������� ���������� ���� ������ (���� �� ����� 0),
                            // ����������� ���� hBitmap �� ����
  long int State;           // ��������� ������ (0 - ������, 1 - ������, -1 - �� ��������)
  long int Enable;          // ����������� ������ (0 - ���������� ��� �������, 1 - ����� ����������)

  WCHAR    Hint[256];       // �������� ��������� � ������ � UNICODE ��� 0

  WCHAR    Comment[256];    // ������� ��������� � ������ � UNICODE ��� 0
}
  TASKBUTTONINFO;

#ifdef LINUXAPI 
typedef struct BUTTONINFOLX // �������� hBitmap ��������� BUTTONINFO
{
  HBITMAP  hBitmap;         // ������������� �������� �� ������

  char     Hint[80];        // ���������
}
  BUTTONINFOLX;
#endif


typedef struct CONTRINFO  // �������� LPARAM ��������� AW_INSERTCONTROL
{
  long int CtrlId;          // ������������� ������������ �������� ����������,
                            // ���� CtrlId = (-1) - ����������� �����������
  HWND     hWindow;         // ������������� ���� �������� ����������

  long int Sibling;         // ������������� �������� ���������� � ������
                            // ������������, ����� �������� �����������
                            // ����������� ������� ����������.
                            // ���� Sibling = NULL - ����������� � �����
}
  CONTRINFO;

typedef struct HITCONTROLINFO // �������� LPARAM ������� MT_PANELRBUTTONUP
{
  POINT    Position;          // ��������� ������� �� ������

  long int CtrlID;            // ������������� �������� ���������� ������,
                              // ��� ������� ���� ������ �������
}
  HITCONTROLINFO;

enum DBFFIELDTYPE         // ���� ����� � ����� DBF
{
  DBFCHAR     = 'C',      // Char (1 - 254)
  DBFDATE     = 'D',      // Date (10 �������� : YYYYMMDD)
  DBFFLOAT    = 'F',      // Float  (1-20)
  DBFFIXED    = 'N',      // Numeric (1-20)
  DBFBOOL     = 'L',      // Logical (Yy, Tt, Nn, Ff, , ?)
  DBFMEMO     = 'M',      // Memo (10 ���� - ������ � DBT ��� �������)
  DBFVARIABLE = 'V',      // Variable (4+4+1+1)
  DBFPICTURE  = 'P',      // Picture (10 ���� - ������ � FTP ��� �������)
  DBFBINARY   = 'B',      // Binary (10 ���� - ������ � DPT ��� �������)
  DBFGENERAL  = 'G',      // OLE-������� (10 ���� - ������ � DPT ��� �������)
  DBFDOUBLE   = 'O',      // Double
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++ ������� ��������� ���������� +++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef enum READLOG   // ������� ���������� ����������
{
  READ_ANYACTION = 0,  // ������� ��������� ����������
  LOG_ANYACTION  = 0,  // ���������� ��������� ����������
  READ_MYACTION  = 1,  // ������� ���� ��������� ����������
                       // (�� ����� ������������)
  LOG_MYACTION   = 1,  // ���������� ���� ����������
}
 READLOG;

// ����������������� ���� ����������
enum ACTION_TYPE
{
  AT_OPEN     = 60000,     // ������ ������
  AT_CLOSE    = 60001,     // ������ ������
  AT_LOGON    = 60002,     // ������ � ������ ��������
  AT_LOGOFF   = 60003,     // ������ � ������ ���������
  AT_CLEAR    = 60004,     // ����� ������ ������� (����������,...)
  AT_UNDO     = 60005,     // ������ �����-���� ���������� ����������
  AT_NEXT     = 60006,     // ����������� ���������� ����������
  AT_REDO     = 60007,     // �������������� �����-���� ���������� ����������
  AT_SORT     = 60008,     // ��������� ���������� �����
  AT_RSCSAVE  = 60009,     // ��������� ���������� ��������������
  AT_ERROR    = 60010,     // ����� ����� �� ������������ ����� �����������, ��� ����
  AT_FIRST    = AT_OPEN,   // ������ ����������������� ���
  AT_LAST     = AT_ERROR,  // ��������� ����������������� ���
};

// ���� Type == AT_OPEN, ����� ��������� ����
// �������� ��������� ����������, ������ 16 ����
// (��� ���������� � ����).

typedef struct ACTIONHEAD  // ��������� �������� ����������
{
  short int      Ident;    // 0x7FFF
  unsigned short Task;     // ������������� ������,����������� ����������
  unsigned short Count;    // ����� �������� (Length = 16+Count*16)
  unsigned short Type;     // ��� ���������� (��� ������)
  unsigned int   Date;     // ���� ���������� ����������
  unsigned int   Time;     // ����� ���������� ����������
}
  ACTIONHEAD;

// ���� �������� ��� ��'�����
enum OBJECT_OPERATION
{
   OO_APPEND    = 1,        // �������� ��' ����
   OO_DELETE    = 2,        // �������� ��'����
   OO_UPDATE    = 4,        // ���������� ��'����
   OO_UNDO      = 8,        // �������������� ��'����
};

// ����� ������������ ��������� ��'����
enum ACTION_MASK
{
   AM_HEAD      = 1,        // �������� ���������� ������
   AM_METRIC    = 2,        // �������� ������� ��'����
   AM_SEMANTIC  = 4,        // �������� ���������
   AM_DRAW      = 8,        // �������� ����������� ��������
   AM_HEADREF   = 16,       // ���������� ������ �������� ������ � ����� ������� ������
};

typedef struct ACTIONRECORD // �������� ��������� ��������
{                           // (��� AT_OPEN - ��� ������ 16 ����)
  int      Key;             // ���������� ����� ������� � �����                // 09/04/13
  int      Number;          // ���������������� ����� � ������ ���������
  int      Back;            // ����� ������ � ����� ������ (���������)
  unsigned char Type;       // ��� ��������
  unsigned char Mask;       // ����� ������������ ��������� �������
  short         List;       // ����� �����
}
 ACTIONRECORD;


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++ ���������� � ��������� �� ���� �����  ++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifdef WIN32API
typedef long int (WINAPI * CHANGECALL)(void * parm, void * value);
#else
typedef long int (*CHANGECALL)(void * parm, void * value);
#endif

typedef struct CHANGEINFO
{
  HSITE    hSite;     // ������������� ����� � ���������
  short int List;     // ����� ����� �����
  unsigned char Type; // ��� �������� (OBJECT_OPERATION)
  unsigned char Mask; // ����� ������������ ��������� ������� (ACTION_MASK)
  unsigned int  Key;    // ���������� ����� ������� � ����� 
                        // (��� -1, ���� ��������� ������� ����� ��������)  // 12/12/13
  unsigned int  Object; // ���������������� ����� ������� � �����
                        // (��� -1, ���� ��������� ������� ����� ��������)
}
  CHANGEINFO;


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++ ��������� ������������ � ������ ������ +++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef struct FILEMAPPING  // ��������� ����������� ����� � ������
{
  FILEMAPPING() { hFile = 0; hMapping = 0; Address = 0; }

  HANDLE   hFile;           // ������������� ��������� �����
  HANDLE   hMapping;        // ������������� ����������� (� UNIX = 0)
  char *   Address;         // ����� ������� ������ ��� ����������� ������
  unsigned long int Offset; // �������� � ����� �� ������ ���� ������
  unsigned long int Size;   // ������ ������������ ������� � �����
  unsigned long int Shift;  // �������� �� ������ ���� � ������� ������
                            // ��� ����� ��������� ������� �������� (64 ��)
}
  FILEMAPPING;

// ���� �������� ���������� �������, ������� �����, � ������ - �����
// (��. mapCreateObjectsCross(...) � seekapi.h)
#define FLAGINSIDEOBJECTS  32

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++ ��������� �� ���� �� �����  +++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct PUTTOMAPINFO
{
  long int Incode;     // ���������� ��� �������
  long int MapNumber;  // ����� �����
  long int Regime;     // ������ ��������� �������

}
  PUTTOMAPINFO;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++ ���������� � ����� ����������� ++++++++++++
// +++++++++++++  ������� � �������� ���������� ++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct NUMBERPOINT
{
  DOUBLEPOINT Point;   // ���������� �����
  long int Number;     // ����� ����� �������, �� ������� ������� point
  long int Update;     // ����������� ������ ����� �������
  long int Equal;      // ����� ����� ���������� � �������
  long int Reserve;
}
  NUMBERPOINT;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    ��������� ��������� �������� ��������, ������������
//        ��� ���������� �������� � �������� �� �����
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct _DLLCLASS COMMITOBJECTPARM                         // 11/04/11
{
  COMMITOBJECTPARM () { memset(this, 0, sizeof(*this)); }

  double MinCutLength;          // ����������� ����� ������� ������� �������
                                // (� ������ �� ���������)

  // ������������ ��� �������������� ���������� ����� ������� ��� ����������
  // �������� � ��������� �������� � �������� �� ������ � ��������:
  // mapCommitWithPlace(), mapCommitWithPlaceAsNew().
  // ��� ����������� �������, ����� �������� ����� MinLineLength,
  // ��������� ��� ������ �����.

  double MinCutLengthOnBorder;  // ����������� ����� ������� ������� �������,
                                // ���������� �� ����� (� ������ �� ���������)

  // ������������ ��� ��������������� �������� �������� ��������
  // � ����������� ��������� ��������, ����������� ��� �������
  // �������� �� ����� � ��������:
  // mapCommitWithPlace(), mapCommitWithPlaceAsNew().
  // ��� ������������ ���������� ��������� ���������� �������:
  // 1) �����������, ��������� ����� ����� ����� �����,
  //    ����� ����� �� ������ �������� ����� MinCutLengthOnBorder;
  // 2) ���������������, ��������� ����� ����� ����� �����,
  //    ����� ���� �������� �������� ����� MinCutLengthOnBorder.

  char Reserve[48];             // ������
}
  COMMITOBJECTPARM;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ���� � ������� ������� ������������� ����� - 3D-�������
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef struct VECDATA     // ������ �������� 3D-������
{                          //
  int         Code;        // ��� ���������� (��� ���������� �����������, ����� 0)
  int         Key;         // ���� ����������� (��� ���������� �����������, ����� 0)
  XYHDOUBLE   Offset;      // �������� ����� ������ ������������ ������ ����� �������
  double      Angle;       // ���� �������� ��� X ������ ������������ ��� X �����
}
  VECDATA;

typedef struct VECRECORD   // ������ ������� �������� (������ ����� VEC)
{                          //
  int         Number;      // ����� �������
  int         BaseKey;     // ���� �������
  VECDATA     Data;        // ������ ��������
}
  VECRECORD;

// ������ ����� ������� �� ������� �������� �� ��� ���������� ������ ����� �������.
// �� ����������� �������� ���������� ������ ����� ������� ������. ���������� �������� = Offset.
// Angle - ���� �������� ��� X ������ ������������ ��� X �����.

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++ ��������� ������������ ++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef struct SAVEMAPCOMPPARM
{
 char Titlsave[40];          // �������� ������
 double MemoryRegister;      // �������
 double MemoryBuffer;        // ����� ������
 double Buffer;              // ����� �����������
 double Memory;              // ������
 double Value;               // ������������ ��������
 long int Flagcomp;          // ������� �������� 1-(+),2-(-),3-(*),4-(/),
                             //                  0 - �������� �� ����
 long int Index;             // ������ ��� ������ ��������� �����
 long int Indexold;          // ���������� ������
 long int IndexSq;           // ������ ��� ������ ��������� �������
 long int Flagshow;          // ��������� �������
 long int Regnow;            // ������������ �����
 long int Regold;            // ����� ����������-���. ��� ����.
 long int Flagreg;           // ������� �����: 0- �����, 1- �������
 long int StopFlag;          // ���� �������� �������
 long int Precision;         // �������� ����������

} SAVEMAPCOMPPARM;


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// // ��������� �������� Ole-�������
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef struct OLELOADPARM
{
 double   PosX;                 // ���������� x � ������ �� ���������
 double   PosY;                 // ���������� y � ������ �� ��������� 

 int      Height;               // ������ Ole-������� � �� �� ����� � ��������� ��������
 int      Width;                // ������ Ole-������� � �� �� ����� � ��������� ��������

 char     PosRight;             // 0 - ����� ����, 1 - ������ ����
 char     PosBottom;            // 0 - ������� ����, 1 - ������ ����
 char     Reserve[50];          // ������������ �� 8

 char     Path[260];            // ������ ���� � ������

} 
  OLELOADPARM;


struct SETVIEWSCALE    // ��������� ��������� ��� ��������������� OLE-����������  
{
  POINT     center;    // ����� ���������� ������
  int       percent;   // ������� ���������� �����������
  int       zero;      // ������������
};


// ������������� �������  // 31/08/11
#define	VIFIRST 1
#define	NDVI    1
#define	RVI     2
#define	IPVI    3
#define	DVI     4
#define	SAVI    5
#define	MSAVI2  6
#define	VILAST  6

// ������, ����������� ��� ����������� �������������� ������� // 31/08/11
typedef struct VEGINDEX
{
   int      Index;         // ������������ ������ ��������� (NDVI, RVI � �.�.)
   int      ColorCount;    // ���������� ������ � ������� ��������� �������������� �������
   RGBQUAD  Palette[256];  // ������� ��������� �������������� �������
   int      RedBandNum;    // ����� �������� ������
   int      NirBandNum;    // ����� ������������� ������
   double   L;             // ����������� ��� SAVI (0..1)
   double   Reserv[32];
}
  VEGINDEX;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ��������� �������� TIFF ������� 18/09/13
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// ��� ������� (����� ������ ���������� ���� ������� �� ������ ������������ ����������,
// �������� ������ ������� � ����� �������� ���������� CREATETIFPARM.BitInBand)
#define PT_MIN       0
#define PT_UNKNOWN   0
#define PT_BYTE      1    // 8-�� ��������� ����� ����� ��� �����
#define PT_UINT16    2    // 16-�� ��������� ����� ����� ��� �����
#define PT_INT16     3    // 16-�� ��������� ����� ����� �� ������
#define PT_UINT32    4    // 32-� ��������� ����� ����� ��� �����
#define PT_INT32     5    // 32-� ��������� ����� ����� �� ������
#define PT_FLOAT32   6    // 32-� ��������� ����� c ��������� �������
#define PT_FLOAT64   7    // 64-� ��������� ����� � ��������� �������
#define PT_CINT16    8    // 16-�� ��������� ����������� �����
#define PT_CINT32    9    // 32-� ��������� ����������� �����
#define PT_CFLOAT32 10    // 32-� ��������� ����������� ����� c ��������� �������
#define PT_CFLOAT64 11    // 64-� ��������� ����������� ����� � ��������� �������
#define PT_MAX      11

// ������������� ������� ��� 3 (CMYK - 4) ��������� �������
#define CS_RGB       2
#define CS_CMYK      5 
#define CS_YCBCR     6
#define CS_CIELAB    8
#define CS_ICCLAB    9
#define CS_ITULAB   10

// ������� �������� BIGTIFF
#define BT_NO        0  // �� ���������
#define BT_YES       1  // ���������
#define BT_IFNEEDED  2  // ���������, ���� ������ ������ 4 �� � ��� ������
#define BT_IFSAFER   3  // ���������, ���� ������ ������ 2 �� � ������ �� �����������

// ���� ���������� � TIF ������
#define NOTCOMPRESS     1
#define LZW             5
#define CCITT           2
#define CCITTFAX3       3
#define CCITTFAX4       4
#define JPEG            6
#define DEFLATE         8
#define PACKBITS        32773

// ��������� �������� �����������������      
typedef struct AFFINCOEF
{
  double A0, A1, A2, B0, B1, B2;
}
  AFFINCOEF;

// ��������� ����������� TIF �����
typedef struct CREATETIFPARM
{
  int     BandCount;    // ���������� �������
  int     BitInBand;    // ��� �� �����
  int     PixelType;    // ��� ������� (PT_BYTE � �.�.)
  int     Compress;     // ��� ���������� (��. NOTCOMPRESS � �.�.)
                        // JPEG - �������� ������ ��� 3 � 1 ��������� 8, 16 ������ �������
                        //      - ��� 3 ��������� �������� ColorSpace = CS_RGB ��� CS_YCBCR (������ ������, �� ���������)
                        //      - ��� CS_YCBCR � ����� ����� ������������ RGB
  int     IsPredictor;  // ��� LZW � DEFLATE ���������� - ������� ������ �����������
                        // 0 - ��������� ���� �����
                        // 1 - ��������� ����������� ����� ��������� ��������� � ������
  int     JPEGQuality;  // �������� JPEG ������ (1-100) (�� ��������� 75)
  int     ColorSpace;   // ������������� ������� ��� 3 ��������� ������� (CMYK ��� 4 ���������) ��. CS_RGB � �.�.
  int     DeflateLevel; // ������� DEFLATE ������ (1-9) (�� ��������� 6)
  int     TileWidth;    // ������ ����� � ��������
  int     TileHeight;   // ������ ����� � ��������
  int     BigTIFF;      // ������� �������� BIGTIFF (��. BT_NO � �.�.)
  int     IsPlane;      // ������� �������� ����������� �� ���������� (0 - RGB RGB ..., 1 - RR...BB...GG...)
                        // ��� JPEG ������ � �������� ������ YCBCR ������ ���� = 0
  int     IsAlpha;      // ������� ������������� ����� ������
  RGBQUAD Palette[256]; // ������� 1,4,8 ������ �������
  int     Reserved[64];
}
  CREATETIFPARM;

#pragma pack(pop)

#endif  // MAPTYPE_H

