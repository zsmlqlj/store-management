#define _CRT_SECURE_NO_WARNINGS
//�˵�ʵ���ļ�
#include"stdafx.h"
#include<iostream>
#include<iomanip>
#include"mainfunction.h"
#include"subfunction.h"
#include<stdlib.h>

using namespace std;
void showwelcome(void)
{
	printf("************************************************\n");
	printf("************��ӭʹ�òֿ����ϵͳ**************\n");
	printf("*********alpha v0.3 by jicheng3 sj/kp**********\n");
	printf("************************************************\n");
}
short showmenu(void)
{
	int selected = 0;  //ѡ��ģ��
	printf("��ѡ������Ҫ�Ĺ���\n");
	printf("1--�޸���Ϣ\n");
	printf("2--��Ʒ����\n");
	printf("3--�鿴��¼\n");
	printf("0--�˳�\n");
	scanf("%d", &selected);
	while(selected>3||selected<0)
	{
		printf("�����������������\n");
		scanf("%d", &selected);
	}
	return selected;
}
short showsubmenu(short menu)
{
	int selected = 0;
	system("cls");
	switch (menu)
	{
	case 1:    //v0.3�޸��﷨����      (case1: ----  case 1:)
		printf("�޸���Ϣ\n");
		printf("��������Ҫִ�еĹ���\n");
		printf("1--�޸Ŀ���Ϣ\n");
		printf("2--�޸Ĳ�Ʒ��Ϣ\n");
		printf("0--�˳�\n");
		printf("��ѡ��:\n");
		scanf("%d", &selected);
		while (selected > 2 || selected < 0)
		{
			printf("�����������������~");
			scanf("%d", selected);
		}
		break;    //ע��break����Ȼ����ִ��
	case 2:
		printf("��Ʒ����\n");
		printf("��ѡ����Ҫִ�еĲ���:\n");
		printf("1--���\n");
		printf( "2--����\n" );
		printf( "0--�˳�\n" );
		printf( "��ѡ��:\n");
		scanf("%d", &selected);
		while (selected > 2 || selected < 0)
		{
			printf( "�����������������~\n" );
			scanf("%d",&selected);
		}
		if (selected != 0)
			selected += 2;
		break;
	case 3:
		printf("�鿴��¼\n");
		printf("��ѡ����Ҫִ�еĹ���\n");
		printf( "1--��ѯ��¼\n" );
		printf( "2--�޸ļ�¼\n" );
		printf( "3--ɾ����¼\n" );
		printf("4--���ļ���¼\n");
		printf( "0--�˳�" );
		printf( "��ѡ��:" );
		scanf("%d", &selected);
		                             //v0.3 �޸��Զ���תbug
		while (selected > 4 || selected < 0)
		{
			printf( "�����������������~\n" );
			scanf("%d", &selected);
		}
		if (selected !=0)
			selected += 4;
		break;
	default:
		selected =0;
	}
	return selected;
}
void callsubtask(short selected)
{
	int rtn;
	switch (selected)
	{
	
	case 1:
		
		rtn = initDepository();
		break;
	case 2:

		rtn = initProduct();
		break;
	case 3:

		rtn = entryDepository();
		break;
	case 4:

		rtn = outDepository();
		break;
	case 5:

		findDataByType();
		break;
	case 6:
		rtn = modifyData();
		break;
	case 7:

		rtn = removeData();
		break;
	case 8:
	
		rtn = readDataFromFile();
		break;
	}
}