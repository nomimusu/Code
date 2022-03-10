#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_GENDER 5
#define MAX_TELE 12
#define MAX_ADDR 30


//switch()函数中，不同的case以数字来指代，不容易了解数字所要实现的功能，所以通过枚举，用功能的名称来取代数字，让代码可读性更高
enum Option{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


//记录一个人的信息
struct PeoInfo{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//记录1000个人的信息的通讯录
struct Contact{
	//存储1000个人的信息
	struct PeoInfo data[MAX];
	//记录目前通讯录里面有多少个人的信息
	int size;
};

//声明函数InitContact,因为修改Contact里的值，所以传地址
void InitContact(struct Contact* ps);

//声明函数Addcontact，因为需要修改Contact里的值，所以传地址
void Addcontact(struct Contact* ps);

//声明函数Showcontact，因为不需要修改Contact里的值，所以地址左边加const
void Showcontact(const struct Contact*ps);

//声明函数Delcontact()，因为需要修改Contact的值，所以需要传址
void Delcontact(struct Contact* ps);

//声明函数Searchcontact()，因为不需要修改Contact的值，所以在*左边添加const
void Searchcontact(struct Contact*ps);

void Modifycontact(struct Contact*ps);