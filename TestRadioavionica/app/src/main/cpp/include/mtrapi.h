/****** MTRAPI.H *************** Belenkov O.V.   ****** 26/05/16 ***
******* MTRAPI.H *************** Gorbunov A.V.   ****** 17/02/14 ***
******* MTRAPI.H *************** Kruzhkov A.E.   ****** 27/02/14 ***
******* MTRAPI.H *************** Shabakov D.A.   ****** 11/07/16 ***
******* MTRAPI.H *************** Derevyagina Zh.A.***** 16/12/10 ***
******* MTRAPI.H *************** Borzov   A.U.   ****** 14/03/14 ***
******* MTRAPI.H *************** Konon    V.N.   ****** 28/01/16 ***
******* MTRAPI.H *************** Zheleznyakov V.A. **** 06/06/16 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2016              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*       �������� ������ ������� � ��'���� "����������� �����"      *
*        ��������� ��� �������� �� ������ C, PASCAL, BASIC         *
*                                                                  *
********************************************************************
*                                                                  *
*    �������������� ������� � Windows :                            *
*                                                                  *
*    // �������� ����������                                        *
*    HINSTANCE libInst = ::LoadLibrary("gisacces.dll");            *
*                                                                  *
*    // ����� �������                                              *
*    HMAP (WINAPI * lpfn_OpenMtr)(const char*, long int);          *
*    (FARPROC)lpfn_OpenMtr = GetProcAddress(libInst, "OpenMtr");   *
*    HMAP hMap = (*lpfn_OpenMtr)("Noginsk.mtw",0);                 *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef MTRAPI_H
#define MTRAPI_H

#ifndef MAPCREAT_H
  #include "mapcreat.h"
#endif

#ifndef MAPOLD_H
  #include "mapold.h"
#endif

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++ �������� ������� ������� � �������� +++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
extern "C"
{

  // ������� ��������� ������
  // ���������� ������������� �������� ��������� ����� (TMapAccess*)
  // mtrname - ��� ������������ �����
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapOpenMtr(const char *mtrname, long int mode = 0);
_MAPIMP HMAP _MAPAPI mapOpenMtrUn(const WCHAR *mtrname, long int mode = 0);

  // ������� ��������� ������ � �������� ������ �����
  // (�������� � ������� ������)
  // ���������� ����� ����� � ������� ������
  // hMap - ������������� �������� �������� ��������� �����
  // mtrname - ��� ������������ �����
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapOpenMtrForMap(HMAP hMap, const char *mtrname, long int mode);
_MAPIMP long int _MAPAPI mapOpenMtrForMapUn(HMAP hMap, const WCHAR *name, long int mode);

  // ������� ��������� ������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����������� �������
  // ���� number == 0, ����������� ��� ������� � ����
  // ����� ���������� ��� ������� - ����� ������� mapCloseData(hMap)

_MAPIMP void _MAPAPI mapCloseMtr(HMAP hMap, long int number);

  // ������� ��������� ������ � �������� ������ �����
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ���������� ����� � �������
  // ���� number == 0, ����������� ��� ��������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCloseMtrForMap(HMAP hMap, long int number);

  // ��������� ����� �������� �������������� �������
  // hMap    - ������������� �������� ��������� �����
  // number  - ����� �������
  // ���������� ��������� ����� �������������� (��������) �� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrSystemTime(HMAP hMap, long int number, SYSTEMTIME *time);

  // ���������� ������� �� ��������� ����� �� �������� ������� ������ �����
  // ��� ������ ���������� ����
  // hMap    - �������� ����� ��� ���������� �������
  // mtrname - ������ ��� ����������� �������
  // filtername - ������ ��� ������� ��������
  //   ������ � ������ ����� ������������� ������ �������� -
  //   ��������� ���� MTRCREA.IMH, ���������� �������� �����
  //   ��������, ������������ ��� ���������� ������� (��. MAPAPI.DOC)
  // ���� filtername ����� ���� - ������ �������� �� ������������
  // mtrparm - ��������� ����������� �������,
  // handle   - ������������� ���� �������, �������� ����������
  // ��������� � ���� �������� :
  //   0x0581 - ��������� � �������� ����������� ����� (� WPARAM),
  //   ���� ������� ������ ���� ������������� ��������, � �����
  //   ������ ��������� �������� 0x0581.
  // ���� handle ����� ���� - ��������� �� ����������.
  // �������� LPARAM (�� ������ 0) ��������� � ���� �������� �������� �����
  // ����� ���������� ������� :
  //   1 - ���������� ������� ����������� �������� ��������
  //   2 - ��������� �������� ����������� � ���������� �������
  //   3 - ��������� �������� ����������� � ���������� �������
  //   4 - ��������� �������� �������� � ���������� �������
  //   5 - ����������� ����������� � ������������ ������
  //   6 - ���������� ������������� ��������� �������
  //   9 - ���������� ������� �������������� �������� ��������
  //   10 - �������� ������� ���������
  //   11 - �������� ������� �� ���������
  //   13 - ��������� ������ ��������� ������������
  //   14 - ���������� ��������� ������� �� ����� �������� �����
  //   15 - ���������� ����� ������������� �� �������� ������
  //   16 - ������ �������
  //   17 - ���������� ����� �� ���������� ������� ��������� ��������

_MAPIMP long int _MAPAPI mapBuildMtw(HMAP hMap, const char *mtrname, const char *filtername,
                                     BUILDMTW *mtrparm, HWND handle);
_MAPIMP long int _MAPAPI mapBuildMtwUn(HMAP hMap, const WCHAR *mtrname, const WCHAR *txtname,
                                       BUILDMTW *mtrparm, HWND handle);

 // ���������� ������ ������� �� ��������� ����� �� ��������
 // ������� ������ �����
 // ��� ������ ���������� ����
 // hMap    - �������� ����� ��� ���������� ������,
 // rstname - ������ ��� ������������ ������,
 // filtername - ������ ��� ���������� ���������� �����
 //   ������ � ������ ������ ������������� ������ �������� -
 //   ��������� ��������� ���� M�P2RSW.INI, ���������� �������� �����
 //   ��������, ������������ ��� ���������� ������
 // mtrparm - ��������� ������������ ������,
 // handle   - ������������� ���� �������, �������� ����������
 // ��������� � ���� �������� :
 //   0x0581 - ��������� � �������� ����������� ����� (� WPARAM),
 //   ���� ������� ������ ���� ������������� ��������, � �����
 //   ������ ��������� �������� 0x0581.
 // ���� handle ����� ���� - ��������� �� ����������

_MAPIMP long int _MAPAPI mapBuildRsw(HMAP hMap, const char *rstname, const char *filtername,
                                     BUILDMTW *mtrparm, HWND handle);
_MAPIMP long int _MAPAPI mapBuildRswUn(HMAP hMap, const WCHAR *rstname, const WCHAR *filtername,
                                       BUILDMTW *mtrparm, HWND handle);

  // �������� ��� ��������� ������, �������� �� ��� �������
  // hMap    - ������������� �������� ��������� �����
  // number  - ����� �������, ��� ������� ����� �������� ���, ��� -1 (��� �������)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapClearMtrCache(HMAP hMap, long int number);


  /*********************************************************
  *                                                        *
  *           ������ ������ �� ������� �����               *
  *                                                        *
  *     ��� ������ "ERRORHEIGHT" ����� (-111111.0)         *
  *  (�.�. ���� �������� ������ ������ (-111 ��) - ������) *
  *                                                        *
  *********************************************************/

  // ��������� �������� ����� ��������� ������
  // hMap - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // describe - ����� ���������, � ������� ����� ���������
  // �������� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrDescribe(HMAP hMap, long int number, MTRDESCRIBE *describe);
_MAPIMP long int _MAPAPI mapGetMtrDescribeUn(HMAP hMap, long int number, MTRDESCRIBEUN *describe);

  // ��������� �������� ��������� ����� ������� � �������
  // hMap - ������������� �������� �������� ��������� �����
  // number � �������
  // colornumber - ����� ��������� �����
  // colordesc - ����� ���������, � ������� ����� ���������
  // �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrColorDescEx(HMAP hMap, long int number,
                                              long int colornumber,
                                              MTRCOLORDESCEX *colordesc);

  // ��������� ��� ����� ��������� ������
  // hMap - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapGetMtrName(HMAP hMap, long int number);

  // ��������� ��� ����� ��������� ������
  // hMap - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrNameUn(HMAP hMap, long int number,
                                         WCHAR *name, long int size);

  // ��������� ����� �������� ������ ��������� ������
  // hMap - ������������� �������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrCount(HMAP hMap);

  // ��������� ����� ������� � ������� �� ����� �����
  // name - ��� ����� �������
  // � ������� ������ ������� ���������� � 1.
  // ��� ������ ���������� ����
_MAPIMP long int _MAPAPI mapGetMtrNumberByName(HMAP hMap, const char* name);
_MAPIMP long int _MAPAPI mapGetMtrNumberByNameUn(HMAP hMap, const WCHAR *name);

  // ��������� ����������� �������� ������������ ������� � ������ � ������ �����
  // ��� ����������� ������� �� ����� ������������ �������� �����
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // frame  - ����� ���������, � ������� ����� ��������� �������� ������� � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetActualMtrFrame(HMAP hMap, DFRAME *frame, long int number);

  // ��������� �������� �������  � ������ � ������ �����
  // number     - ����� ����� � �������
  // location   - ���������� ���-��������� ���� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrLocation(HMAP hMap, long int number, DOUBLEPOINT *location);

  // ���������� �������� �������  � ������ � ������ �����
  // number     - ����� ����� � �������
  // location   - ���������� ���-��������� ���� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrLocation(HMAP hMap, long int number, DOUBLEPOINT *location);

  // ������ ������� ����� ������� �� �������� �������
  // hMap  - ������������� �������� �������� ��������� �����
  // frame - ����� ���������, ���������� �������� ��������� ������� � ������
  // ���� frame ����� ����, �� �������� ������� ������������ ���������� �����
  // ��� ������� ����� ������� ���������� 1, ��� ���������� ���������� 0

_MAPIMP long int _MAPAPI mapHeightValuePresence(HMAP hMap, DFRAME *frame);

  // ����� �������� ���������� ������ � �������� �����.
  // hMap   - ������������� �������� �������� ��������� �����
  // ���������� ����� (x,y) �������� � ������ � ������� ���������
  // ��������� �����. ���������� �������� ������ � ������.
  // � ������ ������ ��� ������ ������ � � ������ ����������������
  // �������� ����� ���������� ������� ���������� ERRORHEIGHT

_MAPIMP double _MAPAPI mapGetHeightValue(HMAP hMap,double x, double y);

  // ����� �������� ���������� ������ � �������� ����� �� �������
  // � ������� number � �������.
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ������� � �������.
  // ���������� ����� (x,y) �������� � ������ � ������� ���������
  // ��������� �����. ���������� �������� ������ � ������.
  // hpaint - �������� ��������� �������������� ������ (��. mapCreatePaintControl)
  // � ������ ������ ��� ������ ������ � � ������ ����������������
  // �������� ����� ���������� ������� ���������� ERRORHEIGHT

_MAPIMP double _MAPAPI mapGetHeightValueOfMtr(HMAP hMap, long int number,
                                              double x, double y);

