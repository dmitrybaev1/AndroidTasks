/****  ALSAPI.H  **************  Belenkov  O.V.  *****  09/06/14 ***
*****  ALSAPI.H  **************  Derevyagina Zh.A.****  29/11/10 ***
*****  ALSAPI.H  **************  Shabakov D.A.   *****  14/05/13 ***
*****  ALSAPI.H  **************  Tarakanova I.R. *****  08/04/14 ***
*****  ALSAPI.H  **************  Kruzhkova E.A.  *****  02/12/15 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2015              *
*                     All Rights Reserved                          *
*                                                                  *
********************************************************************
*                                                                  *
*                FOR  WINDOWS ME & WINDOWS XP, LINUX               *
*                                                                  *
********************************************************************
*                                                                  *
*               ������ ������� ����������� �����                   *
*                                                                  *
*******************************************************************/

#ifndef ALSAPI_H
#define ALSAPI_H

#ifndef MAPTYPE_H
 #include "maptype.h"
#endif

typedef struct ALSITEM     // �������� �������� ������ ������� �����
{
  long Ident;              // ������������� ��������
  char Path[260];          // ������ ���� � �������� ������
  char Name[32];           // ��� ������ (������� �� ��������)
  long Scale;              // ������� ������ (������� �� ��������)
  long Minimum;            // ������ ������� �������� � ������ (��������, 100 000)
  long Maximum;            // ������� ������� �������� � ������ (��������, 500 000)
  long Priority;           // ��������� ������ ��� ���������� ���������
}
  ALSITEM;

typedef struct ALSITEMEX   // �������� �������� ������ ������� �����
{                                                                     // 21/11/06
  long Ident;              // ������������� ��������
  long Scale;              // ������� ������ (������� �� ��������)
  long Minimum;            // ������ ������� �������� � ������ (��������, 100 000)
  long Maximum;            // ������� ������� �������� � ������ (��������, 500 000)
  long Priority;           // ��������� ������ ��� ���������� ���������
  long Reserve;            // ������ = 0
}
  ALSITEMEX;

typedef HMAP HALS;         // ������������� ������ ������� �����

// ������ ��������� ��������, ����������� ����� ����� (������� ������)
#define SEMALSPATH     7701  // ���� � �����
#define SEMALSNAME     7702  // ��� ������ �����
#define SEMALSSCALE    7703  // ������� ������ �����
#define SEMALSMIN      7704  // ������ ������� ��������
#define SEMALSMAX      7705  // ������� ������� ��������
#define SEMALSMODE     7706  // ����� ��������� ������
#define SEMALSPRIOR    7707  // ��������� ������
#define SEMALSGROUP    7708  // ��� ������ ������ ������     // 28/10/09
#define SEMALSNOTE     7709  // ����������                   // 27/11/09
#define SEMALSORDER    7710  // ������� ����������                   // 05/04/10
#define SEMALSPATHTILE 7711  // ���� � �������� �������������� ����� // 05/04/10
#define SEMALSCOUNT    7712  // ����� ��������� � ������ (SEMGROUPLEADER + SEMGROUPSLAVE) // 31/10/11
#define SEMALSSHEET    7713  // ���/������������ �����       // 31/10/11

#define ALS_UP          1  // ����� ����� ������� ��������
#define ALS_DOWN        2  // ����� ����� �������� ��������
#define ALS_ANY         0  // ����� ����� �����
#define ALS_BACK        4  // ��������� � �����

extern "C"
{

// ������� ������ ������� �����
// listname - ���� � ������ ������� ����� (����� "ALS")
// ��� ������ ���������� ����, ����� - ������������� ������ �������

_MAPIMP HALS _MAPAPI alsOpenAreaList(const char * listname);
_MAPIMP HALS _MAPAPI alsOpenAreaListUn(const WCHAR * listname);

// ������� ������ ������� �����
// listname - ���� � ������ ������� ����� (����� "ALS")
// listtype - ��� ������ ������� (0 - ���������� � ���������� �������������
//            ���������, 1 - ��������� � ������� ������� ���������
// rscname -  ��� �������������� ��� �������� ������ (������ - "arealist.rsc")
// ��� ������ ���������� ����, ����� - ������������� ������ �������

_MAPIMP HALS _MAPAPI alsCreateAreaList(const char * listname, long int listtype);
_MAPIMP HALS _MAPAPI alsCreateAreaListEx(const char * listname,
                                         const char * rscname, long int listtype);
_MAPIMP HALS _MAPAPI alsCreateAreaListUn(const WCHAR * listname,
                                         const WCHAR * rscname, long int listtype);

// ������� ������ ������� �����
// hals - ������������� ������ �������

_MAPIMP void _MAPAPI alsCloseAreaList(HALS hals);

// ��������� �������� �� ����� ����������
// hals - ������������� ������ ������� (������)
// ���� ��� - ���������� ����

_MAPIMP long int _MAPAPI alsIsGlobalAreaList(HALS hals);

// ��������� ����� ��������� � ������
// hals - ������������� ������ �������

_MAPIMP long int _MAPAPI alsGetItemCount(HALS hals);

// ��������� �������� �������� ������ �������
// hals   - ������������� ������ �������
// number - ���������� ����� ��������, ������� � 1
// item   - ����������� ��������� �������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetItem(HALS hals, long int number, ALSITEM * item);

// ��������� �������� �������� ������ �������
// hals   - ������������� ������ �������
// number - ���������� ����� ��������, ������� � 1
// item   - ����������� ��������� �������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetItemEx(HALS hals, long int number, ALSITEMEX * item);

// ��������� �������� �������� ������ ������� � ������� � Unicode
// hals   - ������������� ������ �������
// number - ���������� ����� ��������, ������� � 1
// itemex - ����������� ��������� �������� ��������
// path   - ����������� ���� � �������� �������� � Unicode
// sizepath - ������ ������ ��� ���� (� ������)
// name   - ����������� ��� ������ �������� � Unicode
// sizename - ������ ������ ��� ��� ������ �������� (� ������)
_MAPIMP long int _MAPAPI alsGetItemExUn(HALS hals, long int number, ALSITEMEX * itemex,
                                        WCHAR * path, long int sizepath,
                                        WCHAR * name, long int sizename);       // 02/12/15

// ��������� ��� �������� ������ �������
// hals   - ������������� ������ �������
// number - ���������� ����� ��������, ������� � 1
// name   - ����� ������ ��� ������ ����������
// size   - ����� ������� ������ � ������ (�� ����� MAX_PATH ����)
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetItemName(HALS hals, long int number, char * name, long int size);
_MAPIMP long int _MAPAPI alsGetItemNameUn(HALS hals, long int number, WCHAR * name,
                                          long int size);                       // 02/12/15

// ��������� ���� � �������� ��� �������� �� ������ �������
// hals   - ������������� ������ �������
// number - ���������� ����� ��������, ������� � 1
// path   - ����� ������ ��� ������ ����������
// size   - ����� ������� ������ � ������ (�� ����� MAX_PATH)
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetItemPath(HALS hals, long int number, char * path,
                                        long int size);                         // 02/12/15

// ��������� ���� � �������� ��� �������� �� ������ �������
// hals   - ������������� ������ �������
// number - ���������� ����� ��������, ������� � 1
// path   - ����� ������ ��� ������ ����������
// size   - ����� ������� ������ � ������ (�� ����� MAX_PATH_LONG)
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetItemPathUn(HALS hals, long int number, WCHAR * path,
                                          long int size);                       // 02/12/15

// ��������� ���� � �������� ������ ��� WebServer �� �������������� ��������
// hals   - ������������� ������ �������
// ident  - ������������� ��������
// pathtile   - ����� ������ ��� ������ ����������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetPathTileByIdent(HALS hals, long int ident, char * pathtile);
_MAPIMP long int _MAPAPI alsGetPathTileByIdentUn(HALS hals, long int ident,
                                                 WCHAR * pathtile, long int size); // 02/12/15

// ��������� ���� � �������� ������ ��� WebServer �� ������
// hals   - ������������� ������ �������
// number - ���������� ����� ��������, ������� � 1
// pathtile   - ����� ������ ��� ������ ����������(������ ������ ������ ����
//              �� ����� MAX_PATH_LONG)
// ��� ������ ���������� ����
_MAPIMP long int _MAPAPI alsGetPathTileUn(HALS hals, long int number,
                                          WCHAR * pathtile, long int size);     // 02/12/15

// ��������� ���� � �������� ������ ��� WebServer �� ������
// hals   - ������������� ������ �������
// number - ���������� ����� ��������, ������� � 1
// pathtile   - ����� ������ ��� ������ ����������(������ ������ ������ ����
//              �� ����� MAX_PATH)
// ��� ������ ���������� ����
_MAPIMP long int _MAPAPI alsGetPathTile(HALS hals, long int number,
                                        char * pathtile);                       // 02/12/15

// ���������� ���� � �������� ������ ��� WebServer
// hals     - ������������� ������ �������
// ident    - ������������� ��������, ��. ALSITEM
// pathtile     - �������������� ���������� (����������)
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsSetItemPathTile(HALS hals, long int ident, char * pathtile);
_MAPIMP long int _MAPAPI alsSetItemPathTileUn(HALS hals, long int ident,
                                              WCHAR * pathtile, long int size);  // 02/12/15

// ��������� �������� �������� ������ �������
// hals   - ������������� ������ �������
// ident  - ������������� ��������
// item   - ����������� ��������� �������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetItemByIdent(HALS hals, long int ident, ALSITEM * item);

// ��������� �������� �������� ������ ������� � ������� � Unicode
// hals   - ������������� ������ �������
// ident  - ������������� ��������
// itemex - ����������� ��������� �������� ��������
// path   - ����������� ���� � �������� �������� � Unicode
// sizepath - ������ ������ ��� ���� (� ������)
// name   - ����������� ��� ������ �������� � Unicode
// sizename - ������ ������ ��� ��� ������ �������� (� ������)
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetItemByIdentExUn(HALS hals, long int ident,
                                               ALSITEMEX * itemex,
                                               WCHAR * path, long int sizepath,
                                               WCHAR * name, long int sizename); // 02/12/15

// ��������� ��� ������ ������ ������ �������
// hals   - ������������� ������ �������
// ident  - ������������� ��������
// name   - ����� ������ ��� ������ ���������� (������ ������ ������ ����
//          �� ����� MAX_PATH)                                                  
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetNameGroupByIdent(HALS hals, long int ident, char * name);
_MAPIMP long int _MAPAPI alsGetNameGroupByIdentUn(HALS hals, long int ident,
                                                  WCHAR * name, long int size); // 02/12/15

// ���������� ��� ������ ������ ������
// hals     - ������������� ������ �������
// ident    - ������������� ��������, ��. ALSITEM
// name     - ��� ������ ������ ������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsSetItemGroupName(HALS hals, long int ident, char * name);
_MAPIMP long int _MAPAPI alsSetItemGroupNameUn(HALS hals, long int ident,
                                               WCHAR * name, long int size);    // 02/12/15

// ��������� �������������� ���������� (����������) ��� �������� ������ �������
// hals   - ������������� ������ �������
// ident  - ������������� ��������
// note   - ����� ������ ��� ������ ���������� (������ ������ ������ ����
//          �� ����� MAX_PATH)
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetNoteByIdent(HALS hals, long int ident, char * note);
_MAPIMP long int _MAPAPI alsGetNoteByIdentUn(HALS hals, long int ident,
                                             WCHAR * note, long int size);      // 02/12/15

// ���������� �������������� ���������� (����������) ��� �������� ������ �������
// hals     - ������������� ������ �������
// ident    - ������������� ��������, ��. ALSITEM
// note     - �������������� ���������� (����������)
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsSetItemNote(HALS hals, long int ident, char * note);
_MAPIMP long int _MAPAPI alsSetItemNoteUn(HALS hals, long int ident,
                                          WCHAR * note, long int size);         // 02/12/15

// ��������� ������� ����������� � ������ ��� �������� ������ �������
// hals   - ������������� ������ �������
// ident  - ������������� ��������
// order   - ����� ������ ��� ������ ����������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetOrderByIdent(HALS hals, long int ident, long int * order);

// ���������� ������� ����������� � ������ ��� �������� ������ �������
// hals     - ������������� ������ �������
// ident    - ������������� ��������, ��. ALSITEM
// order    - ������� ����������� � ������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsSetItemOrder(HALS hals, long int ident, long int order);

// ��������� �������� �������� ������ �������
// hals   - ������������� ������ �������
// ident  - ������������� ��������
// item   - ����������� ��������� �������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetItemByIdentEx(HALS hals, long int ident, ALSITEMEX * item);

// �������� ������� � ������ �������
// hals - ������������� ������ �������
// path - ������ ���� � �������� ������ �����
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsAppendItem(HALS hals, const char * path);
_MAPIMP long int _MAPAPI alsAppendItemUn(HALS hals, const WCHAR * path);  // 02/12/15

// ���������� ������� ��������� ��� ��������������� �������� � �����
// hals    - ������������� ������ �������
// ident   - ������������� ��������, ��. ALSITEM
// minimum - ������ ������� �������� � ������ (��������, 100 000)
// maximum - ������� ������� �������� � ������ (��������, 500 000)
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsSetItemMiniMax(HALS hals, long int ident,
                                           long int minimum,
                                           long int maximum);

// ���������� ��������� ������ �����
// hals     - ������������� ������ �������
// ident    - ������������� ��������, ��. ALSITEM
// priority - ��������� ������ ������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsSetItemPriority(HALS hals, long int ident,
                                            long int priority);

