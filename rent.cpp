#include"stdafx.h"
#include<iostream>
#include"mainfunction.h"
//fwrite()��fread()���ַ������������׳������룬���Կ���ʹ��fprintf()��fscanf()
int main(void)
{
	short selected = 0;
	short selectedsub = 0;
	showwelcome();
	do 
	{
		selected = showmenu();
		do 
		{
			selectedsub = showsubmenu(selected);
			callsubtask(selectedsub);
		} while (selectedsub!=0);
	} while (selected!=0);
	return 0;
}