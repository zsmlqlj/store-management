#ifndef MAINFUNCTION_H_INCLUDED   //���û�ж��壬��Ķ����
#define MAINFUNCTION_H_INCLUDED
#define _QUIT_0
//��ʾ��ӭ��Ϣ
void showwelcome(void);
//��ʾ�˵������ѡ��Ĳ˵�
short showmenu(void);
short showsubmenu(short menu);  //��ʾ�Ӳ˵�
void callsubtask(short selected);  //���ܵ��ú��������ݲ˵�ѡ����ú���
#endif 
