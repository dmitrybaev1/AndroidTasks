/****** RSCAPI.H *************** Belenkov   O.V. ****** 27/09/15 ***
******* RSCAPI.H *************** Panteleeva N.A. ****** 06/05/16 ***
******* RSCAPI.H *************** Derevyagina Zh.A.***** 28/12/12 ***
******* RSCAPI.H *************** Dishlenko S.G.  ****** 13/03/13 ***
******* RSCAPI.H *************** Shabakov D.A.   ****** 11/02/14 ***
******* RSCAPI.H *************** Tarakanova I.R. ****** 13/03/14 ***
******* RSCAPI.H *************** Kruzhkov A.E.   ****** 20/03/14 ***
******* RSCAPI.H *************** ������ �.�.     ****** 04/03/16 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2016              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*       �������� ������� ������� � ��'���� "������������� ����"    *
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
*    HRSC (WINAPI * lpfn)(HMAP,HSITE);                             *
*    (FARPROC)lpfn = GetProcAddress(libInst, "mapGetRscIdent");    *
*    HRSC hRsc = (*lpfn)(hMap,hSite);                              *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef RSCAPI_H
#define RSCAPI_H

#ifndef MAPTYPE_H
 #include "maptype.h"
#endif

#ifndef MAPGDI_H
 #include "mapgdi.h"
#endif 

  // ���������� ����� ����� ���������� � 0. ������� ���� - ���������.
  // ��������������� ���� ������ ��� ��������. �������� ���� ���������.
  // �������� ��� ���� (����) - ���������.

  // ���������� ��� (���������� ����� ) �������� ���������� � 1.
  // ���������� ��� ������� �� ����� ���������� ��������.
  // ���� ������� - ��������.

  // ��������������� �������� ������ ���. ��������� � ����� 0 - ���������.
  // ��� ��������� �� �������� �� ���������� ������� .
  // ���������� ����� ��������� ���������� � 1.
  // �������� ��� ��������� (����) - ���������.

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ �������� ������� ������� � �������������� +++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
extern "C"
{
  /*********************************************************
  *                                                        *
  * ������� ������� ���������� �� �������������� ��'�����  *
  *                                                        *
  *********************************************************/

  // ��������� ������������� �������������� �����
  // hMap  - ������������� �������� �����
  // hSite - ������������� �������� ���������������� �����
  // ��� ������ ���������� ����

_MAPIMP  HRSC _MAPAPI mapGetRscIdent(HMAP hMap,HSITE hSite);

  // ��������� ��� ����� ��������������
  // hRsc   - ������������� �������������� �����,
  // target - ������ ��� ���������� ������� ����� �����,
  // size   - ������ ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscFileName(HRSC hRsc,
                                     char * target, long int size);

  // ��������� ��� ����� �������������� � ��������� UNICODE              // 23/04/12
  // hRsc   - ������������� �������������� �����,
  // target - ������ ��� ���������� ������� ����� �����,
  // size   - ������ ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscFileNameUn(HRSC hRsc,
                                     WCHAR * target, long int size);

  // ��������� ��� ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  const char * _MAPAPI mapGetRscName(HRSC hRsc);

  // ��������� ��� ����� �������������� � ��������� UNICODE              
  // hRsc    - ������������� �������������� �����,
  // rscname - ������ ��� ���������� ������� ����� �����,
  // size    - ������ ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscNameUn(HRSC hRsc, WCHAR * rscname, long int size); // 12/09/12


  // ��������� �������� �������� ��������������               // 07/06/15
  // hRsc    - ������������� �������������� �����,
  // name    - ������ ��� ���������� ��������� �������� ��������������,
  // size    - ������ ������
  // ��� ������ ���������� ����

  _MAPIMP long int _MAPAPI mapGetRscUserName(HRSC hRsc, char * name, long int size);


  // ���������� �������� �������� ��������������               // 07/06/15
  // hRsc    - ������������� �������������� �����,
  // name    - �������� �������� ��������������,
  // ��� ������ ���������� ����

  _MAPIMP long int _MAPAPI mapSetRscUserName(HRSC hRsc, const char * name);
  
  // ��������� ��� ������ ��������� �������� � ��������������� �����
  // hRsc - ������������� �������������� �����
  // ���� ������ ����������� � maperr.rh

_MAPIMP  long int _MAPAPI mapGetRscError(HRSC hRsc);  

  // ��������� ���� ��������� �������������� �����
  // hRsc - ������������� �������������� �����
  // ��� ��������� ����� ���������� ���� �������� �����������

_MAPIMP  long int _MAPAPI mapGetRscMode(HRSC hRsc);

  // ��������� ����� �������������� �����
  // hRsc - ������������� �������������� �����
  // ��� ��������� ����� ����� ���������� ���������� ���� ��������

_MAPIMP  long int _MAPAPI mapGetRscStyle(HRSC hRsc);

  // ��������� ����������� ����c� �������������� �����
  // hRsc - ������������� �������������� �����
  // 0 - ������������� ������ �� ������, 1 - �� ������

_MAPIMP  long int _MAPAPI mapGetRscIsWrite(HRSC hRsc);        // 15/12/15


  // ��������� ����� �������� ��������� � ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscObjectCount(HRSC hRsc);

  // ��������� ����� �������� ��������� � ��������������
  // � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscObjectCountInLayer(HRSC hRsc,
                                               long int layer);

  // ��������� �������� ������� �� ����������� ������
  // � �������� ����
  // hRsc   - ������������� �������������� �����
  // layer  - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ���� ��� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscObjectNameInLayer(HRSC hRsc,
                                               long int layer,
                                               long int number);

 // ��������� �������� ������� �� ����������� ������
 // � �������� ����
 // hRsc   - ������������� �������������� �����
 // layer  - ����� ����
 // number - ����� ������� � ����
 // name   - ����� ������ ��� ���������� ����������
 // size   - ������ ������ (�� ������ 32 ����)
 // ��� ������ ���������� ����                                  // 08/05/07

_MAPIMP long int _MAPAPI mapGetRscObjectNameInLayerEx(HMAP hRsc, long int layer,
                                                      long int number,
                                                      char * name, long int size);
_MAPIMP long int _MAPAPI mapGetRscObjectNameInLayerUn(HMAP hRsc, long int layer,     // 19/01/14
                                                      long int number,
                                                      WCHAR * name, long int size);

  // ��������� ����������������� ��� �������
  // �� ����������� ������ � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscObjectExcodeInLayer(HRSC hRsc,
                                                      long int layer,
                                                      long int number);

  // ��������� ��� ����������� �������
  // �� ����������� ������ � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ���� (���� ��������)

_MAPIMP  long int  _MAPAPI mapGetRscObjectLocalInLayer(HRSC hRsc,
                                            long int layer,
                                            long int number);

  // ��������� ���������� ��� (���������� �����) �������
  // �� ����������� ������ � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscObjectCodeInLayer(HRSC hRsc,
                                               long int layer,
                                               long int number);

  // ��������� ������ ������� ������� ��������� ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscScaleCount(HRSC hRsc);

  // ��������� �������� (����������� ��������) �� ������� �������
  // ��������� ��������������  �� ����������� ������ (� 1)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscScaleItem(HRSC hRsc,
                                       long int number);

  // ��������� �������� �������� ����������� ����� � ����� - ��������  28/06/12
  // scale - ������� ����������� � % �� 10 �� 100 ����������, ����� 100 ����������

_MAPIMP  long int _MAPAPI mapSetRscExampleScale(HRSC hRsc, long int scale);


  // ������ �������� �������� ����������� ����� � ����� - ��������,
  // �� 10 �� 100 ����������, ����� 100 ����������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscExampleScale(HRSC hRsc);

  // ����� �������� ��������������                                     // 20/04/06
  // oldnumber - ����� ������� ��� ���������� ������, 0 - ����� � �������
  // seektype - ������� ������  SEEK_RSCOBJECT (maptype.h)
  // example - ������ ��� ������
  // ���������� ���������� ����� ������� ��� 0, ���� ������ ���

_MAPIMP  long int  _MAPAPI mapGetRscSeekObjectCode(HRSC hRsc,long int oldnumber,
                                       long int seektype, char * example);

  // ��������� ������ (� �����) ��� P3D ����� �� ���� ���������� � ���������
  // UNICODE �� ����������� ������
  // hRsc    - ������������� �������������� �����,
  // name - ������ ��� ���������� ������� ����� �����,
  // size    - ������ ������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetP3DNameUn(HRSC hRsc, long int number,
                                         WCHAR * name, long int size); // 27/06/13

  /*********************************************************
  *                                                        *
  *        ������� �������� �������������� ��'�����        *
  *                                                        *
  *********************************************************/

  // ������� ������������� ��������� �����
  // name - ��� ������������ ����� ��������������
  // RSCCREATE -   ��������� ������� ������  (��. maptype.h)
  // PALETTE256 -  ��� ������������� �������� ������� (�� ����� 32 ������)
  //               (��. maptype.h)
  // ��� ������ ���������� ����

_MAPIMP  HRSC _MAPAPI mapCreateRsc(const char * name, const RSCCREATE * rsccreate,
                                   const PALETTE256 * palette);

_MAPIMP  HRSC _MAPAPI mapCreateRscUn(const WCHAR * name, const RSCCREATEUN * rsccreate,
                                     const PALETTE256 * palette);

  // ������� ������������� ��������� ����� c �������������� ����� �������
  // �� ����� (��������� ����� �������)
  // name - ��� ������������ ����� ��������������
  // RSCCREATE -   ��������� ������� ������  (��. maptype.h)
  // PALETTE256 -  ��� ������������� �������� ������� (�� ����� 32 ������)
  //               (��. maptype.h)
  // ��� ������ ���������� ����                         // 21/05/02

