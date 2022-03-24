//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define MAX 1000
//#define MAX_NAME 20
//#define MAX_GENDER 5
//#define MAX_TELE 12
//#define MAX_ADDR 30
//
//
////switch()�����У���ͬ��case��������ָ�����������˽�������Ҫʵ�ֵĹ��ܣ�����ͨ��ö�٣��ù��ܵ�������ȡ�����֣��ô���ɶ��Ը���
//enum Option{
//	EXIT,
//	ADD,
//	DEL,
//	SEARCH,
//	MODIFY,
//	SHOW,
//	SORT
//};
//
//
////��¼һ���˵���Ϣ
//struct PeoInfo{
//	char name[MAX_NAME];
//	int age;
//	char gender[MAX_GENDER];
//	char tele[MAX_TELE];
//	char addr[MAX_ADDR];
//};
//
////��¼1000���˵���Ϣ��ͨѶ¼
//struct Contact{
//	//�洢1000���˵���Ϣ
//	struct PeoInfo data[MAX];
//	//��¼ĿǰͨѶ¼�����ж��ٸ��˵���Ϣ
//	int size;
//};
//
////��������InitContact,��Ϊ�޸�Contact���ֵ�����Դ���ַ
//void InitContact(struct Contact* ps);
//
////��������Addcontact����Ϊ��Ҫ�޸�Contact���ֵ�����Դ���ַ
//void Addcontact(struct Contact* ps);
//
////��������Showcontact����Ϊ����Ҫ�޸�Contact���ֵ�����Ե�ַ��߼�const
//void Showcontact(const struct Contact*ps);
//
////��������Delcontact()����Ϊ��Ҫ�޸�Contact��ֵ��������Ҫ��ַ
//void Delcontact(struct Contact* ps);
//
////��������Searchcontact()����Ϊ����Ҫ�޸�Contact��ֵ��������*������const
//void Searchcontact(struct Contact*ps);
//
//void Modifycontact(struct Contact*ps);

//#include <stdio.h>
//#include <string.h>
//
//#define MAX 1000
//#define MAX_NAME 20
//#define MAX_GENDER 20
//#define MAX_TELE 30
//#define MAX_ADDR 30
//
//enum Option{
//	EXIT,
//	ADD,
//	DEL,
//	SEARCH,
//	MODIFY,
//	SHOW
//};
//
//struct PeoInfo{
//	char name[MAX_NAME];
//	int age;
//	char gender[MAX_GENDER];
//	char tele[MAX_TELE];
//	char addr[MAX_ADDR];
//};
//
//struct Contact {
//	struct PeoInfo data[MAX];
//	int size;
//};
//
//void Initcontact(struct Contact*ps);
//
//void Addcontact(struct Contact*ps);
//
//void Showcontact(struct Contact*ps);


//20220321 ��̬ͨѶ¼ʵ��.h�����������ͺ�������
//��̬ͨѶ¼��ʼ������ΪDEFAULT_CAPACITY,��ͨѶ¼Ԫ�ظ���size����ͨѶ¼����ʱ��ͨѶ¼�Զ���������Ԫ�صĿռ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAX_NAME 30
#define MAX_GENDER 20
#define MAX_TELE 20
#define MAX_ADDR 15
//#define MAX 1000
#define DEFAULT_CAPACITY 3

enum Option{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Sort,
	Save
};

struct PeoInfo{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact{
	//��Ϊ��̬ͨѶ¼�Ŀռ���Ҫ��̬�ı䣬����data��������struct PeoInfo���͵�ָ��
	//����һ��Ԫ��capacity����ʼֵΪDEFAULT_CAPACITY,���capacity��ֵ����size����ôͨѶ¼���Զ���������Ԫ�صĿռ�
	struct PeoInfo* data;
	int size;
	int capacity;
};

//��ʼ��ͨѶ¼
//��Ϊdata��������struct PeoInfo���͵�ָ�룬����Ĭ�ϵ�ͨѶ¼�ռ���3��Ԫ�أ�����InitContact����Ҫ���ı�
void InitContact(struct Contact* ps);
//�����ϵ��
void add_contact(struct Contact* ps);
//��ʾͨѶ¼
void show_contact(struct Contact* ps);
//ɾ����ϵ��
void del_contact(struct Contact* ps);
//������ϵ��
void search_contact(struct Contact *ps);
//�޸���ϵ��
void modify_contact(struct Contact *ps);
//��������˳��������ϵ��
void sort_contact(struct Contact *ps);
//ɾ��ͨѶ¼���ͷſ��ٵĶ�̬�ڴ�ռ�
void destory_contact(struct Contact* ps);
//��ͨѶ¼���浽�ļ�
void save_contact(struct Contact* ps);
//���ļ��б����ͨѶ¼��Ϣ���뵽ͨѶ¼
void load_contact(struct Contact* ps);