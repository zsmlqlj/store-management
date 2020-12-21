//#pragma once  由编译器进行保证，防止宏名字冲突    
//#ifndef   保证不会被多次包含      依靠于语言的可移植性

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



