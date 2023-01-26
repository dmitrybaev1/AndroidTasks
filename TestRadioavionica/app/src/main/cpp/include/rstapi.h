/****** RSTAPI.H *************** Belenkov O.V.   ****** 19/01/14 ***
******* RSTAPI.H *************** Shabakov D.A.   ****** 11/07/16 ***
******* RSTAPI.H *************** Gorbunov A.V.   ****** 14/07/10 ***
******* RSTAPI.H *************** Kruzhkov A.E.   ****** 31/05/10 ***
******* RSTAPI.H *************** Vitsko D.A.     ****** 23/11/05 ***
******* RSTAPI.H *************** Derevyagina Zh.A.***** 12/10/09 ***
******* RSTAPI.H *************** Borzov A.U.      ***** 06/11/15 ***
*                                                                  *
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
*    HMAP (WINAPI * lpfn_OpenMap)(const char*, long int);          *
*    (FARPROC)lpfn_OpenMap = GetProcAddress(libInst, "OpenMap");   *
*    HMAP hMap = (*lpfn_OpenMap)("Noginsk.map",0);                 *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef RSTAPI_H
#define RSTAPI_H

#ifndef MAPTYPE_H
  #include "maptype.h"   // �������� �������� ���������� MAPAPI
#endif

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++ �������� ������� ������� � ��������� ����� ++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C"
{

  // ������� ��������� ������
  // ���������� ������������� �������� ��������� ����� (TMapAccess*)
  // rstname - ��� ����� ��������� �����
  // mode    - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapOpenRst(const char *rstname, long int mode = 0);
_MAPIMP HMAP _MAPAPI mapOpenRstUn(const WCHAR *rstname,long int mode);

  // ������� ��������� ������ � �������� ������ �����
  // (�������� � ������� �������)
  // ���������� ����� ����� � ������� �������
  // hMap    - ������������� �������� ��������� �����
  // rstname - ��� ����� ��������� �����
  // mode    - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapOpenRstForMap(HMAP hMap, const char *rstname, long int mode);
_MAPIMP long int _MAPAPI mapOpenRstForMapUn(HMAP hMap, const WCHAR *name, long int mode);

  // �������� ����� ���������� �����������
  // rstname    - ��� ������������ �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // palette    - ����� ��������������� �������
  // colorcount - ����� ��������� � ����� �������
  // scale      - �������
  // precision  - ���������� ������
  // ��� �������� ���������� ������� ������� ���� rstname � �����������
  // ��������� � �������� ������.
  // ��� ������ ���������� 0

_MAPIMP HMAP _MAPAPI mapCreateRst(const char *rstname, long int width, long int height,
                                  long int nbits, COLORREF* palette, long int colorcount,
                                  double scale = 0, double precision = 0);
_MAPIMP HMAP _MAPAPI mapCreateRstUn(const WCHAR *rstname, long int width, long int height,
                                    long int nbits, COLORREF *palette, long int colorcount,
                                    double scale, double precision);

  // �������� ����� ��������� �����
  // name            - ������ ��� ������
  // width           - ������ ����������� � ��������
  // height          - ������ ����������� � ��������
  // nbits           - ���������� ��� �� ������� (1,4,8,24)
  // palette         - ��������� �� ������� ������ (����������� ��� 1,4,8 ��� �� �������)
  // scale           - ������ ������
  // precisionMet    - ���������� ������ (����� �� ����)
  // meterInElementX - ������ ������� ������ � ������ �� ��������� �� ��� X (�� ���������)
  // meterInElementY - ������ ������� ������ � ������ �� ��������� �� ��� Y (�� �����������)
  //                   meterInElementX � meterInElementY ����� ����� ������ ��������
  // location        - ���������� ���-��������� ���� ������ � ������, ��������������� �� � mapregister
  // mapregister     - �������� ��������� ���������
  // �����!!!
  // ��� ����������� �������� ������� � 10-�� � ����� ������ ������� ���������� ��������� �������:
  //                            meterInElementX = scale/precisionMet;
  // ����� ������� � ���������� ����� �����������!!!
  // ��� ������ ���������� 0

_MAPIMP HMAP _MAPAPI mapCreateRstEx(char *rstname, long int width, long int height, long int nbits,
                                    COLORREF* palette, long int colorcount, double scale, double precisionMet,
                                    double meterInElementX, double meterInElementY,
                                    DOUBLEPOINT *location, MAPREGISTEREX *mapregister);
_MAPIMP HMAP _MAPAPI mapCreateRstExUn(WCHAR *rstname, long int width, long int height, long int nbits,
                                      COLORREF* palette, long int colorcount, double scale,
                                      double precisionMet, double meterInElementX, double meterInElementY,
                                      DOUBLEPOINT *location, MAPREGISTEREX* mapregister);

  // �������� ����� ��������� �����
  // name            - ������ ��� ������
  // width           - ������ ����������� � ��������
  // height          - ������ ����������� � ��������
  // nbits           - ���������� ��� �� ������� (1,4,8,24)
  // palette         - ��������� �� ������� ������ (����������� ��� 1,4,8 ��� �� �������)
  // meterInElementX - ������ ������� ������ � ������ �� ��������� �� ��� X (�� ���������)
  // meterInElementY - ������ ������� ������ � ������ �� ��������� �� ��� Y (�� �����������)
  //                   meterInElementX � meterInElementY ����� ����� ������ ��������
  // location        - ���������� ���-��������� ���� ������ � ������, ��������������� �� � mapregister
  // mapregister     - ��������� �� ���������, ���������� ��������� �������� ��������� ���������
  // datumparam      - ��������� �� ���������, ���������� ������������ ����������������� ������������� ���������
  // ellipsoidparam  - ��������� �� ���������, ���������� ��������� ����������
  // ��� ������ ���������� 0

_MAPIMP  HMAP _MAPAPI mapCreateRaster(const char *rstname, long int width, long int height, long int nbits,
                                      COLORREF* palette, long int colorcount, double meterInElementX,
                                      double meterInElementY, DOUBLEPOINT *location,
                                      MAPREGISTEREX* mapregister, DATUMPARAM * datum, ELLIPSOIDPARAM * ellipsoid);
_MAPIMP HMAP _MAPAPI mapCreateRasterUn(const WCHAR *rstname, long int width, long int height, long int nbits,
                                       COLORREF *palette, long int colorcount, double meterInElementX,
                                       double meterInElementY, DOUBLEPOINT *location, MAPREGISTEREX *mapregister,
                                       DATUMPARAM *datum, ELLIPSOIDPARAM *ellipsoid);

  // �������� ����� ���������� �����������
  // hMap       - ������������� �������� ��������� �����
  // rstname    - ��� ������������ �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // palette    - ����� ��������������� �������
  // colorcount - ����� ��������� � ����� �������
  // scale      - �������
  // precision  - ���������� ������
  // location   - �������� ���-��������� ���� ������ � ������(� ������)
  // ��� �������� ���������� ������� ������� ���� rstname � �����������
  // ��������� � �������� ������ � ��������� ��� � ������� �������
  // �������� ��������� ����� (hMap).
  // ����������  ����� ����� (������� � 1) � ������� ������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCreateAndAppendRst(HMAP hMap,const char *rstname, long int width, long int height,
                                               long int nbits, COLORREF* palette, long int colorcount,
                                               double scale, double precision, DOUBLEPOINT location);
_MAPIMP long int _MAPAPI mapCreateAndAppendRstUn(HMAP hMap, const WCHAR *rstname, long int width, long int height,
                                                 long int nbits, COLORREF *palette, long int colorcount,
                                                 double scale, double precision, DOUBLEPOINT location);

  // �������� ����� ���������� �����������
  // hMap       - ������������� �������� ��������� �����
  // rstname    - ��� ������������ �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // palette    - ����� ��������������� �������
  // colorcount - ����� ��������� � ����� �������
  // scale      - �������
  // precision  - ���������� ������ (����� �� ����)
  // meterInElementX - ������ ������� ������ � ������ �� ��������� �� ��� X (�� ���������)
  // meterInElementY - ������ ������� ������ � ������ �� ��������� �� ��� Y (�� �����������)
  //                   meterInElementX � meterInElementY ����� ����� ������ ��������
  // location        - ���������� ���-��������� ���� ������ � ������, ��������������� �� � mapregister
  // mapregister     - �������� ��������� ���������
  // �����!!!
  // ��� ����������� �������� ������� � 10-�� � ����� ������ ������� ���������� ��������� �������:
  //                            meterInElementX = scale/precision;
  // ����� ������� � ���������� ����� �����������!!!
  // ��� �������� ���������� ������� ������� ���� rstname � �����������
  // ��������� � �������� ������ � ��������� ��� � ������� �������
  // �������� ��������� ����� (hMap).
  // ����������  ����� ����� (������� � 1) � ������� ������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCreateAndAppendRstEx(HMAP hMap,const char * rstname,
                                                  long int width, long int height, long int nbits,
                                                  COLORREF* palette, long int colorcount,
                                                  double scale, double precision,
                                                  double meterInElementX, double meterInElementY,
                                                  DOUBLEPOINT* location, MAPREGISTEREX* mapregister);
_MAPIMP long int _MAPAPI mapCreateAndAppendRstExUn(HMAP hMap, const WCHAR *rstname, long int width,
                                                   long int height, long int nbits, COLORREF* palette,
                                                   long int colorcount, double scale, double precision,
                                                   double meterInElementX, double meterInElementY,
                                                   DOUBLEPOINT* location, MAPREGISTEREX* mapregister);

  // �������� ����� ���������� �����������
  // hMap       - ������������� �������� ��������� �����
  // rstname    - ��� ������������ �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // palette    - ����� ��������������� �������
  // colorcount - ����� ��������� � ����� �������
  // scale      - �������
  // precision  - ���������� ������ (����� �� ����)
  // meterInElementX - ������ ������� ������ � ������ �� ��������� �� ��� X (�� ���������)
  // meterInElementY - ������ ������� ������ � ������ �� ��������� �� ��� Y (�� �����������)
  //                   meterInElementX � meterInElementY ����� ����� ������ ��������
  // location        - ���������� ���-��������� ���� ������ � ������, ��������������� �� � mapregister
  // mapregister     - ��������� �� ���������, ���������� ��������� �������� ��������� ���������
  // datumparam      - ��������� �� ���������, ���������� ������������ ����������������� ������������� ���������
  // ellipsoidparam  - ��������� �� ���������, ���������� ��������� ����������
  // �����!!!
  // ��� ����������� �������� ������� � 10-�� � ����� ������ ������� ���������� ��������� �������:
  //                            meterInElementX = scale/precision;
  // ����� ������� � ���������� ����� �����������!!!
  // ��� �������� ���������� ������� ������� ���� rstname � �����������
  // ��������� � �������� ������ � ��������� ��� � ������� �������
  // �������� ��������� ����� (hMap).
  // ����������  ����� ����� (������� � 1) � ������� ������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCreateAndAppendRaster(HMAP hMap, const char *rstname, long int width,
                                                  long int height, long int nbits, COLORREF *palette,
                                                  long int colorcount, double meterInElementX,
                                                  double meterInElementY,
                                                  DOUBLEPOINT *location, MAPREGISTEREX *mapregister,
                                                  DATUMPARAM *datum, ELLIPSOIDPARAM *ellipsoid);
_MAPIMP long int _MAPAPI mapCreateAndAppendRasterUn(HMAP hMap, const WCHAR *rstname, long int width,
                                                    long int height, long int nbits, COLORREF *palette,
                                                    long int colorcount, double meterInElementX,
                                                    double meterInElementY, DOUBLEPOINT *location,
                                                    MAPREGISTEREX *mapregister, DATUMPARAM *datum,
                                                    ELLIPSOIDPARAM *ellipsoid);

  // ������ ����e�������� ����� ����� ��������� ����� �� �� ��������
  // hMap       - ������������� �������� ��������� �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // ����������  ����e�������� ����� ����� ��������� ����� (����)
  // ��� ������ ���������� ����

_MAPIMP  double _MAPAPI mapRstFileLengthCalculation(HMAP hMap, long int width,
                                                    long int height, long int nbits);
  // ���������� �������
_MAPIMP  double _MAPAPI mapRtsFileLengthCalculation(HMAP hMap, long int width,
                                                    long int height, long int nbits);

  // ��������� ����� � ������ ����� ��������� �����
  // ������������ ������ ����� 8 ��.
  // ��������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.rsw � *.rsw.01
  // hMap       - ������������� �������� �����
  // number - ����� ���������� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP __int64 _MAPAPI mapRstFileLength(HMAP hMap, long int number);

  // ��������� ����� ������ � ������� �� ����� �����
  // name        - ��� ����� ������
  // � ������� ������ ������� ���������� � 1.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstNumberByName(HMAP hMap, const char *name);
_MAPIMP long int _MAPAPI mapGetRstNumberByNameUn(HMAP hMap, const WCHAR* name);

  // ������� ��������� ������ � �������� ������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ���������� ����� � �������
  // ���� number ����� 0, ����������� ��� ��������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCloseRstForMap(HMAP hMap, long int number);

  // ������� ��������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ������������ ������
  // ���� number == 0, ����������� ��� ������ � ����

_MAPIMP void _MAPAPI mapCloseRst(HMAP hMap, long int number = 0);

  // ������� ��������� ������ � ������� ����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ���������� ����� � �������
  // ���� number ����� 0, ����������� � ��������� ��� ��������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteRst(HMAP hMap, long int number);

  // ��������� ��� ����� ��������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ������ ������

_MAPIMP const char* _MAPAPI mapGetRstName(HMAP hMap, long int number);

  // ��������� ��� ����� ��������� ������ � ��������� UNICODE
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������
  // ��� ������ ���������� ������ ������

_MAPIMP long int _MAPAPI mapGetRstNameUn(HMAP hMap, long int number,
                                         WCHAR *name, long int size);

  // ��������� ����� �������� ������ ��������� ������
  // hMap    - ������������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstCount(HMAP hMap);

  // ������ �������� ������ ������
  // hMap    - ������������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstCurrentNumber(HMAP hMap);

  // ��������� �������� ������ ������
  // hMap    - ������������� �������� ��������� �����
  // number  - ����� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstCurrentNumber(HMAP hMap, long int number);

  // �������� ��� ��������� ������, �������� �� ��� �������
  // hMap    - ������������� �������� ��������� �����
  // number  - ����� ������, ��� �������� ����� �������� ���, ��� -1 (��� ������)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapClearRstCache(HMAP hMap, long int number);

  // ��������� ����� �������� �������������� ������
  // hMap    - ������������� �������� ��������� �����
  // number  - ����� ������
  // ���������� ��������� ����� �������������� (��������) �� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstSystemTime(HMAP hMap, long int number, SYSTEMTIME *time);

  // ���������/���������� ������� ��������� ������
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  view = 0 - �� �����
  //  view = 1 - ������ ���������
  //  view = 2 - ����������
  //  view = 3 - ��������������
  //  view = 4 - �������
  //  view = 5 - ����������

_MAPIMP  long int _MAPAPI mapGetRstView(HMAP hMap,long int number);
_MAPIMP  long int _MAPAPI mapSetRstView(HMAP hMap,long int number,
                                        long int view);

  // ��������� ������������ ������� ������                   // 19/01/14
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstTransparent(HMAP hMap, long int number);

  // ���������� ������������ ������� ������                   // 19/01/14
  // hMap   - ������������� �������� ������
  // transparent - ������������ � ��������� �� 0 �� 100
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstTransparent(HMAP hMap, long int number,
                                              long int transparent);


  // ���������� ������� ��������� ������ �������
  //  userLabel  - ���������������� ����� ������
  //                -1             - ��� ������
  //                RSW_QUALITY    - ������ �������
  //                RSW_VISIBILITY - ������ ���������
  //                RSW_WEB        - ��������� ����� ��� WEB
  //  view - ������� ���������
  //                0 - �� �����
  //                1 - ������
  //                2 - ����������
  //                3 - ��������������
  //                4 - �������
  //                5 - ����������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstGroupView(HMAP hMap, long int userLabel, long int view);

  // ���������/���������� ������� ����������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ���������� ����� � �������
  //  (0 - ��� ������, 1 - ��� ������)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstViewOrder(HMAP hMap, long int number, long int order);
_MAPIMP  long int _MAPAPI mapGetRstViewOrder(HMAP hMap, long int number);

  // �������� ����������� ����������� ������� (rst) � �������
  // ��������� ����� � ������� ������������ � ��������� �������
  // ��������� ������� � ������� ���������� � 1 � ������������� ������� mapGetRstCount(..)
  // oldNumber - ����� ����� � �������
  // newNumber - ��������������� ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapChangeOrderRstShow(HMAP hMap, long int oldNumber, long int newNumber);
_MAPIMP long int _MAPAPI mapChangOrderRstInChain(HMAP hMap, long int oldNumber, long int newNumber);

  // ���������������� �������� ������� ��� ������
  // ���� ��� ������ ������������ ��� ������, ��
  // ������ ����� ����� ��������� ��� ������. ��� ���������
  // ������ ������ ����� ����� ��������� ��� ������, ��������� -
  // ��� ������. ����� ���������� ������ � ������ ��� ������ -
  // ��� ������ ��� ������. ����� - ����� ������ ����� ��� ������.
  // ���������� ����� ������ ������������� ��� ������ ��� ����.
  // ��� ��������� ���������� �� ������ - ����� ����� ������������
  // hMap    - ������������� �������� ��������� �����

_MAPIMP long int _MAPAPI mapTurnRstViewOrder(HMAP hMap);

  // ��������� ���������� ������ � ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ������������ 0

_MAPIMP long int _MAPAPI mapGetRstColorCount (HMAP hMap, long int number);

  // ��������� �������� ������� ������
  // hMap    - ������������� �������� ��������� �����
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  //           (���� count > 256, �� ������������ ����)
  // number  - ����� ����� � �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstPalette(HMAP hMap, COLORREF *palette,
                                          long int count, long int number);

  // ���������� �������� ������� ������
  // hMap    - ������������� �������� ��������� �����
  // palette - ����� ��������������� �������
  // count   - ����� ��������� � ����� �������
  // number  - ����� ����� � �������
  // ���� palette ����� 0, ��������������� ������� �� ���������
  // count �� ����� 256
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstPalette(HMAP hMap, COLORREF *palette,
                                          long int count, long int number);

  // ��������� �������� ��������� ������� ������
  // (��� ����� ������� � ������������)
  // hMap    - ������������� �������� ��������� �����
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  //           (���� count > 256, �� ������������ ����)
  // number  - ����� ����� � �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstStandardPalette(HMAP hMap, COLORREF *palette,
                                                  long int count, long int number);

  // ��������� �������� ������� �� ��������� ������
  // hMap   - ������������� �������� ��������� �����
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  //           (���� count > 256, �� ������������ ����)
  // number  - ����� ����� � �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstPaletteFromHeader(HMAP hMap, COLORREF *palette,
                                                    long int count, long int number);

  // ��������� ������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstBright(HMAP hMap, long int number);

  // ��������� ������������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstContrast(HMAP hMap, long int number);

  // ��������� �������������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstGamma(HMAP hMap, long int number);

  // ���������� ������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // bright - �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstBright(HMAP hMap, long int bright, long int number);

  // ���������� ������������� ������� ������
  // hMap     - ������������� �������� ��������� �����
  // number   - ����� ����� � �������
  // contrast - ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstContrast(HMAP hMap, long int contrast, long int number);

  // ���������� �������������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // gamma  - �������������� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstGamma(HMAP hMap, long int gamma, long int number);

  //  �������� �������� ������� � ������� �������� � ��������������
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapRestoreRstPalette(HMAP hMap, long int number);

  // ��������� �������� �������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ���� ����������� ������ ���������� - ���������� ����
  // ���� ����������� ������ ���������� - ���������� 1
  // ��� ������ ���������� -1

_MAPIMP long int _MAPAPI mapCheckInversionRst(HMAP hMap, long int number);

  // ������������� ��������� �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // value:
  // 0 - ���������� ����������� ������ ����������
  // 1 - ���������� ����������� ������ ����������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapInvertRst(HMAP hMap, long int number, long int value);

  // ��������� ��������� ����� (��� 16- � 256-������� �������)
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  index  - ������ ����� � ������� ������(������� � 0)
  //  ����������: 1 - ���� � ������ �������� ������������
  //              0 - ���� � ������ �������� �� ������������
  //  ��� ������ ���������� -1

_MAPIMP long int _MAPAPI mapCheckVisibilityColor(HMAP hMap, long int number, long int index);

  // ���������� ��������� ����� (��� 16- � 256-������� �������)
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  index  - ������ ����� � ������� ������(������� � 0)
  //  value: 1 - �������� ����������� ����� � ������ ��������
  //         0 - ��������� ����������� ����� � ������ ��������
  //  ���������� ��������� ������ � INI-����� (�� ��������� � �������� ����� ������)
  //  ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetVisibilityColor(HMAP hMap, long int number,
                                               long int index, long int value);

  // ���������� ��������� ����� (��� 16- � 256-������� �������)
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  index  - ������ ����� � ������� ������(������� � 0)
  //  value: 1 - �������� ����������� ����� � ������ ��������
  //         0 - ��������� ����������� ����� � ������ ��������
  //  ���������� ��������� ������ � ��������� ����� ������(� ����� � INI-�����)
  //  ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetVisibilityColorInRstFile(HMAP hMap, long int number,
                                                        long int index, long int value);

  // ���������� ���������� ���� ������ (��� 16-,24-,32-������ �������)
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  color  - �������� ����������� ����� � ������� RGB (�� 0 �� 0x00FFFFFF)
  // ��� ��������� IMGC_TRANSPARENT (0xFFFFFFFF) ���������� ���� �� ������������
  // ��� ������ ���������� IMGC_TRANSPARENT

_MAPIMP COLORREF _MAPAPI mapSetRstTransparentColor(HMAP hMap, long int number, COLORREF color);

  // ��������� ���������� ���� ������ (��� 16-,24-,32-������ �������)
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  // ���������� ���� � ������� RGB (�� 0 �� 0x00FFFFFF)
  // ��� �������� IMGC_TRANSPARENT (0xFFFFFFFF) ���������� ���� �� ������������
  // ��� ������ ���������� IMGC_TRANSPARENT

_MAPIMP COLORREF _MAPAPI mapGetRstTransparentColor(HMAP hMap, long int number);

  // ��������� ���� � ��� ����� ������
  // hMap      - ������������� �������� ��������� �����
  // maskType  - ���� �����(0 - ����� �����������)
  // maskStep  - ��� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstMaskType(HMAP hMap, long int number,
                                           long int *maskType, long int *maskStep);

  // ���������� ���� � ��� ����� ������
  // hMap      - ������������� �������� ��������� �����
  // maskType  - ���� �����(0 - ����� �����������)
  // maskStep  - ��� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapSetRstMaskType(HMAP hMap,long int number,
                                           long int maskType, long int maskStep);

  // ��������� ��������������� ���������� ������
  // scale           - ����������� ��������
  // precision       - ���������� (����� �� ����)
  // meterinelementX - ���������� ������ �� �������  �� ��� X
  // meterinelementY - ���������� ������ �� �������  �� ��� Y
  // meterinelementX � meterinelementY ����� ����������
  // �����!!!
  // ��� ����������� ����������� ������� � 10-�� � ����� ������ ������� ����������:
  //                         meterinelementX = scale / precision;
  // ���� ������� �� �����������, �� meterinelementX � meterinelementY ������������ � ������������� �� �������.

_MAPIMP long int _MAPAPI mapSetRstParameters(HMAP hMap, long int number,
                                             double scale, double precision,
                                             double meterinelementX,
                                             double meterinelementY);

  // ���������� ������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // scale      - ����������� ��������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstScale(HMAP hMap, long int number, double scale);

  // ��������� ������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // scale      - ��������� ����������, ���� �������� �������� ��������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstScale(HMAP hMap, long int number, double *scale);


  // ��������� �������� �������� ������ � ������� ������ ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // �� ������ bottomScale ������������ ����������� �������� ������ ������� ��������� ������
  // �� ������ topScale ������������ ����������� �������� ������� ������� ��������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstRangeScaleVisible(HMAP hMap, long int number,
                                                    long int *bottomScale, long int *topScale);

  // ���������� �������� �������� ������ � ������� ������ ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // bottomScale   - ����������� �������� ������ ������� ��������� ������
  // topScale   - ����������� �������� ������� ������� ��������� ������
  //              bottomScale <= topScale, ����� ���������� 0
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstRangeScaleVisible(HMAP hMap, long int number,
                                                    long int bottomScale, long int topScale);

  // ���������� ���������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // precision  - ���������� ������, ���������� ��� ������������ (����� �� ����)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstPrecision(HMAP hMap, long int number, double precision);

  // ��������� ���������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // precision  - ���������� ������ (����� �� ����)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstPrecision(HMAP hMap, long int number, double *precision);

  // ���������� ����� ������ �� ������� ���������� �������
  // ��������� ������ ������ ����� �� ����� 4-� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ��������� ������ �����
  // ����� ���������� ������� ����������� ������ ����������� �������� ��������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstBorder(HMAP hMap, long int number, HOBJ info);

  // ���������� ����� ������ �� ������� ���������� �������
  // ��������� ������ ������ ����� �� ����� 4-� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ��������� ������ �����
  // flagSubject- ���� ������������� ����������� ������� ��� ��������� ����� ������ (0/1)
  //              0 - � �������� ����� ������ ��������������� ������ �������
  //              1 - � �������� ����� ������ ��������������� ������ ������� � ������������
  // ����� ���������� ������� ����������� ������ ����������� �������� ��������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstBorderEx(HMAP hMap, long int number, HOBJ info,
                                           long int flagSubject);

  // ��������� ������ ����� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ������������� ������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBorder(HMAP hMap, long int number, HOBJ info);

  // ������� ����� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ����� ���������� ������� ����������� ������ ����� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDeleteRstBorder(HMAP hMap, long int number);

  // ����������� ������������� ����� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstMask(HMAP hMap, long int number);

  // ����������� ������� ����������� ������(������������ �����)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ���������� 1 - ��� ����������� ������ �� �����
  //            0 - ��� ����������� ������ ��� ����� �����
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetShowRstByMask(HMAP hMap, long int number);

  // ��������� ����������� ������ �� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // value  = 1 - ���������� ����� �� �����
  //        = 0 - ���������� ����� ��� ����� �����

_MAPIMP long int _MAPAPI mapSetShowRstByMask(HMAP hMap, long int number, long int value);

  // ����������� ������������� ����� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapCheckExistenceRstBorder(HMAP hMap, long int number);

  // ��������� ����������� ������ �� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // value  = 1 - ���������� ����� �� �����
  //        = 0 - ���������� ����� ��� ����� �����

_MAPIMP long int _MAPAPI mapShowRstByBorder(HMAP hMap, long int number, long int value);

  // ����������� ������� ����������� ������(������������ �����)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ���������� 1 - ��� ����������� ������ �� �����
  //            0 - ��� ����������� ������ ��� ����� �����
  // ��� ������ ���������� -1

_MAPIMP long int _MAPAPI mapCheckShowRstByBorder(HMAP hMap, long int number);

  // ���������� ���������� ����� �����, �������
  // ������ � ������������� �������� ������(�������) �
  // ����� ���������� �������� �� ����� pointIn (���������� � ������).
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // �� ������ pointOut ������������ ���������� ��������� ����� � ������
  // ��� ������ ��� ���������� ����� ���������� 0

_MAPIMP long int _MAPAPI mapGetImmediatePointOfRstBorder(HMAP hMap, long int number,
                                                         DOUBLEPOINT* pointIn,
                                                         DOUBLEPOINT* pointOut);

  // ������ - �������������� �� �������� � �������������
  // ����������� �� ������� ������������� � �������
  // hMap     - ������������� �������� �������� �����
  // number   - ����� ������
  // ���� ��� - ���������� ����

  _MAPIMP long int _MAPAPI mapIsRstGeoSupported(HMAP hMap, long int number);

  // ��������� ������ � �������� ������
  // number      - ����� ����� � �������
  // mapregister - ����� ���������, � ������� ����� ���������
  // ������ � ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstProjectionData(HMAP hMap, int number,
                                                 MAPREGISTEREX* mapregister);

  // ��������� ������ � �������� ������ �� ����� �����
  // name        - ��� ����� ������
  // mapregister - ����� ���������, � ������� ����� ���������
  // ������ � ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstProjectionDataByName(const char *name,
                                                       MAPREGISTEREX* mapregister);
_MAPIMP long int _MAPAPI mapGetRstProjectionDataByNameUn(const WCHAR *name,
                                                         MAPREGISTEREX* mapregister);

  // ���������� ������ � �������� ������
  // number - ����� ����� � �������
  // mapregister - ����� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRstProjectionData(HMAP hMap, int number,
                                                  MAPREGISTEREX* mapregister);

  // ��������� ��������� ���������� ������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� ������ � �������
  // ellipsoidparam - ����� ���������, � ������� ����� ���������
  // ��������� ����������
  // ��������a ELLIPSOIDPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstEllipsoidParam(HMAP hMap, long int number,
                                                 ELLIPSOIDPARAM *ellipsoidparam);

  // ���������� ��������� ���������� ������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� ������ � �������.
  // ellipsoidparam - ����� ���������, ���������� ��������� ����������
  // ��������a ELLIPSOIDPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstEllipsoidParam(HMAP hMap, long int number,
                                                 const ELLIPSOIDPARAM *ellipsoidparam);

  // ��������� ������������ ����������������� ������������� ��������� ������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� ������ � �������
  // datumparam - ����� ���������, � ������� ����� ���������
  // ������������ ����������������� ������������� ���������
  // ��������a DATUMPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstDatumParam(HMAP hMap, long int number,
                                             DATUMPARAM *datumparam);

  // ���������� ������������ ����������������� ������������� ��������� ������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� ������ � �������.
  // datumparam - ����� ���������, ���������� ������������ �����������������
  // ������������� ���������
  // ��������a DATUMPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstDatumParam(HMAP hMap, long int number,
                                             const DATUMPARAM *datumparam);

  // ��������� �������� ������ � ������ � ������ �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // frame      - ������������ �������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstFrameMeters(HMAP hMap, DFRAME *frame, long int number);

  // ��������� ����������� �������� ������������� ������ � ������ � ������ �����
  // ��� ����������� ������ �� ����� ������������ �������� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // frame      - ������������ �������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetActualRstFrame(HMAP hMap, DFRAME *frame, long int number);

  // ���������� �������� ������ � ������ �����(� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // location   - ���������� ���-��������� ���� ������(� ������)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstLocation(HMAP hMap, long int number, DOUBLEPOINT *location);

  // ��������� �������� ������ � ������ �����(� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // location   - ���������� ���-��������� ���� ������(� ������)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstLocation(HMAP hMap, long int number, DOUBLEPOINT *location);

  // ��������� ���� ������������� �������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapCheckExistenceRstLocation(HMAP hMap, long int number);

  // ��������� - ����� �� ����� ������������ ��� ����������������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ���� ��� - ���������� ����

_MAPIMP long int _MAPAPI mapGetRstCopyFlag(HMAP hMap, long int number);

  //**********************************************************************
  // ��� ��������� ����� �� ������� (Dx,Dy)?
  //    ��������� �������� ������ - mapGetRstLocation(...)
  //    �������� ����� �������� �� ������� (Dx,Dy)
  //    ���������� ����� ����� �������� - mapSetRstLocation(...)
  //    ����������� ����.
  //**********************************************************************
  // ��� ��������� ����� � ���������� �������� ?
  //    ��������� �������� ������ - mapGetRstLocation(...)
  //    ��������� ����������� �������� ������ - mapGetRstScale(...)
  //    �������� ����� �������� � ���������� ����������� ��������
  //    ���������� ����� ����� �������� - mapSetRstLocation(...)
  //    ���������� ����� ����������� �������� - mapSetRstScale(...)
  //    ����������� ����.
  //**********************************************************************

  // ���������� �������
  // ��������� ������ �������� ������ � ������ �� ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // metinelem  - ������ �������� ������ � ������ �� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstMeterInElement(HMAP hMap, long int number, double *metinelem);

  // ��������� ������ �������� ������ � ������ �� ��� X
  // number    - ����� ����� � �������
  // metinelemX - ������ �������� ������ � ������ �� ��������� �� ��� X
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstMeterInElementX(HMAP hMap, long int number, double *metinelemX);

  // ��������� ������ �������� ������ � ������ �� ��� Y
  // number    - ����� ����� � �������
  // metinelemY - ������ �������� ������ � ������ �� ��������� �� ��� Y
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstMeterInElementY(HMAP hMap, long int number, double *metinelemY);

  // ���������� �������
  // ��������� ������ ����� ������ � ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // eleminpix  - ������ ����� ������ � ��������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetSizeRstElemInPix(HMAP hMap, long int number, double *eleminpix);

  // ��������� ������ �������� ������ � �������� ������ �� ��� X
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetSizeRstElemXInPix(HMAP hMap, long int number, double *eleminpix);

  // ��������� ������ �������� ������ � �������� ������ �� ��� Y
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetSizeRstElemYInPix(HMAP hMap, long int number, double *eleminpix);

  // ��������� ������ ������ � ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstWidth(HMAP hMap, long int number);

  // ��������� ������ ������ � ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstHeight(HMAP hMap, long int number);

  // ��������� ����� ������ � ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP unsigned long int _MAPAPI mapGetRstLength(HMAP hMap, long int number);

  // ��������� ������ �������� ������ � �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstElementSize(HMAP hMap, long int number);

  // ��������� ���� ��������������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstEdit(HMAP hMap, long int number);
_MAPIMP long int _MAPAPI mapCheckRstEdit(HMAP hMap, long int number);

  // ��������� ����� ��������� ������ ������ (0 - ����� �� ����, 1 - LZW, 2 - JPEG)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCheckRstCompressNumber(HMAP hMap, long int number);

  // ���������� � ��������� ������ ����� ��������� ������(0 - ����� �� ����, 1 - LZW, 2 - JPEG)
  // ��������: ������� �� ��������� ������ �����������
  // ��� ������ ����������� �� ������ LZW �������������� �������� mapCompressLZW(), ����������� � mapapi.h
  // ��� ������ ����������� �� ������ JPEG �������������� �������� mapCompressJPEG(), ����������� � mapapi.h
  // hMap       - ������������� �������� �����
  // number     - ����� ����� � �������
  // value      - ����� ��������� ������(0 - ����� �� ����, 1 - LZW, 2 - JPEG)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstCompressNumber(HMAP hMap, long int number, int value);

  // ��������� ������� ������ ����� ������ �� ��������� JPEG
  // hMap       - ������������� �������� �����
  // number - ����� ����� � �������
  // ���������� ������� ������ ����������� ����� ������ �� ��������� JPEG
  //          (1-100, 1-������������ ������, 100-������ ��� ������ ��������),
  //          ������������� �������� 60.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstCompressJpegQuality(HMAP hMap, long int number);

  // ���������� � ��������� ������ ������� ������ ����� ������ �� ��������� JPEG
  // ����������� ��� ��������� � ��������� ������ ������ ��������� ������ ������� mapSetRstCompressNumber()
  // ��������: ������� �� ��������� ������ �����������
  // ��� ������ ����������� �� ������ JPEG �������������� �������� mapCompressJPEG(), ����������� � mapapi.h
  // hMap       - ������������� �������� �����
  // number - ����� ����� � �������
  // value  - ������� ������ ����������� ����� ������ �� ��������� JPEG
  //          (1-100, 1-������������ ������, 100-������ ��� ������ ��������),
  //          ������������� �������� 60.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstCompressJpegQuality(HMAP hMap, long int number, int value);

  // ������ �������� �� ���������� ��������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string, column - ������ � ������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstPoint(HMAP hMap, long int number, long int *value,
                                        long int string, long int column);

  // ������ �������� �� ���������� ��������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string, column - ������ � ������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPutRstPoint(HMAP hMap, long int number,long int value,
                                        long int string, long int column);

  // ������ ��������  �� ��� ������������� ����������� (� ������) �� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // x,y        - ���������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstPlanePoint(HMAP hMap, long int number,
                                             long int *value, double x, double y);

  // ������ �������� �� ��� ������������� ����������� �� ������ �������������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // x,y        - ���������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstPlanePointTriangle(HMAP hMap, long int number,
                                                     long int *value, double x, double y);


  // ����������� ����� ����� ������ �� ������������� ����������� �����
  // (� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // x,y        - ���������� ��������
  // color      - ���� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstPlanePointColor(HMAP hMap, long int number,
                                                  COLORREF *color, double x, double y);

 // ���������� ������������ - ����������� ����� ����� �� 4 �������� �������� ������
 // hMap       - ������������� �������� ��������� �����
 // number     - ����� ����� � �������
 // color      - ����������� ����������� ������
 // indexColor - ����������� �������� ���������� ����� � ������������ �� ������� ������
 //              (��� 1,4 � 8 ��� �� �������)
 // x, y       - ������������� ���������� ����� � ������� ��������� ������ � ������ �� ���������
 // ��� ��������� � ������� ������� ������ ������������ ���� ���������� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBilinearInterpolationColor(HMAP hMap, long int number, COLORREF* color,
                                                             long int *indexcolor, double x, double y);

 // ������������ ������������ - ����������� ����� ����� �� 16 �������� �������� ������
 // hMap       - ������������� �������� ��������� �����
 // number     - ����� ����� � �������
 // color      - ����������� ����������� ������
 // indexColor - ����������� �������� ���������� ����� � ������������ �� ������� ������
 //              (��� 1,4 � 8 ��� �� �������)
 // x, y       - ������������� ���������� ����� � ������� ��������� ������ � ������ �� ���������
 // ��� ��������� � ������� 2 ������� ������ ������������ ���� ���������� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBicubicInterpolationColor(HMAP hMap, long int number, COLORREF* color,
                                                            long int *indexcolor, double x, double y);

  // ������ ��������  �� ��� ������������� �����������
  // (� ������) � �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // x,y        - ���������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPutRstPlanePoint(HMAP hMap, long int number, long int value,
                                             double x, double y);

  // ������ ������� � ����������� ��������� ������ �� ������������� ����������� (� ������)
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // color  - ���� ������� ���� COLORREF ��� ������� � 16,24,32 ����� �� �������;
  //          ������ ����� � ������� ��� ������� � 1,4,8 ����� �� �������.
  // point1 - ���������� ��������� ����� �������
  // point2 - ���������� �������� ����� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPutRstPlaneLine(HMAP hMap, long int number, long color,
                                            DOUBLEPOINT *point1, DOUBLEPOINT *point2);


  // ��������� ���������� ������ ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBlockCount(HMAP hMap, long int number);

  // ��������� ����� ����� ������ ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBlockRow(HMAP hMap, long int number);


  // ��������� ����� �������� ������ ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBlockColumn(HMAP hMap, long int number);

  // ��������� ������ ������������ ����� ������ � ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBlockSize(HMAP hMap, long int number);

  // ��������� ������ �������� ����� {string,column} ������ � ������
  // (� ������ ��������� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string, column - ���������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstCurrentBlockSize(HMAP hMap,long int number,
                                                   long int string, long int column);

  // ��������� ������ ������������ ����� ������ � ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBlockWidth(HMAP hMap, long int number);

  // ��������� ������ ������������ ����� ������ � ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBlockHeight(HMAP hMap, long int number);

  // ��������� ������ �������� ����� {string,column} ������ � ���������
  // (� ������ ��������� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // column     - ������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstCurrentBlockWidth(HMAP hMap, long int number, long int column);

  // ��������� ������ �������� ����� {string,column} ������ � ���������
  // (� ������ ��������� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstCurrentBlockHeight(HMAP hMap, long int number, long int string);

  // ��������� ����� ����� ������ �� ������ ������ � �������
  // ����� ���������� ���� ����� ����� ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // ��� ������� ���������� ����� ����� ������� ������� �����
  // ��� ������ ���������� ����, ����� - ����� ���������� �����

_MAPIMP char * _MAPAPI mapGetRstBlock(HMAP hMap, long int number,
                                      long int string, long int column);

  // ��������� ����� ����� ������ �� ������ ������ � �������
  // ��� ���������� � ����� - ���������
  // ��� ������� ���������� ����� ����� ������� ������� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // ��� ������ ���������� ����

_MAPIMP char * _MAPAPI mapGetRstBlockAndCreate(HMAP hMap, long int number,
                                               long int string, long int column);

  // ��������� ������� ����� ������ � �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // i          - ���������� ����� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCheckRstBlockExistence(HMAP hMap, long int number, long int i);

  // ������� ����� ����������� �����
  // (0 - �� ������������, 1- ������������, 2 - �������� ������ )
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // i          - ���������� ����� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCheckRstBlockVisible(HMAP hMap, long int number, long int i);

  // ������ ����� {string,column} � ���� ���������� �����������  �� ������ bits.
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // bits       - ��������� �� ������ ����������� ������� �������
  // sizebits   - ������ ������� bits � ������
  // ���������� ���������� ���������� ����.
  // ��� ������ ���������� ����.

_MAPIMP long int _MAPAPI mapWriteRstBlock(HMAP hMap,long int number,
                                          long int string, long int column,
                                          char *bits, long int sizebits);

  // ������ ����� {string,column} �������� "size" �� DIB-����� "mask"
  // �������� "value"
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // mask       - ��������� �� ������ �����
  // size       - ������ ������� mask � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPutRstBlockByMask(HMAP hMap, long int number,
                                              long int string, long int column,
                                              char *mask, long int size,
                                              long int width,long int height, long value);

  // �������� ��������� ������ � ����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveRst(HMAP hMap,long int number);

  // ������ �������������� ������� ������
  // hMap    - ������������� �������� ��������� �����
  // number  - ����� ����� � �������
  // bits    - ��������� �� ������ ����������� ������� �������
  // left    - �������� ����� � ��������� (��������� �� ������� �����)
  // top     - �������� ������ � ���������
  // width   - ������ � ��������� (��������� �� ������� �����)
  // height  - ������ � ���������
  // begining  - ������ �����������:
  //   ==  1  - (bits - ��������� �� ������ ������ ������� �������)
  //   == -1  - (bits - ��������� �� ��������� ������ ������� �������,
  //                          � BMP ����������� �������� ����� - �����)
  // widthinbyte    - ������ �������������� ������� ������ � ������
  // ������� ������������:
  // ��� ElementSize() == 1 (���) - left,width ������ 8,
  //                   == 4 (���) - left,width ������ 2
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapPutRstFrame(HMAP hMap, long int number, char* bits,
                                        long int left, long int top,
                                        long int width, long int height,
                                        long int begining/* = 1*/,
                                        long int widthinbyte /*= 0*/);

  // ������ �������������� ������� ������
  //  hMap       - ������������� �������� ��������� �����
  //  number     - ����� ����� � �������
  //  bits    - ��������� �� ������ ����������� ������� �������
  //  left    - �������� ����� � ��������� (��������� �� ������� �����)
  //  top     - �������� ������ � ���������
  //  width   - ������ � ��������� (��������� �� ������� �����)
  //  height  - ������ � ���������
  //  widthinbyte    - ������ �������������� ������� ������ � ������
  // ������� ������������:
  //  ��� ElementSize() == 1 (���) - left,width ������ 8,
  //                    == 4 (���) - left,width ������ 2
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstFrame(HMAP hMap, long int number,
                                        char* bits, long int left,
                                        long int top, long int width,
                                        long int height, long int widthinbyte = 0);

  // ������ �������� ���������� �������������� ������� ������
  //  hMap       - ������������� �������� ��������� �����
  //  number     - ����� ����� � �������
  //  bitsR,bitsG - ��������� �� ������ ����������� �������� ��������
  //  bitsB         �������, ������� � ����� ���������
  //  left    - �������� ����� � ���������
  //  top     - �������� ������ � ���������
  //  width   - ������ � ���������
  //  height  - ������ � ���������
  //  ������������ ������ 8-������ ������ (����)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstFrameRGB(HMAP hMap, long int number,
                                           char* bitsR, char* bitsG, char* bitsB,
                                           long int left, long int top,
                                           long int width, long int height);

  // ����������� �������������� ������� ��������� ������
  // � �������������� ������, ������������� � ������� ������.
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // bits   - ��������� �� ������ ������� ������;
  // width  - ������ ������� ������ � ��������� COLORREF
  //          (���������� �������� ��������������� ������);
  // height - ������ ������� ������ � ���������
  //          (���������� ����� ��������������� ������);
  // StrL,ColL,StrR,ColR - ���������� ������ � ������� ��������� ���������
  //                       ������, ������� ���������� ������� ���������
  //                       ������� �������������� �������.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstFrameTurn(HMAP hMap, long int number, COLORREF* bits,
                                            long int width, long int height,
                                            double StrL, double ColL, double StrR, double ColR);

  // ����������� �������� ������ � �������
  // ��� �������� �������� �����������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // element    - �������� ������
  // pixel      - ��������� � ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRstElementToPixel(HMAP hMap, long int number, double element, double *pixel);

  // ����������� ������� � �������� ������
  // ��� �������� �������� �����������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // element    - ��������� � ��������� ������
  // pixel      - �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPixelToRstElement(HMAP hMap, long int number,
                                              double pixel, double *element);

  // ������������ ������� ����� �������� ����� {string,column} � ������ ����� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // bits       - ������� ������� �����
  // size       - ������ ������� ������� ����� � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapBuildRstBlockMask(HMAP hMap, long int number,
                                              char *bits, long int size,
                                              long int string, long int column);

  // ���������� ����� ����������� ������ �� ������� �������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ������ ����� � ������������
  // ����� ���������� ������� ����������� ������ ����������� �������� ��������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstMask(HMAP hMap, long int number, HOBJ info);

  // ������� ������ ����� ������, ������������ ������.
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapFillRstVisiblePart(HMAP hMap, long int number, long int color);

  // ��������� ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ������������ ��������:
  //          0 - ��� ������; ��� �������� ����������� ����� � ������ �� �����������
  //          1 - �������� ���� ������� ����������� �����, ������ JPEG ������
  //          2 - �������� ���� ������� ����������� �����, ������ LZW ������
  //          4 - �������� ���� ������� ����������� �����

