/******* MAPRSCEX.H  *********** Panteleeva N.A. ****** 14/04/16 ***
******** MAPRSCEX.H  *********** Kruzhkov A.E.   ****** 23/04/06 ***
******** MAPRSCEX.H  *********** Belenkov O.V.   ****** 13/07/15 ***
******** MAPRSCEX.H  *********** Dishlenko S.G.  ****** 04/04/12 ***
******** MAPRSCEX.H  *********** Shabakov D.A.   ****** 09/12/13 ***
******** MAPRSCEX.H  *********** Tarakanova I.R. ****** 04/02/14 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2016              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*       �������� ������� ������� � ����� ��'�����                  *
*       �������������� ������� ��� ��������������                  *
*       ������ ������                                              *
*        ��������� ��� �������� �� ������ C, PASCAL, BASIC         *
*                                                                  *
********************************************************************
*                                                                  *
*                 �������������� ������� :                         *
*                                                                  *
*    // �������� ����������                                        *
*    HINSTANCE libInst = ::LoadLibrary("gisacces.dll");            *
*                                                                  *
*    // ����� �������                                              *
*    long int (WINAPI * lpfn) (HRSC hRsc, long int code,           *
*                                        long int local);          *
*    (FARPROC)lpfn = GetProcAddress(libInst, "mapSeriaDelete");    *
*    long int retcode = (*lpfn)(hRsc, code, local);                *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef MAPRSCEX_H
#define MAPRSCEX_H

#ifndef MAPMACRO_H
 #include "mapmacro.h"
#endif

#ifndef RSCAPI_H
   #include "rscapi.h"
#endif

typedef struct ELEMTREEE
{
   int  Ident;           // ������������� ������� (��� 0, � ����)                  // 04/04/12
   int  Depth;           // ������� ����������� � ������
   int  LayerNumber;     // ����� ����
   int  ParentNumber;    // ����� �������� � ����� ������� ���������
   int  PictureIndex;    // ������ � ������� �����������
   char Code[28];        // ��������������� ������������� ����(��� �����������)
                         // � ��������� �������������� � ����� � �����������
}
  ELEMTREEE;


 typedef struct SERIALIMIT          // ��������� �������� ���������,���������-
                                    // ������ ������������ ����� ��������
  {
    int    Code        ;            // ��� ���������                              // 04/04/12
    int    Count       ;            // ���������� ������������� (>=2)
    double   Value[256];            // �������� �������������
  }
   SERIALIMIT;


 typedef struct SERIATYPE           // ���������� ������ � �����
  {
    unsigned int Excode      ; // ����������������� ��� ��'����� �����            // 04/04/12
    int           Local      ; // �������� �����������  ��'����� �����
    int           Count      ; // ���������� �������� �����
    int           FirstCode  ; // ��� ������ ���������
    int           FirstCount ; // ���������� ������������� �� 1 ���������
    int           SecondCode ; // ��� ������ ���������
    int           SecondCount; // ���������� ������������� �� 2 ���������
#if defined(_M_X64) || defined(BUILD_DLL64)
    int           SeriaTypeZero; // ������������                                // 04/12/13
#endif
  }
   SERIATYPE;

 typedef struct SERIAPLACE          // ����� ������� � �����
  {
    int FirstCode   ;          // ��� ���������                                    // 04/04/12
    int FirstNumber ;          // ����� ������������ (� 1)
    int SecondCode  ;          // ��� ��������� ,���� ����� �� �����
                               // ���������,�� ����� ����
    int SecondNumber;          // ����� ������������ (� 1)
  }
   SERIAPLACE;

// ��� �������� ����� �������� ����������:
// - ������� ����� �� �������� ������� ������� � ���������� �������� ��������
//   ( mapSeriaCreate );
// - �������� ��������� ������� � ��������� ����� � ��������� �� �����
//   ( mapSeriaAppendObject );
// - ��� ������������� ��������� ����� �������� � �����
//   ( mapSeriaSetObject );
// - ������ ��� (�� ����������� ���� ��� ������� ������� �����)
//   ( mapSetRscObjectImage ��. RSCAPI.H);

extern "C"
{

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++ �������� ������� ������� � ����� ��'�����    ++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 // ������� �����
 // hRsc - ������������� �������������� �����
 // RSCOBJECT -  �������� ������� (��. maptype.h)
 // first, second - ��������� �������� �������� �����
 // ���� ����� �� ����� ���������, second = 0
 // ��� ������ ���������� 0, ����� - ���������� ��� �������

_MAPIMP long int _MAPAPI mapSeriaCreate(HRSC hRsc, SERIALIMIT * first,
                                       SERIALIMIT * second, RSCOBJECT * object);

 // �������� �����
 // hRsc - ������������� �������������� �����
 // code - ����������������� ��� �������� �������� � c����
 // local - ����������� �������� ����� ( LOCAL_POINT, ...)
 // first, second - ��������� �������� �������� �����
 // ���� ����� �� ����� ���������, second = 0
 // ���� ����� � ����� ����� � ������������ ��� , ��� ���������
 // ���� ����� ������ ��� ����� ��� ���� - �� ����������� �����������
 // � �����(� ����� ���������), ��� ������� ������������ - ������ �����
 // ���������, ����� ��������� - ��� ������� �����������
 // ���� ����� �� ����� ��������� second = 0
 // ��� ������ ���������� 0, ����� - ���������� ��� �������

_MAPIMP long int _MAPAPI mapSeriaUpdate(HRSC hRsc, long int code,
                                 long int local, SERIALIMIT * first,
                                 SERIALIMIT * second);


 // �������� ������ � ������������ �����
 // hRsc - ������������� �������������� �����
 // RSCOBJECT -  �������� ������� (��. maptype.h)
 // SERIAPLACE - ����� ������� � �����
 // ��� ������ ���������� 0, ����� - ���������� ��� �������

_MAPIMP long int _MAPAPI mapSeriaAppendObject(HRSC hRsc, RSCOBJECT * object,
                                                 SERIAPLACE * place);

 // ������� �����
 // hRsc - ������������� �������������� �����
 // code - ����������������� ��� �������� �������� � c����
 // local - ����������� �������� ����� ( LOCAL_POINT, ...)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSeriaDelete (HRSC hRsc, long int code, long int local);

 // ��������� ���������� �� �����
 // hRsc - ������������� �������������� �����
 // code - ����������������� ��� �������� �������� � c����
 // local - ����������� �������� ����� ( LOCAL_POINT, ...)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSeriaDescribe(HRSC hRsc, long int code,long int local,
                                          SERIATYPE * seria);

 // ��������� ���������� �� ��������� ������������� ��������� �����
 // hRsc - ������������� �������������� �����
 // incode - ���������� ��� ( ������ ) ������ ������� �����
 // limit->Code - ��� ������������� ���������
 // ��� ������ ���������� ����, ����� ����� ��������� � ����� (1 ��� 2)
 // �� ������ limit - ������ ���� ������  sizeof(SERIALIMIT)

_MAPIMP long int _MAPAPI mapSeriaDescribeLimit(HRSC hRsc, long int incode,
                                               SERIALIMIT * limit);

  // ��������� ����� ������� � ����� (������ ����� �����������)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ( ������ ) �������
  // ��� ������ ���������� ���� , ����� - ���������� ��� �������

_MAPIMP long int _MAPAPI mapSeriaSetObject(HRSC hRsc, long int incode,
                                           SERIAPLACE * place);

  // ��������� ���������� ��� ������� �� ����� � �����
  // hRsc - ������������� �������������� �����
  // code - ����������������� ��� �������� �������� � c����
  // local - ����������� �������� ����� ( LOCAL_POINT, ...)
  // ��� ������ ���������� ���� , ����� - ���������� ��� �������

_MAPIMP long int _MAPAPI mapSeriaGetObject(HRSC hRsc, long int code,long int local,
                                           SERIAPLACE * place);

  // ��������� ��������� ���� �������� ����� (�� �������)      //10/12/01
  // hRsc - ������������� �������������� �����
  // code - ����������������� ��� �������� �������� � c����
  // local - ����������� �������� ����� ( LOCAL_POINT, ...)
  // semanticcode - ��� ���������
  // importance ���������� ���������  ��. maptype.h
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC) )

_MAPIMP long int _MAPAPI mapSeriaSetObjectSemantic(HRSC hRsc, long int code,long int local,
                                                   long int semanticcode, long int importance);

 // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 // +++++ �������� �������������� ������� ������� � �������    ++++++
 // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  // �������� �������                                                // 27/11/01
  // hRsc - ������������� �������������� �����
  // palette - ����� �������,count - ���������� ������ � ������� (16,32,64,256)
  // name    - �������� �������
  // ��� ������ ���������� ���� ����� 1

_MAPIMP long int _MAPAPI mapRscAppendPaletteUn(HRSC hRsc, COLORREF * palette,
                                        long int count,WCHAR *wname);

_MAPIMP long int _MAPAPI mapRscAppendPalette(HRSC hRsc, COLORREF * palette,
                                             long int count,const char *name);

  // ���������� ���������� ������ � ��������������            // 27/11/01
  // hRsc - ������������� �������������� �����
  // count - ���������� ������ � ������� (16,32,64,256)
  // ��� ������ ���������� ���� ����� 1

_MAPIMP long int _MAPAPI mapRscSetColorCount(HRSC hRsc,long int count);

 // ��������� ������� �������������� �� ����������� ������ (� 1)    // 27/11/01
 // hRsc - ������������� �������������� �����
 // number - ���������� ����� �������
 // ���������� ��������� �� �������
 // ��� ������ ���������� ����

_MAPIMP COLORREF * _MAPAPI mapRscGetPalette(HRSC hRsc,long int number);

 // ��������� ������������� ������� ����� � ���������� �������     // 22/03/16
 // hRsc - ������������� �������������� �����
 // color -  ������� ���� �������� ����� ������� ������� ����� (c 0 �� 255),
 //          ������� ���� ����� 0x0F (������� �������� ���������� �����)
 // function - ����� ������� ����������� (mapgdi.h)
 // param - ����� ����������
 // ����������: 1 - ������������, 0 - �� ������������ 

 _MAPIMP long int _MAPAPI mapRscCheckParamColor(HRSC hRsc, COLORREF color, long int function,
                                           const char * param);


 // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 // ++++  �������� �������������� ������� ������� � �����������  +++
 // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 // ��������� ���������� ��������� ������������                 // 16/10/04
 // hRsc - ������������� �������������� �����
 // ��� ������ ��� ���������� ������������ ��������� ���������� ����

_MAPIMP long int _MAPAPI mapGetRscImlCount(HRSC hRsc);

 // ��������� ���������� ����� ���������� ������������(� 1)       // 30/01/02
 // hRsc - ������������� �������������� �����
 // ��de - ��� ����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscImlOrder(HRSC hRsc,long code);

 // ������ ������� ���������� (� 1) �� ����������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscImlIndex(HRSC hRsc,int number);  // 23/04/06

 // ������ ���� �� ����������� ������ ���������� (c 1)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscImlCode(HRSC hRsc,int number);   // 23/04/06

 // ��������� ��� ���������� �� ����������� ������ (c 1)
 // hRsc - ������������� �������������� �����
 // ��� ������ ���������� ������ ������

_MAPIMP long int _MAPAPI mapGetRscImlNameDLLUn(HRSC hRsc,long int number,
                                               WCHAR * wname,long int size);
_MAPIMP const char * _MAPAPI mapGetRscImlNameDLL(HRSC hRsc,long int number);

 // ��������� �������� ��� ���������� �� ����������� ������ (c 1)
 // hRsc - ������������� �������������� �����
 // ��� ������ ���������� ������ ������

_MAPIMP long int _MAPAPI mapGetRscImlNameUn(HRSC hRsc,long int number,
                                     WCHAR * wname,long int size);
_MAPIMP char * _MAPAPI mapGetRscImlName(HRSC hRsc,long number);

 // �������� ����������
 // hRsc - ������������� �������������� �����
 // nameDll - ��� ����������
 // nameUser - �������� ���
 // ���������� ��� ����������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapAppendRscImlUn(HRSC hRsc, WCHAR * wnameDll, WCHAR * wnameUser);
_MAPIMP long int _MAPAPI mapAppendRscIml(HRSC hRsc, char * nameDll,char * nameUser);


 // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 // +++++ �������� ������� ���������� ������ �������� ��������������  ++++
 // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 // ��� ������������� ������ �������� ����������:
 // ��������� ������������ ������
 // �������� ������ ��� ���������� ������� ���������� �������� ELEMTREEE,
 // ������� ������� ���������� ������
 // ��������� �������� �� �������. ��� ���� incode ����� 0
 // � ������� �������� ������ ����� �������� - ��������

  // ��������� ������������ ����� ��������� ������ ��������
_MAPIMP long int _MAPAPI mapCountRscTreeObject(HRSC hRsc);

  // ��������� ������ ����������� �� Rsc � ������� � ���������� ������� ������
  // hRsc - ������������� �������������� �����
  // hSelect - ������������� ������� (����� ���� 0)
  // size    - ������ ���������� ������� ��� ���������� ������(� ������)
  // elemtree - ��������� �� ���������� �������
  // ���������� ������ ���������� ��������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapBuildRscTree(HRSC hRsc, HSELECT hSelect, long size,
                               ELEMTREEE * elemtree);


 // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 // +++++ �������������� ���������� ������� ����������� ��������      ++++
 // +++++                 ����� ���������� DRAW                       ++++
 // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  // ������� ������������� ���������� ������ ����������        // 24/01/08
  // HDRW - maptype.h
  // �������� ������ ��� ������ � ������� ����������
  // ����� ������������� ���������� � ������� ������� mapFreeDraw()
  // hDrw - ������������� ������ ����������

_MAPIMP HDRAW _MAPAPI mapCreateDraw();

  // ���������� ��������� ������ ����������
  // hDrw - ������������� ������ ����������
  // ����������� ������ ��� ������ � ������� ����������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapFreeDraw(HDRAW hDrw);

  // ��������� ��������� � ����� ����������
  // hDrw - ������������� ������ ����������
  // param - ������, ��� ��������� ���������
  // number - ����� ������� ���� IMG_XXXXXXX (��. MAPGDI.H)
  // length - ����� ����������� ����������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapCopyMemoryToDraw(HDRAW hDrw, long int number,
                                             const char * param);

  // ��������� ����� ���������� � ������
  // hDrw - ������������� ������ ����������
  // buffer - ����� ������ ���� ����������� ���������
  // length - ������ ������ ��� �������� �� ����� mapDrawLength()
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapCopyDrawToMemory(HDRAW hDrw, char * buffer,
                                             long int length);

  // ��������� ����� ����� ������ ����������
  // hDrw - ������������� ������ ����������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapAllDrawLength(HDRAW hDrw);

  // ��������� ���������� ��������� ������ ����������
  // hDrw - ������������� ������ ����������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapRscDrawCount(HDRAW hDrw);       // 17/09/09

  // ��������� ��� �������� ������ ����������
  // �� ��� ������ ( �� 1 �� mapDrawCount())
  // hDrw - ������������� ������ ����������
  // ���������� ����� ������� ���� IMG_XXXXXXX (��. MAPGDI.H)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDrawElementImage(HDRAW hDrw, long int number);

  // ��������� ����� ���������� �������� ������ ����������
  // �� ��� ������ ( �� 1 �� mapDrawCount())
  // hDrw - ������������� ������ ����������
  // ���������� ����� ��������� ���� IMGXXXXXX, � ������������
  // � ����� �������� (��. MAPGDI.H)
  // ��� ������ ���������� 0

_MAPIMP char * _MAPAPI mapDrawElementParameters(HDRAW hDrw, long int number);

  // ��������� ����� ���������� �������� ������ ����������
  // �� ��� ������ ( �� 1 �� mapDrawCount())
  // hDrw - ������������� ������ ����������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDrawElementLength(HDRAW hDrw, long int number);

  // �������� ������� � ����� ����������
  // hDrw - ������������� ������ ����������
  // image - ��� �������� (��. MAPGDI.H)
  // param - ����� ���������� ��������
  // ��� ������ ���������� ����,����� - ����� ��������� � ������

_MAPIMP long int _MAPAPI mapAppendElementDraw(HDRAW hDrw, long int image,
                                              const char * parm);

  // �������� ������� � ����� ���������� c �������������� ���������� // 09/02/16
  // hDrw - ������������� ������ ����������
  // image - ��� �������� (��. MAPGDI.H)
  // ��� ������ ���������� ����,����� - ����� ��������� � ������

_MAPIMP long int _MAPAPI mapAppendElementDrawWithInit(HDRAW hDrw, long int image);

  // �������� ��������                                               // 09/02/16
  // hDrw - ������������� ������ ����������
  // number - ����� ����������� ��������� ( �� 1 �� mapDrawCount())
  // image - ��� �������� (��. MAPGDI.H)
  // param - ����� ���������� ��������
  // ��� ������ ���������� ����,����� ����� ��������� � ������

_MAPIMP long int _MAPAPI mapReplaceElementDraw(HDRAW hDrw, long int number,
                             long int image, const char * parm);

  // �������� ��������  �� ������  c �������������� ����������     13/04/16
  // hDrw - ������������� ������ ����������
  // number - ����� ����������� ��������� ( �� 1 �� mapDrawCount())
  // image - ��� �������� (��. MAPGDI.H)
  // ��� ������ ���������� ����,����� ����� ��������� � ������

_MAPIMP long int _MAPAPI mapReplaceElementWithInitDraw(HDRAW hDrw, long int number,
                             long int image);


  // ����������� ��������                                           // 09/02/16
  // hDrw - ������������� ������ ����������
  // oldnumber - ����� ������ ����� �������� ( �� 1 �� mapDrawCount())
  // newnumber - ����� ���� �������� �������� ( �� 1 �� mapDrawCount())
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapMoveElementDraw(HDRAW hDrw, long int oldnumber,
                             long int newnumber);

  // ������� ��� �������� ������������ �������� �������
  // hDrw - ������������� ������ ����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRscClearDraw(HDRAW hDrw);                // 17/09/09

  // ������� ������� ������������ �������� �������
  // hDrw - ������������� ������ ����������
  // number - ����� �������� (������� � 1)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteElementDraw(HDRAW hDrw, long int number);

  // �������� ��������� ������������ �������� ������� �������� ���� IMGMULTIMARK
  // ��������� �� ��� - �����
  // name - ��� �����
  // � BMP �� ����� 256 ������ (�� ������)
  // ������� ����� 32*32 - ����������
  // ��� ������ ���������� ����                  // 31/01/08
_MAPIMP long int _MAPAPI mapAppendBMPtoDraw(HDRAW hDrw, const char * name);

 // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 // +++++                 �������������� �������                      ++++
 // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  // ������ ������� �����e� ������� ��������� �� ����������� ����   // 14/04/16
  // hRsc - ������������� �������������� �����
  // incode - ���������� ���
  // ���������� ������ �� 0 �� 15

_MAPIMP long int _MAPAPI mapGetRscObjectTop(HRSC hRsc,long int incode);

  // ������ ������� ������ ������� ��������� �� ����������� ����    // 14/04/16
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� 
  // ���������� ������ �� 0 �� 15

_MAPIMP long int _MAPAPI mapGetRscObjectBottom(HRSC hRsc,long int incode);



} // extern "C"

#endif
