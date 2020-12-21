#define _CRT_SECURE_NO_WARNINGS
#include"subfunction.h"
#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>

const char* _DATA_FILE_ = "datainfo.dat";
const char* _TEMP_FILE_ = "tmp.dat";
const char* _DEPOSITORY_FILE_ = "depository.dat";
const char* _PRODUCT_FILE_ = "product.dat";
using namespace std;

int initDepository(void) //void 空
{
	system("cls");
	int rtn = 1;  //return 缩写
	DEPOSITORY depository;
	FILE* fp; //文件流指针， fopen,fclose
	fp = fopen(_DEPOSITORY_FILE_, "w");//写方式打开文件
	if (fp == NULL)//如果还是空，说明执行错误
		rtn = 0;
	else
	{
		int control = 1; //control，控制仓库的序号，第control号仓库
		do  //do while 先执行一次，才会判断while条件,while先判断括号内条件
		{
			if (control >= 6) {  //当control>=6时，说明已经成功存储了5个仓库的信息，打破循环
				printf("修改信息完毕");
				break;
			}

			printf( "录入库信息\n" );
			printf("%d号仓库\n",control );
			printf( "请输入仓库名称\n" );
			scanf("%s", &depository.name);  //前面为格式，后面是存放的变量
			printf( "请输入管理人\n" );
			scanf("%s", &depository.personName);
			depository.num = control;    
			fwrite(&depository, sizeof(depository), 1, fp);  //file 文件fwrite    &depository 第一个参数就是你要写进去什么,depository()sizeof,第三个参数为 1 个单位， 第四个参数为定义好的文件流指针
			control++;
		} while (1); 
	}
	//v0.3添加了关闭文件流
	fclose(fp);
	return rtn;
}

int initProduct(void)
{
	system("cls");
	int rtn = 1;
	PRODUCT product;
	FILE* fp;  //定义fp为文件流指针
	fp = fopen(_PRODUCT_FILE_, "w");//写方式打开文件
	if (fp == NULL)
		rtn = 0;
	else
	{
		int control = 1;
		do
		{
			if (control >= 11) {
				printf("修改产品信息完毕");
				break;
			}

			printf("录入产品信息\n");
			printf("%d种产品\n", control);
			printf("请输入产品名称\n");
			scanf("%s", &product.name);
			printf("请输入产品规格\n");
			scanf("%s", &product.specification);
			printf("请输入产品数量\n");
			scanf("%s", &product.qnum);
			printf("请输入产品编号\n");

			scanf("%s", &product.code);
			fwrite(&product, sizeof(product), 1, fp);
			control++;
		} while (1);
	}
	//v0.3添加了关闭文件流
	fclose(fp);
	return rtn;
}

int entryDepository() {
	system("cls");
	int rtn = 1;
	DATAINFO datainfo;
	FILE* fp;

	fp = fopen(_DATA_FILE_, "a");  //追加方式打开文件
	if (fp == NULL)
		fp = fopen(_DATA_FILE_, "w"); //写方式打开文件
	if (fp == NULL)
		rtn = 0;
	else {
			printf("请输入入库信息\n");
			printf("请输入入库日期,日期格式：xxxx.xx.xx\n");
			scanf("%s", &datainfo.date);
			printf("请输入入库产品编号\n");
			scanf("%s", &datainfo.productCode);
			printf("请输入入库仓库编号\n");
			scanf("%s", &datainfo.depositoryNum);
			printf("请输入入库数量\n");
			scanf("%s", &datainfo.qnum);
			strcpy(datainfo.type, "in");
			fwrite(&datainfo, sizeof(datainfo), 1, fp);		
	}
	fclose(fp);
	return rtn;
}

int outDepository() {
	system("cls");
	int rtn = 1;
	DATAINFO datainfo;
	FILE* fp;

	fp = fopen(_DATA_FILE_, "a");  //追加方式打开文件
	if (fp == NULL)
		fp = fopen(_DATA_FILE_, "w"); //写方式打开文件
	if (fp == NULL)
		rtn = 0;
	else {
			printf("请输入出库信息\n");
			printf("请输入出库日期,日期格式：xxxx.xx.xx\n");
			scanf("%s", &datainfo.date);
			printf("请输入出库产品编号\n");
			scanf("%s", &datainfo.productCode);
			printf("请输入出库仓库编号");
			scanf("%s", &datainfo.depositoryNum);
			printf("请输入出库数量\n");
			scanf("%s", &datainfo.qnum);
			strcpy(datainfo.type,"out");
			fwrite(&datainfo, sizeof(datainfo), 1, fp);
	}
	fclose(fp);
	return rtn;
}