_MAPIMP long int _MAPAPI mapGetRstProcessingState(HMAP hMap, long int number);

  // ���������� ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // state      - ��������� ������.
  // ��������� �������� ��������� ������ state:
  //          0 - ��� ������; ��� �������� ����������� ����� � ������ �� �����������
  //          1 - �������� ���� ������� ����������� �����, ������ JPEG ������
  //          2 - �������� ���� ������� ����������� �����, ������ LZW ������
  //          4 - �������� ���� ������� ����������� �����
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstProcessingState(HMAP hMap, long int number, long int state);

  // �������������� ����� ��� �������� � ��� ������                             // 17/04/16
  // ������� ��������� ��������� ������ � ��� ������������� ��������� ��� ������
  // ����������� �� ������� (JPEG - ��� 24-� ������ �������, LZW - ��� ���� ���������)
  // � �������� ���� ������� ����������� �����.
  // ���������� ������� ����� �� ���� ���������� ����� ������� �������
  // rswName- ��� ����� ������
  // handle - ������������� ����, ������� ����� ����������
  // � ���� �������� (0x585 - 0x588)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapOptimizationRstByName(const char* rswName, HWND handle);
_MAPIMP long int _MAPAPI mapOptimizationRstByNameUn(const WCHAR* rswName, HWND handle);

 // ��������� ���������� ��������� ����������� ����� � ������                   // 08/04/16
 // hMap       - ������������� �������� �������� ��������� �����
 // number     - ����� ����� � �������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstDuplicatesCount(HMAP hMap, long int number);

  // �������� ����������� �����
  // ���� ����������� ����� �� ����������, ��������� ��� �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapUpdateRstDuplicates(HMAP hMap, long int number);

  // �������� ����������� ����� ����� (string,column) ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdateRstDuplicateOfBlock(HMAP hMap, long int number,
                                                      int string, int column);

  // ��������� ���������������� ������������� ������
  // number    - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstUserLabel(HMAP hMap, long int number);

  // ���������� ���������������� ������������� ������
  // number    - ����� ����� � �������
  // userLabel - ������������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstUserLabel(HMAP hMap, long int number, long int userLabel);

  // ��������� ���������� ���-��������� ���� ������ � ������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� � �������
  // �� ������ x,y ������������ ���������� ��������� ����� � ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapWhereSouthWestRstPlane(HMAP hMap,long int number,
                                                   double *x, double *y);

  // ������� ���� RSW
  // ������� ������������� ��� �������� ������ � ��� ��������� ������
  // ��������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.rsw � *.rsw.01
  // ������ ������� DeleteTheFile()