_MAPIMP  HRSC _MAPAPI mapCreateKeyObjectRsc(char * name, RSCCREATE * rsccreate,
                            PALETTE256 * palette );


  // ��������� ������ �� �������������� ��������� �����
  // hRsc - ������������� �������������� �����
  // RSCCREATE -  �������� ��������������  (��. maptype.h)
  // PALETTE256 - �������� ������� �����   (��. maptype.h)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscDescribe(HRSC hRsc, RSCCREATE * rsccreate,
                                     PALETTE256 * palette);

  // ������� �������������
  // name - ���  ����� ��������������
  // ��� ������ ���������� ����, ����� ������������� �������������� �����

_MAPIMP  HRSC _MAPAPI mapOpenRsc(const char * name);            // 13/08/12

  // ������� �������������
  // name - ���  ����� �������������� � ��������� UNICODE
  // size    - ������ ������
  // ��� ������ ���������� ����

_MAPIMP  HRSC _MAPAPI mapOpenRscUn(const WCHAR * name);         // 12/09/12

  // ������� �������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCloseRsc(HRSC hRsc);

  // ��������� ������������� �� ���� ��� �� ������ ����� ����������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCommitRsc(HRSC hRsc);

  // ��������� ������������� �� ���������� ���� (������� ���)      // 17/01/12
  // hRsc - ������������� �������������� �����
  // path - ���� � ������������ ����� (� UTF-16)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSaveRscAs(HRSC hRsc, const WCHAR * path);

  // ������� ������������� �� ���������� ����                      // 11/01/13
  // hRsc - ������������� ������������ �������������� �����
  // path - ���� � ������������ ����� (� UTF-16)
  // ����� ����� ��������� ��������� ������������� � ���, ��� ��� ������
  // ����������, ���������� ������� mapCommitRsc
  // ����� �������� ���������� ���������� ����� ������� mapRevertRsc
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapLoadRscFrom(HRSC hRsc, const WCHAR * unpath);

  // ������������ ������������� � �����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapRevertRsc(HRSC hRsc);

  // ��������� �������� �������������� � ���� ���������� XSD �����      // 08/04/15
  // hRsc   - ������������� �������������� �����
  // name   - ��� ����������� XSD �����
  // layers - ��� XML �����, ����������� �������� �� �������������� �
  //          ��������� ����� � ���������� �����
  // comment - ����� ����������� ��� ���������� � ���������� �����
  // isselectonly - ������� ������ � ����� ������ ��� �����, ��� ������ 
  //                � ����� ����� (layers)
  // prefix - ������� �������������� ����� (targetnamespace),
  //          ���� �������� ����� ����, �� � �������� �������������� �������������
  //          ��� �������������� RSC ��� ����������
  // (��������, ��� operator.rsc � ����� ����� ������������� ������:
  // "<xsd:schema "xmlns:operator=\"http://www.gisinfo.net/bsd/operator" 
  //  targetNamespace="http://www.gisinfo.net/bsd/operator">"
  // ����� ���������� ��������� � ������ ����� ����� ���������� � �������� "operator:"
  // ��������� � ���������� ���������� ����� ����� ��������� 
  // � ��������� "������������ GML ��� ���" 
  // ��� ������ ���������� ����

 _MAPIMP long int _MAPAPI mapRscSaveToXSDPro(HRSC hRsc, const WCHAR * name, const WCHAR * layers, 
                                             const WCHAR * comment, long int isselectonly,
                                             const WCHAR * prefix);
 _MAPIMP long int _MAPAPI mapRscSaveToXSDEx(HRSC hRsc, const WCHAR * name, const WCHAR * layers, 
                                            const WCHAR * comment, long int isselectonly);
 _MAPIMP long int _MAPAPI mapRscSaveToXSD(HRSC hRsc, const WCHAR * name, const WCHAR * layers, 
                                          const WCHAR * comment);
                                            

 /****************************************************************
 *                                                               *
 *     ������ � �������� ����������� ����������� �����           *
 *    ����������� ���������� � 0                                 *
 *                                                               *
 ****************************************************************/

  // ������ ���������� �����������
  // hRsc - ������������� �������������� �����

_MAPIMP  long int  _MAPAPI mapGetRscLocalCount(HRSC hRsc);

  // ������ �������� ����������� �� �� ������ (0 - ��������, ...)
  // hRsc - ������������� �������������� �����
  // local - ��� �����������
  // language - ���� (�� ��������� - �������)
  // �������� �������� �� ���� ������ ...

_MAPIMP  const char * _MAPAPI mapGetRscLocalName(HRSC hRsc,long int local,
                                                 long int language = ML_RUSSIAN);

  // ������ �������� ����������� �� �� ������ (0 - ��������, ...)
  // hRsc - ������������� �������������� �����
  // local - ��� �����������
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������
  // language - ���� (�� ��������� - �������)
  // �������� �������� �� ���� ������ ...                  // 13/02/07
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscLocalNameEx(HRSC hRsc, long int local,
                                               char * name, long int size,
                                               long int language = ML_RUSSIAN);

_MAPIMP  long int _MAPAPI mapGetRscLocalNameUn(HRSC hRsc, long int local,
                                               WCHAR * name, long int size,
                                               long int language);

  // ������ ����� ����� �����������
  // hRsc - ������������� �������������� �����
  // (������ ��� �������� �� 32 ��������)

_MAPIMP  long int _MAPAPI mapGetRscLocalNameSize(HRSC hRsc);


  /*********************************************************
  *                                                        *
  *  ������� ������ �� ������ �� �������������� ��'�����   *
  *                                                        *
  *********************************************************/

  // ��� ������� �������� �����  � ������ ���������������  �����
  // ��������� ������� ������ ����� �� �����, ����� ����������� ���-
  // ����� �� ���� � ���� � ����� �������� ����� ���������� ��������
  // ����� � ������������ � ��������������� - ������� mapAdjustData()
  // � ��� ������������� ������������ �����

  // ������ ���������� �����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentCount(HRSC hRsc);


  // ������ ����� ���� �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ""

_MAPIMP  const char * _MAPAPI mapGetRscSegmentName(HRSC hRsc,long int incode);

  // ������ ����� ���� � ��������� UNICODE �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������ (����� ���� �� 2048 ����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSegmentNameUn(HRSC hRsc,long int incode,
                                                 WCHAR * name, long int size);
_MAPIMP  long int _MAPAPI mapGetRscSegmentNameUnicode(HRSC hRsc,long int incode,
                                                      WCHAR * name, long int size);

  // ������ ����������� ������ ���� �� �����
  // ������ ����� ���������� � 0 !
  // hRsc - ������������� �������������� �����
  // name - ��� ����
  // ��� ���������� ���� ���������� - 0, ��� ������ IDS_NOTFIND

_MAPIMP  long int _MAPAPI mapGetSegmentByName(HRSC hRsc, const char * name);

_MAPIMP  long int _MAPAPI mapGetSegmentByNameUn(HRSC hRsc, const WCHAR * name);  // 13/03/14


  // ������ ������������ ����� ����� ����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentNameSize(HRSC hRsc);


  // ������ ������� ������ ���� �� ����� �� ����������� ������ (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentOrder(HRSC hRsc,long int incode);


  // ������ ���������� �������� ���� ��  ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentObjectCount(HRSC hRsc,long int incode);


  // ��������� ����� ���� �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // name   - ��� ����                                          // 15/07/09
  // ��� ������ ���������� ����, ����� ���������� ����� ����.
  // ���� �������� 0, ��������� ��� ��������� ������ �������� mapGetRscError.
  // ��� ��������� ��� ���������� ����� ����
  // ������� mapGetRscError ���������� IDS_RSCEXITSEGMENTERROR (MAPERR.RH)

_MAPIMP  long int _MAPAPI mapSetRscSegmentName(HRSC hRsc,
                                        long int incode,char * name);


  // ��������� ������� ������ ���� �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // order  - ������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRscSegmentOrder(HRSC hRsc,
                                         long int incode,
                                         long int order);


  // ������� ���� �� ����������� ������ ���� (� 0)
  // ���� ���������  ������ � ���������
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapDeleteRscSegment(HRSC hRsc,long int incode);


  // ��������� ������� �� ������ ���� � ������
  // hRsc - ������������� �������������� �����
  // oldcode, newcode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapMoveRscSegmentObjects(HRSC hRsc,
                                            long int oldcode,
                                            long int newcode);


  // ������� ���� � �������������� �����
  // RSCSEGMENT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����                   // 15/07/09
  // ��� ������ ���������� ����, ����� ���������� ����� ����(� 0)
  // ���� �������� 0, ��������� ��� ��������� ������ �������� mapGetRscError.
  // ��� ��������� ��� ���������� ����� ����
  // ������� mapGetRscError ���������� IDS_RSCEXITSEGMENTERROR (MAPERR.RH)

_MAPIMP  long int _MAPAPI mapAppendRscSegment(HRSC hRsc, RSCSEGMENT * segment);


  // ��������� ��������� �������� �����
  // RSCSEGMENT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ����
  // ��� ������ ���������� ���� � ��� ������
  // ����� ���������� ����� ����  (� 0)

_MAPIMP  long int _MAPAPI mapGetRscSegment(HRSC hRsc, RSCSEGMENT * segment,
                                    long int incode);


  // ��������� �������� ��� (����) ����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ���� (� 0)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSegmentShortName(HRSC hRsc,long int incode);
_MAPIMP  long int _MAPAPI mapGetRscSegmentShortNameUn(HRSC hRsc,long int incode,WCHAR * shortname, long int size); // 12/09/12
_MAPIMP  const char * _MAPAPI mapGetRscSegmentKey(HRSC hRsc,long int incode);  //18/09/01


  // ���������� �������� ���(����) ����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSegmentShortName(HRSC hRsc,long int incode,
                                             char * shortname );