// ���������� ������� ��������� ��� ��������������� �������� � �����
// hals   - ������������� ������ �������
// ident   - ������������� ��������, ��. ALSITEM
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsDeleteItem(HALS hals, long int ident);


// ����� ������� ������������� � �������� ����� ���� ����������
// �������� (� ����� ������� ��������)
// hals   - ������������� ������ �������
// ident   - ������������� ��������, ��. ALSITEM
// point  - ������������� ���������� �������� ����� � ��������
// item   - ����������� ��������� �������� ���������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGoItemDown(HALS hals, long int ident,
                                       DOUBLEPOINT * point, ALSITEM * item);

// ����� ������� ������������� � �������� ����� ���� ���������
// �������� (� ����� ������� ��������)
// hals   - ������������� ������ �������
// scale  - ������� �������� ��������
// point  - ������������� ���������� �������� ����� � ��������
// item   - ����������� ��������� �������� ���������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGoItemDownByScale(HALS hals, long int scale,
                                              DOUBLEPOINT * point, ALSITEM * item);

// ����� ������� ������������� � �������� ����� ���� ���������
// �������� (� ����� ������� ��������)
// hals   - ������������� ������ �������
// scale  - ������� �������� ��������
// frame  - ���������� �������� ������� �� ������
// item   - ����������� ��������� �������� ���������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGoItemDownByScaleEx(HALS hals, long int scale,
                                                HOBJ frame, ALSITEM * target);