_MAPIMP long int _MAPAPI mapDeleteRstFile(const char *name);
_MAPIMP long int _MAPAPI mapDeleteRstFileUn(const WCHAR *name);

  // ������������� ��� ����� RSW
  // ������� ������������� ��� ���������������� ������ � ��� ��������� ������
  // ��������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.rsw � *.rsw.01
  // ������ ������� MoveTheFile()

_MAPIMP long int _MAPAPI mapMoveRstFile(const char *oldname, const char *newname);
_MAPIMP long int _MAPAPI mapMoveRstFileUn(const WCHAR *oldname, const WCHAR *newname);

  // ����������� ���� RSW
  // ������� ������������� ��� ����������� ������ � ��� ��������� ������
  // ��������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.rsw � *.rsw.01
  // ������ ������� CopyTheFile()

_MAPIMP long int _MAPAPI mapCopyRstFile(const char *oldname, const char *newname, int exist = 0);
_MAPIMP long int _MAPAPI mapCopyRstFileUn(const WCHAR *oldname, const WCHAR *newname, int exist = 0);

  // ��������� ��� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ����������: 0 - ������� �����
  //             1 - �����-�������� � ������ �������� � ����� TIFF

_MAPIMP long int _MAPAPI mapRstIsAccessTiff(HMAP hMap, long int number);

  // ��������� ��� TIFF-����� ��� ������ � �������  number (����. ����� ������ = MAX_PATH)
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstFileName_Tiff(HMAP hMap, long int number, char *name);

  // ��������� ��� TIFF-����� ��� ������ � �������  number
  // hMap     - ������������� �������� ��������� �����
  // number   - ����� ����� � �������
  // name     - ������������ ���
  // namesize - ������ ������ � ������
_MAPIMP long int _MAPAPI mapGetRstFileName_TiffUn(HMAP hMap, long int number,
                                                  WCHAR *name, int namesize);

  // ��������� ������� �������� ������������� �������� TIFF-�����
  // hMap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // affincoef - ������������ ������� �������� ������������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstAffinCoef_Tiff(HMAP hMap, long int number, AFFINCOEF *affincoef);

  // ���������� ������� �������� ������������� �������� TIFF-�����
  // hMap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // affincoef - ��������������� ������� �������� ������������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstAffinCoef_Tiff(HMAP hMap, long int number, const AFFINCOEF *affincoef);

  // ��������� ���������� ������� TIFF-������ � �������  number
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstBandCount_Tiff(HMAP hMap, long int number);

  // ��������� ����� ������ TIFF-������ � �������  number, ������������� �������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstRedBand_Tiff(HMAP hMap, long int number);

  // ��������� ����� ������ TIFF-������ � �������  number, ������������� �������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstGreenBand_Tiff(HMAP hMap, long int number);

  // ��������� ����� ������ TIFF-������ � �������  number, ������������� �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstBlueBand_Tiff(HMAP hMap, long int number);

  // ���������� ����� ������ TIFF-������ � �������  number, ������������� �������
  // (���� ���������� -1, �� ����� ����� �� ������������)
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapSetRstRedBand_Tiff(HMAP hMap, long int number, int redband);

  // ���������� ����� ������ TIFF-������ � �������  number, ������������� �������
  // (���� ���������� -1, �� ����� ����� �� ������������)
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapSetRstGreenBand_Tiff(HMAP hMap, long int number, int greenband);

  // ���������� ����� ������ TIFF-������ � �������  number, ������������� �����
  // (���� ���������� -1, �� ����� ����� �� ������������)
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapSetRstBlueBand_Tiff(HMAP hMap, long int number, int blueband);

  // ���������� ����������� ������������������� ������ �� �������������� �������
  // ����� ������� ���������� ��������� ��� ������ ������� mapRstIsAccessTiff, ���
  // ��� ������ � ������� number �������������� ������ ������ � ����� TIFF
  // ������� ����������� ��� ������������������ ����������� (mapGetRstBandCount_Tiff() >= 3)