_MAPIMP  long int _MAPAPI mapSetRscSegmentKey(HRSC hRsc,long int incode,    //18/09/01
                                             char * key);


  // ��������� ���������� ����� ���� (� 0) �� ��������� �����(�����) ����   //11/03/00
  // hRsc - ������������� �������������� �����
  // shortname - �������� ���(����) ����
  // ��� ������ ���������� ���� � ��� ������
  // ����� ���������� ����� ����  (� 0)

_MAPIMP  long int _MAPAPI mapGetRscSegmentByShortName(HRSC hRsc,char * shortname);
_MAPIMP  long int _MAPAPI mapGetRscSegmentByShortNameUn(HRSC hRsc, WCHAR * shortname);  // 11/02/14
_MAPIMP  long int _MAPAPI mapGetRscSegmentByKey(HRSC hRsc,char * key);     //18/09/01


  // ��������� ���������� �������� ����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSegmentSemanticCount(HRSC hRsc,long int incode);


  // ��������� ��� ��������� ���� �� ����������� ������
  // number ��������� � ������ (� 1)
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSegmentSemanticCode(HRSC hRsc,long int layer,
                                                 long int number);


  // �������� ��������� ����
  // semanticcode ��� ����������� ���������
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapAppendRscSegmentSemantic(HRSC hRsc,long int layer,
                                                long int semanticcode);


  // ������� ��������� �� ����
  // semanticcode ��� ��������� ���������
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapDeleteRscSegmentSemantic(HRSC hRsc,long int layer,
                                                    long int semanticcode);


  // ���������� ��������� ��� ����
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // type = 0 - ������� ��� ���������,1 - ������ ������������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapBuildRscSegmentSemantic(HRSC hRsc,long int layer,
                                              long int type);

  // ���������� ��� ���� � ��������� UNICODE �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // name - ��� ���� � ��������� UNICODE
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSegmentNameUn(HRSC hRsc,long int incode,
                                                 const WCHAR * name);

_MAPIMP  long int _MAPAPI mapSetRscSegmentNameUnicode(HRSC hRsc,long int incode,
                                                      const WCHAR * name);

  // ��������� ���������� ������� �����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscClassCount(HRSC hRsc);


  // ��������� ������������� ������ ���� �� ����������� ������ ����� �������
  // ����� (� 1)
  // hRsc - ������������� �������������� �����
  // number - ���������� ����� ������
  // ��� ������ ���������� 0 ����� ������������� ������ ����

_MAPIMP long int _MAPAPI mapGetRscClassIdent(HRSC hRsc,long int number);

  // ��������� ������� ������ ���� (������ ����� 1)
  // hRsc - ������������� �������������� �����
  // ident - ������������� ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRscClassLevel(HRSC hRsc,long int ident);

  // ��������� ������������� �������� ������ ����
  // hRsc - ������������� �������������� �����
  // ident - ������������� ������
  // ���������� ������������� ������ ��� ���������� ����� ���� (���� ����� 1 ������)
  // ��� ������ ���������� 0 (��� ������ 1 ������ 0 ��������)

_MAPIMP long int _MAPAPI mapGetRscClassParent(HRSC hRsc,long int ident);

  // ��������� ��� ������ ���� � ��������� UNICODE �� �������������� ������
  // hRsc - ������������� �������������� �����
  // ident - ������������� ������
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������ (����� ���� �� 2048 ����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscClassNameUnicode(HRSC hRsc,long int incode,
                                                 WCHAR * name, long int size);

  // ���������� ��� ������ ���� � ��������� UNICODE �� �������������� ������
  // hRsc - ������������� �������������� �����
  // ident - ������������� ������
  // buffer - ������ ��� ������ (� UNICODE)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscClassNameUnicode(HRSC hRsc,long int ident,
                                                       const WCHAR * buffer);

  // ������� ����� ����� ����
  // hRsc - ������������� �������������� �����
  // parent - ������������� ������ - �������� ��� ���������� ����� ��������� ����,
  // key  - ����, �������� ��� ������ (� � UNUCODE) (����������� ��� char[32],
  //        c ����������� ����� - ����������
  // name - ��� ������ (� UNUCODE)
  // ���������� ������������� ������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapAppendRscClass(HRSC hRsc,long int parent,
                                        const WCHAR * key, const WCHAR * name);

  // ������� ����� ����
  // ����� ��������� �� ����� �������� - ���������, ������� ����������� �
  // ����� - �������� ��� � ���� - ��������
  // ident - ������������� ����
  // ��� ������ ���������� 0, ����� 1

_MAPIMP  long int _MAPAPI mapDeleteRscClass(HRSC hRsc,long int ident);

  // ��������� ���� ��� ������ ���� �� �������������� ������
  // hRsc - ������������� �������������� �����
  // ident - ������������� ������
  // ���������� ����� ���� (����� ���� 0)

_MAPIMP long int _MAPAPI mapGetRscClassGenericSegment(HRSC hRsc,long int ident);

  // ��������� ���� ������ ���� � ��������� UNICODE �� �������������� ������
  // hRsc - ������������� �������������� �����
  // ident - ������������� ������
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������ (�� ����� 64 �����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscClassKeyUnicode(HRSC hRsc,long int ident,
                                                   WCHAR * name, long int size);

  // ��������� ������������� ������ �� ����� ������(� UNICODE)   // 10/10/14
  // buffer - ���������� ���� ����
  // ���������� ������������� ������ ��� 0
_MAPIMP  long int _MAPAPI mapGetRscClassIdentbyKeyUn(HRSC hRsc,
                                                     const WCHAR * buffer);

  // �������� ���� ������(� UNICODE) �� �������������� ������      06/10/14
  // ident - ������������� ������(����� 255)
  // name - ���������� ���� ���� (� UNICODE) �� ����� 31 �������
  // ( ������������ � char[32])
  // ���������� ����� ����� � ������ ��� 0
_MAPIMP  long int _MAPAPI mapSetRscClassKeyUnicode(HRSC hRsc,long int ident,
                                                   const WCHAR * name);

 // ������ ���������� �������� ������� ����
 // hRsc - ������������� �������������� �����
 // number - ����� ���� (c 0)
 // ���������� ���������� �������� ������� ����

 _MAPIMP  long int _MAPAPI mapGetRscSegmentClassCount(HRSC hRsc,long int number);

 // ������ ���������� �������� - ��������������� ������ ��� ����
 // hRsc - ������������� �������������� �����
 // number - ����� ���� (c 0)
 // ���������� ���������� �������� - ��������������� ������

 _MAPIMP  long int _MAPAPI mapGetRscSegmentSeekIdentCount(HRSC hRsc, long int number);

 // ������ ���� �������� - ��������������� ������ ��� ����
 // hRsc - ������������� �������������� �����
 // number - ����� ���� (c 0)
 // semnumber - ���������� ����� ��������� ( �� 1 �� 4)
 // ���������� ��� ��������� - �������������� ������ ��� 0

 _MAPIMP  long int _MAPAPI mapGetRscSegmentSeekIdentCode(HRSC hRsc,long int number,
                                                         long int semnumber);

 // ������ ����� �������� �� ��������� - ��������������� ������ ��� ����
 // hRsc - ������������� �������������� �����
 // number - ����� ���� (c 0)
 // semcode - ��� ���������
 // ���������� 1 - �������� ��� 0 - �� ��������

 _MAPIMP  long int _MAPAPI mapGetRscSegmentSeekIdentFlag(HRSC hRsc,long int number,
                                                         long int semcode);

 // ���������� ��������� ��� ������������� ������ ��� ����
 // hRsc - ������������� �������������� �����
 // number - ����� ���� (c 0)
 // semnumber - ��� ���������
 // flag - 1 ��������� ��������� ��������������� ������ ��� ����
 //      - 0 ������� ��������� �� ������ �������� - ��������������� ������
 // ���� � ���� ��� 4 ��������� - �������������� ��������� �� ���������������
 // � ������������ 0
 // ���� ��������� �� ������ � ������ �������� ���� - ��������� ����� ���������
 // � ������ �������� ����
 // ���������� 1, ��� ������ ���������� 0

 _MAPIMP  long int _MAPAPI mapSetRscSegmentSeekIdentFlag(HRSC hRsc,long int number,
                                                long int semcode,long int flag);

  /***********************************************************
  *                                                          *
  *  ������� ������ � ��'������ �� �������������� ��������   *
  *                                                          *
  ***********************************************************/

  // ������� ������
  // RSCOBJECT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ���� , ����� ���������� ����� ������� (� 1)

_MAPIMP  long int  _MAPAPI mapAppendRscObject(HRSC hRsc, RSCOBJECT * object);


  // ����������� ������
  // hRsc - ������������� �������������� �����
  // oldcode - ���������� ����� ������� � �������� ��������
  // ��� ������ ���������� ���� , ����� ���������� ����� ������ ������� (� 1)
  // ���������� ��������� �������,��� �����������,��������� �������
  // ���  FIRSTSERVEXCODE
  // ��� ����,����� ������ ������ ����������,
  // ������������ ������ �������������� ������� ���

_MAPIMP  long int  _MAPAPI mapCopyRscObject(HRSC hRsc, long int oldcode);


  // �������� ������
  // RSCOBJECT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ���� , ����� ���������� ����� ������� (� 1)
  // ��� ������� ����� ������� ��� � ����������� � ���� - �� ��������
  // ���� ������� ��� ������� �� ������������� ����������� - ������������
  // ������������ ������� ���

_MAPIMP  long int  _MAPAPI mapUpdateRscObject(HRSC hRsc,long int code,
                                       RSCOBJECT * object);


  // ������� ������
  // hRsc - ������������� �������������� �����
  // �ode - ���������� ����� ������� ������� ������� (� 1)
  // ��� ������ ���������� ���� , ����� ���������� ����� ���������� �������
  // ���� ������ ������ � ����� - �������� �� ��������

_MAPIMP  long int  _MAPAPI mapDeleteRscObject(HRSC hRsc,long int code);


  // ��������� ��������� �������� �������
  // RSCOBJECT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // ��� ������ ���������� ���� , ����� ���������� ����� �������

_MAPIMP  long int  _MAPAPI mapGetRscObject(HRSC hRsc,long int incode,
                                    RSCOBJECT * object);


  // ��������� ���������� ����� ������� � ����� ����������
  // �������� (� ����� ����������������� ����� � ������������)
  // �� ����������� ���� �������
  // (��������������� ������� - mapGetRscObjectCodeByNumber)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // ��� ������ ��� ���������� ����� ���������� ���� ,
  // ����� ����� ������� � �����

_MAPIMP  long int _MAPAPI mapGetRscObjectNumber(HRSC hRsc,long int incode);


  // ��������� ������� � �������� � �������� ��������� ���� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // IMAGESIZE -  ��������� ������� ������  (��. maptype.h)
  // ������ string ������ length �������� ���
  // ����������� ��������������� ������� �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscImageSize(HRSC hRsc,
                            long int incode, IMAGESIZE * imagesize,
                            long int length = 0,char * string = 0);

  // ��������� ������� � �������� � �������� ����������� ���� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // IMAGESIZE -  ��������� ������� ������  (��. maptype.h)
  // ������ string ������ length �������� ���
  // ����������� ��������������� ������� �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscPrnImageSize(HRSC hRsc,
                            long int incode, IMAGESIZE * imagesize,
                            long int length = 0,char * string = 0);


 // ��������� ���������� ����� ����������� ������� (��������, ���������)
 // � ������ �������� ������� (IMAGEFRAME - ��. maptype.h)
 // ��� ������� � �������� �� "��������" ����������� (� ������� ��������)
 // ������������ ������ ����� ������� ������� � ���������������� �������
 // ��� ��������� ���������� ��������� � ����� �� ��������� �����
 // �� �������� �� 1 000 000, �������� �� ������� ������� �����
 // � �������� ���������� ������ ����� �������
 // number - ����� ������� ����������� (mapgdi.h)
 // param  - ��������� ����������� (mapgdi.h)
 // angle  - ���� �������� ������� � �������� �� ������� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscMarkFrame(HRSC hRsc, long int number,
                                     const char * param,
                                     double angle,
                                     IMAGEFRAME * imageframe);


  // ��������� ���������� ��� (���������� �����) �������
  // �� �������� ���� , �����������  � ����������� ������ ����� �����������
  // ��������(� 1)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscObjectCodeByNumber(HRSC hRsc,
                                                long int excode,
                                                long int local,
                                                long int number = 1);

  // ��������� ���������� �������� � �������� ������� ����� � ������������
  // hRsc - ������������� �������������� �����
  // excode - ������� ��� �������
  // local  - ��� �����������
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscObjectsCount(HRSC hRsc,
                                          long int excode,
                                          long int local);

  // ��������� ��� ������� �� �����������  ���� (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscObjectName(HRSC hRsc,long int incode);

  // ��������� ��� ������� �� �����������  ���� (����������� ������) ������� (� 1)
  // � ��������� UNICODE
  // hRsc - ������������� �������������� �����                 // 28/05/09
  // incode - ���������� ��� ������� (����� �� �������)
  // name - ����� ������ ��� ���������� ����������
  // size - ����������������� ������ ������ (����� ���� �� 2048 ����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscObjectNameUn(HRSC hRsc,long int incode,
                                                WCHAR * name, long int size);