// ����� ������� ������������� � �������� ����� ���� ����������
// �������� (� ����� ������ ��������)
// hals   - ������������� ������ �������
// ident   - ������������� ��������, ��. ALSITEM
// point  - ������������� ���������� �������� ����� � ��������
// item   - ����������� ��������� �������� ���������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGoItemUp(HALS hals, long int ident,
                                     DOUBLEPOINT * point, ALSITEM * item);

// ����� ������� ������������� � �������� ����� ���� ����������
// �������� (� ����� ������ ��������)
// hals   - ������������� ������ �������
// scale  - ������� �������� ��������
// point  - ������������� ���������� �������� ����� � ��������
// item   - ����������� ��������� �������� ���������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGoItemUpByScale(HALS hals, long int scale,
                                            DOUBLEPOINT * point, ALSITEM * item);

// ����� ������� ������������� � �������� ����� ���� ���������
// �������� (� ����� ������ ��������)
// hals   - ������������� ������ �������
// scale  - ������� �������� ��������
// frame  - ������������� ���������� �������� ������� �� ������
// item   - ����������� ��������� �������� ���������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGoItemUpByScaleEx(HALS hals, long int scale,
                                              HOBJ frame, ALSITEM * target);

// ���������� ������� ����������� � ������ ���������� �����������
// ������ � �������� �������� �������
// width  - ������ ������� � ��������,
// height - ������ ������� � ��������

_MAPIMP void _MAPAPI alsSetPictureSize(HALS hals, long int width,
                                       long int height);