_MAPIMP double _MAPAPI mapGetHeightValueOfMtrControl(HMAP hMap, long int number, double x,
                                                double y, HPAINT hPaint);

  // ���������� ����������������� ������ � �������� �����
  // hMap   - ������������� �������� �������� �����
  // number - ����� ������� ����� � �������
  // interptype - ��� ������������
  //              1 - ��������� �����
  //              2 - ������������ �� ��������� 3 ���������
  //              3 - ���������� ������������ �� 4 ��������� ���������
  //              4 - ������������ ������������ �� 16 ��������� ���������
  // x, y - ���������� ����� � ������
  // h    - ������������ �������� � ������ (��� ������ ��������������� ERRORHEIGHT)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetHeightValueOfMtrEx(HMAP hMap, long int number,
                                                  long int interptype,
                                                  double x, double y, double *h);

  // ������ �������� ������� ����� �� ���������� ��������
  // hMap   - ������������� �������� �����
  // number - ����� ����� � �������
  // value  - ���������� �������� �������� � ������
  // string - ������ ������ ������� (�������� �� 0 �� height-1, ��� height - ������
  //          ������� ���������, ������������� �������� mapGetMtrHeightInElement)
  // column - ������ ������� ������� (�������� �� 0 �� width-1, ��� width - ������
  //          ������� ���������, ������������� �������� mapGetMtrWidthInElement)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrPoint(HMAP hMap, long int number, double *value,
                                        long int string, long int column);

  // ��������� ������ �������� ������� � ������ �� ��� X
  // number    - ����� ����� � �������
  // metinelemX - ������ �������� �������� ������ �� ��������� �� ��� X
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrMeterInElementX(HMAP hMap, long int number, double *metinelemX);

  // ��������� ������ �������� ������� � ������ �� ��� Y
  // number    - ����� ����� � �������
  // metinelemY - ������ �������� ������� � ������ �� ��������� �� ��� Y
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrMeterInElementY(HMAP hMap, long int number, double *metinelemY);

  // ��������� �������� ���������� ������ � ������� �������,
  // ��������������� �������� �����.
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ������� � �������.
  // ���������� ����� (x,y) � �������� ������ (h) �������� � ������
  // � ������� ��������� ��������� �����.
  // � ������ ������ ���������� ����

_MAPIMP long int _MAPAPI mapPutHeightValue(HMAP hMap, long int number,
                                           double x, double y, double h);


  // ����� �������� ���������� ������ � �������� ����� ��
  // ������� � ���������� �������� �������� (����� ������)
  // hMap   - ������������� �������� �������� ��������� ����� 
  // ���������� ����� (x,y) �������� � ������ � ������� ���������
  // ��������� �����. ���������� �������� ������ � ������.
  // hPaint - ������������� ��������� ����������� ��� �������������� ������ �������,
  //          ��������� �������� mapCreatePaintControl, ������������� - mapFreePaintControl
  // � ������ ������ ��� ������ ������ � � ������ ����������������
  // �������� ����� ���������� ������� ���������� ERRORHEIGHT

_MAPIMP double _MAPAPI mapGetPrecisionHeightValue(HMAP hMap, double x, double y);
_MAPIMP double _MAPAPI mapGetPrecisionHeightValueEx(HMAP hMap, double x, double y, HPAINT hPaint);


  // ������ ���������� ������ ������� ������������� � �������� �����
  // �� ������� � ���������� �������� �������� (����� ������).
  // ������ ����������� �� ����� ������ ������� �����,� � ������
  // ���������������� �������� ����� ������� ������ ����� -
  // �� ����� ������ ������� �����.
  // hMap   - ������������� �������� �������� ��������� �����
  // ���������� ����� (x,y) �������� � ������ � ������� ���������
  // ��������� �����. ���������� �������� ������ � ������.
  // hPaint - ������������� ��������� ����������� ��� �������������� ������ �������,
  //          ��������� �������� mapCreatePaintControl, ������������� - mapFreePaintControl
  // � ������ ������ ��� ������ ������ � � ������ ����������������
  // �������� ����� ���������� ������� ���������� ERRORHEIGHT

_MAPIMP double _MAPAPI mapGetPrecisionHeightTriangle(HMAP hMap, double x, double y);
_MAPIMP double _MAPAPI mapGetPrecisionHeightTriangleEx(HMAP hMap,double x, double y, HPAINT hPaint);

  // ������ ���������� ������ ������� ������������� � �������� �����
  // �� ������� � ������� number � �������
  // ���������� ����� (x,y) �������� � ������ � ������� ���������
  // ��������� �����. ���������� �������� ������ � ������.
  // � ������ ������ ��� ������ ������ � � ������ ����������������
  // �������� ����� ���������� ������� ���������� ERRORHEIGHT

_MAPIMP double _MAPAPI mapGetHeightTriangleOfMtr(HMAP hMap, long int number,
                                                 double x, double y);

  // ������ �������� �������� ���������� ������ �� ������� ���������� �������
  // ������� ����� �������������� ��� �������� ������� ����������� �������
  // xcenter, ycenter - ���������� ������ ������� � ������
  // size - ������ ������� ������� � ������ (������ �������� ������� ����������� �������)
  // ���������� ������� �������� ������ � ������
  // � ������ ������ ��� ������ ����� � � ������ ����������������
  // �������� ������� ���������� ������� ���������� ERRORHEIGHT

_MAPIMP double _MAPAPI mapGetGeneralHeight(HMAP hMap, double xcenter,
                                           double ycenter, double size);

  // ������ �������� �������� ���������� ������ �� ������� ���������� �������
  // ������� � ������� number � �������
  // ������� ����� �������������� ��� �������� ������� ����������� �������
  // xcenter, ycenter - ���������� ������ ������� � ������
  // size - ������ ������� ������� � ������ (������ �������� ������� ����������� �������)
  // ���������� ������� �������� ������ � ������
  // � ������ ������ ��� ������ ����� � � ������ ����������������
  // �������� ������� ���������� ������� ���������� ERRORHEIGHT

_MAPIMP double _MAPAPI mapGetGeneralHeightOfMtr(HMAP hMap, long int number, double xcenter,
                                                double ycenter, double size);

  // ��������� ����� � ������� ��� �������, �������������
  // � �������� �����
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ���������� �����, ��������� ������� � �����
  // (1 - ������ � ������ �����, 2 - ������ ...)
  // ��� ������ ������������ ����

_MAPIMP long int _MAPAPI mapGetMtrNumberInPoint(HMAP hMap,double x,
                                                double y, long int number);

 // ���������� �������� ������� ��������� � ����������� ������ �������������     // 15/04/16
 // �� �������� ����� (����������� ��� ��������� OGC WCS-��������)
 // hmap   - ������������� ���������, ����������� �������� ������� ����� (MTW)
 // matrix - ��������� �� ����� �������� ������� 4-�� �������� ������������� ���������
 // width  - ������ �������� ������� (����� ��������� � ������)
 // hight  - ������ �������� ������� (����� �����)
 // unit   - ������� ��������� ������ � ������� (0 - �����, 1 - ���������, 2 - ����������, 3 - ����������)
 // dframe - �������� ������� �� ��������� � ������� ��������� ������� (� ���������)
 //          �� ���-��������� �������� ������� �� ������-����������
 // minvalue - ���� ��� ������ ������������ �������� �������� � �������� �������
 // maxvalue - ���� ��� ������ ������������� �������� �������� � �������� �������
 // hpaint - �������� ��������� �������������� ������ (��. mapCreatePaintControl)
 // � ������ ���������������� �������� ����� ���������� ������� � ������� ������������ ERRORHEIGHT (-111111)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetPrecisionHeightFrame(HMAP hmap, int * matrix, long int width, long int hight,
                                                    long int unit, DFRAME * dframe,
                                                    long int * minvalue, long int * maxvalue, HPAINT hpaint);

  // ����� ������� �������� ���������� �����, ���������������
  // ���������� ���������, ������� �� �������� �������.
  // hMap   - ������������� �������� �������� ��������� ����� 
  // ���������� �����, �������� ������ � ����� �������
  // (FirstPoint,SecondPoint) �������� � ������ � �������
  // ��������� ��������� �����.
  // ������ ������� �����, ��������� ������� HeightArray,
  // ������ ��������������� �������������� ���������� �����
  // (HeightCount), � ��������� ������ �������� ������ ������
  // � �������.
  // � ������ ���������������� ����������� �������� ����������
  // ������� ��� �������� ����� ERRORHEIGHT (-111111.0 �)
  // � ������ ������ ��� ������ ����� ���������� ����

_MAPIMP long int _MAPAPI mapGetHeightArray(HMAP hMap, double *HeightArray,
                                           long int HeightCount,
                                           const DOUBLEPOINT *FirstPoint,
                                           const DOUBLEPOINT *SecondPoint);


  // ��������� ������ ������� ����� ������� � ������
  // hMap   - ������������� �������� �������� ��������� ����� 
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrBlockSize(HMAP hMap, long int number);

  // ��������� ������(���) �������� ������� � ������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������.
  // ������������ �������� 1 ������������� ���� "unsigned char".
  // ������������ �������� 2 ������������� ���� "short int".
  // ������������ �������� 4 ������������� ���� "long int".
  // ������������ �������� 8 ������������� ���� "double".
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrElementSize(HMAP hMap, long int number);


  // ��������� ������������ ������ ����� ������� � ���������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrBlockSide(HMAP hMap, long int number);


  // ��������� �������������� ������ ����� ������� � ���������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrBlockWidth(HMAP hMap, long int number);

  // ��������� ������ �������� ����� ������� � ���������
  // (� ������ ��������� ������)
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrCurrentBlockWidth(HMAP hMap, long int number,
                                                    long int column);

  // ��������� ������ �������� ����� ������� � ���������
  // (� ������ ��������� ������)
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP   long int _MAPAPI mapGetMtrCurrentBlockHeight(HMAP hMap, long int number,
                                                       long int string);

  // ��������� ������ �������� ����� ������� � ������
  // (� ������ ��������� ������)
  // number - ����� ����� � �������
  // string, column - ������ � ������� ����� �������������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrCurrentBlockSize(HMAP hMap, long int number,
                                                   long int string, long int column);

  // ��������� ����� ����� ������� �� ������ ������ � �������
  // ����� ���������� ���� ����� ����� ��������� ������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // string, column - ������ � ������� ����� �������������
  // ��� ������� ���������� ����� ����� ������� ������� �����
  // ��� ������ ���������� ����, ����� - ����� ���������� �����

_MAPIMP char* _MAPAPI mapGetMtrBlockAddress(HMAP hMap, long int number,
                                            long int string, long int column);

  // ��������� ����� ����� ������� �� ������ ������ � �������
  // string, column - ������ � ������� ����� �������������
  // ��� ���������� � ����� - ���������
  // ��� ������� ���������� ����� ����� ������� ������� �����
  // ��� ������ ���������� ����

_MAPIMP char* _MAPAPI mapGetMtrBlockAndCreate(HMAP hMap, long int number,
                                              long int string, long int column);

  // ������ ����� {string,column} � ���� ������� �� ������ bits
  // number   - ����� ����� � �������
  // bits     - ��������� �� ������ ����������� ������� �������
  // sizebits - ������ ������� bits � ������
  // ���������� ���������� ���������� ����.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapWriteMtrBlock(HMAP hMap, long int number, long int string,
                                          long int column, char *bits, long int sizebits);

  // ������� ����� ����������� ����� �������
  // (0 - �� ������������, 1- ������������, 2 - �������� ������ )
  // number - ����� ����� � �������
  // i - ���������� ����� (������) �����, i = str * blockColumnCount + col, ���:
  //     str - ������ ������ ������,
  //     blockColumnCount - ����� �������� ������ ������� (������� mapGetMtqBlockColumn)
  //     col - ������ ������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCheckMtrBlockVisible(HMAP hMap, long int number, long int i);

  // ��������� ����� ����� ������ �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrBlockRow(HMAP hMap, long int number);

  // ��������� ����� �������� ������ �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrBlockColumn(HMAP hMap, long int number);


  // ��������� ����� ����� ��������� � �������
  // hMap   - ������������� �������� �������� ��������� ����� 
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrElementRow(HMAP hMap, long int number);


  // ��������� ����� �������� ��������� � �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrElementColumn(HMAP hMap, long int number);

  // ��������� ������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrScale(HMAP hMap, long int number);

  // ��������� �������� �������� ������ � ������� ������ ��������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // �� ������ bottomScale ������������ ����������� �������� ������ ������� ��������� �������
  // �� ������ topScale ������������ ����������� �������� ������� ������� ��������� �������
  // ��� ������ ���������� ����
