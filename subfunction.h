//#pragma once  �ɱ��������б�֤����ֹ�����ֳ�ͻ    
//#ifndef   ��֤���ᱻ��ΰ���      ���������ԵĿ���ֲ��

#ifndef SUBFUNCTION_H_INCLUDED
#define SUBFUNCTION_H_INCLUDED
#include"datainfo.h"

int initProduct();
int initDepository();
int entryDepository();
int outDepository();

bool findDataByType();
datainfo findDataByDate();

int removeData(void);
int doRemoveData(char* productCode,char* date);

int modifyData();

int readDataFromFile();
#endif             //SUBFUNCTION_H_INCLUDED