// �������� �� ����� ��������� ������� ������
// hdc   - �������� ���� ����������� ������
// rect  - ���������� ���� � ������� ������� ����������� ������
// ident - ������������� ��������, ��. ALSITEM
// color - ���� ��������� �������� �� ������
// thick - ������� ����� ��������� � ��������

_MAPIMP void _MAPAPI alsPaintSelectItem(HALS hals, HDC hdc,
                                        RECT * rect, long int ident,
                                        COLORREF color, int thick);

// ��������� ��������� ������ � ����������� ������
// ident - ������������� �������� (������), ��. ALSITEM
// point - ����������� ���������� � �������� ��� �������� �������� �����������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetItemPosition(HALS hals, long int ident, POINT * point);

// ������� � ����� ��� ������ � ��������� ������ �� ������ item
// hals   - ������������� ������ �������
// item   - ����� ������� ������ ��� ���������� ������ ��������� ���������
// count  - ����� ���������, ��� ������� ��������������� ������
// point  - ������������� ���������� �������� ����� � ��������
// ��� ������ ���������� ���� ����� - ����� ��������� ���������

_MAPIMP long int _MAPAPI alsItemListEx(HALS hals, ALSITEM * item, long int count, DOUBLEPOINT * point);


// ��������� - ���� �� � ����� �����
// direct    - ����������� ������ (ALS_UP, ALS_DOWN, ALS_ANY)
// point     - ������������� ���������� �������� ����� � ��������
// ���� ����� ���� - ���������� ��������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsEnableItem(HALS hals, long int scale,
                                       DOUBLEPOINT * point, long int direct);

// ��������� - ���� �� � �������� ������� �����
// direct    - ����������� ������ (ALS_UP, ALS_DOWN, ALS_ANY)
// frame     - ���������� �������� ������� �� ������
// ���� ����� ���� - ���������� ��������� ��������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsEnableItemEx(HALS hals, long int scale,
                                         HOBJ frame, long int direct);

// ���������� ������� ��������
// hals - ������������� ������ �������
// path - ������ ���� � �������� ������ �����
// frame  - ���������� �������� ������� � ������ �� �����
// ���� frame == 0, �� ��������������� �������� ������
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsBorderChange(HALS hals, const char * path, HOBJ frame);
_MAPIMP long int _MAPAPI alsBorderChangeUn(HALS hals, const WCHAR * path, HOBJ frame);  // 02/12/15

// ���������� ��������� ����� � �����
// hals - ������������� ������ �������
// path - ������ ���� � �������� ������ �����
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsMapOccurrence(HALS hals, const char * path);
_MAPIMP long int _MAPAPI alsMapOccurrenceUn(HALS hals, const WCHAR * path);     // 02/12/15

// ��������� ������� ��������
// hals - ������������� ������ �������
// path - ������ ���� � �������� ������ �����
// frame  - ���������� �������� ������� � ������ �� �����
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsGetMapBorder(HALS hals, const char * path, HOBJ frame);
_MAPIMP long int _MAPAPI alsGetMapBorderUn(HALS hals, const WCHAR * path, HOBJ frame);   // 02/12/15

// ����� � ������ �����, ���������� ���� � ��������� ������������� (��������
// ���������)
// hals  - ������������� ������ ������� (������)
// sheet - ������������ �����
// name  - ����� ������ ��� ���������� ���������� (���� � �����)
// size  - ������ ������, � ������� ����� ������� ���� � ����� (����� �� �����
//         MAX_PATH_LONG)
// ��� �������� ���������� � ����� ������������ ���� � �������� �����
// ��� ��� ������ ����� �� ��� �������
// ��� ��������� ���������� ������� ����������� ��������� ���� ��
// ������� ���� � �����������. �� ����� ��� ����� ������ � ���������� "shl"
// ��� ������ ���������� ����

_MAPIMP long int _MAPAPI alsFindMapBySheetName(HALS hals, const char * sheet,
                                               char * name, int size);
_MAPIMP long int _MAPAPI alsFindMapBySheetNameUn(HALS hals, const WCHAR * sheet,
                                                 WCHAR * name, int size);         // 02/12/15

}  // extern "C"


#endif  //  AREALIST_H