_MAPIMP long int _MAPAPI mapGetMtrRangeScaleVisible(HMAP hMap, long int number,
                                                    long int *bottomScale,
                                                    long int *topScale);

  // ���������� �������� �������� ������ � ������� ������ ��������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // bottomScale - ����������� �������� ������ ������� ��������� �������
  // topScale    - ����������� �������� ������� ������� ��������� �������
  //               bottomScale <= topScale, ����� ���������� 0
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrRangeScaleVisible(HMAP hMap, long int number,
                                                   long int bottomScale,
                                                   long int topScale);

  // ��������� ��� �������� �����
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrMapType(HMAP hMap, long int number);

  // ��������� ������� ��������� �������� ����� �������
  // � ������� number � �������.
  // ���������� �������� ���� Unit ��������� ���������� ��������
  // ������� BUILDMTW
  // ������������ �������� :
  //   0-�����, 1-���������, 2-����������, 3-����������
  // hMap - ������������� �������� �������� ��������� �����
  // ��� ������ ���������� -1

_MAPIMP long int _MAPAPI mapGetMtrMeasure(HMAP hMap, long int number);

  // ������ - �������������� �� �������� � �������������
  // ����������� �� ������� ������������� � �������
  // hMap     - ������������� �������� �������� �����
  // number   - ����� ����� � �������
  // ���� ��� - ���������� ����

  _MAPIMP long int _MAPAPI mapIsMtrGeoSupported(HMAP hMap, long int number);

  // ��������� ������ � �������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // projectiondata - ����� ���������, � ������� ����� ���������
  // ������ � ��������
  // ��������a MTRPROJECTIONDATA ������a � maptype.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrProjectionData(HMAP hMap, long int number,
                                                 MTRPROJECTIONDATA *projectiondata);

  // ��������� ������ � �������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // mapregister - ����� ���������, � ������� ����� ���������
  // ������ � ��������
  // ��������a MAPREGISTEREX ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrProjectionDataEx(HMAP hMap, long int number,
                                                   MAPREGISTEREX *mapregister);

  // ��������� ������ � �������� ������� �� ����� �����
  // name        - ��� ����� �������
  // mapregister - ����� ���������, � ������� ����� ���������
  // ������ � ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrProjectionDataByName(const char *name,
                                                       MAPREGISTEREX *mapregister);
_MAPIMP  long int _MAPAPI mapGetMtrProjectionDataByNameUn(const WCHAR *name,
                                                          MAPREGISTEREX *mapregister);

  // ���������� ������ � �������� �������
  // ��������: ������ ������ � �������� ������� ��������� ������ mapregister->Scale
  // � ��������� �������.
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ������� � �������.
  // mapregister - ����� ���������, ���������� ������ � ��������
  // ��������a MAPREGISTEREX ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrProjectionData(HMAP hMap, long int number,
                                                 MAPREGISTEREX *mapregister);

  // ���������� ������ � �������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ������� � �������.
  // mapregister, datumparam, ellipsoidparam - ������ ��������, ���������� ������ � ��������
  // ��������� MAPREGISTEREX, DATUMPARAM, ELLIPSOIDPARAM ������� � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrProjectionDataEx(HMAP hMap, long int number,
                                                   MAPREGISTEREX  *mapregister,
                                                   DATUMPARAM     *datumparam,
                                                   ELLIPSOIDPARAM *ellipsoidparam);

  // �������� ��������� ������� � ����
  // hMap       - ������������� �������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveMtr(HMAP hMap, long int number);

  // ��������� ��������� ���������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� ������� � �������
  // ellipsoidparam - ����� ���������, � ������� ����� ���������
  // ��������� ����������
  // ��������a ELLIPSOIDPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrEllipsoidParam(HMAP hMap, long int number,
                                                 ELLIPSOIDPARAM *ellipsoidparam);

  // ���������� ��������� ���������� �������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� ������� � �������.
  // ellipsoidparam - ����� ���������, ���������� ��������� ����������
  // ��������a ELLIPSOIDPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrEllipsoidParam(HMAP hMap, long int number,
                                                 const ELLIPSOIDPARAM *ellipsoidparam);

  // ��������� ������������ ����������������� ������������� ��������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� ������� � �������
  // datumparam - ����� ���������, � ������� ����� ���������
  // ������������ ����������������� ������������� ���������
  // ��������a DATUMPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrDatumParam(HMAP hMap, long int number,
                                             DATUMPARAM *datumparam);

  // ���������� ������������ ����������������� ������������� ��������� �������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� ������� � �������.
  // datumparam - ����� ���������, ���������� ������������ �����������������
  // ������������� ���������
  // ��������a DATUMPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrDatumParam(HMAP hMap, long int number,
                                             const DATUMPARAM *datumparam);

 // ���������� �������� ���������� ������ (point->H) � ��������       // 22/04/16
 // ����� (point->X,point->Y) �� ������ ��������� �����
 // ���������� ����� �������� � ������ � ������� ���������
 // ��������� �����
 // � ������ ������ ��� ���������� ������ ���������� 0

_MAPIMP long int _MAPAPI mapCalcAbsoluteHeight(HMAP hMap, XYHDOUBLE* point);

 // ���������� �������� ���������� ������ � ��������                  // 22/04/16
 // ����� (point->X,point->Y) �� ������ ��������� �����
 // ���������� ����� �������� � ������ � ������� ���������
 // ��������� �����
 // sectorcount - ���������� ����������� ��� ������ ���������� �����
 // (������ ���� ������ 4, ����������� ���������� ����������� = 4,
 //  ������������ = 256)
 // ���������� �������� ������ � ������
 // � ������ ������ ��� ���������� ������ ���������� ERRORHEIGHT

_MAPIMP double _MAPAPI mapCalcAbsoluteHeightBySectors(HMAP hMap,
                                                      DOUBLEPOINT* point,
                                                      long int sectorcount);

  /*********************************************************
  *                                                        *
  *          ���������� ������������ �������               *
  *                                                        *
  *********************************************************/

  // ���������/���������� ������� ��������� �������
  //  hMap   - ������������� �������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  view = 0 - �� �����
  //  view = 1 - ������
  //  view = 2 - ����������
  //  view = 3 - ��������������
  //  view = 4 - �������
  //  view = 5 - ����������

_MAPIMP long int _MAPAPI mapGetMtrView(HMAP hMap,long int number);
_MAPIMP long int _MAPAPI mapSetMtrView(HMAP hMap,long int number,
                                       long int view);

  // ��������� ������������ ������� �������                   // 19/01/14
  // number - ����� ����� � �������
  // ���������� ������� ������������ � ��������� �� 0 �� 100

_MAPIMP long int _MAPAPI mapGetMtrTransparent(HMAP hMap, long int number);

  // ���������� ������������ ������� �������                  // 19/01/14
  // hMap   - ������������� �������� ������
  // number - ����� ����� � �������
  // transparent - ������������ � ��������� �� 0 �� 100
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrTransparent(HMAP hMap, long int number,
                                              long int transparent);

  // ���������/���������� ������� ����������� �������
  //  hMap   - ������������� �������� �������� ��������� ����� 
  //  number - ����� ����� � �������
  //  order  - ������� (0 - ��� ������, 1 - ��� ������)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrViewOrder(HMAP hMap, long int number, long int order);
_MAPIMP long int _MAPAPI mapGetMtrViewOrder(HMAP hMap, long int number);

  // �������� ����������� ����������� ������ (mtr) � �������
  //   oldNumber - ����� ����� � �������
  //   newNumber - ��������������� ����� ����� � �������
  //  ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapChangeOrderMtrShow(HMAP hMap, long int oldNumber,
                                                          long int newNumber);

  // ����������/��������� ������� ���� ������� �����
  //  hMap  - ������������� �������� �������� ��������� �����
  //  value - ���� ��������� ���� (�� 0 �� 16)
  //   MTRSHADOW_NONE   =  0,   // ���� �����������
  //   MTRSHADOW_PALE   =  1,   // �������
  //   MTRSHADOW_WEAK   =  2,   // ������
  //   MTRSHADOW_MIDDLE =  4,   // �������
  //   MTRSHADOW_HEAVY  =  8,   // �������
  //   MTRSHADOW_DEEP   = 16,   // ��������

_MAPIMP long int _MAPAPI mapGetMtrShadow(HMAP hMap);
_MAPIMP long int _MAPAPI mapSetMtrShadow(HMAP hMap, long int value);


  // ����������/��������� ������������� ���� ������� �����
  //  hMap  - ������������� �������� �������� ��������� �����
  //  value - ������������� ���� (�� 0 �� 100)

_MAPIMP long int _MAPAPI mapGetMtrShadowIntensity(HMAP hMap);
_MAPIMP long int _MAPAPI mapSetMtrShadowIntensity(HMAP hMap, long int value);

  // ��������� ����� ������ � ������� ������ �����
  // ��� ������� ����� �������� � ����� ��������
  //  hMap   - ������������� �������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrPaletteCount(HMAP hMap);

  // ��������� ������� ������� ������� �����
  // (� ������ �������/�������������)
  // hMap    - ������������� �������� �������� ��������� ����� 
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrPalette(HMAP hMap, COLORREF *palette, long int count);

  // ��������� ��������� ������� ������� �����
  // (��� ����� �������/������������)
  // hMap    - ������������� �������� �������� ��������� ����� 
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrStandardPalette(HMAP hMap, COLORREF *palette, long int count);

  // ���������� �������� ������� ������� �����
  // hMap    - ������������� �������� �������� ��������� �����
  // palette - ����� ��������������� �������
  // count   - ����� ��������� � ����� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrPalette(HMAP hMap, COLORREF *palette, long int count);


  // ��������� ������� ������� ������� �����
  // hMap   - ������������� �������� �������� ��������� �����

_MAPIMP long int _MAPAPI mapGetMtrBright (HMAP hMap);

  // ���������� ������� ������� ������� �����
  // hMap   - ������������� �������� �������� ��������� ����� 
  // bright - �������� ������� (-16..+16) 
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrBright (HMAP hMap, long int bright);


  // ��������� ������������� ������� ������� �����
  // hMap     - ������������� �������� �������� ��������� ����� 
  // �������� ��������� (-16..+16) 
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrContrast (HMAP hMap);

  // ���������� ������������� ������� ������� �����
  // hMap     - ������������� �������� �������� ��������� ����� 
  // contrast - �������� ��������� (-16..+16) 
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrContrast (HMAP hMap, long int contrast);

  // ��������� ����� ������� ������� �����
  // hMap     - ������������� �������� �������� ��������� ����� 
  // ������������ ��������:
  //  0  - ����������� �������
  //  1  - ������� �������
  // -1  - ������������ ������ ���� �� �������     

