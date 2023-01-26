/****  GMLAPI.H  *********** ��������� �.�. ******* 20/09/2011 *****
*****  GMLAPI.H  *********** Belenkov  O.V. ******* 15/02/2016 *****
*****  GMLAPI.H  *********** Konon     V.N. ******* 28/09/2015 *****
*****  GMLAPI.H  *********** Shabakov D.A.  ******* 20/11/2014 *****
*****  GMLAPI.H  *********** Zheleznyakov V.A. **** 16/06/2016 *****
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2016              *
*                     All Rights Reserved                          *
*                                                                  *
********************************************************************
*                                                                  *
*                     FOR  LINUX & MS WINDOWS                      *
*                                                                  *
********************************************************************
*                                                                  *
*       ��������� ��������� �������� OGC WFS-T (gisu64acces.dll)   *
*                                                                  *
*******************************************************************/

#ifndef GMLAPI_H
#define GMLAPI_H

#ifndef MAPTYPE_H
 #include "maptype.h"
#endif

enum OGCSERVICETYPE       // ��� �������� ��� ������ ����� ������
{
  OST_GML  = 0,           // ����� ������ GML
  OST_WFS  = 1,           // GML ��� �������� �� WFS
  OST_JSON = 2,           // JSON  
};

enum OGCSERVICEFLAG       // ����� ����������� ���������� �� ������� 
{
  OSF_METRIC      =   1,  // ����� �������  � �������� �������
  OSF_SEMANTIC    =   2,  // ����� ��������� � �������� �������
  OSF_MEASURE     =   4,  // ����� ������� � ����� (���������) �������
  OSF_MEASURE3D   =   8,  // ����� ������� � ����� (���������) ������� � ������ ������� ���������
  OSF_CENTER      =  16,  // ����� ������ �������
  OSF_SCALEBORDER =  32,  // ����� ������� � ������ ������� ��������� ������� (�������� �����������)
  OSF_POINT       =  64,  // ����� ������ ����� �������
  OSF_SEMANTICNAME=  128, // ����� ����� ��������� ��� ���������� ����� ���������
  OSF_CUTMETRIC   =  256, // ���������� ������� �������� �� ������� ������ �������� �����
  OSF_BBOX        =  512, // ����� ��������� �������
  OSF_KEY         = 1024  // ����� ����� �������
};
 
// ������������� GML ������
typedef HANDLE HGML;

// ������������� ��� �������� GML ������
typedef HANDLE HGMLCLASS;

