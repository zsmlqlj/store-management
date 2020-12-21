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

int initDepository(void) //void ��
{
	system("cls");
	int rtn = 1;  //return ��д
	DEPOSITORY depository;
	FILE* fp; //�ļ���ָ�룬 fopen,fclose
	fp = fopen(_DEPOSITORY_FILE_, "w");//д��ʽ���ļ�
	if (fp == NULL)//������ǿգ�˵��ִ�д���
		rtn = 0;
	else
	{
		int control = 1; //control�����Ʋֿ����ţ���control�Ųֿ�
		do  //do while ��ִ��һ�Σ��Ż��ж�while����,while���ж�����������
		{
			if (control >= 6) {  //��control>=6ʱ��˵���Ѿ��ɹ��洢��5���ֿ����Ϣ������ѭ��
				printf("�޸���Ϣ���");
				break;
			}

			printf( "¼�����Ϣ\n" );
			printf("%d�Ųֿ�\n",control );
			printf( "������ֿ�����\n" );
			scanf("%s", &depository.name);  //ǰ��Ϊ��ʽ�������Ǵ�ŵı���
			printf( "�����������\n" );
			scanf("%s", &depository.personName);
			depository.num = control;    
			fwrite(&depository, sizeof(depository), 1, fp);  //file �ļ�fwrite    &depository ��һ������������Ҫд��ȥʲô,depository()sizeof,����������Ϊ 1 ����λ�� ���ĸ�����Ϊ����õ��ļ���ָ��
			control++;
		} while (1); 
	}
	//v0.3����˹ر��ļ���
	fclose(fp);
	return rtn;
}

int initProduct(void)
{
	system("cls");
	int rtn = 1;
	PRODUCT product;
	FILE* fp;  //����fpΪ�ļ���ָ��
	fp = fopen(_PRODUCT_FILE_, "w");//д��ʽ���ļ�
	if (fp == NULL)
		rtn = 0;
	else
	{
		int control = 1;
		do
		{
			if (control >= 11) {
				printf("�޸Ĳ�Ʒ��Ϣ���");
				break;
			}

			printf("¼���Ʒ��Ϣ\n");
			printf("%d�ֲ�Ʒ\n", control);
			printf("�������Ʒ����\n");
			scanf("%s", &product.name);
			printf("�������Ʒ���\n");
			scanf("%s", &product.specification);
			printf("�������Ʒ����\n");
			scanf("%s", &product.qnum);
			printf("�������Ʒ���\n");

			scanf("%s", &product.code);
			fwrite(&product, sizeof(product), 1, fp);
			control++;
		} while (1);
	}
	//v0.3����˹ر��ļ���
	fclose(fp);
	return rtn;
}

int entryDepository() {
	system("cls");
	int rtn = 1;
	DATAINFO datainfo;
	FILE* fp;

	fp = fopen(_DATA_FILE_, "a");  //׷�ӷ�ʽ���ļ�
	if (fp == NULL)
		fp = fopen(_DATA_FILE_, "w"); //д��ʽ���ļ�
	if (fp == NULL)
		rtn = 0;
	else {
			printf("�����������Ϣ\n");
			printf("�������������,���ڸ�ʽ��xxxx.xx.xx\n");
			scanf("%s", &datainfo.date);
			printf("����������Ʒ���\n");
			scanf("%s", &datainfo.productCode);
			printf("���������ֿ���\n");
			scanf("%s", &datainfo.depositoryNum);
			printf("�������������\n");
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

	fp = fopen(_DATA_FILE_, "a");  //׷�ӷ�ʽ���ļ�
	if (fp == NULL)
		fp = fopen(_DATA_FILE_, "w"); //д��ʽ���ļ�
	if (fp == NULL)
		rtn = 0;
	else {
			printf("�����������Ϣ\n");
			printf("�������������,���ڸ�ʽ��xxxx.xx.xx\n");
			scanf("%s", &datainfo.date);
			printf("����������Ʒ���\n");
			scanf("%s", &datainfo.productCode);
			printf("���������ֿ���");
			scanf("%s", &datainfo.depositoryNum);
			printf("�������������\n");
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
	fp = fopen(_DATA_FILE_, "r");         //����ʽ���ļ�
	printf("�������Ʒ���\n");
	scanf("%s", &code);
	printf("�������ѯ���ͣ�in������¼��out�������¼\n");
	scanf("%s", &type);
	if (fp != NULL)
	{
		fread(&datainfo, sizeof(datainfo), 1, fp);
		do {
			if (strcmp(datainfo.productCode, code)==0)   //�ȽϺ�������ͬ�����㣬str1>str2������������str1<str2�����ظ���
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
			//��һ��book����Ϊ��λ���б���Ѱ��,fread��ȡһ�ι���ָ��λ���Զ�ƫ��һ��sizeof(book)
		} while (!feof(fp));      //feof�����ļ���β����β���ط���ֵ��δ��β��������
		if (!found)
			printf("û�в�ѯ��!\n");
		fclose(fp);			//�����ļ��ر��ͷ�
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
	fp = fopen(_DATA_FILE_, "r");         //����ʽ���ļ�
	printf("�������Ʒ���\n");
	scanf("%s", &code);
	printf("������������ڣ����ڸ�ʽ��xxxx.xx.xx\n");
	scanf("%s", &date);
	if (fp != NULL)
	{
		fread(&datainfo, sizeof(datainfo), 1, fp);
		do {				
			if (strcmp(datainfo.productCode, code)==0)   //�ȽϺ�������ͬ�����㣬str1>str2������������str1<str2�����ظ���
			{
				if (strcmp(datainfo.date, date)==0) {
					found = true;
					break;
				}
			}
			fread(&datainfo, sizeof(datainfo), 1, fp);
			//��һ��datainfo����Ϊ��λ���б���Ѱ��,fread��ȡһ�ι���ָ��λ���Զ�ƫ��һ��sizeof(datainfo)
		} while (!feof(fp));      //feof�����ļ���β����β���ط���ֵ��δ��β��������
		if (!found) {
			printf("û�в�ѯ��!\n");
			strcpy(datainfo.productCode,"unfinded");
		}	
		fclose(fp);			//�����ļ��ر��ͷ�
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
			printf( "û���ҵ�\n" );
		}
		else
		{
			strcpy(productCode, datainfo.productCode);
			strcpy(date, datainfo.date);
			rtn = doRemoveData(productCode,date);
			if (rtn == 0)
				printf( "ɾ��ʧ��\n" );
		}
		system("pause");
		return rtn;
}


int doRemoveData(char* productCode,char* date)        //��ͬproductCode�Ĳ���������������д����
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
					fwrite(&datainfo, sizeof(datainfo), 1, temp); //��д	
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


int modifyData(void)               //�޸��Զ�����������data
{
	system("cls");
	printf( "�޸ļ�¼\n" );        //�˺�������ɾ������¼���¼
	int rtn = 1;
	DATAINFO datainfo;
		datainfo =findDataByDate();
		if (!strcmp(datainfo.productCode,"unfinded"))
			printf( "û�ҵ�\n" );
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
	printf("������ָ���ļ�����\n");
	scanf("%s", &fileName);
	fp = fopen(fileName, "r");
	fp2 = fopen(_DATA_FILE_, "a");

	if (fp==NULL){
		printf("�Ҳ���ָ���ļ�\n");
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