_MAPIMP long int _MAPAPI mapGetMtrColorStyle(HMAP hMap);

  // ���������� ����� ������� ������� �����
  // hMap       - ������������� �������� �������� ��������� ����� 
  // colorstyle - ����� ����������� �������:
  //  0  - ����������� �������
  //  1  - ������� �������
  // -1  - ������������ ������ ���� �� �������     
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrColorStyle (HMAP hMap, long int colorstyle);

  // ���������� ���� ��������� ����� ������� � �������
  // number � �������
  // hMap        - ������������� �������� �������� ��������� ����� 
  // colornumber - ����� ��������� �����
  // color       - ���� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrColor(HMAP hMap, long int number,
                                        long int colornumber, COLORREF color);

  // ���������� ����� ������� �� ������� ���������� �������
  // ��������� ������ ������ ����� �� ����� 4-� �����
  // hMap       - ������������� �������� �������� ��������� ����� 
  // number     - ����� ����� � �������
  // info       - ��������� ������ �����
  // ����� ���������� ������� ����������� ������� ����������� �������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrBorder(HMAP hMap, long int number, HOBJ info);


  // ���������� ����� ������� �� ������� ���������� �������
  // ��������� ������ ������ ����� �� ����� 4-� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ��������� ������ �����
  // flagSubject- ���� ������������� ����������� ������� ��� ��������� ����� �������  (0/1)
  //              0 - � �������� ����� ������� ��������������� ������ �������
  //              1 - � �������� ����� ������� ��������������� ������ ������� � ������������
  // ����� ���������� ������� ����������� ������ ����������� �������� ��������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetMtrBorderEx(HMAP hMap, long int number,
                                            HOBJ info, long int flagSubject);

  // ������� ����� �������
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ����� ���������� ������� ����������� ������� ����� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteMtrBorder(HMAP hMap, long int number);

  // ����������� ������������� ����� �������
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCheckExistenceMtrBorder(HMAP hMap, long int number);

  // ����������� ������� ����������� �������(������������ �����)
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ���������� 1 - ��� ����������� ������� �� �����
  //            0 - ��� ����������� ������� ��� ����� �����
  // ��� ������ ���������� -1

_MAPIMP long int _MAPAPI mapCheckShowMtrByBorder(HMAP hMap, long int number);

  // ��������� ����������� ������� �� �����
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // value = 1 - ���������� �������  �� �����
  //       = 0 - ���������� ��������  ��� ����� �����

_MAPIMP long int _MAPAPI mapShowMtrByBorder(HMAP hMap, long int number, long int value);

  // ��������� ������ ����� �������
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ������������� ������� ����� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrBorder(HMAP hMap, long int number,HOBJ info);

  // ���������� ���������� � ���������� ����� ����� �����, �������
  // ������ � ������������� �������� ������(�������) �
  // ����� ���������� �������� �� ����� pointIn (���������� � ������).
  // �� ������ pointOut ������������ ���������� ��������� ����� � ������
  // hMap       - ������������� �������� �������� ��������� ����� 
  // number     - ����� ����� � �������
  // ��� ������ ��� ���������� ����� ���������� 0.

_MAPIMP long int _MAPAPI mapGetImmediatePointOfMtrBorder(HMAP hMap, long int number,
                                                         DOUBLEPOINT *pointIn,
                                                         DOUBLEPOINT *pointOut);

  // ��������� ��������� �������
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ������������ ��������:
  //          0 - ��� ������; ��� �������� ����������� ����� � ������ �� �����������
  //          3 - �������� ���� ������� ����������� �����, ������ RMF_COMPR_32 �������
  //          4 - �������� ���� ������� ����������� ����� �������

_MAPIMP long int _MAPAPI mapGetMtrProcessingState(HMAP hMap, long int number);

  // ���������� ��������� �������
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // state      - ��������� �������.
  // ��������� �������� ��������� ������� state:
  //          0 - ��� ������; ��� �������� ����������� ����� � ������ �� �����������
  //          3 - �������� ���� ������� ����������� �����, ������ RMF_COMPR_32 �������
  //          4 - �������� ���� ������� ����������� ����� �������
  // ��� ������ ���������� 0.

_MAPIMP long int _MAPAPI mapSetMtrProcessingState(HMAP hMap, long int number, long int state);

  // �������������� ������� ��� �������� � ��� ������                           
  // ������� ��������� ��������� ������� � ��� ������������� ��������� ��� �ţ
  // ����������� �� ������� � �������� ���� ������� ����������� �����.
  // ���������� ������� ������� �� ���� ���������� ����� ������� �������
  // mtrName- ��� ����� �������
  // handle - ������������� ����, ������� ����� ����������
  // � ���� �������� (0x585 - 0x588)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapOptimizationMtrByName(const char* mtrName, HWND handle);
_MAPIMP long int _MAPAPI mapOptimizationMtrByNameUn(const WCHAR* mtrName, HWND handle);


  // ��������� ���������� ��������� ����������� ����� � �������
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetMtrDuplicatesCount(HMAP hMap, long int number);

  // �������� ����������� �����
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapUpdateMtrDuplicates(HMAP hMap, long int number);

  /*********************************************************
  *                                                        *
  *          ���������� ����������� ������� �����          *
  *                                                        *
  *********************************************************/

  // ������� ����� ���������� ������������ ���������,
  // ������������ ��������� ��������� �����
  // hMap   - ������������� �������� �������� ��������� ����� 
  // number - ����� ����� � �������
  // width  - ������ �����������,
  // height - ������ �����������.
  // ���������� ������������� ��������� ������ (TMtr3D*)
  // ��� ������ ���������� ����

_MAPIMP HMTR3D _MAPAPI mapOpenMtr3D(HMAP hMap, long int width, long int height);


  // ������� ����� ���������� ������������ ���������
  // hMtr3D - ������������� ��������� ������ 3D ������������

_MAPIMP void _MAPAPI mapCloseMtr3D(HMTR3D hMtr3D);


  // ���������� �������� ��������� � ���������� ����
  // hMtr3D - ������������� ��������� ������ 3D ������������
  // parm   - ��������� ����������� (��. MAPTYPE.H)
  // hDC    - �������� �����������
  // ���������� ������� (������������� ������������ mapPaintMtr3Dx)

_MAPIMP void _MAPAPI mapPaintMtr3D(HMTR3D hMtr3D, HDC hDC, MTR3DVIEW* parm);


  // ���������� �������� ��������� � ���������� ����
  // hMtr3D - ������������� ��������� ������ 3D ������������
  // parm   - ��������� ����������� (��. MAPTYPE.H)
  // hDC    - �������� �����������

_MAPIMP void _MAPAPI mapPaintMtr3Dx(HMTR3D hMtr3D, HDC hDC, MTR3DVIEWEX* parm);

  // ��������� BITMAP � ������������ ��������� ��������� � ���������� ����
  // hMtr3D - ������������� ��������� ������ 3D ������������
  // parm   - ��������� ����������� (��. MAPTYPE.H)
  // ��� ������ ���������� ����

_MAPIMP HBITMAP _MAPAPI mapBuildMtr3D(HMTR3D hMtr3D, MTR3DVIEW* parm);

  // ��������� BITMAP � ������������ ��������� ��������� � ���������� ����
  // hMtr3D - ������������� ��������� ������ 3D ������������
  // parm   - ��������� ����������� (��. MAPTYPE.H)
  // ��� ������ ���������� ����

_MAPIMP HBITMAP _MAPAPI mapBuildMtr3Dx(HMTR3D hMtr3D, MTR3DVIEWEX* parm);

  /*********************************************************
  *                                                        *
  *          �������� ������� ��� �������� ������          *
  *                                                        *
  *********************************************************/

  // ������� ��������� �����
  // mtrname - ��� ����� ����������� �������
  // ���������� ������������� �������� ��������� �����
  // ��������� BUILDMTW,MTRPROJECTIONDATA ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapCreateMtw(const char *mtrname, BUILDMTW *mtrparm,
                                  MTRPROJECTIONDATA *mtrprojectiondata);
_MAPIMP HMAP _MAPAPI mapCreateMtwUn(const WCHAR *mtrname, BUILDMTW *mtrparm,
                                    MTRPROJECTIONDATA *mtrprojectiondata);

  // ����� �������������� ������� �������
  //   hMap - ������������� �������� ��������� ����� (TMapAccess *)
  //   number - ����� ����� � �������
  //   bits - ����� ����������� ������ ���������� �������
  //          (��. beginning)
  //   left - �������� ������� ������� ����� (� ���������)
  //   top - �������� ������� ������� ������ (� ���������)
  //   width - ������ ������� ������� (� ���������)
  //   height - ������ ������� ������� (� ���������)
  //   beginning - ����������, �� ����� ������ ��������� bits :
  //     ���� beginning == 0, �� bits ���������
  //       �� ������ ������� ������ ���������� �������
  //     ���� beginning == 1, �� bits ���������
  //       �� ������ ������ ������ ���������� �������.
  //   ������ �������, ��������� ������� bits, ������ ���� �� �����
  //   (width * height * ������ �������� ������� � ������),
  //   � ��������� ������ �������� ������ ������ � �������.
  //   ������ ������� �������� ������� � ������
  //   - ������� mapGetMtrElementSize.
  //   ������ ���������� ������� ������ ���� ��������
  //   � ������� bits � �������� ��������� ����� ������ �������.
  //   ������ ������� ��������� ������ �������
  //   - ������� mapGetMtrMeasure.
  // ��� ������ ���������� ����

_MAPIMP long int  _MAPAPI mapPutMtrFrame(HMAP  hMap, long int number, char *bits,
                                         long int left, long int top,
                                         long int width, long int height,
                                         long int beginning/* = 0*/);

  // ������ �������������� ������� ������� � �������� ������� ������
  // hMap - ������������� �������� ��������� ����� (TMapAccess *)
  // number - ����� ����� � �������
  // bits - ��������� �� ������ ������� ������
  // left - �������� ������� ������� ����� (� ���������)
  // top - �������� ������� ������� ������ (� ���������)
  // width - ������ ������� ������� (� ���������)
  // height - ������ ������� ������� (� ���������)
  // widthinbyte - �����a ������� ������� � ������
  // ������ �������, ��������� ������� bits, ������ ���� �� �����
  // (width * height * ������ �������� ������� � ������),
  // � ��������� ������ �������� ������ ������ � �������.
  // ������ ������� �������� ������� � ������ - ������� mapGetMtrElementSize.
  // ������ ������� ������������ � ������� bits � �������� ���������
  // �������� ����� ������ �������.
  // ������ ������� ��������� �������� ����� ������� - ������� mapGetMtrMeasure.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrFrame(HMAP hMap, long int number, char *bits,
                                        long int left, long int top,
                                        long int width, long int height,
                                        long int widthinbyte = 0);

  // ��������� �������� ����� ������� (��������� �������� ���� ������
  // �����, �����, TIN-�������)
  // hMap     - ������������� �������� ����� (TMapAccess*)
  // minvalue - ����������� ������ ��������� � ������
  // maxvalue - ������������ ������ ��������� � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetReliefRange(HMAP hMap, double *minvalue,
                                           double *maxvalue);

  // ������� � ������� �������� �������� �����
  // hMap     - ������������� �������� �������� ����� (TMapAccess *)
  // number   - ����� ������� � �������
  // minvalue - ����������� ������ ��������� � ������
  // maxvalue - ������������ ������ ��������� � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrShowRange(HMAP hMap, long int number,
                                            double minvalue, double maxvalue);


  // ��������� �������� �������� ����� �������
  // hMap     - ������������� �������� �������� ����� (TMapAccess *)
  // number   - ����� ������� � �������
  // minvalue - ����������� ������ ��������� � ������
  // maxvalue - ������������ ������ ��������� � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrShowRange(HMAP hMap, long int number,
                                            double *minvalue, double *maxvalue);

  // ���������� �������� ������������ ����� ���� ������� ������.
  // ������������� �������� � ������� �� ��������� (�����������
  // � INI-���� ���������)
  //   hMap - ������������� �������� �������� �����
  //   minvalue - ����������� ������ ��������� � ������
  //   maxvalue - ������������ ������ ��������� � ������
  //   viewOutRange - ���������� �������� �������, �������� �������
  //                  ��� ��������� (0 ��� 1). ���� viewOutRange == 0,
  //                  �� �������� ��� ��������� �� ������������.
  //                  ���� viewOutRange == 1, ��:
  //                - ��������, ������� �������� ����� < minvalue,
  //                  ������������ ������ ������ ������� �������;
  //                - ��������, ������� �������� ����� > maxvalue,
  //                  ������������ ��������� ������ ������� �������.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrHeightRangeEx(HMAP hMap,
                                        double minvalue,
                                        double maxvalue,
                                        long int viewOutRange);  // 27/02/14

  // ���������� �������� ������������ ����� ���� ������� ������.
  // ������� ������� �� ������������, ���� �� �������� ������,
  // �� �������� � �������� ��������.
  // ������������� �������� � ������� �� ��������� (�����������
  // � INI-���� ���������)
  //   hMap - ������������� �������� �������� �����
  //   minvalue - ����������� ������ ��������� � ������
  //   maxvalue - ������������ ������ ��������� � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrHeightRange(HMAP hMap, double minvalue,
                                              double maxvalue);


  // ��������� �������� ����� ������������ ���������
  // ������� ������.
  //   hMap - ������������� �������� �������� ����� (TMapAccess *)
  //   minvalue - ����������� ������ ��������� � ������
  //   maxvalue - ������������ ������ ��������� � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrHeightRange(HMAP hMap, double* minvalue,
                                              double* maxvalue);

  // ���������� ��������� �������� ����� ������������ ���������
  // ������� ������. ��������� �������� �������� � ���� ���������
  // ���� ������ �������.
  // hMap - ������������� �������� �������� ����� (TMapAccess *)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapResetMtrHeightRange(HMAP hMap);


  // ��������� ��������� ����������� ������� ������ ��� ���������
  // ����� ������ ������� � ��������� ������������ �����.
  // hMap - ������������� �������� �������� ����� (TMapAccess *)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrShowVariables(HMAP hMap);


  // ���������� �������� ��� �������
  // hMap   - ������������� �������� �������� ����� (TMapAccess *)
  // number - ����� ������� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtrUserName(HMAP hMap, long int number,
                                           char *username);