extern "C"
{
 // ������� ������ � ����� ��� ���������� ������������ GML\JSON
 // ���� ������������� �������� �� ��� �������, �� ����� ����������� �����
 // ������������� ����� (gmlOpen, gmlOpenEx, gmlOpenUn)
 // schemafilename - ��������� ���� � ����� XSD-�����  
 // rscname        - ��������� ���� � ����� �������������� RSC,
 //                  � ������� ������� �����, ����������� � ���������
 // hrsc - ������������� �������������� (����� ���� ������� � mapGetRscIdent, mapGetRscIdentByObject)
 // ���������� ������������� ������� � GML ������
 // ��� ������ ���������� ����

_MAPIMP HGML _MAPAPI gmlOpenPro(const WCHAR* schemafilename, const WCHAR * rscname);
_MAPIMP HGML _MAPAPI gmlOpenProEx(const WCHAR* schemafilename, HRSC hrsc);

 // ������� ������ � ���������� ����� ��� �������� �����
 // hMap - ������������� ������ ������
 // schemafilename - ��������� ���� � ����� XSD-����� GML ������
 // schemaURL      - URL � ����� XSD-����� GML ������
 //                  ��������: "http://www.gisinfo.net/bsd/topomap.xsd"
 // ���������� ������������� ������� � ���������� �����
 // ��� ������ ������ (dataset) �������� gmlGetFeaturiesDataset
 // ������ � ����� ����������� gmlOpenEx
 // �� ���������� ������ ���������� ���������� ������� ������� gmlClose
 // ��� ������ ���������� ����

_MAPIMP HGML _MAPAPI gmlOpen(HMAP hMap, const char *schemafilename);
_MAPIMP HGML _MAPAPI gmlOpenEx(HMAP hMap, HSITE hSite,
                               const char * schemafilename,
                               const char * schemaURL);
_MAPIMP HGML _MAPAPI gmlOpenUn(HMAP hMap, HSITE hSite, 
                               const WCHAR * schemafilename,
                               const WCHAR * schemaURL);

 // ������� ������ � ����� � ���������� �������
 // hGml - ������������� GML ������

_MAPIMP void _MAPAPI gmlClose(HGML hGml);

 // ��������� ����� ����� �������� GML ������ ("�����")
 // ���������� ����� ����� �������� GML, ������������ � �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI gmlFeatureTypeCount(HGML hGml);

 // ��������� ��� ���� ������� GML ������ �� ����������� ������
 // ���������� ��� ���� �������
 // ��� ������ ���������� ������ ������

_MAPIMP const char * _MAPAPI gmlFeatureTypeName(HGML hGml, long int number);

 // ��������� ���������� ����� ���� ������� �� ����� ����
 // hGml - ������������� �������� ����� ��� ������ GML
 // featuretypename - ��� ���� ������� GML ������
 // ���������� ���������� ����� ���� ������� � �����
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI gmlFeatureTypeNameNumber(HGML hGml, const char *featuretypename);

 // ��������� �������� �������� ����� �� ������ ������� ����� ��������
 // hGml  - ������������� GML ������
 // hMap  - ������������� ������ ������
 // hSite - ������������� ����� (��� �������� ����� ����� ���� ����� hMap)
 // list  - ����� ��������������� ����� �� ������������� ����� ��� 0 (��� �����)
 // hSelect - ������������� ������� ������ �������� ��� 0
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG, ��� GML �� ��������� - 4326
 // dframe - �������� �������� ����� � ��������� ������� ���������
 // ��� ������ ���������� ����.

_MAPIMP long int _MAPAPI gmlFeaturiesBoundsPro(HGML hGml, HMAP hMap, HSITE hSite, long int list,
                                               HSELECT hSelect, long int epsgcode, DFRAME *dframe);

 // ��������� ������ �������� ����� �� �������� �������� � ����� ������� GML ��� JSON
 // hGml - ������������� �������� ����� ��� ������ GML
 // hMap  - ������������� ������ ������
 // hSite - ������������� �����
 // list  - ����� ����� ��� ������������� ����� ��� 1, ��� ���������������
 //         � ���� GML-���� ����� ���� ������ ���������� ������� "-1" ��� 0
 // hSelect - ������������� ������� ������ �������� ��� 0
 // number - ���������� ����� �������, � �������� �������� ����� � ���� (� 1)
 // count - ����� ��������, ��������� � ����, ���� ����� 0, �� ��������� ��� �������  
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG, 
 // ��� GML �� ��������� - 4326
 // dframe - ������ ������ �������� ����� � ��������� ������� ��������� ��� 0 (����� ������ � ������ ������� ���� �������)
 // format - ��� �������� ��� ������ �����: GML, GML/WFS, JSON  (��. OGCSERVICETYPE)
 // targetfilename - ��� ��������� �����
 // flags - ������ ������ ����������� ���������� �� ������� (��. OGCSERVICEFLAG)
 // format - ������ ������ ������: GML, JSON (��. OGCSERVICETYPE) 
 // mapid  - ��������� �� ������������� �����, ������� ������������ � ������ ������ ����� ��� 0
 // completed - ������� ������������� ������ ��������� ������ � ����� �����
 //             (0 - �� �����������, 1 - ������ �����������, 2 - ������ ��������� ����, -1 - ������ � ����� ������)
 // JSON - { "type": "FeatureCollection",    ... }
 // GML  - <gml:FeatureCollection> ... </gml:FeatureCollection>
 // WFS  - <wfs:FeatureCollection> ... </wfs:FeatureCollection>
 // force - ������� �������������� ������ ��������, ������� �� ������� � ���������� �����,
 //         ���� ����� ����, �� ������������ ������ �������, ���� (����) ������� ������� � �����
 // hwnd - ������������� ���� ��� ������ ��������� ��� ����, ���������� ��������� WM_PROGRESSBAR
 // requestId - ������������� �������
 // xmlns - ������� ������ ������������ ���� � ��� member ��� gml/wfs
 // secondframe - �������������� ����� ��� ������� ������ �������� ����� � ��������� ������� ��������� 
 // (�������� ������������� � dframe, ����� ������� � ������ ������ ���� �������)
 // ���������� ����� ���������� ��������
 // ���� ������ ����, ���������� �������, ������� ��� �� �����, �� ���������� -1
 // ���� �������� ������ �� ������������� �� ���� ������, �� ���������� -2
 // ���� �������� ���� �� ����� ���� ������, �� ���������� -3
 // ���� ��������� ���� ��� ������ ���������, �� ���������� -4
 // ���� ��� ����� ��������� �����������, �� ���������� -5

_MAPIMP long int _MAPAPI gmlGetFeaturiesPro(HGML hGml, HMAP hMap, HSITE hSite, long int list,
                                            HSELECT hSelect, const WCHAR * metadata,
                                            long int number, long int count,
                                            long int epsgcode, DFRAME* dframe, long int flags,
                                            long int format, const WCHAR *targetfilename,
                                            const WCHAR * mapid, long int completed,
                                            long int force, HWND hwnd, const WCHAR* requestId = 0,
                                            long int xmlns = 0);

_MAPIMP long int _MAPAPI gmlGetFeaturiesProEx(HGML hGml, HMAP hMap, HSITE hSite, long int list,
                                            HSELECT hSelect, const WCHAR * metadata,
                                            long int number, long int count,
                                            long int epsgcode, DFRAME* dframe, long int flags,
                                            long int format, const WCHAR *targetfilename,
                                            const WCHAR * mapid, long int completed,
                                            long int force, HWND hwnd, const WCHAR* requestId = 0,
                                            long int xmlns = 0, DFRAME* secondframe = 0);

 // ��������� ������ �������� ����� �� �������� �������� � ������ � ������� GML ��� JSON
 // ��� ������ �� ������ ���������� ���������� ������� gmlGetFeaturiesPoint
 // ����� ���������� ������ ���������� ���������� ������ ������� gmlFreeFeaturiesPoint
 // ���� ����� ������ ������� �������, �� ������� ����� ������ ��� ������ � �������
 // ���������� ���������� ���������� ������� gmlGetFeaturiesPro
 // xmlns - ������� ������ ������������ ���� � ��� member ��� gml/wfs
 // ���������� � ��������� retcode ����� ���������� �������� ��� ��� ������
 // ���� ������ ����, ���������� �������, ������� ��� �� �����, �� ���������� -1
 // ���� �������� ������ �� ������������� �� ���� ������, �� ���������� -2
 // ���� ��������� ���� ��� ������ ���������, �� ���������� -4
 // ���� ��� ����� ��������� �����������, �� ���������� -5
 // ��� ������ ���������� ���� ����� ������������� ������ � ������
 
 _MAPIMP HANDLE _MAPAPI gmlGetFeaturiesProInMemory(HGML hGml, HMAP hMap, HSITE hSite, long int list,
                                                  HSELECT hSelect, const WCHAR * metadata,
                                                  long int number, long int count,
                                                  long int epsgcode, DFRAME* dframe, long int flags,
                                                  long int format, const WCHAR * mapid, long int completed, 
                                                  long int force, long int * retcode, const WCHAR* requestId = 0, long int xmlns = 0);

 // ��������� ��������� �� ������ � ������ �� �������������� ������, 
 // ����������� �� ������� gmlGetFeaturiesProInMemory ��� gmlGetObjectFeatureProInMemory
 // ����� ���������� ������ ���������� ���������� ������ ������� gmlFreeFeaturiesPoint
 // ��� ������ ���������� ���� ����� ��������� �� ������ � ������
 
_MAPIMP const char * _MAPAPI gmlGetFeaturiesPoint(HANDLE handle, long int * size);

 // ���������� ������ ��� ������ �� �������������� ������, 
 // ����������� �� ������� gmlGetFeaturiesProInMemory ��� gmlGetObjectFeatureProInMemory

_MAPIMP void _MAPAPI gmlFreeFeaturiesPoint(HANDLE handle);

 // ��������� ������ ������� ����� � ����� ������� GML ��� JSON
 // hGml - ������������� �������� ����� ��� ������ GML
 // hObj - ������������� ������� ����� � ������
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG
 // flags - ������ ������ ����������� ���������� �� ������� (��. OGCSERVICEFLAG)
 // format - ������ ������ ������: GML, JSON (��. OGCSERVICETYPE) 
 // targetfilename - ��� ��������� GML ��� JSON �����
 // mapid  - ��������� �� ������������� �����, ������� ������������ � ������ ������ ����� ��� 0
 // requestId - ������������� �������
 // xmlns - ������� ������ ������������ ���� � ��� member ��� gml/wfs
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI gmlGetObjectFeaturePro(HGML hGml, HOBJ hObj,
                                                long int epsgcode, 
                                                long int flags, long int format,
                                                const WCHAR* targetfilename,
                                                const WCHAR * mapid,
                                                long int completed, const WCHAR* requestId = 0, long int xmlns = 0);

 // ��������� ������ ������� ����� � ������ � ������� GML ��� JSON
 // ��� ������ �� ������ ���������� ���������� ������� gmlGetFeaturiesPoint
 // ����� ���������� ������ ���������� ���������� ������ ������� gmlFreeFeaturiesPoint
 // ��� �������� � ������ ����� �������� �������� handle ������ ���������
 // ��������, ������� ������� ������� ��� ������ ������, ����� �������� handle ��� ����� 0
 // ���������� � ��������� retcode ����� ���������� �������� ��� ��� ������
 // ���� ������ ����, ���������� �������, ������� ��� �� �����, �� ���������� -1
 // ���� �������� ������ �� ������������� �� ���� ������, �� ���������� -2
 // ���� ��������� ���� ��� ������ ���������, �� ���������� -4
 // ���� ��� ����� ��������� �����������, �� ���������� -5
 // ��� ������ ���������� ���� ����� ������������� ������ � ������
                                                
_MAPIMP HANDLE _MAPAPI gmlGetObjectFeatureProInMemory(HGML hGml, HOBJ hObj,
                                                      long int epsgcode, 
                                                      long int flags, long int format,
                                                      HANDLE handle,
                                                      const WCHAR * mapid,
                                                      long int completed, long int * retcode,
                                                      const WCHAR* requestId = 0, long int xmlns = 0);
                                        
 // ��������� ������ ������� ����� �� GML-��������������
 // hGml - ������������� �������� ����� ��� ������ GML
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG
 // id - GML-������������� �������
 // flags - ������ ������ ����������� ���������� �� ������� (��. OGCSERVICEFLAG)
 // format - ������ ������ ������: GML, JSON (��. OGCSERVICETYPE) 
 // targetfilename - ��� ��������� �����
 // mapid  - ��������� �� ������������� �����, ������� ������������ � ������ ������ ����� ��� 0
 // completed - ������� ������������� ������ ��������� ������ � ����� �����
 //             (0 - �� �����������, 1 - ������ �����������, 2 - ������ ��������� ����, -1 - ������ � ����� ������)
 // JSON - { "type": "FeatureCollection",    ... }
 // GML  - <gml:FeatureCollection> ... </gml:FeatureCollection>
 // WFS  - <wfs:FeatureCollection> ... </wfs:FeatureCollection>
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI gmlGetFeatureByIdPro(HGML hGml, HMAP hMap, HSITE hSite, long int list,
                                              long int epsgcode, const char *id,
                                              long int flags, long int format,
                                              const WCHAR* targetfilename,
                                              const WCHAR * mapid,
                                              long int completed, const WCHAR* requestId = 0);

 // ������������� ���������� ����� �� ����� ������������� ������� ���������
 // � ������ ������������� ������� ���������
 // epsgcodesource - ��� �������� ������������� ������� ��������� � ���� ������ EPSG,
 // epsgcodedest - ��� �������� ������������� ������� ��������� � ���� ������ EPSG,
 // ���� ����� ���� � ��������� 4326 - 4937
 // dframe - ���������� ����� � �������� ������� ��������� � ��������
 // ���������� �� ������ dframe �������� ��������� � �� epsgcodedest
 // ��� ������ ���������� ����.

_MAPIMP long int _MAPAPI gmlGeoToGeo(long int epsgcodesource, long int epsgcodedest,
                                     DFRAME* dframe);

 // ���������� ����� �������� �� �������������� ����
 // hGml - ������������� �������� ����� ��� ������ GML
 // hSelect - ������������� ������� ������ ��������
 // featuretype - ������������� ���� � ��������� UTF-8
 // ��� ������ ���������� ����
  
_MAPIMP long int _MAPAPI gmlSetSelectByFeaturieType(HGML hGml, HSELECT hSelect, const char * featuretype);
                                     
 /*********************************************************
 *                                                        *
 *           �������� ������ �� geoJSON                   *
 *                                                        *
 *********************************************************/

 // C������� �������� �� ����� ������� geoJSON
 // hmap  - ������������� �������� �����
 // hsite - ������������� �������� ���������������� �����
 // jsonname - ��� ����� ������� GeoJSON
 // ��� ������������ ������� ������ � ���� code ("code": 115001010,)
 // ���� ��� �� ����� � �������, �� �� ���������� �� ������� ����������
 // squareCode - ��� ����������� ��������� �������� ��� 0
 // pointCode  - ��� ����������� �������� �������� ��� 0
 // lineCode   - ��� ����������� �������� �������� ��� 0
 // textCode   - ��� ����������� �������� ��� 0
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI gmlCreateObjectsFromJSON(HMAP hMap, HSITE hSite,
                                                  const WCHAR* jsonname,
                                                  long int squareCode = 0, long int pointCode = 0,  
                                                  long int lineCode = 0, long int textCode = 0);

 // C������� �������� �� ����� ������� geoJSON
 // hmap  - ������������� �������� �����
 // hsite - ������������� �������� ���������������� �����
 // jsonname - ��� ����� ������� GeoJSON
 // ��� ������������ ������� ������ � ���� code ("code": 115001010,)
 // ���� ��� �� ����� � �������, �� �� ���������� �� ������� ����������
 // squareCode - ��� ����������� ��������� �������� ��� 0
 // pointCode  - ��� ����������� �������� �������� ��� 0
 // lineCode   - ��� ����������� �������� �������� ��� 0
 // textCode   - ��� ����������� �������� ��� 0
 // hwnd - ������������� ���� ��� ������ ��������� ��� ����, ���������� ��������� WM_PROGRESSBAR                                                  
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI gmlCreateObjectsFromJSONEx(HMAP hMap, HSITE hSite,
                                                    const WCHAR* jsonname,
                                                    long int squareCode = 0, long int pointCode = 0,  
                                                    long int lineCode = 0, long int textCode = 0, HWND hwnd = 0);
                                                  
 // �������� ����������� ����
 // hGml - ������������� �������� ����� ��� ������ GML
 // format - ������ ������ ������: GML, JSON (��. OGCSERVICETYPE)
 // targetfilename - ��� ��������� �����
 // matched  - ���������� ��������� ��������
 // returned - ���������� ��������, ���������� � GML
 // data - ������ ������� ���������� �������� � ����� �����
 // datasize - ������ ������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI gmlSaveFileEnd(long int format, const WCHAR* targetfilename, long int matched, long int returned);

_MAPIMP long int _MAPAPI gmlSaveFileEndInMemory(HANDLE handle, long int matched, long int returned);

_MAPIMP long int _MAPAPI gmlSaveFileEndEx(long int format, const WCHAR* targetfilename,
                                        long int matched, long int returned,
                                        const char* data, long int datasize);
 
 // ������ ��������� �������� ����� geojson
 // name   - ��� ����� geojson
 // border - �������� �������� � �������� � �� WGS-84
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI gmlGetJSONBorder(const WCHAR* name, DFRAME * border);

 /*********************************************************
 *                                                        *
 *           �������� ������ �� GML/XML, OGC WFS,         *
 *                 OGC WFS-T (Transaction)                *
 *                                                        *
 *********************************************************/

 // C������� �������� �� ������ ���������� �� ��������� OGC WFS-T
 // hMap, hSite - ������������� �����
 // stream - ��������� �� ������, � ������� ��������� xml ���� ���������� OGC WFS-T
 // streamlength - ����� ������
 // squareCode - ��� ����������� ��������
 // pointCode  - ��� ����������� �������� ��������
 // lineCode - ��� ����������� �����
 // textCode - ��� ����������� ��������
 // ���������� ������������� ������ HGMLCLASS, �������
 // ������ ���� ���������� �������� mapFreeGmlClassHandle
 // ��� ������ ���������� 0

_MAPIMP HGMLCLASS _MAPAPI gmlLoadGmlTransactionToMap(HMAP hMap, HSITE hSite,
              const char* stream, long int streamlength,
              long int squareCode = 0, long int pointCode = 0, long int lineCode = 0, long int textCode = 0);

 // C������� �������� �� ������ gml/xml �����
 // hMap, hSite - ������������� �����
 // stream - ��������� �� ������, � ������� ��������� gml/xml ���� ��� ���� gml OGC WFS
 // streamlength - ����� ������
 // squareCode - ��� ����������� ��������
 // pointCode  - ��� ����������� �������� ��������
 // lineCode - ��� ����������� �����
 // textCode - ��� ����������� ��������
 // ���������� ������������� ������ HGMLCLASS, �������
 // ������ ���� ���������� �������� mapFreeGmlClassHandle
 // ��� ������ ���������� 0

_MAPIMP HGMLCLASS _MAPAPI gmlCreateObjectsFromXmlStream(HMAP hMap, HSITE hSite,
               const char* stream, long int streamlength,
               long int squareCode = 0, long int pointCode = 0,  long int lineCode = 0, long int textCode = 0);
_MAPIMP HGMLCLASS _MAPAPI gmlCreateObjectsFromXmlStreamPro(HMAP hMap, HSITE hSite,
               const char* stream, long int streamlength, long int protocol,
               long int squareCode = 0, long int pointCode = 0,  long int lineCode = 0, long int textCode = 0, HWND hwnd = 0);

 // C������� �������� �� ����� gml/xml
 // hMap, hSite - ������������� �����
 // xmlname - ��� �������� ����� gml/xml ��� ����� gml OGC WFS
 // protocol   - ������� ������� ��������� ������ � ������� JSON (������������� gmlGetGmlReport)
 // squareCode - ��� ����������� ��������
 // pointCode  - ��� ����������� �������� ��������
 // lineCode - ��� ����������� �����
 // textCode - ��� ����������� ��������
 // hwnd - ������������� ���� ��� ������ ��������� ��� ����, ���������� ��������� WM_PROGRESSBAR
 // ���������� ������������� ������ HGMLCLASS, �������
 // ������ ���� ���������� �������� mapFreeGmlClassHandle
 // ��� ������ ���������� 0

_MAPIMP HGMLCLASS _MAPAPI gmlCreateObjectsFromXmlPro(HMAP hMap, HSITE hSite, const WCHAR* xmlname, long int protocol,
               long int squareCode, long int pointCode,  long int lineCode, long int textCode, HWND hwnd = 0);
_MAPIMP HGMLCLASS _MAPAPI gmlCreateObjectsFromXml(HMAP hMap, HSITE hSite, const WCHAR* xmlname,
               long int squareCode, long int pointCode,  long int lineCode, long int textCode);
_MAPIMP HGMLCLASS _MAPAPI gmlCreateObjectsFromXmlEx(HMAP hMap, HSITE hSite, const WCHAR* xmlname,
               long int squareCode = 0, long int pointCode = 0,  long int lineCode = 0, long int textCode = 0, HWND hwnd = 0);

 // ���������� ������������� ������ gml/xml
 // hGmlClass - ������������� ������, ���������� � �������� mapCreateObjFromXml,
 // mapCreateObjFromXmlStream, mapLoadGmlTransactionToMap

_MAPIMP void _MAPAPI gmlFreeGmlClassHandle(HGMLCLASS hGmlClass);

 // ��������� �������� ������ � ������� JSON ��� �������� GML �������� gmlCreateObjectsFromXmlPro
 // hGmlClass - ������������� ������, ���������� � �������� mapCreateObjFromXml,
 // buffer    - ����� ������ ��� ������ ���������
 // size      - ������ ������ ��� ������ ���������
 // ��� ������� ������� ��������� �������� buffer ������ ���� ����� ����
 // ��� ������ ���������� 0

_MAPIMP int _MAPAPI gmlGetGmlReport(HGMLCLASS hGmlClass, char * buffer, long int size);

 // ��������� ������ ���������� ������� ��������� ��������
 // hGmlClass - ������������� ������
 // ObjCrNum - ������ ���������� ������� ��������� ��������
 // ���������� ��������� �� ����� THandleList
 // ��� ������ ���������� 0

_MAPIMP HANDLE _MAPAPI gmlGetGmlObjectsNumber(HGMLCLASS hGmlClass);

 // ��������� ���������� ��������� ��������
 // hGmlClass - ������������� ������
 // ���������� ���������� ��������� ��������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI gmlGetGmlCreateObjectsCount(HGMLCLASS hGmlClass);

 // ��������� ���������� ����������� �������� ��� ���������� ����������
 // hGmlClass - ������������� ������
 // ���������� ���������� ����������� ��������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI gmlGetGmlUpdateObjectsCount(HGMLCLASS hGmlClass);

 // ��������� ���������� ��������� �������� ��� ���������� ����������
 // hGmlClass - ������������� ������
 // ���������� ���������� ��������� ��������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI gmlGetGmlDeleteObjectsCount(HGMLCLASS hGmlClass);


 // ��������� ��� �������������� ������, �� �������� ��� ������ gml
 // xmlname - ��� �������� ����� gml/xml ��� ����� gml OGC WFS
 // rscname - ������������ �������� ����� ��������������, �� �������� ������ gml
 // size - ������ ���������� rscname
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI gmlGetGmlRscName(const WCHAR* xmlname, WCHAR* rscname, long int size);

 // ��������� �������� ������ ������ � ������� GML          // 12/02/16
 // name   - ��� gml-�����
 // border - �������� ������ ������ � �������� � ������� WGS-84
 // ��� ������ ���������� 0, ����� ������������� ������

_MAPIMP long int _MAPAPI gmlGetGmlBorder(const WCHAR * name, DFRAME * border);

 /*********************************************************
 *                                                        *
 *                ���������� �������                      *
 *                                                        *
 *********************************************************/

 // ��������� �������� �������� ����� �� ������ ������� ����� ��������
 // hGml  - ������������� GML ������
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG, ��� GML �� ��������� - 4326
 // dframe - �������� �������� ����� � ��������� ������� ���������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI gmlFeaturiesBounds(HGML hGml, const char *featuretypenumbers,
                                            long int epsgcode, DFRAME *dframe);

 // ��������� ����� �������� �����, ���������� �������� ������
 // hGml - ������������� �������� ����� ��� ������ GML
 // featuretypenumbers - ������ ������� ����� ��������, ����������� �������
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG, 
 // ��� GML �� ��������� - 4326
 // dframe - ������� ������ �������� ����� � ��������� ������� ��������� ��� 0
 // number - ���������� ����� �������, � �������� �������� ����� (� 1)
 // count - ����� �������� ������� 
 // ���������� ����� ��������
 // ���� ������ ����, ���������� �������, ������� ��� �� �����, �� ���������� -1
 // ���� �������� ������ �� ������������� �� ���� ������, �� ���������� -2
 // ���� ��������� ���� ��� ������ ���������, �� ���������� -4
 // ���� ��� ����� ��������� �����������, �� ���������� -5