bool findDataByType()
{
	system("cls");
	DATAINFO datainfo;
	bool found = false;
	FILE* fp;
	char code[20];
	char type[5];
	fp = fopen(_DATA_FILE_, "r");         //读方式打开文件
	printf("请输入产品编号\n");
	scanf("%s", &code);
	printf("请输入查询类型：in：入库记录，out：出库记录\n");
	scanf("%s", &type);
	if (fp != NULL)
	{
		fread(&datainfo, sizeof(datainfo), 1, fp);
		do {
			if (strcmp(datainfo.productCode, code)==0)   //比较函数，相同返回零，str1>str2，返回正数，str1<str2，返回负数
			{
				if (strcmp(datainfo.type, type)==0) {
					printf("---------------------\n");
					printf("%s    ", datainfo.date);
					printf("%s    ", datainfo.depositoryNum);
					printf("%s    ", datainfo.productCode);
					printf("%s    \n", datainfo.qnum);
					found = true;
				}	
			}
			fread(&datainfo, sizeof(datainfo), 1, fp);
			//以一个book长度为单位进行遍历寻找,fread读取一次过后，指针位置自动偏移一个sizeof(book)
		} while (!feof(fp));      //feof查找文件结尾，结尾返回非零值，未结尾，返回零
		if (!found)
			printf("没有查询到!\n");
		fclose(fp);			//进行文件关闭释放
		system("pause");
	}
	return found;
}

datainfo findDataByDate() {

	DATAINFO datainfo;
	bool found = false;
	FILE* fp;
	char code[20];
	char date[20];
	fp = fopen(_DATA_FILE_, "r");         //读方式打开文件
	printf("请输入产品编号\n");
	scanf("%s", &code);
	printf("请输入入库日期，日期格式：xxxx.xx.xx\n");
	scanf("%s", &date);
	if (fp != NULL)
	{
		fread(&datainfo, sizeof(datainfo), 1, fp);
		do {				
			if (strcmp(datainfo.productCode, code)==0)   //比较函数，相同返回零，str1>str2，返回正数，str1<str2，返回负数
			{
				if (strcmp(datainfo.date, date)==0) {
					found = true;
					break;
				}
			}
			fread(&datainfo, sizeof(datainfo), 1, fp);
			//以一个datainfo长度为单位进行遍历寻找,fread读取一次过后，指针位置自动偏移一个sizeof(datainfo)
		} while (!feof(fp));      //feof查找文件结尾，结尾返回非零值，未结尾，返回零
		if (!found) {
			printf("没有查询到!\n");
			strcpy(datainfo.productCode,"unfinded");
		}	
		fclose(fp);			//进行文件关闭释放
	}
	return datainfo;
}


int removeData(void)
{
	system("cls");
	int rtn = 1;
	DATAINFO datainfo;
	char productCode[20];
	char date[20];
		datainfo = findDataByDate();
		if (strcmp(datainfo.productCode,"unfinded")==0)
		{
			rtn = 0;
			printf( "没有找到\n" );
		}
		else
		{
			strcpy(productCode, datainfo.productCode);
			strcpy(date, datainfo.date);
			rtn = doRemoveData(productCode,date);
			if (rtn == 0)
				printf( "删除失败\n" );
		}
		system("pause");
		return rtn;
}


int doRemoveData(char* productCode,char* date)        //不同productCode的不拷贝，其他都重写拷贝
{
	DATAINFO datainfo;
	FILE* fp;
	FILE* temp;
	temp = fopen(_TEMP_FILE_, "w");
	fp = fopen(_DATA_FILE_, "r");
	if (fp != NULL)
	{	
		fread(&datainfo, sizeof(datainfo), 1, fp);
		do
		{
			int controla = strcmp(datainfo.productCode, productCode);
			int controlb = strcmp(datainfo.date, date);
			if (controla!=0||controlb!=0)
			{
					fwrite(&datainfo, sizeof(datainfo), 1, temp); //块写	
			}
			fread(&datainfo, sizeof(datainfo), 1, fp);
		} while (!feof(fp));
		fclose(fp);
		fclose(temp);
		remove(_DATA_FILE_);
		rename(_TEMP_FILE_, _DATA_FILE_);
	}
	return 1;
}


int modifyData(void)               //修改自定义数据类型data
{
	system("cls");
	printf( "修改记录\n" );        //此函数负责删除重新录入记录
	int rtn = 1;
	DATAINFO datainfo;
		datainfo =findDataByDate();
		if (!strcmp(datainfo.productCode,"unfinded"))
			printf( "没找到\n" );
		else
		{
			printf("---------------------\n");
			printf("%s    ", datainfo.date);
			printf("%s    ", datainfo.depositoryNum);
			printf("%s    ", datainfo.productCode);
			printf("%s    \n", datainfo.qnum);
			printf("---------------------\n");
			system("pause");
			doRemoveData(datainfo.productCode,datainfo.date);
				entryDepository();
			
		}	
		return rtn;
}

int readDataFromFile() {
	system("cls");
	int rtn = 1;
	DATAINFO datainfo;
	FILE* fp;
	FILE* fp2;
	char fileName[20];
	printf("请输入指定文件名称\n");
	scanf("%s", &fileName);
	fp = fopen(fileName, "r");
	fp2 = fopen(_DATA_FILE_, "a");

	if (fp==NULL){
		printf("找不到指定文件\n");
		system("pause");
		rtn = 0;
	}
	else {
		fscanf(fp,"%s %s %s %s %s ",&datainfo.productCode,&datainfo.depositoryNum,&datainfo.date,&datainfo.qnum,&datainfo.type);
		do
		{
			fwrite(&datainfo, sizeof(datainfo), 1, fp2);
			fscanf(fp, "%s %s %s %s %s ", &datainfo.productCode, &datainfo.depositoryNum, &datainfo.date, &datainfo.qnum, &datainfo.type);
		} while (!feof(fp));
		fclose(fp);
	}
	fclose(fp2);
	return rtn;
}