_MAPIMP long int _MAPAPI mapSetMtrUserNameUn(HMAP hMap, long int number,
                                             const WCHAR *username);

  // ��������� �������� ��� �������
  //   hMap - ������������� �������� �������� ����� (TMapAccess *)
  //   number - ����� ������� � �������
  // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapGetMtrUserName(HMAP hMap, long int number);

  // ��������� �������� ��� �������
  //   hMap   - ������������� �������� �������� ����� (TMapAccess *)
  //   number - ����� ������� � �������
  //   name   - ����� ������ � ������� ������������ �������� ��� �������
  //   namesize - ������ ������ � ������
  // ��� ������ ���������� ����
_MAPIMP long int _MAPAPI mapGetMtrUserNameUn(HMAP hMap, long int number,
                                             WCHAR *name, long int namesize);

  // ��������� ���������� ���-��������� ���� ������� � ������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� � �������
  // �� ������ x,y ������������ ���������� ��������� ����� � ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetSouthWestMtrPlane(HMAP hMap, long int number,
                                                 double *x, double *y);

  // ��������� �������� �������
  // (��������������� ����������� �� ������ ����������)
  // hMap - ������������� �������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetActiveMtr(HMAP hMap);

  // ���������� �������� �������
  // (��������������� ����������� �� ������ ����������)
  // hMap - ������������� �������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetActiveMtr(HMAP hMap, long int number);

  // ��������� ���� ��������������� �������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrEdit(HMAP hMap, long int number);

  // ��������� ������ �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // �� ������ fileSize ������������ ������ �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrFileSize(HMAP hMap, long int number, __int64 *fileSize);

  // ��������� ������ ������� (��������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrWidthInElement(HMAP hMap, long int number);

  // ��������� ������ ������� (��������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrHeightInElement(HMAP hMap, long int number);

  // ��������� �������� (����/����) �������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrAccuracy(HMAP hMap, long int number);

  // ��������� ���� ��������� �������� (�����) �������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrFlagLocationChanged(HMAP hMap, long int number);

  // ��������� ��� �������             /
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrType(HMAP hMap, long int number);

  // ��������� ���� ������ �������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtrCompress(HMAP hMap, long int number);

  // ������� � ������� ����� ����� ��������� ������ ������
  //   hMap - ������������� �������� ��������� ����� (TMapAccess *)
  //   number - ����� ������� � �������
  //   compressnumber - ����� ��������� ������ ������
  // ��� ������ ���������� 0

 _MAPIMP long int _MAPAPI mapSetMtrCompressNumber(HMAP hMap, long int number,
                                                  long int compressnumber);

 _MAPIMP long int _MAPAPI mapSetMtqCompressNumber(HMAP hMap, long int number,
                                                  long int compressnumber);

  // ������� ���� ������� �����
  // ������� ������������� ��� �������� ������� ����� � �e ��������� ������
  // ������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.mtw � *.mtw.01
  // ������ ������� DeleteTheFile()

_MAPIMP long int _MAPAPI mapDeleteMtrFile(const char *name);
_MAPIMP long int _MAPAPI mapDeleteMtrFileUn(const WCHAR *filename);

  // ������������� ��� ����� ������� �����
  // ������� ������������� ��� ���������������� ������� ����� � ţ ��������� ������
  // ������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.mtw � *.mtw.01
  // ������ ������� MoveTheFile()

_MAPIMP long int _MAPAPI mapMoveMtrFile(const char *oldname, const char *newname);
_MAPIMP long int _MAPAPI mapMoveMtrFileUn(const WCHAR *oldname, const WCHAR *newname);

  // ����������� ���� ������� �����
  // ������� ������������� ��� ����������� ������� ����� � ţ ��������� ������
  // ������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.mtw � *.mtw.01
  // ������ ������� CopyTheFile()

_MAPIMP long int _MAPAPI mapCopyMtrFile(const char *oldname, const char *newname, int exist = 0);
_MAPIMP long int _MAPAPI mapCopyMtrFileUn(const WCHAR *oldname, const WCHAR *newname, int exist = 0);

  // ������� ���������� ������� ������� �����
  // ��� ������������� �������� ����������� �������������� ������� (��������� �� 16x16, 24x24 � 32x32)
  // ������� ������ � ��������� imgsize
  // hmap      - ������������� �������� ��������� �����    
  // xmlname   - ��� ��������� xml-�����
  // imgpath   - ���� � ������������ ������� png
  // imgsize   - ������������� ������ ����������� (������� ��������),
  //             ���� ����� ����, �� ����� ������� ������ ����������� �������� 16x16, 24x24 � 32x32)
  // ������������ ������ ����������� 1024x1024
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapCreateMtrLegendToXML(HMAP hmap,                                                
                                                 const WCHAR * xmlname,
                                                 const WCHAR * imgpath,                                                 
                                                 long int imgsize); 

#ifndef HIDEMTQ

  /*********************************************************
  *                                                        *
  *                    ������� �������                     *
  *                                                        *
  *            ������ ������ - ����� ��������,             *
  * ��� ����������� �������� ����� �� ���������� ��������  *
  *                                                        *
  *********************************************************/

  // ������� ������� �������
  // ���������� ������������� �������� ��������� �����
  // mtqname - ��� ������������ �����
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapOpenMtq(const char *mtqname, long int mode = 0);
_MAPIMP HMAP _MAPAPI mapOpenMtqUn(const WCHAR *mtqname, long int mode = 0);

  // ������� ������� �������
  // hMap - ������������� �������� �������� �����
  // number - ����� ����������� �������
  // ���� number = 0, ����������� ��� ������� � ����
  // ����� ���������� ��� ������� - ����� ������� mapCloseData(hMap)

_MAPIMP void _MAPAPI mapCloseMtq(HMAP hMap, long int number = 0);

  // ������� ������ ������� ������� � �������� ������ �����
  // (�������� � ������� ������ �������)
  // hMap - ������������� �������� �������� �����
  // mtqname - ��� ������������ ����� 
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������
  // ���������� ����� ����� � ������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapOpenMtqForMap(HMAP hMap, const char *mtqname, long int mode);
_MAPIMP long int _MAPAPI mapOpenMtqForMapUn(HMAP hMap, const WCHAR *name, long int mode);

  // ������� ������ ������� ������� � �������� ������ �����
  // hMap   - ������������� �������� �������� �����
  // number - ����� ���������� ����� � �������
  // ���� number = 0, ����������� ��� ��������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCloseMtqForMap(HMAP hMap, long int number);

  // ��������� ��� ����� ������ ������� �������
  // hMap - ������������� �������� �������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapGetMtqName(HMAP hMap, long int number);
_MAPIMP long int _MAPAPI mapGetMtqNameUn(HMAP hMap, long int number, WCHAR *name, long int namesize);

  // ��������� ����� ����� ������� ������� � ������� �� ����� �����
  // � ������� ������ ������ ������� ���������� � 1
  // name - ��� ����� ������� �������
  // ��� ���������� ����� ������� ������� � ������� ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqNumber(HMAP hMap, const char *name);
_MAPIMP long int _MAPAPI mapGetMtqNumberByName(HMAP hMap, const char* name);
_MAPIMP long int _MAPAPI mapGetMtqNumberUn(HMAP hMap, const WCHAR *name);

  // ��������� ����� �������� ������ ������ �������
  // hMap - ������������� �������� �������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqCount(HMAP hMap);

  // ��������� �������� ����� ������� �������
  // hMap   - ������������� �������� �������� �����
  // number - ����� ����� � �������
  // describe - ����� ���������, � ������� ����� ���������
  // �������� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqDescribe(HMAP hMap, long int number, MTRDESCRIBE *describe);
_MAPIMP long int _MAPAPI mapGetMtqDescribeUn(HMAP hMap, long int number, MTRDESCRIBEUN *describe);

  // ��������� ������ �������� ������� ������� � ������
  // hMap   - ������������� �������� �������� �����
  // number - ����� ����� � �������
  // ������������ �������� 1 ������������� ���� "unsigned char".
  // ������������ �������� 2 ������������� ���� "short int".
  // ������������ �������� 4 ������������� ���� "long int".
  // ������������ �������� 8 ������������� ���� "double".
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqElementSize(HMAP hMap, long int number);


  // ���������/���������� ����������� ������� �������
  // hMap - ������������� �������� �������� �����
  // number - ����� ����� � �������
  // view : 0 - ������� �� ����������, 1 - ����������

_MAPIMP long int _MAPAPI mapGetMtqView(HMAP hMap, long int number);
_MAPIMP long int _MAPAPI mapSetMtqView(HMAP hMap, long int number, long int view);

  // ���������/���������� ������� ����������� ������� �������
  // hMap   - ������������� �������� �������� �����
  // number - ����� ����� � �������
  // order  - ������� ����������� (0 - ��� ������, 1 - ��� ������)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqViewOrder(HMAP hMap, long int number, long int order);
_MAPIMP long int _MAPAPI mapGetMtqViewOrder(HMAP hMap, long int number);

  // �������� ����������� ����������� ������ (mtq) � �������
  // hMap   - ������������� �������� �������� �����
  // oldNumber - ����� ����� � �������
  // newNumber - ��������������� ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapChangeOrderMtqShow(HMAP hMap, long int oldNumber,
                                                          long int newNumber);

  // ���������/���������� ���� ������� ��������
  // hMap   - ������������� �������� �������� �����
  // number - ����� ����� � �������
  // value  - ���� ��������� ���� (1 - ���� ����, 0 - ��� ����)

_MAPIMP long int _MAPAPI mapGetMtqShadow(HMAP hMap,long int number);
_MAPIMP long int _MAPAPI mapSetMtqShadow(HMAP hMap,long int number, long int value);

  // ������� ������� �������
  // ���������� ������������� �������� ��������� ����� (TMapAccess*)
  // ��������� BUILDMTW,MTRPROJECTIONDATA ������� � maptype.h
  // palette - ��������� �� �������
  // countpalette - ���������� ������ � �������
  // name - ��� ����� ����������� �������

_MAPIMP HMAP _MAPAPI mapCreateMtq(const char *name, BUILDMTW *parm,
                                  MTRPROJECTIONDATA *projectiondata,
                                  COLORREF* palette, int countpalette);