_MAPIMP  long int _MAPAPI mapGetRscObjectNameUnicode(HRSC hRsc,long int incode,
                                                     WCHAR * name, long int size);

  // ��������� ���� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscObjectKey(HRSC hRsc,long int incode);

  // ��������� ���� ������� �� �����������  ���� (����������� ������) // 29/05/09
  // ������� (� 1) � ��������� UNICODE
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ������ ������

_MAPIMP  long int _MAPAPI mapGetRscObjectKeyUn(HRSC hRsc,long int incode,
                                               WCHAR * name, long int size);

  // ���������� ���� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // (�������� ��� ������ ���� ���������)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapSetRscObjectKey(HRSC hRsc,long int incode,
                                                const char * key);

  // ��������� ��� ����������� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����                 // 28/05/09
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ���� (���� ��������)

_MAPIMP  long int  _MAPAPI mapGetRscObjectLocal(HRSC hRsc,
                                                long int incode);

  // ��������� ����� ���� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����                 // 28/05/09
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ���� (���� ��������)

_MAPIMP  long int  _MAPAPI mapGetRscObjectSegment(HRSC hRsc,
                                                  long int incode);

  // ��������� ������������� ������ ���� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����                 // 25/09/14
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ����

_MAPIMP long int  _MAPAPI mapGetRscObjectClass(HRSC hRsc, long int incode);

  // ���������� ������������� ������ ���� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����                 // 25/09/14
  // incode - ���������� ��� ������� (����� �� �������)
  // ident - ������������� ������
  // ��� ������ ���������� ����

 _MAPIMP long int  _MAPAPI mapSetRscObjectClass(HRSC hRsc, long int incode,
                                                 long int ident);

  // ��������� ������������� ������� (���������� ���������� ��������
  // � �������� ������� ��������������) �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectIdent(HRSC hRsc,long int incode);


  // ��������� ���������� ��� (���������� �����) �������
  // �� ��������������
  // hRsc - ������������� �������������� �����
  // ident - ������������� �������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectIdentIncode(HRSC hRsc,long int ident);


  // ��������� ���������� ��� (���������� �����) �������
  // �� �����
  // hRsc - ������������� �������������� �����
  // key  - ���� �������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectCodeByKey(HRSC hRsc,const char * key);
_MAPIMP  long _MAPAPI mapGetRscObjectKeyIncode(HRSC hRsc,const char * key);
_MAPIMP  long _MAPAPI mapGetRscObjectCodeByKeyUn(HRSC hRsc, const WCHAR * key);  // 29/05/09

  // ��������� ����������  ��� (���������� �����) �������       //22/06/01
  // �� �����
  // hRsc - ������������� �������������� �����
  // name - ��� �������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectCodeByName(HRSC hRsc,char * name);


  // ��������� ����� �������� �������� �� ������� ��� ������� �� �����������
  // ���� (����������� ������)  ������� (� 1)
  // incode - ���������� ��� ������� (����� �� �������)
  // hRsc   - ������������� �������������� �����

_MAPIMP  long  _MAPAPI mapGetRscImageSemanticCount(HRSC hRsc,long int incode);


  // ������ ���� ��������� �������� �� ����������� �� ����������� ����
  // (����������� ������) ������� � ����������� ������ ����� ��������� (c 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // number - ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscImageSemanticCode(HRSC hRsc,long int incode,
                                                 long int number);

  // ���p����� ���������� ��������� �������� �������        //01/11/01
  // �� ����������� ���� (����������� ������) �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)

_MAPIMP  long _MAPAPI mapGetRscObjectRelateCount(HRSC hRsc,long int incode);


  // ���p����� �������� ��������� ������� �� ����������� ����   //01/11/01
  // (����������� ������) ������� � �� ����������� ������ ��������� ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // relate - �������� ��������� ������� (maptype.h)
  // Order  - ���������� ����� ��������� �������
  // ���������� ������������� �������,
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectRelateOrder(HRSC hRsc,long int incode,
                                                 long int order,RSCRELATION * relate);

  // ��������� ��������� ������ ��� ������� ��������� �������   // 14/04/06
  // �� �����������  ���� (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // semanticcode - ��� ��������� �������
  // viewtype - ��� ����������� ������� 0 - ��������, 1 - ����������
  // ��� ������ ��� ���� � ���������� ������� ��� ������� ����������  0

_MAPIMP  long _MAPAPI mapGetRscObjectSemanticFont(HRSC hRsc, long int incode,
                                                  long int semanticcode, LOGFONT * font,
                                                  long int viewtype);

  // ���������� ��� ������� �� �����������  ���� (����������� ������) ������� (� 1)
  // � ��������� UNICODE
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // name - ��� ������� � ��������� UNICODE
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscObjectNameUn(HRSC hRsc,long int incode,
                                                const WCHAR * name);

_MAPIMP  long int _MAPAPI mapSetRscObjectNameUnicode(HRSC hRsc,long int incode,
                                                     const WCHAR * name);


  /**************************************************************
  *                                                             *
  *  ������� ������ � ����������� ����������� ��������          *
  *                                                             *
  **************************************************************/

  // ��������� ����� ������� ����������� ������� �� �����������  ����
  // (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscObjectFunction(HRSC hRsc,long int incode);


  // ��������� ����� ���������� ����������� ������� �� �����������  ����
  // (����������� ������)������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectParametersSize(HRSC hRsc,long int incode);


  // ��������� ��������� ����������� ������� �� �����������  ����
  // (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  const char * _MAPAPI mapGetRscObjectParameters(HRSC hRsc,long int incode);


  // ��������� ���������� ���������� � ���������� ����������� ������� ��
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrimitiveCount(HRSC hRsc,long int incode,
                                               long int viewtype = 0);


  // ��������� ����� ������� ����������� ��������� �� �����������
  // ������ ��������� � ���������� ����������� ������� ,
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrimitiveFunction(HRSC hRsc, long int incode,
                                                  int number,
                                                  long int viewtype = 0);

  // ��������� ����� ���������� ��������� �� �����������
  // ������ ��������� � ���������� ����������� ������� ,
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // number - ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrimitiveLength(HRSC hRsc,long int incode,
                                                int number,
                                                long int viewtype = 0);

  // ��������� ����� ���������� ��������� �� �����������
  // ������ ��������� � ���������� ����������� ������� ,
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // number - ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  char * _MAPAPI mapGetRscPrimitiveParameters(HRSC hRsc,long int incode,
                                                     int number,
                                                     long int viewtype = 0);

  // �������� ������������ ����������� � ���� ����������� �������
  // �� ����������� ����  ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscImageSuitable(HRSC hRsc,long int local,
                                     long int incode);


  // ���������� ������� ��� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // length - ����� ����������
  // number - ����� ������� �����������
  // param  - ��������� �� ��������� �������
  // ��� ������ ���������� ���� , ����� ���������� ����� �������

_MAPIMP  long int  _MAPAPI mapSetRscObjectImage(HRSC hRsc,
                                         long int incode,
                                         long int length,
                                         long int number,char * param);


  // ��������� ����� ������� (�����������) ����������� ������� �� ����������� ����
  // (����������� ������) �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrintObjectFunction(HRSC hRsc,long int incode);   //26/11/01


  // ��������� ����� ���������� (�����������)����������� ������� �� �����������  ����
  //(����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0                                              //05/02/02

_MAPIMP  long _MAPAPI mapGetRscPrintObjectParametersSize(HRSC hRsc,long int incode);


  // ��������� ��������� ����������� (�����������)������� �� �����������  ����
  //  �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0
                                                       //26/11/01
_MAPIMP  const char * _MAPAPI mapGetRscPrintObjectParameters(HRSC hRsc,long int incode);


  // ���������� ���������� ��� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // length - ����� ����������
  // number - ����� ������� �����������
  // param  - ��������� �� ��������� �������
  // ��� ������ ���������� ���� , ����� ���������� ����� �������
                                                     //26/11/01
_MAPIMP  long int  _MAPAPI mapSetRscPrintObjectImage(HRSC hRsc,
              long int incode,long int length,long int number,char * param);


  // ����� "��������" ���� ����������� �������                  // 11/04/05
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // viewtype - ��� �����������  0 - ��������, 1 - ����������
  // ��� ���������� ����� ���������� 0xFF000000
  // ��� ������ ���������� 0

_MAPIMP  COLORREF  _MAPAPI  mapGetRscObjectBaseColor(HRSC hRsc, long int incode,
                                          long int viewtype);


  // ��������� ��������� ������ ������� �� �����������  ����     // 14/04/06
  // (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // viewtype -��� �����������  0 - ��������, 1 - ����������
  // ��� ������ ��� ���� � ���������� ������� ��� ������� ����������  0

_MAPIMP long int _MAPAPI mapGetRscObjectFont(HRSC hRsc,long int incode,LOGFONT * font,
                                             long int viewtype);

  // ��������� ��������� ������ �� ���������� ������
  // ��������� ������ ����������� ���������, ���� ����� �������� ���� ����
  // ����� � ���������� ��������������� ��������������
  // ������ ������ ����������� ��� �������� �������� ����� � �������
  // ����������� ������
  // hRsc - ������������� �������������� �����
  // text - ��������� ������� ����������� ������
  // font - ������������ ���������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRscTextFont(HRSC hRsc, const IMGTEXT *text, LOGFONT *font);

 // ��������� ������ ����� ��������, ����������� ������� � ��������� ������,
 // ���������� ������ ���� �������
 // incode - ���������� ��� (���������� ����� ������� � 1)        // 15/02/11
 // size - ����������� �������(���������� ���������)
 // code - ����� ������� ����� ���������
 // viewtype -��� �����������  0 - ��������, 1 - ����������, 2 - ���
 // ���������� ����� ��������, �� ������� ������� �������
 // ���� ������ ������� ������, ��� ����� �������� "������" ��������� �� �������

_MAPIMP long int _MAPAPI mapGetRscObjectLabelSemantics(HRSC hrsc, long int incode,
                               long int viewtype, long int size, int * code);

 // ������� ���������� ��� �������
 // incode - ���������� ��� (���������� ����� ������� � 1)        // 06/05/16
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapDeleteRscPrintObjectParameters(HRSC hRsc,
                                                           long int incode);


  /**************************************************************
  *                                                             *
  *     ������� ���������� ���������������� ��������            *
  *                                                             *
  **************************************************************/

  // ��������� ���� ������ ����������� �������                     // 18/04/05
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // ���������� 0 - ����������� ���������, 1 - ���.

_MAPIMP  int _MAPAPI  mapGetRscObjectPressure(HRSC hRsc, long int incode);


  // ���������� ���� ������ ����������� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // flag - ���� ������ ����������� 0 - ���������, 1 - ���.
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI  mapSetRscObjectPressure(HRSC hRsc, long int incode,long int flag);

  // ��������� ������ ������������� ������ ����������� �������      // 18/12/07
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // ���������� ����������� ������������� ������, ���������� �� 10.

_MAPIMP  int _MAPAPI  mapGetRscObjectPressLimit(HRSC hRsc, long int incode);

  // ���������� ������ ������������� ������ ����������� �������      // 18/12/07
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // presslimit - ����������� ������������� ������, ���������� �� 10.
  //              � ��������� �� 10 �� 250)
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI  mapSetRscObjectPressLimit(HRSC hRsc, long int incode,
                                                 long int presslimit);

  // ��������� ���� ��������������� ����������� �������    // 02/11/12
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // ���������� 1 - ����������� ��������������, 0 - ���.

_MAPIMP  int _MAPAPI  mapGetRscObjectScale(HRSC hRsc, long int incode);

  // ���������� ���� ��������������� ����������� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // flag - ���� ��������������� ����������� 1 - ��������������, 0 - ���.
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI  mapSetRscObjectScale(HRSC hRsc, long int incode,long int flag);

  // ��������� ������ ������������� ���������� ����������� �������      // 18/12/07
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // ���������� ����������� ������������� ����������, ���������� �� 10.

_MAPIMP  int _MAPAPI  mapGetRscObjectScaleLimit(HRSC hRsc, long int incode);

  // ���������� ������ ������������� ���������� ����������� �������   // 18/12/07
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // scalelimit - ����������� ������������� ������, ���������� �� 10.
  //              � ��������� �� 10 �� 250)
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI  mapSetRscObjectScaleLimit(HRSC hRsc, long int incode,
                                                long int scalelimit);

  // ���������� ������� ��������� ������� �� ����� (�������� ���������    // 02/07/08
  // ��������� ������� �� �����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (���������� ��� � ��������������)
  // bottom - ����������� �������� ����������� �������� ��� ������� �����
  //          ������
  // top    - ������������ �������� ����������� �������� ��� ������� �����
  //          ������
  // ��� ��������� �������� ��������� ��� ����������� �� ���������
  // �������� �� ������� ����������� ��������� � ���������� �������� "�������"
  // ��� "��������" ������� (� ����������� �� ���������������� ��������)
  // ��������, ��� �������� bottom = 1, top = 199999, ������ �����
  // ����� � ��������� ������� 1:200 000 (��� ���������� ����� 200 000),
  // � ������� ������� ����� ���� bottom = 200000, top = 1000000 - ��
  // ����� ����� � ��������� 1:200 000 � ������ � ����� ��������� ����������
  // ������ (������ ��� ������� �� �����������).
  // �� ���� �������� ��������� ������� 160000 � 170000 - ��� ������������
  // � 200 000 �� ���� ����� �����������.
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI mapSetRscObjectScaleBorder(HRSC hRsc, long int incode,
                                                long int bottom, long int top);

  // ��������� ������� ��������� ������� �� ����� (�������� ���������
  // ��������� ������� �� �����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (���������� ��� � ��������������)
  // bottom - ����������� �������� ����������� �������� ��� ������� �����
  //          ������
  // top    - ������������ �������� ����������� �������� ��� ������� �����
  //          ������
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI mapGetRscObjectScaleBorder(HRSC hRsc, long int incode,
                                                long int * bottom, long int * top);

  // ��������� ��������� ������� ������� ��������� ������� �� �����    // 11/12/15
  // � �������� ���������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (���������� ��� � ��������������)
  // ������ - ���������� 1, ����� 0

 _MAPIMP  int _MAPAPI mapGetRscObjectBotScaleInclude(HRSC hRsc, long int incode);

  // ��������� ��������� ������ ������� ��������� ������� �� �����
  // � �������� ���������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (���������� ��� � ��������������)
  // ������ - ���������� 1, ����� 0

 _MAPIMP  int _MAPAPI mapGetRscObjectTopScaleInclude(HRSC hRsc, long int incode);


  /**************************************************************
  *                                                             *
  *  ������� ������ � ����������� �� �������������� ��'�����    *
  *                                                             *
  **************************************************************/

  // ������� ����� ��������� - ����������  ��� ��������� ���������
  // hRsc - ������������� �������������� �����
  // ��������� RSCSEMANTICEX ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapAppendRscSemanticEx(HRSC hRsc,RSCSEMANTICEX * rsem);


  // �������� ��������� - ����������  ��� ����������� ���������
  // code - ��� ����������� ���������
  // classupdate - 1, ������������� ��������� ��������� ��� ������������
  // ����������(�������� ��� ����� ���� ���������), 0 - ��� ��������� ��������
  // ������� � ���������� �������������� ������ ��������� �� �����.
  // hRsc - ������������� �������������� �����
  // ��������� RSCSEMANTICEX ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapUpdateRscSemanticEx(HRSC hRsc,long int code,
                                    RSCSEMANTICEX * rsem,long int classupdate);


  // ������� ���������
  // code - ��� ��������� ���������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapDeleteRscSemantic(HRSC hRsc,long int code);


  // ��������� ���������� � ���������� ��������� ��� �������� �����
  // code - ��� ���������
  // applysemantic - ��������� ��� ���������� (maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscApplySemantic(HRSC hRsc,long int code,
                                           APPLYSEMANTIC * applysemantic);


  // �������� �������������� ��������� �������
  // hRsc - ������������� �������������� �����
  // objincode - ���������� ��� �������,
  // code      - ��� ���������,
  // enable    - ��� ������� � ���������
  // (2 - ������������, 1 - ���������)
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapEnableRscSemantic(HRSC hRsc,
                                         long int objincode,
                                         long int code,
                                         long int enable);


  // ��������� ���������� �������� � ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticCount(HRSC hRsc);

  // ��������� ��� ��������� �� ����������� ������
  // hRsc   - ������������� �������������� �����
  // number - ���������� ����� ��������� � 1
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticCodeByNumber(HRSC hRsc, long int number);

  // ��������� ��� ��������� �� ��������� ����� (�����)���������   // 18/09/15
  // (���� ��������� ������ ���� ������� �������� ���������� ��������, ����, ������ �������������)
  // hRsc      - ������������� �������������� �����
  // shortname - �������� ��� ���������
  // ��� ������ ���������� ����
  
