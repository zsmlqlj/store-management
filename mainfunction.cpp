#define _CRT_SECURE_NO_WARNINGS
//菜单实现文件
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
	printf("************欢迎使用仓库管理系统**************\n");
	printf("*********alpha v0.3 by jicheng3 sj/kp**********\n");
	printf("************************************************\n");
}
short showmenu(void)
{
	int selected = 0;  //选择模块
	printf("请选择你需要的功能\n");
	printf("1--修改信息\n");
	printf("2--商品操作\n");
	printf("3--查看记录\n");
	printf("0--退出\n");
	scanf("%d", &selected);
	while(selected>3||selected<0)
	{
		printf("输入错误，请重新输入\n");
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
	case 1:    //v0.3修改语法错误      (case1: ----  case 1:)
		printf("修改信息\n");
		printf("请输入你要执行的功能\n");
		printf("1--修改库信息\n");
		printf("2--修改产品信息\n");
		printf("0--退出\n");
		printf("请选择:\n");
		scanf("%d", &selected);
		while (selected > 2 || selected < 0)
		{
			printf("输入错误，请重新输入~");
			scanf("%d", selected);
		}
		break;    //注意break，不然继续执行
	case 2:
		printf("产品操作\n");
		printf("请选择你要执行的操作:\n");
		printf("1--入库\n");
		printf( "2--出库\n" );
		printf( "0--退出\n" );
		printf( "请选择:\n");
		scanf("%d", &selected);
		while (selected > 2 || selected < 0)
		{
			printf( "输入错误，请重新输入~\n" );
			scanf("%d",&selected);
		}
		if (selected != 0)
			selected += 2;
		break;
	case 3:
		printf("查看记录\n");
		printf("请选择你要执行的功能\n");
		printf( "1--查询记录\n" );
		printf( "2--修改记录\n" );
		printf( "3--删除记录\n" );
		printf("4--从文件记录\n");
		printf( "0--退出" );
		printf( "请选择:" );
		scanf("%d", &selected);
		                             //v0.3 修复自动跳转bug
		while (selected > 4 || selected < 0)
		{
			printf( "输入错误，请重新输入~\n" );
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