_MAPIMP HMAP _MAPAPI mapCreateMtqUn(const WCHAR *name, BUILDMTW *parm,
                                    MTRPROJECTIONDATA *projectiondata,
                                    COLORREF *palette, int countpalette);

  // �������� ������������� ������� ������� ������� �� ������
  //   hMap - ������������� �������� ��������� �����
  //   number - ����� ������� � �������.
  //   bits - ����� ����������� ������ ������������� �������
  //          (��. beginning)
  //   left - �������� ������� ������� ����� (� ���������)
  //   top - �������� ������� ������� ������ (� ���������)
  //   width - ������ ������� ������� (� ���������)
  //   height - ������ ������� ������� (� ���������)
  //   beginning - ����������, �� ����� ������ ��������� bits :
  //     ���� beginning == 0, �� bits ���������
  //       �� ������ ������� ������ ���������� �������
  //     ���� beginning == 1, �� bits ���������
  //       �� ������ ������ ������ ���������� �������
  //   ������ �������, ��������� ������� bits, ������ ���� �� �����
  //   (width * height * ������ �������� ������� � ������),
  //   � ��������� ������ �������� ������ ������ � �������.
  //   ������ ������� �������� ������� ������� � ������
  //   - ������� mapGetMtqElementSize.
  //   �������� ��������� ������� ������� � ������� bits ������ ����
  //   �������� � �������� ��������� �������� ������ ������� �������.
  //   ������ ������� ��������� �������� ������� �������
  //   - ������� mapGetMtqMeasure.
  // ��� ������ ���������� ����

_MAPIMP long int  _MAPAPI mapPutMtqFrame(HMAP hMap, long int number, char *bits,
                                         long int left, long int top,
                                         long int width, long int height,
                                         long int beginning);

  // ���������� �������� ������������ ��������� ������� �������
  // hMap   - ������������� �������� �������� �����
  // number - ����� ������� � �������.
  // minvalue,maxvalue - ������� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqShowRange(HMAP hMap, long int number,
                                            double minvalue, double maxvalue);

  // ���������� ����� ����������� ��������� ������� �������
  // ��� ������ ���������, ��������� � ������� mapSetMtqShowRange
  // hMap   - ������������� �������� �������� �����
  // number - ����� ������� � �������.
  // viewUp - ���������� ��������, �������� ������� ������ �������
  //          ������� ��������� (�������� maxvalue ������� mapSetMtqShowRange)
  // viewDown - ���������� ��������, �������� ������� ������ ������
  //          ������� ��������� (�������� minvalue ������� mapSetMtqShowRange)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqViewOutRange(HMAP hMap, long int number,
                                               long int viewUp, long int viewDown);

  // ��������� �������� ������� ������� �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqPalette(HMAP hMap, COLORREF *palette,
                                          long int count, long int number);


  // ��������� ��������� ������� ������� �������
  // (��� ����� ������� � �������������)
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqStandardPalette(HMAP hMap, COLORREF *palette,
                                                  long int count, long int number);

  // ���������� �������� ������� ������� �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // palette - ����� ��������������� �������
  // count   - ����� ��������� � ����� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqPalette(HMAP hMap, COLORREF *palette,
                                          long int count, long int number);

  // ���������� ������� �������� ���������� ������������� ������� ������� �������
  // hMap     - ������������� �������� �������� �����
  // number   - ����� ������� � �������.
  // diapason - ����� ������� ��������������� �������� ����������
  // count    - ����� ��������� � ������� �������� ����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqPaletteDiapason(HMAP hMap, double *diapason,
                                                  long int count, long int number);

  // ������� ������� �������� ���������� ������������� ������� ������� �������
  // (������� ���������� �����������)
  // hMap     - ������������� �������� ��������� �����
  // number   - ����� ������� � �������.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUnsetMtqPaletteDiapason(HMAP hMap, long int number);

  // ��������� ������� �������� ���������� ������������� ������� � �����������
  // �������� �������� ������� �������
  // hMap     - ������������� �������� ��������� �����
  // minimum  - ����������� �������� �������� ������� (��������� �������)
  // diapason - ����� ������� ������� �������� ���������� (��������� �������)
  // count    - ����� ��������� � ������� �������� ����������
  // number   - ����� ������� � �������
  // ��� ������ � ��� ��������������� ������� ��������� ���������� ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqPaletteDiapason(HMAP hMap, double *minimum,
                                                  double *diapason, long int count,
                                                  long int number);

  // ��������� � ����� �������� ������� ������� �������
  // hMap    - ������������� �������� �������� �����
  // palette - ����� ����������� �������
  //           (���� palette = 0, �� � ���� ������������ �������
  //            ������� �������, ������������� �������� mapSetMtqPalette)
  // count   - ����� ��������� ����������� �������
  // number  - ����� ������� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveMtqPalette(HMAP hMap, COLORREF *palette,
                                           long int count, long int number);

  // ���������� �������� ���������������� ������� ������� �������
  // ���������������� ������� ����������� � �������������� �ң�
  // ������ (����������, ��������������, ���������), �������� �������
  // ���� ����������. ������������ ������������� ������ ������ ���������
  // ���������� ���������� �� ���������� ����� ��������� � ���������.
  // hMap - ������������� �������� �������� �����
  // firstColor - ����� ���������� ����� ������� ���������
  // mediumColor - ����� �������������� ����� (��������� �������
  //               ���������, ���������� ������� ���������)
  // lastColor - ����� ��������� ����� ������� ���������
  // count  - ����� ��������� � �������
  // mediumPosition - ����� �������������� ����� � �������,
  //                  (����� �� 0 �� count-1)
  // number - ����� ������� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqTwoIntervalPalette(HMAP hMap,
                                                     COLORREF firstColor,
                                                     COLORREF mediumColor,
                                                     COLORREF lastColor,
                                                     long int count,
                                                     long int mediumPosition,
                                                     long int number);

  // ���������/���������� ������� ������� ������� �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // bright  - ������� (-16..+16)

_MAPIMP long int _MAPAPI mapGetMtqBright(HMAP hMap, long int number);
_MAPIMP long int _MAPAPI mapSetMtqBright(HMAP hMap, long int number,
                                         long int bright);

  // ���������/���������� ������������� ������� ������� �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // contrast- �������� (-16..+16)

_MAPIMP long int _MAPAPI mapGetMtqContrast(HMAP hMap, long int number);
_MAPIMP long int _MAPAPI mapSetMtqContrast(HMAP hMap, long int number,
                                           long int contrast);

  // ��������� ����� ������ � ������� ������� �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // ��� ������ ������������ 0

_MAPIMP long int _MAPAPI mapGetMtqPaletteCount(HMAP hMap, long int number);

  // ��������� �������� ��������� �������� ������� � �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // colornumber - ����� ��������� ��������
  // colordesc - ����� ���������, � ������� ����� ���������
  // �������� ��������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqColorDescEx(HMAP hMap, long int number,
                                              long int colornumber,
                                              MTRCOLORDESCEX *colordesc);

  // ���������� ���� ��������� �������� ��������� ������� � �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // colornumber - ����� ��������� ��������
  // color - ���� ��� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqColor(HMAP hMap, long int number,
                                        long int colornumber,
                                        COLORREF color);

  // ����� �������� � �������� ����� �� �������
  // � ������� number � �������.
  // hMap   - ������������� �������� �������� �����
  // number - ����� ������� � �������.
  // ���������� ����� (x,y) �������� � ������.
  // ���������� �������� �������� � �ޣ��� ������� ���������.
  // ������������ �������� ����� �������� �������� �� ����� �������,
  // ��̣����� �� 10 � ������� n, ��� n = mapGetMtqMeasure().
  // � ������ ������ ��� ������ �������� � � ������ ����������������
  // �������� ����� ���������� ������� ���������� ERRORHEIGHT.

_MAPIMP double _MAPAPI mapGetMtqValue(HMAP hMap, long int number,
                                      double x, double y);

  // ���������� ����������������� �������� �� ������� �������
  // hMap   - ������������� �������� �������� �����
  // number - ����� ������� ������� � �������
  // interptype - ��� ������������
  //          1 - ��������� �����
  //          2 - ������������ �� ��������� 3 ���������
  //          3 - ���������� ������������ �� 4 ��������� ���������
  //          4 - ������������ ������������ �� 16 ��������� ���������
  // x, y  - ���������� ����� � ������
  // value - ������������ �������� (��� ������ ��������������� ERRORHEIGHT)
  // hPaint - ������������� ��������� ����������� ��� �������������� ������ �������,
  //          ��������� �������� mapCreatePaintControl, ������������� - mapFreePaintControl
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetMtqValueEx(HMAP hMap, long int number, long int interptype,
                                          double x, double y, double *value);
_MAPIMP double _MAPAPI mapGetMtqValuePro(HMAP hMap, long int number, long int interptype,
                               double x, double y, double *value, HPAINT hPaint);

  // ������ �������� ������� ������� �� ���������� ��������
  // hMap   - ������������� �������� �����
  // number - ����� ����� � �������
  // value  - ���������� �������� �������� � ������
  // string - ������ ������ ������� (�������� �� 0 �� height-1, ��� height - ������
  //          ������� ���������, ������������� �������� mapGetMtqHeightInElement)
  // column - ������ ������� ������� (�������� �� 0 �� width-1, ��� width - ������
  //          ������� ���������, ������������� �������� mapGetMtqWidthInElement)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqPoint(HMAP hMap, long int number, double *value,
                                        long int string, long int column);

  // ��������� �������� � ������� �������,
  // ��������������� �������� �����.
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // ���������� ����� (x,y) �������� � ������
  // � ������� ��������� �������� �������� � �ޣ��� ������� ���������.
  // ��������� �������� ����� h, ����������� �� 10 � ������� n,
  // ��� n = mapGetMtqMeasure().
  // � ������ ������ ���������� ����.

