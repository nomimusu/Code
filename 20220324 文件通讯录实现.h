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
////switch()函数中，不同的case以数字来指代，不容易了解数字所要实现的功能，所以通过枚举，用功能的名称来取代数字，让代码可读性更高
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
////记录一个人的信息
//struct PeoInfo{
//	char name[MAX_NAME];
//	int age;
//	char gender[MAX_GENDER];
//	char tele[MAX_TELE];
//	char addr[MAX_ADDR];
//};
//
////记录1000个人的信息的通讯录
//struct Contact{
//	//存储1000个人的信息
//	struct PeoInfo data[MAX];
//	//记录目前通讯录里面有多少个人的信息
//	int size;
//};
//
////声明函数InitContact,因为修改Contact里的值，所以传地址
//void InitContact(struct Contact* ps);
//
////声明函数Addcontact，因为需要修改Contact里的值，所以传地址
//void Addcontact(struct Contact* ps);
//
////声明函数Showcontact，因为不需要修改Contact里的值，所以地址左边加const
//void Showcontact(const struct Contact*ps);
//
////声明函数Delcontact()，因为需要修改Contact的值，所以需要传址
//void Delcontact(struct Contact* ps);
//
////声明函数Searchcontact()，因为不需要修改Contact的值，所以在*左边添加const
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


//20220321 动态通讯录实现.h，类型声明和函数声明
//动态通讯录初始化容量为DEFAULT_CAPACITY,当通讯录元素个数size等于通讯录容量时，通讯录自动增加两个元素的空间

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
	//因为动态通讯录的空间需要动态改变，所以data的类型是struct PeoInfo类型的指针
	//增加一个元素capacity，初始值为DEFAULT_CAPACITY,如何capacity的值等于size，那么通讯录就自动增加两个元素的空间
	struct PeoInfo* data;
	int size;
	int capacity;
};

//初始化通讯录
//因为data的类型是struct PeoInfo类型的指针，而且默认的通讯录空间是3个元素，所以InitContact函数要做改变
void InitContact(struct Contact* ps);
//添加联系人
void add_contact(struct Contact* ps);
//显示通讯录
void show_contact(struct Contact* ps);
//删除联系人
void del_contact(struct Contact* ps);
//查找联系人
void search_contact(struct Contact *ps);
//修改联系人
void modify_contact(struct Contact *ps);
//按照姓名顺序排列联系人
void sort_contact(struct Contact *ps);
//删除通讯录，释放开辟的动态内存空间
void destory_contact(struct Contact* ps);
//把通讯录保存到文件
void save_contact(struct Contact* ps);
//将文件中保存的通讯录信息导入到通讯录
void load_contact(struct Contact* ps);