_MAPIMP long int _MAPAPI gmlGetFeaturiesCount(HGML hGml, const char *featuretypenumbers, 
                                              long int epsgcode, DFRAME* dframe,
                                              long int number, long int count); 


 // ��������� ������ �������� ����� �� ��������� �������
 // hGml - ������������� �������� ����� ��� ������ GML
 // featuretypenumbers - ������ ������� ����� ��������, ����������� �������
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG, 
 // ��� GML �� ��������� - 4326
 // dframe - ������� ������ �������� ����� � ��������� ������� ��������� ��� 0
 // service - ��� �������� ��� ������ �����: GML, GML/WFS, JSON  (��. OGCSERVICETYPE)
 // number - ���������� ����� �������, � �������� �������� ����� � ���� (� 1)
 // count - ����� ��������, ��������� � ����, ���� ����� 0, �� ��������� ��� �������  
 // targetfilename - ��� ��������� GML-�����
 // ���������� ����� ���������� ��������
 // ���� ������ ����, ���������� �������, ������� ��� �� �����, �� ���������� -1
 // ���� �������� ������ �� ������������� �� ���� ������, �� ���������� -2
 // ���� �������� ���� �� ����� ���� ������, �� ���������� -3
 // ���� ��������� ���� ��� ������ ���������, �� ���������� -4
 // ���� ��� ����� ��������� �����������, �� ���������� -5