_MAPIMP long int _MAPAPI mapPutMtqValue(HMAP hMap, long int number,
                                        double x, double y, double h);

  // ��������� ����������� �������� ������������ ������� � ������ � ������ �����
  // ��� ����������� ������� �� ����� ������������ �������� �����
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // frame   - ����� ��� ���������� ����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetActualMtqFrame(HMAP hMap, DFRAME *frame,
                                              long int number);

  // ��������� ������� �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqScale(HMAP hMap, long int number);

  // ������ - �������������� �� �������� � �������������
  // ����������� �� ������� ������������� � �������
  // hMap     - ������������� �������� �������� �����
  // number   - ����� ����� � �������
  // ���� ��� - ���������� ����

  _MAPIMP long int _MAPAPI mapIsMtqGeoSupported(HMAP hMap, long int number);

  // ��������� ������ � �������� ��������� ������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // projectiondata - ����� ���������, � ������� ����� ���������
  // ������ � ��������
  // ��������a MTRPROJECTIONDATA ������a � maptype.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqProjectionData(HMAP hMap, long int number,
                                                 MTRPROJECTIONDATA *projectiondata);

  // ���������� ������ � �������� ��������� ������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������.
  // mapregister - ����� ���������, ���������� ������ � ��������
  // ��������a MAPREGISTEREX ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqProjectionData(HMAP hMap, long int number,
                                                 MAPREGISTEREX *mapregister);

  // ���������� ������ � �������� ������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ������� � �������.
  // mapregister, datumparam, ellipsoidparam - ������ ��������, ���������� ������ � ��������
  // ��������� MAPREGISTEREX, DATUMPARAM, ELLIPSOIDPARAM ������� � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqProjectionDataEx(HMAP hMap, long int number,
                                                   MAPREGISTEREX  *mapregister,
                                                   DATUMPARAM     *datumparam,
                                                   ELLIPSOIDPARAM *ellipsoidparam);

  // ��������� ������ � �������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // mapregister - ����� ���������, � ������� ����� ���������
  // ������ � ��������
  // ��������a MAPREGISTEREX ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqProjectionDataEx(HMAP hMap, long int number,
                                                   MAPREGISTEREX *mapregister);

  // ��������� ��������� ���������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� ������� � �������
  // ellipsoidparam - ����� ���������, � ������� ����� ���������
  // ��������� ����������
  // ��������a ELLIPSOIDPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqEllipsoidParam(HMAP hMap, long int number,
                                                 ELLIPSOIDPARAM *ellipsoidparam);

  // ���������� ��������� ���������� �������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� ������� � �������.
  // ellipsoidparam - ����� ���������, ���������� ��������� ����������
  // ��������a ELLIPSOIDPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqEllipsoidParam(HMAP hMap, long int number,
                                                 const ELLIPSOIDPARAM *ellipsoidparam);

  // ��������� ������������ ����������������� ������������� ��������� �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� ������� � �������
  // datumparam - ����� ���������, � ������� ����� ���������
  // ������������ ����������������� ������������� ���������
  // ��������a DATUMPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqDatumParam(HMAP hMap, long int number,
                                             DATUMPARAM *datumparam);

  // ���������� ������������ ����������������� ������������� ��������� �������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� ������� � �������.
  // datumparam - ����� ���������, ���������� ������������ �����������������
  // ������������� ���������
  // ��������a DATUMPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqDatumParam(HMAP hMap, long int number,
                                             const DATUMPARAM *datumparam);

  // ������ �������������� ������� ������� ������� � �������� ������� ������
  //   hMap - ������������� �������� �������� ����� (TMapAccess *)
  //   number - ����� ������� � �������.
  //   bits - ��������� �� ������ ������� ������
  //   left - �������� ������� ������� ����� (� ���������)
  //   top - �������� ������� ������� ������ (� ���������)
  //   width - ������ ������� ������� (� ���������)
  //   height - ������ ������� ������� (� ���������)
  //   widthinbyte - �����a ������� ������� � ������
  //   ������ �������, ��������� ������� bits, ������ ���� �� �����
  //   (width * height * ������ �������� ������� � ������),
  //   � ��������� ������ �������� ������ ������ � �������.
  //   ������ ������� �������� ������� ������� � ������
  //   - ������� mapGetMtqElementSize.
  //   �������� ��������� ������� ������� ������������ � ������� bits
  //   � �������� ��������� �������� ������ ������� �������.
  //   ������ ������� ��������� �������� ������� �������
  //   - ������� mapGetMtqMeasure.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqFrame(HMAP hMap, long int number, char *bits,
                                        long int left,  long int top,
                                        long int width, long int height,
                                        long int widthinbyte = 0);

  // ��������� ������� ��������� �������� ������� �������
  // hMap - ������������� �������� �������� ����� (TMapAccess *)
  // number - ����� ������� � �������.
  // �������� �������� � ����� ������� ����� �������� ��������,
  // ����������� �� 10 � ������� n, ��� n - ������� ���������.
  // ������� ���������� �������� ���� Unit ��������� ���������� ��������
  // ������� BUILDMTW
  // ������������ �������� :
  //   0-"�����", 1-"���������", 2-"����������", 3-"����������"
  // ��� ������ ���������� -1

_MAPIMP long int _MAPAPI mapGetMtqMeasure(HMAP hMap, long int number);

 // ���������� ���� ���������� �� ������ ������� ������ ����
 // ������� ���� �������� ��������� ������������ ����������� �������
 // � ���������� ���������� ����������� ������� �������, ��������
 // ������� �������� ������� � ���� ����������.
 // �������� ������� ������� ������������ ������������ ����� �
 // ��������� ������ ���� (������ pointArray) � ��������� ����������
 // ��������� ������� (areaExtension).
 // hMap    - �������� ����� � �������� ����� ��� ���������� ���� ����������,
 // mtqName - ������ ��� ����������� ������� �������,
 // pointArray - ����� ������� ����� � ��������� ������ ����
 //   ���������� ����� (pointArray->X,pointArray->Y) � �������� ������
 //   (pointArray->H) �������� � ������ � ������� ��������� ���������
 //   �����,
 // pointCount - ����� ����� � ������� pointArray
 //   ������ � ������ �������, ��������� ������� pointArray, ������
 //   ���� �� ����� pointCount * sizeof(XYHDOUBLE), � ��������� ������
 //   �������� ������ ������ � �������,
 // areaExtension - ������������� �����, �������� ��������
 //   ���������� ��������� ������� � ������,
 // minDepth - ������������� �����, �������� ����������� �������
 //   ���� ���������� � ������ (�������, ������� minDepth � �������
 //   ������� �� ���������),
 // handle - ������������� ���� �������, �������� ����������
 // ��������� � ���� �������� :
 //   0x0581 - ��������� � �������� ����������� ����� (� WPARAM),
 //   ���� ������� ������ ���� ������������� ��������, � �����
 //   ������ ��������� �������� 0x0581.
 //   ���� handle ����� ���� - ��������� �� ����������.
 // ��� ������ ���������� ����.

_MAPIMP long int _MAPAPI mapBuildFloodZone(HMAP hMap, const char *mtqName,
                                           XYHDOUBLE *pointArray, long int pointCount,
                                           double areaExtension, double minDepth, HWND handle);
_MAPIMP long int _MAPAPI mapBuildFloodZoneUn(HMAP hMap, const WCHAR *mtqName,
                                             XYHDOUBLE *pointArray, long int pointCount,
                                             double areaExtension, double minDepth, HWND handle);

 // ���������� ���� ���������� �� ������ ������� ������ ����
 // ������� ���� �������� ���������� ��������� ������
 // � ���������� ���������� ����������� ������� �������, ��������
 // ������� �������� ������� � ���� ����������.
 // �������� ������� ������� ������������ ������������ ����� �
 // ��������� ������ ���� (������ pointArray) � ��������� ����������
 // ��������� ������� (areaExtension).
 // hMap    - �������� ����� � �������� ����� ��� ���������� ���� ����������,
 // mtqName - ������ ��� ����������� ������� �������,
 // pointArray - ����� ������� ����� � ��������� ������ ����
 //   ���������� ����� (pointArray->X,pointArray->Y) � �������� ������
 //   (pointArray->H) �������� � ������ � ������� ��������� ���������
 //   �����,
 // pointCount - ����� ����� � ������� pointArray
 //   ������ � ������ �������, ��������� ������� pointArray, ������
 //   ���� �� ����� pointCount * sizeof(XYHDOUBLE), � ��������� ������
 //   �������� ������ ������ � �������,
 // areaExtension - ������������� �����, �������� ��������
 //   ���������� ��������� ������� � ������,
 // minDepth - ������������� �����, �������� ����������� �������
 //   ���� ���������� � ������ (�������, ������� minDepth � �������
 //   ������� �� ���������),
 // handle - ������������� ���� �������, �������� ����������
 // ��������� � ���� �������� :
 //   0x0581 - ��������� � �������� ����������� ����� (� WPARAM),
 //   ���� ������� ������ ���� ������������� ��������, � �����
 //   ������ ��������� �������� 0x0581.
 //   ���� handle ����� ���� - ��������� �� ����������.
 // ��� ������ ���������� ����.

_MAPIMP long int _MAPAPI mapBuildFloodZoneAbs(HMAP hMap, const char *mtqName,
                                              XYHDOUBLE *pointArray, long int pointCount,
                                              double areaExtension, double minDepth,
                                              HWND handle);
_MAPIMP long int _MAPAPI mapBuildFloodZoneAbsUn(HMAP hMap, const WCHAR *mtqName,
                                                XYHDOUBLE *pointArray, long int pointCount,
                                                double areaExtension, double minDepth,
                                                HWND handle);

 // ���������� ������� ������� �� ������� �������� �������������� ��������.
 // hMap - ������������� �������� �������� ����� ��� ���������� ������� �������
 // mtqName - ������ ��� ����������� ������� �������
 // palette - ����� ������� ����������� ������� �������,
 //           ���� palette ����� ���� - ������������ ������� �� ���������
 // countpalette - ���������� ������ � �������
 // pointArray - ����� ������� �������� �������������� ��������
 //              ���������� ����� (pointArray->X,pointArray->Y) �������� � ������
 //              � ������� ��������� ��������� �����
 // pointCount - ����� ����� � ������� pointArray
 //              ������ � ������ �������, ��������� ������� pointArray, ������
 //              ���� �� ����� pointCount * sizeof(XYHDOUBLE), � ��������� ������
 //              �������� ������ ������ � �������
 // elemSizeMeters - ������ ������� ������������� ������� � ������ �� ���������
 //                  (������� �������)
 // minValue,maxValue - �������� �������� �������������� �������� ����������� �������
 //                     �������, ���� minValue >= maxValue - � ������� ���������
 //                     ����������� �������� �������� �� ������� pointArray
 // handle - ������������� ���� �������, �������� ����������
 //          ��������� � ���� �������� :
 //          0x0581 - ��������� � �������� ����������� ����� (� WPARAM),
 //          ���� ������� ������ ���� ������������� ��������, � �����
 //          ������ ��������� �������� 0x0581.
 //          ���� handle ����� ���� - ��������� �� ����������.
 // ��� ������ ���������� ����.

_MAPIMP long int _MAPAPI mapBuildMtq(HMAP hMap, const char *mtqName,
                                     const COLORREF *palette, long int countpalette,
                                     const XYHDOUBLE *pointArray, long int pointCount,
                                     double elemSizeMeters, double minValue,
                                     double maxValue, HWND handle);
_MAPIMP long int _MAPAPI mapBuildMtqUn(HMAP hMap, const WCHAR *mtqName,
                                       const COLORREF *palette, long int countpalette,
                                       const XYHDOUBLE *pointArray, long int pointCount,
                                       double elemSizeMeters, double minValue,
                                       double maxValue, HWND handle);

 // ������������ ������� ������� �������
 // ��� ������������ �������������� ������� (resultPalette) ������������ ��������
 // ������� (skeletPalette), ���������� ������ �������������� �������
 // (resultColorCount) � ���� �������� ��������� ������ (smoothColorModification).
 // skeletPalette - �������� (���������) �������, ������ �������� sizeof(COLORREF)*256,
 //                 ���������� ��������� ����� ����������, �����̣���� �������
 //                 ���������� (�������� 0xFFFFFFFF);
 // resultPalette - �������������� �������, ������ �������� sizeof(COLORREF)*256;
 // resultColorCount - ���������� ����������� ������ �������������� �������
 //                    (�� ����� 256);
 // smoothColorModification - ���� �������� ��������� ������ �������������� ������� :
 //   0 - ���������� ����� ��������� ��������� ��������� ���� ���������,
 //   1 - ������������ ������������� ���������� ������ ��������� ����������
 //       ���������� �� ���������� ����� ��������� � ���������.
 // ����� �������� ������� ����������� � ��������������� ������� ��������������
 // �������, ��������� ����� �������������� ������� ����������� ������������� �
 // ����������� �� �������� ����� smoothColorModification.
 // ��� ������ ���������� ����.

_MAPIMP long int _MAPAPI mapMakeMtqPalette(COLORREF* skeletPalette,
                                           COLORREF* resultPalette,
                                           long int resultColorCount,
                                           long int smoothColorModification);

 // ���������� ������� ����������� (������� ������� ��� ������� �����)
 // �� ������ ��������� �����. ���� mtrparm->FileMtw ����� 1, �� ��������
 // ������� ����� (*.mtw), ����� �������� ������� ������� (*.mtq).
 // hMap - ������������� �������� �������� ����� ��� ���������� �������
 // mtrname - ������ ��� ����������� �������
 // mtrparm - ��������� ����������� ������� (��������� BUILDSURFACE ������� � maptype.h)
 // ��� ������ ���������� ����.

_MAPIMP long int _MAPAPI mapBuildMatrixSurface(HMAP hMap, const char *mtrname,
                                               BUILDSURFACE *mtrparm);