_MAPIMP long int _MAPAPI mapSetRstVegIndex_Tiff(HMAP hMap, long int number, VEGINDEX *vegindex);

  // ���������� ��������� ����������� �������������� �������
  // ���� ����������� �� �������������� ������� �� ����������� ���������� 0
  // ����� ������� ���������� ��������� ��� ������ ������� mapRstIsAccessTiff, ���
  // ��� ������ � ������� number �������������� ������ ������ � ����� TIFF
  // ������� ����������� ��� ������������������ ����������� (mapGetRstBandCount_Tiff() >= 3)

_MAPIMP long int _MAPAPI mapGetRstVegIndex_Tiff(HMAP hMap, long int number, VEGINDEX *vegindex);

  // ���������� ������� ������� ����������� �� ����� bandnum
  // x, y  - ���������� ������� � ������� ��������� ������ (� ��������)
  // color - ������������ �������� ������� ���������� � ������ (����� ���� 1,4,8,16 ���)
  // bandnum - ����� ������ (�� 0 �� mapGetRstBandCount_Tiff - 1)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBandPixel_Tiff(HMAP hMap, long int number,
                                                 long int x, long int y,
                                                 long int bandnum, long int *color);

  // ������������� ������ ������ � ����� ������� �������� ��������� �����������
  // �� ������� �������� ��� ��������� ������ � ������� ���������, �������� ��
  // ������� ��������� ������.
  // ����� ������ �������� ��������� ����������� �������� �������������. ������������
  // ��������� ��������� ������ ������ ����������� �� ���� ������� ����� ������.
  // ��� ���������� ������� ������������� �������� ���������, �� ���������� ��������
  // ����������� ��� ������������ ���������� ������� ��������� ��������� ������������
  // ������� ��������� ������ (����������� �������������� �� ������� ������).
  // ���� �������� �������� ����������, �.�. � ������� ��������� ��� ������
  // �������������� � �������������� ����� ���������
  // radius - ��������������� ������ ������ � �������� (�� ����� ���� ������ 0).
  //          ���� ����� 0, �� ��� ������� ����������� �� ������� ��������.
  //          �������� �� ��������� 3.
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstPaintCellRadius_Tiff(long int radius);

  // ���������� ������ ������ � ����� ������� �������� ��������� �����������
  // �� ������� �������� ��� ��������� ������ � ������� ���������, �������� ��
  // ������� ��������� ������.

