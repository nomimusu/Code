#include <stdio.h>

////方法一：利用指针
//int check_sys()
//{
//	int a = 1;
//	//如果返回值是1，表示小端
//	//如果返回值是0，表示大端
//	//&a是一个int类型的指针，解引用会访问4个字节，所以将其强制类型转换为char类型的指针，解引用就会访问一个字节
//	
//	return *(char*)&a;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (1 == ret)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}

//方法二：利用联合体

int check_sys()
{
	union Un{
		char c;
		int i;
	}u;

	u.i = 1;

	//如果返回值是1，表示小端字节序存储
	//如果返回值是0，表示大端字节序存储
	return u.c;
}

int main()
{
	int ret = check_sys();
	if (1 == ret)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}