//typedef ����c��˵����ʡ�ԣ�typedef struct T{} A,���Խ���A��������c++�п���ʡ��
//���ȶ�������Ҫ�����ݽṹ

typedef struct depository
{
    int num; //���
    char name[20]; //������
    char personName[20]; //����������
 }DEPOSITORY;

typedef struct product
{
    char code[20];
    char name[20];
    char specification[20];
    char qnum[10];
}PRODUCT;

typedef struct datainfo
{
    char productCode[20];
    char depositoryNum[10];
    char date[20];
    char qnum[10];
    char type[5];
}DATAINFO;