_MAPIMP long int _MAPAPI gmlGetFeaturiesRangeUn(HGML hGml, const char *featuretypenumbers,
                                                long int epsgcode, DFRAME* dframe,
                                                long int service,
                                                long int number, long int count,
                                                const WCHAR *targetfilename);
                                         
_MAPIMP long int _MAPAPI gmlGetFeaturiesRange(HGML hGml, const char *featuretypenumbers,
                                              long int epsgcode, DFRAME* dframe,
                                              long int service,
                                              long int number, long int count,  
                                              const char *targetfilename);
                               

 // ��������� ������ ������� ����� �� GML-��������������
 // hGml - ������������� �������� ����� ��� ������ GML
 // featuretypenumber - ����� ���� �������
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG
 // id - GML-������������� �������
 // service - ��� �������� �����: GML/WFS
 // targetfilename - ��� ��������� GML-�����

_MAPIMP long int _MAPAPI gmlGetFeatureByIdUn(HGML hGml, const char* featuretypenumber,
                                             long int epsgcode, const char *id,
                                             long int service,
                                             const WCHAR* targetfilename);
 
_MAPIMP long int _MAPAPI gmlGetFeatureById(HGML hGml, const char* featuretypenumber,
                                           long int epsgcode, const char *id,
                                           long int service,
                                           const char* targetfilename);

 // ��������� ������ �������� �����
 // hGml - ������������� �������� ����� ��� ������ GML
 // featuretypenumbers - ������ ������� ����� ��������, ����������� �������
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG, 
 // ��� GML �� ��������� - 4326
 // dframe - ������� ������ �������� ����� � ��������� ������� ��������� ��� 0
 // service - ��� �������� �����: GML/WFS  (��. OGCSERVICETYPE)
 // targetfilename - ��� ��������� GML-�����. 
 // ��� ������ ���������� ����, ����� - ����� ���������� ��������
 // ���� ������ ����, ���������� �������, ������� ��� �� �����, �� ���������� -1
 // ���� �������� ������ �� ������������� �� ���� ������, �� ���������� -2
 // ���� �������� ���� �� ����� ���� ������, �� ���������� -3
 // ���� ��������� ���� ��� ������ ���������, �� ���������� -4
 // ���� ��� ����� ��������� �����������, �� ���������� -5