_MAPIMP long int _MAPAPI mapGetRstPaintCellRadius_Tiff();

  // ���������� ������� ����� �� ����� (1, 4, 8, 16)
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBitInBand_Tiff(HMAP hMap, long int number);

  // ���������� �����������
  // ����������� - ����������� ������ ���������� ��������, �������������� � ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // count     - ���������� ��������� � ������� histogram
  //             ���������� ��������� ����������� �� �������
  //             count = BandCount * (1 << BitInBand)
  //             ��� ���������� ������� BandCount = 1
  //             ��� 1 ������ ������� (����������) count = 2
  //             ��� 4 ������ ������� (����������) count = 16
  //             ��� 8 ������ ������� (����������) count = 256
  //             ��� RGB                           count = 3 * 256 = 768
  //             ��� 8  ������ ������������������  count = BandCount * 256
  //             ��� 16 ������ ������������������  count = BandCount * 65536
  // histogram - ������������ �����������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstHistogram_Tiff(HMAP hMap, long int number,
                                                 long int count, DWORD *histogram);

  // ���������� ������� �������������� ����� ��� ����������� ����������������,
  // RGB � ������������������ ������� � �������� ����� 8 ��� 16 ���
  // hMap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // bandnum   - ����� ������ (�� 0 �� mapGetRstBandCount_Tiff - 1)
  // table     - ������������ ������� ��������������
  // tablesize - ������ ������� table (��� 8 ��� ������ ���� 256, ��� 16 ��� - 65536)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstLookupTable_Tiff(HMAP hMap, long int number,
                                                   long int bandnum, BYTE *table,
                                                   long int tablesize);

  // ������������� ������� �������������� ����� ��� ����������� ����������������,
  // RGB � ������������������ ������� � �������� ����� 8 ��� 16 ���
  // hMap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // bandnum   - ����� ������ (�� 0 �� mapGetRstBandCount_Tiff - 1)
  // table     - ������������ ������� ��������������
  // tablesize - ������ ������� table (��� 8 ��� ������ ���� �� ������ 256,
  //                                   ��� 16 ��� - �� ������ 65536)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstLookupTable_Tiff(HMAP hMap, long int number,
                                                   long int bandnum, BYTE *table,
                                                   long int tablesize);

  // ���������� ������ ����� � ��������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockWidth_Tiff(HMAP hMap, long int number);

  // ���������� ������ ����� � ��������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockHeight_Tiff(HMAP hMap, long int number);

  // ���������� ������ ������������ �������� ������������ ������� � �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ������������ ��������:
  // 0 - ������ ����������
  // 1 - ��������������� RGB RGB ...
  // 2 - �� �������� ����������  RRR... GGG... BBB...

