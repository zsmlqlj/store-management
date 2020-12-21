//typedef 对于c来说可以省略：typedef struct T{} A,可以叫做A，但是在c++中可以省略
//首先定义所需要的数据结构

typedef struct depository
{
    int num; //序号
    char name[20]; //库名称
    char personName[20]; //管理人名称
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
