/****** MAPAPI.H *************** Belenkov O.V.    ***** 02/08/16 ***
******* MAPAPI.H *************** Tarakanova I.R.  ***** 12/01/15 ***
******* MAPAPI.H *************** Kruzhkova E.A.   ***** 12/01/16 ***
******* MAPAPI.H *************** Dishlenko S.G.   ***** 21/04/14 ***
******* MAPAPI.H *************** Borzov A.U.      ***** 02/03/15 ***
******* MAPAPI.H *************** Derevyagina Zh.A.***** 21/06/16 ***
******* MAPAPI.H *************** Kruzhkov A.E.    ***** 22/06/16 ***
******* MAPAPI.H *************** Shabakov D.A.    ***** 26/08/13 ***
******* MAPAPI.H *************** Gheleznyakov V.A.***** 07/06/16 ***
******* MAPAPI.H *************** Shishkova L.A.   ***** 05/05/14 ***
******* MAPAPI.H *************** Osipov    D.A.   ***** 05/06/15 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2016              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*     �������� ���������� ������� � ������� "����������� �����"    *
*                                                                  *
********************************************************************
*                                                                  *
*     �������������� ������� � Windows :                           *
*                                                                  *
*    // �������� ����������                                        *
*    HINSTANCE libInst = ::LoadLibrary("gisacces.dll");            *
*                                                                  *
*    // ����� �������                                              *
*    HMAP (WINAPI * lpfn_OpenData)(const char*, long int);         *
*    (FARPROC)lpfn_OpenMap = GetProcAddress(libInst, "OpenData");  *
*    HMAP hMap = (*lpfn_OpenData)("Noginsk.map",0);                *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

/******************************************************************
********************  ������� ��������� ***************************
*******************************************************************

    X� Xm
  ^
  | (0,0) (������ ���������� "Picture")
  +---------------------------------------------------> X�
  |                                                 ^
  |        (���������� ���� "Client")               |
  |   (0,0)                      X�                 |
  |     ----------------------->                    |
  |     |               |                           |
  |     |        x..... x  ���� ������������        |
  |     |        ....A. |                           |
  |     |        ...+.. |                           |
  |     |        ...... |                         ��������
  |     ---------x------x                    ������ ("Region")
  |     |          ^                                |
  |     |          |                                |
  |     |         ������� �������� ������           |
  |     V                  ("Draw")                 |
  |       Y�                                        |
  |                                                 V
  +----------------------------------------------------> Y� Ym
  |
  |  0,0 (������ ������ "Map" � ��������� � ������,
  |       ������� �.�. ����� �����)
  |
  V        ���������� �.A � ������ X�,Y�; � ����������� X�,Y�
    Y�

******************************************************************/

//   ����������� �����������, ����������� ��������� "MAPAPI",
// ����� ����������� � ��������� ������������ ��������
// (Windows, Linux, QNX, OC - PB � �.�.).
//   ��� ��������� ��������� API - ������� ����� ���������
// ANSI ��� Windows � KO� - 8 ��� UNIX-�������� ������.
// ��������� ���� HWND � HDC � Windows �������� ����������������
// ���� � ������������ ��������� ��������������.
//   ��� ������, ����������� ������� X-Window,
// ��������� HWND � HDC ���������� ��� long int (mapsyst.h),
// �� �������� ��������� �� ��������� ���� XCONTEXT.
//  typedef struct XCONTEXT
//  {
//   Display     xcDisplay;  //  ����� � � - ��������
//   Window      xcWindow;   //  ������������� ����
//   GC          xcContext;  //  ����������� �������� ����
//   DRAWPOINT   xcPoint;    //  ������������ ������� ������ � ���� :
//                           //  �������, �����  ���� � ��������
// }
//   XCONTEXT;


#ifndef MAPAPI_H
#define MAPAPI_H

#if defined(__BORLANDC__)
#ifndef MAPVERSN_H
 #include "mapversn.h"
#endif
#endif

#ifndef MAPGDI_H
  #include "mapgdi.h"    // ��������� ������� ������������
#endif

#ifndef MAPTYPE_H
  #include "maptype.h"   // �������� �������� ���������� MAPAPI
#endif

#ifndef MAPCREAT_H
  #include "mapcreat.h"   // �������� �������� ������ ��� �������� �����
#endif

// ������ ���������� MapAccess
// (���� ����������� "mapacces.h" � �.�.)
#define MAPACCESSVERSION  20160605

// ������ ���������� MAPAPI � ���� ����������
#define MAPAPIVERSION  0x0111304

//enum PPLACE             // ����������� ������� ���������
//    {
//      PP_MAP     = 1,    // ���������� ����� � ������� ����� � ���������
//      PP_PICTURE = 2,    // ���������� ����� � ������� ����������� � ��������
//      PP_PLANE   = 3,    // ���������� ����� � ������� ������������� �������
//                         // �� ��������� � ������
//      PP_GEO     = 4,    // ���������� ����� � ������������� �����������
//                         // � ��������
//    };

//enum VTYPE              // ��� ����������� �����
//    {
//      VT_SCREEN        = 1, // �������� (����� DIB)
//      VT_SCREENCONTOUR = 2, // �������� ���������
//      VT_PRINT         = 3, // ���������� (����� WIN API)
//      VT_PRINTGLASS    = 4, // ���������� ��� ������� ���������
//      VT_PRINTCONTOUR  = 5, // ���������� ���������, ��� �������� ������
//      VT_PRINTRST      = 6, // ���������� �������������� (����� WIN API)
//    };

#ifndef SEEKAPI_H
  #include "seekapi.h"     // �������� ������� ������ � ������ �������� �����
#endif

#ifndef SITAPI_H
  #include "sitapi.h"      // �������� ������� ������� � ����������
#endif

#ifndef MTRAPI_H
  #include "mtrapi.h"      // �������� ������� ������� � ��������
#endif

#ifndef RSTAPI_H
  #include "rstapi.h"      // �������� ������� ������� � �������
#endif

#ifndef RSCAPI_H
  #include "rscapi.h"      // �������� ������� ������� � ��������������
#endif

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++ �������� ������� ������� � ����������� ����� ++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C"
{

  /*********************************************************
  *                                                        *
  *          �������/������� ������ � ������ �����         *
  *                                                        *
  *********************************************************/

  // ������� ������ � �������������� ������������ �� ����
  // (���������,���������,���������...)
  // name - ��� ������������ ����� (MAP, SIT, MTW, RSW, MPT) � ��������� UNICODE
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������, ��� ���� �� �����������
  // ����� \Log\name.log � \Log\name.tac - �������� ������ � ������ ����������
  // error - ����� ���������� ������� ���������� �������� ��� ������
  //        (����� HMAP ����� 0) ��� 0; ���� ������ ��������� � maperr.rh
  // password - ������ ������� � ������ �� �������� ����������� 256-������ ���
  //            ��� ���������� ������ (��� ������ ������ ������ �� �����������������)
  // size     - ����� ������ � ������ !!!
  // �������� ������ ����������, ���� ��� �������� ����� �� ��� ������.
  // ���� ������ �� �������, � �� ��� ������ ��� ��������,
  // �� ������������� ���������� ������ scnGetMapPassword �� mapscena.dll (gisdlgs.dll)
  // ���� ������ ��������� ��������� (mapIsMessageEnable()), �� ������
  // �� ����������, � ��� ���������� ������ ���������� ����� �������� ������
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapOpenAnyDataPro(const WCHAR *name, long int mode,
                                       long int *error,
                                       const WCHAR *password, long int size);

_MAPIMP HMAP _MAPAPI mapOpenAnyData(const WCHAR *name, long int mode = 0,
                                    long int *error = 0);

_MAPIMP HMAP _MAPAPI mapOpenDataUn(const WCHAR * name, long int mode = 0);

  // ������� ��������� ������ (���������� mapOpenData)
  // ���������� ������������� �������� ��������� �����
  // mapname - ��� ����� ����� MAP(�������������), SIT (����������������),
  //           SITX (��������� ������ � ���������� ���������� ������)
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE, ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������, ��� ���� �� �����������
  // ����� \Log\name.log � \Log\name.tac - �������� ������ � ������ ����������
  // password - ������ ������� � ������ �� �������� ����������� 256-������ ���
  //            ��� ���������� ������ (��� ������ ������ �� �����������������)
  // size     - ����� ������ � ������ !!!
  // �������� ������ ����������, ���� ��� �������� ����� �� ��� ������.
  // ���� ������ �� �������, � �� ��� ������ ��� ��������,
  // �� ������������� ���������� ������ scnGetMapPassword �� mapscena.dll (gisdlgs.dll)
  // ���� ������ ��������� ��������� (mapIsMessageEnable()), �� ������
  // �� ����������, � ��� ���������� ������ ���������� ����� �������� ������
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapOpenMapPro(const WCHAR *name,long int mode,
                                   const WCHAR *password, long int size);
_MAPIMP HMAP _MAPAPI mapOpenMapUn(const WCHAR *mapname, long int mode = 0);

  // ��������� �������� �� ������������� ������ ����������           // 28/02/14
  // hMap -  ������������� �������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapIsMapHandleCorrect(HMAP hMap);

  // ������/��������� ���������� ��������� ����������� �������� �����
  // ����� ����� ���������
  // flag - ������� �������� ��������� ���������� �������� ���������
  //        ��� �������� �����, ��������� - ���������
  // ���������� ������ �������� �����

_MAPIMP long int _MAPAPI mapSetStructureControlFlag(long int flag);

  // ���������� ����� ���������� ������ � �����
  // hMap -  ������������� �������� ������
  // mode - ����� ���������� ������ (1 - ����������, 0 - �����������)
  // ��� ���������� ������ �� ��������������� �������� ��������� ��
  // ���� �������� ������ � �� ����������� �������, ��� �����������
  // �������� ������� ���������� ������ �������
  // �� ��������� ���������� ������ ������������� ������� ����� ����������
  // � ������������ ��� ���������� ��������� � �������
  // �������� ����������� ������������� � ��� ��������������� ���������,
  // � ������� ����� ��� ������������ ����������� � ������������ ����������
  // ������
  // ����� ������ mapOpenProject ��� mapAppendProject ������������� �������������
  // ����������� ����� ���������� ������
  // ���������� ������� �������� ������

_MAPIMP long int _MAPAPI mapSetAppendDataMode(HMAP hMap, long int mode);

  // �������� ������ � �������� ����� (�����, �����, �������)
  // hMap -  ������������� �������� ������
  // name - ��� ������������ ����� (SIT, MTW, MTQ, RSW, MPT)
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // ���������� ������������� ���� ������ (FILE_MAP - ��� ����������������
  // �����, FILE_RSW - ��� ������, FILE_MTW - ��� �������, FILE_MTL - ���
  // ������� �����, FILE_MTQ - ��� ������� �������), ������ ����������� �
  // ������ ����������, ���� ������ ��� ���� �������, ����� �������� ������
  // (����, �������, ������) �� ��������
  // transform - ������� ����������������� ���������������� �����
  //             � ����� �������� ������ (���� �������� ������):
  //             0 - �� ���������������� ������ (��������������� "�� ����"),
  //             1 - ���������������� ������ ��� �������� � ��������� �����
  //                 � ����� ��������,
  //            -1 - ������ ������ ������������.
  // � ��������� ������ (-1) ��������������, ��� 0.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendData(HMAP hMap, const char *name,
                                       long int mode = 0);

_MAPIMP long int _MAPAPI mapAppendDataEx(HMAP hMap, const char *name,
                                         long int mode = 0,
                                         long int transform = -1);

  // �������� ������ � �������� ����� (�����, �����, �������)
  // hMap -  ������������� �������� ������
  // name - ��� ������������ ����� (SITX, SIT, MTW, MTQ, RSW, MPT) � ��������� UNICODE
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // transform - ������� ����������������� ���������������� �����
  //             � ����� �������� ������ (���� �������� ������):
  //             0 - �� ���������������� ������ (��������������� "�� ����"),
  //             1 - ���������������� ������ ��� �������� � ��������� �����
  //                 � ����� ��������,
  //            -1 - ������ ������ ������������.
  // � ��������� ������ (-1) ��������������, ��� 0.
  // password - ������ ������� � ������ �� �������� ����������� 256-������ ���
  //            ��� ���������� ������ (��� ������ ������ �� �����������������)
  // size     - ����� ������ � ������ !!!
  // �������� ������ ����������, ���� ��� �������� ����� �� ��� ������.
  // ���� ������ �� �������, � �� ��� ������ ��� ��������,
  // �� ������������� ���������� ������ scnGetMapPassword �� mapscena.dll (gisdlgs.dll)
  // ���� ������ ��������� ��������� (mapIsMessageEnable()), �� ������
  // �� ����������, � ��� ���������� ������ ���������� ����� �������� ������
  // ���������� ������������� ���� ������ (FILE_MAP - ��� ����������������
  // �����, FILE_RSW - ��� ������, FILE_MTW - ��� �������, FILE_MTL - ���
  // ������� �����, FILE_MTQ - ��� ������� �������), ������ ����������� �
  // ������ ����������, ���� ������ ��� ���� �������, ����� �������� ������
  // (����, �������, ������) �� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendAnyData(HMAP hMap, const WCHAR *name,
                                          long int mode = 0, long int transform = -1);

_MAPIMP long int _MAPAPI mapAppendDataUn(HMAP hMap, const WCHAR *name,
                                         long int mode = 0);

_MAPIMP long int _MAPAPI mapAppendAnyDataPro(HMAP hMap, const WCHAR *name,
                                             long int mode = 0, long int transform = -1,
                                             const WCHAR *password = 0, long int size = 0);

  // ��������� ������ ������ �� ����� �����
  // ��� ������ ���������� ����

_MAPIMP double _MAPAPI mapGetDataSize(const char *name);
_MAPIMP double _MAPAPI mapGetDataSizeUn(const WCHAR *name);

  // ��������� ��� ������� ����� � ��������� ��� ��� �������,
  // ���� ������ ������
  // hMap -  ������������� �������� ������
  // ��� ������ ���������� ������ ������

_MAPIMP const char* _MAPAPI mapGetMainName(HMAP hMap);
_MAPIMP const WCHAR * _MAPAPI mapGetMainNameEx(HMAP hMap);             // 17/02/14  

  // ��������� � ��������� UNICODE ��� ������� ����� � ��������� ��� ��� �������,
  // ���� ������ ������
  // hMap -  ������������� �������� ������
  // name - ����� ������ ��� ������ ����������
  // size - ����� ������ � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMainNameUn(HMAP hMap, WCHAR *name, long int size);

  // ��������� ��� (������ ���� � �����) ������� ����� � ���������
  // ��� � ������� (MPT)
  // hMap -  ������������� �������� ������
  // ��� ������ ���������� ������ ������

_MAPIMP const char* _MAPAPI mapGetMainMapName(HMAP hMap);

  // ��������� ��� (������ ���� � �����) ������� ����� � ���������
  // ��� � ������� (MPT)
  // hMap     -  ������������� �������� ������
  // name     - ����� ��� ������������ ������
  // namesize - ������ ������ � ������
  // ��� ������ ���������� 0
  
_MAPIMP long int _MAPAPI mapGetMainMapNameUn(HMAP hMap, WCHAR *name, int namesize);

  // �������� ������������ ���������� ������ �, ���� ����, �� ����������
  // ��������� �� �������� ���������� 0 - ������ ������������� ���������
  //                                  1 - �������������
  // ��������� MAPREGISTEREX, LISTREGISTER ������� � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCheckAndUpdate(MAPREGISTEREX *mapreg, LISTREGISTER *listreg,
                                           long int priority);

  // ���������� ���������� ������ � ����������� �� ���� �����
  // ��������� MAPREGISTEREX, LISTREGISTER ������� � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRegisterFromMapType(int maptype, MAPREGISTEREX *mapreg);

  // ��������� ���������� ��������� ��� ��������
  // code - ����� �������� �� MAPPROJECTION (mapcreat.h)
  // ���������� ���������� ������ PROJECTIONPARAMETERS (mapcreat.h)
  // ��������: �������� 49 = EPP_AXISMERIDIAN|EPP_FALSEEASTING|EPP_FALSENORTHING
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetProjectionParameters(long int code);

  // ������� ����� ����� (����� ��������� �����)
  // mapname - ������ ��� ����� ����� (MAP, SIT, SITX)
  // rscname - ������ ��� ����� �������� (RSC)
  // ���������� ������������� �������� ��������� �����
  // ��������� MAPREGISTEREX � LISTREGISTER ������� � mapcreat.h
  // sheetnames - �������� (UTF-16) ����� �����, ������������ � ������ ����� (��� ������������� �����),
  // ��� ���������������� ����� (�� ������������ ������) �������� ����� � ������������ ���������,
  // � �������� ������ ������ ��������� � ��������� �������� �����
  // mainname - ������� �������� (UTF-16) ������������� ����� (MAP),
  // ��� ���������������� ����� ��������� � ��������� ����� �����
  // (��������� ������� �������� ����� ����� �������� mapGetSiteNameUn)
  // password  - ������ ������� � ������ �� �������� ����������� 256-������ ���
  //             ��� ���������� ������ (��� ������ ������ �� �����������������)
  //             (�������������� ��� ���� � ����������� SITX - ��������� �
  //              ����� �����) ��� 0
  // size      - ����� ������ � ������ !!! ��� 0
  // ���������� ������������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapCreateMapPro(const WCHAR * mapname,        // 14/10/14
                                     const WCHAR * rscname,
                                     MAPREGISTEREX * mapreg,
                                     LISTREGISTER * listreg,
                                     SHEETNAMES  * sheetnames,
                                     const WCHAR * mainname,
                                     const WCHAR * password, long int size);

_MAPIMP HMAP _MAPAPI mapCreateMapUn(const WCHAR * mapname,
                                    const WCHAR * rscname,
                                    MAPREGISTEREX * mapreg,
                                    LISTREGISTER * listreg,
                                    const WCHAR * mainname,
                                    const WCHAR * password, long int size);

_MAPIMP HMAP _MAPAPI mapCreateMapEx(const char * mapname,
                                    const char * rscname,
                                    MAPREGISTEREX * mapreg,
                                    LISTREGISTER * listreg);

  // ������� ����
  // (����� � ������� ������� ���������)
  // mapname - ������ ��� ����� �����
  // rscname - ������ ��� ����� ��������
  // ���������� MAPREGISTEREX, LISTREGISTER ������� � mapcreate.h
  // ���������� ������������� �������� ��������� �����
  // ��������� CREATEPLAN ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapCreatePlane(const char * mapname,
                                    const char * rscname,
                                    CREATEPLANE * createplane);

_MAPIMP HMAP _MAPAPI mapCreatePlaneUn(const WCHAR * mapname,                    // 05/05/14
                                      const WCHAR * rscname,
                                      CREATEPLANE * createplane);

  // ������� ���������������� �����
  // mapname - ������ ��� ����� ����� � ��������� UNICODE
  // rscname - ������ ��� ����� �������� � ��������� UNICODE
  // ���������� ������������� �������� ��������� �����
  // ��������� CREATESITEUN ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapCreateSiteUn(const WCHAR * mapname,
                                     const WCHAR * rscname,
                                     CREATESITEUN * createsite);

  // ������� ���������������� ����� �� �������� �����
  // hmap -  ������������� �������� ������
  // mapname - ������ ��� ����� ����� � ��������� UNICODE
  // rscname - ������ ��� ����� �������� � ��������� UNICODE
  // ��������� CREATESITEUN ������� � maptype.h
  // ���������� ������������� �������� ���������������� �����
  // ��� ������ ���������� ����

_MAPIMP HSITE _MAPAPI mapCreateAndAppendSiteUn(HMAP hmap,
                                               const WCHAR * mapname,
                                               const WCHAR * rscname,
                                               CREATESITEUN * createsite);

  // ������� ��������� ���������������� �����
  // rscname - ������ ��� ����� ��������
  // ����� ����� ����������� � ������� ���������� �������
  // � ����� ���������� �����, ������������ �������������
  // ��� �������� ����� ��� ����� ������ ���������
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapCreateTempSite(const char * rscname);
_MAPIMP HMAP _MAPAPI mapCreateTempSiteUn(const WCHAR * rscname);

  // ������� ��������� ���������������� �����
  // rscname - ������ ��� ����� ��������
  // mapreg  - ��������� �������� ����������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapCreateTempSiteEx(const char *rscname, MAPREGISTEREX *mapreg);
_MAPIMP HMAP _MAPAPI mapCreateTempSiteExUn(const WCHAR *rscname, MAPREGISTEREX *mapreg,
                                           DATUMPARAM *datum, ELLIPSOIDPARAM *ellipsoid);

  // ������� ��������� ���������������� ����� �� �������� �����
  // hmap    -  ������������� �������� ������
  // rscname - ������ ��� ����� ��������, ���� ����� 0 - ����������
  // �� �������� �����
  // ����� ����� ����������� � ������� ���������� �������
  // � ����� ���������� �����, ������������ �������������
  // ��� �������� ���������������� ����� ��� ����� ������ ������������� ���������
  // ���������� ������������� �������� ���������������� �����
  // ��� ������ ���������� ����

_MAPIMP HSITE _MAPAPI mapCreateAndAppendTempSite(HMAP hmap, const char *rscname);
_MAPIMP HSITE _MAPAPI mapCreateAndAppendTempSiteUn(HMAP hMap, const WCHAR *rscname);

  // ���������� ��������� Datum ��� �����
  // ����� ����������� ��� �� ������ �������� �� ����� ���
  // � ������ ������ - ��� ����� �������� ������������� ���������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetSiteDatum(HMAP hmap, HSITE hSite, DATUMPARAM * parm);

  // ��������� ��������� Datum ��� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetSiteDatum(HMAP hmap, HSITE hSite, DATUMPARAM * parm);

  // ���������� ��������� ���������� ��� �����
  // ����� ����������� ��� �� ������ �������� �� ����� ���
  // � ������ ������ - ��� ����� �������� ������������� ���������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetSiteEllipsoidParameters(HMAP hMap, HSITE hSite,
                                                       ELLIPSOIDPARAM * parm);

  // ��������� ��������� ���������� ��� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetSiteEllipsoidParameters(HMAP hMap, HSITE hSite,
                                                       ELLIPSOIDPARAM * parm);

  // ����������� ������� �����
  // ��� ����������� �������. HMAP �������� �������, �
  // ����� ����������� �����
  // name     - ��� ����������� �����
  // password - ������ ������� � ������ �� �������� ����������� 256-������ ���
  //            ��� ���������� ������ (��� ������ ������ �� �����������������)
  // size     - ����� ������ � ������ !!!
  // ��� ������ ���������� ���� (� ���� ������ ����� ��������
  // �������� ������� ����� ��� �������)

_MAPIMP long int _MAPAPI mapReOpenMapPro(HMAP hMap, const WCHAR * name, const WCHAR * password, long int size);
_MAPIMP long int _MAPAPI mapReOpenMap(HMAP hMap, const char * name);

  // ������� ��� ������ ����������� �����
  // hmap -  ������������� �������� ������
  // ������������� HMAP ���������� ���������������� !

_MAPIMP void _MAPAPI mapCloseData(HMAP hMap);

  // ������� ��� ������ ����������� �����
  // hmap -  ������������� �������� ������
  // ������������� HMAP ���������� ���������������� !

_MAPIMP void _MAPAPI mapCloseMap(HMAP hMap);

  // ����������� ������ �����         // 09/01/07
  // oldname - ������ ��� ������
  // newname - ����� ��� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCopyMap(const char * oldname, const char * newname);
_MAPIMP long int _MAPAPI mapCopyMapUn(const WCHAR *oldname, const WCHAR *newname);

  // ������� � ������� ��������� ����� (��� ����� ������)
  // hmap - ������������� �������� ������
  // ����� �������� ������������� hMap �� ������ ��������������,
  // ��� ����� mapCloseData()
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteMap(HMAP hMap);

  // �������� ������ �����
  // name      - ��� ��������� �����
  // rscdelete - ������� �������� ����� �������������� ������ � ������
  // ������������� ���������� ������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteMapByName(const char *name);
_MAPIMP long int _MAPAPI mapDeleteMapByNameUn(const WCHAR *name);
_MAPIMP long int _MAPAPI mapDeleteMapByNameEx(const WCHAR *name, long int rscdelete);  // 11/05/15

  // ������� ������ ������ (�����, ����������, ������, �������...)
  // name - ��� ����� ������� (MPT : ���������, ��� � INI)
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapOpenProject(const char *name);
_MAPIMP HMAP _MAPAPI mapOpenProjectUn(const WCHAR *name);

  // �������� ������ ������ (�����, ����������, ������, �������...)
  // name - ��� ����� ������� (MPT : ���������, ��� � INI)
  // ��� ������ ���������� ����

_MAPIMP int _MAPAPI mapAppendProject(HMAP hMap, const char *name);
_MAPIMP int _MAPAPI mapAppendProjectUn(HMAP hMap, const WCHAR *name);

  // ��������� ��� ��������� �������
  // ��� ������ ���������� ������ ������

_MAPIMP const char * _MAPAPI mapGetProjectName(HMAP hMap);

  // ��������� ��� ��������� �������
  // hmap     -  ������������� �������� ������
  // name     - ����� ��� ���������� ������������ ������
  // namesize - ������ ������ � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetProjectNameUn(HMAP hMap, WCHAR *name, long int namesize);

  // ��������� ������� �������� ������ � ������� ������
  // hmap -  ������������� �������� ������
  // name - ��� ����� ������� (MPT : ���������, ��� � INI)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveProjectUn(HMAP hMap, const WCHAR * name);
_MAPIMP long int _MAPAPI mapSaveProject(HMAP hMap, const char * name);

  // ��������� - �������� �� �������� �������� (MPT)          // 29/07/15
  // hmap -  ������������� �������� ������
  // ���� ��� ������ - ���������� ��������� ��������

_MAPIMP long int _MAPAPI mapIsDocProject(HMAP hMap);

  // ��������� ������� ��������� ���� ����� � INI-���� �����,
  // ��� ����� ����� ��������� ����� mapGetMapIniName()
  // ���������� ����� ��������� ���� �����
  // ��������� �������� �������� ������, �������, �������, �������� ���������,
  // ���������������, ������ ������������ ��������...
  // hmap  -  ������������� �������� ������
  // point -  ���������� ������ ���� � ������ (����� ���� 0)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveMapState(HMAP hMap, DOUBLEPOINT *point);

  // ������������ ��������� ���� ����� �� INI-����� �����,
  // ��� ����� ����� ��������� ����� mapGetMapIniName()
  // ���������� ����� �������� �����
  // ��������������� �������� ������ ������, �������, �������, �������� ���������,
  // ���������������, ������ ������������ ��������...
  // hmap  -  ������������� �������� ������
  // point -  ���������� ������ ���� � ������ (����� ���� 0)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRestoreMapState(HMAP hMap, DOUBLEPOINT *point);

  // ��������� - ���� �� �����-���� �������� ������
  // ������ - ���������, ���������, ���������...
  // hmap -  ������������� �������� ������
  // ���� �������� ������ ��� ��� ������ - ���������� ����

_MAPIMP long int _MAPAPI mapIsActive(HMAP hMap);

  // ��������� - ���� �� �����-���� �������� ��������� �����
  // ���� �������� ��������� ���� ��� ��� ������ - ���������� ����

_MAPIMP long int _MAPAPI mapIsVectorMapActive(HMAP hMap);

  // ��������� - ���� �� �����-���� �������� ��������� �����,
  // ��������� ��� ��������������
  // ���� ��������� ��� �������������� ��������� ���� ���
  // ��� ������ - ���������� ����

_MAPIMP long int _MAPAPI mapIsVectorMapEdit(HMAP hMap);

  // ��������� - ���� �� �����-���� �������� ��������� �����
  // ���� �������� ��������� ���� ��� ��� ������ - ���������� ����

_MAPIMP long int _MAPAPI mapIsVectorActive(HMAP hMap);

  // ��������� ������������ ������ ����������� �����
  // � ������ � �� ����� (��� ��������������������� �������
  // � ������)
  // hmap -  ������������� �������� ������
  // ���� ��������� ������ � ������ ���������� (�� ������
  // � �����) - ���������� ��������� �������� (1), ����� 0
  // ���� ����� ������ ���� ������� - ���������� 2
  // (������ �� ��� ������ ���������!)
  // ���� ��������� ���������� - ���������� ������������
  // ����������� �����
  // ����� ��������� ������������� ��������� ������������
  // � �������� ������ ����������

_MAPIMP long int _MAPAPI mapAdjustData(HMAP hMap);

  // ���������� ����������� ��� ���������� ������� Adjust
  // mode - ������� ����������� ��������� ������� Adjust,
  //        ���� ����� 0 - ������� �� ��������������.
  // ��� ���������� ���������� �������� (������ �������
  // ����������, ����������������� ������ � �.�.) �������������
  // ��������� ������� Adjust, ���� ��� ����� ���� ������� ��
  // ������ ������� ����������. ������� Adjust ����� ��������
  // ������������ ���� � ����������������� ������.
  // ���������� ������� ��������

_MAPIMP long int _MAPAPI mapSetAdjustMode(HMAP hMap, long int mode);

  // ��������� ������ �� ����
  // ��� ������ �� Sparc-��������� ����� ��������� ������ � ����� Intel-���������
  // hMap - ������������� ������� �����
  // hSite - ������������� ���������������� �����
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapFlushData(HMAP hMap, HSITE hSite);


  // �������(��������) ����� ���� � ������
  // hmap -  ������������� �������� ������
  // ��������� LISTREGISTER ������� � mapcreat.h
  // ��� ������ ���������� ����, ����� - ����� ���������� �����

_MAPIMP long int _MAPAPI mapCreateList(HMAP hMap, LISTREGISTER *sheet);

_MAPIMP long int _MAPAPI mapCreateListPro(HMAP hMap, LISTREGISTER *sheet,
                                          SHEETNAMES * sheetnames);      // 07/11/14

  // ������� ��������� ���� �����
  // list - ����� ����� (� 1)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteList(HMAP hmap, long int list);

  // �������� ����� �� ������� ������ ����� � ������
  // hmap -  ������������� �������� ������
  // mapname - ����������� �����,
  // handle - ������������� ����,������� ����� ����������
  // � ���� �������� (0x585 - 0x588)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendMapToMap(HMAP hMap, const char *mapname, HWND handle);
_MAPIMP long int _MAPAPI mapAppendMapToMapUn(HMAP hMap, const WCHAR *name, HWND handle);

  // C������ ������ ������ ��������� �����
  // (�������� ���������� - ��. �������������� �������)
  // �� ��������� ������� FLOAT 2-�� ������
  // hmap - ������������� �������� ������
  // sheetnumber - ����� ����� � ������� ����� ����������
  // kind - ��� ����������� �������, ������ � maptype.h
  // ����������� ������
  // text - ������� ������� � ������� (������� ���� "�������")
  // (��������������� ������������� ��� ������ mapPutText(...))
  // ����� ������ ������� ���� What...() � Seek...() ��� ���������
  // ����������� ������� ����� ���������� (text,kind,list � �.�.)
  // ��� ������ ���������� ����

#ifndef HIDEFORMAT
_MAPIMP HOBJ _MAPAPI mapCreateObject(HMAP hMap, long int sheetnumber = 1,
                                     long int kind = IDDOUBLE2,
                                     long int text = 0);
#endif

  // �������� ���������� �������
  // (��� ���������� ����������, ��� ������� �������)
  // hmap - ������������� �������� ������
  // sheetnumber - ����� ����� � ������� ����� ����������
  // kind - ��� ����������� �������, ������ � maptype.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapClearObject(HOBJ info,
                                        long int sheetnumber = 1,
                                        long int kind = IDDOUBLE2);

  // C������ ����� ������� ��������� �����
  // hmap - ������������� �������� ������
  // info - ������������� ������� ����� � ������
  // ��� ������� ����������� � ������ �� �������������
  // �������������� HOBJ ��������� ����� ������� mapFreeObject()
  // ��� ������ ���������� ����

_MAPIMP HOBJ _MAPAPI mapCreateCopyObject(HMAP hMap, HOBJ info);

  // ������� ����� ������� ��������� (src) ����� � ������ ������ (dest)
  // ��� ������� ����������� � ������ �� �������������
  // �������������� HOBJ ��������� ����� ������� mapFreeObject()
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapReadCopyObject(HOBJ dest, HOBJ src);

  // ������� ����� ���������� ��������� (src) ����� � ������ ������ (dest)   // 20/08/13
  // ��� ������� ����������� � ������ �� �������������
  // �������������� HOBJ ��������� ����� ������� mapFreeObject()
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapReadCopySubject(HOBJ dest, HOBJ src, long int subject);

  // C������ ����� ������� ��������� �����, ��� ������ ������� (!)
  // hmap - ������������� �������� ������
  // info - ������������� ������� ����� � ������
  // ��� ������� ����������� � ������ �� �������������
  // �������������� HOBJ ��������� ����� ������� FreeObject()
  // ��� ������ ���������� ����

_MAPIMP HOBJ _MAPAPI mapCreateCopyObjectAsNew(HMAP hMap, HOBJ info);

  // C������ ����� ������� ��������� �����, ��� ������ �������
  // ��� ������� ����������� � ������ �� �������������
  // �������������� HOBJ ��������� ����� ������� FreeObject()
  // src  - �������� ������,
  // dest - ����� ������� (��� ���������� - ����� ������ �����)
  // ��������������, ��� �� ���������� � ����� ���-�� ��������.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCopyObjectAsNew(HOBJ dest, HOBJ src);

  // ������� �������� ������� ��������� ����� �� ������
  // info - ������������� ������� ����� � ������
  // ��� ���������� ������� �� ����� ����������
  // �� ������ mapFreeObject(...) ��������� �������
  // mapCommitObject(...)
  // ��� ������ ���������� ����

_MAPIMP void _MAPAPI mapFreeObject(HOBJ info);

  // ��������� ��� ������ ��������� �������� ������� � ������
  // ���� ������ - ��. maperr.rh

_MAPIMP long int _MAPAPI mapGetAccessError();

  // ������� ������, ������� ����������� ��������� ����� ��������������
  // ���� ����������� ����
  // ����������� ��� ��������� � ������ catch(..) ��� ������ �����������
  // ����� ��� ������ ��������������� ����������
  // hmap - ������������� �������� ������;
  // info - ������������� ������������� �������,
  // � ������� ����� �������� ��������� ������.
  // ���� ����� ������ �� ���������� - ���������� ����
 
_MAPIMP long int _MAPAPI mapReadLastViewObject(HMAP hMap, HOBJ info);

  // ���������, ������������� �� ������ �� �������
  // ������ ������� ����� ���� ���������� � ��������
  // � ��������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapIsObjectStretch(HOBJ info);


  /*********************************************************
  *                                                        *
  *    ������� ����������� � ������ ����������� �����      *
  *  ��������� ��������� ������������ (HDC) � �����������  *
  *  �������� �� ������� ������ � ���� ::SetViewportOrgEx()*
  *                                                        *
  *  ������ ��������, �������� �� ���� ����� �� ����� ���  *
  *  � ������, �� ����� ������� �������� ������!           *
  *  ������������ ������ - ��. PaintToDib,PaintToImage,    *
  *                            PaintToXImage               *
  *                                                        *
  *********************************************************/

 // ���������� ����� ��������� �������� ��������� ��� �����������,
 // ������ � ������� ���������
 // hmap  - ������������� �������� ������ (���������)
 // ��������� MAPREGISTER, DATUMPARAM � ELLIPSOIDPARAM ������� � mapcreat.h
 // ������������� ����� ��������� �������� ����� ��� ���������
 // ��������������� �������� ������������� ��������� (mapIsGeoSupported() != 0)
 // ����� ��������� ����� ���������� �������� ����������� ����� �����������
 // � �������� ��������. ��������� �����, ������� ������ ���������
 // ��������, ���������������� � �������� �����������.
 // ������� � ������ �� ���������������� ��� ����������� � ������ ����� 
 // �� �� ��������� ��������, ��� � ����� ��������� ���������
 // ��� �������� � ������������ (mapPlaneToGeo, mapGeoToPlane, 
 // mapPlaneToGeoWGS84, mapAppendPointPlane, mapInsertPointPlane,
 // mapUpdatePointPlane, mapAppendPointGeo � ������) �����������
 // � ������� ��������� ���������, ������������ ������ ����������� ��������
 // ��� ������\������ ��������� � ���������� ����� ����������� ��������
 // �� ������� ��������� ���������
 // ��������, ��� ������ ��������� �� WGS84 �� ����� � ��-42 �����
 // ���������� ����� ��������� ���������, ��� "������/������� �� WGS-84"
 // � ��������� ������ ��������� �������� mapAppendPointGeo, �� ��������
 // � �������������� ��������� ���������, ��� ������� ���������� ��������
 // mapGetGeoPoint (��� �������� mapGetGeoPointWGS84, ������������ ���������
 // ���������).
 // ����� ���������� ������� ��������� �������� � ������� ���������, ��� � ������
 // ����� � ��������� ����� �������� � �������� ���������� (����� hMap) ����,
 // ��� ������� mapClearDocProjection.
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetDocProjection(HMAP hMap,
                                             MAPREGISTEREX * map,
                                             DATUMPARAM * datum,
                                             ELLIPSOIDPARAM * ellparm);

_MAPIMP long int _MAPAPI mapClearDocProjection(HMAP hMap);
                                             
 // ��������� ����� ��������� �������� ��������� ��� �����������,
 // ������ � ������� ���������
 // hmap  - ������������� �������� ������ (���������)
 // ��������� MAPREGISTER, DATUMPARAM � ELLIPSOIDPARAM ������� � mapcreat.h
 // ���� ��������� �� ��������������� �������� mapSetMapInfoEx,
 // �� ��� ������������ ���������� �����, �������� � ��������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetDocProjection(HMAP hMap,
                                             MAPREGISTEREX * map,
                                             DATUMPARAM * datum,
                                             ELLIPSOIDPARAM * ellparm);


 // ��������� - ��������������� �� ����� ��������� �������� ��������� 
 // ��� �����������, ������ � ������� ���������
 // hmap  - ������������� �������� ������ (���������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapIsDocProjection(HMAP hMap);

 // ��������� ������� ������ ����������� ����� � ��������
 // ��� �������� ��������
 // hmap - ������������� �������� ������
 // � ���������� width ��������� ������ ����������� (dx),
 // � ���������� height - ������ (dy)

_MAPIMP void _MAPAPI mapGetPictureSize(HMAP hmap, long int *width,
                                       long int *height);
_MAPIMP void _MAPAPI mapGetPictureSizePro(HMAP hmap, double * width,
                                          double * height);
                                          
_MAPIMP long int _MAPAPI mapGetPictureHeight(HMAP hMap);
_MAPIMP long int _MAPAPI mapGetPictureWidth(HMAP hMap);

 // ��������� ������ ������� ����������� ����� � ������ �� ���������
 // ��� �������� �������� �����������
 // ��� ������ ���������� ����

_MAPIMP double _MAPAPI mapGetPixelWidth(HMAP hMap);

 // ��������� ������ ������� ����������� ����� � ������ �� ���������
 // ��� �������� �������� �����������
 // ��� ������ ���������� ����

_MAPIMP double _MAPAPI mapGetPixelHeight(HMAP hMap);

 // ��������� ������������� ���������� ������� �����
 // hmap - ������������� �������� ������
 // ��� ������ ���������� ����

_MAPIMP HPALETTE _MAPAPI mapGetMapPalette(HMAP hmap);

 // ��������� �������� ����� ������� �� ������� (index)
 // hmap - ������������� �������� ������
 // ����� ������� ������� ����� ����

_MAPIMP COLORREF _MAPAPI mapGetMapColor(HMAP hmap, long int index);

 // ��������� ����� ������ ���������� �������
 // hmap - ������������� �������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetColorCount(HMAP hmap);

 // ���������� �������� ����� �� �������� ����������
 // � ������� �������� � ������� ��������
 // hmap - ������������� �������� ������
 // hdc   - ������������� ��������� ���������� ������,
 // erase - ������� �������� ���� ����� �������,
 // (0 - ��� �� �������, !=0 - �������� �������� ������ ����,
 //  ��� ��������� ������� ������ (VT_SCREEN) ������ �������
 //  ������ ����, ����� �������� -2 (����� 2))
 // rect  - ���������� ��������� ����� (Draw)
 // � ����������� (Picture).
 // � ������������� ������ 32000�32000 �������� ������
 // ��� Windows NT (Windows 95 ����� 16-������� �������)
 // ������ ��������, �������� �� ���� �����, �� �����
 // ������� �������� ������! ����� - ��. PaintToDib,PaintToImage...

_MAPIMP void _MAPAPI mapPaint(HMAP hmap, HDC hdc, long int erase, RECT *rect);

 // �������/������� �������� ����������� ��� �������������� ������   // 26/10/15
 // ������� mapPaintByFramePro ��� mapPaintByFrameToXImagePro
 // hmap - ������������� �������� ������
 // ��� ������� ������ ��������� ���� �������� � ���������� � �������� ��������� �������
 // � ������ ��������� ��������� ���� ����� ����������� � ���������� ������ ��� ��������� �������
 // ������ ������������� ������ ������ ������ ����������� ����� �������� 1-2 ������,
 // ���������� ����� ����������� ��� ������� 1920x1080 �������� 8 ����� 
 // ������ ����� ��������������� ���������� - mapSetMaxScreenImageSize
 // ��� ������ ���������� ����

_MAPIMP HPAINT _MAPAPI mapCreatePaintControl(HMAP hmap);
_MAPIMP void _MAPAPI mapFreePaintControl(HPAINT hPaint);

 // ������� ������������� �������� ������ � ��������� �����������     // 26/10/15
 // ����������� ��� ���������������� ��������� � ������������� �������� 
 // � ����� ����������� ������ ��������� �� ���������� HMAP
 // ��� ��������� �����
 // hPaint - ������������� ��������� ����������� ��� �������������� ������ ������� �����������
 // hmap - ������������� �������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetPaintControlMapHandle(HPAINT hPaint, HMAP hmap);

 // ���������� ��������� ������� ��������� ��������� � ��������� �����������      // 05/11/15
 // ����������� ��� ��������� ������� ��������� ������������ �����������
 // �� ���� EPSG
 // hPaint - ������������� ��������� ����������� ��� �������������� ������ ������� �����������
 // epsgcode - ��� EPSG ��� ��������� ������� ��������� (��������, 3395, 3857, 4326)
 // ��� ������������� ������ ��������� ���������� 2,
 // ��� ������� ������������� ���������� 1.
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetPaintControlProjection(HPAINT hPaint, long int epsgcode);

 // ��������� ������������� �������� ������, ��� ������� ������ �������� �����������
 // hPaint - ������������� ��������� ����������� ��� �������������� ������ ������� �����������
 // ��� ������ ���������� ����

 _MAPIMP HMAP _MAPAPI mapGetPaintControlMapHandle(HPAINT hPaint);

#ifdef WIN32API
 // ��������� �������� ���������� ����������� ��� ������������ ������  // 26/10/15
 // hPaint - ������������� ��������� ����������� ��� �������������� ������ ������� �����������
 // �������� ���������� ������ ����� ����������� ��� ��������� �������� �����������,
 // ������ �������� ����� ���������� ����� (�����, �������) �
 // ��� ���������� �������� �����������
 // ��� ������ ���������� ����

 _MAPIMP HDC _MAPAPI mapGetPaintControlDC(HPAINT hPaint);
#endif 

 // ����������� ���������� ������������ ������ � �������� �������      // 26/10/15
 // hPaint - ������������� ��������� ����������� ��� �������������� ������ ������� �����������
 // imagedesc - �������� ��������� ������ �����������
 // ��� ������ ���������� ����

 _MAPIMP long int _MAPAPI mapCopyPaintControlToXImage(HPAINT hPaint, XIMAGEDESC * imagedesc);
 
 // ���������� �������� �����, �������������� �� �������� ������ � ������
 // � ������� ������� �������� (����������� ��� ��������� OGC WMS-��������)
 // hmap - ������������� �������� ������
 // hdc   - ������������� ��������� ���������� ������,
 //         ���� �������� ���������� ������ ����� 0, �� ��������� �����������
 //         �� ���������� ����� ��������� ����������� (hPaint) 
 // erase - ������� �������� ���� ����� �������,
 //        (0 - ��� �� �������, !=0 - �������� �������� ������ ����,
 //         ��� ��������� ������� ������ (VT_SCREEN) ������ �������
 //         ������ ����, ����� �������� -2 (����� 2))
 //         ��� ���������������� ����������� ���������� HMAP � ���� ��������
 //         �����������, ��� ������� HMAP � ����� �������� erase = -2 ��� hdc = 0
 // frame  - ���������� ��������� ����� � ������� ��������� ��������� � ������
 // (��. mapSetDocProjection)
 // width  - ������ ����������� � ��������
 // height - ������ ����������� � ��������
 // alpha - ���� ������������� ����� ������ 0 - �� ������������ 1 - ������������
 // filename  - ������ ��� ������������ ����� ������� png
 // viewselect - ������� ������ ������������ ��������, ���� ����� 0, �� �����������
 //           ������� ����������� ������\��������� (����������)
 // hPaint - ������������� ��������� ����������� ��� �������������� ������ ������� �����������
 // ������ ������� ����� �������� ������� ������� ����������� ��������� (���� hPaint ����� 0),
 // ��� ���������� �������� �������� ����� ��������� ������� mapGetRealShowScale/mapSetRealShowScale
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintByFramePro(HMAP hMap,HDC hDC,          // 26/10/15
                                            long int erase, DFRAME * frame,
                                            long int width, long int height, long int alpha, 
                                            HSELECT viewselect, HPAINT hPaint);

_MAPIMP long int _MAPAPI mapPaintByFrame(HMAP hMap, HDC hDC,
                                         long int erase, DFRAME *frame,
                                         long int width, long int height);

_MAPIMP long int _MAPAPI mapPaintByFrameEx(HMAP hMap,HDC hDC,
                                           long int erase, DFRAME *frame,
                                           long int width, long int height, long int alpha);

_MAPIMP long int _MAPAPI mapPaintByFrameSelectEx(HMAP hMap,HDC hDC,
                                           long int erase, DFRAME *frame,
                                           long int width, long int height, long int alpha, 
                                           HSELECT viewselect);

_MAPIMP long int _MAPAPI mapPaintByFrameToFile(HMAP hMap,  const char *filename,
                                               long int erase, DFRAME * frame,
                                               long int width, long int height);
_MAPIMP long int _MAPAPI mapPaintByFrameToFileUn(HMAP hMap, const WCHAR *filename,
                                                 long int erase, DFRAME *frame,
                                                 long int width, long int height);

 // ���������� �������� ����� �� �������� ����������
 // � ������� �������� � ������� ��������
 // hmap  - ������������� �������� ������
 // hdc   - ������������� ��������� ���������� ������,
 // erase - ������� �������� ���� ����� �������,
 //        (0 - ��� �� �������, !=0 - �������� �������� ������ ����,
 //        ��� ��������� ������� ������ (VT_SCREEN) ������ �������
 //        ������ ����, ����� �������� -2 (����� 2))
 // rect - ���������� ��������� ����� (Draw) � ����������� (Picture)
 // ��������� �������� � �������� ������������� ��� Windows95 � NT,
 // �� ������� ����� ������� ���������
 //              ::SetViewportOrgEx(hDC, dx , dy, 0),
 // ��� dx,dy - ��������� ������������� ��������� � ���������
 // ������� !
 // ������ ��������, �������� �� ���� �����, �� �����
 // ������� �������� ������! ����� - ��. PaintToDib,PaintToImage...
 // alpha - ���� ������������� ����� ������ 0 - �� ������������ 1 - ������������
 // filename  - ������ ��� ������������ ����� ������� png
 // alpha - ���� ������������� ����� ������ 0 - �� ������������ 1 - ������������
 // ���� image != 0 � object != 0 ������������� ��������� ������
 // mapPaintMapObject95Ex  (���������� ������������ ������ � �������� ���������
 // � �������� ������ ������������)
 // image - �������� ���� ������� (��. MAPGDI.H),
 // object - ������������� �������

_MAPIMP long int _MAPAPI mapPaint95(HMAP hmap, HDC hdc, long int erase, RECT *rect);

_MAPIMP long int _MAPAPI mapPaint95Ex(HMAP hmap, HDC hdc, long int erase,
                                      RECT *rect, long int alpha);

_MAPIMP long int _MAPAPI mapPaint95ToFile(HMAP hMap, const char *filename,
                                          long int erase, RECT *rect, long int alpha,
                                          PAINTPARM *image, HOBJ object);

_MAPIMP long int _MAPAPI mapPaint95ToFileUn(HMAP hMap, const WCHAR *filename,
                                            long int erase, RECT *rect, long int alpha,
                                            PAINTPARM *image, HOBJ object);

 // ���������� �������� ����� �� �������� ����������
 // � ������� �������� � ������� �������� �
 // �������� �� ����� �������, �������������� �������� �������
 // hMap   - ������������� �������� ������
 // hdc    - �������� ����������
 // erase  - ������� �������� ���� ����� �������,
 //          (0 - ��� �� �������, !=0 - �������� �������� ������ ����,
 //          ��� ��������� ������� ������ (VT_SCREEN) ������ �������
 //          ������ ����, ����� �������� -2 (����� 2))
 // rect   - ���������� ��������� ����� (Draw) � ����������� (Picture)
 // select - ������� ������ ��������, ���� ����� 0, �� �����������
 //          ������� ����������� ������\��������� (��. mapTotalPaintSelect95).
 // color  - ����, ������� ����� ���������� ������� �� �����
 // ��������� �������� � �������� ������������� ��� Windows95 � NT,
 // �� ������� ����� ������� ���������
 //              ::SetViewportOrgEx(hDC, dx , dy, 0),
 // ��� dx,dy - ��������� ������������� ��������� � ��������� ������� !
 // ������ ��������, �������� �� ���� �����, �� �����
 // ������� �������� ������!
 // alpha - ���� ������������� ����� ������ 0 - �� ������������ 1 - ������������
 // filename  - ������ ��� ������������ ����� ������� png
 // alpha - ���� ������������� ����� ������ 0 - �� ������������ 1 - ������������
 // ���� image != 0 � object != 0 ������������� ��������� ������
 // mapPaintMapObject95Ex  (���������� ������������ ������ � �������� ���������
 // � �������� ������ ������������)
 // image - �������� ���� ������� (��. MAPGDI.H),
 // object - ������������� �������

_MAPIMP void _MAPAPI mapPaint95AndSelect(HMAP hMap, HDC hDC, long int erase,
                                         RECT *rect, HSELECT select, COLORREF color);

_MAPIMP void _MAPAPI mapPaint95AndSelectEx(HMAP hMap, HDC hDC, long int erase,
                                           RECT *rect, HSELECT select,
                                           COLORREF color, long int alpha);

_MAPIMP long int _MAPAPI mapPaint95AndSelectToFile(HMAP hMap, const char *filename,
                                                   long int erase, RECT *rect,
                                                   HSELECT select, COLORREF color,
                                                   long int alpha, PAINTPARM *image,
                                                   HOBJ object);

_MAPIMP long int _MAPAPI mapPaint95AndSelectToFileUn(HMAP hMap, const WCHAR *filename,
                                                     long int erase, RECT *rect,
                                                     HSELECT select, COLORREF color, long int alpha,
                                                     PAINTPARM *image, HOBJ object);

 // ���������� ������� ����� ��� ��������� ���������� �� �����
 // �������� (��� ������ mapPaint95AndSelect � �.�.)
 // thick - ������� ����� � mkm (�� �������� - PIX2MKM(pixel))
 // ���������� ������������� ����� ��������

_MAPIMP long int _MAPAPI mapSetSelectLineThick(HMAP hmap, long int thick);

 // ���������� ��������� ������ ����� � �������� ���������
 // � �������� ������ �����
 // ����� �������������� ��� ������ �������� ��������
 // hmap - ������������� �������� ������
 // hdc   - ������������� ��������� ���������� ������,
 // rect  - ���������� ��������� ����� (Draw)
 // info - ������������� ������� ����� � ������
 // ��� ������ � ���������� ���������� ����
 // ������ ��������, �������� �� ���� �����, �� �����
 // ������� �������� ������! ����� - ��. PaintToDib,PaintToImage...

_MAPIMP long int _MAPAPI mapPaintObject(HMAP hmap, HDC hdc, RECT *rect, HOBJ info);

 // ���������� ��������� ������ ����� � �������� ���������
 // � �������� ������ �����
 // ����� �������������� ��� ������ �������� ��������
 // hmap - ������������� �������� ������
 // hdc   - ������������� ��������� ���������� ������,
 // rect  - ���������� ��������� ����� (Draw)
 // info - ������������� ������� ����� � ������
 // erase -  ������� �������� ���� ����� �������,
 // (0 - ��� �� �������, !=0 - �������� �������� ������ ����),
 // dontclip - ������� ������ ������� �������� �� ����� ��� �����������
 // (1 - �� ��������, 0 - ��������� �������)
 // ��� ������ � ���������� ���������� ����
 // ������ ��������, �������� �� ���� �����, �� �����
 // ������� �������� ������! ����� - ��. PaintToDib,PaintToImage...

_MAPIMP long int _MAPAPI mapPaintObjectEx(HMAP hmap, HDC hdc, RECT *rect,
                                          HOBJ info, long int erase,
                                          long int dontclip);

 // ���������� ��������� ������ ����� � �������� ���������
 // � �������� ������ �����
 // ����� �������������� ��� ������ �������� ��������
 // hmap - ������������� �������� ������
 // hdc   - ������������� ��������� ���������� ������,
 // rect  - ���������� ��������� ����� (Draw)
 // info - ������������� ������� ����� � ������
 // ��������� �������� � �������� ������������� ��� Windows95 � NT,
 // ��� ������ � ���������� ���������� ����
 // ������ ��������, �������� �� ���� �����, �� �����
 // ������� �������� ������! ����� - ��. PaintToDib,PaintToImage...
 // alpha - ���� ������������� ����� ������ 0 - �� ������������ 1 - ������������

 _MAPIMP long int _MAPAPI mapPaintObject95(HMAP hmap, HDC hdc, RECT *rect,
                                          HOBJ info);

 _MAPIMP long int _MAPAPI mapPaintObject95Ex(HMAP hmap, HDC hdc, RECT *rect,
                                             HOBJ info, long int alpha);

 // ���������� ������������ ������ � �������� ��������� ���� (�����)
 // � �������� ������ ������������
 // hmap - ������������� �������� ������
 // hdc   - ������������� ��������� ���������� ������,
 // rect  - ���������� ��������� ����� (Draw)
 // image - �������� ���� ������� (��. MAPGDI.H), ���� ������
 // ������ ���������� ����� �������� ������ - �������� ���������
 // ����� ���������� � ����
 // info - ������������� ������� ����� � ������
 // ��� ������ � ���������� ���������� ����
 // ������ ��������, �������� �� ���� �����, �� �����
 // ������� �������� ������! ����� - ��. PaintToDib,PaintToImage...
 // filename  - ������ ��� ������������ ����� ������� png
 // alpha - ���� ������������� ����� ������ 0 - �� ������������ 1 - ������������

_MAPIMP long int _MAPAPI mapPaintMapObject95(HMAP hmap, HDC hdc, RECT *rect,
                                             PAINTPARM *image, HOBJ info);

_MAPIMP long int _MAPAPI mapPaintMapObject95Ex(HMAP hMap, HDC hdc, RECT *rect,
                                               PAINTPARM *image, HOBJ object,
                                               long int alpha);

_MAPIMP long int _MAPAPI mapPaintMapObject95ToFile(HMAP hMap, const char *filename,
                                                   RECT *rect, PAINTPARM *image,
                                                   HOBJ object, long int alpha);

_MAPIMP long int _MAPAPI mapPaintMapObject95ToFileUn(HMAP hMap, const WCHAR *filename,
                                                     RECT *rect, PAINTPARM *image,
                                                     HOBJ object, long int alpha);

 // ���������� ������������ ������ � �������� ���������
 // � �������� ������ ������������
 // hmap - ������������� �������� ������
 // hdc   - ������������� ��������� ���������� ������,
 // rect - ���������� ��������� ����� (Draw) � ����������� (Picture)
 // image - �������� ���� ������� (��. MAPGDI.H), ���� ������
 // ������ ���������� ����� �������� ������ - �������� ���������
 // ����� ���������� � ����,
 // info - ������������� ������� ����� � ������
 // offset - �������� ��������� ������� (� ������������ � place)
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintOffsetMapObject95(HMAP hmap, HDC hdc, RECT *rect,
                                                   PAINTPARM *image, HOBJ info,
                                                   DOUBLEPOINT *offset,
                                                   long int place = PP_MAP);


 // ���������� ������� ���� ������� �� ������ ������      
 // � �������������� �������� (incode)
 // hmap - ������������� �������� �����
 // hrsc - ������������� �������������� �������� �����
 // hdc  - ������������� ��������� ���������� ������,
 // rect - ���������� ���������� ������� ���� ������ (������ ����)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintExampleRscObject(HMAP hmap, HRSC hrsc,
                                                  HDC hdc, RECT *rect,
                                                  long int incode);

// ���������� ������� ���� �������
// ��� ������ ���������� ����
_MAPIMP long int _MAPAPI mapPaintExample(HMAP hMap, PAINTEXAMPLE *parm);

#ifdef WIN32API
 // ������� ����������� ����� � DIB
 // ������ ������� ����������� ������ ��� ��������� Windows !
 // ��������� �������� �����, �������� ���������� rect.
 // ���������� �������,������������� �� BITMAINFOHEADER
 // ����������� �������� � ������� �������� � ������� ��������
 // ������ ����� 1,2,3 ��� 4 ����.
 // ���� ������� ��������� DIB ������ �������� ��������� -
 // ����������� �������� � �������� �������� DIB.
 //  hmap      - ������������� �������� ������
 //  dibinfo   - ��������� ������������ DIB � ������
 //  lpDibBits - ����� ������� ����� ������� �������.
 //  rect      - ���������� ��������� ����� (Draw)
 //              � ����������� (Picture).
 // ������ ������� DIB, ���������� ���������� dibinfo->biSizeImage,
 // ������ ��������� ��, ��� ������ ������ DIB ������ ����
 // ������ 4 ������ (32 �����):
 //  dibinfo->biSizeImage = dibinfo->biHeight *
 //    ((dibinfo->biWidth * dibinfo->biBitCount + 31) / 32) * 4;
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintToDib(HMAP hmap, BITMAPINFOHEADER *dibinfo,
                                       char *lpDibBits, RECT *rect);

#ifndef WINCE
 // ������� ����������� ����� � Image (������)
 // ������ ������� ����������� ������ ��� ��������� Windows !
 // ��������� �������� �����, �������� ���������� rect.
 // ����������� ������� � ���� palette.
 // ����������� �������� � ������� �������� � ������� ��������
 // ������� Image ������ 256 ������, ������ ����� 1 ���� !
 // ���� ������� ��������� Image ������ �������� ��������� -
 // ����������� �������� � �������� �������� Image.
 //  hmap          - ������������� �������� ������
 //  palette       - ����� ������� (256 RGBQUAD-������)
 //  lpImage       - ����� ������� ����� ������� �����������.
 //  width, height - ������ � ������ Image.
 //  rect          - ���������� ��������� ����� (Draw)
 //                  � ����������� (Picture).
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintToImage(HMAP hmap, RGBQUAD *palette,
                                         char *lpImage, long int width,
                                         long int height, RECT *rect);
#endif  // !WINCE
#endif  // WIN32API

 // ������� ����������� ������� � DIB
 //  hmap      - ������������� �������� ������
 //  lpDibBits - ����� ������� ����� ������ ����������� (32 ����)
 //  width     - ������ ����������� (������ 32),
 //  height    - ������ �����������,
 //  rect      - ���������� ��������� ����� (Draw)
 //              � ����������� (Picture).
 //  image     - �������� ���� ������� (��. MAPGDI.H), ���� ������
 //              ������ ���������� ����� �������� ������ - �������� ���������
 //              ����� ���������� � ����,
 //  info      - ������������� ������� ����� � ������
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintMapObjectToDib(HMAP hmap, char *lpImage,
                                                int width, int heigth, RECT *rect,
                                                PAINTPARM *image, HOBJ object);

 // ���������� �������� �����, �������������� �� �������� ������ � ������
 // � ������� ������� ��������
 // hmap  - ������������� �������� ������
 // imagedesc - �������� ��������� ������ �����������
 // erase - ������� �������� ���� ����� �������,
 // (0 - ��� �� �������, !=0 - �������� �������� ������ ����,
 //  ��� ��������� ������� ������ (VT_SCREEN) ������ �������
 //  ������ ����, ����� �������� -2 (����� 2))
 // frame  - ���������� ��������� ����� � ������� ��������� ��������� � ������
 // (��. mapSetDocProjection)
 // width  - ������ ����������� � ��������
 // height - ������ ����������� � ��������
 // �������� ��������� XIMAGEDESC � maptype.h
 // alpha - ���� ������������� ����� ������ 0 - �� ������������ 1 - ������������
 // viewselect - ������� ������ ��������, ���� ����� 0, �� �����������
 // ������� ����������� ������\���������
 // hPaint - ������������� ��������� ����������� ��� �������������� ������ ������� �����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintByFrameToXImagePro(HMAP hMap, XIMAGEDESC * imagedesc,  // 26/10/15
                                                    long int erase,
                                                    DFRAME *frame, long int width,
                                                    long int height, long int alpha, 
                                                    HSELECT viewselect, HPAINT hPaint);

_MAPIMP long int _MAPAPI mapPaintByFrameToXImage(HMAP hMap, XIMAGEDESC * imagedesc,
                                                 DFRAME *frame, long int width,
                                                 long int height, long int alpha);

_MAPIMP long int _MAPAPI mapPaintByFrameSelectToXImage(HMAP hMap, XIMAGEDESC * imagedesc,
                                                       DFRAME *frame, long int width,
                                                       long int height, long int alpha, HSELECT viewselect);


 // ������� ����������� ����� � XImage (������)
 // �������� ��������� XIMAGEDESC � maptype.h
 // hmap - ������������� �������� ������
 // x,y - ���������� ������ �������� ���� ������
 // ������� ������� XImage ��� ���������� �����������
 // rect - ��������� �������� �����
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintToXImage(HMAP hmap, XIMAGEDESC *imagedesc,
                                           long int x, long int y, RECT *rect);

  // ������� ����������� ����� � XImage (������) � ��������
  // �� ����� ���������� �������
  // �������� ��������� XIMAGEDESC � maptype.h
  // x,y - ���������� ������ �������� ���� ������
  // ������� ������� XImage ��� ���������� �����������
  // rect - ��������� �������� �����
  // select - ������� ������ ��������, ���� ����� 0, �� �����������
  //          ������� ����������� ������\��������� (��. mapTotalPaintSelect95).
  // color  - ����, ������� ����� ���������� ������� �� �����
  // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintAndSelectToXImage(HMAP hMap, XIMAGEDESC *imagedesc,
                                                    long int x, long int y, RECT *rect,
                                                    HSELECT select, COLORREF color);

  // ������� ����������� ����� � ������� � XImage (������)
  // �������� ��������� XIMAGEDESC � maptype.h
  // x,y - ���������� ������ �������� ���� ������
  // ������� ������� XImage ��� ���������� �����������
  // rect - ��������� �������� �����
  // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintMapAndObjectToXImage(HMAP hMap, HOBJ hObj,
                                                       XIMAGEDESC *imagedesc,
                                                       long int x, long int y,
                                                       RECT *rect);

  // ������� ����������� ����� � XImage (������)
  // �������� ��������� XIMAGEDESC � maptype.h
  // x,y - ���������� ������ �������� ���� ������
  // ������� ������� XImage ��� ���������� �����������
  // rect - �������� ��� ������ �����������
  // func - ������� ����������� �������
  // parm - ��������� �����������
  // data - ������� ��� �����������
  // colors - ���������� ������
  // palette - �������
  // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintExampleObjectByFuncDataToXImage(HMAP hMap, XIMAGEDESC *imagedesc,
                                                                 long int x, long int y,
                                                                 RECT *rect, long int func,
                                                                 const char *parm, POLYDATAEX* data,
                                                                 long int colors, COLORREF *palette);

  // ������� ����������� ����� � XImage (������)
  // ������ ������� ����������� ��� XWindow !
  // �������� ��������� XIMAGEDESC � maptype.h
  // rect - �������� ��� ������ �����������
  // func - ������� ����������� �������
  // parm - ��������� �����������
  // colors - ���������� ������
  // palette - �������
  // text - ����������� �����
  // local - �����������
  // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintExampleObjectByFuncToXImage(HMAP hMap, XIMAGEDESC *imagedesc,
                                                             RECT *rect, long int func, const char *parm,
                                                             long int colors, COLORREF *palette,
                                                             const char *text, long int local);

_MAPIMP long int _MAPAPI mapPaintExampleObjectByFuncToXImageUn(HMAP hMap, XIMAGEDESC *imagedesc,
                                                               RECT *rect, long int func, const char *parm,
                                                               long int colors, COLORREF *palette,
                                                               const WCHAR *text, long int local);


#ifdef WIN32API
 // ������� ����������� ����� � ��������
 // ������ ������� ����������� ������ ��� ��������� Windows !
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintToEmf(HMAP hMap, const char *name,
                                       METAFILEBUILDPARM *parm);
_MAPIMP long int _MAPAPI mapPaintToEmfUn(HMAP hMap, const WCHAR *name,
                                         METAFILEBUILDPARM *parm);
_MAPIMP long int _MAPAPI mapPaintToEmfEx(HMAP hMap, const char *name,
                                         METAFILEBUILDPARMEX *parm);
_MAPIMP long int _MAPAPI mapPaintToEmfExUn(HMAP hMap, const WCHAR *name,
                                           METAFILEBUILDPARMEX *parm);

#endif  // WIN32API

 // ���������� ������������ ������ � �������� ���������
 // � �������� ������ ������������
 // hmap - ������������� �������� ������
 // hdc  - ������������� ��������� ���������� ������,
 // rect - ���������� ��������� ����� (Draw)
 // � ����������� (Picture).
 // image - �������� ���� ������� (��. MAPGDI.H),
 // data  - ���������� �������.
 // ���������� ������� ������ � ������������ � ���������� place
 // � ������������� ������ 32000�32000 �������� ������
 // ��� Windows NT (Windows 95 ����� 16-������� �������)
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintUserObject(HMAP hmap, HDC hdc, RECT *rect,
                                            PAINTPARM *image, PLACEDATA *data,
                                            long int place/* = PP_MAP*/);

 // ���������� ������������ ������ � �������� ���������
 // hmap - ������������� �������� ������
 // hdc  - ������������� ��������� ���������� ������,
 // rect - ���������� ��������� ����� (Draw)
 // � ����������� (Picture).
 // image - �������� ���� ������� (��. MAPGDI.H),
 // data  - ���������� �������.
 // offset - �������� ��������� ������� (� ������������ � place)
 // ���������� ������� ������ � ������������ � ���������� place
 // ��������� �������� � �������� ������������� ��� Windows95 � NT,
 // ��� ������ � ���������� ���������� ����

_MAPIMP  long int _MAPAPI mapPaintOffsetUserObject95(HMAP hmap, HDC hdc,
                                                     RECT *rect, PAINTPARM *image,
                                                     PLACEDATA *data,
                                                     DOUBLEPOINT *offset,
                                                     long int place);

 // ���������� ������������ ������ � �������� ���������
 // hmap - ������������� �������� ������
 // hdc  - ������������� ��������� ���������� ������,
 // rect - ���������� ��������� ����� (Draw)
 // � ����������� (Picture),
 // image - �������� ���� ������� (��. MAPGDI.H),
 // data  - ���������� �������.
 // ���������� ������� ������ � ������������ � ���������� place
 // ��������� �������� � �������� ������������� ��� Windows95 � NT,
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapPaintUserObject95(HMAP hmap, HDC hdc,
                                              RECT *rect, PAINTPARM *image,
                                              PLACEDATA *data, long int place);

 // ���������� ������� ���� ������� �� ������ ������
 // � �������������� �������� (incode)
 // hmap - ������������� �������� ������
 // hdc  - ������������� ��������� ���������� ������,
 // rect - ���������� ��������� ����� (Draw)
 // � ����������� (Picture),
 // ������������ � �������� ������ ���� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintExampleObject(HMAP hmap, HDC hdc,
                                               RECT *rect, long int incode);

 // ���������� ������� ���� ������� c ������ ���� ������������ ��
 // ������ ������ � �������������� �������� (incode)
 // ������������ � �������� ������ ���� �������
 // hmap - ������������� �������� ������
 // hdc  - ������������� ��������� ���������� ������,
 // rect - ���������� ��������� ����� (Draw)
 // � ����������� (Picture),
 // visualtype - ��� ������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintExampleObjectEx(HMAP hmap, HDC hdc, RECT *rect,
                                                 long int incode, long int visualtype);

 // ���������� ������� ���� ������� c ������ ���� ������������ ��      // 23/02/14
 // ������ ������ � �������������� �������� (incode)
 // ������������ � �������� ������ ���� �������
 // hmap - ������������� �������� ������
 // hdc  - ������������� ��������� ���������� ������,
 // rect - ���������� ��������� ����� (Draw)
 // � ����������� (Picture),
 // visualtype - ��� ������������ (VT_SCREEN, VT_PRINT)
 // text - ����� ��� ����������� ����� ���� �������
 // factor - ������� ��������� ������� ����� ��� ����������� ������� ������
 //          � ��������� ������� (50 - ����� � 2 ����, 150 - ��������� � 1,5 ����)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintExampleObjectUn(HMAP hMap, HDC hdc,RECT* rect,
                                                 long int incode, long int visualtype,
                                                 const WCHAR * text, long int factor);

 // ���������� ������� ���� ������� �� ������ �������
 // hmap       - ������������� �������� ������
 // hdc        - �������� ����������
 // rect       - ������� �����������
 // func       - ����� �������
 // parm       - ��������� �� ��������� �������
 // colors     - ����� ������ �������
 // palette    - ��������� �� �������
 // visualtype - ��� ������������
 // text       - ����� ������ � ��������� WINDOWS, ����� ������� IMG_TEXT
 //              (��������� ������ � ���������� ��������� IMGTEXT)
 // ��������� colors, palette, visualtype, text - ����� ���� �������� :
 //  colors,palette - ���� � ���������� ������� ������� ������� �� ������������;
 //  visualtype     - ���� ����������� ����������� � ������� ������ ������������;
 //  text           - ��� ����������� ������������ ������ ("AaBbCc").
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintExampleObjectFunc(HMAP hmap, HDC hdc, RECT rect,
                                                   long int func, char* parm,
                                                   long int colors, COLORREF* palette,
                                                   long int visualtype, const char* text);
_MAPIMP long int _MAPAPI mapPaintExampleObjectFuncUn(HMAP hMap, HDC hdc, RECT rect,
                                                     long int func, char* parm,
                                                     long int colors, COLORREF* palette,
                                                     long int visualtype, const WCHAR *text);

 // ���������� ������� ���� ������� �� ������ �������     // 09/02/16
 //  hdc        - �������� ����������
 //  rect       - ������� �����������
 //  func       - ����� �������
 //  local      - ����������� ��� ������� ���� �������
 //  parm       - ��������� �� ��������� �������
 //  colors     - ����� ������ �������
 //  palette    - ��������� �� �������
 //  visualtype - ��� ������������
 //  erase      - 0 - �� �������, 1 - ������� �����������
 //  factor - ����������� ���������� ������� ( �� ��������� 0.0)
 //  text       - ����� ������ � ��������� WINDOWS, ����� ������� IMG_TEXT
 //               (��������� ������ � ���������� ��������� IMGTEXT)
 // ��������� colors, palette, visualtype, text - ����� ���� �������� :
 //  colors,palette - ���� � ���������� ������� ������� ������� �� ������������;
 //  visualtype     - ���� ����������� ����������� � ������� ������ ������������;
 //  text           - ��� ����������� ������������ ������ ("AaBbCc").
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintExampleFunc(HMAP hMap, HDC hdc, RECT rect,
                                      long int func, const char * parm,
                                      long int colors, COLORREF* palette,
                                      long int visualtype, const WCHAR * text,
                                      long int local,HRSC hRsc, long int erase);

 // ���������� ������� ���� ������� �� �������� �������
 // � �������� ������ (� �������������� ������� - 100%)
 // hmap       - ������������� �������� ������,
 // hdc        - �������� ����������
 // rect       - ������� �����������
 // func       - ����� �������
 // parm       - ��������� �� ��������� �������
 // data       - ������� ����������� � ������ ���������� ������
 // colors     - ����� ������ �������
 // palette    - ��������� �� �������
 // visualtype - ��� ������������
 // text - ����� ������ � ��������� WINDOWS
 //        (���� data != 0, �� text ������������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintExampleObjectRealByFuncData(HMAP hmap, HDC hdc, RECT* rect,
                                                             long int func, const char* parm, POLYDATA* data,
                                                             long int colors, COLORREF* palette,
                                                             long int visualtype, const char* text);

_MAPIMP long int _MAPAPI mapPaintExampleObjectRealByFuncDataUn(HMAP hMap, HDC hdc, RECT* rect,
                                                               long int func, const char* parm, POLYDATA* data,
                                                               long int colors, COLORREF* palette,
                                                               long int visualtype, const WCHAR *text);

 // �������� �� ����� �������, ��������������� �������� ��������
 // hmap   - ������������� �������� ������
 // hdc    - �������� ����������
 // rect   - ������� �����������
 // select - ������� ������ ��������
 // color  - ����, ������� ����� ���������� ������� �� �����
 // ������������ ������ ��������, ����� ���������� ������ (�������� �����)

_MAPIMP void _MAPAPI mapPaintSelect95(HMAP hmap, HDC hdc, RECT *rect,
                                      HSELECT select, COLORREF color);

 // ����������/��������� ������ ��������� ��������� � ��������
 // �������� �� �����
 // type - ������ ��������� (STF_CONTOUR - ������ �������,
 // STF_OBJECT - ���� ������)
 // ���������� ��������, ������� ���� ����� �����������

_MAPIMP long int _MAPAPI mapSetSelectType(long int type);
_MAPIMP long int _MAPAPI mapGetSelectType();

#ifndef LINUXAPI
 // ���������� �������� ����� �� �������� ���������� � ������ ����������
 // � ������� �������� � ������� ��������
 // hmap   - ������������� �������� ������
 // rect - ���������� ��������� ����� (Draw) � ����������� (Picture)
 // parm - ��������� ������, ��������� �� PRINTPARM (��. prnapi.h)

_MAPIMP void _MAPAPI mapPrint(HMAP hmap, HDC hDC, RECT *rect, const char *parm);
#endif

 // ���������� ��������� ����� DIB � ����
 // millisec - �������� ������ ������������� ����������� � �������� ������
 //            � ������������� (��� ������� �������� ����������� ��������� ���� ��� �� ����������)
 // ���������� ���������� ��������

_MAPIMP long int _MAPAPI mapSetPaintStepEx(HMAP hmap, long int millisec);

 // ��������� �������� ���������� ������ DIB � ����
 // ���������� �������� ������ ������������� ����������� � �������� ������
 // � ������������� (��� ������� �������� ����������� ��������� ���� ��� �� ����������)
 // ���� hmap ����� ����, �� ���������� ����

_MAPIMP long int _MAPAPI mapGetPaintStepEx(HMAP hmap);

 // ���������� ����� ������������� ����������� ��������
 // ��� �������� ���������� �������� ������� ��� ������
 // flag - ��������� �������� ������������� ����� ������������� ������
 //        (��� ���� ����� ����������� ��������� ������� �������������
 //         �������� � 2 ����)
 // ��� ������ ��������� ���������� ����� ������������� �����������
 // ���������� ���������� ��������

_MAPIMP long int _MAPAPI mapSetTextQuality(long int flag);

 // ��������� ����� ������������� ����������� ��������
 // ��� �������� ���������� �������� ������� ��� ������

_MAPIMP long int _MAPAPI mapGetTextQuality();

  /*********************************************************
  *                                                        *
  *      ������� ����������� � ������ ����������� �����    *
  *   ����� ������������� ����, � ������� ��������� ������ *
  *                ����������� ����� � ����                *
  *                                                        *
  *********************************************************/

 // �������� �� ����� �������, �������������� �������� �������
 // hmap   - ������������� �������� ������
 // hwnd   - ������������� ���� ������
 // point - ���������� �������� ������ ���� ���� �� �����
 // � �������������� ��������� place ������� ���������
 // select - ������� ������ ��������,
 // color  - ����, ������� ����� ���������� ������� �� �����

_MAPIMP void _MAPAPI mapViewSelect(HMAP hmap, HWND hwnd, DOUBLEPOINT *point,
                                   HSELECT select, COLORREF color,
                                   long int place);

 // ����������/��������� ��������� �������� �� ����� � ���������     // 29/07/14
 // hmap - ������������� �������� ������
 // flag - ������� ����������� ���������� �������� � ���������,
 // ��������� ���������� ���������� ������� ���������, �����
 // ���������� ������ ��������
 // ���������� ������������� ��������

_MAPIMP long int _MAPAPI mapSetLiteSelect(HMAP hmap, long int flag);
_MAPIMP long int _MAPAPI mapGetLiteSelect(HMAP hmap);

 // ���������� �������� ����� � ��������� ������� ����
 // � ������� �������� � ������� ��������
 // erase - ������� �������� ���� ����� �������,
 // (0 - ��� �� �������, !=0 - �������� �������� ������ ����),
 // point - ���������� �������� ������ ���� ���������
 // � �������������� ��������� place ������� ���������

_MAPIMP void _MAPAPI mapView(HMAP hmap, HWND hwnd, long int erase,
                             DOUBLEPOINT *point, long int place);

#ifdef WIN32API
 // ���������� �������� ����� � ��������� ������� ����
 // � ������� �������� � ������� ��������
 // hMap   - ������������� �������� ������
 // hwnd  - ������������� ����,
 // erase - ������� �������� ���� ����� �������,
 // (0 - ��� �� �������, !=0 - �������� �������� ������ ����),
 // rect - ���������� ��������� ����� (Draw)
 // � ����������� (Picture),
 // point - �������� ��������� � ������������ ����

_MAPIMP void _MAPAPI mapViewEx(HMAP hmap, HWND hwnd, long int erase,
                               RECT *rect, POINT *point);
#endif  // WIN32API

 // ���������� ������������ ������ � ��������
 // ��������� ������� ����
 // hmap   - ������������� �������� ������
 // hwnd  - ������������� ����,
 // point - ���������� �������� ������ ���� ���� �� �����
 // � �������������� ��������� place ������� ���������
 // info - ������������� ������� ����� � ������
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapViewObject(HMAP hmap, HWND hwnd,
                                       DOUBLEPOINT *point,
                                       HOBJ info, long int place);

 // ���������� ������������ ������ ����� � �������� ��������� ���� (�����)
 // � �������� ������ ������������
 // hmap   - ������������� �������� ������
 // hwnd  - ������������� ����,
 // point - ���������� �������� ������ ���� ���� �� �����
 // � �������������� ��������� place ������� ���������
 // image - �������� ���� ������� (��. MAPGDI.H), ���� ������
 // ������ ���������� ����� �������� ������ - �������� ���������
 // ����� ���������� � ����,
 // info - ������������� ������� ����� � ������
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapViewMapObject(HMAP hmap, HWND hwnd,
                                          DOUBLEPOINT *point,
                                          PAINTPARM *image,
                                          HOBJ info, long int place);

 // ���������� ������������ ������ ����� � �������� ��������� ���� (�����)
 // � �������� ������ ������������
 // hmap   - ������������� �������� ������
 // image - �������� ���� ������� (��. MAPGDI.H), ���� ������
 // ������ ���������� ����� �������� ������ - �������� ���������
 // ����� ���������� � ����,
 // info - ������������� ������� ����� � ������
 // offset - �������� ��������� ������� (� ������������ � place)
 // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapViewOffsetMapObject(HMAP hmap, HWND hwnd,
                                                DOUBLEPOINT *point,
                                                PAINTPARM *image,
                                                HOBJ info, DOUBLEPOINT *offset,
                                                long int place);

  // ���������� ������������ ������ � �������� ��������� ���� (�����)
  // hmap   - ������������� �������� ������
  // hwnd  - ������������� ����,
  // point - ���������� �������� ������ ���� ���� �� �����
  // � �������������� ��������� place ������� ���������
  // image - �������� ���� ������� (��. MAPGDI.H),
  // data  - ���������� �������.
  // offset - �������� ��������� ������� (� ������������ � place)
  // ���������� ������� ������ � ������������ � ���������� place

_MAPIMP long int _MAPAPI mapViewOffsetUserObject(HMAP hmap, HWND hwnd,
                                                 DOUBLEPOINT *point,
                                                 PAINTPARM *image,
                                                 PLACEDATA *data,
                                                 DOUBLEPOINT *offset,
                                                 long int place);

 // ���������� ������������ ������ � �������� ��������� ���� (�����)
 // hmap   - ������������� �������� ������
 // hwnd  - ������������� ����,
 // point - ���������� �������� ������ ���� ���� �� �����
 // � �������������� ��������� place ������� ���������
 // image - �������� ���� ������� (��. MAPGDI.H),
 // data  - ���������� �������.
 // ���������� ������� ������ � ������������ � ���������� place

_MAPIMP long int _MAPAPI mapViewUserObject(HMAP hmap, HWND hwnd,
                                           DOUBLEPOINT *point,
                                           PAINTPARM *image,
                                           PLACEDATA *data,
                                           long int place);

 // ���������� ������ � ���� ����������� � �������� �����
 // hmap   - ������������� �������� ������
 // hwnd  - ������������� ����,
 // point - ���������� �������� ������ ���� ���� �� ����� � ��������
 // linethick - ������� ����� ������� � �������� (������������� 1 - 2)
 // size  - ������ ������� (������ 16 ��� 32 - � ����������� �� ������)
 // x,y   - ���������� ������ ������� (������������ place)

_MAPIMP void _MAPAPI mapViewMarkerEx(HMAP hMap, HWND hwnd, POINT *point,
                                     long int linethick, long int size,
                                     long int x, long int y);

 // ���������� ������ � ���� ����������� � �������� �����
 // hmap   - ������������� �������� ������
 // hwnd  - ������������� ����,
 // point - ���������� �������� ������ ���� ���� �� �����
 // � �������������� ��������� place ������� ���������
 // linethick - ������� ����� ������� � �������� (������������� 1 - 2)
 // x,y   - ���������� ������ ������� (������������ place)

_MAPIMP  void _MAPAPI mapViewMarker(HMAP hMap, HWND hwnd, DOUBLEPOINT *point,
                                    long int linethick, double x, double y,
                                    long int place);

 // ���������� ����� � ���� ��������� ���������
 // hmap   - ������������� �������� ������
 // hwnd  - ������������� ����,
 // point - ���������� �������� ������ ���� ���� �� �����
 // � �������������� ��������� place ������� ���������
 // image - �������� ���� ������� (��. MAPGDI.H),
 // first - ���������� ������ �����,
 // second - ���������� ������ �����.

_MAPIMP  void _MAPAPI mapViewUserLine(HMAP hMap, HWND hwnd, DOUBLEPOINT *point,
                                      PAINTPARM *image, DOUBLEPOINT *first,
                                      DOUBLEPOINT *second, long int place);

  /*********************************************************
  *                                                        *
  *        ������� ���������� ��������� �����������        *
  *                                                        *
  *********************************************************/

  // ���������� ����� �������, ������� ����� ������������
  // ���������� ��� ���������� ����������� ����� � ������
  // ��� � �������� �������� �����������
  // ������������� ����� ������������� ����� ������ ������� Paint,
  // � �� ��������� ��������� ����� - ���������
  // (������������� ������� �����).
  // ���������� ������� �� ������ ���� �������� Paint !
  // call - ����� ���������� ������� (��. maptype.h),
  // parm - ��������, ������� ����� ������� ���������� �������.
  // ����� ��������� parm ���������� ������� ���������� �������
  // ����������� ����� (0/1) ��� �� ���������� ���������� �� ������
  // ���� ���������� ������� ������ ��������� ��������, ��
  // ������� ����������� ����� ������� (��������, ��� �������
  // ������� ��������� ��������� �������� ������ ���� �
  // ���������� ������� Esc, ������� ���������� 1, �����������
  // �����������).

_MAPIMP void _MAPAPI mapSetBreakCallAndParmEx(HMAP hMap, BREAKCALLEX call,
                                              void *parm);

  // ���������� ����� �������, ������� ����� ����������
  // ����� ������������� ����������� ����� � �������
  // ������ ��� ����� ������� ����������� ����� �� �����.
  // ���������� ������� �� ������ ���� �������� Paint !
  // hmap   - ������������� �������� ������
  // call - ����� ���������� ������� (��. maptype.h),
  // parm - ��������, ������� ����� ������� ���������� �������.
  // � ���������� ������� ����� �������� "��� ������"
  // � ����������� ����������� ������� ������� ��� �������
  // ���� PaintUserObject.

_MAPIMP void _MAPAPI mapSetBeforePaintCallAndParm(HMAP hmap, BEFOREPAINT call,
                                                  void *parm);

  // ���������� ����� �������, ������� ����� ������������
  // ���������� ��� ���������� ����������� ����� � ������
  // ��� �� �����. 
  // ���������� �������. �������� ����� ����������� ������ �����
  // ��������� ���������� ����� ��������, ��������� ��������
  // mapSetPaintStep, ��� ������ ������ (������, �������).
  // ��������� �������� ����������� �����,
  // ������� ��������� ����������� (�������, ������� �����...)
  // � ��������� ����� ������� �����������. �������������
  // ����� ������������� ����� ������ ������� Paint,
  // � �� ��������� ��������� ����� - ���������
  // (������������� ������� �����).
  // ���������� ������� �� ������ ���� �������� Paint !
  // hmap   - ������������� �������� ������
  // call - ����� ���������� ������� (��. maptype.h),
  // parm - ��������, ������� ����� ������� ���������� �������.
  // ���� ���������� ������� ������ ��������� ��������, ��
  // ������� ����������� ����� ������� (��������, ��� �������
  // ������� ��������� ��������� �������� ������ ���� �
  // ���������� ������� Esc, ������� ���������� 1, �����������
  // �����������).

_MAPIMP void _MAPAPI mapSetBreakCallAndParm(HMAP hmap, BREAKCALL call,
                                            void *parm);

  /*********************************************************
  *                                                        *
  *     ������� ��������� ����������� ����������� �����    *
  *                     � ���������                        *
  *                                                        *
  *********************************************************/

 // ������� ��������� ����������� ����� � ���������
 //  hmap     - ������������� �������� ������
 //  angle    - ���� �������� ����� � ����� � �������� �
 //             ���-�������� ���� ����� (�� -Pi �� Pi)
 //  fixation - ���� ������� �������� �������� ����������� �����
 //             ������������ ����������� ��������� (�� 0 �� Pi/6).
 //             �� ��������� = Pi/18 (10 ��������)
 // ���� fixation ������������ ��� ����������� �������� ����������� 
 // ��� �������� �� ���������� ����� �� ������ (��� ����� �� ������), 
 // ����� ��� ���������������� ������ ������� �������� ������� 
 // �������� ���� �������� (angle). � ������, ���� �������� ����� 
 // ������� ����� �������� � ��������� ����� ������ fixation, 
 // �� ����� ���� �������� �� ���������������.
 // ���������� �������� �������������� ���� ��������.
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapSetupTurn(HMAP hmap, double angle, double fixation);

 // ������� �� ������� ?
 // hmap - ������������� �������� ������
 // ���������� (1 - �������, 0 - ���)

_MAPIMP long int _MAPAPI mapTurnIsActive(HMAP hmap);

 // ��������� ���� ��������
 // hmap - ������������� �������� ������
 // ���������� �������� �� -Pi �� Pi

_MAPIMP double _MAPAPI mapGetTurnAngle(HMAP hmap);

  /*********************************************************
  *                                                        *
  *    ������� ���������� ������������ ����������� �����   *
  *                                                        *
  *    ��� ��������� �������� ����������� �������������    *
  *       ���������� �������� ����������� � �������� !     *
  *                                                        *
  *********************************************************/

  // ���������� ������� ����������� (����������� ��������)
  //  ���������:
  //          hmap - ������������� �������� ������
  //          x, y - ���������� ��������������� "������ �����������"
  //                 (����� ����� ��������) � ���� � ������� ��������
  //         scale - �������� ������� �����������, ������� ������ ��������
  //  ����������:   0 - ������� �� ���������,  1 - ������� ���������
  //          x, y - ���������� ��������������� "������ �����������"
  //                 � ���� ������������ ���� ��������
  //                 � ����� �������� �����������

_MAPIMP long int _MAPAPI mapSetViewScale(HMAP hmap, long int *x,
                                         long int *y, float scale);

  // �������� ������� ����������� ������������ ��������
  //  ���������:
  //          hmap - ������������� �������� ������
  //          x, y - ���������� ��������������� "������ �����������"
  //                 (����� ����� ��������) � ���� � ������� ��������
  //        change - ����������� ��������� �������� �������� �����������
  //                 0 < change < 1 , ��� ������
  //                 1 < change < N , ��� ����������
  //  ����������:   0 - ������� �� ���������,  1 - ������� ���������
  //          x, y - ���������� ��������������� "������ �����������"
  //                 � ���� ������������ ���� ��������
  //                 � ����� �������� �����������

_MAPIMP long int _MAPAPI mapChangeViewScale(HMAP hmap, long int *x,
                                            long int *y, float change);

  // ��������� ����������� ������� ����������� �����
  // hmap - ������������� �������� ������
  // ���������� �������� ����������� ��������

_MAPIMP long int _MAPAPI mapGetShowScale(HMAP hmap);

  // ��������� ������ ������� ����������� �����
  // hmap - ������������� �������� ������
  // ���������� �������� ����������� ��������

_MAPIMP double _MAPAPI mapGetRealShowScale(HMAP hmap);

  // ���������� ������ ������� ����������� �����
  // ���������� �������� ����������� ��������

_MAPIMP double _MAPAPI mapSetRealShowScale(HMAP hMap, double scale);

  // ��������� ������� ����������� ��������������� �����
  // ��������: 5 - ��������� � 5 ��� ������������ �������� ��������,
  //         0.1 - ����� � 10 ���.

_MAPIMP double _MAPAPI mapGetDrawScale(HMAP hmap);

  // ��������� "�����������" �������, ��������� � ��������� (scale)

_MAPIMP long int _MAPAPI mapScaleToRoundScale(double scale);

  // ��������� "�����������" �������, ��������� � ��������� (scale)
  // � ������ ������� ����� (��� �������� ������ WMST ����� ����
  // ������ ����������� ��������)
  // hmap - ������������� �������� ������
  // ���������� ����� �������� ����������� ��������

_MAPIMP long int _MAPAPI mapScaleToRoundScaleEx(HMAP hmap, double scale);

  // ��������� "�����������" �������� �������, ��������� � ��������� (scale)
  // � ������ ������� ����� (��� �������� ������ WMTS ����� ����
  // ������ ����������� ��������)
  // hmap - ������������� �������� ������
  // ���������� ����� �������� (�������������) �������� ����������� ��������

_MAPIMP double _MAPAPI mapScaleToRoundScaleReal(HMAP hmap, double scale);   // 12/11/15

  // ��������� ���������� "�����������" ���������

_MAPIMP long int _MAPAPI mapScaleTableCount();

 // ��������� ������� ������� "�����������" ��������� �� �����������
 // ������ � �������(� 1)

_MAPIMP long int _MAPAPI mapScaleTableItem(long int number);

  // ���������� ������ ��������������� �������� ����� ��� �����������
  // method - ������ ���������������
  // (0 - ���������������� "� ������������� ����������",
  //  1 - ���������)
  // ���������� ����� ������������� ��������

_MAPIMP long int _MAPAPI mapSetScaleMethod(long int method);
_MAPIMP long int _MAPAPI mapGetScaleMethod();

  // ����������� ����� �������� ������ �����
  // hmap - ������������� �������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRegion(HMAP hMap);

  // ��������� ������ ������������ ��������
  // hmap - ������������� �������� ������
  // select - ������������� ��������� ������/�����������
  // � ������� ����� �������� ������� ������� �����������
  // ��. mapCreateMapSelectContext(...)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetViewSelect(HMAP hmap, HSELECT select);

  // ���������� ������ ������������ ��������
  // hmap - ������������� �������� ������
  // select - ������������� ���������������� ��������� ������/�����������

_MAPIMP void _MAPAPI mapSetViewSelect(HMAP hmap, HSELECT select);

  // ���������/���������� ���� ���� ������������ �����
  // hmap - ������������� �������� ������
  // color - ���� ����
  // ��� ��������� ����� ���� ���������� ������������ ���� �����
  // ��� ������ ���������� 0x0FFFFFF (�����)

_MAPIMP COLORREF _MAPAPI mapGetBackColor(HMAP hmap);

_MAPIMP COLORREF _MAPAPI mapSetBackColor(HMAP hmap, COLORREF color);

  // ���������/���������� ���� ���� ������������ �����
  // ��� ������ � ���������� ������ �� �����
  // ��� ��������� ����� ���� ���������� ������������ ���� �����
  // ��� ������ ���������� 0x0FFFFFF (�����)

_MAPIMP COLORREF _MAPAPI mapGetBackPrintColor(HMAP hmap);

_MAPIMP COLORREF _MAPAPI mapSetBackPrintColor(HMAP hmap, COLORREF color);

  // ���������/���������� ������ ����������� �����
  // hmap - ������������� �������� ������
  // ��� ��������� ������ ������� ����������� ������������
  // ���������� ��������
  // (��. Maptype.h : VT_SCREEN(1), VT_PRINT(3), VT_PRINTRST(6),...)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetViewType(HMAP hmap);
_MAPIMP long int _MAPAPI mapSetViewType(HMAP hmap, long int type);

  // ��������� ������� ����� (�� -16 �� +16)
  // hmap - ������������� �������� ������

_MAPIMP long int _MAPAPI mapGetBright(HMAP hmap);

  // ���������� ������� ����� (�� -16 �� +16)
  // hmap - ������������� �������� ������

_MAPIMP long int _MAPAPI mapSetBright(HMAP hmap, long int bright);

  // ��������� ������������� (�� -16 �� +16)
  // hmap - ������������� �������� ������

_MAPIMP long int _MAPAPI mapGetContrast(HMAP hmap);

  // ���������� ������������� (�� -16 �� +16)
  // hmap - ������������� �������� ������

_MAPIMP long int _MAPAPI mapSetContrast(HMAP hmap, long int contrast);

  // ��������� ������������� ������� �������� ��������� ���
  // ����������� ����������� (�� 0 �� 100)
  // hmap - ������������� �������� ������

_MAPIMP long int _MAPAPI mapGetIntensity(HMAP hmap);

  // ���������� ������������� ������� �������� ��������� ���
  // ����������� ����������� (�� 0 �� 100)
  // ���� mapGetTransparentSquare ���������� 0, �� �������� ������������� 
  // ������������� ������������ ������ (����� �������):
  //   0 - ������� ���, 50 - ����������������� �����, 100 - ���������� �����
  // ���� mapGetTransparentSquare ���������� 1, �� �������� �������������
  // ������������� ������� �������������� ������:
  //   0 - ������� ���, 50 - �������������� �������, 100 - ���������� �����
  // hmap - ������������� �������� ������

_MAPIMP long int _MAPAPI mapSetIntensity(HMAP hmap, long int intensity);

  // ��������� ���� ������������ ������� �������� ���������
  // hMap  - ������������� �������� �����
  // ���������� �������� �����

_MAPIMP long int _MAPAPI mapGetTransparentSquare(HMAP hMap);   // 21/06/16

  // ���������� ���� ������������ ������� �������� ���������.
  // ������� ������������ ��������������� �������� mapSetIntensity
  // hMap  - ������������� �������� �����
  // flag  - ������� ������������:
  //         0 - ������������ ��������� (������� �������� ������),
  //             ������������ ��� ������� ����������� ��� ������ �����;
  //             � ���������� ������� (VT_PRINT, VT_PRINTRST)
  //         1 - ������������ �������� (������� � ���� �������� ������),
  //             ������������ ��� ����������� ��� ������ ����� ������ �������
  //             � ���������� ��������� ������ (VT_PRINTRST)

_MAPIMP long int _MAPAPI mapSetTransparentSquare(HMAP hMap, long int flag);

  // ������ ��� ����������� �����
  // 1 - � ������, 0 - ��� �����

_MAPIMP long int _MAPAPI mapGetNodeView(HMAP hMap);

  // ���������� ����������� ����� �� �����
  // 0 - �� ����������, 1 - ����������

_MAPIMP void _MAPAPI mapSetNodeView(HMAP hMap, long int mode);


  /*********************************************************
  *                                                        *
  *          ������������ ������ ���� �����                *
  *                                                        *
  *********************************************************/

  // ������� ����� ����� � ������ ��� ���������� �������
  // ������������ �� ����� ��������
  // width  - ������ ���������� ����� ���� ����� � ������,
  // height - ������ ���������� ����� ���� ����� � ������.
  // ��������� ������ ����� ������, ������ ��������� ��� ������ ������
  // ������� ����������� ������� � ����� (Draw) -  ��� ������������
  // ���������� ������� ��� ����������� ����� � ��� ������������ ��������
  // ������ ������ =  (width * height * 4)
  // ����� ����� ���� ����������� ������� �� 256 ������� ������� ������������
  // ����� ����������� � ���� � �������� mapChangeImageSizeEx
  // ��� �������� ���������� ���������� ������������� ������ ������
  // ��� ������ ���������� ����

_MAPIMP HIMAGE _MAPAPI mapCreateImageEx(long int width, long int height);

  // �������� ������ ����
  // hwnd - ������������� ����, ��� ����������� �������� ���������� �������
  // ����� ����������� � ���� � �������� mapChangeImageSize
  // ��� ������ ���������� ����

_MAPIMP HIMAGE _MAPAPI mapCreateImage(HWND hwnd);

  // ������� ����� ����
  // himage - ������������� ������ ����

_MAPIMP void _MAPAPI mapCloseImage(HIMAGE image);

  // ��������� �������� ������ ����
  // himage - ������������� ������ ����
  // ��� ������ ���������� ����

_MAPIMP HDC _MAPAPI mapGetImageDC(HIMAGE image);

  // ��������� �������� ������ ���� ��� ����������� ��������
  // himage - ������������� ������ ����
  // ��� ������ ���������� ����

_MAPIMP HDC _MAPAPI mapGetImageObjectDC(HIMAGE image);

  // ���������� ���������� ������ ���� � �������� ��������
  // himage - ������������� ������ ����
  // hdc - �������� ������� ����������� (����),
  // rect - ���������� ������� ����������� � ������ � ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapViewImage(HIMAGE image, HDC hdc, RECT *rect);

  // ���������� ���������� ������ ���� � �������� ��������
  // himage - ������������� ������ ����
  // hwnd - ������������� ����, � ������� ��������� �����������,
  // rect - ���������� ������� ����������� � ������ � ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapViewImageEx(HIMAGE image, HWND hwnd, RECT *rect);

  // ���������� ���������� ������ ���� � �������� �������� �� ���������
  // himage - ������������� ������ ����
  // hwnd - ������������� ����, � ������� ��������� �����������,
  // rect - ���������� ������� ����������� � ������ � ���������
  // offset - �������� ����������� � ����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapViewImageExOffset(HIMAGE himage, HWND hwnd,
                                              RECT *rect, POINT *offset);

  // �������� ����������� ����� �� ��������������� ������
  // himage - ������������� ������ ����
  // offset - �������� ����������� � ����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapViewImageOffset(HIMAGE himage, POINT *offset);

  // �������� ������� ������ ����
  // himage - ������������� ������ ����
  // erase  - ������� ������� ����, ���� ����� 0 - ���������� �����������
  // width  - ����� ������ ������
  // height - ����� ������ ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapChangeImageSizeEx(HIMAGE image, long int erase,
                                              long int width, long int height);

  // �������� ������� ������ ����
  // himage - ������������� ������ ����
  // ����������� ��������� ������, ���� ����� ������ ����� mapCreateImage(HWND hwnd);
  // ���������� ������ �������� !
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapChangeImageSize(HIMAGE image);

  // ��������� ������ ����
  // himage - ������������� ������ ����
  // dx     - �������� �������� ���� �� ����������� (> 0 - ����� �������,
  //                                                 < 0 - ������ ������)
  // dy     - �������� �������� ���� �� ���������   (> 0 - ������ ����,
  //                                                 < 0 - ����� �����)
  // onlymap - ������� ���������� ������ ������ ����� (����������� �������� ���������
  //           ��� ���������� ������ mapClearImageObjects)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapScrollImageEx(HIMAGE himage, long int dx, long int dy, long int onlymap);

_MAPIMP long int _MAPAPI mapScrollImage(HIMAGE himage, long int dx, long int dy);

  // �������� ����������� ��������� ��������� ����� � ������ ������
  // ����� ���������� ����� ����������� ������������ �������� ���������
  // � �������� ��������� ��������� (�� ��� �������� �������� �������
  // ����� ����� ���������� ������� mapClearImageObjects).
  // himage   - ������������� ������ ����
  // hMap     - ������������� �������� ������
  // rect     - ����������� �������� �����, �������� � �������� �
  //            ������� ��������� ������� ����������� ����� (PICTURE)
  // position - ��������� �������� ������ ���� ��������� � ����������
  //            ������� ���� ����� (� ������ ������)
  // onlymap  - ������� ���������� ������ ������ ����� (����������� �������� ���������
  //            ��� ���������� ������ mapClearImageObjects)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDrawImageMapEx(HIMAGE himage, HMAP hMap, RECT *rect,
                                           POINT *position, long int onlymap);

_MAPIMP long int _MAPAPI mapDrawImageMap(HIMAGE image, HMAP hMap, RECT *rect,
                                         POINT *position);

  // �������� ����������� ��������� ��������� ����� � ������ ������
  // ����� ���������� ����� ����������� ������������ �������� ���������
  // � �������� ���������, ��������� ���������� �������
  // himage  - ������������� ������ ����
  // object  - ������������� �������, � �������� ��������� �������� ����� ��������� �����
  // onlymap - ������� ���������� ������ ������ ����� (����������� �������� ���������
  //           ��� ���������� ������ mapClearImageObjects)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapReDrawImageMapExUnderObject(HIMAGE himage, HMAP hMap,
                                                        HOBJ object, long int onlymap);

  // ���������� ������ ������ ����� ��������� � ������ ������
  // himage  - ������������� ������ ����
  // hMap - ������������� �������� ������
  // parm - ��������� ����������� ������� ����� � ������ ������ (������ �����)
  // object - ������������� �������� ������� � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDrawImageMapObject(HIMAGE himage, HMAP hMap,
                                               PAINTPARM *parm, HOBJ object);

  // ���������� ������ ������ ����� ��������� � ������ ������ c ������
  // ��������� ������ �������
  // himage  - ������������� ������ ����
  // hMap - ������������� �������� ������
  // offset - �������� �������� ����������� ������� � ������ �� ��� ��������
  //          ��������� � ������ � ������� ������� ��������� ���������
  // parm - ��������� ����������� ������� ����� � ������ ������ (������ �����)
  // object - ������������� �������� ������� � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDrawImageOffsetMapObject(HIMAGE himage, HMAP hMap,
                                                     DOUBLEPOINT *offset,
                                                     PAINTPARM *parm, HOBJ object);

  // ���������� ������ ������ ����� ��������� � ������ ������
  // himage  - ������������� ������ ����
  // hMap - ������������� �������� ������
  // parm - ��������� ����������� ������� ����� � ������ ������ (������ �����)
  // data - ������ ��������� ������� � ������� ���������, �������� ���������� place
  // place - ��� ������� ��������� (� ������ ������ - PP_PICTURE, � ������ �
  //         ������� ��������� ��������� - PP_PLANE, � �������� �� ����������
  //         ��������� - PP_GEO)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDrawImageUserObject(HIMAGE himage, HMAP hMap,
                                                PAINTPARM *parm,
                                                PLACEDATA *data,
                                                long int place);

  // ���������� ������ ������ ����� ��������� � ������ ������ c ������
  // ��������� ������ �������
  // himage  - ������������� ������ ����
  // hMap - ������������� �������� ������
  // offset - �������� �������� ����������� ������� � ������ �� ��� ��������
  //          ��������� � ������� ���������, �������� ���������� place
  // parm - ��������� ����������� ������� ����� � ������ ������ (������ �����)
  // data - ������ ��������� ������� � ������� ���������, �������� ���������� place
  // place - ��� ������� ��������� (� ������ ������ - PP_PICTURE, � ������ �
  //         ������� ��������� ��������� - PP_PLANE, � �������� �� ����������
  //         ��������� - PP_GEO)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDrawImageOffsetUserObject(HIMAGE himage, HMAP hMap,
                                                      DOUBLEPOINT *offset,
                                                      PAINTPARM *parm,
                                                      PLACEDATA *data,
                                                      long int place);

  // ���������� ����������� ������
  // hScreen  - ������������� ������ ������,
  // points   - ���������� � ��������
  // count    - ����� ���������
  // image    - ��� ������������ ��������� (��. mapgdi.h)
  // parm     - ��������� ������������ ���������

_MAPIMP long int _MAPAPI mapDrawImageGraphics(HIMAGE image, HMAP hMap,
                                              DRAWPOINT *points, long int count,
                                              long int type, const char *parm);

  // ���������� ��������� ������ (Arial)
  // image    - ������������� ������ ������,
  // points   - ���������� � ��������
  // count    - ����� ���������
  // text     - ����� �������
  // height   - ������ ������� � ���
  // color    - ���� ������� RGB
  // align    - ������ ������������ ������ (��� -1 - FA_BASELINE|FA_LEFT)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDrawImageText(HIMAGE image, HMAP hMap,
                                          DRAWPOINT *points, long int count,
                                          const char *text, long int height,
                                          long int color, long int align);
_MAPIMP long int _MAPAPI mapDrawImageTextUn(HIMAGE image, HMAP hMap,
                                            DRAWPOINT *points, long int count,
                                            const WCHAR *text, long int height,
                                            long int color, long int align);

  // ���������� BMP � ����� ������
  // image     - ������������� ������ ������,
  // point     - ���������� � ��������,
  // bmpmemory - ����� ������� ����, ����������� ����� BMP-�����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDrawImageBitMap(HIMAGE image, HMAP hMap,
                                            DRAWPOINT *point,
                                            const char *bmpmemory,
                                            long int transparent);

  // ������� ����������� �������� �� �������� ��������� ������
  // ������ (������������ ����� ���� ����� � ��������� ������)
  // ��� ������ ���������� ����

_MAPIMP void _MAPAPI mapClearImageObjects(HIMAGE image, RECT *rect);


#ifdef WIN32API
  // ������� BITMAP � ������� ������� CreateDIBSection
  // ������ �������� - 4 �����
  // hdc    - ������������ ��������
  // width  - ������ �����������
  // height - ������ �����������
  // memory - ����� ����������� � ������
  // ��� ������ ���������� ����

_MAPIMP HBITMAP _MAPAPI mapCreateBitmap(HDC hdc, long int width, long int height,
                                        void ** memory);

_MAPIMP HBITMAP _MAPAPI mapCreateBitmapEx(long int width, long int height);

  // ������� BITMAP, ��������� mapCreateBitmap

_MAPIMP void _MAPAPI mapCloseBitmap(HBITMAP hbitmap);

  // ���������� ����� � Bitmap
  // ������ ����������� �� ������ �������� ������
  // ��� ���������� �������� ��������������� �����������
  // (�� �������� ��������) ����� ������� mapSetMaxScreenImageSize()
  // erase - ������� �������� ���� ����� �������,
  //        (0 - ��� �� �������, !=0 - �������� �������� ������ ����,
  //        ��� ��������� ������� ������ (VT_SCREEN) ������ �������
  //        ������ ����, ����� �������� -2 (����� 2))
  // rect - ���������� ��������� ����� (Draw) � ����������� (Picture)
  // ��� ������ � ���������� ���������� 0

_MAPIMP long int _MAPAPI mapPaintToBitmap(HMAP hmap, HBITMAP hbitmap, int erase,
                                          RECT *rect);

  // ��������� ����������� � ��������� ��������� � ���� BMP
  // ������ ������� ����������� ������ ��� ��������� Windows !
  // hdc     - �������� ����������
  // rect    - ������ ����������� �������
  // bmpname - ��� ������������ ����� BMP, 32 ���� �� ������
  // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapSaveImageToBMP(HDC hdc, RECT *rect, const char *bmpname);
_MAPIMP long int _MAPAPI mapSaveImageToBMPUn(HDC hdc, RECT *rect, const WCHAR *bmpname);

  // ������� ����������� �� ����� BMP
  // rect    - ������ ��������� �������
  // bmpname - ��� ������������ ����� BMP, 32 ���� �� ������
  // ��� ������ � ���������� ���������� ����

_MAPIMP HBITMAP _MAPAPI mapLoadFromBMP(RECT * rect, const char *bmpname);
_MAPIMP HBITMAP _MAPAPI mapLoadFromBMPUn(RECT *rect, const WCHAR *bmpname);

#endif

  /*********************************************************
  *                                                        *
  *          ����������� ����� �� ����������� �����        *
  *                                                        *
  *********************************************************/

  // ��������� ������� ����������� �����
  // hmap - ������������� �������� ������
  // ���� ����������� ����� �������� - ���������� ��������� ��������
  // 1 - ����������� ��� ������, -1 - ����������� ��� ������
  // ���� ����� �� ������������ - ���������� ����

_MAPIMP long int _MAPAPI mapIsGridActive(HMAP hmap);

  // ���������� ������� ����������� �����
  // hmap - ������������� �������� ������
  // 1 - ����������� ��� ������, -1 - ����������� ��� ������
  // 0 - �� ���������� �����
  // ���� ����� �� ������������ - ���������� ����

_MAPIMP long int _MAPAPI mapSetGridActive(HMAP hmap, long int active);

  // ��������� ������� ��� �����
  // hmap - ������������� �������� ������
  // ������� �������� ����� ���������� � ������ ��������
  // ����������� ����������� ���������
  // (��������� ������ ������ 8 ��������, ������ �������������)

_MAPIMP double _MAPAPI mapGetGridStep(HMAP hmap);

  // ��������� ��������� �����
  // hmap - ������������� �������� ������
  // parm - ��������� �� ������� ���������� ����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetGridParm(HMAP hmap, GRIDPARM *parm);
_MAPIMP long int _MAPAPI mapGetGridParmEx(HMAP hmap, GRIDPARMEX *parm);

  // ���������� ��������� �����
  // hmap - ������������� �������� ������
  // parm - ����� �������� ���������� ����������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetGridParm(HMAP hmap, GRIDPARM *parm);
_MAPIMP long int _MAPAPI mapSetGridParmEx(HMAP hmap, GRIDPARMEX *parm);

  /*********************************************************
  *                                                        *
  *       ������� ������� ���������� � ��������� �����     *
  *                                                        *
  *********************************************************/

  // ��������� ������� ������� �����
  // hmap - ������������� �������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMapScale(HMAP hmap);

  // ��������� �������� �����
  // hmap - ������������� �������� ������
  // name - ����� ������ ��� ���������� �������
  // size - ������ ������
  // ��� ������ ���������� ������ ������

_MAPIMP const char * _MAPAPI mapGetMapName(HMAP hmap);
_MAPIMP long int _MAPAPI mapGetMapNameEx(HMAP hmap, char *name, long int size);

  // ��������� �������� ����� � ������� UNICODE
  // name - ������ � ��������� UNICODE (2 ����� �� ������)
  // size - ������ ������ � ������
  // ��� ������ ���������� ������ ������

_MAPIMP long int _MAPAPI mapGetMapNameUn(HMAP hMap, WCHAR *name, long int size);

  // ��������� ������ ���� � �������� ������� �����
  // (������� �������� mapGetMainMapName)
  // hmap - ������������� �������� ������
  // ��� ������ ���������� ������ ������

_MAPIMP const char * _MAPAPI mapGetMapPath(HMAP hmap);

  // ��������� ������ ���� � �������� ������� ����� � ������� UNICODE
  // (������� �������� mapGetMainMapName)
  // hmap - ������������� �������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetMapPathUn(HMAP hmap, WCHAR *name, long int size);       // 24/10/14

  // ��������� ��� �����
  // hmap - ������������� �������� ������
  // ���� ���� - ��. mapcreat.h, MAPTYPE
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMapType(HMAP hmap);

  // ��������� - �������� �� ����� ����������������
  // ���������������� ����� ������� �� ������ ����� ����������
  // �������� ��� �����
  // � ��������� MAPREGISTEREX ���������������� ����� � ����
  // FlagRealPlace ����� ��������� ��������
  // ���� ����� ���������������� - ������������ ��������� ��������

_MAPIMP long int _MAPAPI mapIsMapSite(HMAP hmap);

  // ��������� ������������� ���������� ��������� �������� ��������� �����
  // � ������ (������� ��������� PLANE)
  // X - ����� �����, Y - ����� �������
  // �.1 - ������ ����� ����,
  // �.2 - ������� ������
  // hmap - ������������� �������� ������
  // ��� ������ ���������� ���� (��������, ���� ������ ������ �����)

_MAPIMP double _MAPAPI mapGetMapX1(HMAP hmap);
_MAPIMP double _MAPAPI mapGetMapY1(HMAP hmap);
_MAPIMP double _MAPAPI mapGetMapX2(HMAP hmap);
_MAPIMP double _MAPAPI mapGetMapY2(HMAP hmap);

  // ��������� ���������� ������ ��������� �����
  // ��������� MAPREGISTER � LISTREGISTER ������� � mapcreat.h
  // hmap - ������������� �������� ������
  // sheetnumber - ����� ����� ����� ���
  // �������� ������������� ���������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMapInfo(HMAP hmap, long int sheetnumber,
                                       MAPREGISTER *map, LISTREGISTER *sheet);
_MAPIMP long int _MAPAPI mapGetMapInfoEx(HMAP hmap, long int sheetnumber,
                                         MAPREGISTEREX *map, LISTREGISTER *sheet);
_MAPIMP long int _MAPAPI mapGetMapInfoPro(HMAP hmap, long int sheetnumber,
                                          MAPREGISTEREX *map, LISTREGISTER *sheet,
                                          SHEETNAMES * sheetnames);         // 07/11/14

  // ��������� ���������� ������ ��������� �����
  // �� ����� ����� - �������� ����� (MAP,SIT) (name)
  // ��������� MAPREGISTER � LISTREGISTER ������� � mapcreat.h
  // sheetnumber - ����� ����� ����� ���
  // �������� ������������� ���������� ������
  // ��� ������ ���������� ����,
  // ����� - ����� �������� �� ����� (���� �� ����� ��� ��������, ���������� -1)

_MAPIMP long int _MAPAPI mapGetMapInfoByName(const char *name,
                                             long int sheetnumber,
                                             MAPREGISTER *map,
                                             LISTREGISTER *sheet);
_MAPIMP long int _MAPAPI mapGetMapInfoByNameUn(const WCHAR *name,
                                               long int sheetnumber,
                                               MAPREGISTER *mapreg,
                                               LISTREGISTER *sheet);
_MAPIMP long int _MAPAPI mapGetMapInfoByNameEx(const char *name,
                                               long int sheetnumber,
                                               MAPREGISTEREX *map,
                                               LISTREGISTER *sheet);
_MAPIMP long int _MAPAPI mapGetMapInfoByNameExUn(const WCHAR *name,
                                                 long int sheetnumber,
                                                 MAPREGISTEREX *mapreg,
                                                 LISTREGISTER *sheet);


  // ��������� ��� ������������� ����� �� ����� �����   
  // name    - ��� ����� �������� ����� (MAP,SIT)
  // rscname - ��� ����� RSC
  // size    - ������ ������ ��� ���������� ����� RSC
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscByName(const char *name, char *rscname, long int size);
_MAPIMP long int _MAPAPI mapGetRscByNameUn(const WCHAR *name, WCHAR *rscname, long int size);

  // �������� ������������ �����
  // nomenclature - ������ � �������������
  // length - ����� ������
  // type - ��� ����� (�� MAPTYPE)
  // scale - �������  (1000000,500000,200000 � �.�.
  //                   ��������������� ���� �����)

_MAPIMP long int _MAPAPI mapCheckNomenclature(const char *nomenclature,
                                              long int length,
                                              long int type, long int scale);
_MAPIMP long int _MAPAPI mapCheckNomenclatureUn(const WCHAR *nomenclature,
                                                long int type, long int scale);

  // ������������ ����� ����� �� ������������ (������� �����, �������, -)
  // filename - ����� ��� ��� �����
  // filelength - ����� ������ ��� ��� �����
  // nomenclature - ������������ �����
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetFileNameFromNomenclature(char *filename, int filelength,
                                                        const char *nomenclature);

  // ������������ ����� ����� �� ������������ (������� �����, �������, -)
  // filename - ����� ��� ����� �����
  // namesize - ������ ������ � ������
  // nomenclature - ������������ �����
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetFileNameFromNomenclatureUn(WCHAR *filename, int namesize,
                                                          const WCHAR *nomenclature);

  // ������ ������ �� ���� ��������������� �����
  // ������������� �������� ������-�������
  // hmap - ������������� �������� ������
  // ��������� MAPREGISTER � LISTREGISTER ������� � mapcreat.h
  // ������� ������   ���������  ���� � mapreg:
  //                - ��� �����
  //                - �������
  //                - �������� ��������� ���������
  //                  ���������  ���� � sheet:
  //                - ������������
  // �������� ������  ���������  ���� � mapreg:
  //                 - ������ �������� (��� �������� �����( hMap = 0))
  //                  ���������  ���� � sheet:
  //                 - ������������� ����������,
  //                 - ������������� ����������,
  //                 - ��������� ����������
  // ���� mapreg � sheet ����������� ��� �������� ����� (����� ������ ����)
  //  - hmap = 0
  // ���� mapreg ����������� ��� ���������� ����� � �����
  //  - hmap != 0

_MAPIMP long int _MAPAPI mapCalcTopographicSheet(HMAP hmap,
                                                 MAPREGISTER *mapreg,
                                                 LISTREGISTER *sheet);

_MAPIMP long int _MAPAPI mapCalcTopographicSheetEx(HMAP hmap,
                                                   MAPREGISTEREX *mapreg,
                                                   LISTREGISTER *sheet);

  // ���������� ������ �������� (�� 0 �� 360) �� ������������ ���������
  // nomenclature - ������������ �����
  // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapGetAxisMeridianFromNomenclature(const char *nomenclature);

                                                   
  // ���������� ������� ���������� �������� �������� ���������
  // ���������� ����� �������� ����� (Map) ��� ����� (Plane)
  // ��� ��������� ������������ �������� �������� ���������
  // hmap -  ������������� �������� ������
  // ����� ������� ����� ������, �������� �������� - ������������
  // ���������� �������� �������� ������� �� �������� - ��� 100 000 - ��
  // ���� 0,5 �����, ��� 10 000 - �� ���� 0,05 �����
  // ��� ���������������� �����, ����� � ����� ���������
  // ��������� 5 000 � ������� - ������ ���������� ��������
  // ������� �������� ��������������� ��� �������� ����� � ���� DeviceCapability
  // ��������� MAPREGISTEREX ������������� ��������� (��. mapcreat.h),
  // � ���� ������ ����� mapSetMapPrecision �� �����

_MAPIMP void _MAPAPI mapSetMapPrecision(HMAP hmap);

  // ��������� ������� ���������� �������� �������� ���������
  // hmap -  ������������� �������� ������
  // ���������� ��������:
  // 1 - ������������ �������� ��������,
  // 2 - � ��������� 2 ����� (����������),
  // 3 - � ��������� 3 ����� (����������)
  // ��� ������ ��� ���������� �������� �������� ��������� ���������� ����

_MAPIMP long int _MAPAPI mapGetMapPrecision(HMAP hmap);


  /*********************************************************
  *                                                        *
  *     ������� ������� ������������� ���������� �����     *
  *                                                        *
  *********************************************************/

  // ��������� ���������� ����������� � ������

_MAPIMP long int _MAPAPI mapGetEllipsoidCount();

  // ��������� �������� ���������� �� ����
  // ���������  code  - ��� ����������
  //            name  - ����� ������ ��� ���������� �������� ����������
  //            size  - ����� ���������� ������� ��� ������ � ������
  // ��� ������ ���������� 0
  // name �������� �������� "�� �����������"

_MAPIMP long int _MAPAPI mapGetEllipsoidNameByCode(long int code, char *name,
                                                   long int size);

_MAPIMP long int _MAPAPI mapGetEllipsoidNameByCodeUn(long int code, WCHAR* name,
                                                     long int size);

  // ������ ���� � �������� ���������� �� ������ � �������
  // ���������  number  - ����� ������ ������� ����������� (����� ���������� � 1)
  //            code    - ��� ����������
  //            name    - ����� ������ ��� ���������� �������� ����������
  //            size    - ����� ���������� ������� ��� ������ � ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetEllipsoidByNumber(long int number, long int &code,
                                                 char *name, long int size);

_MAPIMP long int _MAPAPI mapGetEllipsoidByNumberUn(long int number, long int *code,
                                                   WCHAR *name, long int size);

  // ��������� �� ���� EPSG ����� ���������� (��. MAPCREAT.H)
  // ��� ���������� ��������� MAPREGISTEREX
  // code - ��� EPSG
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetEllipsoidByEPSGCode(long int code);

  // ��������� ��� EPSG ���������� �� ��� ���� (��. MAPCREAT.H)
  // ellipsoid - ����� ���������� (��. MAPCREAT.H, ELLIPSOIDKIND)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetEllipsoidEPSGCode(long int code);

  // ������ ���������� ����� ���� � ������

_MAPIMP long int _MAPAPI mapGetMapTypeCount();

  // ������ �������� ���� ����� �� ����
  // ���������  code  - ��� ���� �����
  //            name  - ����� ������ ��� ���������� �������� ���� �����
  //            size  - ����� ���������� ������� ��� ������ � ������
  // ��� ������ ���������� 0
  // name �������� �������� "�� �����������"

_MAPIMP long int _MAPAPI mapGetMapTypeByCode(long int code, char *name,
                                             long int size);

_MAPIMP long int _MAPAPI mapGetMapTypeByCodeUn(long int code, WCHAR* name,
                                               long int size);

  // ������ ���� � �������� ���� ����� �� ������ � �������
  // ���������  number  - ����� ������ ������� ���� ����� (����� ���������� � 1)
  //            code    - ��� ���� �����
  //            name    - ����� ������ ��� ���������� �������� ���� �����
  //            size    - ����� ���������� ������� ��� ������ � ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetMapTypeByNumber(long int number, long int &code,
                                               char *name, long int size);

_MAPIMP long int _MAPAPI mapGetMapTypeByNumberUn(long int number, long int *code,
                                                 WCHAR *name, long int size);


  // ������ ���������� �������� � ������

_MAPIMP long int _MAPAPI mapGetProjectionCount();

  // ������ �������� �������� �� ����
  // ���������  code  - ��� ��������
  //            name  - ����� ������ ��� ���������� �������� ��������
  //            size  - ����� ���������� ������� ��� ������ � ������
  // ��� ������ ���������� 0
  // name �������� �������� "�� �����������"
_MAPIMP long int _MAPAPI mapGetProjectionNameByCode(long int code, char *name,
                                                    long int size);

_MAPIMP long int _MAPAPI mapGetProjectionNameByCodeUn(long int code, WCHAR *name,
                                                      long int size);

  // ������ ���� � �������� �������� �� ������ � �������
  // ���������  number  - ����� ������ ������� �������� (����� ���������� � 1)
  //            code    - ��� ��������
  //            name    - ����� ������ ��� ���������� �������� ��������
  //            size    - ����� ���������� ������� ��� ������ � ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetProjectionByNumber(long int number, long int &code,
                                                  char *name, long int size);

_MAPIMP long int _MAPAPI mapGetProjectionByNumberUn(long int number, long int *code,
                                                    WCHAR *name, long int size);

  /*********************************************************
  *                                                        *
  *       ������� ������� ���������� � ����� �����         *
  *                                                        *
  *********************************************************/

 // ��������� ����� ����� �� �����
 // hmap - ������������� �������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetLayerCount(HMAP hmap);

 // ��������� �������� ���� �� ��� ������ (number)
 // hmap - ������������� �������� ������
 // name - ����� ������ ��� ���������� �������
 // size - ������ ������ � ������
 // ����� ������� ���� 0
 // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapGetLayerName(HMAP hmap, long int number);

_MAPIMP long int _MAPAPI mapGetLayerNameEx(HMAP hmap, long int number,
                                           char *name, long int size);

_MAPIMP long int _MAPAPI mapGetLayerNameUn(HMAP hmap, long int number,
                                           WCHAR *name, long int size);

  /*********************************************************
  *                                                        *
  *       ������� ������� ���������� � ������ �����        *
  *                                                        *
  *********************************************************/

 // ���������� ����������� ����� ����� �� �������� ����������� (x,y).
 // ������� ��������� ������ ���������� place.
 // ���� ���� �� ������ - ���������� ����.
 // ���� � ����� ����� ��������� ������ :
 // hmap - ������������� �������� ������
 // number - ���������� ����� ����� � ���������� (������ � 1).
 // ����� ������ ���� ���������� ������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapWhatListNumber(HMAP hmap, double  x,double y,
                                           long int number, long int place);

 // ��������� ������������ ����� �� �������� ����������� (x,y).
 // hmap - ������������� �������� ������
 // name - ����� ������ ��� ���������� �������
 // size - ������ ������
 // ������� ��������� ������ ���������� place.
 // ���� ���� �� ������ - ���������� ����

_MAPIMP const char* _MAPAPI mapWhatListName(HMAP hmap, double x, double y,
                                            long int number, long int place);

_MAPIMP long int _MAPAPI mapWhatListNameEx(HMAP hmap, double x, double y,
                                           long int number, long int place,
                                           char *name, long int size);

_MAPIMP long int _MAPAPI mapWhatListNameUn(HMAP hmap, double x, double y,
                                           long int number, long int place,
                                           WCHAR *name, long int size);

 // ��������� ��� ����� �� ��� ������ (number)
 // hmap - ������������� �������� ������
 // name - ����� ������ ��� ���������� �������
 // size - ������ ������ � ������
 // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapGetSheetName(HMAP hmap, long int number);

_MAPIMP long int _MAPAPI mapGetSheetNameEx(HMAP hmap, long int number,
                                           char *name, long int size);

_MAPIMP long int _MAPAPI mapGetSheetNameUn(HMAP hmap, long int number,
                                           WCHAR *name, long int namesize);

 // ��������� ������������ ����� �� ��� ������ (number)
 // hmap - ������������� �������� ������
 // name - ����� ������ ��� ���������� �������
 // size - ������ ������
 // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapGetListName(HMAP hmap,long int number);

_MAPIMP long int _MAPAPI mapGetListNameEx(HMAP hmap,long int number,
                                          char *name,long int size);

_MAPIMP long int _MAPAPI mapGetListNameUn(HMAP hmap, long int number,
                                          WCHAR *name, long int size);

 // ��������� ����� ����� ������ � ������
 // hmap - ������������� �������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetListCount(HMAP hmap);

 // ��������� ����� ����� �������� � �����
 // hmap - ������������� �������� ������
 // list - ����� �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetObjectCount(HMAP hmap, long int list);

 // ��������� ����� ����� �������� � �����, �������� ���������
 // number - ����� �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRealObjectCount(HMAP hMap, long int number);

 // ��������� ����� ����� �� ��� ������������
 // hmap - ������������� �������� ������
 // name - ��� �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetListNumberByName(HMAP hmap, const char *name);

_MAPIMP long int _MAPAPI mapGetListNumberByNameUn(HMAP hMap, const WCHAR *name);

 // ���������� �� ������������ ����� ��� �������������� �����
 // hmap - ������������� �������� ������
 // listname - ��� ����� (������������)
 // ���������� ����� ����� � ������� ����,������� �����������
 // ���� �� ����� listname
 // (0-������� �����, 1-������ ���������������� ����� � �.�.)
 // ��� ������ ���������� "-1"

_MAPIMP long int _MAPAPI mapWhatListLayoutIs(HMAP hmap, const char *listname);

_MAPIMP long int _MAPAPI mapWhatListLayoutIsUn(HMAP hMap, const WCHAR *listname);

 // ��������� ������ "����� �����"
 // hmap - ������������� �������� ������
 // list - ����� ����� (c 1)
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetListFrameObject(HMAP hmap, long int list,
                                               HOBJ info);

 // ��������� �������� ������� "����� �����" (���� ����� ��� -
 // ����������� �� ��������� �� ��������)
 // hmap  - ������������� �������� ������
 // list  - ����� �����
 // frame - ��������� �� �������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetListFrame(HMAP hmap, int list, DFRAME *frame);

 // ������� ������ "����� �����"
 // hmap - ������������� �������� ������
 // list - ���������������� ����� ����� ����� (c 1)
 // info - ������������� ������� ����� � ������
 // HOBJ ������ ���� ������ ������� mapCreateObject
 // ��� �������� ���������� HOBJ ����� ��������� ���������
 // ��� ������������ ����� �����
 // ��� ���������������� ����� ����� ���������, �� �� ������������
 // ��� ����� ��������� ��������� ����� ����������� �� �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCreateListFrameObject(HMAP hmap, long int list,
                                                  HOBJ info);

 // ���������� ����������� �� ����� ������, �������� ������������ 
 // ����������� ��� ������ � �������������� ������� ��������� �
 // ������������ ������� ������
 // hmap - ������������� �������� ������
 // islimited - ������� ��������� ����������� ����� �������� ������, 
 // ������ �� 8 �� 32, �� �� ����� ����� �������, �������������� ����� �����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetActiveListCountLimit(HMAP hmap, long int islimited = 32);

  /*********************************************************
  *                                                        *
  * ������� ������� ���������� �� �������������� ��'�����  *
  *                                                        *
  *********************************************************/

 // ��������� ����� �������� ��������� � ��������������
 // hmap - ������������� �������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRscObjectCount(HMAP hmap);

 // ��������� ����� �������� ��������� � ��������������
 // � �������� ����
 // hmap - ������������� �������� ������
 // layer - ����� ���� � ��������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRscObjectCountInLayer(HMAP hmap, long int layer);

 // ��������� �������� ������� �� ����������� ������ (number)
 // � �������� ����
 // hmap - ������������� �������� ������
 // layer - ����� ���� � ��������������
 // size - ������ ������ � ������
 // ��� ������ ���������� ���� ��� ������ ������

_MAPIMP const char* _MAPAPI mapRscObjectNameInLayer(HMAP hmap, long int layer,
                                                    long int number);

_MAPIMP long int _MAPAPI mapRscObjectNameInLayerEx(HMAP hMap, long int layer,
                                                   long int number,
                                                   char *name, long int size);

_MAPIMP long int _MAPAPI mapRscObjectNameInLayerUn(HMAP hMap, long int layer,
                                                   long int number, WCHAR *name,
                                                   long int size);

 // ��������� ����������������� ��� �������
 // �� ����������� ������ � �������� ���� (number)
 // hmap - ������������� �������� ������
 // layer - ����� ���� � ��������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRscObjectExcodeInLayer(HMAP hmap, long int layer,
                                                   long int number);

 // ��������� ��� ����������� �������
 // �� ����������� ������ � �������� ���� (number)
 // hmap - ������������� �������� ������
 // layer - ����� ���� � ��������������
 // ��� ������ ���������� ���� (���� ��������)

_MAPIMP long int _MAPAPI mapRscObjectLocalInLayer(HMAP hmap, long int layer,
                                                  long int number);

 // ��������� ���������� ��� (������) �������
 // �� ����������� ������ � �������� ���� (number)
 // hmap - ������������� �������� ������
 // layer - ����� ���� � ��������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRscObjectCodeInLayer(HMAP hmap, long int layer,
                                                 long int number);

 // ��������� ���������� ��� (������) �������
 // �� �������� ���� (excode) � ����������� (local)
 // hmap - ������������� �������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRscObjectCode(HMAP hMap, long int excode, long int local);

 // ��������� ����� ������������� ������������� � ��������������
 // hmap - ������������� �������� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRscSemanticCount(HMAP hmap);

 // ��������� ��� ������������� �������������� �������
 // hmap - ������������� �������� ������
 // number - ���������������� ����� �������������� � �������������� (c 1)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRscSemanticCode(HMAP hmap, long int number);

 // ��������� ��� ������������� �������������� �������
 // �� ��������� ����� ���������
 // hmap - ������������� �������� ������
 // key  - �������� ��� ��������� (����) � ��������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRscSemanticCodeByKey(HMAP hmap, const char *key);

_MAPIMP long int _MAPAPI mapRscSemanticCodeByKeyUn(HMAP hMap, const WCHAR *key);

 // ��������� �������� ������������� �������������� �������
 // hmap - ������������� �������� ������
 // code    - ��� ��������������
 // ��� ������ ���������� ���� ��� ������ ������

_MAPIMP const char* _MAPAPI mapRscSemanticName(HMAP hmap, long int code);

_MAPIMP long int _MAPAPI mapRscSemanticNameUn(HMAP hmap, long int code,
                                              WCHAR *semname, long int size);

  /*********************************************************
  *                                                        *
  *           �������������� ��������� �����               *
  *                                                        *
  *********************************************************/

 // ��������� �������� ������ (���� ����� ����)
 // hmap - ������������� �������� ������
 // dframe - ��������� �� ����������� ���������
 // ������������� ���������� ����� ������ � ������ ��� �������� �� ���������
 // � ���������������� ������� ��� � �������� ������������ �������� ������ ����
 // ������
 // place  - ������������� ������� ��������� (PP_PICTURE, PP_PLANE, PP_GEO)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetTotalBorder(HMAP hmap, DFRAME *dframe,
                                           long int place);

 // ��������� �������� ������ (���� ����� ����) � ������� ���������,
 // �������� ����� EPSG, � ������ � �������� �� ���������
 // hmap - ������������� �������� ������
 // dframeplane - ��������� �� ����������� ��������� � ������
 // dframegeo   - ��������� �� ����������� ��������� � ��������
 // epsgcode    - ��� ������� ��������� (3395, 3857, 4326 � �.�.)
 // ��� ������������� ������ ��������� ���������� 2,
 // ��� ������� ������������� ���������� 1.
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetTotalBorderByEPSG(HMAP hmap, DFRAME *dframeplane,
                                                 DFRAME *dframegeo, long int epsgcode);

 // �������������� �� ��������� �� ����� (������ �����)
 // � ������� �� �����������
 // hmap - ������������� �������� ������
 // x,y  - ������������� ����������
 // �� ����� ��������, �� ������ - �������.
 // ���������� :
 // xpix = xdis; ypix = ydis;
 // mapMapToPicture(xpix,ypix);

_MAPIMP void _MAPAPI mapMapToPicture(HMAP hmap, double *x, double *y);

 // �������������� �� ��������� �� ����� (������ �����)
 // � ����� �� ���������
 // �� ����� ��������, �� ������ - �����.

_MAPIMP void _MAPAPI mapMapToPlane(HMAP hmap, double *x, double *y);

 // �������������� �� �������� � ����������� � ����������
 // ����� (������ �����) � ���������
 // hmap - ������������� �������� ������
 // x,y  - ������������� ����������

_MAPIMP void _MAPAPI mapPictureToMap(HMAP hmap, double *x, double *y);

 // �������������� �� �������� � ����������� � ����������
 // �� ��������� � ������
 // ���������� :
 // xmet = xdis; ymet = ydis;
 // mapPictureToPlane(xmet,ymet);
 // hmap - ������������� �������� ������
 // x,y  - ������������� ����������

_MAPIMP void _MAPAPI mapPictureToPlane(HMAP hmap, double *x, double *y);

 // �������������� �� ������ �� ��������� � ��������
 // �� ����� (������ �����)
 // hmap - ������������� �������� ������
 // x,y  - ������������� ����������

_MAPIMP void _MAPAPI mapPlaneToMap(HMAP hmap, double *x, double *y);

 // �������������� �� ������ �� ��������� � ������� ��
 // �����������
 // hmap - ������������� �������� ������
 // x,y  - ������������� ����������

_MAPIMP void _MAPAPI mapPlaneToPicture(HMAP hmap, double *x, double *y);

 // �������������� �� ������ �� ��������� � �������������
 // ���������� � �������� � ������������ � ��������� �����
 // (������������� �� ��� ���� ���� !)
 // ���������� :
 // if (mapIsGeoSupported())   |  ��� :
 //   {                        |  if (mapIsGeoSupported())
 //     B = Xmet; L = Ymet;    |    {
 //     mapPlan2Geo(B,L);      |      mapPlan2Geo(B=Xmet,L=Ymet);
 //   }                        |    }
 // hmap - ������������� �������� ������
 // Bx,Ly  - ������������� ����������
 // �� ����� �����, �� ������ - �������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapPlaneToGeo(HMAP hmap, double *Bx, double *Ly);

 // �������������� �� ������������� ��������� � ��������
 // � ����� �� ��������� � ������������ � ��������� �����
 // (�������������� �� ��� ���� ���� !)
 // hmap - ������������� �������� ������
 // Bx,Ly  - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGeoToPlane(HMAP hmap, double *Bx, double *Ly);

 // �������������� ��������� � ������ �� ��������� �� ����� ���� � ������
 // source - ����� �������� ���� ������� 1942�
 // target - ������ ����
 // x,y  - ������������� ����������
 // �� ����� ����� � ����� ���� 42�.,�� ������ - ������.
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapPlaneToPlaneByZone(long int source, long int target,
                                               double *x, double *y);


 // �������������� ��������� � ������ �� ��������� �� �������� ����
 // � ������������� ���������� � ������� 42�.
 // zone - ����� �������� ���� ������� 1942�
 // x,y  - ������������� ����������
 // �� ����� ����� � ����� ���� 42�.,�� ������ - �������.
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapPlane42ToGeo42ByZone(long int zone, double *x, double *y);
_MAPIMP long int _MAPAPI mapPlaneToGeo42ByZone(long int zone, double *x, double *y);

 // �������������� ��������� � ������ �� ��������� �� �������� ���� UTM
 // � ������������� ���������� � ������� WGS-84.
 // zone - ����� �������� ���� ������� UTM
 // x,y  - ������������� ����������
 // �� ����� ����� � ����� ���� UTM, �� ������ - ������� WGS-84.
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapPlaneUTMToGeoWGS84ByZone(long int zone, double *x, double *y);

 // �������������� ��������� � ������ �� ��������� �� ����� ���� � ������
 // source - ����� �������� ���� ������� UTM
 // target - ������ ���� ������� UTM
 // x,y  - ������������� ����������
 // �� ����� ����� � ����� ���� UTM, �� ������ - ����� � ������ ���� UTM.
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapPlaneUTMToPlaneUTMByZone(long int source, long int target,
                                                     double *x, double *y);

 // ������ - �������������� �� �������� � �������������
 // ����������� �� ������� ������������� � �������
 // hmap - ������������� �������� ������
 // ���� ��� - ���������� ����

_MAPIMP long int _MAPAPI mapIsGeoSupported(HMAP hmap);

 // �������������� �� ������ �� ��������� (�������� �����)
 // � ������������� ���������� � �������� (���������� ��������� WGS84)
 // (�������������� �� ��� ���� ���� !)
 // ������� ������ �������� �������� ��������,
 // ������� mapPlaneToGeoWGS84() ��������
 // ���������� ������ �� �������
 // ���������� :
 // if (mapIsGeoSupported())
 //   {
 //     B = Xmet; L = Ymet;
 //     mapPlaneToGeoWGS84(hMap,B,L);
 //   }
 // hmap  - ������������� �������� ������
 // Bx,Ly - ������������� ����������
 // �� ����� �����, �� ������ - �������
 // H     - ������ � ����� (�����)
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapPlaneToGeoWGS84(HMAP hmap, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapPlaneToGeoWGS843D(HMAP hmap, double *Bx, double *Ly,
                                              double *H);

 // �������������� �� ������ �� ��������� (�������� �����)
 // � ������������� ���������� � �������� (��������� �����������, ��-42)
 // (�������������� �� ��� ���� ���� !)
 // hmap  - ������������� �������� ������
 // Bx,Ly - ������������� ����������
 // �� ����� �����, �� ������ - �������
 // H     - ������ � ����� (�����)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPlaneToGeo42(HMAP hmap, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapPlaneToGeo423D(HMAP hmap, double *Bx, double *Ly,
                                           double *H);

 // �������������� �� ������ �� ��������� (�������� �����)
 // � ������������� ���������� � �������� (��������� �����������, ��-95)
 // (�������������� �� ��� ���� ���� !)
 // ���� �������� ����� � ��-42, �� ������������� ���������� �������� � ��-42
 // ��� �������������� 
 // hmap  - ������������� �������� ������
 // Bx,Ly - ������������� ����������
 // �� ����� �����, �� ������ - �������
 // H     - ������ � ����� (�����)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPlaneToGeo953D(HMAP hmap, double *Bx, double *Ly,
                                           double *H);

                                          
 // �������������� ��������� �� ������������� ������� ��������� ����� �
 // � ������������� ���������� � �������� (���������� ��������� WGS84)
 // (�������������� �� ��� ���� ���� !)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeoToGeoWGS843D(HMAP hMap, double *Bx, double *Ly,
                                            double *H);

 // �������������� ��������� �� ������������� ������� ��������� � ��������
 // (���������� ��������� WGS84) � ������������� ������� ��������� �����
 // (�������������� �� ��� ���� ���� !)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeoWGS84ToGeo3D(HMAP hMap, double *Bx, double *Ly,
                                            double *H);

                                           
 //  �������������� �� ������������� ��������� � ��������
 // (���������� ��������� WGS84)
 //  � ����� �� ��������� � ������� 1942� (��������� �����������)
 // (�������������� �� ��� ���� ���� !)
 // ���������� :
 // if (mapIsGeoSupported())
 //   {
 //     B = Xmet; L = Ymet;
 //     mapGeo84ToPlane42(hMap,B,L);
 //   }
 // hmap - ������������� �������� ������
 // Bx,Ly  - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeoWGS84ToPlane42(HMAP hmap, double *Bx, double *Ly);

 //  �������������� �� ������������� ��������� � ��������
 // (���������� ��������� WGS84)
 //  � ����� �� ��������� � �������� �����
 // (�������������� �� ��� ���� ���� !)
 // hmap - ������������� �������� ������
 // Bx,Ly,H  - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeoWGS84ToPlane3D(HMAP hmap, double *Bx, double *Ly,
                                              double *H);

 //  �������������� �� ������������� ��������� � ��������
 // (��������� �����������, ��-42)
 //  � ����� �� ��������� � �������� �����
 // (�������������� �� ��� ���� ���� !)
 // hmap - ������������� �������� ������
 // Bx,Ly,H  - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeo42ToPlane3D(HMAP hmap, double *Bx, double *Ly,
                                           double *H);

 //  �������������� �� ������������� ��������� � ��������
 // (��������� �����������, ��-95)
 //  � ����� �� ��������� � �������� �����
 // (�������������� �� ��� ���� ���� !)
 // hmap - ������������� �������� ������
 // Bx,Ly,H  - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeo95ToPlane3D(HMAP hmap, double *Bx, double *Ly,
                                           double *H);

 //  �������������� �� ������������� ��������� � ��������
 // (���������� ��������� ��-90.02)
 //  � ����� �� ��������� � �������� �����
 // (�������������� �� ��� ���� ���� !)
 // hmap - ������������� �������� ������
 // Bx,Ly,H  - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeoEP90ToPlane3D(HMAP hmap, double *Bx, double *Ly,
                                             double *H);

 // �������������� ������������� ���������� � �������� �� ������� 1942�
 // (��������� �����������) � ������������� ���������� � ��������
 // (���������� ��������� WGS84) (�������������� �� ��� ���� ���� !)
 // hmap - ������������� �������� ������
 // Bx,Ly  - ������������� ����������
 // �� ����� ������� � 42�., �� ������ - ������� � WGS84
 // H     - ������ � ����� (�����)
 // �������� hmap ����� ���� ����� ����

_MAPIMP void _MAPAPI mapGeo42ToGeoWGS84Ex(double *Bx, double *Ly, double *H);
_MAPIMP long int _MAPAPI mapGeo42ToGeoWGS84(HMAP hmap,double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapGeo42ToGeoWGS843D(HMAP hmap,double *Bx, double *Ly,
                                              double *H);

 // �������������� ������������� ��������� � �������� �� ������� NAHRWAN
 // (��������� ������ 1880�) � ������������� ���������� � ��������
 // ������� WGS84 (���������� ��������� WGS-84)
 // �� ����� ������� � NAHRWAN, �� ������ - ������� � WGS84
 // H     - ������ � ����� (�����)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeoNahrwanToGeoWGS843D(double *B, double *L, double *H);


 // �������������� ������������� ���������� � �������� �� ������� WGS 84
 // (���������� ��������� WGS84) (�������������� �� ��� ���� ���� !)
 // � ������������� ���������� � �������� � ������� 1942 � (��������� �����������)
 // hmap - ������������� �������� ������
 // Bx,Ly  - ������������� ����������
 // �� ����� ������� � WGS84, �� ������ - ������� � 42�.
 // H     - ������ � ����� (�����)
 // �������� hmap ����� ���� ����� ����

_MAPIMP long int _MAPAPI mapGeoWGS84ToGeo42Ex(double *Bx, double *Ly, double *H);
_MAPIMP long int _MAPAPI mapGeoWGS84ToGeo42(HMAP hmap, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapGeoWGS84ToGeo423D(HMAP hmap, double *Bx, double *Ly,
                                              double *H);

 // �������������� ������������� ��������� � �������� �� ������� ��-90
 // (���������� ��������� ��-90.02) � ������������� ���������� � ��������
 // ������� 1942 � (��������� �����������)
 // �������� hmap ����� ���� ����� ����

_MAPIMP void _MAPAPI mapGeoEP90ToGeo42Ex(double *Bx, double *Ly, double *H);
_MAPIMP long int _MAPAPI mapGeoEP90ToGeo42(HMAP hmap, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapGeoEP90ToGeo423D(HMAP hmap, double *Bx, double *Ly,
                                             double *H);

 // �������������� ������������� ��������� � �������� �� ������� ��-90
 // (���������� ��������� ��-90.02) � ������������� ���������� � ��������
 // ������� 1995 � (��������� �����������)

_MAPIMP void _MAPAPI mapGeoEP90ToGeo95Ex(double *Bx, double *Ly, double *H);

 // �������������� ������������� ��������� � �������� �� ������� 1995 �
 // (��������� �����������) � ������������� ���������� � ��������
 // ������� ��-90(���������� ��������� ��-90.02)

_MAPIMP void _MAPAPI mapGeo95ToGeoEP90Ex(double *Bx, double *Ly, double *H);

 // �������������� ������������� ��������� � �������� �� ������� 1942 �
 // (��������� �����������) � ������������� ���������� � ��������
 // ������� ��-90(���������� ��������� ��-90.02)
 // �������� hmap ����� ���� ����� ����

_MAPIMP void     _MAPAPI mapGeo42ToGeoEP90Ex(double *Bx, double *Ly, double *H);
_MAPIMP long int _MAPAPI mapGeo42ToGeoEP90(HMAP hmap, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapGeo42ToGeoEP903D(HMAP hmap, double *Bx, double *Ly,
                                             double *H);

 // �������������� ������������� ��������� � �������� �� ������� ��-90
 // (���������� ��������� ��-90.02) � ������������� ���������� � ��������
 // � ������� WGS-84 (���������� ��������� WGS84)

_MAPIMP void _MAPAPI mapGeoEP90ToGeoWGS843D(double *Bx, double *Ly, double *H);

 // �������������� ������������� ��������� � ������ �� ������� ��������� �����
 // � ������������� ���������� � �������� ������� ��-90(���������� ��������� ��-90.02)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPlaneToGeoEP903D(HMAP hmap, double *Bx, double *Ly,
                                             double *H);

 // �������������� ������������� ��������� � �������� �� ������� 1942 �
 // (��������� �����������) � ������������� � ������ � ������� NAHRWAN �
 // �������� UTM (��������� ������ 1880�.) - NAD27

_MAPIMP void     _MAPAPI mapGeo42ToPlaneUTMEx(double *Bx, double *Ly, double H);
_MAPIMP long int _MAPAPI mapGeo42ToPlaneUTM(HMAP hmap, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapGeo42ToPlaneUTM3D(HMAP hmap, double *Bx, double *Ly,
                                              double *H);


 // �������������� ������������� ��������� � �������� �� ������� 1942 �
 // (��������� �����������) � ������������� � ������ � ������ ���������
 // ���� � ����������� �����
 // Bx,Ly - ������������� ����������

_MAPIMP long int _MAPAPI mapGeo42ToPlaneByOwnZone(double *Bx, double *Ly);


 // �������������� ������ ����� �� ����� �������
 // ��������� � ������
 // hmap  - ������������� �������� ������
 // src,tag - ��������� �� ������� ���������� �����,
 // ����� ��������� �� ���� � �� �� ������� ������;
 // source,target - ���� ������� � �������� ������� (PP_MAP,PP_PLANE ...);
 // count - ����� ������������� �����.
 // �������� ��������� � �������������� ������������
 // ����� ����������� ������,���� IsGeoSupported() != 0.

_MAPIMP void _MAPAPI mapTransformPoints(HMAP hmap, DOUBLEPOINT *src,
                                        long int source, DOUBLEPOINT *tag,
                                        long int target, long int count);

 // �������������� ��������� �� �������� � �������
 // (��� �������������� ��������)
 // degree - ���������, ���������� ���������� � ��������, �������,
 // ��������. ������� � maptype.h
 // radian - �������� � ��������

_MAPIMP void _MAPAPI mapDegreeToRadian(GEODEGREE *degree, double *radian);

 // �������������� ��������� �� ������ � �������
 // (��� �������������� ��������)
 // radian - �������� � ��������
 // degree - ���������, ���������� ���������� � ��������, �������,
 // ��������. ������� � maptype.h

_MAPIMP void _MAPAPI mapRadianToDegree(double *radian, GEODEGREE *degree);

 // �������������� ��������� �� �������� � ������� � ������ �����
 // degree - ���������, ���������� ���������� � ��������, �������,
 // ��������. ������� � maptype.h
 // radian - �������� � ��������

_MAPIMP void _MAPAPI mapSignDegreeToRadian(SIGNDEGREE *degree, double *radian);

 // �������������� ��������� �� ������ � ������� �� ������
 // radian - �������� � ��������
 // degree - ���������, ���������� ���������� � ��������, �������,
 // ��������. ������� � maptype.h

_MAPIMP void _MAPAPI mapRadianToSignDegree(double *radian, SIGNDEGREE *degree);

 // ���������� ������� ��������� �� ������ ���� ���
 // �������� ������� 42 ����
 // zone - ����� ���� ������� 42 ����
 // ��� ������ ���������� ����

_MAPIMP double _MAPAPI mapGetAxisMeridianByZone(long int zone);

 // ���������� ������ ���� �� ������������� ������� � ��������
 // (���������) ��� �������� ������� 42 ����
 // meridian - �������� ��������� � ��������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetZoneByMeridian(double meridian);

 // ���������� ������� ��������� �� ������������� ������� �
 // �������� ��� ��������������� ����
 // hmap - ������������� �������� ������
 // meridian - �������� ��������� � ��������
 // �� ������������� ��������� ��� ���� ��� ���������� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetAxisMeridianByMeridian(HMAP hmap, double meridian);

 // ���������� ������� ��������� �� ���������� Y ���
 // ��������������� ���� ������� 42 ����
 // �� ������������� ��������� ��� ���� ��� ���������� �������
 // hmap  - ������������� �������� ������
 // y     - ���������� Y � ������ ������������ �����,
 //         ���������� �� �������� ����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetAxisMeridianByPlaneY(HMAP hmap, double y);

  /*********************************************************
  *                                                        *
  *     �������� ��������� � ������� ������� ���������     *
  *                                                        *
  *********************************************************/

 // ��������� ��������� ���������� �� ��� ������ (��. MAPCREAT.H)
 // ellipsoid - ����� ���������� (��. MAPCREAT.H, ELLIPSOIDKIND)
 // parm      - ��������� ��������� ����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetEllipsoidParameters(long int ellipsoid,
                                                   ELLIPSOIDPARAM *parm);

 // ���������� ������� ��������� ������� ������� ���������
 // hMap      - ������������� �������� �������� �����
 // parm      - ��������� ������� ������� ���������
 // datum     - ��������� ��������� � ���������� ������� ������� ���������
 //             � WGS-84 (datum ����� ���� 0)
 // ellipsoid - ��������� ����������������� ���������� ��� �������
 //             ������� ���������, ����� ���� EllipsoideKind �
 //             MAPREGISTEREX ����� USERELLIPSOID (ellipsoid ����� ���� 0)
 // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetWorkSystemParametersEx(HMAP hMap,
                                                       MAPREGISTEREX *parm,
                                                       DATUMPARAM *datum,
                                                       ELLIPSOIDPARAM *ellipsoid);
                                                    
_MAPIMP long int _MAPAPI mapSetWorkSystemParameters(HMAP hmap,
                                                    MAPREGISTEREX * parm);

 // ��������� ������� ��������� ������� ������� ���������
 // hMap      - ������������� �������� �������� �����
 // parm      - ��������� ������� ������� ���������
 // datum     - ��������� ��������� � ���������� ������� ������� ���������
 //             � WGS-84
 // ellipsoid - ��������� ����������������� ���������� ��� ������� 
 //             ������� ���������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetWorkSystemParametersEx(HMAP hmap,
                                                      MAPREGISTEREX *parm,
                                                      DATUMPARAM *datum,
                                                      ELLIPSOIDPARAM *ellipsoid);

_MAPIMP long int _MAPAPI mapGetWorkSystemParameters(HMAP hmap,
                                                    MAPREGISTEREX *parm);

 // ��������� - ����������� �� ��������� ������� ������� ���������
 // (���� mapSetWorkSystemParameters �� ���������� - ���������� 0)
 // hMap   - ������������� �������� �������� �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapIsWorkSystemParameters(HMAP hmap);

 // �������������� �� ������� ������������� ��������� � ������ �� ���������� �����
 // � ����� �� ��������� � ������������ � ����������� ������� ������� ���������
 // hmap   - ������������� �������� ������
 // X,Y,H  - ������������� ����������
 // �� ����� �����, �� ������ - �����
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapPlaneToWorkSystemPlane(HMAP hMap, double *X,
                                                   double *Y, double *H);

 // �������������� �� ������� ������������� ��������� � ������ �� ���������� �����
 // � ������������� ����������  � ������������ � ����������� ������� ������� ���������
 // hmap   - ������������� �������� ������
 // X,Y,H  - ������������� ����������
 // �� ����� �����, �� ������ - �������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapPlaneToWorkSystemGeo(HMAP hMap, double *X,
                                                 double *Y, double *H);

 // �������������� �� ������������� ��������� � �������� �� ���������� �����
 // � ����� �� ��������� � ������������ � ����������� ������� ������� ���������
 // hmap     - ������������� �������� ������
 // Bx,Ly,H  - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGeoToWorkSystemPlane(HMAP hmap, double *Bx,
                                                 double *Ly, double *H);

 // �������������� � ������������� ���������� � �������� �� ���������� �����
 // �� ������ �� ��������� � ������� ������� ��������� � ������������ � �� �����������
 // hmap    - ������������� �������� ������
 // Bx,Ly,H - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapWorkSystemPlaneToGeo(HMAP hmap, double *Bx,
                                                 double *Ly, double *H);

  /**********************************************************
  *                                                         *
  * �������� ��������� � ���������������� ������� ��������� *
  *                                                         *
  **********************************************************/

 // ���������� ������� ��������� ���������������� ������� ���������
 // parm      - ��������� ������� ������� ��������� (��. MAPCREAT.H)
 // datum     - ��������� ��������� � ���������� ������� ������� ���������
 //             � WGS-84 (datum ����� ���� 0)
 // ellipsoid - ��������� ����������������� ���������� ��� ������� 
 //             ������� ���������, ������ ����� ���� EllipsoideKind �
 //             MAPREGISTEREX ����� USERELLIPSOID (ellipsoid ����� ���� 0)
 // code      - ��� EPSG (4326 - WGS-84),
 //             ��� ��-42 ���� 1-60 : 28401-28460, ��� ��-95 ���� 4-32: 20004-20032
 // ���������� ������������� ���������������� ������� ���������
 // �� ���������� ������������� ���������� ������� mapDeleteUserSystemParameters
 // ��� ������ ���������� ����

_MAPIMP HANDLE _MAPAPI mapCreateUserSystemParameters(MAPREGISTEREX *parm,
                                                     DATUMPARAM *datum,
                                                     ELLIPSOIDPARAM *ellipsoid);

_MAPIMP HANDLE _MAPAPI mapCreateUserSystemParametersByEpsg(long int code);

 // ���������/���������� ��� ������� ���������
 // (������� ������������� - 1 ��� ������������� - 2)
 // ��� ���������� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetUserSystemType(HANDLE huser);
_MAPIMP long int _MAPAPI mapSetUserSystemType(HANDLE huser, long int type);

 // �������������� �� ������������� ��������� (�������) � ���������������� ��������
 // � ������������� ���������� � �������� (���������� ��������� WGS84)
 // huser - ������������� ���������������� ������� ���������
 // Bx,Ly - ������������� ����������
 // �� ����� �������, �� ������ - �������
 // H     - ������ � ����� (�����)
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapUserGeoToGeoWGS84(HANDLE huser, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapUserGeoToGeoWGS843D(HANDLE huser, double *Bx, double *Ly,
                                                double *H);

 // �������������� �� ������������� ��������� (�������) � ���������������� ��������
 // � ����� � ���������������� ��������
 // huser - ������������� ���������������� ������� ���������
 // Bx,Ly - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapUserGeoToUserPlane(HANDLE huser, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapUserGeoToPlane(HANDLE huser, double *Bx, double *Ly);

 // �������������� �� ������ �� ��������� � ���������������� ��������
 // � ������������� ���������� � �������� (���������� ��������� WGS84)
 // ������� ������ �������� �������� ��������
 // huser - ������������� ���������������� ������� ���������
 // Bx,Ly - ������������� ����������
 // �� ����� �����, �� ������ - �������
 // H     - ������ � ����� (�����)
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapUserPlaneToGeoWGS84(HANDLE huser, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapUserPlaneToGeoWGS843D(HANDLE huser, double *Bx, double *Ly,
                                                  double *H);

 // �������������� �� ������ �� ��������� � ���������������� ��������
 // � ������������� ���������� � �������� �� ���������� � ���������������� ��������
 // ������� ������ �������� �������� ��������
 // huser - ������������� ���������������� ������� ���������
 // Bx,Ly - ������������� ����������
 // �� ����� �����, �� ������ - �������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapUserPlaneToUserGeo(HANDLE huser, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapUserPlaneToGeo(HANDLE huser, double *Bx, double *Ly);

 // �������������� �� ������������� ��������� � ��������
 // (���������� ��������� WGS84)
 // � ������������� ���������� � �������� �� ���������� � ���������������� ��������
 // huser    - ������������� ���������������� ������� ���������
 // Bx,Ly,H  - ������������� ����������
 // �� ����� �������, �� ������ - �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeoWGS84ToUserGeo(HANDLE huser, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapGeoWGS84ToUserGeo3D(HANDLE huser, double *Bx, double *Ly,
                                                double *H);

 // �������������� �� ������������� ��������� � ��������
 // (���������� ��������� WGS84)
 // � ����� �� ��������� � ���������������� ��������
 // huser    - ������������� ���������������� ������� ���������
 // Bx,Ly,H  - ������������� ����������
 // �� ����� �������, �� ������ - �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeoWGS84ToUserPlane(HANDLE huser, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapGeoWGS84ToUserPlane3D(HANDLE huser, double *Bx, double *Ly,
                                                  double *H);

 // �������������� �� ������������� ��������� (�������) � �������� ���������
 // � ������������� ���������� � �������� �� ���������� � ���������������� ��������
 // hmap    - ������������� �������� ������
 // huser    - ������������� ���������������� ������� ���������
 // Bx,Ly,H  - ������������� ����������
 // �� ����� �������, �� ������ - �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeoToUserGeo(HMAP hmap, HANDLE huser, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapGeoToUserGeo3D(HMAP hmap, HANDLE huser, double *Bx, double *Ly,
                                           double *H);
                                                                                    
 // �������������� �� ������������� ��������� (�������) �� ����������
 // � ���������������� �������� � ������������� ���������� (�������) � �������� ���������
 // hmap    - ������������� �������� ������
 // huser    - ������������� ���������������� ������� ���������
 // Bx,Ly,H  - ������������� ����������
 // �� ����� �������, �� ������ - �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUserGeoToGeo(HMAP hmap, HANDLE huser, double *Bx, double *Ly);
_MAPIMP long int _MAPAPI mapUserGeoToGeo3D(HMAP hmap, HANDLE huser, double *Bx, double *Ly,
                                           double *H);

  // ���������� ������� ���������������� ������� ���������

_MAPIMP void _MAPAPI mapDeleteUserSystemParameters(HANDLE huser);

 // �������� ��������� ���� ������ ���������                   // 22/01/14
 // parm1      - ��������� ������ ������� ��������� (��. MAPCREAT.H)
 // datum1     - ��������� ��������� � ���������� ������ ������� ���������
 //              � WGS-84 (datum ����� ���� 0)
 // ellipsoid1 - ��������� ����������������� ���������� ��� ������
 //              ������� ���������, ������ ����� ���� EllipsoideKind �
 //              MAPREGISTEREX ����� USERELLIPSOID (ellipsoid ����� ���� 0)
 // parm2      - ��������� ������ ������� ��������� (��. MAPCREAT.H)
 // datum2     - ��������� ��������� � ���������� ������ ������� ���������
 //              � WGS-84 (datum ����� ���� 0)
 // ellipsoid2 - ��������� ����������������� ���������� ��� ������
 //              ������� ���������
 // ��� ������������ �����-���� �������� ���������� ���������� ��������� ��������
 // ��������� ������������� ��������� ����� ��������� �����������
 // (��������, ��������������� ����� UTM � �������-�������������� ����� UTM)

_MAPIMP long int _MAPAPI mapCompareSystemParameters(MAPREGISTEREX * parm1,
                                                    DATUMPARAM * datum1,
                                                    ELLIPSOIDPARAM * ellipsoid1,
                                                    MAPREGISTEREX * parm2,
                                                    DATUMPARAM * datum2,
                                                    ELLIPSOIDPARAM * ellipsoid2);

  /*********************************************************
  *                                                        *
  *     ����������� ��������� � �������� �������           *
  *                                                        *
  *********************************************************/

 // ���������� ������ ����������� ������� ��������� �������
 // hmap    - ������������� �������� ������
 // format -  ����� ������� ����������� ��������� (��. maptype.h - CURRENTPOINTFORMAT)
 // ��� ������ ���������� ����, ����� - ������������� ��������

_MAPIMP long int _MAPAPI mapSetCurrentPointFormat(HMAP hmap, long int format);
  
 // ��������� ������ ����������� ������� ��������� �������
 // hmap    - ������������� �������� ������
 // ���������� ����� ������� ����������� ��������� (��. maptype.h - CURRENTPOINTFORMAT)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetCurrentPointFormat(HMAP hmap);
  
 // ����������� �������� ��������� �� ������� ������������� ��������� ��������� (�����)
 // � �������, ������������ �������� ����������� ������� ���������
 // hmap    - ������������� �������� ������
 // x, y    - ���������� ����� � �������� � ������������ � �������� �����������
 //           �������� (mapGetDocProjection) - ��������������� � ����� ��������
 // h       - ������ ����� (��������� ����� ���� ����� ����), ���� ������ �������� -
 //           ��������������� � ����� ��������
 // maptype - ��� �����, ��������������� �����������, ���� �� ����� ����, 
 //           �� ����������� ������ � ������������ ������� ���������: "(��42)", "(CR95)"...
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPlaneToPointFormat(HMAP hmap, double *x,
                                               double *y, double *h);

 // ����������� �������� ��������� �� ������� ������������� ��������� ��������� (�����)
 // � �������, ������������ �������� ����������� ������� ���������
 // � ������������ ������
 // hmap    - ������������� �������� ������
 // x, y    - ���������� ����� � �������� � ������������ � �������� �����������
 //           �������� (mapGetDocProjection)
 // h       - ������ ����� (��������� ����� ���� ����� ����)
 // place   - ����� ������ ��� ������ ����������
 // size    - ������ ��������� ������ (�� ����� 256 ����)
 // ������ ������:
 // B= -73� 27' 04.53"  L= 175� 51' 21.07"  H= 109.51 m (WGS84)
 // X= 6 309 212.12 �   Y= 7 412 249.25 � (��42)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPlaneToPointFormatString(HMAP hmap, double *x,
                                                     double *y, double *h,
                                                     char *place, long int size);
_MAPIMP long int _MAPAPI mapPlaneToPointFormatStringUn(HMAP hmap, double *x,
                                                       double *y, double *h,
                                                       WCHAR *place, long int size);

 // ����� ��������� ����� � ������
 // x,y   - ������� ������������� ���������� ����� � ������
 // h     - ������ � ������ ��� ������� ���������
 // place - ����� ������ ��� ���������� ����������
 // size  - ������ ������ � ������ (�� ����� 80 ����)
 // maptype - ��� �����, ���� �� ����� ����, �� ����������� ������
 //           � ������������ ������� ���������: "   (��42)", "   (C�95)",...
 // ������ ����������:
 // "X=  438 145.27 m  Y= 6 230 513.03 m  H=  54.12 m"

_MAPIMP void _MAPAPI mapPlaneToString(double *x, double *y, double *h,
                                      char *place, long int size, long int maptype);
_MAPIMP long int _MAPAPI mapPlaneToStringUn(double *x, double *y, double *h,
                                            WCHAR *place, long int size, long int maptype);

 // ������ ����� � ��������� ������ � ���������� ���� �� �������� ����������� ��������
 // (���������� �� ������ �������� �� ����� ������ � ������)
 // ��������: 7 390 621.458
 // value  - �������� �����, ������������� � ������
 // string - ����� ������ ��� ���������� ����������
 // size   - ����� ������ � ������ (�� ����� 16 !)
 // precision - ����� ������ ����� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDoubleToString(double value, char* string,
                                           long int size, long int precision);
_MAPIMP long int _MAPAPI mapDoubleToStringUn(double value, WCHAR *string,
                                             long int size, long int precision);

  // ������ ������ ����� � ���������� ���� �� �������� ����������� ��������
  // (���������� �� ������ �������� �� ����� ������ � ������)
  // size - ����� ������ � ������ (�� ����� 16 !)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapLongToString(long int number, char *string, long int size);
_MAPIMP long int _MAPAPI mapLongToStringUn(long int number, WCHAR* string,long int size);

  // ������ ������ ����� ���� __int64 � ���������� ����
  // �� �������� ����������� ��������
  // (���������� �� ������ �������� �� ����� ������ � ������)
  // size - ����� ������ � ������ (�� ����� 32 !)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapInt64ToString(__int64 number, char *string, long int size);
_MAPIMP long int _MAPAPI mapInt64ToStringUn(__int64 number, WCHAR *string, long int size);

  // ��������� ������� ����� ����� �� ��������� ����� ������
  // ����� ����� �������� ��� ���������
  // value - �������� ��������
  // count - ����� ������ ����� ������� (�� 0 �� 9)

_MAPIMP double _MAPAPI mapRoundDouble(double value, int count);

  // ������ �������� � ���������� ���� �� �������� ����������� ��������
  // (��������: "1 : 50 000","2 : 1" - ���� scale < 1)
  // (���������� �� ������ �������� �� ����� ������ � ������)
  // size - ����� ������ � ������ (�� ����� 20 !)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapScaleToString(double scale, char * string, long int size);
_MAPIMP long int _MAPAPI mapScaleToStringUn(double scale, WCHAR* string, long int size);


/*************************************************************************
*                                                                        *
*             ������� ������� � ���� ������ EPSG                         *
*  ��� ���������� ���������� ������� � ����� ���������� ������           *
*  EPSG.CSG, EPSG.CSP, EPSG.CSU, ������� ������ � ������ ��� ����� 2011. *
*  �������� ����� ����� ��������� ��������� EPSGReader, �������� �       *
*  ��� ����� 2011.                                                       *
*************************************************************************/

  // ��������� ��������� �������� � ������� ��������� �� ���� EPSG
  // ���� ��� EPSG ������ ������������� ������� ���������,
  // �� ��������������� �������� ������\������� � ���������������
  // ��������� ���������� � �����
  // ���� ��� EPSG ������ ������� ������������� ������� ���������,
  // �� ��� ��������� ��������������� �� ���� EPSG
  // epsgcode  - ��� EPSG, ��� ��-42 ���� 2-32 : 28402-28432, ��� ��-95 ���� 4-32: 20004-20032
  // mapreg    - ��������� ������� ��������� � ��������
  // datum     - ��������� ��������� � ���������� ������� ������� ���������
  //             � WGS-84
  // ellipsoid - ��������� ����������������� ���������� ��� �������
  //             ������� ���������
  // ��� ������������� ������ ��������� ���������� 2,
  // ��� ������� ������������� ���������� 1.
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetParametersForEPSG(long int epsgcode,
                                                 MAPREGISTEREX  *mapreg,
                                                 DATUMPARAM     *datum,
                                                 ELLIPSOIDPARAM *ellipsoid);

  // ������� ���� ������ EPSG
  // ��� �������� ���������� ���������� ������������� �������� ���� ������ EPSG
  // ��� ������ ���������� 0

_MAPIMP HANDLE _MAPAPI mapOpenEPSGDatabase();

  // ������� ���� ������ EPSG
  // epsgdata - ������������� �������� ���� ������ EPSG

_MAPIMP void _MAPAPI mapCloseEPSGDatabase(HANDLE epsgdata);

  // ������� ������ �� ������� ������������� ������� ��������� � ���� ������ EPSG
  // ����� ������ ������� ������� ���������� ��������� ������� ��������� � ���� ������ EPSG
  // epsgdata  - ������������� �������� ���� ������ EPSG
  // mapreg    - ��������� ��������
  // ellipsoid - ���������
  // datum     - �����
  // rectsys   - ��������� ������������� ������� ���������
  // geodsys   - ��������� ������� ������������� ������� ���������
  // unit      - ������� ���������
  // ��� ������ ��� ��� ������ �� ������� ������ ������ ���������� 0

_MAPIMP long int _MAPAPI mapReadEPSGProjectedSystem(HANDLE epsgdata, MAPREGISTEREX *mapreg, ELLIPSOIDPARAM *ellipsoid,
                                                    DATUMPARAM *datum, EPSGRECTSYS *rectsys,
                                                    EPSGGEODSYS *geodsys, EPSGMEASUNIT *unit);

  // ������� ������ �� ������������� ������� ��������� �� ������ ������ � ���� ������ EPSG   // 24/03/11
  // ����� ������ ������� ������� ���������� ��������� ������� ��������� � ���� ������ EPSG
  // epsgdata    - ������������� �������� ���� ������ EPSG
  // coordsysnum - ����� ������ � ������ ������������� ������ ��������� (�� 1)
  // mapreg      - ��������� ��������
  // ellipsoid   - ���������
  // datum       - �����
  // rectsys     - ��������� ������������� ������� ���������
  // geodsys     - ��������� ������� ������������� ������� ���������
  // unit        - ������� ���������
  // ��� ������ ��� ��� ������ �� ������� ������ ������ ���������� 0

_MAPIMP long int _MAPAPI mapReadEPSGProjectedSystemByNumber(HANDLE epsgdata, long int coordsysnum,
                                                            MAPREGISTEREX *mapreg,
                                                            ELLIPSOIDPARAM *ellipsoid,
                                                            DATUMPARAM *datum, EPSGRECTSYS *rectsys,
                                                            EPSGGEODSYS *geodsys, EPSGMEASUNIT *unit);

  // ��������� ��������� ������������� ������� ��������� �� ���� � ���� ������ EPSG
  // epsgcode  - ��� ������������� ������� ��������� � ���� ������ EPSG
  // ellipsoid - ��������� ����������
  // datum     - ��������� ������
  // geodsys   - ��������� ������������� ��
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetEPSGGeodeticSystem(long int epsgcode, ELLIPSOIDPARAM *ellipsoid,
                                                  DATUMPARAM *datum, EPSGGEODSYS *geodsys);

  // ��������� ��������� ������������� ������� ��������� �� ���� � ���� ������ EPSG
  // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG
  // mapreg   - ��������� ��������
  // rectsys  - ��������� ������������� ��
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetEPSGProjectedSystem(long int epsgcode, MAPREGISTEREX *mapreg,
                                                   EPSGRECTSYS *rectsys);


  // ��������� ��������� ������� ��������� �� ���� � ���� ������ EPSG
  // epsgcode - ��� ������� ��������� � ���� ������ EPSG
  // unit     - ��������� ������� ���������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetEPSGUnit(long int epsgcode, EPSGMEASUNIT *unit);

  // ��������� WKT ������ �� MAPREGISTEREX, ELLIPSOIDPARAM, DATUMPARAM
  // mapreg    - ��������� ��������
  // ellipsoid - ��������� ����������
  // datum     - ��������� ������
  // wktstr    - ����������� ������ � ��������� ������� ���������
  // wktstrsize - ����������������� ������ ������ (4 ������ ����������)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetWKTString(MAPREGISTEREX *mapreg, ELLIPSOIDPARAM *ellipsoid, DATUMPARAM *datum,
                                         char *wktstr, long int wktstrsize);


  /***************************************************************
  *                                                              *
  *  ������� ������ ���������� ������ ������� �� ������ � �����  *
  *                                                              *
  ****************************************************************
  * <?xml version="1.0" encoding="UTF-8"?>                       *
  * <ProjectList Version="1.0">                                  *
  * <Project Name="ITM"                                          *
  * Comment="Israel Transverse Mercator"                         *
  * EPSG="2039">                                                 *
  * <Projection Type="Transverse Mercator"                       *
  * EPSG="9807"                                                  *
  * CentralMeridian="31 44 3.816999999992845"                    *
  * LatitudeOfOrigin="35 12 16.260999999993260"                  *
  * ScaleFactor="1.0000067"                                      *
  * FalseEasting="219529.584"                                    *
  * FalseNothing="626907.3899999999"/>                           *
  * <Spheroid Type="GRS 1980" Parm="6378137.0 298.257222101"/>   *
  * </Project>                                                   *
  * </ProjectList>                                               *
  ****************************************************************/

 // ������� ������ ���������� ������ �������
 // name - ��� ����� ������ ����������
 // ��� �������� ���������� ���������� ������������� ������ � ������
 // ��� ������ ���������� ����

_MAPIMP HMAPREG _MAPAPI mapOpenMapRegisterList(const char *name);

_MAPIMP HMAPREG _MAPAPI mapOpenMapRegisterListUn(const WCHAR *name);

 // ������� ������ ���������� ������ �������
 // name - ��� ����� ������ ����������
 // ��� �������� ���������� ���������� ������������� ������ � ������
 // ��� ������ ���������� ����

_MAPIMP HMAPREG _MAPAPI mapCreateMapRegisterList(const char *name);

_MAPIMP HMAPREG _MAPAPI mapCreateMapRegisterListUn(const WCHAR *name);

 // ������� ������ ���������� ������ �������
 // hmapreg - ������������� ������ ���������� ������ �������

_MAPIMP void _MAPAPI mapCloseMapRegisterList(HMAPREG hmapreg);

 // ��������� ����� ������ �������, ���������� � ������
 // � ���� ����� XML (<ProjectList Version="1.0">
 // ����� ������� ������������� ���� ��� "Project"
 // hmapreg - ������������� ������ ���������� ������ �������
 // ��� �������� ���������� ���������� ����� ������� ����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapMapRegisterListCount(HMAPREG hmapreg);

 // ��������� �������� ������� ������� �� ��������� ����������� ������
 // � ������ (������� � 1)
 // hmapreg - ������������� ������ ���������� ������ �������
 // number  - ���������� ����� ������ ����������
 // name    - ����� ������ ��� ���������� ����������
 // size    - ������ ���������� ������ � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapMapRegisterListName(HMAPREG hmapreg, long int number,
                                                char *name, int size);

_MAPIMP long int _MAPAPI mapMapRegisterListNameUn(HMAPREG hmapreg, long int number,
                                                  WCHAR *name, int size);

 // ��������� ����������� ��� ������� ������� �� ��������� ����������� ������
 // � ������ (������� � 1)
 // hmapreg - ������������� ������ ���������� ������ �������
 // number  - ���������� ����� ������ ����������
 // name    - ����� ������ ��� ���������� ����������
 // size    - ����� ���������� ������ ��� ���������� ����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapMapRegisterListComment(HMAPREG hmapreg, long int number,
                                                   char *name, int size);

_MAPIMP long int _MAPAPI mapMapRegisterListCommentUn(HMAPREG hmapreg, long int number,
                                                     WCHAR *name, int size);

 // ��������� ���������� ����� � ������ (������� � 1)               // 05/04/14
 // �� ���� EPSG ��� ������� ������� (CRS)
 // hmapreg - ������������� ������ ���������� ������ �������
 // epsg    - ��� EPSG ��� ������� ������� (CRS)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSeekMapRegisterListByEPSG(HMAPREG hmapreg, long int epsg);

 // ��������� ��� EPSG ��� ������� ������� �� ��������� ����������� ������
 // � ������ (������� � 1)
 // hmapreg - ������������� ������ ���������� ������ �������
 // number  - ���������� ����� ������ ����������
 // ���� ��� �� ����� - ���������� "-1"
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapMapRegisterListEPSG(HMAPREG hmapreg, long int number);

 // ��������� ������������� ��� ������� �������
 // �� ��������� ����������� ������ � ������ (������� � 1)
 // hmapreg - ������������� ������ ���������� ������ �������
 // number  - ���������� ����� ������ ����������
 // ident   - ����� ������ ��� ���������� ��������������
 // size    - ����� ���������� ������ ��� ���������� ��������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapMapRegisterListCrsIdent(HMAPREG hmapreg, long int number,
                                                    char *ident, int size);

_MAPIMP long int _MAPAPI mapMapRegisterListCrsIdentUn(HMAPREG hmapreg, long int number,
                                                      WCHAR *ident, int size);

 // ��������� ��������� ������� ������� �� ��������� ����������� ������
 // � ������ (������� � 1)
 // hmapreg - ������������� ������ ���������� ������ �������
 // number  - ���������� ����� ������ ����������
 // mapreg  - ��������� �������� <Projection ...>
 // datum   - ��������� ������ <Datum ...>
 // ellparm - ��������� ���������� <Spheroid ...>
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapMapRegisterListParameters(HMAPREG hmapreg, long int number,
                                                      MAPREGISTEREX  *mapreg,
                                                      DATUMPARAM     *datum,
                                                      ELLIPSOIDPARAM *ellparm);

 // �������� ������ ���������� ������� �������
 // hmapreg - ������������� ������ ���������� ������ �������
 // name     - ���������� �������� ������� ������� (�����������)
 // comment  - ����������� ��� ������� ������� (��� ����)
 // epsgcode - ��� EPSG (��� ����)
 // ident   - ������������� ������� ������� (��� ����)
 // mapreg   - �������� ���������� ������� ������� (�����������)(��. mapcreat.h)
 // datum    - �������� ���������� ������ (��� ����) (��. mapcreat.h)
 // ellparam - �������� ���������� ���������� (��� ����) (��. mapcreat.h)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendMapRegisterListParameters(HMAPREG hmapreg,
                                                            const char *name,
                                                            const char *comment,
                                                            long int epsgcode,
                                                            MAPREGISTEREX *mapreg,
                                                            DATUMPARAM *datum,
                                                            ELLIPSOIDPARAM *ellparm);

_MAPIMP long int _MAPAPI mapAppendMapRegisterListParametersEx(HMAPREG hmapreg,
                                                              const char *name,
                                                              const char *comment,
                                                              long int epsgcode,
                                                              const char *ident,
                                                              MAPREGISTEREX *mapreg,
                                                              DATUMPARAM *datum,
                                                              ELLIPSOIDPARAM *ellparm);

_MAPIMP long int _MAPAPI mapAppendMapRegisterListParametersUn(HMAPREG hmapreg,
                                                              const WCHAR *name,
                                                              const WCHAR *comment,
                                                              long int epsgcode,
                                                              const WCHAR *ident,
                                                              MAPREGISTEREX *mapreg,
                                                              DATUMPARAM *datum,
                                                              ELLIPSOIDPARAM *ellparm);

 // ������� ������ ���������� ������ ������� �� ����������� ������
 // � ������ (������� � 1)
 // hmapreg - ������������� ������ ���������� ������ �������
 // number  - ���������� ����� ������ ����������
 // ��� ������������ ��������� ������ � ����� ����� �������
 // ������� mapCommitMapRegisterList
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteMapRegisterListParameters(HMAPREG hmapreg, long int number);

 // �������� ��������, ����������� � ��� ������� ������� �� ��������� ����������� ������
 // � ������ (������� � 1)
 // hmapreg - ������������� ������ ���������� ������ �������
 // number  - ���������� ����� ������ ����������
 // name    - �������� ������� ������� ��� 0 (�� ������)
 // comment - ����������� � ������� ������� ��� 0 (�� ������)
 // code    - ��� EPSG ��� 0 (�� ������)
 // ident   - ������������� ������� ������� ��� 0 (�� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdateMapRegisterListName(HMAPREG hmapreg, long int number,
                                                      const char *name,
                                                      const char *comment,
                                                      long int code);

_MAPIMP long int _MAPAPI mapUpdateMapRegisterListNameEx(HMAPREG hmapreg, long int number,
                                                        const char *name,
                                                        const char *comment,
                                                        long int code,
                                                        const char *ident);

_MAPIMP long int _MAPAPI mapUpdateMapRegisterListNameUn(HMAPREG hmapreg, long int number,
                                                        const WCHAR *name,
                                                        const WCHAR *comment,
                                                        long int code, const WCHAR *ident);

 // ��������� ��������� ������ ���������� ������ ������� � �����
 // hmapreg - ������������� ������ ���������� ������ �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCommitMapRegisterList(HMAPREG hmapreg);

 // �������� ��������� ������ ���������� ������ ������� � ������
 // ������ ��������� ����� ���� ��������� �� ������ mapCommitMapRegisterList
 // hmapreg - ������������� ������ ���������� ������ �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUndoMapRegisterList(HMAPREG hmapreg);

  /*********************************************************
  *                                                        *
  *     ������� ������� ���������� �� ������� �����        *
  *                                                        *
  *********************************************************/

 // ��������� �������� ����� �� ������� ���������� ������
 // info - ������������� ������� ����� � ������
 // name - ����� ������ ��� ���������� �������
 // size - ������ ������ � ������
 // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapListName(HOBJ info);
_MAPIMP long int _MAPAPI mapListNameEx(HOBJ info, char *name, long int size);
_MAPIMP long int _MAPAPI mapListNameUn(HOBJ info, WCHAR *name, long int size);

 // ��������� ������������� �������������� �����, ���������� ������
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP HRSC _MAPAPI mapGetRscIdentByObject(HOBJ info);

 // ��������� ���������� ����� �������
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapObjectKey(HOBJ info);

 // ���������� ���������� ����� �������
 // info - ������������� ������� ����� � ������
 // number - ���������� ����� ������� � �����
 // ���������, ���������� ������ ������� ������ ����������
 // ������������ ������� � ����� !
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetObjectKey(HOBJ info, long int number);

 // ��������� ����������������� ��� �������
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� 0 (���� �������� ��� ������ �������)

_MAPIMP long int _MAPAPI mapObjectExcode(HOBJ info);

 // ��������� �������� ����������� �������
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� 0  (���� ��������)

_MAPIMP long int _MAPAPI mapObjectLocal(HOBJ info);

 // ��������� �������� �������� �������
 // info - ������������� ������� ����� � ������
 // name - ����� ������ ��� ���������� �������
 // size - ������ ������ � ������
 // ��� ������ ���������� ����

_MAPIMP const char * _MAPAPI mapObjectName(HOBJ info);

_MAPIMP long int _MAPAPI mapObjectNameEx(HOBJ info, char *name, long int size);

_MAPIMP long int _MAPAPI mapObjectNameUn(HOBJ info, WCHAR *name, long int size);

 // ��������� ������������ ������ ��������� �������� �������
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapObjectNameSize(HOBJ info);

 // ��������� ����������� ���������� �������
 //  info - ������������� ������� ����� � ������
 // ����������:
 //  OD_UNDEFINED (1) - �� ���������� (����������� ������ ��� ������,
 //                     ����������� � ����� ��� ������, ������� "�����")
 //  0D_RIGHT     (2) - ������ ������ (�������� ������ ���������� �������
 //                     �� ������� �������)
 //  0D_LEFT      (4) - ������ ����� (�������� ������ ���������� �������
 //                     ������ ������� �������)
 // (��. OBJECT_DIRECT � Maptype.h)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapObjectDirect(HOBJ info);

 // ��������� ����������� ���������� �������
 //  info    - ������������� ������� ����� � ������
 //  subject - ����� ���������� (��� ������� - ����� ����)
 // ����������:
 //  OD_UNDEFINED (1) - �� ���������� (����������� ������ ��� ������,
 //                     ����������� � ����� ��� ������, ������� "�����")
 //  0D_RIGHT     (2) - ������ ������ (��������� ������ �������
 //                     �� ������� �������)
 //  0D_LEFT      (4) - ������ ����� (��������� ������ �������
 //                     ������ ������� �������)
 // (��. OBJECT_DIRECT � Maptype.h)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSubjectDirect(HOBJ info, long int subject);


 // ��������� ����� ���� ������� ("Layer" = "Segment")
 // ������ ����� ���������� � ���� !
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSegmentNumber(HOBJ info);

 // ��������� �������� ���� ������� ("Layer" = "Segment")
 // info - ������������� ������� ����� � ������
 // name - ����� ������ ��� ���������� �������
 // size - ������ ������
 // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapSegmentName(HOBJ info);
_MAPIMP long int _MAPAPI mapSegmentNameEx(HOBJ info, char *name, long int size);
_MAPIMP long int _MAPAPI mapSegmentNameUn(HOBJ info, WCHAR *name, long int size);

 // ��������� ������������ ������ ������� ���� �������
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSegmentNameSize(HOBJ info);

 // ��������� ������ (���������� ���) �������
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� 0 (���� �������� ��� ������ �������)

_MAPIMP long int _MAPAPI mapObjectCode(HOBJ info);

 // ���������� �������� ������ ��������� �� ��������������
 // ��������
 // info - ������������� ������� ����� � ������

_MAPIMP void _MAPAPI mapClearBotTop(HOBJ info);

 // ���������/���������� �������� ��������� ��������� �������
 // scale - ������� ����������� �� 1:1 �� 1:40 ���.
 // info - ������������� ������� ����� � ������

_MAPIMP long int _MAPAPI mapObjectTopScale(HOBJ info);
_MAPIMP long int _MAPAPI mapSetObjectTopScale(HOBJ info, long int scale);
_MAPIMP long int _MAPAPI mapObjectBotScale(HOBJ info);
_MAPIMP long int _MAPAPI mapSetObjectBotScale(HOBJ info, long int scale);

 // ��������� - �������� �� �������� ������ ��������� � �������
 // ����������� (�� ���� �������������� �� �� ��������������,
 // � ������������� ��� ������� ����������)
 // ���� ������� ��������� �������� �� �������������� - ���������� 0

_MAPIMP long int _MAPAPI mapObjectBotTopUniqueness(HOBJ info);

 // ������������ �������� ������ ������� �� �������� ���� � �����������
 // ��� �������� ��� ������������� ������� �� �����
 // info - ������������� ������� ����� � ������
 // excode - ������� ��� ������� (��������),
 // local  - ����������� (LOCAL_LINE, LOCAL_POINT...)
 // ������ ���������� ����� mapCreateObject(...) � ���������� ��������� 
 // (���� ��� ����)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRegisterObject(HOBJ info, long int excode,
                                           long int local);

 // ������������ �������� ������ ������� �� ��������� ����� ������� 
 // (�����) ��� �������� ��� ������������� ������� �� �����
 // info - ������������� ������� ����� � ������
 // name - ���������� ��� ������� � �������������� (�� 31 �������)
 // ������ ���������� ����� mapCreateObject(...)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRegisterObjectByKey(HOBJ info, const char *name);

 // ������������ �������� ������ �������
 // �� ����������� ���� ������� (��. mapRscObjectCode() � �.�.)
 // ��� �������� ��� ������������� ������� �� �����
 // info - ������������� ������� ����� � ������
 // ������ ���������� ����� mapCreateObject(...) � ����������
 // ��������� (���� ��� ����)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDescribeObject(HOBJ info, long int code);

 // ������������ �������� ������ ������������ �������
 // �� ������ ���� (�� �������������� �����) � �����������
 // info - ������������� ������� ����� � ������
 // layer - ���������� ����� ���� � ��������������
 // local  - ����������� (LOCAL_LINE, LOCAL_POINT..., ��. maptype.h)
 // ���������� ����� mapCreateObject(...)
 // ��� ������������ ��������� ����� ����������
 // ������������ ������� mapAppendDraw(...)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRegisterDrawObject(HOBJ info, long int layer,
                                               long int local);

 // ���������� ����� ����� ��� ������ �������
 // info - ������������� ������� ����� � ������
 // list - ���������������� ����� ����� (� 1)
 // �������� ���������������� � ���������� ������ �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetObjectListNumber(HOBJ info, long int list);

 // ��������� ����� ����� ��� �������
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetListNumber(HOBJ info);

 //  ��������� ������ �������� ������� (IDSHORT2,...,IDDOUBLE3)
 //  ��� ������ ���������� ����, ����� - ��� ������� �������� �������

_MAPIMP long int _MAPAPI mapGetObjectKind(HOBJ info);

 // ���������� ��� � ����������� ������� �������
 // info - ������������� ������� ����� � ������
 // kind - ��� �������, ��. maptype.h
 // (�������� : IDFLOAT2,IDDOUBLE3, � �.�.,
 // ������� ���������������� ����� � ����� ����� ������ ����� ��� DOUBLE)
 // �������� ����������� � ����������� ������������ ���������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetObjectKind(HOBJ info, long int kind);

 // ��������� �������� ������� � ���� ������
 // info - ������������� ������� ����� � ������
 // buffer - ����� ������ ��� ���������� ����������,
 // size   - ������ ���������� ������ ��� ��������.
 // ����� ����������� ��� �������� ������� �� ������ �����
 // ��� �� �������� (!) (����������� ������ ������)
 // �������� ������� ����� ����������� ����� ����������
 // ��������, ����������, ������������
 // �� ��������������� ����������.
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetObjectRecord(HOBJ info, char *buffer,
                                            long int size);

 // ��������� ����� �������� ������� � ���� ������
 // info - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetObjectRecordLength(HOBJ info);

 // ������� ������ �� ��������� ����� �� ������ �������
 // hmap  - ������������� �������� ������
 // hsite - ������������� �������� ���������������� �����
 // buffer - ����� ������� ������ � ������� �������, ��������� � mapGetObjectRecord
 // mode  - ����� ��������
 //  0 - ��������,��� �����;
 //  1 - �������� ������ ��� ���������� Key();
 //  4 - ������� � ������,��� �����,
 //  5 - �������� ������ ��� ���������� Key() � ������;
 // ��� ������� 4 � 5 ��������� �����������
 // ����� mapCommitObject()
 // ��� ������ ���������� ����, ����� - ������������� ���������� �������
 // ���� ������ �� �����, ����� ���������� ������� �������� mapFreeObject

_MAPIMP HOBJ _MAPAPI mapPutObjectRecord(HMAP hmap, HSITE hsite,
                                        const char *buffer, long int size,
                                        long int mode);

 // ��������� ���������� ����� ������� � �����
 // info  - ������������� ������� ����� � ������
 // ���� ������ ������ ������ � ����� mapCommit... �� ��������� -
 // ���������� ����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetObjectNumber(HOBJ info);

 // ��������� ���������� ������������� ���� ������� � ��������������
 // (�������� ��� - ������ ������ �� 31 �������)
 // info  - ������������� ������� ����� � ������
 // key  - ����� ������ ��� ������ ����������
 // size - ����� ������
 // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapObjectRscKey(HOBJ info);

_MAPIMP long int _MAPAPI mapObjectRscKeyUn(HOBJ info, WCHAR *key, long int size);

 // ����������/��������/��������� ���������������� �������
 // ����������� ������ ��� ����������� ��������, ������� ���������� ��� ������ ����
 // ��� �������� �� �������������� �������� ������������
 // scale = 1 ��� ��������� ���������������� ��� ���������� �����
 //         0 ��� ������ �������� ����������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetObjectScale(HOBJ info, long int scale);
_MAPIMP long int _MAPAPI mapGetObjectScale(HOBJ info);

 // ����������/��������/��������� ������� "�� �������" �������
 // ����������� ������ ��� ����������� ��������, ������� ���������� ��� ������ ����
 // press = 1 ��� ��������� �������� "�� �������" ��� ������ �����
 //           �������������� �������� �������� �����
 //         0 ��� ������ ��������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetObjectPress(HOBJ info, long int press);
_MAPIMP long int _MAPAPI mapGetObjectPress(HOBJ info);  

 // ����������/��������� ������ ����������� ������� ������� � ����
 // ������������� �������
 // type - ��� ������� (SPLINETYPE_SMOOTH, SPLINETYPE_POINTS)
 // ��� ������ ��� ������ ��������� ������� ���������� ����

_MAPIMP long int _MAPAPI mapSetObjectSpline(HOBJ info, long int type);
_MAPIMP long int _MAPAPI mapGetObjectSpline(HOBJ info);

 // ����������/��������� ������� ������������ ���������� �� ���������
 // ��� ����������� ������ ����� ������� ���������� ������������� �� ���������
 // �� ������ ����� ������� ������� ��� ��������� ������ � ��������
 // ��� ������ ���������� ����

 _MAPIMP long int _MAPAPI mapSetObjectVerticalAlignment(HOBJ info, long int flag);
 _MAPIMP long int _MAPAPI mapGetObjectVerticalAlignment(HOBJ info);

 // ����������/��������� ������� ����� ������� ��� ��� ��������          // 09/07/15
 // ��������� ����� �� ������ ������� � �� ��������� �������� �������� ����� �������,
 // �� ����� ����������� � ������������� ��������� ��� ������� ������������ ��������������
 // 1 (OBM_RECTANGLE) - ������� ����� ����� ��������������� (�������������) ��������������
 // 2 (OBM_CIRCLE) - ������� ����� ����� ����������
 // ���� ����� �� ����������� ���������� ����

 _MAPIMP long int _MAPAPI mapSetObjectFormType(HOBJ info, long int type);
 _MAPIMP long int _MAPAPI mapGetObjectFormType(HOBJ info);

 // ���������/���������� ������� ������������� ��������� ��� ����������� �������
 // info   - ������������� ������� ����� � ������
 // isview - ������� ������������� ��������� ��� ����������� �������
 // ��� ����������� �������� �������������� � ���������� ��������� ��������,
 // �������� �� ��� �������, ������������� ��������� ���������� �������������
 // ��� ������ ���������� ����

 _MAPIMP long int _MAPAPI mapSetObjectViewSemantic(HOBJ info, long int isview);
 _MAPIMP long int _MAPAPI mapGetObjectViewSemantic(HOBJ info);



 // ************************************************************
 //                                                            *
 //         ������ ��������� (���������) �������               *
 //                                                            *
 // ************************************************************

 // ��������� ����� ������������� ������������� � �������
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticAmount(HOBJ info);

 // ��������� �������� ������������� �������������� �������
 // �������� ������������� � ���������� ��� ��� ��������������
 // info   - ������������� ������� ����� � ������
 // number - ���������������� ����� �������������� (c 1),
 // value  - ����� ���������� ������,
 // size   - ������������ ����� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticValue(HOBJ info, long int number,
                                          char *value, long int size);

 // ��������� - �� �������� �� ��������� ������� UNICODE
 // info   - ������������� ������� ����� � ������
 // number - ���������������� ����� �������������� (c 1)
 // ���� ��������� � ��������� Unicode - ���������� ��������� ��������

_MAPIMP long int _MAPAPI mapIsSemanticUnicode(HOBJ info, long int number);
_MAPIMP long int _MAPAPI IsSemanticUnicode(HOBJ info, long int number);

 // ��������� �������� ������������� �������������� ������� � UNICODE
 // �������� ������������� � ���������� ��� ��� ��������������
 // info   - ������������� ������� ����� � ������
 // number - ���������������� ����� �������������� (c 1),
 // value  - ����� ���������� ������,
 // size   - ������������ ����� ������ � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticValueUn(HOBJ info, long int number,
                                            WCHAR *value, long int size);

_MAPIMP long int _MAPAPI mapSemanticValueUnicode(HOBJ info, long int number,
                                                 WCHAR *value, long int size);

 // ��������� �������� ������������� �������������� �������
 // � ���� ����� � ��������� ������ ������� ��������
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� �������������� (c 1)
 // ���� �������� ��������� �� ����� ���� �������������
 // � ��������� ���� ��� �� ������� - ���������� ����

_MAPIMP double _MAPAPI mapSemanticDoubleValue(HOBJ info, long int number);

 // ��������� �������� ������������� �������������� �������
 // � ���� ������ �����
 // number  - ���������������� ����� ��������������
 // ���� �������� ��������� �� ����� ���� �������������
 // � ��������� ���� ��� - ���������� ����

_MAPIMP double _MAPAPI mapSemanticLongValue(HOBJ info, long int number);

 // ��������� �������� ������������� �������������� �������
 // � ���������� ��������������� ����
 // ��������: ��� ��������� "���������" �������� "5"
 // ��������� �� "�����"
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� �������������� (c 1),
 // place   - ����� ���������� ������,
 // maxsize - ������������ ����� ������ � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticValueName(HOBJ info, long int number,
                                              char *place, long int maxsize);
_MAPIMP long int _MAPAPI mapSemanticValueNameUnicode(HOBJ info, long int number,
                                                     WCHAR *place, long int maxsize);
_MAPIMP long int _MAPAPI mapSemanticValueNameUn(HOBJ info, long int number,
                                                WCHAR *place, long int maxsize);

 // ��������� �������� ������������� �������������� �������
 // � ���������� ��������������� ���� � ����������� �������
 // ��������� � ���������� ����
 // ��������: ��� ��������� "���������" �������� "5"
 // ��������� �� "�����";
 // �� ��������� "������" �������� "205,5" ���������
 // �� "205,5 �"
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� �������������� (c 1),
 // place   - ����� ���������� ������,
 // maxsize - ������������ ����� ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticValueFullName(HOBJ info,long int number,
                                                  char *place,long int maxsize);
_MAPIMP long int _MAPAPI mapSemanticValueFullNameUn(HOBJ info,long int number,
                                                    WCHAR *place,long int maxsize);

 // ��������� �������� ������������� �������������� �������
 // �������� ������������� � ���������� ���
 // info    - ������������� ������� ����� � ������
 // code    - ��� ��������������,��� ������� ������ ��������,
 // place   - ����� ���������� ������,
 // maxsize - ������������ ����� ������
 // number  - ���������������� ����� ���������� ��������,
 //  �� ����� ����������������� ������ �������������� !
 //  �������� : ��� code ����� 3-� � 6-� ��������������,
 //             �������������� ��� ��� number = 1 � 2,
 //             � ��� number = 3  - ��� �������� ����� ����.
 // ��� ������ ���������� ����,
 // ��� �������� ���������� - ���������������� �����
 // ��������� ��������������

_MAPIMP long int _MAPAPI mapSemanticCodeValue(HOBJ info, long int code,
                                              char *place, long int maxsize,
                                              long int number);

_MAPIMP long int _MAPAPI mapSemanticCodeValueUn(HOBJ info, long int code, WCHAR *place,
                                                long int maxsize, long int number);

 // ��������� �������� ������������� �������������� �������
 // � ���� ����� � ��������� ������ ������� ��������
 // info    - ������������� ������� ����� � ������
 // code    - ��� ��������������,��� ������� ������ ��������,
 // number  - ���������������� ����� ���������� ��������,
 //  �� ����� ����������������� ������ �������������� !
 //  �������� : ��� code ����� 3-� � 6-� ��������������,
 //             �������������� ��� ��� number = 1 � 2,
 //             � ��� number = 3  - ��� �������� ����� ����.
 // ���� �������� ��������� �� ����� ���� �������������
 // � ��������� ���� ��� �� ������� - ���������� ����

_MAPIMP double _MAPAPI mapSemanticCodeDoubleValue(HOBJ info, long int code,
                                                  long int number);

 // ��������� �������� ������������� �������������� �������
 // � ���������� ��������������� ����
 // info    - ������������� ������� ����� � ������
 // code    - ��� ��������������,��� ������� ������ ��������,
 // place   - ����� ���������� ������,
 // maxsize - ������������ ����� ������
 // number  - ���������������� ����� ���������� ��������,
 //  �� ����� ����������������� ������ �������������� !
 //  �������� : ��� code ����� 3-� � 6-� ��������������,
 //             �������������� ��� ��� number = 1 � 2,
 //             � ��� number = 3  - ��� �������� ����� ����.
 // ��� ������ ���������� ����,
 // ��� �������� ���������� - ���������������� �����
 // ��������� ��������������

_MAPIMP long int _MAPAPI mapSemanticCodeValueName(HOBJ info, long int code,
                                                  char *place, long int maxsize,
                                                  long int number);

_MAPIMP long int _MAPAPI mapSemanticCodeValueNameUn(HOBJ info, long int code,
                                                    WCHAR *place, long int maxsize,
                                                    long int number);

 // ��������� �������� ������������� �������������� �������
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� �������������� (c 1)
 // name - ����� ������ ��� ���������� �������
 // size - ������ ������ � ������
 // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapSemanticName(HOBJ info, long int number);
_MAPIMP long int _MAPAPI mapSemanticNameEx(HOBJ info, long int number,
                                           char *name, long int size);
_MAPIMP long int _MAPAPI mapSemanticNameUn(HOBJ info, long int number,
                                           WCHAR *name, long int size);

 // ��������� ��� ������������� �������������� �������
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� �������������� (c 1)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticCode(HOBJ info, long int number);

 // ��������� ���������������� ����� ���� �������������
 // �������������� ������� (c 1)
 // info    - ������������� ������� ����� � ������
 // code    - ��� ������������� �������������� � ��������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticNumber(HOBJ info, long int code);

 // ��������� ����� ������ ������ ��� ���������� ��������� � ������ �������
 // ���� ��������� � ���������� ���������������
 // ��� ������ ������ ������ ����� 255 �������� ��� ������� �� ���������
 // �������������, ���������� ����� ������ ����� 255 ��������
 // ������ �������������� ����� ���� ������ � ����������� �����������
 // �������������� (������� ��������� �������� ��� ������ �������,
 // ��. � RSCSEMANTICEX ���� Reply)
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� �������������� (c 1)
 // ���� ������ ����� ��������� � UNICODE, �� ������ ������ ����� �������� �� 2
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticStringLength(HOBJ info, long int number);

 // ��������� ����� ������ ��� ���������� ��������� � ������ �������
 // ���� ��������� � ���������� ���������������
 // ��� ������ ������ (mapAppendSemantic) ������ ����� 255 ��������
 // ��� ������� �� ��������� �������������, ���������� ����� ������
 // ����� 255 ��������.
 // ���� ��� �������������� ��������� ��������� ������ ������ ����� 255 ��������,
 // �� ������ ������� ����� ������ ����� mapAppendSemantic (��� ���������������
 // �������� ������� ������ ����� ������������� ���������).
 // ������ �������������� ����� ���� ������ � ����������� �����������
 // �������������� (������� ��������� �������� ��� ������ �������,
 // ��. � RSCSEMANTICEX ���� Reply)
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� �������������� (c 1)
 // value   - ����� ������, ���� ����� �������� ������ � ��������� ANSI
 // length  - ������������ ������ �������� ������ ��� ��������
 // ��� ������ ���������� ����, ����� - ����� ���������� ������

_MAPIMP long int _MAPAPI mapSemanticString(HOBJ info, long int number,
                                           char *value, long int length);

_MAPIMP long int _MAPAPI mapSemanticStringUnicode(HOBJ info, long int number,
                                                  WCHAR *value, long int length);

 // ��������� ��������� �������� ������������� ��������������
 // �� ���� ���������
 // info    - ������������� ������� ����� � ������
 // code    - ������� ��� ���������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticDescribeEx(HOBJ info, RSCSEMANTICEX * semtype,
                                               long int code);

 // ��������� ���������� ������� � ��������������
 // ��������� �� ���� ���������
 // info    - ������������� ������� ����� � ������
 // code - ��� ��������� (��������� ���� "TCODE")
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticClassificatorCount(HOBJ info, long int code);

 // ��������� �������� �������� �������������� ��
 // �������������� ��������� �� ���� �
 // ����������������� ������ � ��������������
 // info    - ������������� ������� ����� � ������
 // number - ���������������� ����� � ��������������(1,2,3...)
 // code - ��� ���������
 // name - ����� ������ ��� ���������� �������
 // size - ������ ������ � ������
 // ��� ������ ���������� ����� ������ ������,
 // ��� �������� ���������� - ����� ������

_MAPIMP const char* _MAPAPI mapSemanticClassificatorName(HOBJ info,long int code,
                                                         long int number);

_MAPIMP long int _MAPAPI mapSemanticClassificatorNameEx(HOBJ info, long int code,
                                                        long int number,
                                                        char *name, long int size);

_MAPIMP long int _MAPAPI mapSemanticClassificatorNameUn(HOBJ info,long int code,
                                                        long int number,
                                                        WCHAR *name, long int size);

 // ��������� ��� �������� �������������� ��
 // �������������� ��������� �� ���� �
 // ����������������� ������ � ��������������
 // info   - ������������� ������� ����� � ������
 // number - ���������������� ����� � ��������������(1,2,3...)
 // code   - ������� ��� ���������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSemanticClassificatorCode(HOBJ info, long int code,
                                                      long int number);


 // ************************************************************
 //                                                            *
 //      �������������� ��������� (���������) ��'����          *
 //                                                            *
 // ************************************************************

 // ��������� ������� �� ���������, ������� ��� ����� ����
 // ��������� ��� ������� �������
 // ��������� ������� ���������� � �������� �������������� ��������� ������� !
 // (��������� �������������� ����� ������������� ������ ���� ���)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapIsAvailableSemantic(HOBJ info);

 // ��������� ���������� ����� ��������, ������� ��� ����� ����
 // ��������� ��� ������� �������
 // ���������� � �������� �������������� ��������� ������� !
 // (��������� �������������� ����� ������������� ������ ���� ���)
 // info    - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAvailableSemanticCount(HOBJ info);

 // ��������� ������� ��� ��������� ��������� �� ������
 // �� ����������������� ������ ��������� ��������
 // ���������� � �������� �������������� ��������� ������� !
 // info    - ������������� ������� ����� � ������
 // number - ���������������� ����� ��������� �������� (1,2,3...)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAvailableSemanticCode(HOBJ info, int number);

 // ��������� ������ ������� ����� ��������� �������� �� ������
 // ���������� � �������� �������������� ��������� ������� !
 // info    - ������������� ������� ����� � ������
 // buffer  - ��������� �� ������� ������ ��� ���������� ������ ����� ��������
 // count   - ������������ ����� ��������� � ������ (������ ������ �������� �� 4)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAvailableSemanticList(HOBJ info, long int *buffer, long int count);

 // ��������� ������ ������� ����� ��������� ������������ �������� �� ������        // 15/10/15
 // ���������� � �������� �������������� ��������� ������� !
 // info    - ������������� ������� ����� � ������
 // buffer  - ��������� �� ������� ������ ��� ���������� ������ ����� ��������
 // count   - ������������ ����� ��������� � ������ (������ ������ �������� �� 4)
 // ��� ������ ���������� ����

 _MAPIMP long int _MAPAPI mapAvailableMustSemanticList(HOBJ info,long int * buffer, long int count);

 // �������� ����� �������������� � ��������� �������
 // info    - ������������� ������� ����� � ������
 // code    - ������� ��� ��������������
 // value   - ����� ������,���������� ����� ��������
 //           � ���������� ����, ����� � ��������� ������ ����� �����
 //           ������������ ������ ������ ����� "."
 // size    - ������������ ����� ������
 // (�������� �������� ����� ����������������� � �������� ���)
 // ���� ����� ��������� ���� � ��� �� ����������� - �������� ����������  // 10/07/06
 // ��� ������ ���������� ����,
 // ��� �������� ���������� - ���������������� �����
 // ��������� ��������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendSemantic(HOBJ info, long int code,
                                           const char *value,
                                           long int size);

 // �������� ����� �������������� � ��������� ������� � ���� UNICODE-������  // 24/03/11
 // info    - ������������� ������� ����� � ������
 // code    - ������� ��� ��������������
 // value   - ����� ������,���������� ����� ��������
 //           � ���������� ���� UNICODE UTF-16,
 // size    - ������������ ����� ������
 // ���� ����� �������� ��������� ������� �� 0x0001 �� 0x007E
 // ��� ��������� (0x0400 - 0x045F) � �� ����������
 // ����������� ������� Windows (OEM 866 ��� 1251), �� �����
 // ������������� ��������� � ANSI,
 // ����� ����� �������� ���������� � UTF-16
 // �������� �������� ����� ����������������� � �������� ���
 // ���� ����� ��������� ���� � ��� �� ����������� - �������� ����������
 // ��� ������ ���������� ����,
 // ��� �������� ���������� - ���������������� ����� ��������� ��������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendSemanticUnicode(HOBJ info, long int code,
                                                  const WCHAR *value, long int size);

 // ���������� ������� - �������� mapAppendSemanticUnicode

_MAPIMP long int _MAPAPI mapAppendSemanticUn(HOBJ info, long int code,
                                             const WCHAR *value, long int size);

 // �������� ����� �������������� � ��������� �������,
 // info    - ������������� ������� ����� � ������
 // code    - ������� ��� ��������������
 // value   - �������� � ���� ����� ������� ��������
 // ��� ������ ���������� ����,
 // ��� �������� ���������� - ���������������� �����
 // ��������� ��������������

_MAPIMP long int _MAPAPI mapAppendSemanticDouble(HOBJ info, long int code,
                                                 double value);

 // �������� ����� �������������� � ��������� �������,   // 12/12/12
 // info    - ������������� ������� ����� � ������
 // code    - ������� ��� ��������������
 // value   - �������� � ���� ������ �����
 // ��� ������ ���������� ����,
 // ��� �������� ���������� - ���������������� �����
 // ��������� ��������������

_MAPIMP long int _MAPAPI mapAppendSemanticLong(HOBJ info, long int code,
                                               long int value);

 // ������� ������������� �������������� �������
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� ��������������,
 //           ���� ����� ����� "-1", ��������� ��� ��������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteSemantic(HOBJ info, long int number);


 // �������� �������� ���� ������������� �������������� �������
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� ��������������
 // code    - ������� ��� ��������������
 // ��� ������ ���������� ����,
 // ����� - ���������� ��� ���������

_MAPIMP long int _MAPAPI mapSetSemanticCode(HOBJ info, long int number,
                                            long int code);

 // �������� �������� ������������� �������������� �������
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� ��������������,
 // place   - ����� ������, ���������� ����� ��������
 //           � ���������� ����; ��� ��������� ���� "�������������"
 //           ���������� ��� �������� � ���� ����� � ���������� ����,
 //           �� �� - ��� ���� "������ �� ������".
 // maxsize - ����� ������������ ������ (��� ��������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetSemanticValue(HOBJ info, long int number,
                                             const char *place, long int maxsize);

 // �������� �������� ������������� �������������� ������� � ��������� UNICODE
 // info    - ������������� ������� ����� � ������
 // number  - ���������������� ����� ��������������,
 // place   - ����� ������, ���������� ����� ��������
 //           � UNICODE. ��� ��������� ���� "�������������"
 //           ���������� ��� �������� � ���� ����� � ���������� ����,
 //           �� �� - ��� ���� "������ �� ������".
 // maxsize - ����� ������������ ������ (��� ��������)
 // ���� ����� �������� ��������� ������� �� 0x0001 �� 0x007E
 // ��� ��������� (0x0400 - 0x045F) � �� ����������
 // ����������� ������� Windows (OEM 866 ��� 1251), �� �����
 // ������������� ��������� � ANSI,
 // ����� ����� �������� ���������� � UTF-16
 // �������� �������� ����� ����������������� � �������� ���
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetSemanticValueUn(HOBJ info, long int number,
                                               const WCHAR *place, long int maxsize);

_MAPIMP long int _MAPAPI mapSetSemanticValueUnicode(HOBJ info, long int number,
                                                    const WCHAR *place, long int maxsize);

 // �������� �������� ������� ��� ��������� �������������
 // �������������
 // info    - ������������� ������� ����� � ������
 // ���� ��� ������� �� ��������� ���������� 0

_MAPIMP long int _MAPAPI mapRedefineObject(HOBJ info);

 // �������� �������� �������� ���� ������� ��� ����������
 // ��������� ��� ������� �������
 // ������ ������� ������������� ���������� ��� ���������� ������� (mapCommitObject)
 // info    - ������������� ������� ����� � ������
 // mode - ������� ���������� ��������� � �������:
 // 0 - ���������� ������ �������, 1 - ���������� ���������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdateSemanticByFormula(HOBJ info, long int mode);

 // ***********************************************************************
 //      �������������� ��������� (���������) ��'���� -                   *
 //  �������� ���������� ������ �� ��������������� ������                 *
 //      � ������ �������� ��������� �������                              *
 // ������ ������: ����� %# ���� ����� ���������, �� ��� � []- ��������,  *
 // ������� ����� ��������� � ������ ��� ���������� ��������� ���������   *
 // ��������� ����� � ������������ �����.                                 *
 // ������:������� ������ - "��� N %#45[���] ����. %#3[�� ���������]"     *
 //     ��������� �� ��������� ��������� ��� ����������� �������          *
 //     "��� N 5 ����. �� ���������" ��� "��� N 7-a ����. �����"          *
 //      ���  "��� N ��� ����. �� ���������"                              *
 // ***********************************************************************

 // ������ ���������������  ������ �� �����
 // value - ������� ������,
 // ������� ������ �� ����� 256.
 // ��� �������� �������������� ��� ������ - ���������� 0,
 // ����� ������������� ������� � ������ (HFORMULA)
 // ��� ������� ����������� � ������ �� �������������
 // �������������� HFORMULA ��������� ����� ������� mapFreeFormula()

_MAPIMP HFORMULA _MAPAPI mapTakeStringToPieces(const char *value);

_MAPIMP HFORMULA _MAPAPI mapTakeStringToPiecesUn(const WCHAR *value);

 // ������� ���������� ������ �� �������������e HFORMULA
 // � ������ �������� �������
 // info - ������������� ������� ����� � ������
 // string - ������ ��� ������ ����������
 // size   - ������ ������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapBuildFormulaString(HFORMULA formula, HOBJ info,
                                               char *string, long int size);

_MAPIMP long int _MAPAPI mapBuildFormulaStringUn(HFORMULA formula, HOBJ info,
                                                 WCHAR *string, long int size);

 // ����������  ������������� HFORMULA
_MAPIMP void _MAPAPI mapFreeFormula(HFORMULA formula);

 // ************************************************************
 //                                                            *
 //         ������ ������� (���������) ��'����                 *
 //                                                            *
 // ************************************************************

 // ��������� ����������� �������/����������
 // info   - ������������� ������� ����� � ������
 // number - ����� ���������� (��� ������� - ����� ����)
 // ����������:  0 - �� �������, �� 0 - �������

_MAPIMP long int _MAPAPI mapGetExclusiveSubject(HOBJ info, long int number);

 // ������ ��������� ������� (� ������)
 // info   - ������������� ������� ����� � ������
 // dframe - �������� ������� ������� � ������ � ������� ���������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapObjectFrame(HOBJ info, MAPDFRAME *dframe);

 // ������/�������� ��������� ����������� ����� ������� (� ������)
 // info   - ������������� ������� ����� � ������
 // dframe - �������� ����������� ������� � ������
 // force  - ������� ��������������� ��������� ��������� (���������� ����������,
 //          ���� ������ ��������������, �� �� ������� �� �����)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapObjectViewFrameEx(HOBJ info, MAPDFRAME *dframe,
                                              long int force);
_MAPIMP long int _MAPAPI mapObjectViewFrame(HOBJ info, MAPDFRAME *dframe);

 // ������ ����� ����� ������� �������/����������
 // info    - ������������� ������� ����� � ������
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPointCount(HOBJ info, long int subject);

 // ������ ����� ��������� ������ (����������� + 1)
 // info    - ������������� ������� ����� � ������
 // ���� ����������� ��� - ���������� 1 (������ ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPolyCount(HOBJ info);

 // ��������� ���������� ����� � ������� ��������� ���������
 // number - ����� ����� (���������� � 1)
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetPlanePoint(HOBJ info, DOUBLEPOINT *point,
                                          long int number, long int subject);

 // ������ ��������� ����� � ������ � ������� ��������� �����
 // number - ����� �����
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetMapPlanePoint(HOBJ info, DOUBLEPOINT *point,
                                             long int number, long int subject);

 // ������ ���������� ����� ������� � ������������� �������
 // � ������ �� ���������
 // info    - ������������� ������� ����� � ������
 // number - ����� ����� (���������� � 1)
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ������� ����������� ����� ����� mapGetPlanePoint()
 // ��� ������ ���������� ����

_MAPIMP double _MAPAPI mapXPlane(HOBJ info, long int number = 1,
                                 long int subject = 0);

_MAPIMP long int _MAPAPI mapXPlaneEx(HOBJ info, long int number,
                                     long int subject, double *x);

_MAPIMP double _MAPAPI mapYPlane(HOBJ info, long int number = 1,
                                 long int subject = 0);

_MAPIMP long int _MAPAPI mapYPlaneEx(HOBJ info, long int number,
                                     long int subject, double *y);

_MAPIMP double _MAPAPI mapHPlane(HOBJ info, long int number = 1,
                                 long int subject = 0);
_MAPIMP long int _MAPAPI mapHPlaneEx(HOBJ info, long int number,
                                     long int subject, double *h);

 // ��������� ������������� ���������� ����� � �������� � ������� ���������
 // number - ����� ����� (���������� � 1)
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetGeoPoint(HOBJ info, DOUBLEPOINT *point,
                                        long int number, long int subject);

 // ��������� ������������� ���������� ����� � �������� �� ���������� WGS-84
 // number - ����� ����� (���������� � 1)
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetGeoPointWGS84(HOBJ info, DOUBLEPOINT *point,
                                             long int number, long int subject);

_MAPIMP long int _MAPAPI mapGetGeoPointWGS843D(HOBJ info, DOUBLEPOINT *point,
                                               double *heigth, long int number,
                                               long int subject);
                                          
 // ������ ������������� ��������� ����� �������
 // � �������� (BGeo - ������, LGeo - �������)
 // number - ����� ����� (���������� � 1)
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ������� ����������� ����� ����� mapGetGeoPoint()
 // ��� ������ ���������� ����

_MAPIMP double _MAPAPI mapBGeo(HOBJ info, long int number  = 1,
                                          long int subject = 0);

_MAPIMP double _MAPAPI mapLGeo(HOBJ info, long int number  = 1,
                                          long int subject = 0);



 // ��������� ����� �� ������ 3-�������� �������
 // info    - ������������� ������� ����� � ������
 // ���� ��, ���������� ��������� ��������

_MAPIMP long int _MAPAPI mapIsObject3D(HOBJ info);

 // ��������� �������� �� ������ ���������������
 // ������������� - ��� ��������� ������, � �������� ��������� ����������
 // ����� ���� ��� ������ �������
 // ��� �������� ������� �������������� ������� ������� �����������
 // ����� ����������� � ������� ��������� �������, � �������
 // ���������� ����������� - ����������
 // info    - ������������� ������� ����� � ������
 // ���� ��, ���������� ��������� ��������

_MAPIMP long int _MAPAPI mapIsMultiPolygon(HOBJ info);

 // ����������\�������� ������� ��������������                       // 31/05/16
 // info  - ������������� ������� ����� � ������
 // multi - ������� ��������������
 // isautoset - ������� �������������� ����������� ����� ���������� (����������)
 // ��� ������ ��������� �������� �������������� ����� ����������� ��������������
 // ����������� ����� ���������� ���������� �� ������ ����� ������� ���������� -
 // ����� ���������� ����� ����������� � ������
 // ���� ��������� ������ ���������� ��������� ������� �������, ��
 // ������� �������������� ����� ��������������� ����� ���������� ��������
 // ������� � ���� ����������� ��� �������������� �����������,
 // ����� ����������� ��������� ������ ����������� � ������� mapSetSubjectMultiFlag
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetMultiPolygonEx(HOBJ info, long int multi, long int isautoset = 1);
_MAPIMP long int _MAPAPI mapSetMultiPolygon(HOBJ info, long int multi);

 // ��������� ���� ���������� ���������� ��� �������                 // 31/05/16
 // subject - ����� ����������, ���� 0 - ������ ��� �������
 // ��� ������� ����������� ���������� ������������� �������� (-1),
 // ��� ���������� ����������� ���������� ����� �������� ���������� (c 0), � �������
 // ������ ������ ���������
 // ��� ���������� �������� ���������� ����

_MAPIMP long int _MAPAPI mapGetSubjectMultiFlag(HOBJ info, long int subject);

 // ���������� ���� ���������� ���������� ��� �������                // 31/05/16
 // subject - ����� ����������, ���� 0 - ������ ��� �������
 // flag    - ������� ���������� (����������) ����������
 // ��� ������� ����������� ��������������� ������������� �������� (-1),
 // ��� ���������� ����������� ��������������� ����� �������� ���������� (c 0), � �������
 // ������ ������ ���������
 // ��� ���������� �������� ���������� ����

_MAPIMP long int _MAPAPI mapSetSubjectMultiFlag(HOBJ info, long int subject, long int flag);

 // ��������� ��� ������ � ������� ����������
 // ������� ������ ����� ���� � �� ������
 // (0 - ����������, ����� - �������������)

_MAPIMP long int _MAPAPI mapGetHeightType(HOBJ info);

 // ���������� ��� ������ � ������� ����������
 // �������� ������ ����� ���� ����������� �������
 // (0 - ����������, ����� - �������������)
 // ������� � ������������� ������� �� ������ �� ���������� ������� �����
 // �������� - ������������ �������� � ���������

_MAPIMP long int _MAPAPI mapSetHeightType(HOBJ info, long int type);

 // ���������� ����� �������
 // info  - ������������� ������� ����� � ������
 // x, y  - ����������� ���������� ������ ������� � ������ � ������� ���������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetObjectCenter(HMAP hmap, HOBJ info, double *x, double *y);

 // ��������� - ������������ �� ����� ����� ������� ��� ������ � ���������� �������
 // ����� ����� ����������� �� 32-��������� ��������� ��� ������ � ������� ������
 // ������������ �������� ��������� ����
 // � ���� ������ ������������� ����� ������������� MAPAPI-������� �� ��������

_MAPIMP long int _MAPAPI mapIsCommonBufferActive();

 // ************************************************************
 //                                                            *
 //      �������������� ������� (���������) ��'����            *
 //                                                            *
 // ************************************************************

 // �������� � ����� ������� ������� �����
 // info    - ������������� ������� ����� � ������
 // x,y     - ���������� ����� � ������
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // �������� ��������� ������ � ������ �� ���������
 // ��� ��������� ���������� � ���������� �����
 // ��������� ������� SetHPlane(...)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendPointPlane(HOBJ info, double x, double y,
                                             long int subject = 0);

 // �������� � ����� ������� ������� �����
 // info    - ������������� ������� ����� � ������
 // x,y     - ���������� ����� � ������
 // h       - ������ (���������� ��� �������������) � ������
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ������������ ��������� mapGetHeightType � mapSetHeightType
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendPointPlane3D(HOBJ info, double x, double y,
                                               double h, long int subject = 0);

 // ������� �������� ����� �������
 // info    - ������������� ������� ����� � ������
 // number  - ����� ����� (� 1)
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeletePointPlane(HOBJ info, long int number,
                                             long int subject = 0);
_MAPIMP long int _MAPAPI mapDeletePoint(HOBJ info, long int number,
                                        long int subject = 0);

 // �������� �� ������� ���������� �����
 // precision - �������� ����������� �������� ��������� � ������ �� ���������
 // height    - ������� ����� ���������� ������� (� ���� ������ ��� ����������
 //             ����� � ������ ������� ��������� �������)
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDeleteEqualPoint(HOBJ info, double precision, long int height);

 // ������� �� �������/���������� ������� � ����� number1 �� ����� number2
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ������� ���������� ����� ��������� �� ����������
 // ��� �������� ���� ����� �������/���������� ��������� ������ �������,
 // ������/��������� �� ���������

_MAPIMP long int _MAPAPI mapDeletePartObject(HOBJ info, long int number1,
                                             long int number2, long int subject = 0);

 // �������� � ������� ������� �����
 // info    - ������������� ������� ����� � ������
 // x,y     - ���������� ����� � ������
 // number  - ����� ����� �� ������� ����� ��������� ����� �����
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // �������� ��������� ������ � ������ �� ���������
 // ��� �������� ���������� � ���������� �����
 // ��������� ������� mapSetHPlane(...)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapInsertPointPlane(HOBJ info, double x, double y,
                                             long int number, long int subject = 0);

 // �������� ���������� ����� �������
 // �������� ��������� ������ � ������ �� ���������
 // info    - ������������� ������� ����� � ������
 // x,y     - ���������� ����� � ������
 // number  - ����� ����� (c 1)
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdatePointPlane(HOBJ info, double x, double y,
                                             long int number, long int subject = 0);

_MAPIMP long int _MAPAPI mapUpdatePointPlane3D(HOBJ info, double x, double y, double h,
                                               long int number, long int subject = 0);

 // �������� � ����� ������� ������� �����
 // info    - ������������� ������� ����� � ������
 // b,l     - ���������� ����� � �������� � ������� ��������� ���������
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // �������� ��������� ������ ��������������� ������� ���������,
 // �������� � ���������� �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendPointGeo(HOBJ info, double b, double l,
                                           long int subject = 0);

 // �������� � ����� ������� ������� �����
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // �������� ��������� ������ � �������� �� ���������� WGS-84
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendPointGeoWGS84(HOBJ info, double b, double l,
                                                long int subject);

_MAPIMP long int _MAPAPI mapAppendPointGeoWGS843D(HOBJ info, double b, double l, double h,
                                                  long int subject);

 // �������� � ������� ������� �����
 // info    - ������������� ������� ����� � ������
 // b,l     - ���������� ����� � ��������
 // number - ����� ����� �� ������� ����� ��������� ����� �����
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // �������� ��������� ������ ��������������� ������� ���������,
 // �������� � ���������� �����
 // ��� ��������� ���������� � ���������� �����
 // ��������� ������� HPlane(...)
 // ��� ������ ���������� ����

 _MAPIMP long int _MAPAPI mapInsertPointGeo(HOBJ info, double b, double l,
                                            long int number, long int subject = 0);

 // �������� ���������� ����� �������
 // info    - ������������� ������� ����� � ������
 // b,l     - ���������� ����� � ��������
 // number  - ����� ����������� �����
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // �������� ��������� ������ ��������������� ������� ���������,
 // �������� � ���������� �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdatePointGeo(HOBJ info, double b, double l,
                                           long int number, long int subject = 0);

_MAPIMP long int _MAPAPI mapUpdatePointGeo3D(HOBJ info, double b, double l,
                                             double h, long int number,
                                             long int subject = 0);

 // �������� ���������� ����� ����� ������� � ������� ������� �
 // � ���� �������� �����, ������� ����� �����
 // ��������� ����������� ����� ������ mapCommitObject()
 // ��� mapCommitWithPlace()
 // �������� ��������� ������ � ������ �� ���������
 // info    - ������������� ������� ����� � ������
 // x,y,h   - ���������� ����� � ������
 // number  - ����� ����� (c 1)
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdatePointPlaneInMap(HOBJ info, double x, double y,
                                                  long int number,
                                                  long int subject = 0);

_MAPIMP long int _MAPAPI mapUpdatePointPlane3DInMap(HOBJ info, double x, double y,
                                                    double h, long int number,
                                                    long int subject = 0);

 // �������� ���������� ����� ����� ������� � ������� ������� �
 // � ���� �������� ������ ����,  ������� ����� �����
 // ��������� ����������� ����� ������ mapCommitObject()
 // ��� mapCommitWithPlace()
 // �������� ��������� ������ � ������ �� ���������
 // info    - ������������� ������� ����� � ������
 // x,y,h   - ���������� ����� � ������
 // number  - ����� �����
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdatePointPlaneInLayer(HOBJ info, double x, double y,
                                                    long int number,
                                                    long int subject = 0);

_MAPIMP long int _MAPAPI mapUpdatePointPlane3DInLayer(HOBJ info, double x, double y,
                                                      double h, long int number,
                                                      long int subject = 0);

 // �������������� ���������� ����� �������/����������
 // � ������������� ������� � ������ �� ���������
 // info    - ������������� ������� ����� � ������
 // x,y,h   - ���������� ����� � ������
 // number  - ����� ����� (c 1)
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetXPlane(HOBJ info, double x, long int number,
                                      long int subject = 0);

_MAPIMP long int _MAPAPI mapSetYPlane(HOBJ info, double y, long int number,
                                      long int subject = 0);

_MAPIMP long int _MAPAPI mapSetHPlane(HOBJ info, double h, long int number,
                                      long int subject = 0);

 // ������� ���������� ���������� � ������ �������
 // � ����� ������ ����������� ���������� ���������� � ������� ������ �����
 // info    - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCreateSubject(HOBJ info);

 // ������� ��������� � ������ �������
 // info   - ������������� ������� ����� � ������
 // number - ����� ���������� ���������� (� 1),
 // ���� ����� (-1), �� ��������� ��� ������� ������� ������ � ������������
 // ������� ���������� ������ ����� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteSubject(HOBJ info, long int number);

 // �������� ��� ���������� ������� ������� �� ��������
 // �������� (delta) � ������
 // info   - ������������� ������� ����� � ������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapRelocateObjectPlane(HOBJ info,
                                                DOUBLEPOINT *delta);

 // �������� ��� ���������� ������� ������� �� ��������
 // �������� (delta) � ������������ � ���������� place
 // hmap  - ������������� �������� ������
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapRelocateObject(HMAP hmap, HOBJ info,
                                           DOUBLEPOINT * delta,
                                           long int place/* = PP_MAP*/);

 // �������� ����������� ���������� ����������
 // info  - ������������� ������� ����� � ������
 // number - ����� ���������� (� 0),
 // ��� ������ ���������� ����, ����� - ����� ��������
 // (OD_RIGHT,OD_LEFT,... - ��. Maptype.h)

_MAPIMP long int _MAPAPI mapChangeSubjectDirect(HOBJ info, long int number);

 // �������� ����������� ���������� �������
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� ����, ����� - ����� ��������
 // (OD_RIGHT,OD_LEFT,... - ��. Maptype.h)

_MAPIMP long int _MAPAPI mapChangeObjectDirect(HOBJ info);

 // ��������������� ������ (���������), ��������� ������ �������� �����
 // number - ����� �����
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetFirstPoint(HOBJ info, long int number,
                                          long int subject);

 // �������� ���������� �������
 // info  - ������������� ������� ����� � ������
 // precision - �������� � ������
 // �������: 1. ������� ����� �������;
 //          2. ����������� ���������� < 2 �����;
 //          3. ��������� ���������� < 4 �����;
 //          4. ����� �������, ������� � �������� ������� ������
 //             �� ���������� precision �� ������.
 // ������ �� ������� ������� !!!
 // ���������� ����� ����� ����� �������
 // ��� ������� ����������:
 //    0 - ������ ���������
 //   -1 - ������ ������� �� ����� �����
 //   -2 - ������ ������� �� ���� ���������� �����
 //   -3 - ����� ����� ���������� ������� ������� ����� 3
 //  -10 - ����� ����� ������� ��������� ����� ������ �������

_MAPIMP long int _MAPAPI mapLinearFilter(HOBJ info,
                                         double precision/* = DELTANULL*/);

 // ���������� ������� � ������ �������������� ������ � ���������
 // ��������� ����� �����, �������� ����������� ������
 // (����������� � �������� �������, ������� ����� �����;
 //  �������� ����� ����� �� �����������)
 // hMap      - ������������� �������� ������
 // info      - ����������� ������
 // precision - �������� � ������ �� ���������
 //             (����������� ���������� �� ����� �� ������,
 //              ����������� ���������� � ��������� �����)
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGeneralFilter(HMAP hMap, HOBJ hobj,
                                          double precision/* = DELTANULL*/);

 // ���������� ���� �������� ������ ����� ����� � ������
 // �������������� ������ � ��������� ��������� ���� �� �����
 // ��� �� ����� (����������� � �������� �������, ������� ����� �����;
 // �������� ����� ����� �� �����������)
 // hMap      - ������������� �������� ������
 // hSite     - ������������� �������������� �����
 // list      - ����� �����
 // precision - �������� � ������ �� ���������
 //             (����������� ���������� �� ����� �� ������,
 //              ����������� ���������� � ��������� �����)
 // hwnd      - ������������� ����,������� ����� ����������
 //             (��� ������ ��������� ���������� ������������� � ����)
 // ������� �������� ��������� 0x590:
 // wparm : ������� ���������,
 // lparm : ���������� ������������ ��������.
 //   ����� ���������� = mapGetObjectCount(hMap, list)     - ��� �������� �����
 //   ����� ���������� = mapGetSiteObjectCount(hMap, hSit) - ��� ����������������
 // ��� ���������� �������� ������� ����� 0x590
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGeneralFilterInMap(HMAP hMap, HSITE hSite,
                                               long int list,
                                               double precision/* = DELTANULL*/,
                                               HWND hwnd);

 // �������� ������� - ����������� ������� � ���� ��� �����������
 // ��� ������, ������� �������� ������
 // ����� ������ � ��������� ����� �������(����������) � ��� ��
 // ���������� (���������) ���� �������, ����������� ����� �������
 // (������� ��������� �������/����������).
 // info  - �������� ������� �������, �� �������� �������� ������
 // cashion   - �������� ������� ����������
 //             ����� ������� ����� ������� (1<= cashion <= 50)
 //             (������� ��������� �������/����������).
 //             ��� ������ cashion, ��� ������ ����������� ����
 // smooth    - ��������� ������ �������
 //             (����� ����� ����� ������ ������� smooth >= 3).
 //             ��� ������ smooth,��� ����� ��������� �����
 // precision - ����� (��������) ��� ���������� �����, ��� ���������������
 //             ����������� �������� ���������� �������� "-1".
 // ���� �������� ������ ���� 3-� ���������� (������),�� � �������
 // ����� ���� ������ (������������ ��� ����� �����).
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCashionSpline(HOBJ info, long int cashion,
                                          long int smooth,
                                          double precision/* = -1*/);

 // �������� ������� - ����������� ����������
 // ��� ������, ������� �������� ������
 // ����� ������ � ��������� ����� ���������� � ��� ��
 // ���������� (���������) ���� �������, ����������� ����� �������
 // (������� ��������� ����������).
 // info  - �������� ������� �������, �� ���������� �������� �������� ������
 // subject - ����� ��������������� ���������� (0,1,2...)
 // cashion   - �������� ������� ����������
 //             ����� ������� ����� ������� (1<= cashion <= 50)
 //             (������� ��������� ����������).
 //             ��� ������ cashion, ��� ������ ����������� ����
 // smooth    - ��������� ������ �������
 //             (����� ����� ����� ������ ���������� smooth >= 3).
 //             ��� ������ smooth,��� ����� ��������� �����
 // precision - ����� (��������) ��� ���������� �����, ��� ���������������
 //             ����������� �������� ���������� �������� "-1".
 // ���� �������� ��������� ���� 3-� ���������� (������),�� � �������
 // ����� ���� ������

_MAPIMP long int _MAPAPI mapCashionSplineSubject(HOBJ info, long int subject,
                                                 long int cashion,
                                                 long int smooth,
                                                 double precision/* = -1*/);

 // �������� ������� - �������� ������� � ���� ��� �����������
 // ��� ������, ������� �������� ����� ��� ����� ��������� �������
 // (������� ��������� �������) � ������� ���. �������� ������
 // ��� �� ������ � ������.
 // info  - �������� ������� �������, �� �������� �������� ������
 // press     - ������������ ���������
 //             ������ ������ ������� �� �������
 //             � ��������� �� ����� ������� ( >= 5 ).
 //             ��� ������ press, ��� ����� ������ �����
 //             ��������� �� ������� ������� (������� ���������
 //             �������/����������).
 // smooth    - ��������� ������ �������
 //             (����� ����� ����� ������ ������� smooth >= 3).
 //             ��� ������ smooth,��� ����� ��������� �����
 // precision - ����� (��������) ��� ���������� �����, ��� ���������������
 //             ����������� �������� ���������� �������� "-1".
 // ���� �������� ������ ���� 3-� ���������� (������),�� � �������
 // ����� ���� ������ (������������ ��� ����� �����).
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapBendSpline(HOBJ info, long int press,
                                       long int smooth,
                                       double precision/* = -1*/);

 // �������� ������� - �������� ����������
 // ��� ������, ������� ��������
 // ����� ��� ����� ��������� ���������� � ������� ���.
 // �������� ������ ��� �� ������ � ������.
 // info  - �������� ������� �������, �� �������� �������� ������
 // subject - ����� ��������������� ���������� (0,1,2...)
 // press     - ������������ ���������
 //             ������ ������ ������� �� �������
 //             � ��������� �� ����� ������� ( >= 5 ).
 //             ��� ������ press, ��� ����� ������ �����
 //             ��������� �� ������� ������� (������� ���������
 //             �������/����������).
 // smooth    - ��������� ������ �������
 //             (����� ����� ����� ������ ������� smooth >= 3).
 //             ��� ������ smooth,��� ����� ��������� �����
 // precision - ����� (��������) ��� ���������� �����
 // ���� �������� ��������� ���� 3-� ���������� (������),�� � �������
 // ����� ���� ������

_MAPIMP long int _MAPAPI mapBendSplineSubject(HOBJ info, int subject,
                                              long int press, long int smooth,
                                              double precision/* = -1*/);

// ����������� ������� � ������ �������������� ������ � ���������
// ��������� ����� �����, �������� ����������� ������
// hMap       - ������������� �������� ������
// info       - ����������� ������
// press      - ������������ ��������� ������ ������ ������� �� �������
//              � ��������� �� ����� ������� (>= 5), ��� ������ press,
//              ��� ������ ������ ����� ���������� �� ��������� �������
// smooth     - ��������� ������ ������� (>= 3) ����� ����� ����� ������ �������,
//              ��� ������ smooth, ��� ����� ������� ����� ������
// adjustdist - ������ ������������ - ������������ ����������, ��� ������� ��� ��������
//              ����� ��������� �������������� �� ����� �����
// filterprec - ������� ���������� (����������� ���������� �� ����� �� ������,
//              ����������� ���������� � ��������� �����)
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGeneralBendSpline(HMAP hMap, HOBJ info, long int press, long int smooth,
                                              double adjustdist, double filterprec);

 // ���������� ������������ ������
 // points - ������ ����� (���� �� ���������)
 // count  - ���������� �����
 // smooth - ������� ����������� (0..1; 0 - ������ �����, 1 - ���������� ������)
 // ��� ������ ���������� ����
 
_MAPIMP long int _MAPAPI mapSmoothingSpline1(double *points, int count,
                                             double smooth);

 // ���������� ������������ ������
 // points - ������ ����� (x, y)
 // count  - ���������� �����
 // smooth - ������� ����������� (0..1; 0 - ������ �����, 1 - ���������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSmoothingSpline2(DOUBLEPOINT *points, int count,
                                             double smooth);

 // �ң������� ������������ ������
 // points - ������ ����� (x, y, h)
 // count  - ���������� �����
 // smooth - ������� ����������� (0..1; 0 - ������ �����, 1 - ���������� ������)
 // ��� ������ ���������� ����
 
_MAPIMP long int _MAPAPI mapSmoothingSpline3(XYHDOUBLE *points, int count,
                                             double smooth);

 // C����������� ������ (2-� ��� 3-� ������ � ����������� �� ������� ������)
 // info    - ������������ ������
 // subject - ������������ ���������
 // smooth  - ������� ����������� (0..1; 0 - ������ �����, 1 - ���������� ������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSmoothingSplineSubject(HOBJ info, long int subject,
                                                   double smooth);

 // C����������� ������ (2-� ��� 3-� ������ � ����������� �� ������� ������)
 // info   - ������������ ������
 // smooth - ������� ����������� (0..1; 0 - ������ �����, 1 - ���������� ������)
 // ��� ������ ���������� ����
 
_MAPIMP long int _MAPAPI mapSmoothingSplineObject(HOBJ info, double smooth);

 // ��������� ���� ��������� ������� � �������
 // � ����� point2 (� ������ �� ���������)
 // ����� point1 � point3 �������� ��� �����������
 // ����������� (� ������ �� ���������)
 // hmap   - ������������� �������� ������
 // info   - ������������� ������� ����� � ������
 // radius - � ������ �� ���������
 // ������� �������� � info
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapCreateArc(HMAP hmap, HOBJ info, DOUBLEPOINT *point1,
                                      DOUBLEPOINT *point2, DOUBLEPOINT *point3,
                                      double radius);

 // ���������� ���� ������ ������� ������� ��� ����������
 // ������� ������ ���� � ������� ������ (������ ������ � ��������
 // � �������� ��������� � �������� ������ ����� ����)
 // ���������� �������, ������������ ������
 //  if (mapGetExclusiveSubject(info, subject))
 //   return mapInsideZoneObjectEx(radius, info, subject, form, 0.001 * Map->Scale(), 3.);
 // return mapZoneObjectEx(radius, info, subject, form, 0.001 * Map->Scale(), 3., 3);
 // radius  - ������ ����������� ���� (� ������ �� ���������)
 // info    - ������������� ����� �������, �� ������� �������� �������� ����.
 //           � ���� ������ ����� �������� ������� ����������� ����, �������
 //           ����� ����� ��������� ��� ����� ��������� ������
 // subject - ����� ����������, ������ �������� ������ ����
 //           0 - ���� �������� ��� ��������� ������� ������� (��� ����� �����������)
 // form    - ����� ���� ����
 //           ��� ����������� ��������:
 //           0 - ���� �����
 //           1 - ������������� ����
 //           ��� ��������� ��������:
 //           0 - "���������" ����
 //           1 - ������ ����
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapZoneObject(double radius,
                                       HOBJ info, long int subject/* = 0*/,
                                       long int form/* = 0*/);

 // ���������� ���� ������ ����������
 // radius  - ������ ����������� ���� (� ������ �� ���������)
 // info    - ������������� ����� �������, �� ������� �������� �������� ����.
 //           � ���� ������ ����� �������� ������� ����������� ����.
 // subject - ����� ����������, ������ �������� �������� ����
 // form    - ��� ���� 0 - ������, 1 - ������������
 // arcdist - ���������� ����� ������� �� ���� (� ������ �� ���������)
 //           ������������� radius / 15
 // cornerfactor - ����������� ��� ������� ������������ ����� ���� (������������� 3)
 // ���� ����� ������ ��� ����, �� ������� ���� ���������� �� ���������� �� ���� ��
 // ������� radius*cornerfactor ��� ���������� ������� �����
 // side    - ����������� ���������� ���� (1-������, 2-�����, 3-� ����� ������)
 // ��� ������ ���������� ����
 
_MAPIMP long int _MAPAPI mapZoneObjectEx(double radius, HOBJ info, long int subject,
                                         long int form, double arcdist, double cornerfactor, 
                                         long int side);

 // ���������� ���� �������/������ ����������
 // ������� ������ ���� � ������� ������ (������ ������ � ��������
 // � �������� ��������� � �������� ������ ����� ����)
 // ���������� �������, ������������� ������
 // mapInsideZoneObjectEx(radius, info, subject, 0, 0.001 * Map->Scale(), 3.)
 // radius    - ������ ����������� ����
 //    ������������� �������� - ������ �������
 //    ������������� �������� - ������� �������
 // info      - ������� �������; ���� �������� ������
 // subject   - ����� ����������, ������ �������� ������ ����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapInsideZoneObject(double radius,
                                             HOBJ info, long int subject);

 // ���������� ���� �������/������ ����������
 // radius  - ������ ����������� ���� (� ������ �� ���������)
 //           ������������� �������� - ������ �������
 //           ������������� �������� - ������� �������
 // info    - ������������� ����� �������, �� ������� �������� �������� ����.
 //           � ���� ������ ����� �������� ������� ����������� ����.
 // subject - ����� ����������, ������ �������� �������� ����
 // form    - ��� ���� 0 - ������, 1 - ������������
 // arcdist - ���������� ����� ������� �� ���� (� ������ �� ���������)
 //           ������������� radius / 15
 // cornerfactor - ����������� ��� ������� ������������ ����� ���� (������������� 3)
 // ���� ��� ���� ������, �� ������� ���� ���������� �� ���������� �� ���� ��
 // ������� radius*cornerfactor ��� ���������� ������� �����
 // ��� ������ ���������� ����
 
_MAPIMP long int _MAPAPI mapInsideZoneObjectEx(double radius, HOBJ info, long int subject,
                                               long int form, double arcdist, double cornerfactor);

 // ���������� �������� ���� ������ ������� / ����������
 // (������ �� ������� �� ����������� ����������)
 // radius    - ������ ����������� ���� (� ������ �� ���������)
 // info - ������� �������, �� �������� �������� ����
 // subject - ����� ����������, ������ �������� ������ ����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapHalfZoneObject(double radius,
                                           HOBJ info, long int subject/* = 0*/);


// ���������� ���� ������ ��������� ������� ��������� ������������
// ���������� �������, ������������� ������
// return mapZoneObjectEx(radius, info, 0, 1, 0.001 * mapGetMapScale(hmap), 3., 3);
// ������� ���� "������" (��� ����� �����������)
// radius - ������ ����������� ���� (� ������ �� ���������)
// info   - ������� �������, �� �������� �������� ����.
//          �������� ������ ������� �� �����, ������ ������ ����� �������� ����.
//          ��������� ���� ������������ � ����
// � info ������������ ��������� ������ - ����
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapZoneLineObject(HMAP hmap, HOBJ info, double radius);

 // ��������  ������� ������ � ��� ��� ���������� ���
 // ���������� ��� ��������� �������
 // info  - ������������� ������� ����� � ������
 // delta - ����� ��������� � �� �� �����
 // ���� ���������� ����� ������ � ��������� ������ ������ delta, ��
 // ������ ��������� ����� ����� ������
 // ���� ���������� ����� ������ � ��������� ������ ������ delta, ��
 // ����� ��������� ����� ��������� ������
 // ������� - 1 - ���������� ����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAbrige(HOBJ info, double delta);

 // ��������� ������� ������� �� ������������� �������� ����� (��, ��)
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

 _MAPIMP long int _MAPAPI mapRoundObject(HOBJ info);                 // 07/06/16

 // ���������� ����������
 // first - ���������� ������ ����� � ��������
 // second - ���������� ������ ����� � ��������
 // array - ����� ������� ��������� ����������� ����������,
 //         ������ ������� ����� count
 // count - ���������� ����� ��� ���������� ����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapOrthodrome(DOUBLEPOINT *first, DOUBLEPOINT *second,
                                       DOUBLEPOINT *array, long int count);

 // ���������� ���������� (���� �� ����������� �����, �������� ���������� ����������)
 // ����� ��������� �������
 // info   - ������������� ������� ����� � ������
 // first  - ���������� ������ ����� � �������� �� ������� ���������� ��������� (SetDocProjection)
 // second - ���������� ������ ����� � ��������
 // ��� ������� ����������� ����� ���� ����������� � ����� �� ����� 0,5 �������,
 // ��� ����� ���������� - �� ���� 10 ����������, ��� ������������ �����������
 // ���� � ����� � ��������� ������������ 1 ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapOrthodromeObject(HOBJ info, DOUBLEPOINT *first, DOUBLEPOINT *second);

 // ���������� �����������
 // first - ���������� ������ ����� � ��������
 // second - ���������� ������ ����� � ��������
 // array - ����� ������� ��������� ����������� �����������,
 //         ������ ������� ����� count
 // count - ���������� ����� ��� ���������� �����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapLoxodrome(DOUBLEPOINT *first, DOUBLEPOINT *second,
                                      DOUBLEPOINT *array, long int count);

 // ���������� ���� ��������� �� ������� ����� � ���� ���������� �����������
 // hmap - ������������� �������� ��������� �����
 // namerst - ������ ��� ������
 // zonevisibility - ��������� ���������� ���� (��.maptype.h)
 // hpaint - �������� ��������� �������������� ������ (��. mapCreatePaintControl)
 // ���������� ������������ ��� ������� �������� ������� �����
 // ��������� ������������ � ���� namerst
 // ���������� ����� ������ � �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapVisibilityZone(HMAP hMap, const char *namerst,
                                           TBUILDZONEVISIBILITY *zonevisibility);

_MAPIMP long int _MAPAPI mapVisibilityZoneUn(HMAP hmap, const WCHAR *namerst,
                                             TBUILDZONEVISIBILITY *zonevisibility);

_MAPIMP long int _MAPAPI mapVisibilityZoneEx(HMAP hmap, const WCHAR *namerst,
                                             TBUILDZONEVISIBILITY *zonevisibility, HPAINT hPaint);


 // ����������� ��������� �� ����� point1 (���������� � ������ �� ���������) ����� point2
 // deltaheight  - ������ ���������� (� ������),
 // ����������� � ������ � ����� point1
 // ���������� ������������ ��� ������� �������� ������� �����
 // ���������� 0 - point2 �� ����� �� point1
 //            1 - point2 ����� �� point1

_MAPIMP long int _MAPAPI mapVisibilityFromPoint(HMAP hmap, DOUBLEPOINT *point1,
                                                DOUBLEPOINT *point2, double deltaheight);


// �������� �������� - ������ �� ���������� ��������                                    // 12/01/15
// hmap - ������������� �������� ��������� ����� � ����������� ���������
// hsite - ������������� ���������������� ����� ��� ������ �������� - ������
// info   - ������������� ������� ����� � ������, ������� ������� ��� �������� �������� - ������
// incode - ���������� ��� ������� ��� ���������� �������� - ������
// ���������� ���������� ��������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCreateObjectVoid(HMAP hmap, HSITE hsite, HOBJ info, long int incode);


 // ������� ����� � �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteLoop(HOBJ info, double precision);

 // ��������� ������ ������ �������� � ������������� ������� �����
 // �� �������� ����
 // info   - ������������� ������� ����� � ������
 // center - ���������� �����, ������ ������� �������������� ������ (�����)
 // angle  - ���� �������� �� ������� ������� (�������, �� -PI �� +PI)
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapRotateObject(HOBJ info, DOUBLEPOINT *center, double *angle);

 // ������������� ��������, ��������������� �������� ����������� ������,
 // �� ���� �������� ��������� ������
 // hmap - ������������� ������� �����
 // hobj - ������ � ������� ������������ ������������ ������
 // precision - ������ ������������ �������� (������ ���� >= DELTANULL)
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapContourTotalSeekObjects(HMAP hmap, HOBJ info, double precision);

 // ************************************************************
 //                                                            *
 //      �������������� ������ �������                         *
 //                                                            *
 // ************************************************************

  // ��������� ���������� ��������� ������
  // info    - ������������� ������� ����� � ������
  // text    - ����� ��� ���������� ������ (ANSI)
  // size    - ����� ���������� ������� ��� ������ � ������
  // subject - ����� ����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetText(HOBJ info, char *text,
                                    long int size, long int subject);

_MAPIMP long int _MAPAPI mapGetTextUnicode(HOBJ info, WCHAR *text,
                                           long int size, long int subject);

_MAPIMP long int _MAPAPI mapGetTextUn(HOBJ info, WCHAR *text,
                                      long int size, long int subject);

  // ���������� ����� ���������� ��������� ������
  // info   - ������������� ������� ����� � ������
  // text   - ����� ����� ������ (ANSI)
  // subject - ����� ����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPutText(HOBJ info, const char *text, long int subject);

  // ���������� ����� ���������� ��������� ������
  // info   - ������������� ������� ����� � ������
  // text   - ����� ����� ������ UNICODE UTF-16
  // ���� ����� �������� ��������� ������� �� 0x0001 �� 0x007E
  // ��� ��������� (0x0400 - 0x045F) � �� ����������
  // ����������� ������� Windows (OEM 866 ��� 1251), �� �����
  // ������������� ��������� � ANSI,
  // ����� ����� �������� ���������� � UTF-16
  // subject - ����� ����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPutTextUnicode(HOBJ info, const WCHAR *text, long int subject);

  // ���������� ������� - �������� mapPutTextUnicode

_MAPIMP long int _MAPAPI mapPutTextUn(HOBJ info, const WCHAR *text, long int subject);

  // ��������� - �������� �� ����� � ��������� UNICODE
  // info   - ������������� ������� ����� � ������
  // ���� ����� � UNICODE - ���������� ��������� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapIsTextUnicode(HOBJ info);

  // ��������� ����� ������ � �������� �� �����
  // info    - ������������� ������� ����� � ������
  // subject - ����� ����������
  // ��� �������������� ������� ���������� 0
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetTextLengthMkm(HOBJ info, long int subject);

  // ��������� ������ ������ ������ ��� �������� ���� �������
  // � �������� �� �����
  // info    - ������������� ������� ����� � ������
  // ��� �������������� ������� ���������� 0
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetTextHeightMkm(HOBJ info);

  // ��������� ����� ������� � �������� ��� ������� ������� �����������
  // hMap    - ������������� ���������
  // hdc     - ������������� ���������, �� ������� �������������� ������ �����
  //           (����� ���� ����� ����)
  // rect    - ��������� ������� �����������, ������������ ������� ��������� �����,
  //           � �������� �� ���������
  // info    - ������������� ������� ���� �������, ��������� ����������� ������ ���� ���� IMG_TEXT
  // box     - ���������� 4-�� ����� ��������� ����� ������������ �������� ������
  //           ���� ������� rect
  // ���������� ������� �� ����������� ��� ������� �����
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetPaintTextBorder(HMAP hMap, HDC hdc, RECT *rect,
                                               HOBJ info, DRAWBOX *box);

  // ��������� ������ ������������ ������ �� �����������
  // info    - ������������� ������� ����� � ������
  // subject - ����� ����������
  // (FA_LEFT,FA_RIGHT,FA_CENTER - ��. mapgdi.h)

_MAPIMP long int _MAPAPI mapGetTextHorizontalAlign(HOBJ info, long int subject);

  // ��������� ������ ������������ ������ �� ���������
  // info    - ������������� ������� ����� � ������
  // subject - ����� ����������
  // (FA_BOTTOM,FA_TOP,FA_BASELINE,FA_MIDDLE)

_MAPIMP long int _MAPAPI mapGetTextVerticalAlign(HOBJ info, long int subject);

  // ���������� ������ ������������ ������ �� �����������
  // (FA_LEFT,FA_RIGHT,FA_CENTER)
  // info    - ������������� ������� ����� � ������
  // subject - ����� ���������� (-1 - ���������� ����)
  // �� ��������� ����� �������� FA_LEFT
  // ��� �������� ���������� ���������� ������������� ��������

_MAPIMP long int _MAPAPI mapPutTextHorizontalAlign(HOBJ info, long int align,
                                                   long int subject);

  // ���������� ������ ������������ ������ �� ���������
  // (FA_BOTTOM,FA_TOP,FA_BASELINE,FA_MIDDLE)
  // info    - ������������� ������� ����� � ������
  // subject - ����� ���������� (-1 - ���������� ����)
  // �� ��������� ����� �������� FA_BASELINE
  // ��� �������� ���������� ���������� ������������� ��������

_MAPIMP long int _MAPAPI mapPutTextVerticalAlign(HOBJ info, long int align,
                                                 long int subject);

 // ************************************************************
 //                                                            *
 //     �������������� ������������ �������� ��'����           *
 //                                                            *
 //  (����������� �������� �������, ��� �������, � ��������    *
 //   ���������������� �����, �� ��������� � ���������������)  *
 //                                                            *
 // ************************************************************


  // ��������� - ����� �� ������ ����������� ��������
  // info    - ������������� ������� ����� � ������

_MAPIMP long int _MAPAPI mapIsDrawObject(HOBJ info);

  // ��������� ���������� ��������� ������������ ��������
  // info    - ������������� ������� ����� � ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDrawCount(HOBJ info);

  // ��������� ��� �������� ������������ ��������
  // �� ��� ������ (number -  �� 1 �� DrawCount())
  // info    - ������������� ������� ����� � ������
  // ���������� ����� ������� ���� IMG_XXXXXXX (��. MAPGDI.H)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDrawImage(HOBJ info, int number);

  // ��������� ����� ���������� �������� ������������ ��������
  // �� ��� ������ (number -  �� 1 �� DrawCount())
  // info    - ������������� ������� ����� � ������
  // ���������� ����� ��������� ���� IMGXXXXXX, � ������������
  // � ����� �������� (��. MAPGDI.H)
  // ��� ������� � 0 ������� ���������� ����� ����������
  // ������������ �������� ������� ��������� IMGDRAW
  // ��� ������ ���������� 0

_MAPIMP const char * _MAPAPI mapDrawParameters(HOBJ info, int number);

  // ��������� ����� ���������� �������� ������������ ��������
  // �� ��� ������ ( �� 1 �� DrawCount())
  // info    - ������������� ������� ����� � ������
  // ��� ������� � 0 ������� ���������� ����� ����������
  // ������������ �������� �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDrawLength(HOBJ info, int number);

  // �������� ������� ������������ �������� ��������
  // info  - ������������� ������� ����� � ������
  // image - ����� ������� ���� IMG_XXXXXXX (��. MAPGDI.H)
  // parm  - ����� ��������� ���� IMGXXXXXX
  // ��� ������ ���������� ����,����� - ����� ��������� � ������

_MAPIMP long int _MAPAPI mapAppendDraw(HOBJ info, int image, const char *parm);

  // ������� ��� �������� ������������ �������� �������
  // info  - ������������� ������� ����� � ������

_MAPIMP long int _MAPAPI mapClearDraw(HOBJ info);

  // ������� ������� ������������ �������� �������
  // info   - ������������� ������� ����� � ������
  // number - ����� �������� (������� � 1)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteDraw(HOBJ info, int number);


 // ************************************************************
 //                                                            *
 //         ���������/������������ ������ ��'����              *
 //                                                            *
 // ************************************************************

 // ��������� - ���������� �� �����-���� ������ ������� � ������:
 // �������, ���������, �������
 // ��� ��������� ������, ������� �� ���� ��������� �������� ����
 // mapCommitObject, ���������� ��������� ��������
 // ��������� ���� �������, ������ ��������� � ������ �������
 // ��� ������� �� ���������
 // ��� ������� ��������� ���������� ���� ��������� (2 - �������,
 // 4 - ���������, 8 - �������).
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapIsDirtyObject(HOBJ info);

 // ��������� ������ �� ������� � �����
 // info  - ������������� ������� ����� � ������
 // ����� ����� � ������ ������ ���� ����������
 // ���������� ��������� ������� ����������� � ���������
 // ������ � ����� ���� �������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCommit(HOBJ info);
_MAPIMP long int _MAPAPI mapCommitObject(HOBJ info);

 // ��������� ������ �� ������� � �����
 // info  - ������������� ������� ����� � ������
 // ������� ����� ������������ � ������� ������ � ����
 // ����������� ��� ����������� ���������� ��������
 // (��������, �������� ����� ���� ��� ���������)
 // ���������� ��������� ������� ����������� � ���������
 // ������ � ����� ���� �������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCommitObjectByOrder(HOBJ info);

 // ��������� ������ �� ������� � �����
 // info  - ������������� ������� ����� � ������
 // ���� ������ ����� - ����������� ������� mapCommitObject(),
 // ���� ����� ������ ��� ���, �� ����������� �����
 // ������� � ����� ���������� ������� (��������������,
 // ��� �������������� �������� ���������� � �.�.)
 // ����� ����� � ������ ������ ���� ����������
 // ��������� �������� �������� ����� ���������� ��������
 // (������ ������ - mapCopyObjectAsNew()).
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCommitObjectAsNew(HOBJ info);

 // ��������� ������ �� ������� � ����� � ������� �����
 // ��� �������� ������� �� ������ (��� �������������)
 // info  - ������������� ������� ����� � ������
 // ��� �������� ���������������� ���� (����������)
 // ���������� mapCommitObject() - ��� ���� ���� � ��� ������.
 // ���������� ��������� ������� ����������� � ���������
 // ������ � ����� ���� �������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCommitWithPlace(HOBJ info);

 // ��������� ������ �� ������� � ����� � ������� �����
 // ��� �������� ������� �� ������ (��� �������������)
 // ������ ����� ��������, ��� �����, � �����������
 // ������ ����������� ������
 // info  - ������������� ������� ����� � ������
 // ��� �������� ���������������� ���� (����������)
 // ���������� mapCommitObject() - ��� ���� ���� � ��� ������.
 // ���������� ��������� ������� ����������� � ���������
 // ������ � ����� ���� �������������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCommitWithPlaceAsNew(HOBJ info);

 // ��������� ������ �� ������� � ����� �
 // ���������� ������� �� �������� ��������� �����
 // info  - ������������� ������� ����� � ������
 // list  - ����� ����� ( > 0 ), �� ����� �������� ���������������
 // ����������� ������ �������
 // ��� �������� ���������������� ���� (����������)
 // ���������� mapCommitObject() - ��� ���� ���� � ��� ������.
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCommitWithPlaceForList(HOBJ info, long int list);

 // ��������/���������� ��������� ��������� ������� �������� � ��������� ��������,
 // ������������ ��� ���������� �������� � �������� �� ����� � ��������:
 // mapCommitWithPlace, mapCommitWithPlaceAsNew, mapCommitWithPlaceForList
 // parm  - ���������, ������������ ��� ��������������� �������� ����� ��������,
 //         ����� �������� � ����������� ��������� ��������, ������� ����������
 //         ��� ���������� �������� �� ������ ������ �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetCommitObjectParm(HMAP hmap, COMMITOBJECTPARM* parm);
_MAPIMP long int _MAPAPI mapSetCommitObjectParm(HMAP hmap, COMMITOBJECTPARM* parm);

 // ������� ������ �����
 // ���������� ��������� ������� ����������� � ���������
 // ������ � ����� ���� �������������
 // info  - ������������� ������� ����� � ������
 // ������� �������� ������������ � ������ � � �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteObject(HOBJ info);

 // ������� ������ ����� �� ��� ������ (number)
 // hMap   - ������������� �������� ������
 // list   - ���������������� ����� ����� (� 1)
 // number - ���������������� ����� ������� � �����
 // ����� � ������� - ��. mapReadObjectByNumber,mapGetObjectNumber
 // ����� �������� ������� �� ������ ����� �ommit �� ������ �����������
 // ��� ����� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteObjectByNumber(HMAP hMap, long int list,
                                                 long int number);

 // �������� �������� ������� �����
 // info  - ������������� ������� ����� � ������
 // ������� �������� ��������� � ������ � � �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUndeleteObject(HOBJ info);

 // ����������� ������ � ������� � ����� (�������� ��� �����)      // 19/02/14
 // ������� ������������� ������� "���� ����"
 // info  - ������������� ������� ����� � ������
 // ���������� ����� ���������������� ����� ������� �� ����� - mapGetObjectNumber()
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdateObjectUp(HOBJ info);

 // ����������� ������ � ������� � ������ (�������� ��� �����)     // 19/02/14
 // ������� ������������� ������� "���� ����"
 // info  - ������������� ������� ����� � ������
 // ���������� ����� ���������������� ����� ������� �� ����� - mapGetObjectNumber()
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdateObjectDown(HOBJ info);

 // �������� �������� "���� ����" � "���� ����" � �������          // 19/02/14
 // ��������� ������� � ������������ � ��� ����� � ������������
 // ��������� ����� ���������� �����
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdateObjectNormal(HOBJ info);

 // ��������� ���� ���������� ������� (2 - ��� �����, 3 - ��� �����, 1 - �� ������)
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapObjectUpDownState(HOBJ info);         // 28/04/16

 // �������� �������� ������� ����� �� ��� ������ (number)
 // hmap   - ������������� �������� ������
 // hSite  - ������������� ���������������� �����
 //          (��� ������ ����� ����� hMap ��� 0)
 // list   - ���������������� ����� ����� (� 1)
 // number - ���������������� ����� ������� � �����
 // ����� � ������� - ��. mapReadObjectByNumber,mapGetObjectNumber
 // ������� �������� ��������� � �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUndeleteObjectByNumber(HMAP hMap, HSITE hSite,
                                                   long int list, long int number);

 // ������������ (� ������) ������ �� ������� �� �����
 // info  - ������������� ������� ����� � ������
 // ����� ����� � ������ � ����� ������� ������ ���� �����������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRevert(HOBJ info);
_MAPIMP long int _MAPAPI mapRevertObject(HOBJ info);

  // ������������ ����� �������, �� ��������� �� ���������� ����������
  // info -  ������������� ������������� �������,
  // number - ����� ����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRestoreBackObjectByAction(HOBJ info, long int number);

  // ������������ ����� �������, �� ��������� �� ���������� ����������
  // info -  ������������� ������������� �������,
  // number - ����� ����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRestoreBackObjectByTime(HOBJ info, long int date, long int time);

  // ���������� ����� �������, ������� ����� ����������
  // ��� �������������� ������� �����.
  // ��� ������ ���������� � �������������� ���������� �������
  // ������ ������� � �������� � ���������� call � parm ������� ��������
  // ���������� ������� �� ������ ���� ������������� ����� !
  // hmap   - ������������� �������� ������
  // hSite  - ������������� ���������������� �����
  //          (��� ������� ����� ����� hMap ��� 0)
  // call - ����� ���������� ������� (��. maptype.h),
  // parm - ��������, ������� ����� ������� ���������� ������� ������,
  // ������ ���������� ����� ����� ��������� CHANGEINFO (��. maptype.h).
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetChangeCallAndParm(HMAP hmap, HSITE hSite,
                                                 CHANGECALL call, void *parm);

 // *************************************************************
 //                                                             *
 //     ��������� ��������� ������ ...\LOG\... ^DA,^SE,^HD      *
 //      (�������� ����� ���� ����������� �� ����� �����)       *
 //                                                             *
 // *************************************************************

  // ���������������� ������� ����������������� ����� ������� info
  // info  - ������������� ������� ����� � ������
  // copynumber - ���������������� ����� ����� ������� ������� (1, 2, ...)
  // � ������� �� ��������� �������� �������������� � ����������
  // ���������� � ���������������� ����������� copynumber,
  // ���� �� ����� ������� ������ ����� ��� ����� ����������
  // ����� ������� ��������� ����� ������� ���������� ������� �� �����,
  // ����� ������� ������ ����� ������� ��������
  // mapDeleteObjectCopyToNumber, � ����� ������� ������� mapCommit.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapReadObjectCopyByNumber(HOBJ info,
                                                   long int copynumber);

  // ������� ����������������� ����� ������� info
  // info  - ������������� ������� ����� � ������
  // ������� ����� ������� �� ������ �� copynumber �� ������ ������
  // ����� copynumber+1 ���������� ������
  // ���� ���������� ����� ���������� �������������� ����� �������
  // �� ����� (mapCommit - ������ ����������� �������� ��������������),
  // �� ����� ��������� ����� ������ ���� �� 1 ������, ��� �����
  // ����������������� �����. (�.�. mapCommit ������� ��� ���� �����
  // ������� � ��� ����������� ������).
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteObjectCopyToNumber(HOBJ info,
                                                     long int copynumber);


 // ************************************************************
 //                                                            *
 //         ������ ������������� ��'����                       *
 //                                                            *
 // ************************************************************

 // ���������� ����� ������� ������� (�������) �� ���������, 
 // ������� � ��������� �����
 // ��� ��������� ����� ��������� ���������� �� ������ �����
 // info  - ������������� ������� ����� � ������
 // number - ����� �����, ������� � 1
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� 0 (��� ���������� ����� �����)

_MAPIMP double _MAPAPI mapSideLength(HOBJ info,long int number,
                                     long int subject = 0);

_MAPIMP long int _MAPAPI mapSideLengthEx(HOBJ info, long int number,
                                         long int subject, double *length);

 // ���������� ����� ������� ������� (�������) � �������� ���������
 // ��� �� ���������, � ����������� �� ��������
 // ������� ���������� ���������� �� ����� -
 // mapSetCalculationConventional
 // info  - ������������� ������� ����� � ������
 // number - ����� �����, ������� � 1
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapConventionalSideLength(HOBJ info, long int number,
                                                 long int subject = 0);
                                         
 // ���������� ������� ������� ������� (�������)
 // ���������� �������� ���� � ��������
 // ���� �������� �� ��������������, �� ����������� ������������ ����
 // ��� ��������� ����� ��������� ����������� �� ������ �����
 // � ��������� �������� ������ � ��������� ����� ���������
 // info  - ������������� ������� ����� � ������
 // number - ����� �����, ������� � 1
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� 0 (��� ���������� ����� �����)

_MAPIMP double _MAPAPI mapSideAzimuth(HOBJ info,long int number,   
                                      long int subject);
_MAPIMP long int _MAPAPI mapSideAzimuthEx(HOBJ info,long int number,
                                          long int subject, double *azimuth);

 // ���������� ������������� ���� ������� ������� (�������)
 // ���������� �������� ���� � ��������
 // ��� ��������� ����� ��������� ����������� �� ������ �����
 // � ��������� �������� ������ � ��������� ����� ���������
 // info  - ������������� ������� ����� � ������
 // number - ����� �����, ������� � 1
 // subject - ����� ���������� (���� = 0, �������������� ������)
 // ��� ������ ���������� 0 (��� ���������� ����� �����)

_MAPIMP double _MAPAPI mapSideDirection(HOBJ info,long int number,
                                        long int subject/* = 0*/);

 // ���������� ���������� ������� ������� �� ���������
 // ��� ���������� ������� ������� ��� ���������� ��������������
 // � �������� ��������������� ����� ��������� ����!
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapSquare(HOBJ info);
_MAPIMP long int _MAPAPI mapSquareEx(HOBJ info, double *square);

 // ���������� ������� ������� � �������� �����
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapSquareInMap(HOBJ info);

 // ���������� ������� ������� � �������� �����
 // ��� �� ���������, � ����������� �� ��������
 // ������� ���������� ���������� �� ����� -
 // mapSetCalculationConventional
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapConventionalSquare(HOBJ info);

 // ���������� ������� ���������� ���������� � �������� ���������
 // ��� �� ���������, � ����������� �� ��������
 // ������� ���������� ���������� �� ����� -
 // mapSetCalculationConventional
 // info    - ������������� ������� ����� � ������
 // subject - ����� ���������� �� 0 �� mapPolyCount,
 //           ���� ����� ����, �� ����������� ������� �������� �������
 //           ��� ��������� ������� �����������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapConventionalSubjectSquare(HOBJ info, long int subject);

 // ���������� ������� ���������� � �������� ���������
 // info  - ������������� ������� ����� � ������
 // subject - ����� ���������� �� 0 �� mapPolyCount,
 //           ���� ����� ����, �� ����������� ������� �������� �������
 //           ��� ��������� ������� �����������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapSubjectSquareInMap(HOBJ info, long int subject);

 // ���������� ������� ��� ������� ���������� � ��������
 // �� �����
 // hmap   - ������������� �������� ������
 // flag   - ������� ���������� ��������: 
 //          0 - ��������� ���������� �������� �������� � 
 //          ���������� �� ���������� ������� ���������;
 //          1 - ��������� ������� � ���������� � ��������
 //          �����, ������� ����������� ������
 // ���������� ���������� �������� ������� 

_MAPIMP long int _MAPAPI mapSetCalculationConventional(HMAP hmap, long int flag);

 // ��������� ������� ��� ������� ���������� � ��������
 // �� �����
 // hmap   - ������������� �������� ������
 // ���������� ������� ���������� ��������: 
 //          0 - ��������� ���������� �������� �������� � 
 //          ���������� �� ���������� ������� ���������;
 //          1 - ��������� ������� � ���������� � ��������
 //          �����, ������� ����������� ������

_MAPIMP long int _MAPAPI mapGetCalculationConventional(HMAP hmap);

                                              
 // ���������� ������� ������� c ������ �������
 // ��� ���������� �������(������� �����,�����,Tin-�������) ���������� ������� �������
 // hmap   - ������������� �������� ������
 // info  - ������������� ������� ����� � ������
 // step - ��� ������������ � ������, ���� 0 �� ����������� �������������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapSquareWithHeight(HMAP hmap, HOBJ info);
_MAPIMP double _MAPAPI mapSquareWithHeightEx(HMAP hmap, HOBJ info, double step = 0.); //05/06/15

 // ���������� ��������� �������
 // info  - ������������� ������� ����� � ������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapPerimeter(HOBJ info);

 // ���������� ����� �������
 // ��� ���������� ����� ������� ��� ���������� ��������������
 // � �������� ��������������� ����� �� ������� ������� ��������
 // � ���������� ������� ��������� � ������ �������
 // info  - ������������� ������� ����� � ������
 // ��� ����������� ��������� ��������� �����
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapLength(HOBJ info);
_MAPIMP long int _MAPAPI mapLengthEx(HOBJ info, double *length);

 // ���������� ����� ������� �� �����
 // ���������� ������� �� ���������������, ���������� �����
 // ����� ����������� ���������� �� �������� ����� ������� �� ���������
 // info  - ������������� ������� ����� � ������
 // ��� ����������� ��������� ��������� �����
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapLengthInMap(HOBJ info);

 // ���������� ����� ������� �� ������ �� �������� �����
 // info  - ������������� ������� ����� � ������
 // point - ���������� �����, ������������� �����(������) �������
 // ���� ����� �� �� ������� - ������ ��������� ����� �� �������
 // ���������� ����� �����������!
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapLengthToPoint(HOBJ info, DOUBLEPOINT *point);

 // ���������� ����� ����������/�������
 // info    - ������������� ������� ����� � ������
 // subject - ����� ���������� (���� = 0, �������������� ������;
 //           ���� ����� -1, ����������� ����� ������� � �����������)
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapSubjectLength(HOBJ info, long int subject);

 // ���������� ����� �������\���������� � �������� ���������
 // info    - ������������� ������� ����� � ������
 // subject - ����� ���������� (���� = 0, �������������� ������;
 //           ���� ����� -1, ����������� ����� ������� � �����������)
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapSubjectLengthInMap(HOBJ info, long int subject);

 // ���������� ����� �������\���������� � �������� ���������
 // ��� �� ���������, � ����������� �� ��������
 // ������� ���������� ���������� �� ����� -
 // mapSetCalculationConventional
 // info    - ������������� ������� ����� � ������
 // subject - ����� ���������� (���� = 0, �������������� ������;
 //           ���� ����� -1, ����������� ����� ������� � �����������)
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapConventionalSubjectLength(HOBJ info, long int subject = -1);

 // ���������� ����� ������� c ������ �������
 // ��� ���������� �������(������� �����,�����,Tin-�������) ���������� ����� �������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapLengthWithHeight(HMAP hmap, HOBJ info);

 // ����������� ����������� ������� ����������
 // info  - ������������� ������� ����� � ������
 // subject - ����� �������� ���������� (0 - �������)
 // ����������: 1 - ������ �������, ����� 0

_MAPIMP long int _MAPAPI mapCircuitousSubject(HOBJ info, long int subject/* = 0*/);

 // ����������� ����������� ���������� �� ����� �� �������
 // hmap   - ������������� �������� ������
 // info  - ������������� ������� ����� � ������
 // subject - ����� �������� ���������� (0-�������)
 // ���������� ����� point ������ � �������������
 // ������� ��������� , � ������ �� ���������
 // ���������� ����������� ���������� � ������
 // ��� 0 � ������ ������

_MAPIMP double _MAPAPI mapDistancePointSubject(HMAP hmap, HOBJ info,
                                               long int subject,
                                               DOUBLEPOINT * point);

 // ����������� ����������� ���������� �� ����� �� ������� (�������
 // ����������)
 // hmap   - ������������� �������� ������
 // info  - ������������� ������� ����� � ������
 // ���������� ����� point ������ � �������������
 // ������� ��������� , � ������ �� ���������
 // ���������� ����������� ����������  � ������
 // ��� 0 � ������ ������

_MAPIMP double _MAPAPI mapDistancePointObject(HMAP hmap, HOBJ info,
                                              DOUBLEPOINT * point);

 // ����������� ����������� ���������� ����� ���������
 // info1  - ������������� 1-�� ������� ����� � ������
 // info2  - ������������� 2-�� ������� ����� � ������
 // ���������� ����������� ����������  � ������
 // ��� 0 � ������ ������

_MAPIMP double _MAPAPI mapDistanceObject(HOBJ info1, HOBJ info2);

 // ����������� ����������� ���������� ����� ��������� � ���������
 // ����� �� �������� ��������
 // hobj1  - ������������� ������� ������� ����� � ������
 // hobj2  - ������������� ������� ������� ����� � ������
 // point1 - ���������� ������ ����� ����� ����������� ����������
 //          ����� ��������� (�� ������� hobj1)
 // point2 - ���������� ������ ����� ����� ����������� ����������
 //          ����� ��������� (�� ������� hobj2)
 // ���������� ����������� ����������  � ������
 // ��� ������� �������� (>= 100000000) � ������ ������

_MAPIMP double _MAPAPI mapDistanceObjectEx(HOBJ hobj1, HOBJ hobj2,
                                           DOUBLEPOINT *point1,
                                           DOUBLEPOINT *point2);

 // ������ ������������� ������ �� ����������
 // ��� ���������� �� ����� 250 �� ���������� ������������ � ������� �� 0,0001",
 // � �������� ������ - �� 0,001", ��� ������������� ������������ 1 ������
 // ������ ��������������� ����� �� ������ �����������
 // ����� ������������ ��� ���������� ������ ������� �����
 // ���������� ����������� �� ������� ����������, �������������
 // � ��������� - mapSetDocProjection
 // ���� hmap ����� 0, �� ���������� ����������� �� ���������� WGS-84
 // hmap     - ������������� �������� ������
 // b1,l1    - ������������� ���������� �������� �����
 // angle1   - ������ �� ������ �����
 // distance - ���������� �� ������ �����
 // b2,l2    - ������������ ���������� ������ �����
 // angle2   - ������������ ������ �� ������ ����� �� ������
 //            (���� angle2 ����� 0, �� �������� ������ �� �����������)
 // ��� ������ � ���������� ���������� 0

_MAPIMP long int _MAPAPI mapDirectPositionComputation(HMAP hmap,
                                                      double b1, double l1, double angle1,
                                                      double distance,
                                                      double *b2, double *l2, double *angle2);

 // �������� ������������� ������ �� ����������
 // ��� ���������� �� ����� 180 �������� �� ������
 // ����������� ���������� ���������� �������� mapOrthodromeObject
 // � ������ ����� ������� � ������� ������� �������
 // �������� ������� �������� ������������ 1 ������
 // ���������� ����������� �� ������� ����������, �������������
 // � ��������� - mapSetDocProjection
 // ���� hmap ����� 0, �� ���������� ����������� �� ���������� WGS-84
 // hmap     - ������������� �������� ������
 // b1,l1    - ������������� ���������� ������ �����
 // b2,l2    - ������������� ���������� ������ �����
 // angle    - ������������ ������ � ������ ����� �� ������
 // ���������� ���������� ����� ��������� ������� �� ������� ����������
 // ��� ������ � ���������� ���������� 0

_MAPIMP double _MAPAPI mapInversePositionComputation(HMAP hmap, double b1, double l1,
                                                     double b2, double l2, double *angle);

 /*********************************************************
 *                                                        *
 *                �������������� �������                  *
 *                                                        *
 *********************************************************/

 // ���������� ���������� ����� ����� ������� �� ���������
 // point1, point2 - ���������� ����� � ������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapDistance(DOUBLEPOINT *point1, DOUBLEPOINT *point2);

 // ���������� ���������� ����� ����� ������� �� ���������
 // hmap   - ������������� �������� ������
 // point1, point2 - ���������� ����� � ������ �� ���������
 // ��� ���������� ���������� ���������� ���������������
 // � �������� ��������������� ����� � ���������� �������
 // ��������� � ������ �������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapRealDistance(HMAP hmap, DOUBLEPOINT *point1,
                                       DOUBLEPOINT *point2);

 // ���������� ���������� ����� ����� ������� � �������� �����
 // ��� �� ���������, � ����������� �� ��������
 // ������� ���������� ���������� �� ����� -
 // mapSetCalculationConventional
 // hmap   - ������������� �������� ������
 // point1, point2 - ���������� ����� � ������ �� ���������
 // ��� ������ ���������� 0

_MAPIMP double _MAPAPI mapConventionalDistance(HMAP hmap, DOUBLEPOINT *point1,
                                               DOUBLEPOINT *point2);

 // ����������� ���� ������� ����������� ����, ���������
 // ������� p1,p2,p3 � �������� � ����� p2
 // ����������� ���� ������� ����������� ����, ���������
 // ������� p1,p2,p3 � �������� � ����� p2
 // ������������ ���� ����� ������������ ��� X, ��� �������������
 // ����������� ������������� �������������� ����������� ��� Y

_MAPIMP double _MAPAPI mapBisectorAngle(DOUBLEPOINT *p1, DOUBLEPOINT *p2,
                                        DOUBLEPOINT *p3);


  /*********************************************************
  *                                                        *
  *          ������� ������ ������ ����                    *
  *                                                        *
  *  ������ - ����������� ��������� ����� ����� ������     *
  *           ������ ��� �����������. �������� �������     *
  *           �� �� ����� � ������ �������� � �������,     *
  *           � ����� ������� ������ ������ (MPT)          *
  *                                                        *
  *********************************************************/

  // �������� ������ �� �����
  // hMap - ������������� �������� ������
  // name - ��� ����� (�������, ������) ��� ����������� ������
  // ���������� ������� ����� ������ � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendInset(HMAP hmap, const WCHAR *name);

  // �������� ������ �� �����
  // hMap - ������������� �������� ������
  // item - ��������� �� �������� ����������� ������ (�����, �������, ������)
  // ���������� ������� ����� ������ � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapAppendInsetItem(HMAP hmap, INSETDESC *item);

  // ��������� ����� ������ �� �����
  // hMap - ������������� �������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapInsetCount(HMAP hmap);

  // ��������� �������� ������ �� ������ � 1
  // hMap   - ������������� �������� ������
  // number - ���������� ����� ������ �� ����� � 1
  // item   - ��������� �� �������� ������,
  //          ������� ����� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetInset(HMAP hmap, long int number, INSETDESC *item);

  // ��������� �������� ������ �� ��������������
  // hMap   - ������������� �������� ������
  // ident  - ������������� ������ �� �����
  // item   - ��������� �� �������� ������,
  //          ������� ����� ���������
  // ��� ������ ���������� ����, ����� - ����� ������ � ������

_MAPIMP long int _MAPAPI mapGetInsetByIdent(HMAP hmap, long int ident, INSETDESC *desc);

  // ��������� �������� ������ �� ������ � 1
  // hMap   - ������������� �������� ������
  // number - ���������� ����� ������ �� �����
  // name   - ����� ��� ������ �����
  // size   - ����� ������ � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetInsetName(HMAP hmap, long int number, WCHAR *name, long int size);

  // ��������� ������������� ������ �� ������ � 1
  // hMap   - ������������� �������� ������
  // number - ���������� ����� ������ �� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetInsetIdent(HMAP hmap, long int number);

  // ��������� ������������� �������� ������ ������ �� ������ � 1
  // hMap   - ������������� �������� ������
  // number - ���������� ����� ������ �� �����
  // ����������� ������������� �� ������ ����������� (����� ����� mapCloseData)
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapGetInsetMapHandle(HMAP hmap, long int number);

  // ������� �������� ������ �� ������ � 1
  // hMap   - ������������� �������� ������
  // number - ���������� ����� ������ �� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteInset(HMAP hmap, long int number);

  // �������� �������� ������ �� ������ � 1
  // hMap   - ������������� �������� ������
  // number - ���������� ����� ������ �� �����
  // item   - ��������� �� ����� �������� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapUpdateInset(HMAP hmap, long int number, INSETDESC * desc);

  // ���������� ������ ������� ������������ �����������
  // hMap   - ������������� �������� ������
  // number - ����� ������, ��� ������� ��������������� ����,
  //          ���� ����� -1, �� ��������������� ��� ���� ������
  // flag   - ������� ������������ ����������� (0 ��� 1)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetInsetSchemeFlag(HMAP hmap, long int number, long int flag);

  // ��������� ������� ����������� ������
  // hMap   - ������������� �������� ������
  // number - ����� ������ � 1, ��� ������� ������������� ����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetInsetViewFlag(HMAP hmap, long int number);

  // ���������� ������ ������� �����������
  // hMap   - ������������� �������� ������
  // number - ����� ������, ��� ������� ��������������� ����,
  //          ���� ����� -1, �� ��������������� ��� ���� ������
  // flag   - ������� ����������� (0 ��� 1)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetInsetViewFlag(HMAP hmap, long int number, long int flag);

  // ��������� ������� ����������� ���� ������
  // hMap   - ������������� �������� ������
  // number - ����� ������ � 1, ��� ������� ������������� ����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetInsetTransparenceFlag(HMAP hmap, long int number);

  // ���������� ������ ������� ����������� ����
  // hMap   - ������������� �������� ������
  // number - ����� ������, ��� ������� ��������������� ����,
  //          ���� ����� -1, �� ��������������� ��� ���� ������
  // flag   - ������� ����������� (0 ��� 1)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetInsetTransparenceFlag(HMAP hmap, long int number, long int flag);

  // ���������� ������ � ���������
  // hMap     - ������������� �������� ������
  // number   - ����� ������������ ������
  //            ���� ����� -1, �� ������������ ��� ������
  // hdc      - ������������� ��������� ���������� ������,
  // rect     - ���������� ������������� ��������� ����� (Draw) � ����������� (Picture)
  // position - ��������� �������� ������ ���� ������������ ������� � ���� �����������
  //            (���� �������� �������������� ������ ����� SetViewportOrgEx, �� �������� ����� 0)
  // printscale - ������������ ������� ������� ����������� ���������� � ������� ������
  //            (��� ������, ��� ������ �� ����� �������� ����� 0)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPaintInset(HMAP hMap, long int number, HDC hdc, RECT *rect,
                                       POINT *position, double *printscale);

 /*********************************************************
 *                                                        *
 *                 ��������� �������                      *
 *                                                        *
 *********************************************************/

 // ���������� ������� ���� ����� ��������� ����������

_MAPIMP  long int _MAPAPI mapCloseMapAccess();

  // ���������� ��� ����� �� ��� �����
  // name - ��� ������������ ����� (������ ����)
  // ������������� ������ 4 �����, ���������� ������������� ������.
  // ��� ������ ���������� ����, ����� - ������������� �����
  // (��. maptype.h : FILE_SXF, FILE_MAP, FILE_MTW,...)

_MAPIMP long int _MAPAPI mapCheckFile(const char *name);

  // ���������� ��� ����� �� ��� �����
  // name - ��� ������������ ����� (������ ����)
  // ������������� ������ 4 �����, ���������� ������������� ������.
  // ��� ������ ���������� ����, ����� - ������������� �����
  // (��. maptype.h : FILE_SXF, FILE_MAP, FILE_MTW,...)
  // ������������� ��������� MAP (FILE_MAP) � SIT (FILE_MAPSIT)
  // ��� ����� ���� � ���� ALIAS#XXXX ��� ���� �� ��� �������

_MAPIMP long int _MAPAPI mapCheckFileEx(const char *name);

_MAPIMP long int _MAPAPI mapCheckFileExUn(const WCHAR *name);

  // ��������� ������� ����� � ������� "HH:MM:SS"
  // buffer - ����� ������ ��� ���������� ���������� �������
  // size   - ������ ���������� ������ � ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetTheTime(char *buffer, long int size);

_MAPIMP long int _MAPAPI mapGetTheTimeUn(WCHAR *buff, long int size);

  // ��������� ���������� DLL
  // �� ������ ����� mapLoadLibrary ������ ����������� ����� mapFreeLibrary
  // ��� ������ DLL ����������� � ���������� ����������
  //  void (WINAPI * myfunction)(int param);
  // (FARPROC)myfunction = mapLoadLibrary("ABC.DLL",&instance,"MyFunction");
  //  if (myfunction)
  //      { (*myfunction)(123); ::FreeLibrary(*instance); }
  // ��� ������ ���������� ���� � ������ ��������� �� �����

_MAPIMP FARPROC _MAPAPI mapLoadLibrary(const char *dllname,
                                       HINSTANCE  *libinst,
                                       const char *funcname);
_MAPIMP FARPROC _MAPAPI mapLoadLibraryUn(const WCHAR *dllname,
                                         HINSTANCE   *libinst,
                                         const WCHAR *funcname);

  // ��������� ���������� DLL

_MAPIMP long int _MAPAPI mapFreeLibrary(HINSTANCE libinst);

  // ��������� ������� ���������� DLL

_MAPIMP FARPROC _MAPAPI mapGetProcAddress(HINSTANCE libinst,
                                          const char *funcname);

  // ����� ���� ������� ������� �� ����� *.CHM                                     // 13/11/14
  // (�������� HelpExecLang ��� HelpExecLangUn)
  // helpName - ��� ����� ������� (������ ��� ��������)
  // pageName - ��� �������� ������� (��� ����������), ����� ���� ����� 0        
  // ������ ������ �������: HelpExec(TEXT("map3d.chm"), TEXT("Setup"));

_MAPIMP void _MAPAPI HelpExec(const TCHAR* helpName, const TCHAR* pageName);

// ����� ���� ������� ������� � �ޣ��� ��������������
// �������� mapSetMapAccessLanguage ����� ���������
// helpName - ��� ����� ������� (������ ��� ��������)
// pageName - ��� �������� �������, ����� ���� ����� 0
// ������ ������ �������: HelpExecLang("map3d.chm", "Setup");

_MAPIMP void _MAPAPI HelpExecLangUn(const WCHAR* helpName, const WCHAR* pageName);    // 08/08/14
_MAPIMP void _MAPAPI HelpExecLang(const char* helpName, const char* pageName);        // 18/08/14

// ������������ ����� ����� ������� ������� � �ޣ��� ��������������
// �������� mapSetMapAccessLanguage ����� ���������
// helpName - �������� ��� ����� ������� (��� �ޣ�� ����� ���������)
// helpNameLang - ����� ������ ��� ������������ ����� ����� �������
//                (� �ޣ��� ����� ���������)
// size - ������ ������ helpNameLang � ������

_MAPIMP int _MAPAPI HelpNameLang(const char* helpName, char* helpNameLang, int size);  // 09/07/14
_MAPIMP int _MAPAPI HelpNameLangUn(const WCHAR* helpName, WCHAR* helpNameLang, int size);  // 09/07/14

  // ���������� ��������� ����� ���������
  //  mapname - ����������� �����
  //  flags   - ������ ��������� ����� :
  //   0 - ����������� ��� �����,
  //   1 - ������ ���������������,
  //   2 - ��������� ����� ������,
  //   4 - �������� �������� ��������,
  //   8 - ���������� �������� �������� (FLOAT).
  //  16 - �������� �������� ��������, ������ - ��
  //  32 - �������� �������� ��������, ������ - ��
  //  64 - �������� �������� ��������, ������ - �������
  // hEvent - ����� ������� ��������� ������ ��� ����������� � ��������
  // eventparam - ��������� ������� ��������� ������
  // outpath - ����� ������ ��� ������ ������ ���� � ��������������� �����,
  //           ���� ����� ������ �� �����, �� ����� ����������� �� �����
  // size    - ������ ������ ��� ������ ����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI MapSortingWithEvent(const char *mapname,
                                             long int flags,
                                             EVENTCALL hEvent,
                                             void *eventparam,
                                             char *outpath,
                                             long int size);

  // ���������� ��������� ����� ���������
  // mapname - ����������� �����
  // flags   - ������ ��������� ����� :
  //   0 - ����������� ��� �����,
  //   1 - ������ ���������������,
  //   2 - ��������� ����� ������,
  //   4 - �������� �������� ��������,
  //   8 - ���������� �������� �������� (FLOAT).
  //  16 - �������� �������� ��������, ������ - ��
  //  32 - �������� �������� ��������, ������ - ��
  //  64 - �������� �������� ��������, ������ - �������
  // handle     - ������������� ����, �������� ���������� ��������� WM_LIST � WM_OBJECT,
  //              ���� �� ����� �������� hEvent
  // hEvent     - ����� ������� ��������� ������ ��� ����������� � �������� ����������,
  //              ���� �������� �� �����, �� ���������� ��������� WM_LIST � WM_OBJECT
  // eventparam - ��������, ������������ ������� ��������� ������
  // outpath    - ����� ��� ������ ���� � �����, ���� ��������� ��������������� �����,
  //              ���� ����� ���� ��������, �� �������� ����� �� �����������,
  //              ����� ��������� ������������� � ��������� ����������
  // size       - ����� ������ � ������
  // format - ���������� �������� ����� :
  //  0 -  �� ������,
  //  1 -  ���������� ������ SITX (�� ����� ����� ���� SIT ��� MAP � ����� ������),
  // -1 -  ���������� ������ SIT (�� ����� ����� ���� SITX ��� MAP � ����� ������),
  // code - ���������� ����������� ����� :
  //  0 - �� ������,
  //  1 - ��������� ������ � ������� ������ �� ��������� password (������ SITX),
  // -1 - ����� ���������� ������
  // password - ������ ��� ���������� ������, ����� code = 1, ��� 0
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI MapSortingWithEventPro(const WCHAR *mapname, long int flags,
                                                HWND handle, EVENTCALL hEvent, void *eventparam,
                                                WCHAR *outpath, long int size,
                                                long int format, long int code,
                                                const WCHAR *password);

_MAPIMP long int _MAPAPI MapSortingSitePro(HMAP hmap, HSITE hsite, long int flags,
                                           HWND handle, long int format, long int code,
                                           const WCHAR *password);

_MAPIMP long int _MAPAPI MapSortingWithEventUn(const WCHAR *mapname, long int flags,
                                               HWND handle, EVENTCALL hEvent, void *eventparam,
                                               WCHAR *outpath, long int size);

  // ����������� c���������� �������� ������
  // in     - ��� �������� �����
  // out    - ��� ��������� �����
  // mode   - ������ ������� � ��������� ����� (GENERIC_READ, GENERIC_WRITE),
  //          ���� ������������� GENERIC_READ,
  // access - ������ �������� ��������� ����� (FILE_SHARE_READ,FILE_SHARE_WRITE)
  //          ���� ������������� FILE_SHARE_READ|FILE_SHARE_WRITE
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCopyFile(const char *in, const char *out,
                                     long int access = 0, long int mode = 0);

_MAPIMP long int _MAPAPI mapCopyFileUn(const WCHAR *in, const WCHAR *out,
                                       long int access = 0, long int mode = 0);

  // ��������� ����� �����
  // name - ������ ���� � �����
  // ��� ������ ���������� ����

_MAPIMP double _MAPAPI mapGetFileLength(const char *name);

_MAPIMP double _MAPAPI mapGetFileLengthUn(const WCHAR *name);

  // ���������/��������� ������ ��������� �� �����
  // (��������� ����� ������)
  // enable = 0  - ������ ������ ���������,
  // ���������� ���������� �������� �����

_MAPIMP long int _MAPAPI mapMessageEnable(long int enable);

_MAPIMP long int _MAPAPI mapIsMessageEnable();

  // ������ ��������� �� ������ (�� �����)
  // code - ��� ������ (��. MAPERR.RH)

_MAPIMP void _MAPAPI ErrorMessageEx(HWND hwnd, int code, const char *filename);
_MAPIMP void _MAPAPI mapErrorMessage(long int code, const char *filename);
_MAPIMP void _MAPAPI mapErrorMessageUn(long int code, const WCHAR *filename);

  // ������ ��������� �� ������ (�� �����)
  // hwnd - ������������� ������������� ���� ��� ������ ��������� ��� 0
  // code - ��� ������ (��. MAPERR.RH)
  // filename - ��� ����� (�������), ��� �������� �������� ������
  // message  - ����� ������ ��� ���������� ������ ��������� (��� ������
  //            � �������� � �.�.), ������� ������ ������ ����
  //            �� ����� ����� ����� ����� + 256 ����; �������� ����� ���� 0

_MAPIMP void _MAPAPI mapErrorMessageExUn(HWND hwnd, long int code, 
                                         const WCHAR *filename, WCHAR *message);

  // ���������� ������� ��������� ������ ��� ��������� � ������       // 17/04/16
  // ��������� �� ������� � ��������, ���������� �� ���-����
  // ����� ��������� ������� MessageBox
  // call - ����� ������� ��������� ������ (�������� � maptype.h)
  // parm - �������� ������� ��������� � ������� ��������� ������ (����� ���� 0)
  // ��������� ��������� � ������� ��������� ������ ����� �� �� ����������,
  // ��� � ��������� � ������� MessageBox ��� UNICODE

_MAPIMP void _MAPAPI mapSetMessageBoxCall(MESSAGEBOXCALL call, void * parm);

  // ������ ��������� �� ����� ����� ��������� ������� MessageBox
  // ���� mapIsMessageEnable() ����� 0,  �� ��������� �� ��������
  // � ������� ���������� ����
  // ���� ����������� ������� ��������� ������ mapSetMessageBoxCall,
  // �� ������ ��������� ����� ����� ��� �������

_MAPIMP long int _MAPAPI mapMessageBox(HWND hwnd, const char *message,
                                       const char *title, long int flag);

_MAPIMP long int _MAPAPI mapMessageBoxUn(HWND hwnd, const WCHAR *message,
                                         const WCHAR *title, long int flag);

  // ������ ��������� � �������� �����
  // HMAP � HSITE ���������� �����, � �������� �������
  // ������������ ���������
  // (��� ����� ��������� HSITE = HMAP, ��. sitapi.h)
  // message - ����� ���������
  // type - ��� ��������� (��. maptype.h : MT_INFO,MT_ERROR,...)

_MAPIMP void _MAPAPI mapMessageToLog(HMAP hMap, HSITE hSite,
                                     const char *message,
                                     long int type);

_MAPIMP void _MAPAPI mapMessageToLogUn(HMAP hMap, HSITE hSite,
                                       const WCHAR *message,
                                       long int type);

  // ��������� ������ ������ MapAccess.Dll
  // ���� ���������� ������ �� ����� �������� MAPACCESSVERSION
  // � ������ ��������� ����� ��������� ����

_MAPIMP long int _MAPAPI GetMapAccessVersion();
_MAPIMP long int _MAPAPI mapGetMapAccessVersion();
_MAPIMP long int _MAPAPI mapGetMapApiVersion();

  // ����������/��������� ���� ���������
  // 1 - ����������, 2 - �������, ... (��. Maptype.h)
  // (��-��������� - ����������)

_MAPIMP void _MAPAPI SetMapAccessLanguage(int code);
_MAPIMP int  _MAPAPI GetMapAccessLanguage();
_MAPIMP void _MAPAPI mapSetMapAccessLanguage(int code);
_MAPIMP int  _MAPAPI mapGetMapAccessLanguage();

  // ���������� ������������� ���� ��� ������ ���������
  // �� "��������" ��������� (������������� ��� ��������
  // �����, ������� �������� �� �������� �������,...)
  // ��� ��������� - 0x590,
  // wparm : -1 ����� ��������,-2 ����������,0-100 ������� ����������
  // lparm : ����� ���������
  // ��� ������ ��������� - ���������� ������������� � ����
  // (������������� ��������� ���� ����� �������� � ���� � �������)
  // ��� ���������� �������� ������� ����� 0x590
  // ���������� ���������� �������� ��������������

_MAPIMP HMESSAGE _MAPAPI mapSetHandleForMessage(HMESSAGE hwnd);
_MAPIMP HMESSAGE _MAPAPI mapGetHandleForMessage();

#ifdef WIN32API
  // ���������� ������������� ���� ��� ������ ��������� � �������� �����
  // hmap   - ������������� �������� ������
  // hwnd   - ������������� ����
  // event - ���� ����� ������� (1 - ����������� �����)
  // ��� ��������� WM_MAPEVENT (0x591)
  // wparm : ������������� �����, � ������� ��������� ������� (HMAP)
  // lparm : �������� �������
  // ��� ������ ��������� - ���������� ������������� � ����
  // (������������� ��������� ���� ����� �������� � ���� � �������)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetHandleForEvent(HMAP hmap, HWND hwnd, int event);

  // ��������� ������� �������� �������������� ���� ��� ������ ���������

_MAPIMP HWND _MAPAPI mapGetHandleForEvent(HMAP hmap);

  // ��������� ��������� ������� ������������ ��������� �������� �����
  // ������� ���������:
  //   left, top, width, height -  ������ �������� ��������� � ��������
  //   ����������� ���� �������. ���������� �������� ��������� � ��������
  //   ������������� �� ���� �� �������.
  //
  // ��� ������ � ��������� ��������� ��������� � �������� ����
  // ���������� ����.
  // ��� ��������� ��������� � �������� ���� ���������� �������.

_MAPIMP int _MAPAPI mapAdjustFormBounds(int* left, int* top, int* width,
                                        int* height);                           // 12/01/16

#endif

  // �������� ��� ������ ��� ����� ��������
  // ���������� : (1-CMLESS, 2-CMEQUAL, 3-CMMORE - ��. Maptype.h)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCompareString(const char *string,
                                          const char *filter);

_MAPIMP long int _MAPAPI mapCompareStringUn(const WCHAR *value,
                                            const WCHAR *temp);

  // ������������� ���� �� ������ date � ����� ��������
  // ������ ����� ����� ��� ��/��/���� ��� ��.��.����
  // ��� �������� ��� ����/��/��
  // ��� ������ ���������� ����, ����� - �������� ����

_MAPIMP long int _MAPAPI mapDateToLong(const char *date);

_MAPIMP long int _MAPAPI mapDateToLongUn(const WCHAR *date);

  // ������������� ���� �� �� ����� �������� � ������
  // ��/��/����
  // number - �������� �������� ����,
  // date   - ����� ������ ��� ����������
  // size   - ������ ������ � ������
  // ��� ������ ���������� ����, ����� - ����� ������� ������

_MAPIMP char* _MAPAPI mapLongToDate(long int number, char *date, long int size);

_MAPIMP WCHAR* _MAPAPI mapLongToDateUn(long int number, WCHAR *date, long int size);

  // ������������� ����� �� ������ time � ����� ������
  // ������ ����� ����� ��� ��:��:��
  // ��� ������ ���������� ����, ����� - �������� ����

_MAPIMP long int _MAPAPI mapTimeToLong(const char *time);

_MAPIMP long int _MAPAPI mapTimeToLongUn(const WCHAR *time);

  // ������������� ����� �� �� ����� ������ � ������
  // ��:��:��
  // number - �������� �������� �������,
  // time   - ����� ������ ��� ����������
  // size   - ������ ������ � ������
  // ��� ������ ���������� ����, ����� - ����� ������� ������

_MAPIMP char* _MAPAPI mapLongToTime(long int number, char *time, long int size);

_MAPIMP WCHAR* _MAPAPI mapLongToTimeUn(long int number, WCHAR *time, long int size);

  // ������������� ������� �������� � �������� �� ������
  // � �������� �������� � ��������
  // ������ ����� ����� ��� �����'CC.CC" ��� ���.��������
  // ��� Linux ������ ������� � (\xB0) �.�. ^
  // ��� ������ ���������� ����, ����� - �������� � ��������

_MAPIMP double _MAPAPI mapAngleToRadian(const char *angle);

_MAPIMP double _MAPAPI mapAngleToRadianUn(const WCHAR *angle);

  // ������������� �������� �������� �� ������ � ������ ����
  // �����'CC.CC"
  // ��� Linux ������ ������� � (\xB0) �.�. ^
  // angle  - ����� ������ ��� ����������
  // size   - ������ ������ � ������
  // ��� ������ ���������� ����, ����� - ����� ������� ������

_MAPIMP char* _MAPAPI mapRadianToAngle(double radian, char *angle, int size);

_MAPIMP WCHAR* _MAPAPI mapRadianToAngleUn(double radian, WCHAR *angle, int size);

  // ������ ������ ������� � ���� ������ XXXXX/XXXXX ��� �����������
  // (��������, 16777339 ������������� ������ 256/123)
  // format - ������ ������: 1 - XXXXX/XXXXX, 2 - XXXXXXXXXXX,
  // 0 - ����� �������� �� ��������� (mapGetObjectKeyFormat).
  // ����������� ����� �������� ������ - 12 ����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapObjectKeyToString(long int key , char *string,
                                              long int size, long int format);

_MAPIMP long int _MAPAPI mapObjectKeyToStringUn(long int key, WCHAR *string,
                                                long int size, long int format);

 // �������������� ������ ������� �� ������ XXXXX/XXXXX ��� �����������
 // � ����� (��������, 16777339 ������������� ������ 256/123)
 // string - ������� ������
 // long   - ���������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapStringToObjectKey(const char *string, long int *key);

_MAPIMP long int _MAPAPI mapStringToObjectKeyUn(WCHAR *string, long int *key);

  // ����������/��������� ������ ������ �������
  // 1 - XXXXX/XXXXX, 2 - XXXXXXXXXXX

_MAPIMP long int _MAPAPI mapGetObjectKeyFormat(void);

_MAPIMP long int _MAPAPI mapSetObjectKeyFormat(long int format);

  // ����������/��������� ���� � ���������� ����������, ���
  // ������������� ��������������� ����� ��� ����������������
  // ���-���� (���������� �������� ������ *.iml, ����� ���� ������ EPSG,
  // wmslist.xml, xml-����� � ��.)
  // ������������� ������������� ��� ������� ����������

_MAPIMP void _MAPAPI mapSetPathShell(const char *path);

_MAPIMP void _MAPAPI mapSetPathShellUn(const WCHAR *path);

_MAPIMP const char* _MAPAPI mapGetPathShell();
_MAPIMP const WCHAR * _MAPAPI mapGetPathShellUnicode();

_MAPIMP void _MAPAPI mapGetPathShellUn(WCHAR *path, long int size);

_MAPIMP void _MAPAPI mapGetPathShellEx(char *path, long int size);

  // ���������� ����� ��� INI-����� ����������

_MAPIMP void _MAPAPI mapSetIniPath(const char *inipath);

_MAPIMP void _MAPAPI mapSetIniPathUn(const WCHAR *inipath);

  // ��������� ��� INI-����� ����������
  // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapGetIniPath();

_MAPIMP const WCHAR* _MAPAPI mapGetIniPathUn();

  // ����������/��������� ���� � ���������� ������
  // path - ����� ������ � ��������� UTF-16 c ����� � ����� ��� ���������� ������
  // size - ����� ������ (������) � ������

_MAPIMP void _MAPAPI mapSetDataPathUn(const WCHAR *path);

_MAPIMP void _MAPAPI mapGetDataPathUn(WCHAR *path, long int size);

  // ���������� ����� ��� INI-����� ���������
  // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapSetMapIniName(HMAP hMap, const char *mapininame);

_MAPIMP const WCHAR* _MAPAPI mapSetMapIniNameUn(HMAP hMap, const WCHAR *mapininame);

  // ��������� ��� INI-����� ���������
  // ��� ������ ���������� ������ ������

_MAPIMP const char * _MAPAPI mapGetMapIniName(HMAP hMap);
_MAPIMP const WCHAR * _MAPAPI mapGetMapIniNameEx(HMAP hMap);

  // ��������� ��� INI-����� ��������� � ��������� UNICODE
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������ � ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetMapIniNameUn(HMAP hMap, WCHAR *name, long int size);

  // ������������ ��� INI-����� �� ����� ����������� ������
  // name - ���� � ������������ ����� ������ ��� ����� ������ � ���-������� ���
  // URL ����������
  // mapininame - ����� ������ ��� ���������� ����������
  // size - ������ ������, ����������������� ��� ���������� ���������� (�� ����� 260 ����)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapBuildIniName(const char *name, char *mapininame, long int size);

_MAPIMP long int _MAPAPI mapBuildIniNameUn(const WCHAR *name, WCHAR *mapininame, long int size);

  // ���������� ���� � ����� ������ ��������������� (RSC)
  // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapSetCommonRscPath(const char *rscpath);

_MAPIMP long int _MAPAPI mapSetCommonRscPathUn(const WCHAR *rscpath);

  // ��������� ���� � ����� ������ ��������������� (RSC)
  // ��� ������ ���������� ������ ������

_MAPIMP const char* _MAPAPI mapGetCommonRscPath();

_MAPIMP const WCHAR* _MAPAPI mapGetCommonRscPathUn();

  // ���������, ��� ��� ����� �� �������� ������� ������� ��� ����������
  // ��� ���������� ������������ ���������� ��������� ��������

_MAPIMP long int _MAPAPI mapIsNormalPath(const char * name);     // 08/06/14
_MAPIMP long int _MAPAPI mapIsNormalPathUn(const WCHAR * name);

  // ������������� ��� ������ ��� ���������� � �������� � ��� ����� (��� ����)        // 04/08/15
  // alias - ��� ������ ��� ���������� � �������� (WMS, WFS, WCS)
  // name  - ����� ������ ��� ���������� ����������
  // size  - ������ ���������� ������ � ������ � ������
  // ��� ������ ���������� ����
  
_MAPIMP long int _MAPAPI mapAliasToNormalNameUn(const WCHAR * alias, WCHAR * name, long int size);
_MAPIMP long int _MAPAPI mapAliasToNormalName(const char * alias, char * name, long int size);

  // ������������ ������������ ����� ����� �� ������� �����
  // ��� ����������� � ��������� ��������
  // source - �������� ����,
  // target - ���������� ������ (c:\abc..\klm.ext),
  // size   - ���������� ������ �������� ������ � �������� !!!
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapPathToShort(const char *source,
                                        char *target, long int size);

_MAPIMP long int _MAPAPI mapPathToShortUn(const WCHAR *source,             // 12/09/12
                                          WCHAR *target, long int size);

  // ��������� "��������" ��� �����
  // templ - ��������� ����, ������������ �������� �������� �������� ����;
  // ��������, ���� � ����������� ���������� (mapGetPathShell)
  // name  - ������ ��� �����
  // ���������� ��������� �� "��������" ��� �����
  // ��� ������ ���������� ����

_MAPIMP const char* _MAPAPI mapBuildShortName(const char *templ,
                                              const char *name);

_MAPIMP const WCHAR* _MAPAPI mapBuildShortNameUn(const WCHAR *templ,
                                                 const WCHAR *name);

  // ��������� "��������" ��� �����
  // � �������� ���������� ���� ����������� ���� � ����������� ���������� (mapGetPathShell)
  // name  - ������ ��� ����� � UNICODE
  // ���������� ��������� �� "��������" ��� �����
  // ��� ������ ���������� ����

_MAPIMP const WCHAR* _MAPAPI mapBuildShellShortNameUnicode(const WCHAR *name);

  // ��������� "�������" ��� ����� (������ ���� � �����)
  // templ - ��������� ����, ������������ �������� �������� ������ ����;
  // templ - ���� � ����������� ���������� (mapGetPathShell)
  // name - �������� ���� � �����; ��������, ��� �����
  // path - "�������" ��� ����� (��������� �� ������ ��� ���������� ����������, MAX_PATH)
  // ��� ������ ���������� ����

_MAPIMP char* _MAPAPI mapBuildLongName(const char *templ,
                                       const char *name, char *path);

_MAPIMP long int _MAPAPI mapBuildLongNameUn(const WCHAR *templ,
                                            const WCHAR *name, WCHAR *path);

  // ��������� ��������� ���� � ����� (������������ ������)
  // templ  - ���� � ������ (��������, mapGetMapPath(HMAP hMap))
  // name   - ������ ��� ����� (c:\abc\def...)
  // target - ����� ������ ��� ��������� ���������� ���� (��� �������, ���� ����� �����)
  // size   - ������ ������
  // ���������� ��������� �� ��������� ���� � ����� (.\def...)
  // ��� ������ ���������� ����

_MAPIMP char* _MAPAPI mapCutPath(const char *templ, const char *name,
                                 char *target, int size);

_MAPIMP WCHAR* _MAPAPI mapCutPathUn(const WCHAR *templ, const WCHAR *name,
                                    WCHAR *target, int size);

  // ��������� ������ ��� ����� �� ���������� ����
  // templ  - ���� � ������ (��������, mapGetMapPath(HMAP hMap))
  // name   - ��������� ���� (���������� � .\) ��� ������ ����
  // target - ����� ������ ��� ���������� ������� ����� �����
  // size   - ������ ������
  // ���������� ��������� �� ������ ���� (�:\abc\def... ��� \\NAME\abc\...)
  // ��� ������ ���������� ����

_MAPIMP char* _MAPAPI mapUnionPath(const char *templ, const char *name,
                                   char *target, long int size);

_MAPIMP WCHAR* _MAPAPI mapUnionPathUn(const WCHAR *templ, const WCHAR *name,
                                      WCHAR *target, long int size);

  // ������������ �������� ������ ��������� �����
  //  size     - ������ �����: size = 16 (16x16), size = 32 (32x32)
  //  bits     - ������� ������� �����: 32 ����� (16x16), 128 ���� (32x32)
  //  length   - ����� ������� data (10000 ���� - �������)
  // ��������� - �������, ���������� � data
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapMarkVectorization(int size, char *bits,
                                              int length, POLYDATA *data);

  // ������������� ��������� ������ �� ��������� OEM (DOS) � ANSI (WINDOWS)
  // ��� ������ ���������� 0

_MAPIMP char* _MAPAPI mapDos2Win(char *string, long int size);

  // ������������� ��������� ������ �� ��������� ANSI (WINDOWS) � OEM (DOS)
  // ��� ������ ���������� 0

_MAPIMP char* _MAPAPI mapWin2Dos(char *string, long int size);

#ifdef LINUXAPI
  // ������������� ��������� ������ �� ��������� OEM (DOS) � KOI8 (UNIX)
  // ��� ������ ���������� 0

_MAPIMP char* _MAPAPI mapDos2Koi8(char *string, long int size);

  // ������������� ��������� ������ �� ��������� KOI8 (UNIX) � OEM (DOS)
  // ��� ������ ���������� 0

_MAPIMP char* _MAPAPI mapKoi82Dos(char *string, long int size);

  // ������������� ��������� ������ �� ��������� ANSI (WINDOWS) � KOI8 (UNIX)
  // ��� ������ ���������� 0

_MAPIMP char* _MAPAPI mapWin2Koi8(char *string, long int size);

  // ������������� ��������� ������ �� ��������� KOI8 (UNIX) � ANSI (WINDOWS)
  // ��� ������ ���������� 0

_MAPIMP char* _MAPAPI mapKoi82Win(char *string, long int size);
#endif

  // ��������� ������� Dib
  // ���������� ���������� ���, ���������� �� ���� ����� ����������� �����

_MAPIMP long int _MAPAPI mapGetMapScreenDepth();

 /*********************************************************
 *                                                        *
 *   ������� ������������� ����� �� ����������� �����     *
 *                                                        *
 *   ��������� ������ ����� ������ ���������� �������,    *
 * � ������ ����� �������� ����������� � ����� ���������  *
 *                                                        *
 *********************************************************/

  // ���������� ������� ���������� ������� ��� �����
  // hmap     - ������������� �������� ����� (���������)
  // position - ���������� ������� � ������� ������� ��������� ���������
  // ���� position ����� ����, �� ���������� ��������� �� ��������������

_MAPIMP void _MAPAPI mapSetMarkerPosition(HMAP hmap, DOUBLEPOINT *position);

  // ��������� ������� ���������� ������� ��� �����
  // hmap     - ������������� �������� ����� (���������)
  // position - ���������� ������� � ������� ������� ��������� ���������
  // ���� ���������� �� �����������, ��� ��������� ���������, �� ���������� ����

_MAPIMP long int _MAPAPI mapGetMarkerPosition(HMAP hmap, DOUBLEPOINT *position);

  // ���������� ����� �������, ������� ����� ������������
  // ���������� ��� ����� ��������� ������� (������ mapSetMarkerPosition)
  // ��� ������� ��������� ���������� ������� mapGetMarkerPosition
  // call - ����� ���������� ������� (��. maptype.h),
  // parm - ��������, ������� ����� ������� ���������� �������
  // ��� ���������� ������, ������������ ����� ������� ����������,
  // ���������� ��� ��� ������� ������� � �������� �����������
  // call � parm.

_MAPIMP void _MAPAPI mapSetMarkerPositionCallAndParm(HMAP hmap, BREAKCALL call,
                                                     void *parm);

  /*********************************************************
  *                                                        *
  *              ������� ���������� �����������            *
  *                                                        *
  *********************************************************/

  // ���������� ���������� ������� ������ ����������� (�� ������ �� ������ ���������� ������)  // 03/06/16
  // ������� ������ ���������� �� �������� ������
  // ����� �������� ������ ��� ������ ��� ��������� ��������������� ��������
  // ������ ���� ����� 0
  // ���� ����� ����������, �� ������� ����������� ���������, ����� �������
  // �������, �� ������������� �������� ����� ������������� ��������� ��
  // �������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetMaxScreenImageSize(long int width, long int height);

  // ���������� ��������� ������� ������ ����������� (������ �� ������ ���������� ������)
  // ������� ������ ���������� �� �������� ������
  // ����� �������� ������ ��� ������ ��� ��������� ��������������� ��������
  // ������ ���� ����� 0
  // ���� ����� ����������, �� ������� ����������� ���������, ����� �������
  // �������, �� ������������� �������� ����� ������������� ��������� ��
  // �������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetScreenImageSize(long int width, long int height);
_MAPIMP long int _MAPAPI SetScreenImageSize(long int width, long int height);

 // ��������� ������������ ������ ����������� ����� � ������
 // ��������� ������ �������� - mapSetScreenImageSize

_MAPIMP long int _MAPAPI mapGetMaxScreenWidth();
_MAPIMP long int _MAPAPI mapGetScreenWidth();

 // ��������� ������������ ������ ����������� ����� � ������
 // ��������� ������ �������� - mapSetScreenImageSize

_MAPIMP long int _MAPAPI mapGetMaxScreenHeight();
_MAPIMP long int _MAPAPI mapGetScreenHeight();

  // ���������/���������� ������ ��������� �������� �����������
  // ������ � ����������� (50 - 4000). ��� ��������� ����������
  // ������ ��������
  // hdc - �������� �������� ���� ��� ������� ������� ��������
  // ������ � ��������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetScreenSize();
_MAPIMP long int _MAPAPI mapSetScreenSize(long int size);
_MAPIMP long int _MAPAPI mapSetScreenSizeEx(long int size, HDC hdc/* = 0*/);
_MAPIMP double _MAPAPI mapGetScreenSizeEx();
_MAPIMP double _MAPAPI mapSetScreenSizePro(double size);

  // ���������/���������� ����������� ��������������� �����������
  // ������ � ��������� (100 - 2000). ��� ��������� ����������
  // ������ �������� � ������������� �������� �������� ������ ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetScreenScale();
_MAPIMP long int _MAPAPI mapSetScreenScale(long int scale);
_MAPIMP double _MAPAPI mapGetScreenScaleEx();
_MAPIMP double _MAPAPI mapSetScreenScaleEx(double scale);

  // ���������/���������� �������� �������� ������ ������ � ������
  // �� ���� (1000 - 100000). ��� ��������� ���������� ������
  // �������� � ������������� ����������� ��������������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetScreenPrecision();
_MAPIMP double _MAPAPI mapGetHorizontalScreenPrecision();
_MAPIMP double _MAPAPI mapGetVerticalScreenPrecision();
_MAPIMP long int _MAPAPI mapSetScreenPrecision(long int value);
_MAPIMP void _MAPAPI mapSetScreenPrecisionEx(double valueHor, double valueVer);

  // �������� ����� ������� ��������� ������

_MAPIMP long int _MAPAPI mapScreenMeter2Pixel(double metric);
_MAPIMP double _MAPAPI mapScreenPixel2Meter(long int pixel);

 // ���������/���������� ������������ ������ � ���������� ������������ ������� ������
 // ��� �������� � ����������� ������ � ��������� �������� ������������� ���������
 // ������
 // maxcount - ���������� ������������ �������� ����(������) � ����������� ������
 // maxsize - ������������ ������ ������ ��������� � ����������� ������ ����� �����(�����)
 // ��� ���������� �������� �������� ����� ����������� ����� ����� ��� �������� ������,
 // ��� �������� � ����������� ������������ ������� (������� ������������������).
 // ��� ���������� ����������� �������� ��������� ����������� ������ �����
 // ����������� ����� ��� �������� ������

 _MAPIMP void _MAPAPI mapSetOpenDataLimits(long int maxcount, BIGINT maxsize);
 _MAPIMP void _MAPAPI mapGetOpenDataLimits(long int* maxcount, BIGINT* maxsize);


 /*********************************************************
 *                                                        *
 *           ������� ���������� � ������������            *
 *                                                        *
 *********************************************************/

  // ���������� ������ �� ��������� ���� LZW
  //  in      - ������ �������� ������
  //  out     - ������ �������� (������) ������
  //  sizein  - ������ ������� �������� ������
  //  sizeout - ������ ������� �������� (������) ������
  // ���������� ������ ������ ������ � �������� ������
  // ��� ������ ��� ��� ������ ����� ��� �� 20%
  // �������� ������ �� ����������� � ������� ���������� 0.

_MAPIMP long int _MAPAPI mapCompressLZW(const char *in, long int sizein,
                                        char *out, long int sizeout);

  // ������������ ������ �� ��������� ���� LZW
  //  in      - ������ �������� (������) ������
  //  out     - ������ �������� ������
  //  sizein  - ������ ������� �������� (������) ������
  //  sizeout - ������ ������� �������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDecompressLZW(const char *in, long int sizein,
                                          char *out, long int sizeout);

  // ���������� ����������� �� ��������� JPEG
  // in       - ������ �������� ������
  // width    - ������ ����������� (��������)
  // height   - ������ ����������� (��������)
  // bit      - ���������� ��� �� ������� (����������� ������ �����������
  //            � ����������� ��� �� �������, ������ 24)
  // compressionValue - ������� ������ �������� (1-100, 1-������������ ������,
  // 100-������ ��� ������ ��������), ������������� �������� 60.
  //  out     - ������ �������� ������
  //  sizeout - ������ ������� �������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapCompressJPEG(const char *in, int width, int height,
                                         int bit, int compressionValue,
                                         char *out, long int sizeout);

  // ������������ ����������� �� ��������� JPEG
  // in       - ������ �������� (������) ������
  // sizein   - ������ ������� �������� (������) ������
  // width    - ������ ����������� (��������)
  // height   - ������ ����������� (��������)
  // bit      - ���������� ��� �� ������� (����������� ������ �����������
  //            � ����������� ��� �� �������, ������ 24)
  //  out     - ������ �������� ������
  //  sizeout - ������ ������� �������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDecompressJPEG(const char *in, long int sizein,
                                           int width, int height, int bit,
                                           char *out, long int sizeout);

 /*********************************************************
 *                                                        *
 *                   �������� �������                     *
 *                                                        *
 *********************************************************/

#ifdef WIN32API
  // ��������� ����� ����� ������
_MAPIMP unsigned long int _MAPAPI GetKeyNumber();
#endif

 /*********************************************************
 *                                                        *
 *           ������� ������� � ���-�������                *
 *                                                        *
 *     ��� �������� ����� �� ���-������� � �������        *
 *      ������� �������� ���� ���������� ������ ����      *
 *         "HOST#����#����#ALIAS#��������_���_�����"      *
 *    (��������: "HOST#233.47.123.99#2047#ALIAS#Noginsk") *
 *                                                        *
 *  �������� ��� ����� �� �������� ����� � �������� ����� *
 *     ������ "HOST#" � "ALIAS#" �������� ���������       *
 *           ������� ��� ��������� � ���-�������          *
 *                                                        *
 *********************************************************/

  // ��������� �������� �� ��� ��������������� ������ �� �������
  // ���� ��, �� ���������� ��������� �������� (1 - ����������
  // ������ ��� ����� �������, 2 - �������� ��� �������)

_MAPIMP long int _MAPAPI mapIsAliasName(const char *name);

_MAPIMP long int _MAPAPI mapIsAliasNameUn(const WCHAR *name);

  // ��������� ��� ������ ������ �� ������ ������ �����, ���������� ��� �����
  // ���������� ��������� �� ��� ������ (������ ������ ����� ALIAS#) ��� 0

_MAPIMP const char* _MAPAPI mapGetDataNameFromAlias(const char *name);

_MAPIMP const WCHAR* _MAPAPI mapGetDataNameFromAliasUn(const WCHAR *name);

  // ������������ ��� ������� �� �������
  // � ������� "HOST#����#����#ALIAS#��������_���_�����"
  // host  - ��� �����
  // port  - ����� �����
  // alias - ��� ������� (�������� ��� �����)
  // name  - ��� ������ ��� ���������� ���������
  // size  - ������������ ������ � ������ ������
  // ��� ������ � ���������� ���������� ����

_MAPIMP long int _MAPAPI mapBuildAliasName(const char *host, long int port,
                                           const char *alias,
                                           char *name, long int size);

_MAPIMP long int _MAPAPI mapBuildAliasNameUn(const WCHAR *host, long int port,
                                             const WCHAR *alias, WCHAR *name,
                                             long int size);

  // ��������� ����� ����������� � ��� ��������
  // ��� ���������� ����������� ���������� ����

_MAPIMP long int _MAPAPI mapActiveServerCount();

  // ��������� ��������� ����������� � �������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ��� ��������� ��������\���������� ������ � ��� ������� �������������
  // ����� ������ ������ �������� ������ ��������� ��������� �����������
  // � ��� ������ �������� ��������� ���������
  // ���� ����� ������ �������� ������ � ������ "HOST#..." ��� "ALIAS#..."
  // ����������� �� �����������, �� ����� ��������, ��� ������ ������� �
  // ������� ���������� ��������� ����������
  // ���� ����������� � ������� ����������� - ���������� ��������� ��������

_MAPIMP long int _MAPAPI mapIsServerActiveEx(long int number);

  // ��������� ������ � ��������� ����������� ��������� �������
  // ���� ���������� �������� - ���������� ������� ��������

_MAPIMP long int _MAPAPI mapIsServerMonitoringEnable(long int number);

  // ��������� ������ ��� ������� �� ������ ����������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ���������� ����������������� ����� ������ ��� ������,
  // ��������: 0x00040503 ������������� ������ 4.5.3
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetServerVersion(long int number);

  // ������� ���������� � ��������� �������� ���������� (����������)
  // versin  - ����� ��� ���������� ������ � ������ � ������� ��� �������
  // size    - ������ ������ (�� ����� 80 ����)
  // state   - ��������� ��� �������, ���������� � ���������� �������,
  //           ���� ��������� �� ����������, �� ������������ ����������� �����
  // ����� ���������� ��������� ������ ���������� ���������� ������� �����
  // ������ mapFreeServerState � ����������, ���������� � mapGetServerState
  // ��� ������ ���������� ����

_MAPIMP GSMONITOR* _MAPAPI mapGetServerState(long int number, WCHAR *version,
                                             long int size, long int state);

  // ���������� ������� ����� ��������� ������ ����������� ��������� �������

_MAPIMP void _MAPAPI mapFreeServerState(GSMONITOR *buffer);

  // ��������� ��������� �� ����������� � ����������� ������������
  // ��� ��������� ����� ������ ������
  // name - ����� � ������� "HOST#����:����#ALIAS#��������_���_�����",
  //        ��� "HOST#����" ��� "HOST#����:����"
  // ��� �������� �������� ���������� ����� �����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCheckConnectForAlias(const char *name);

_MAPIMP long int _MAPAPI mapCheckConnectForAliasUn(const WCHAR *name);

  // ������� ����� ���������� � ���-��������
  // name - ��� ����� (�� 256 ��������),
  //        ��� ������ ������ "XXX.XXX.XXX.XXX"
  // ���� �������� ����� ���� - ������ ������ �� ��������� ����� "localhost".
  // port - ����� ����� �� 1024 �� 65536, �� ��������� - 2047 (���� port = 0)
  // � ������ ������ ������������ ����������� ���������� ��� ���������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapOpenConnect(const char *name, long int port);

_MAPIMP long int _MAPAPI mapOpenConnectUn(const WCHAR *name, long int port);

  // ������� ����� ���������� � ���-��������
  // name - ��� ����� (�� 256 ��������),
  //        ��� ������ ������ "XXX.XXX.XXX.XXX"
  // ���� �������� ����� ���� - ������ ������ �� ��������� ����� "localhost".
  // port - ����� ����� �� 1024 �� 65536, �� ��������� - 2047 (���� port = 0)
  // cansleep - ���������� �� �������� ������������ (�������) ����������,
  //        ��� ���������� ����������� ������� � �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapOpenConnectEx(const char *name, long int port, long int cansleep);

_MAPIMP long int _MAPAPI mapOpenConnectExUn(const WCHAR *name, long int port, long int cansleep);

  // ��������� - ����� �� ������� ����������
  // ��� ������ (���������� �� �������) ���������� ����
  // ��� ��������� ���������� ���������� "-1"
  // ���� ���������� ����� ���� �������, �� ���������� ������������� ��������

_MAPIMP long int _MAPAPI mapCanCloseConnect(long int number);

  // ������� ���������� � ���-��������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ��� ������ (���������� �� �������) ���������� ����
  // ��� ��������� ���������� ���������� "-1"
  // ��� �������� ���������� ���������� ������������� ��������

_MAPIMP long int _MAPAPI mapCloseConnect(long int number);

  // �������� ��������� ���������� � ���-��������
  // ���������� �� �������� ���� �� �������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // name - ��� ����� (�� 256 ��������),
  //        ��� ������ ������ "XXX.XXX.XXX.XXX"
  // ���� �������� ����� ���� - ������ ������ �� ��������� ����� "localhost".
  // port - ����� ����� �� 1024 �� 65536, �� ��������� - 2047 (���� port = 0)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetConnectParametersEx(long int number,
                                                   const char *name, long int port);

_MAPIMP long int _MAPAPI mapSetConnectParametersExUn(long int number,
                                                     const WCHAR *name, long int port);

  // ��������� ����� ����� ��� ����� � ���-��������
  // ����� ����� �� 1024 �� 65536, �� ��������� - 2047
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()

_MAPIMP long int _MAPAPI mapGetConnectPortEx(long int number);

  // ��������� ���\����� �����
  // ���� ���� ���������� ����� ����� - ������������ �������� 1,
  // ���� ��� ����� - ������������ �������� 2.
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ���� ����������� ��� �������� - ������������ ����� �����
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������ (��� ����� ����� �� ����� 256)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetConnectHostEx(long int number, char *name, long int size);

_MAPIMP long int _MAPAPI mapGetConnectHostExUn(long int number, WCHAR *name, long int size);

  // ���������������� ������������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ���� ���������� � �������� �� ���� ����������� -
  // �������� ����������� � �������������� ����� �����������
  // ������ ������ ������������ � ������������� ���� �� ��������� MD5 (� ���� ����)
  // ��� ��������� ���� ������ ������� ������������ ������� svStringToHash 
  // (������� � gisdlgs.h)  
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRegisterUserEx(long int number, TMCUSERPARM * parm);

  // ���������������� �������� ������������ �� ��� ������������ ��� �������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ���� ���������� � �������� �� ���� ����������� -
  // �������� ����������� � �������������� ����� �����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRegisterSystemUserEx(long int number);

  // ������� � ������ ��������� ����������� ������������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ����� �������� ���������� ��������� �� ������� ����������
  // ����������� � ��� ������������ �������� ����� ����� ��������
  // ��������� mapRegisterUser()

_MAPIMP void _MAPAPI mapUnRegisterUserEx(long int number);

  // ��������� ��� ����������� ������������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ���� ����������� ������������ ����������� ����� ������� mapRegisterSystemUserEx,
  // �� ������������ ������������� ��������

_MAPIMP long int _MAPAPI mapGetRegisterUserType(long int number);

  // ��������� ������ ��������� ������������ ���� �� ���-�������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // buffer - ����� ������ ��� ���������� ������ ����,
  //          ��������� TMCMAPLIST ������� � maptype.h
  // ���� buffer ����� ����, ���������� ������ ����������� ������� ������
  // length - ����� ���������� ������� ������
  // ���������� ����� ������ ��������� ������ ��� 0

_MAPIMP long int _MAPAPI mapGetMapListforUserEx(long int number, TMCMAPLIST *buffer, int length);

  // ��������� ������ ��������� ������������ ������� �� ���-�������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // buffer - ����� ������ ��� ���������� ������ �������,
  //          ��������� TMCMAPLIST ������� � maptype.h
  // length - ����� ���������� ������� ������
  // ���������� ����� ������ ��������� ������ ��� 0

_MAPIMP long int _MAPAPI mapGetAlsListforUserEx(long int number, TMCMAPLIST *buffer, int length);

  // ��������� ������ ��������� ������������ ������ �� ���-�������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // buffer - ����� ������ ��� ���������� ������ ������,
  //          ��������� TMCMAPLIST ������� � maptype.h
  // ���� buffer ����� ����, ���������� ������ ����������� ������� ������
  // length - ����� ���������� ������� ������
  // ���������� ����� ������ ��������� ������ ��� 0

_MAPIMP  long int _MAPAPI mapGetMtwListforUserEx(long int number, TMCMAPLIST *buffer, int length);

  // ��������� ������ ��������� ������������ ������� �� ���-�������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // buffer - ����� ������ ��� ���������� ������ �������,
  //          ��������� TMCMAPLIST ������� � maptype.h
  // ���� buffer ����� ����, ���������� ������ ����������� ������� ������
  // length - ����� ���������� ������� ������
  // ���������� ����� ������ ��������� ������ ��� 0

_MAPIMP long int _MAPAPI mapGetRswListforUserEx(long int number, TMCMAPLIST *buffer, int length);

  // ��������� ��� ������������, ��������������� � ���-�������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ��� ������ ���������� ������ ������

_MAPIMP const char * _MAPAPI mapGetCurrentUserNameEx(long int number);

  // ���������� ������� ��� ������������ ������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ����� - 1, ������ - 2, ������� - 3, ������  - 4
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetActiveDataType(long int number, long int type);

  // ��������� ������� ��� ������������ ������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ����� - 1, ������ - 2, ������� - 3, ������  - 4
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetActiveDataType(long int number);

  // ��������� ���� � ����� ��� �������� ���������� ������ � ��� ������

_MAPIMP const char* _MAPAPI mapGetCachePath();
_MAPIMP const WCHAR* _MAPAPI mapGetCachePathUn();

  // ���������� ���� � ����� ��� �������� ���������� ������ � ��� ������
  // ���� ���������� �� ���������� ���� � ����� ��� ����������� ������,
  // �� ��� ������������� ����� ��������� ������ ��������� ����� Temp
  // � ����� Panorama.Cache.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetCachePath(const char *path);
_MAPIMP long int _MAPAPI mapSetCachePathUn(const WCHAR *path);

  // �������� ��� ������ ��� ���� ���� �������� ���������,
  // �������� � ��� �������
  // hMap  -  ������������� �������� ������
  // ��� ������������� ��������� ��� ���������� ����� �� ��� �������
  // ��� ����������� �������� ����� ����������� ����������,
  // � ������� ����������� ��������� � ������
  // ����� ��� ����������� (�������������) � ������������
  // � �������� ���������� �� ��� �������

_MAPIMP void _MAPAPI mapClearDocCache(HMAP hMap);

  // �������� ��� ������ ��� �������� ���������������� �����,
  // �������� � ��� �������
  // hMap  -  ������������� �������� ������
  // hSite - ������������� �������� ���������������� �����
  // ��� ������������� ��������� ��� ���������� ����� �� ��� �������
  // ��� ����������� �������� ����� ����������� ����������,
  // � ������� ����������� ��������� � ������
  // ����� ��� ����������� (�������������) � ������������
  // � �������� ���������� �� ��� �������

_MAPIMP void _MAPAPI mapClearSiteCache(HMAP hMap, HSITE hSite);

  // ��������� ������� �� ����� �� ������� ��� ��������
  // hmap -  ������������� �������� ������
  // hSite - ������������� �������� ���������������� �����
  // (��� ������� (��������) ����� hSite = hMap)
  // ���� ����� ������� �� ������� ���������� ��������� ��������

_MAPIMP long int _MAPAPI mapIsMapFromServer(HMAP hMap, HSITE hSite);

  // ��������� ������ ����� �� �������, ��������� ��� ������ ������            // 02/07/14
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // folder - ���� � �����, � ������� ������������� ������ ������ � ����� ��� 0
  // ��������, "Data\\Maps"
  // ���� folder ����� 0, �� ������������� ������ ������� ���� ��������� �����
  // allfiles - ������� ������� ���� ������ � ����� folder, ���� �� ����������,
  // �� ����� ����� ������ ���������� ����� � ������ MAP,SIT,SITX,RSC,MTW,MTQ,RSW
  // parm   - ����� ������ ��� ���������� ������ ����������� ������ ��� 0
  // ���� parm ����� 0, �� ������������� ������ ������, ��������� ��� ���������� ������
  // length - ������ ������ ��� ���������� ������
  // ������ ������ ����������� ������ ��� ������ � �����, ��������������� �������������
  // � �������� ����� ��� ��������
  // ��� �������� ���������� ���������� ������ ��������������� ������
  // ���� ������ ������ ��������� ������ ������, �� ������ ������� �� ���������.
  // ����� ����� �������� ������� ����� � ��������� ������ ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetFolderList(long int number, const WCHAR * folder, long int allfiles,
                                          TMCDATALIST * parm, long int size);

  // ������� ����� �� ������� ������������ ������ ��������� �����            // 26/06/14
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // folder - ���� � ����������� �����
  // ��������, "Data\\Maps" ��� "Data/Maps",
  // ��� "Data" - �������� ����� � ���������� ��� �������, "Maps" - ����������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCreateFolderOnServer(long int number, const WCHAR * folder);

  // ������� ����� �� ������� ������������ ������ ��������� �����            // 27/06/14
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // folder - ���� � ��������� �����
  // ��������, ��� �������� ����� "Maps": "Data\\Maps" ��� "Data/Maps",
  // ��� "Data" - �������� ����� � ���������� ��� �������, "Maps" - ��������� �����
  // deletefiles - ������� ��� ����� � ����� (���� ������ ��������� ��������)
  // deletefolders - ������� ��� �������� � ������� � ��� (���� ������ ��������� ��������)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteFolderOnServer(long int number, const WCHAR * folder,
                                                 long int deletefiles, long int deletefolders);

  // ������� ���� �� �������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // file - ���� � ���������� �����
  // ��������, "Data\\Maps\\image.rsw",
  // ��� "Data" - �������� ����� � ���������� ��� �������, "image.rsw" - ��������� ����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapDeleteFileOnServer(long int number, const WCHAR * file);

  // ������������� (�����������) ���� ��� ����� �� �������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // source - ���� � ����������� ����� ��� �����
  // ��������, "Data\\Maps\\image.sitx",
  // ��� "Data" - �������� ����� � ���������� ��� �������, "image.sitx" - ������������ ����
  // target - ����� ���� � ����� ��� �����
  // ��������, "Storage\\Roads\\road_M4.sitx",
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRenameFileOnServer(long int number, const WCHAR * source, const WCHAR * target);

  // ��������� ���� �� �������                                               // 26/06/14
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // folder - ���� ��� ���������� �����, ���� ������ ���������� � ������ �����,
  //          ��������� ��� ������ ������
  // ��������, "Data\\Maps" ��� "Data/Maps",
  // ��� "Data" - �������� ����� � ���������� ��� �������
  // file   - ���� � �����, ������� ����� ������� � ����� �� ������� (���� ������
  //          ��������� ������, � �� ����������� ���).
  // ��� �����, ���������� � �������� ������/������ �����������.
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveFileOnServer(long int number, const WCHAR * folder,
                                             const WCHAR * file);

  // ��������� ����� �� �������                                               // 02/07/14
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // folder - ���� ��� ���������� �����, ���� ������ ���������� � ������ �����,
  //          ��������� ��� ������ ������
  // ��������, "Data\\Maps" ��� "Data/Maps",
  // ��� "Data" - �������� ����� � ���������� ��� �������
  // hMap -  ������������� �������� ������
  // hSite - ������������� �������� ���������������� �����
  // (��� ������� (��������) ����� hSite = hMap)
  // rscsave - ������� ������������� ���������� ����� RSC �� ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveMapOnServer(long int number, const WCHAR * folder,
                                            HMAP hMap, HSITE hSite, long int rscsave);

  // ��������� ���� �� ������� (���� ���� ������ � ����������� �����)
  // alias   - ����� ����� �� �������, ������� � ����� ����������� ����� (����� ����������� ������,
  //           ������ ����, ������ � �������)
  // path    - ����, �� �������� ����� �������� ���� (����� ������ ���� ����������� ������ �����)
  // size    - ������ ����, ����������� ����
  // error   - ���� ��� ������ ���� ������, ���� ������� ������ ����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapReadFileOnServer(long int number, const WCHAR * alias, WCHAR * path, long int size,
                                             long int * error);

  // ��������� ������ � ���� ������ �� � ���                   // 24/08/15
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // handle  - �������������� ����, �������� ���������� ��������� � ���� �������� ������ � ���� ������
  //           (WM_PROGRESSBAR, WPARAM = -1 - �����, LPARAM - ����� ��������� � ��������� ����������,
  //                            0-100 - % ����������, -2 - ���������� ��������)
  //           ���� ��������� ���������� ��� �������� ������� ������ ������ (�����) �� ������ �
  //           ��� �������� ������� � ���� ������ �� �������
  // dslist  - ���� � ����� - ������ ����������� ������� ������ (111, 222, 333 - ����� ������)
  //           <?xml version="1.0" encoding="UTF-8"?> <dsl> 111, 222, 333 </dsl>
  // logname - ����� ������ ��� ��������� ����� ����� � ���������� �������� ������� � ���� ������
  // size    - ������� ������ ��� ������ ����� ����� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveToGeoDB(long int number, HMESSAGE handle,
                                        const WCHAR * dslist, WCHAR * logname, long int size);

  // ��������� ������� �� �������� ������� ������, ������� ��� �������� �� ��� ������,     // 09/02/16
  // � ���� ������ �� � ���
  // ������ ������ ����� ���� ��������� �������� ������ ����������� �� ��� ������
  // � ����������� ����� ��� ����� ������
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // handle  - ������������� ����, �������� ���������� ��������� � ���� �������� ������ � ���� ������
  // dslist  - ��� ����� - ������ ����������� ������� ������
  // callevent - ����� ������� ���������� ������ ��� ����������� � �������� ������������ ������� ������ (��. maptype.h)
  // parm    - ����� ����������, ������� ����� �������� ��� ������ ������� (������ ����� ������ ����������� ���������),
  //           ������ ���������� � ���������� ������� ���������� ������� �� 0 �� 100
  // logname - ����� ������ ��� ��������� ����� ����� � ���������� �������� ������� � ���� ������
  // size    - ������� ������ ��� ������ ����� ����� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCallGeoDBLoader(long int number, HMESSAGE handle, const WCHAR * dslist, WCHAR * logname, long int size);
_MAPIMP long int _MAPAPI mapCallGeoDBLoaderEx(long int number, EVENTSTATE callevent, void * parm,
                                              const WCHAR * dslist, WCHAR * logname, long int size);

  // ��������� ������� �� ������������ ����������� �� ������� ������ ����� ������ �� � ���     // 22/06/16
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // geolist - ��� ����� - ������ ����������� ������� ������
  // callevent - ����� ������� ���������� ������ ��� ����������� � �������� ������������ ������� ������ (��. maptype.h)
  // parm    - ����� ����������, ������� ����� �������� ��� ������ ������� (������ ����� ������ ����������� ���������),
  //           ������ ���������� � ���������� ������� ���������� ������� �� 0 �� 100
  // logname - ����� ������ ��� ��������� ����� ����� � ���������� �������� ������� � ���� ������
  // size    - ������� ������ ��� ������ ����� ����� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCallGeoLevel(long int number, EVENTSTATE callevent, void * parm,
                                         const WCHAR * geolist, WCHAR * logname, long int size);
_MAPIMP long int _MAPAPI mapCallGeoLevelEx(long int number, EVENTSTATE callevent, void * parm,
                                           const WCHAR * geolist, WCHAR * logname, long int size,
                                           long int * error);

  // ��������� ����������� ������� ���������� ������� ������ � ���� ������ �� � ���
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapIsGeoDBEnable(long int number);
                                        
  // ��������� ������ �������������� � ����� ������ ��������      // 13/11/15
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // buffer - ����� ������ ��� ���������� ���������� �������
  // size   - ������ ������
  // ������ �������� ������� �� ���� ��������� �����, ��������������� �������� '\n'
  // � ������ ������ ������������ ������ �������� �������� ����, �� ������ - ������� (�������),
  // � ������� - ������ (�������). ������� ������ ����������� ��������.
  // ����� �������� �������� ������ ����������� ������� ��������������� ������
  // (����������, ����������� ����������� ������ � ������).
  // ��������:
  // SXF,RSC,DIR,MIF,MID,KML,SITX,XML,SHP,DBF,PRJ,SHX,preview.png,
  // RSW,TAB,INI,JPG,preview.png,TIF,IMG,TIFF,
  // MTW,TIFF,TIF,preview.png,HGT,
  // ��� ������ ���������� ����, ����� - ������ ��������� ������

_MAPIMP long int _MAPAPI mapGetGeoDBFormats(long int number, char * buffer, long int size);

  // ��������� ������ �������������� � ����� ������ �����
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // buffer - ����� ������ ��� ���������� ���������� �������
  // size   - ������ ������
  // ������ ����� ������� �� ��������� �����, ��������������� �������� '\n'
  // � ������ ������ ������ ������������� ������, � ����� ������� ������� �������� ������ � ��������� UTF-8
  // ��������: "7,�������-�������������� �����\n"
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetGeoDBGroups(long int number, char * buffer, long int size);      // 25/04/16

  // ��������� ���������� �� ����������� ������ ����� �� ������       // 05/03/16
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // alias - ����� ������ �� �������
  // error - ��� ������ ������� (��. maperr.rh)
  // ��� ������ ���������� ����, ����� - ��� ������ (1 - �����, 2 - �����, 3 - �������)

_MAPIMP long int _MAPAPI mapIsCopyDataEnabled(long int number, const WCHAR * alias, long int type, long int * error);

  // ����������� ����� ������ � ��� ������� �� ������                 // 07/03/16
  // number - ����� ��������� ����������� � ��� ������� �� 1 �� mapActiveServerCount()
  // alias  - ����� ������ �� �������
  // type   - ��� ������ (1 - �����, 2 - �����, 3 - ������� ��� 0 - ��������� ����������)
  // target - ��� ����� ��������� ������ ������ (���� ������ ������ �����, �� ��� �����������
  //          � ������ ������ � ���� ������
  // error  - ��� ������ ������� (��. maperr.rh)
  // ��� ������ ���������� ����, ����� - ��� ������ (1 - �����, 2 - �����, 3 - �������)

_MAPIMP long int _MAPAPI mapCopyDataFromServer(long int number, const WCHAR * alias, long int type,
                                               const WCHAR * target, long int * error);

 /*********************************************************
 *                                                        *
 *    ������� �����������/������������� ������            *
 *                                                        *
 *********************************************************/

   // �������� ������������� ��� ������� �����������
   // key  - ������, ���������� �������� ���� ��� ����������� ������
   //        ���� ������ ����� ��������� ����������� ����������,
   //        ��������, ������� �������������� ������ ������������ � ��������
   //        ������� �� ��������� MD5
   // size - ����� ������ (������ 16 ����)
   // ����� ���������� �����������/�������������� ����� ���������� �������
   // �������� mapDeleteCoder
   // ��� ������ ���������� ����

_MAPIMP HANDLE WINAPI mapCreateCoder(const char *key, int size);

   // ������������ ������� ������ �������� ������ (����� ������� ������ 16)
   // hcoder - ������������� ��� ������� �����������
   // memory - ����� ������� ������, ������� ����� ������������
   // size   - ������ ������� ������ ��� �����������, ������� 16 ������
   // ��� ����������� ����������� �������� XOR � ������������ ������ ������
   // ��������� ����� �������� ��� ����������� ��� ����������� ���������� ������
   // ��� ������ ���������� ����

_MAPIMP long int WINAPI mapCoderOn(HANDLE coder, char *memory, long int size);

   // ������������� ������� ������ �������� ������ (����� ������� ������ 16)
   // hcoder - ������������� ��� ������� �����������
   // memory - ����� ������� ������, ������� ����� ������������
   // size   - ������ ������� ������ ��� �����������, ������� 16 ������
   // ��� ����������� ����������� �������� XOR � ������������ ������ ������
   // ��������� ����� �������� ��� ����������� ��� ����������� ���������� ������
   // ��� ������ ���������� ����

_MAPIMP long int WINAPI mapCoderOff(HANDLE coder, char *memory, long int size);

   // ���������� ������� ����� ���������� �����������/��������������

_MAPIMP void WINAPI mapDeleteCoder(HANDLE coder);

}       // extern "C"


 /*********************************************************
 *                                                        *
 *                ���������� �������                      *
 *                                                        *
 *********************************************************/

extern "C"
{
  // ������� ������ � �������������� ������������ �� ����
  // (���������,���������,���������...)
  // name - ��� ������������ ����� (MAP, SIT, MTW, RSW, MPT)
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������, ��� ���� �� �����������
  // ����� \Log\name.log � \Log\name.tac - �������� ������ � ������ ����������
  // error - ����� ���������� ������� ���������� �������� ��� ������
  //        (����� HMAP ����� 0) ��� 0; ���� ������ ��������� � maperr.rh
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapOpenDataEx(const char *name,
                                   long int mode, long int *error);

  // ������� ������ � �������������� ������������ �� ����
  // (���������,���������,���������...)
  // name - ��� ������������ ����� (MAP, SIT, MTW, RSW, MPT)
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������, ��� ���� �� �����������
  // ����� \Log\name.log � \Log\name.tac - �������� ������ � ������ ����������
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapOpenData(const char *name, long int mode = 0);

  // ������� ��������� ������ (���������� mapOpenData)
  // ���������� ������������� �������� ��������� �����
  // mapname - ��� ����� �����
  // mode - ����� ������/������ (GENERIC_READ, GENERIC_WRITE, ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������, ��� ���� �� �����������
  // ����� \Log\name.log � \Log\name.tac - �������� ������ � ������ ����������
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapOpenMap(const char *mapname, long int mode = 0);

  // �������� ������������ ���������� ������ �, ���� ����, �� ����������
  // ��������� �� �������� ���������� 0 - ������ ������������� ���������
  //                                  1 - �������������
  // ��������� MAPREGISTER, LISTREGISTER ������� � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI CheckAndUpdate(MAPREGISTER *mapreg,
                                        LISTREGISTER *listreg,
                                        long int priority);

  // ������� ����� ����� (����� ��������� �����)
  // mapname - ������ ��� ����� �����
  // rscname - ������ ��� ����� ��������
  // ���������� ������������� �������� ��������� �����
  // ��������� MAPREGISTER � LISTREGISTER ������� � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapCreateMap(const char *mapname, const char *rscname,
                                  MAPREGISTER *map, LISTREGISTER *sheet);

  // ������� ���������������� �����
  // mapname - ������ ��� ����� �����
  // rscname - ������ ��� ����� ��������
  // ���������� ������������� �������� ��������� �����
  // ��������� CREATESITE ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP HMAP _MAPAPI mapCreateSite(const char *mapname,
                                   const char *rscname,
                                   CREATESITE *createsite);

_MAPIMP HMAP _MAPAPI mapCreateSiteEx(const char *mapname,
                                     const char *rscname,
                                     CREATESITEEX *createsite);

  // ������� ���������������� ����� �� �������� �����
  // hmap -  ������������� �������� ������
  // mapname - ������ ��� ����� �����
  // rscname - ������ ��� ����� ��������
  // ��������� CREATESITE ������� � maptype.h
  // ���������� ������������� �������� ���������������� �����
  // ��� ������ ���������� ����

_MAPIMP HSITE _MAPAPI mapCreateAndAppendSite(HMAP hmap,
                                             const char *mapname,
                                             const char *rscname,
                                             CREATESITE *createsite);


  // ������� ���������������� ����� �� �������� �����
  // hmap -  ������������� �������� ��������� �����
  // mapname - ������ ��� ����� �����
  // rscname - ������ ��� ����� ��������
  // issitx  - ������� �������� ����� ���� SITX
  // ��� ������ ���������� ����
  
_MAPIMP HSITE _MAPAPI mapCreateAndAppendSiteForMap(HMAP hmap,
                                             const char * mapname,
                                             const char * rscname);

_MAPIMP HSITE _MAPAPI mapCreateAndAppendSiteForMapUn(HMAP hmap,              // 23/01/15
                                                     const WCHAR * mapname,
                                                     const WCHAR * rscname,
                                                     long int issitx = 0);
                                             
 // ���������� ��������� ����� DIB � ����
 // flag - ���������� ���� �� ��������� �������� (1) ��� ����������� ���������� (0)
 // ��-��������� ��� ���������� ���� ����� ��������������� ���������
 // ��� ������������ ��������. ��� ������� ���� ��� ������� ������ �����������
 // (����� ������ - ��������). ��������� ������� ����� ����� ��������� ���,
 // ����� � ��� ����������� ������ �������.
 // �� ��� ��������� ��������� ���������� ����� ������ ����� ��������� ��������,
 // ������� ��� ����� ���������.
 // ������������ ������ ����� ������ ��������������� ����� ������������, � �����
 // ��������������� ���������� ��������.
 // ���������� ���������� ��������

_MAPIMP long int _MAPAPI mapSetPaintStep(HMAP hmap, long int flag);

 // ��������� �������� ���������� ������ DIB � ����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetPaintStep(HMAP hmap);

#ifdef WIN32API
  // ��������� ������ � ��������� ��������
  // ���� ������ �������� - ��������� ������� �� ���������
  // � �� ��������������

_MAPIMP long int _MAPAPI GetGroupObjectsAccess();
_MAPIMP long int _MAPAPI SetGroupObjectsAccess(long int access);
#endif

 // ������ �������� ���������� ������� (���������� �������)
 // info - ������������� ������� ����� � ������
 // ���� ������ ���������, ���������� 1, ����� 0

_MAPIMP long int _MAPAPI mapObjectIsGroup(HOBJ info);

 // ������ ������� ������� � ������ (���������� �������)
 // info - �������� ������
 // infofirst - ������ ������ � ������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapFirstObjectInGroup(HOBJ infofirst, HOBJ info);

 // ������ ���������� ������� � ������ (���������� �������)
 // info - �������� ������
 // infonext - ��������� �� �������� ������ � ������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapNextObjectInGroup(HOBJ infonext, HOBJ info);

 // ����������� ��������� ������ ��������� �������� (���������� �������)
 // info - ������������� ������� ����� � ������
 // limit - ������ ��� ����������� (� ������)
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapUnionGroupObject(HOBJ info, double limit);


 /*********************************************************
 *                                                        *
 *  ���������� �������. ���������� � ������� ����������.  *
 *                                                        *
 *      ���������� ������ ����� ������� �� ��� ������� -  *
 *           "ALIAS#��������_���_�����"                   *
 *                                                        *
 *********************************************************/

  // ���������� ��������� ���������� � ���-��������
  // ���������� �� �������� ���� �� �������
  // name - ��� ����� (�� 256 ��������), ���� ishost �� ����� 0
  //        ��� ������ ������ "XXX.XXX.XXX.XXX"
  // ���� �������� ����� ���� - ������ ������ �� ��������� ����� "localhost".
  // port - ����� ����� �� 1024 �� 65536, �� ��������� - 2047 (���� port = 0)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetConnectParameters(const char *name,
                                                 long int port,
                                                 long int ishost);

  // ��������� ����� ����� ��� ����� � ���-��������
  // ����� ����� �� 1024 �� 65536, �� ��������� - 2047

_MAPIMP long int _MAPAPI mapGetConnectPort();

  // ��������� ���\����� �����
  // ���� ���� ���������� ����� ����� - ������������ �������� 1,
  // ���� ��� ����� - ������������ �������� 2.
  // ���� ����������� ��� �������� - ������������ ����� �����
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������ (��� ����� ����� �� ����� 256)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetConnectHost(char *name, long int size);

  // ���������������� ������������
  // ���� ���������� � �������� �� ���� ����������� -
  // �������� ����������� � �������������� ����� �����������
  // ��������� USERPARM ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRegisterUser(TMCUSERPARM *parm);

  // ���������������� ������������ ������������ ������� �� ��� �������
  // ���� ���������� � �������� �� ���� ����������� -
  // �������� ����������� � �������������� ����� �����������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapRegisterSystemUser();

  // ������� � ������ ��������� ����������� ������������
  // ����� �������� ���������� ��������� �� ������� ����������
  // ����������� � ��� ������������ �������� ����� ����� ��������
  // ��������� mapRegisterUser() ��� mapRegisterSystemUser()

_MAPIMP void _MAPAPI mapUnRegisterUser();

  // ��������� ��� ������������, ��������������� � ���-�������
  // ��� ������ ���������� ������ ������

_MAPIMP const char* _MAPAPI mapGetCurrentUserName();

  // ��������� ������ ��������� ������������ ���� �� ���-�������
  // �� ������ ������� ���������� ���������������� ������������
  // �������� mapRegisterUser.
  // buffer - ����� ������ ��� ���������� ������ ����,
  //          ��������� TMCMAPLIST ������� � maptype.h
  // length - ����� ���������� ������� ������
  // ��� �������� ��������� ����� ��������� MAPAPI � ��
  // ����� ������ ���� �������� ������� "ALIAS#"
  // ���������� ����� ������ ��������� ������ ��� 0

_MAPIMP long int _MAPAPI mapGetMapListforUser(TMCMAPLIST *buffer, int length);

  // ��������� ������ ��������� ������������ ������ �� ���-�������
  // buffer - ����� ������ ��� ���������� ������ ����,
  //          ��������� TMCMAPLIST ������� � maptype.h
  // length - ����� ���������� ������� ������
  // ��� �������� ��������� ������� ��������� MAPAPI � ��
  // ����� ������ ���� �������� ������� "ALIAS#"
  // ���������� ����� ������ ��������� ������ ��� 0

_MAPIMP long int _MAPAPI mapGetMtwListforUser(TMCMAPLIST *buffer, int length);

  // ��������� ������ ��������� ������������ ������� �� ���-�������
  // buffer - ����� ������ ��� ���������� ������ ����,
  //          ��������� TMCMAPLIST ������� � maptype.h
  // length - ����� ���������� ������� ������
  // ��� �������� ���������� ������ ��������� MAPAPI � ��
  // ����� ������ ���� �������� ������� "ALIAS#"
  // ���������� ����� ������ ��������� ������ ��� 0

_MAPIMP long int _MAPAPI mapGetRswListforUser(TMCMAPLIST *buffer, int length);

  // ��������� ������ ��������� ������������ ������� �� ���-�������
  // buffer - ����� ������ ��� ���������� ������ �������,
  //          ��������� TMCMAPLIST ������� � maptype.h
  // length - ����� ���������� ������� ������
  // ���������� ����� ������ ��������� ������ ��� 0

_MAPIMP long int _MAPAPI mapGetAlsListforUser(TMCMAPLIST *buffer, int length);

  // ��������� ��������� ����������� � �������
  // hmap -  ������������� �������� ������ ��� 0
  // ��� ��������� ��������\���������� ������ � ��� ������� �������������
  // ����� ������ ������ �������� ������ ��������� ��������� �����������
  // � ��� ������ �������� ��������� ���������
  // ���� ����� ������ �������� ������ � ������ "ALIAS#..."
  // ����������� �� �����������, �� ����� ���������, ��� ������ ������� �
  // ������� ���������� ��������� ����������
  // ���� ����������� � ������� ����������� - ���������� ��������� ��������

_MAPIMP long int _MAPAPI mapIsServerActive(HMAP hMap);

 /*********************************************************
 *                                                        *
 *    ������� �������/��������� ������� (����������)      *
 *                                                        *
 *********************************************************/

#ifdef WIN32API
  // ��������� ������������� ������� gdi+ ��� ��������� ��������        // 14/04/16
  // ������� ����������� ������ � ������������� ����������� �� ������
  // ��������� ��� ���������� ������������� �������� �� ����������� gdi+
  // ��� �������� ������������� ���������� 1,
  // ���� �� ������ ����� image/png ���������� -1
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapInitGDIPlus(void);

  // ���������/���������� ����� �����
  // ������� ���������� ��� �� Windows
  // technology - ��� ���������� (DT_RASDISPLAY, DT_PLOTTER)
  //              ������������ �������� GetDeviceCaps(...)
  // index      - ����� ������ (0-4)
  // fontname   - ��������� �� ��� ������, �������� 32 �������,
  //              ������� ����� ������ 0x00

_MAPIMP char* _MAPAPI mapGetMapFont(long int technology, long int index = 0);
_MAPIMP char* _MAPAPI mapSetMapFont(long int technology, long int index, char* fontname);
_MAPIMP char* _MAPAPI GetMapFont(int technology, int index = 0);
_MAPIMP char* _MAPAPI SetMapFont(int technology, int index, char* fontname);

_MAPIMP long int _MAPAPI mapGetMapFontName(long int technology, long int index,
                                           char *name, long int size);

_MAPIMP long int _MAPAPI mapSetMapFontName(long int technology, long int index,
                                           char *name, long int size);

  // ���������/���������� ��������� ������ �����
  // technology - ��� ���������� (DT_RASDISPLAY, DT_PLOTTER)
  //              ������������ �������� GetDeviceCaps(...)
  // index      - ����� ������ (0-4)
  // code       - (RUSSIAN_CHARSET, DEFAULT_CHARSET, ANSI_CHARSET)

_MAPIMP long int _MAPAPI mapGetMapFontCharSet(long int technology, long int index);
_MAPIMP long int _MAPAPI mapSetMapFontCharSet(long int technology, long int index,
                                              long int code);

  // ��������� ����� ������ (0-4)

_MAPIMP int _MAPAPI mapGetMapFontIndex(long int technology, char* fontname);
_MAPIMP int _MAPAPI GetMapFontIndex(long int technology, char* fontname);

  // ���������/���������� ����� ����� ��������

_MAPIMP char* _MAPAPI mapGetDialogStringFont();
_MAPIMP char* _MAPAPI mapSetDialogStringFont(char* fontname);
_MAPIMP char* _MAPAPI GetDialogStringFont();
_MAPIMP char* _MAPAPI SetDialogStringFont(char* fontname);

  // ���������/���������� ����� ������ ��������

_MAPIMP char* _MAPAPI mapGetDialogTableFont();
_MAPIMP char* _MAPAPI mapSetDialogTableFont(char* fontname);
_MAPIMP char* _MAPAPI GetDialogTableFont();
_MAPIMP char* _MAPAPI SetDialogTableFont(char* fontname);

  // ���������/���������� ������ ������ ����� � ������ ��������

_MAPIMP long int _MAPAPI mapGetDialogStringFontSize();

_MAPIMP long int _MAPAPI mapGetDialogTableFontSize();

_MAPIMP long int _MAPAPI mapSetDialogStringFontSize(long int size);

_MAPIMP long int _MAPAPI mapSetDialogTableFontSize(long int size);

  // ���������/���������� ������� �������� ������ ����� � ������ ��������

_MAPIMP long int _MAPAPI mapGetDialogStringFontCharSet();

_MAPIMP long int _MAPAPI mapGetDialogTableFontCharSet();

_MAPIMP long int _MAPAPI mapSetDialogStringFontCharSet(long int charset);

_MAPIMP long int _MAPAPI mapSetDialogTableFontCharSet(long int charset);

  // ��������� �������� ����������� VCL-������� (��� Windows)
  // ����������: DEFAULT_CHARSET, RUSSIAN_CHARSET, ...

_MAPIMP long int _MAPAPI mapGetWinCharSet();  // 23/10/15

#endif  // WIN32API

}       // extern "C"


#if defined(__BORLANDC__) || defined(LINUXAPI)                    // 21/04/14
inline int _ScaleToString(double scale, TCHAR* string, int size)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapScaleToString(scale, string, size);
#else
  return mapScaleToStringUn(scale, string, size);
#endif
}

inline int _LongToString(int value, TCHAR* string, int size)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapLongToString(value, string, size);
#else
  return mapLongToStringUn(value, string, size);
#endif
}

inline int _PathToShort(const TCHAR * source, TCHAR * target, int size)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapPathToShort(source, target, size);
#else
  return mapPathToShortUn(source, target, size);  // ������ � ��������
#endif
}

inline long int _BuildLongName(const TCHAR * templ, const TCHAR * name, TCHAR * path)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return (mapBuildLongName(templ, name, path) != 0);
#else
  return mapBuildLongNameUn(templ, name, path);
#endif
}

inline const TCHAR * _BuildShortName(const TCHAR * templ, const TCHAR * name)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapBuildShortName(templ, name);
#else
  return mapBuildShortNameUn(templ, name);
#endif
}

inline void _ErrorMessage(int code, const TCHAR *filename)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  mapErrorMessage(code, filename);
#else
  mapErrorMessageUn(code, filename);
#endif
}

inline const TCHAR * _GetIniPath()
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapGetIniPath();
#else
  return mapGetIniPathUn();
#endif
}

inline const TCHAR * _GetPathShell()
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapGetPathShell();
#else
  return mapGetPathShellUnicode();
#endif
}

inline void _MessageToLog(HMAP hMap, HSITE hSite, 
                          const TCHAR *message, long int type)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  mapMessageToLog(hMap, hSite, message, type);
#else
  mapMessageToLogUn(hMap, hSite, message, type);
#endif
}

inline int _GetMapName(HMAP hmap, TCHAR *name, int size)
{
#if !defined(UNICODE11) && !defined(UNICODE)
   return mapGetMapNameEx(hmap, name, size);
#else
   return mapGetMapNameUn(hmap, name, size);
#endif
}

inline const TCHAR * _GetSiteName(HMAP hmap, HSITE hsite)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapGetSiteName(hmap, hsite);
#else
  return mapGetSiteNameEx(hmap, hsite);
#endif  
}

inline int _GetSiteFileNameEx(HMAP hmap, HSITE hsite, TCHAR *name, int size)
{
#if !defined(UNICODE11) && !defined(UNICODE)
   return mapGetSiteFileNameEx(hmap, hsite, name, size);
#else
   return mapGetSiteFileNameUn(hmap, hsite, name, size);
#endif
}

inline const TCHAR * _GetMapIniName(HMAP hMap)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapGetMapIniName(hMap);
#else
  return mapGetMapIniNameEx(hMap);
#endif
}

inline const TCHAR * _GetMainName(HMAP hMap)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapGetMainName(hMap);
#else
  return mapGetMainNameEx(hMap);
#endif
}

inline long int _IsAliasName(const TCHAR * name)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapIsAliasName(name);
#else
  return mapIsAliasNameUn(name);
#endif
}
#endif

inline long int _IsNormalPath(const TCHAR * name)
{
#if !defined(UNICODE11) && !defined(UNICODE)
  return mapIsNormalPath(name);
#else
  return mapIsNormalPathUn(name);
#endif
}

#endif  // MAPAPI_H