_MAPIMP long int _MAPAPI mapGetRstBlockPixelType_Tiff(HMAP hMap, long int number);

  // ���������� ���������� ����� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockRowCount_Tiff(HMAP hMap, long int number);

  // ���������� ���������� �������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockColCount_Tiff(HMAP hMap, long int number);

  // ���������� ������ ����� � ������
  // ��� 1 � 4 ������ ������� � ���� ������������ 1 ���� �� �������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockSize_Tiff(HMAP hMap, long int number);

  // ��������� ���� �� ������
  // ��� 1 � 4 ������ ������� � ���� ������������ 1 ���� �� �������
  // hMap     - ������������� �������� ��������� �����
  // number   - ����� ����� � �������
  // blockrow - ����� ������ ������
  // blockcol - ����� ������� ������
  // buf      - �����, � ������� ������������ ����������� �����
  // bifsize  - ������ ����� (������ ���� ����� mapGetRstBlockSize_Tiff)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlock_Tiff(HMAP hMap, long int number, int blockrow,
                                             int blockcol, char *buf, int bufsize);

  // ��������� ���� TIF �� ����������� �������� ��� �������������� � ������ RSW
_MAPIMP long int _MAPAPI mapIsTiffOpenWithoutConvert(const char *name);
_MAPIMP long int _MAPAPI mapIsTiffOpenWithoutConvertUn(const WCHAR *name);      // 19/06/14


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++ �������� ������� �������� TIFF ������ +++++++++++++ 18/09/13
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// ������� TIFF ����
// filename - ��� ������������ TIFF �����
// width    - ������ ������ � ��������
// height   - ������ ������ � ��������
// parm     - ��������� �������� ������
// ���������� ������������� ���������� ������
// ��� ������ ���������� 0

_MAPIMP HANDLE _MAPAPI mapCreateTiff(const char *filename, long int width,
                                     long int height, CREATETIFPARM *parm);
_MAPIMP HANDLE _MAPAPI mapCreateTiffUn(const WCHAR *filename, long int width,
                                       long int height, CREATETIFPARM *parm);

// ����������� ������������� �������� TIFF �����
// tiff - �������������, ���������� ��� �������� TIFF ����� �������� mapCreateTiff

_MAPIMP void _MAPAPI mapFreeTiff(HANDLE tiff);

// ���������� ������ ����� � ��������
// tiff - �������������, ���������� ��� �������� TIFF ����� �������� mapCreateTiff
// ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetTiffBlockWidth(HANDLE tiff);

// ���������� ������ ����� � ��������
// tiff - �������������, ���������� ��� �������� TIFF ����� �������� mapCreateTiff
// ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetTiffBlockHeight(HANDLE tiff);

// ���������� ���������� ����� ������
// tiff - �������������, ���������� ��� �������� TIFF ����� �������� mapCreateTiff
// ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetTiffBlockRowCount(HANDLE tiff);

// ���������� ���������� �������� ������
// tiff - �������������, ���������� ��� �������� TIFF ����� �������� mapCreateTiff
// ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetTiffBlockColCount(HANDLE tiff);

// ���������� ��� ������� �� ����� (��. PT_BYTE � �.�.)
// tiff - �������������, ���������� ��� �������� TIFF ����� �������� mapCreateTiff
// ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetTiffBandPixelType(HANDLE tiff);

// ����� ���� � ����
// tiff    - �������������, ���������� ��� �������� TIFF ����� �������� mapCreateTiff
// bandnum - ����� ������
// col     - ����� ������� �����
// row     - ����� ������ �����
// image   - ����������� �����
//           ������, ������ ����� ������������� ����� mapGetTiffBlockWidth, mapGetTiffBlockHeight
//           ������ ������� � ������ ������� �� ���� �������, ������������ ����� GetTiffBandPixelType
//           � ��������� ������� � �������� ������ ����� �� ���������
// ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapWriteTiffBlock(HANDLE tiff, long int bandnum,
                                           long int col, long int row, void *image);

// ������������� ������� �������� ������
// tiff - �������������, ���������� ��� �������� TIFF ����� �������� mapCreateTiff
// coef - �������, ����������� ������� ��������� ������ � �������� � �������� ��������� ��������� � ������
//        Xmeter = coef->A0 + coef->A1 * Xpix + coef->A2 * Ypix
//        Ymeter = coef->B0 + coef->B1 * Xpix + coef->B2 * Ypix
//        ����������� ����
//        -------------Xrst
//        |    Ymeter
//        |      |
//        Yrst   |
//               ---------- Xmeter
// ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetTiffLocation(HANDLE tiff, AFFINCOEF *coef);

// ������������� ��������� ������� ��������� ������
// tiff      - �������������, ���������� ��� �������� TIFF ����� �������� mapCreateTiff
// mapreg    - ��������� ��������
// ellipsoid - ��������� ����������
// datum     - �����
// ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetTiffProjection(HANDLE tiff, MAPREGISTEREX *mapreg,
                                              ELLIPSOIDPARAM *ellipsoid, DATUMPARAM *datum);


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++ �������� ������� ������� � ����������� ������ +++++++++++++ 08/02/16
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  // ��������� ��� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ����������: 0 - ������� �����
  //             1 - �����-�������� � ������ �������� � ������������ �����
  //                 (TIFF, GeoTIFF, IMG, JPEG, PNG, GIF, BMP)

