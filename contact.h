#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_GENDER 5
#define MAX_TELE 12
#define MAX_ADDR 30


//switch()�����У���ͬ��case��������ָ�����������˽�������Ҫʵ�ֵĹ��ܣ�����ͨ��ö�٣��ù��ܵ�������ȡ�����֣��ô���ɶ��Ը���
enum Option{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


//��¼һ���˵���Ϣ
struct PeoInfo{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//��¼1000���˵���Ϣ��ͨѶ¼
struct Contact{
	//�洢1000���˵���Ϣ
	struct PeoInfo data[MAX];
	//��¼ĿǰͨѶ¼�����ж��ٸ��˵���Ϣ
	int size;
};

//��������InitContact,��Ϊ�޸�Contact���ֵ�����Դ���ַ
void InitContact(struct Contact* ps);

//��������Addcontact����Ϊ��Ҫ�޸�Contact���ֵ�����Դ���ַ
void Addcontact(struct Contact* ps);

//��������Showcontact����Ϊ����Ҫ�޸�Contact���ֵ�����Ե�ַ��߼�const
void Showcontact(const struct Contact*ps);

//��������Delcontact()����Ϊ��Ҫ�޸�Contact��ֵ��������Ҫ��ַ
void Delcontact(struct Contact* ps);

//��������Searchcontact()����Ϊ����Ҫ�޸�Contact��ֵ��������*������const
void Searchcontact(struct Contact*ps);

void Modifycontact(struct Contact*ps);