_MAPIMP long int _MAPAPI mapGetRscSemanticCodeByKey(HRSC hRsc, const char * key);
_MAPIMP long int _MAPAPI mapGetRscSemanticCodeByKeyUn(HRSC hRsc, const WCHAR * key);

  // ��������� ���������� ����� ���������
  // �� ��������� ����� (�����)���������                        
  // hRsc      - ������������� �������������� �����
  // shortname - �������� ��� ���������
  // ��� ������ ���������� ����
  // ����� ���������� ����� ��������� (� 1)

_MAPIMP  long int _MAPAPI mapGetRscSemanticByShortName(HRSC hRsc,const char * shortname);
_MAPIMP  long int _MAPAPI mapGetRscSemanticByKey(HRSC hRsc,const char * key);
_MAPIMP  long int _MAPAPI mapGetRscSemanticByShortNameUn(HRSC hRsc,const WCHAR * shortname);
_MAPIMP  long int _MAPAPI mapGetRscSemanticByKeyUn(HRSC hRsc, const WCHAR * key);

  // ��������� �������� ��������� �� ����������� ������
  // hRsc   - ������������� �������������� �����
  // number - ���������� ����� ��������� � 1
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSemanticNameByNumber(HRSC hRsc, long int number);

  // ��������� �������� ��������� �� ����������� ������ � ��������� UNICODE
  // hRsc - ������������� �������������� �����
  // number - ����� ���������
  // name   - ����� ������ ��� ���������� ����������
  // size   - ������������ ������ �������� ������
  // ��� ������ ���������� ������ ������

_MAPIMP  long int _MAPAPI mapGetRscSemanticNameByNumberUn(HRSC hRsc, long int number,
                                                          WCHAR * name, long int size);

  // ��������� �������� ��������� �� ���� � ��������� UNICODE
  // hRsc - ������������� �������������� �����                  // 15/06/09
  // code - ��� ���������
  // name - ����� ������ ��� ���������� ����������
  // size - ������������ ������ �������� ������ (����� ���� �� 2048 ����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSemanticNameUn(HRSC hRsc, long int code,
                                                  WCHAR * name, long int size);

_MAPIMP  long int _MAPAPI mapGetRscSemanticNameUnicode(HRSC hRsc, long int code,
                                                       WCHAR * name, long int size);

  // ���������� �������� ��������� �� ���� � ��������� UNICODE
  // hRsc - ������������� �������������� �����                  // 17/04/11
  // code - ��� ���������
  // name - ����� ������ � ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemanticNameUn(HRSC hRsc, long int code,
                                                  const WCHAR * name);

_MAPIMP  long int _MAPAPI mapSetRscSemanticNameUnicode(HRSC hRsc, long int code,
                                                       const WCHAR * name);

  // ��������� ��� ��������� �� �� �������� ����
  // ���� ����� �������� - ��. maptype.h (SEMTYPE)
  // hRsc - ������������� �������������� �����
  // code - �������� ��� ���������
  // ��� ������ ���������� ���� (���������� ��������� ����� ��� ����!)

_MAPIMP  long int _MAPAPI mapGetRscSemanticTypeByCode(HRSC hRsc, long int code);


  // ��������� �������� ��� (����) ���������
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSemanticShortName(HRSC hRsc,long int code);
_MAPIMP  long int _MAPAPI mapGetRscSemanticShortNameUn(HRSC hRsc,long int code,
                                                WCHAR * shortname, long int size);
_MAPIMP  const char * _MAPAPI mapGetRscSemanticKey(HRSC hRsc,long int code);

  // ��������� �������� ��� (����) ��������� � ��������� UNICODE
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // name   - ����� ������ ��� ���������� ����������
  // size   - ������������ ������ ������
  // ��� ������ ���������� ������ ������

_MAPIMP  long int _MAPAPI mapGetRscSemanticKeyUn(HRSC hRsc,long int code,
                                                 WCHAR * name, long int size);

  // ���������� �������� ��� (����) ���������
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemanticShortName(HRSC hRsc, long int code,
                                                     const char * shortname);
_MAPIMP  long int _MAPAPI mapSetRscSemanticKey(HRSC hRsc,long int code,
                                               const char * key);


  // ���������� �������� ��� (����) ���������
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemanticShortNameUn(HRSC hRsc, long int code,
                                                       const WCHAR * shortname);
_MAPIMP  long int _MAPAPI mapSetRscSemanticKeyUn(HRSC hRsc,long int code,
                                                 const WCHAR * key);

  // ���������� ������ � �������� �������� ��������� 
  // hRsc - ������������� �������������� �����
  // size - ������ �������� ��������� (������� ���������� �����)
  // decimal - ���������� ������ ����� ������� (� ���������� - 0)
  // code - ��� ���������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemanticDecimal(HRSC hRsc,long int code,
                                                   long int size,long int decimal);


  // ��������� ��������� �������� ������������� ��������������
  // �� ���� ���������
  // hRsc - ������������� �������������� �����
  // code - ������� ��� ���������
  // ��������� RSCSEMANTICEX ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticExByCode(HRSC hRsc,RSCSEMANTICEX * semtype,
                                                    long int code);


  // ��������� ���������� �������� �������������� �������������
  // �������������� �� ���� ��������� (���� �� ��� TCODE)
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticClassificatorCount(HRSC hRsc,
                                                    long int code);

  //  ��������� �������� �������� �������������� ��
  //  �������������� ��������� �� ���� ��������� �
  //  ����������������� ������ � ��������������
  //  hRsc - ������������� �������������� �����
  //  code - ��� ���������
  //  number - ���������������� ����� � ��������������(1,2,3...)
  //  ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSemanticClassificatorName(HRSC hRsc,long int code,
                                                                 long int number);

  //  ��������� �������� �������� �������������� ��
  //  �������������� ��������� �� ���� ��������� �
  //  ����������������� ������ � �������������� � ��������� UNICODE
  //  hRsc - ������������� �������������� �����
  //  code   - ��� ���������
  //  number - ���������������� ����� � ��������������(1,2,3...)
  //  name   - ����� ������ ��� ���������� ����������
  //  size   - ������������ ������ ������ (����� ���� �� 2048 ����)
  //  ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticClassificatorNameUn(HRSC hRsc,long int code,
                                                               long int number,
                                                               WCHAR * name, long int size);

  // ��������� ��� �������� �������������� ��
  // �������������� ��������� �� ���� ��������� �
  // ����������������� ������ � ��������������
  // hRsc - ������������� �������������� �����
  // number - ���������������� ����� � ��������������(1,2,3...)
  // code - ��� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticClassificatorCode(HRSC hRsc,
                                                             long int code,
                                                             long int number);

  // �������� ����� "�������" ��������������
  // (�������� �������� � ����������) ����������
  // ����� ���������� ������ � 1
  // hRsc - ������������� �������������� �����
  // code - ��� ������������� ��������������
  // value - �������� ��������
  // name  - ���������� �������� ������������� ��������������
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapAppendRscClassificator(HRSC hRsc,
                                                     long int code,
                                                     long int value, const char * name);
_MAPIMP  long int  _MAPAPI mapAppendRscClassificatorUn(HRSC hRsc,                        // 07/12/12
                                                     long int code,
                                                     long int value, const WCHAR * name);

  // �������� ���������� �������� �������������� �� ������ ������ (� 1)
  // ���������� ����� ������������ ������ � 1
  // hRsc - ������������� �������������� �����
  // code - ��� ������������� ��������������
  // index - ����� ������
  // name  - ���������� �������� ������������� ��������������
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapUpdateRscClassificatorName(HRSC hRsc,
                                                         long int code,
                                                         long int index, const char * name);

_MAPIMP  long int  _MAPAPI mapUpdateRscClassificatorNameUn(HRSC hRsc,               // 12/09/12
                                                         long int code,
                                                         long int index, const WCHAR * name);

 // ����� �������� ������������� ������ ���������-�������������� �� ���������� ��������
  // ����� �������������� �� ���������� �������� ������ � �������� � ������
  // ������ � ���������-��������������  
  // hRsc - ������������� �������������� �����
  // code - ��� ������������� �������������� ���� �������������
  // name  - ���������� �������� ������������� ��������������, ������� ����� �����
  // ���� �� ����� ���������� 0, ����� - �������� �������� �������������� ���������

_MAPIMP  long int  _MAPAPI mapFindRscClassificatorCode(HRSC hRsc,
                                                       long int code, const char * name);
_MAPIMP  long int  _MAPAPI mapFindRscClassificatorCodeUn(HRSC hRsc,
                                                       long int code, const WCHAR * name);     // 28/12/12

 // ��������� ���� ������ �������������� ���������  16/02/10
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������

_MAPIMP  const char * _MAPAPI mapGetRscClsKey(HRSC hRsc,long code,long value);

 // �������� ���� �������������� ���������                       16/02/10
 // ��� ����� ��������� ���� �������������� ������ ���� ��������
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������
 // ���������� �������� �������������� � ������ ������, ���� ��� ��������
 // �� ��������� � ������� - ���� ���������� � �� �������

_MAPIMP  long int _MAPAPI mapSetRscClsKey(HRSC hRsc,long code,long value,
                                           const char * key);

 // ������ ������� ����� �������������� ��������� (� UNICODE)
 // �� ���� ��������� � �������� ��������������
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������
 // size - ������ ������ ��� ���������� ������         // 16/02/10
 // buffer - ����� ��� ���������� ������
 // ���������� ����� ������� ����� ��� 0

_MAPIMP  long int _MAPAPI mapGetRscClsFullNameUn(HRSC hRsc, long int code, long int value,
                                                 long int size, WCHAR * buffer);

_MAPIMP  long int _MAPAPI mapGetRscSemanticClassificatorFullNameUn(HRSC hRsc,   // 15/05/13
                          long int code, long int value, WCHAR * buffer, int size);

 // �������� ������ ��� �������������� ��������� (� UNICODE)
 // �� ���� ��������� � �������� ��������������
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������
 // buffer - ������ ��� ������� (� UNICODE)           // 16/02/10
 // ���������� ����� ������� ����� ��� 0

_MAPIMP  long int _MAPAPI mapSetRscClsFullNameUn(HRSC hRsc,long int code,long int value,
                                                 const WCHAR * buffer);

 // ������ ��������� ����� �������������� ���������   // 17/12/14
 // �� ���� ��������� � ��������� �������� ��������������
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������
 // ��� ������ ���������� ����� ������ ������,
 // ��� �������� ���������� - ����� ������

 _MAPIMP const char * _MAPAPI mapRscSemanticClassificatorShortName(HRSC hRsc,
                                       long int code,long int value);

 // ��������� �������� �������������� ��������� �� �����   16/02/10
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������
_MAPIMP  long int _MAPAPI mapGetRscClsKeyValue(HRSC hRsc,long int code,char * key);


  // ��������� �������� �� ��������� ������� 3D ����������� �� ����  // 27/06/13
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ���� ��������� - ������ 3D ����������� ���������� 1,
  // ����� - 0

_MAPIMP  long int _MAPAPI mapGetRscSemantic3DListFlag(HRSC hRsc,long int code);

 // ���������� ������� ��������� - ������ 3D �����������     // 28/06/13
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemantic3DListFlag(HRSC hRsc,long int code);

 // ��������� ���� ������� �������������� ���������          // 23/08/13
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // ���������� 0 ��� 1

_MAPIMP long int _MAPAPI mapGetRscSemanticNotEditFlag(HRSC hRsc,long int code);

 // ���������� ���� ������� �������������� ���������     // 23/08/13
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // flag - 1 - ���������� ������, 0 - �����
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRscSemanticNotEditFlag(HRSC hRsc,long int code,long int flag);

  // ��������� ���������� �������� - ������� 3D �����������  � ������ ����������
  // libcode  - ��� ����������                                      // 27/06/13
  // hRsc - ������������� �������������� �����

_MAPIMP  long int _MAPAPI mapGetRscSemantic3DListCount(HRSC hRsc,long int libcode);

  // ��������� ������ ����� �������� - ������� 3D �����������     // 27/06/13
  // � ������ ����������
  // hRsc - ������������� �������������� �����
  // libcode  - ��� ����������
  // code - ����� ������� ����� ��������
  // countlimit - ������ �������
  // ���������� ����� ���������� ����� ���������
  // ����� 0

_MAPIMP  long int _MAPAPI mapGetRscSemantic3DList(HRSC hRsc, long int libcode,
                                                  long int *code, long int countlimit);

  /**************************************************************
  *                                                             *
  *  ������� ������ � ����������� ��� ���������  ��'�����       *
  *                                                             *
  **************************************************************/

  // ��������� ���������� �������� ��� ������� �������
  // �� ���������� ��������� - ��. maptype.h (SEMANTIC_FOR_OBJECT )
  // �� ����������� ���� (����������� ������) ������� (c 1)
  // hRsc - ������������� �������������� �����
  // ���������� ���������� �������� ��������� ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // importance - ��������

_MAPIMP  long int  _MAPAPI mapGetRscSemanticObjectCount( HRSC hRsc,long int incode,
                                                  long int importance);


  // ��������� ������������� ��������� ��� ������� ������� -
  // incode - ���������� ��� (���������� �����)�������
  // semanticcode - ��� ���������
  // hRsc - ������������� �������������� �����
  // ���������� ���������� ���������  ��. maptype.h (SEMANTIC_FOR_OBJECT )

_MAPIMP  long int  _MAPAPI mapGetRscSemanticObjectUsed(HRSC hRsc,long int incode,
                                      long int semanticcode);

  // ��������� ������������� ��������� ��� ������� ������� -    // 19/02/09
  // ��� ����� ����� �������� � �������� ����
  // incode - ���������� ���(������)�������
  // semanticcode - ��� ���������
  // hRsc - ������������� �������������� �����
  // ���������� ���������� ���������  ��. maptype.h (SEMANTIC_FOR_OBJECT )

_MAPIMP  long int  _MAPAPI mapGetRscSemanticOnlyObjectUsed(HRSC hRsc,long int incode,
                                      long int semanticcode);


  // ��������� ��� ���������  ��� ������� ������� �� ����������� ������
  // ������ ��������� ��� ������� (� 1) � ���������� ���������
  // ��. maptype.h (SEMANTIC_FOR_OBJECT ) ��� ���������� ���������
  // ALL_SEMANTIC - ���������� ��������� � ������� ����������
  // incode - ���������� ��� (���������� �����) �������
  // importance - ���������� ���������
  // hRsc - ������������� �������������� �����
  // ���������� ��� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscSemanticObjectCode(HRSC hRsc,long int incode,
                                                     long int number,long int importance);

  // ��������� ������ ���� ����� ��������� ��� ������� �������
  // incode - ���������� ���(������)�������
  // hRsc   - ������������� �������������� �����
  // code   - ����� ������� ��������
  // countlimit - ������ �������
  // ���������� ����� ��������� ����� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscSemanticObjectCodeList(HRSC hRsc,long int incode,
                                                         long int * code, long int countlimit);
                                                           
  // �������� ��� ���������  ��� ������� ������� �� ���������� ���������
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC)
  // semanticcode - ��� ���������
  // incode - ���������� ��� (���������� �����) �������
  // hRsc - ������������� �������������� �����
  // ���������� ����� ����������� ��������� � ���������� ������� ����
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapAppendRscSemanticObject(HRSC hRsc,long int incode,
                                     long int semanticcode,long int importance);


  // �������� ���������� ��������� ��� ������� �������
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC)
  // semanticcode - ��� ���������
  // incode - ���������� ��� (���������� �����) �������
  // hRsc - ������������� �������������� �����
  // ���������� ����� �������� ��������� ����������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapUpdateRscSemanticObject(HRSC hRsc,long int incode,
                                     long int semanticcode,long int importance);


  // ������� ��������� ��� ������� �������
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC)
  // semanticcode - ��� ���������
  // incode - ���������� ��� (���������� �����) �������
  // hRsc - ������������� �������������� �����
  // ���������� ����� ����� �������� �������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapDeleteRscSemanticObject(HRSC hRsc,long int incode,
                                     long int semanticcode);


   // ��������������� ������ �������� ��� ������� � ������������ �  // 16/02/04
   // ����������� ��������
   // incode - ���������� ��� (���������� �����) �������
   // hRsc - ������������� �������������� �����
   // count - ������ ������� �������� ������� ��� ����������
   // semantics - ��������� �� ������ ������� ��������� �������� �������.
   // order     - ��������� �� �������� ������ �������� ����������������
   // ����������� �������� ������� ��������(� 1 )
   // ��� ���������� ���������� ���������� 1

_MAPIMP   long int  _MAPAPI mapSortRscObjSemantic(HRSC hRsc,long int incode,
                            long int count,long int * semantics,long int * order);


   // �������� ������� �������� ��� ������� � ������������ � �������
   // �������
   // incode - ���������� ��� (���������� �����) �������
   // hRsc - ������������� �������������� �����
   // count - ������ ������� �������� �������
   // semantics - ��������� �� ������������� ������ �������� �������.
   // ��������� ������� �� �������� ������� - ������������,
   // ���� ����� - �� ��������� ��������� ������� � ����� ������
   // ��� ���������� ���������� ���������� ���������� �������� �������

_MAPIMP   long int  _MAPAPI mapSetRscObjSemanticOrder(HRSC hRsc,long int incode,
                                       long int count,long int * semantics);

   // ��������� ������ ���� �������� ��������������, ������������ ��������� �
   // ��������� - ������ 3D ����.
   // hRsc - ������������� �������������� �����
   // buffer - ��������� �� ������ ������ 
   // count - ������ ������ � ������ (�� ����� ���������� �������� ��������������) 
   // ���� ��� ������� ��������� ��������� - ������ 3D �����, � �����
   // �� �����, ������������ ���������� ����� ������� ��������� 1, ����� 0.
   // ��� ���������� ���������� ���������� ���������� ��������, ��� �������
   // ����� �������������� ��������� - ������ 3D �����
                                                                   // 16/09/13