_MAPIMP long int _MAPAPI gmlGetFeaturies(HGML hGml, const char *featuretypenumbers,
                                         long int epsgcode, DFRAME* dframe,
                                         long int service,
                                         const char *targetfilename);

_MAPIMP long int _MAPAPI gmlGetFeaturiesUn(HGML hGml, const char *featuretypenumbers,
                                           long int epsgcode, DFRAME* dframe,
                                           long int service,
                                           const WCHAR *targetfilename);
                                         
 // ������������ ����� ������ (dataset) � ������� GML
 // hmap  - ������������� ��������� ������ ������, ����������� ��������� �����
 // hsite - ������������� ����� � ������ ������
 // list  - ����� ����� ��� ������������� ����� ��� 1, ��� ���������������
 //         � ���� GML-���� ����� ���� ������ ���������� ������� "-1"
 // hGml - ������������� �������� ����� ��� ������ GML
 // (����������� �������� gmlOpenEx)
 // featuretypenumbers - ������ ������� ����� ��������, ����������� �������,
 //                      ��������: "1,5,11"
 // metadata - URL ��� ����������
 // epsgcode - ��� ������������� ������� ��������� � ���� ������ EPSG,
 // �� ��������� - 4326
 // targetfilename - ��� ��������� GML-�����
 // force - ������� �������������� ������ �������� (1), ���� ���� ��� ��
 //         ������� � ���������� ����� ��� 0
 // hwnd - ������������� ��� ������� ��������� � ���� ���������� ��������
 // ��� ������ ���������� ����, ����� - ����� ���������� ��������
 // ���� ������ ����, ���������� �������, ������� ��� �� �����, �� ���������� -1
 // ���� �������� ������ �� ������������� �� ���� ������, �� ���������� -2
 // ���� �������� ���� �� ����� ���� ������, �� ���������� -3
 // ���� ��������� ���� ��� ������ ���������, �� ���������� -4
 // ���� ��� ����� ��������� �����������, �� ���������� -5

_MAPIMP long int _MAPAPI gmlGetFeaturiesDataset(HMAP hmap, HSITE hsite, long int list,
                                                HGML hGml, const char * metadata,
                                                const char * featuretypenumbers,
                                                long int     epsgcode,
                                                const char * targetfilename,
                                                long int force, HWND hwnd);

_MAPIMP long int _MAPAPI gmlGetFeaturiesDatasetUn(HMAP hmap, HSITE hsite, long int list,
                                                  HGML hGml, const WCHAR * metadata,
                                                  const char  * featuretypenumbers,
                                                  long int      epsgcode,
                                                  const WCHAR * targetfilename,
                                                  long int force, HWND hwnd);
                                           
                                     
} // extern "C"

#endif  // GMLAPI_H