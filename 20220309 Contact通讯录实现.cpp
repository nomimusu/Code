//test.c 用于测试
//contact.c 用于函数声明
//contact.h 函数头文件
//存放1000个好友信息（姓名、年龄、性别、电话、住址）；存放、增删查改、打印好友信息

#include "contact.h"

void menu()
{
	printf("********1.add       2.del************\n");
	printf("********3.search    4.modify*********\n");
	printf("********5.show      6.sort***********\n");
	printf("********0.exit            ***********\n");
}

int main()
{
	int input = 0;
	//创建通讯录,里面能够存1000个人的信息以及记录了已有多少人的信息
	struct Contact con;
	//初始化通讯录
	InitContact(&con);

	do{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:
			//往通讯录里添加成员信息
			Addcontact(&con);
			break;
		case DEL:
			//删除通讯录里的成员
			Delcontact(&con);
			break;
		case SEARCH:
			Searchcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			printf("退出通讯录！\n");
			break;
		default:
			printf("输入错误");
			break;
		}
	} while (input);

	return 0;
}