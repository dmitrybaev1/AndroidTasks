/****  classmacro.h  ********  Zheleznyakov  V.A. ***** 16/09/15 ***
*****  classmacro.h  ********  Savelov A.S.       ***** 23/05/16 ***
*****  classmacro.h  ********  Dishlenko S.G.     ***** 21/04/16 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2016              *
*                     All Rights Reserved                          *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR WINDOWS & LINUX                         *
*                                                                  *
********************************************************************
*                                                                  *
*                  ����������� �ͣ� �������                        *
*            ���������� ��������� � ���������� �������             *
*        condition defines CLASSPREFIX=�������� �������� ������    *
*                                                                  *
*******************************************************************/

#ifndef CLASSMACRO_H
#define CLASSMACRO_H

// ��� ����������� �������� ������ 64-�� ��������� ����������, 
// ���������� ��������� ������������ ���������, � ������� �����������
// ���� � �� �� ����� ������, ���������� ����������, ����� ����������
// ������������� ���������� ������ ����� ������� � ������ �����������.
// ��� ����� � �������� ��������� ���������� ���������� ���������� "�������"
// �������. 
// ��������, � gisu64mapacces: CLASSPREFIX=MapAcc, � objectmath: CLASSPREFIX=Math
// ����������� �������� ���������� ������ � Windows � Linux

#ifndef CLASSNAME
  #define CLASSNAME
  #define _XClassName(a,b) _ClassName(a,b) // ��������������
  #define _ClassName(a,b) a##b // ����������
#endif

// simlist
#define THandleList _XClassName(THandleList, CLASSPREFIX)
#define TSimpleList _XClassName(TSimpleList, CLASSPREFIX)

// cmdparser
#define TParmList _XClassName(TParmList, CLASSPREFIX)
#define TLayerList _XClassName(TLayerList, CLASSPREFIX)
#define TRoleList _XClassName(TRoleList, CLASSPREFIX)
#define TParmSet _XClassName(TParmSet, CLASSPREFIX)
#define TParmParser _XClassName(TParmParser, CLASSPREFIX)

// xmlrpc
#define TParmXmlRpcParser _XClassName(TParmXmlRpcParser, CLASSPREFIX)

// longstring
#define TLongString _XClassName(TLongString, CLASSPREFIX)
#define TLongStringArray _XClassName(TLongStringArray, CLASSPREFIX)
#define TLongStringUn _XClassName(TLongStringUn, CLASSPREFIX)
#define TLongStringArrayUn _XClassName(TLongStringArrayUn, CLASSPREFIX)  // 21/04/16
#define TDataArray _XClassName(TDataArray, CLASSPREFIX)                  // 21/04/16

// xmlfile
#define XMLATTRVALUEUN _XClassName(XMLATTRVALUEUN, CLASSPREFIX)
#define XMLATTRVALUE _XClassName(XMLATTRVALUE, CLASSPREFIX)
#define XMLNODE _XClassName(XMLNODE, CLASSPREFIX)
#define XMLATTRNODE _XClassName(XMLATTRNODE, CLASSPREFIX)
#define TXmlFile _XClassName(TXmlFile, CLASSPREFIX)

// translate
//#define TTranslateRule _XClassName(TTranslateRule, CLASSPREFIX)
//#define TTranslate _XClassName(TTranslate, CLASSPREFIX)

// transaction
#define TTransaction _XClassName(TTransaction, CLASSPREFIX)      // 21/04/16 �������
#define TSitX _XClassName(TSitX, CLASSPREFIX)                    // 21/04/16 �������
#define LFILE _XClassName(LFILE, CLASSPREFIX)                    // 21/04/16 �������

#endif