_MAPIMP long int  _MAPAPI mapGetRscAll3DSemObjects(HRSC hRsc,char * buffer,
                                                long int count);

  /**************************************************************
  *                                                             *
  *  ������� ������ � ��������� ���������������                 *
  *                                                             *
  **************************************************************/

  // ��������� ���� �� �������
  // color - ���� � COLORREF
  // index - ���������� ����� ����� � ������� (� 1)
  // number - ���������� ����� ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� ���� � COLORREF

_MAPIMP  COLORREF _MAPAPI mapGetRscColor(HRSC hRsc,long int index,
                                         long int number = 1);


  // ���������� ���� � ������ �������
  // color - ���� � COLORREF
  // index - ���������� ����� ����� � ������� (� 1)
  // number - ���������� ����� ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� �������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapSetRscColor(HRSC hRsc,COLORREF color,long int index,
                                           long int number = 1);

  // ��������� ���������� ������ � ������� ��������������
  // hRsc - ������������� �������������� �����

_MAPIMP  long int  _MAPAPI mapGetRscColorCount(HRSC hRsc);


  // ��������� ���������� ������ ��������������
  // hRsc - ������������� �������������� �����

_MAPIMP  long int  _MAPAPI mapGetRscPaletteCount(HRSC hRsc);


  // ������ ����� ������� �� �� ������
  // number - ���������� ����� ������� (� 1)
  // hRsc - ������������� �������������� �����

_MAPIMP  char * _MAPAPI mapGetRscPaletteName(HRSC hRsc,int number);
_MAPIMP long int _MAPAPI mapGetRscPaletteNameUn(HRSC hRsc, int number, WCHAR * name, long int size);

  // ��������� ���� �� CMYK - �������                       // 13/10/06
  // index - ���������� ����� ����� � ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� ���� �� 4 ������������ (�,M,Y,K)
  // (������ � ��������� �� 0 �� 255)

_MAPIMP unsigned long _MAPAPI mapGetRscCMYKColor(HRSC hRsc,long int index);

  // ���������� ���� � CMYK - �������                      // 13/10/06
  // color - 4 ������������ (�,M,Y,K)
  // (������ � ��������� �� 0 �� 255)
  // index - ���������� ����� ����� � ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRscCMYKColor(HRSC hRsc,unsigned long int color,
                                             long int index);


  /************************************************************
  *                                                           *
  *  ������� ������ � �������� ���������������  //04/10/01    *
  *                                                           *
  ************************************************************/

  // K�� ������ - ������������� � ��������� ������� (IMGTEXT: ���� Type)
  // (��. mapgdi.h) ��� ������ �� ������� �������.

  // ������ ���������� �������
  // ��� ������ ���������� ����
  // hRsc - ������������� �������������� �����

_MAPIMP  long int _MAPAPI mapGetFontCount(HRSC hRsc);


  // �������� ����� - ���������� ��� ������
  // hRsc - ������������� �������������� �����
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapAppendFont(HRSC hRsc,RSCFONT * font);


  // �������� ����� - ���������� ��� ������
  // hRsc - ������������� �������������� �����
  // index - ���������� ����� ������ (� 1)
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapReplaceFont(HRSC hRsc,int index,RSCFONT * font);


  // ������ ���� ������ �� ����������� ������(c 1)
  // hRsc - ������������� �������������� �����
  // number - ����� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetFontCode(HRSC hRsc,int number);


  // ������ ������ �� ����������� ������ (c 1)
  // ���������� ��� ������
  // hRsc - ������������� �������������� �����
  // number - ����� ������
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetFont(HRSC hRsc,int number,RSCFONT * font);


  // ������ ������ �� ����
  // ���������� ���������� ����� ������ (� 1)
  // hRsc - ������������� �������������� �����
  // code - ��� ������
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetFontByCode(HRSC hRsc,int code,RSCFONT * font);

  // ���������� ���������� ������                              // 16/12/15
  // hRsc - ������������� �������������� �����
  // code - ��� ������
  // ���������� ���������� ����� ������ � ������� �������
  // ��� ������ ���������� ����
_MAPIMP  long int _MAPAPI mapSetFontByCode(HRSC hRsc,int code);


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  // 19/07/06
// +++++     �������� ������� �������� � ���������� ������           ++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  // �������� ���������� ������� � ���������� �� ��������
  // ���������� ��������: +,  -,  *,  /,
  // (����������� ����� ���������� ������� ,)
  // MAX(... ,...,   ),MIN(... ,...,   )- ��������, �������
  // ARM(... ,...,   ) - ������� ��������������
  // (����������� ����� ���������� � MAX, MIN, ARM - ������� ,)
  // SIN,COS,TG,CTG - ������������������ ������� �� ����� � �������� � ����� �������
  // SQRT2(),SQRT3(),POW2(),POW3() - ������ � ���������� �� 2,3 �������
  // PI - ����� PI
  // P - �������� �������,
  // S - ������� �������
  // # - ���������, ��� ������ ���� ��� ���������, � ������� ����� ��������,
  //     ����� � ()�������� �� ���������.
  // (������: #1(0) - ����� �������� ��������� 1, ��� ���������� ����� 0)
  // ����� 0- 9,(����������� ����� .)
  // ������ (),[],{}
  // ���������� 0 ��� ������, � � ���������� errcode - ��� ������


  // ���������� �������
  // HOBJ info - ������������� ������� �����
  // formula - ������, ���������� �������
  // value - �������� �������
  // ��� ������ � errcode (maperror.rh)
  // ���������� 0 ��� ������, � � ���������� errno - ��� ������

_MAPIMP long int _MAPAPI GetFormulaValue(HOBJ info, const char * formula,
                                double * value,  long * errcode);

  // �������� ���������� �������
  // HRSC rsc - ������������� �������������� �����
  // formula - ������, ���������� �������
  // ���������� 0 ��� ������, � � ���������� errno - ��� ������

_MAPIMP long int _MAPAPI CheckFormula(HRSC rsc, const char * formula, long * errcode);

  // �������� ���������� ������ � ��������� �� ��������� ���������
  // �� ����� ���������� ������ ������ ���������� source, � ������� ������� �����
  // ��� ������� ��������� ��������� �������
  // # - ���������, ��� ������ ���� ��� ���������, � ������� ����� ��������
  //     ������ ����
  //     ����� � ()�������� �� ���������.
  // (������: #9(��� ��������) - ����� �������� ��������� 9, ��� ����������
  // �������� ������� "��� ��������"
  // dest - ��������� �� ����� ��� ���������� ������
  //        ������ ������ - ������ ������ + 256*���������� �������
  // ���������� 0 ��� ������, � � ���������� errcode - ��� ������

_MAPIMP long int _MAPAPI AgregateString(HRSC hrsc, HOBJ info, const char * source,     // 15/05/09
                              char * dest,long int destlength,long int * errcode);
_MAPIMP long int _MAPAPI AgregateStringUn(HRSC hrsc, HOBJ info, const WCHAR * source,     // 18/12/12
                              WCHAR * dest,long int destlength,long int * errcode);
  // ��������� ���������� ������ � ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscFormuleCount(HRSC hrsc);

  // ��������� ��� ������� � �������������� �� ����������� ������ � 1
  // hRsc   - ������������� �������������� �����
  // number - ���������� ����� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscFormuleCodeByNumber(HRSC hrsc, long int number);

  // ��������� ��������� �������� �������                           // 07/03/13
  // �� ���� �������
  // hRsc - ������������� �������������� �����
  // code - ��� �������
  // ��������� RSCFORMULE ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscDescribeFormuleByCode(HRSC hrsc, RSCFORMULE * form,
                                                        long int code);

  // �������� ����� ������� �� ���� �������
  // �������� �� �������������� ������������ �� ��������
  // bufflength - ����� ������� � ������
  // buff - ����� �������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapReplaceRscFormulaText(HRSC hrsc, long int code,
                                       long int bufflength, WCHAR * buff);

  // ��������� ��������� ������� ��� ��������
  // ���������� ��� ������� ��� ����

_MAPIMP long int _MAPAPI mapSetRscFormulaToSemantic(HRSC hrsc,long int code,
                                                       long int semanticcode);

  // ��������� ����� ������� �� ���� �������
  // hRsc - ������������� �������������� �����
  // code - ��� �������
  // ��� ������ ���������� ����

_MAPIMP const wchar_t * _MAPAPI mapGetRscTextFormuleByCode(HRSC hrsc, long int code);

  // �������� ����� ������� - ���������� ��� �������
  // form - �������� �������
  // text - ����� �������
  // errcode - ��� ������ ��� �������� ������� (maperr.rh)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRscFormula(HRSC hrsc, RSCFORMULE * form, WCHAR * text,
                                          long * errcode);

  // ��������� ���������� ��������� ������ ��� ���������       14/11/14
  // hRsc - ������������� �������������� �����

_MAPIMP long int _MAPAPI mapCountRscFormulaLibraries(HRSC hrsc);

  // �������� ���������� � ������ ��� ���������� �������� ���������
  // hRsc - ������������� �������������� �����
  // name - ��� ����������
  // message - 0 �� �������� ���������
  // ���������� ����� ���������� � ������ (1,...)
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapOpenRscFormulaLibrary(HRSC hrsc, const WCHAR * name,
                                                  long int message);
  // ��������� �������� ������ ��� ��������� �� ������ ���������� � ������ (1,...)
  // hRsc - ������������� �������������� �����
  // number - ���������� � ������
  // ��� ������ ���������� ����

_MAPIMP SEMLIBLIST * _MAPAPI mapGetRscFormulaLibraryFunction(HRSC hrsc,
                                                             long int number);

  // ��������� �� ������ ���������� � ������ (1,...)
  // ��� ����������
  // ��� ������ ���������� ����

_MAPIMP WCHAR * _MAPAPI mapGetRscFormulaLibraryName(HRSC hrsc, int number);


} // extern "C"


#endif