_MAPIMP long int _MAPAPI mapBuildMatrixSurfaceUn(HMAP hMap, const WCHAR *mtrname,
                                                 BUILDSURFACE *mtrparm);

  // ������� ������� �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteMtq(HMAP hMap, long int number);

  // ����������� ������� ����������� ������� (������������ �����)
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������
  // ���������� 1 - ��� ����������� ������� �� �����
  //            0 - ��� ����������� ������� ��� ����� �����

_MAPIMP long int _MAPAPI mapGetShowMtqByBorder(HMAP hMap, long int number);

  // ����������� ������������� ����� �������
  // hMap    - ������������� �������� �������� �����
  // number  - ����� ������� � �������
  // ���� ����� ������� ���������� ���������� 1, ����� ���������� 0.

_MAPIMP long int _MAPAPI mapGetExistenceMtqBorder(HMAP hMap, long int number);

  // ��������� ����������� ������� �� �����
  // hMap      - ������������� �������� �������� �����
  // number    - ����� ������� � �������
  // value = 1 - ���������� �������  �� �����
  //       = 0 - ���������� �������  ��� ����� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetShowMtqByBorder(HMAP hMap, long int number, long int value);
_MAPIMP long int _MAPAPI mapShowMtqByBorder(HMAP hMap, long int number, long int value);

  // ��������� �������� �������� ������ � ������� ������ ��������� �������
  // hMap   - ������������� �������� �������� �����
  // number - ����� ������� � �������
  // �� ������ bottomScale ������������ ����������� �������� ������ ������� ��������� �������
  // �� ������ topScale ������������ ����������� �������� ������� ������� ��������� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqRangeScaleVisible(HMAP hMap, long int number,
                                                    long int *bottomScale,
                                                    long int *topScale);

  // ���������� �������� �������� ������ � ������� ������ ��������� �������
  // hMap   - ������������� �������� �������� �����
  // number - ����� ������� � �������
  // bottomScale - ����������� �������� ������ ������� ��������� �������
  // topScale    - ����������� �������� ������� ������� ��������� �������
  //               bottomScale <= topScale, ����� ���������� 0
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqRangeScaleVisible(HMAP hMap, long int number,
                                                    long int bottomScale,
                                                    long int topScale);

  // ���������� ���������� � ���������� ����� ����� �����, �������
  // ������ � ������������� �������� ������(�������) �
  // ����� ���������� �������� �� ����� pointIn (���������� � ������).
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� � �������
  // �� ������ pointOut ������������ ���������� ��������� ����� � ������
  // ��� ������ ��� ���������� ����� ���������� 0.

_MAPIMP long int _MAPAPI mapGetImmediatePointOfMtqBorder(HMAP hMap, long int number,
                                                         DOUBLEPOINT *pointIn,
                                                         DOUBLEPOINT *pointOut);

  // ��������� ���������� ���-��������� ���� ������� � ������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� � �������
  // �� ������ x,y ������������ ���������� ��������� ����� � ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetSouthWestMtqPlane(HMAP hMap,long int number,
                                                 double *x, double *y);

  // ��������� �������� �������
  // (��������������� ����������� �� ������ ����������)
  // hMap - ������������� �������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetActiveMtq(HMAP hMap);

  // ���������� �������� �������
  // (��������������� ����������� �� ������ ����������)
  // hMap - ������������� �������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetActiveMtq(HMAP hMap, long int number);

  // ��������� ���� ��������������� �������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetMtqEdit(HMAP hMap, long int number);

  // ��������� ������ �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // �� ������ fileSize ������������ ������ �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqFileSize(HMAP hMap, long int number, __int64 *fileSize);

  // ��������� ������ ������� (��������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqWidthInElement(HMAP hMap, long int number);

  // ��������� ������ ������� (��������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqHeightInElement(HMAP hMap, long int number);

  // ��������� �������� (����/����) �������             /
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqAccuracy(HMAP hMap, long int number);

  // ��������� ���� ��������� �������� (�����) �������             /
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqFlagLocationChanged(HMAP hMap, long int number);

  // ���������� �������� ��� ������� ������� (��� ������������)
  // hMap   - ������������� �������� �������� ����� (TMapAccess *)
  // number - ����� ������� � �������
  // username - ��� ������������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqUserName(HMAP hMap, long int number, const char *username);
_MAPIMP long int _MAPAPI mapSetMtqUserNameUn(HMAP hMap, long int number, const WCHAR *username);

  // ��������� �������� ��� ������� ������� (��� ������������)
  // hMap   - ������������� �������� �������� ����� (TMapAccess *)
  // number - ����� ������� � �������
  // namesize - ������ ������ � ������
  // ��� ������ ���������� 0
_MAPIMP const char* _MAPAPI mapGetMtqUserName(HMAP hMap, long int number);
_MAPIMP long int _MAPAPI mapGetMtqUserNameUn(HMAP hMap, long int number, WCHAR *name, long int namesize);

  // ��������� ����� ����� ������ �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqBlockRow(HMAP hMap, long int number);


  // ��������� ����� �������� ������ �������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqBlockColumn(HMAP hMap, long int number);

  // ��������� ������������ ������ ����� ������� � ���������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqBlockSide(HMAP hMap, long int number);

  // ��������� ������ ����� ������� � ���������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����
_MAPIMP long int _MAPAPI mapGetMtqBlockWidth(HMAP hMap, long int number);

  // ������� ����� ����������� ����� �������
  // (0 - �� ������������, 1- ������������, 2 - �������� ������ )
  // number - ����� ����� � �������
  // i - ���������� ����� (������) �����, i = str * blockColumnCount + col, ���:
  //     str - ������ ������ ������,
  //     blockColumnCount - ����� �������� ������ ������� (������� mapGetMtqBlockColumn)
  //     col - ������ ������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCheckMtqBlockVisible(HMAP hMap, long int number, long int i);

  // ���������� ����� ������� �� ������� ���������� �������
  // ��������� ������ ������ ����� �� ����� 4-� �����
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� � �������
  // info   - ��������� ������ �����
  // ����� ���������� ������� ����������� ������� ����������� �������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMtqBorder(HMAP hMap, long int number, HOBJ info);

  // ��������� ������ ����� ������� �������
  // hMap       - ������������� �������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ������������� ������� ����� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqBorder(HMAP hMap, long int number, HOBJ info);

  // ��������� ������ �������� ����� column ������� � ���������
  // (� ������ ��������� ������)
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqCurrentBlockWidth(HMAP hMap, long int number,
                                                    long int column);

  // ��������� ������ �������� ����� string ������� � ���������
  // (� ������ ��������� ������)
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqCurrentBlockHeight(HMAP hMap, long int number,
                                                     long int string);

  // ��������� ���� ������� �� ������ ������ � �������
  // ����� ���������� ���� ����� ����� ��������� ������
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP char* _MAPAPI mapGetMtqBlockAddress(HMAP hMap, int number, int row, int column);

  // �������� ��������� ������� � ����
  // hMap       - ������������� �������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveMtq(HMAP hMap, long int number);

  // ������� ���� ������� �������
  // ������� ������������� ��� �������� ������� � �e ��������� ������
  // ������� �������� ����� 4Gb ������� �� 2-� ������: *.mtq � *.mtq.01
  // ������ ������� DeleteTheFile()
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteMtqFile(const char *name);
_MAPIMP long int _MAPAPI mapDeleteMtqFileUn(const WCHAR *name);

  // ������������� ��� ����� ������� �������
  // ������� ������������� ��� ���������������� ������� � ţ ��������� ������
  // ������� �������� ����� 4Gb ������� �� 2-� ������: *.mtq � *.mtq.01
  // ������ ������� MoveTheFile()
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapMoveMtqFile(const char *oldname, const char *newname);
_MAPIMP long int _MAPAPI mapMoveMtqFileUn(const WCHAR *oldname, const WCHAR *newname);

  // ����������� ���� ������� �������
  // ������� ������������� ��� ����������� ������� � ţ ��������� ������
  // ������� �������� ����� 4Gb ������� �� 2-� ������: *.mtq � *.mtq.01
  // ������ ������� CopyTheFile()
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCopyMtqFile(const char *oldname, const char *newname, int exist = 0);
_MAPIMP long int _MAPAPI mapCopyMtqFileUn(const WCHAR *oldname, const WCHAR *newname, int exist = 0);

  // ������ ����� {string,column} � ���� ������� �� ������ bits.
  // number    - ����� ����� � �������
  //  bits     - ��������� �� ������ ����������� ������� �������
  //  sizebits - ������ ������� bits � ������
  // ���������� ���������� ���������� ����.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapWriteMtqBlock(HMAP hMap, long int number,
                                          long int string, long int column,
                                          char *bits, long int sizebits);

  // ��������� ������ �������� ����� {string,column} ������� � ������
  // (� ������ ��������� ������)
  // number - ����� ����� � �������
  // string, column - ������ � ������� ����� �������������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMtqCurrentBlockSize(HMAP hMap, long int number,
                                                   long int string, long int column);


  // ������� ���������� ������� ������� �������
  // ��� ������������� �������� ����������� �������������� ������� (��������� �� 16x16, 24x24 � 32x32)
  // ������� ������ � ��������� imgsize
  // hmap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // xmlname   - ��� ��������� xml-�����
  // imgpath   - ���� � ������������ ������� png
  // imgsize   - ������������� ������ ����������� (������� ��������),
  //             ���� ����� ����, �� ����� ������� ������ ����������� �������� 16x16, 24x24 � 32x32)
  // ������������ ������ ����������� 1024x1024
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapCreateMtqLegendToXML(HMAP hmap, long int number,
                                                 const WCHAR * xmlname,
                                                 const WCHAR * imgpath,
                                                 long int imgsize);

  // ������ �������� �������������� ������� �������      // 25/05/16
  // hmap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetMtqValueName(HMAP hMap, long int number, WCHAR * value, long int size);

  // ������ �������� �������������� ������� �������      // 25/05/16
  // hmap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetMtqValueName(HMAP hMap, long int number, const WCHAR * value);

  // ������ �������� ������� ��������� ������� �������      // 25/05/16
  // hmap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetMtqUnitName(HMAP hMap, long int number, WCHAR * unit, long int size);

  // ������ �������� ������� ��������� ������� �������      // 25/05/16
  // hmap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetMtqUnitName(HMAP hMap, long int number, const WCHAR * value);


#endif  // !HIDEMTQ


  /************************************************************************************* 
  *                                                                                    *
  *  ������ ������ �� ������� ����� ������ ��� ������������ ���������� WGS84 (EGM2008) *
  *                                                                                    *
  *************************************************************************************/

  // �������� ������� Egm2008
  // �������� ������� egm8_25.mtw (������ �������� 2.5 ������) �
  //                  egm8_1.mtw  (������ �������� 1 ������)
  // ���������� ������������� �������� ������� Egm2008
  // ��� ������ ���������� 0

_MAPIMP HANDLE _MAPAPI mapOpenEgm2008(const char *mtrname);
_MAPIMP HANDLE _MAPAPI mapOpenEgm2008Un(const WCHAR *mtrname);

  // �������� ������� Egm2008
  // mtr - ������������� �������� ������� Egm2008

_MAPIMP void _MAPAPI mapCloseEgm2008(HANDLE mtr);

  // ������ ������ ������ ��� ������������ ���������� wgs84
  // �� ������������� ����������� �� ���������� WGS84
  // mtr - ������������� �������� ������� Egm2008
  // interptype - ��� �������������
  //          1 - ��������� �����
  //          2 - ������������ �� ��������� 3 ���������
  //          3 - ���������� ������������ �� 4 ��������� ���������
  //          4 - ������������ ������������ �� 16 ��������� ���������
  // b - ������ ����� �� ���������� WGS84 � ��������
  // l - ������� ����� �� ���������� WGS84 � ��������
  // h - ������������ ������ ������ � ������
  // ��� ������ ���������� 0  

_MAPIMP long int _MAPAPI mapReadEgm2008(HANDLE mtr, long int interptype, double b, double l, double *h);




}  // extern "C"

#endif // MTRAPI_H
