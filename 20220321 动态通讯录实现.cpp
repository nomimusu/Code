////test.c 用于测试
////contact.c 用于函数声明
////contact.h 函数头文件
////存放1000个好友信息（姓名、年龄、性别、电话、住址）；存放、增删查改、打印好友信息
//
//#include "contact.h"
//
//void menu()
//{
//	printf("********1.add       2.del************\n");
//	printf("********3.search    4.modify*********\n");
//	printf("********5.show      6.sort***********\n");
//	printf("********0.exit            ***********\n");
//}
//
//int main()
//{
//	int input = 0;
//	//创建通讯录,里面能够存1000个人的信息以及记录了已有多少人的信息
//	struct Contact con;
//	//初始化通讯录
//	InitContact(&con);
//
//	do{
//		menu();
//		printf("请选择：");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case ADD:
//			//往通讯录里添加成员信息
//			Addcontact(&con);
//			break;
//		case DEL:
//			//删除通讯录里的成员
//			Delcontact(&con);
//			break;
//		case SEARCH:
//			Searchcontact(&con);
//			break;
//		case MODIFY:
//			Modifycontact(&con);
//			break;
//		case SHOW:
//			Showcontact(&con);
//			break;
//		case SORT:
//			break;
//		case EXIT:
//			printf("退出通讯录！\n");
//			break;
//		default:
//			printf("输入错误");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
//
//#include "contact.h"
//
//void menu()
//{
//	printf("****1.ADD      2.DEL*******\n");
//	printf("****3.SEARCH   4.MODIFY****\n");
//	printf("****5.SHOW     0.EXIT******\n");
//
//}
//
//int main()
//{
//	int input = 0;
//	//创建一个通讯录
//	struct Contact con;
//	//初始化通讯录，将指都变为0；
//	Initcontact(&con);
//
//	do{
//		menu();
//		printf("请选择:>");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case ADD:
//			Addcontact(&con);
//			break;
//		case DEL:
//			break;
//		case SEARCH:
//			break;
//		case MODIFY:
//			break;
//		case SHOW:
//			Showcontact(&con);
//			break;
//		case EXIT:
//			printf("退出通讯录\n");
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//对通讯录进行测试
//设置菜单栏，通过do....while()语句进行循环，switch case()语句选择菜单栏里不同的功能

#include "20220321 动态通讯录实现.h"

void menu()
{
	printf("****1.Add        2.Del**************\n");
	printf("****3.Search     4.Modify***********\n");
	printf("****5.Show       6.Sort*************\n");
	printf("****0.Exit             *************\n");
}

void test()
{
	int input = 0;
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);

	do{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case Add:
			add_contact(&con);
			break;
		case Del:
			del_contact(&con);
			break;
		case Search:
			search_contact(&con);
			break;
		case Modify:
			modify_contact(&con);
			break;
		case Show:
			show_contact(&con);
			break;
		case Sort:
			sort_contact(&con);
			break;
		case Exit:
			//销毁通讯录，释放开辟的动态内存空间
			destory_contact(&con);
			printf("退出程序\n");
			break;
		default:
			printf("输入错误，请重现输入\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}