_MAPIMP long int _MAPAPI mapRstIsAccessGraphicFile(HMAP hMap, long int number);

  // ��������� ��� ������������ ����� ��� ������ � �������  number
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap     - ������������� �������� ��������� �����
  // number   - ����� ����� � �������
  // name     - ������������ ���
  // namesize - ������ ������ � ������
  // ��� ������ ���������� 0
_MAPIMP long int _MAPAPI mapGetRstGraphicFileNameUn(HMAP hMap, long int number,   
                                                    WCHAR *name, int namesize);

  // ��������� ������� �������� ������������� �������� ������������ �����
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // affincoef - ������������ ������� �������� ������������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstAffinCoef_GraphicFile(HMAP hMap, long int number,
                                                    AFFINCOEF *affincoef);

  // ���������� ������� �������� ������������� �������� ������������ �����
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // affincoef - ��������������� ������� �������� ������������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstAffinCoef_GraphicFile(HMAP hMap, long int number,
                                                    const AFFINCOEF *affincoef);

  // ��������� ���������� ������� ������������ ����� � �������  number
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBandCount_GraphicFile(HMAP hMap, long int number);

  // ��������� ����� ������ ������������ ����� � �������  number, ������������� �������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstRedBand_GraphicFile(HMAP hMap, long int number);

  // ��������� ����� ������ ������������ ����� � �������  number, ������������� �������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstGreenBand_GraphicFile(HMAP hMap, long int number);

  // ��������� ����� ������ ������������ ����� � �������  number, ������������� �����
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapGetRstBlueBand_GraphicFile(HMAP hMap, long int number);

  // ���������� ����� ������ ������������ ����� � �������  number, ������������� �������
  // (���� ���������� -1, �� ����� ����� �� ������������)
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapSetRstRedBand_GraphicFile(HMAP hMap, long int number,
                                                      int redband);

  // ���������� ����� ������ ������������ ����� � �������  number, ������������� �������
  // (���� ���������� -1, �� ����� ����� �� ������������)
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapSetRstGreenBand_GraphicFile(HMAP hMap, long int number,
                                                      int greenband);

  // ���������� ����� ������ ������������ ����� � �������  number, ������������� �����
  // (���� ���������� -1, �� ����� ����� �� ������������)
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP long int _MAPAPI mapSetRstBlueBand_GraphicFile(HMAP hMap, long int number,
                                                      int blueband);

  // ���������� ����������� ������������������� ������ �� �������������� �������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // ������� ����������� ��� ������������������ �����������
  //                                     (mapGetRstBandCount_GraphicFile() >= 3)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstVegIndex_GraphicFile(HMAP hMap, long int number,
                                                      VEGINDEX *vegindex);

  // ���������� ��������� ����������� �������������� �������
  // ���� ����������� �� �������������� ������� �� ����������� ���������� 0
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // ������� ����������� ��� ������������������ �����������
  //                                     (mapGetRstBandCount_GraphicFile() >= 3)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstVegIndex_GraphicFile(HMAP hMap, long int number,
                                                      VEGINDEX *vegindex);

  // ���������� ������� ������� ����������� �� ����� bandnum
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // x, y  - ���������� ������� � ������� ��������� ������ (� ��������)
  // color - ������������ �������� ������� ���������� � ������ (����� ���� 1,4,8,16 ���)
  // bandnum - ����� ������ (�� 0 �� mapGetRstBandCount_GraphicFile - 1)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBandPixel_GraphicFile(HMAP hMap, long int number,
                                                      long int x, long int y,
                                                      long int bandnum,
                                                      long int *color);

  // ������������� ������ ������ � ����� ������� �������� ��������� �����������
  // �� ������� �������� ��� ��������� ������ � ������� ���������, �������� ��
  // ������� ��������� ������.
  // ����� ������ �������� ��������� ����������� �������� �������������. ������������
  // ��������� ��������� ������ ������ ����������� �� ���� ������� ����� ������.
  // ��� ���������� ������� ������������� �������� ���������, �� ���������� ��������
  // ����������� ��� ������������ ���������� ������� ��������� ��������� ������������
  // ������� ��������� ������ (����������� �������������� �� ������� ������).
  // ���� �������� �������� ����������, �.�. � ������� ��������� ��� ������
  // �������������� � �������������� ����� ���������
  // radius - ��������������� ������ ������ � �������� (�� ����� ���� ������ 0).
  //          ���� ����� 0, �� ��� ������� ����������� �� ������� ��������.
  //          �������� �� ��������� 3.

_MAPIMP long int _MAPAPI mapSetRstPaintCellRadius_GraphicFile(long int radius);

  // ���������� ������ ������ � ����� ������� �������� ��������� �����������
  // �� ������� �������� ��� ��������� ������ � ������� ���������, �������� ��
  // ������� ��������� ������.

_MAPIMP long int _MAPAPI mapGetRstPaintCellRadius_GraphicFile();

  // ���������� ������� ����� �� ����� (1, 4, 8, 16)
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBitInBand_GraphicFile(HMAP hMap, long int number);

  // ���������� �����������
  // ����������� - ����������� ������ ���������� ��������, �������������� � ������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // count     - ���������� ��������� � ������� histogram
  //             ���������� ��������� ����������� �� �������
  //             count = BandCount * (1 << BitInBand)
  //             ��� ���������� ������� BandCount = 1
  //             ��� 1 ������ ������� (����������) count = 2
  //             ��� 4 ������ ������� (����������) count = 16
  //             ��� 8 ������ ������� (����������) count = 256
  //             ��� RGB                           count = 3 * 256 = 768
  //             ��� 8  ������ ������������������  count = BandCount * 256
  //             ��� 16 ������ ������������������  count = BandCount * 65536
  // histogram - ������������ �����������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstHistogram_GraphicFile(HMAP hMap, long int number,
                                                 long int count, DWORD *histogram);

  // ���������� ������� �������������� ����� ��� ����������� ����������������,
  // RGB � ������������������ ������� � �������� ����� 8 ��� 16 ���
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // bandnum   - ����� ������ (�� 0 �� mapGetRstBandCount_GraphicFile - 1)
  // table     - ������������ ������� ��������������
  // tablesize - ������ ������� table (��� 8 ��� ������ ���� 256, ��� 16 ��� - 65536)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstLookupTable_GraphicFile(HMAP hMap, long int number,
                                                   long int bandnum, BYTE *table,
                                                   long int tablesize);

  // ������������� ������� �������������� ����� ��� ����������� ����������������,
  // RGB � ������������������ ������� � �������� ����� 8 ��� 16 ���
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap      - ������������� �������� ��������� �����
  // number    - ����� ����� � �������
  // bandnum   - ����� ������ (�� 0 �� mapGetRstBandCount_GraphicFile - 1)
  // table     - ������������ ������� ��������������
  // tablesize - ������ ������� table (��� 8 ��� ������ ���� �� ������ 256,
  //                                   ��� 16 ��� - �� ������ 65536)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstLookupTable_GraphicFile(HMAP hMap, long int number,
                                                   long int bandnum, BYTE *table,
                                                   long int tablesize);

  // ���������� ������ ����� � ��������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockWidth_GraphicFile(HMAP hMap, long int number);

  // ���������� ������ ����� � ��������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockHeight_GraphicFile(HMAP hMap, long int number);

  // ���������� ������ ������������ �������� ������������ ������� � �����
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ������������ ��������:
  // 0 - ������ ����������
  // 1 - ��������������� RGB RGB ...
  // 2 - �� �������� ����������  RRR... GGG... BBB...

_MAPIMP long int _MAPAPI mapGetRstBlockPixelType_GraphicFile(HMAP hMap,
                                                             long int number);

  // ���������� ���������� ����� ������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockRowCount_GraphicFile(HMAP hMap,
                                                            long int number);

  // ���������� ���������� �������� ������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockColCount_GraphicFile(HMAP hMap,
                                                            long int number);

  // ���������� ������ ����� � ������
  // ��� 1 � 4 ������ ������� � ���� ������������ 1 ���� �� �������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlockSize_GraphicFile(HMAP hMap, long int number);

  // ��������� ���� �� ������
  // ��� 1 � 4 ������ ������� � ���� ������������ 1 ���� �� �������
  // ����� ������� ���������� ���������, ��������� ������� mapRstIsAccessGraphicFile,
  // ��� ��� ������ � ������� number �������������� ������ ������ � ������������ �����
  // hMap     - ������������� �������� ��������� �����
  // number   - ����� ����� � �������
  // blockrow - ����� ������ ������
  // blockcol - ����� ������� ������
  // buf      - �����, � ������� ������������ ����������� �����
  // bifsize  - ������ ����� (������ ���� ����� mapGetRstBlockSize_GraphicFile)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBlock_GraphicFile(HMAP hMap, long int number,
                                                    int blockrow, int blockcol,
                                                    char *buf, int bufsize);

  // ��������� ����������� ���� �� ����������� �������� ��� �������������� � ������ RSW
_MAPIMP long int _MAPAPI mapIsGraphicFileOpenWithoutConvert(const char *name);
_MAPIMP long int _MAPAPI mapIsGraphicFileOpenWithoutConvertUn(const WCHAR *name);   



}  // extern "C"


#endif  // RSTAPI_H