#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

//检验是否开辟内存空间成功
//int main()
//{
//	int* p = (int*)malloc(10*sizeof(int));
//	//如果开辟内存空间失败
//	if (NULL == p)
//	{
//		printf("开辟内存空间失败\n");
//		printf("%s\n", strerror(errno));
//	}
//	//如果开辟空间成功
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	//p = NULL;
//
//	return 0;
//}

//int main()
//{
//	int* p = (int*)calloc(40,sizeof(int));
//	if (p == NULL)
//	{
//		printf("动态内存空间未开辟成功\n");
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//
//	int*p2 = (int*)realloc(p, 500);
//	if (p2 != NULL)
//	{
//		int i = 0;
//		for (i = 10; i < 20; i++)
//		{
//			*(p2 + i) = i;
//		}
//		for (i = 10; i < 20; i++)
//		{
//			printf("%d ", *(p2 + i));
//		}
//	}
//
//	return 0;
//}

//错题一分析

//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//}

//Bug 1 ： 运行程序，程序会崩溃
//	GetMemory(str),传的不是str的地址，而是str本身即NULL，所以指针p是指针str的一份临时拷贝
//  (char*)malloc(100)开辟了100个字节的动态内存空间，并将其强制转换为(char*),
//   p = (char*)malloc(100),让指针p指向(char*)malloc(100)开辟的100个字节的动态内存空间，此时p保存的是开辟的动态内存空间的地址
//  但因为p是GetMemory函数的形参变量，作用域仅限GetMemory函数内部，出了GetMemory函数就不在了，所以并不影响指针str指向的空间
//   strcpy是把hello world拷贝到空指针所指向的那块空间，但空指针没有指向一块有效空间，strcpy函数是无法将hello world拷贝过去的
//   相当于是对空指针进行解引用，所以程序崩溃
//Bug 2 ： 程序存在内存泄漏
//	GetMemory函数内部使用了malloc()函数，开辟了一块动态内存空间，但是并没有对其释放，而且出了GetMemory函数，指向malloc()开辟的
//  动态内存空间的指针p也会失效，也就是说，我们就找不到这块开辟好的动态内存空间

//Debug 方法1 : 将开辟的动态内存空间保存到str指针
//    如果想要将GetMemory函数里面开辟的动态内存空间的地址传给str指针，那么GetMemory函数的形参就需要能够接收str指针的地址
//    所以GetMemory函数的新参就需要是二级指针
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//}

// Debug 方法2 : 为了避免指针p在GetMemory函数被调用结束之后消失，所以可以把GetMemory函数的返回值改为指针p，然后将指针p赋值给str指针

//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//}

//错题二分析

//char* GetMemory(void)
//{
//	static char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//}

//原本思路	
//		p是字符数组，return p ---> 不是sizeof或& + 数组名，所以p是首元素地址，GetMemory函数的返回值就是首元素地址
//      将字符数组p的首元素地址赋给str指针，然后打印，所以会打印字符'h'

// Bug ：返回栈空间地址问题
//       字符数组p仅在GetMemory函数内部有效，当GetMemory函数调用结束之后，里面创建的字符数组p的内存空间就会返回给操作系统
//       虽然把字符数组p的地址传递给了str指针，但字符数组p的内存空间已经返回给操作系统了
//		 这时候如果再通过str指针去访问字符数组p的内存空间，就会造成非法访问

// Debug："p是字符数组，return p ---> 不是sizeof或& + 数组名，所以p是首元素地址，GetMemory函数的返回值就是首元素地址" ----->
//         return p 中的p，既可以是数组p，也可以是数组p的首元素地址
//		   在GeoMemory函数中，在数组p左边加上关键字static，这样数组p的空间就从栈区移到了静态区，
//		   这样哪怕GeoMemory调用结束以后，数组p的空间也不会还给操作系统

// #柔性数组的使用一（结构体的最后一个元素允许是未知大小的数组，这叫“柔性数组”成员，结构体中的一个元素是柔性数组成员）

//struct S{
//	int n;
//	int arr[0];
//};
//
//int main()
//{
//	//struct S s;
//	//printf("%d\n", sizeof(s));

	//开辟一块动态内存空间，并将malloc函数的返回值的类型转换为struct S*,用结构体指针来接收
	//sizeof(struct S)是n所用的空间，5*sizeof(int)是柔性数组int arr[0]所用的空间
//	struct S* ps = (struct S*)(malloc(sizeof(struct S) + 5 * sizeof(int)));
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//我觉得给int arr[0]分配的5*sizeof(int)的空间不够， 希望变成10*sizeof(int)的空间
//	struct S* ptr = (struct S*)(realloc(ps,44));
//	//因为realloc函数有可能返回NULL，未必避免对空指针进行解引用，所以要先检测一下
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	return 0;
//}

// #柔性数组的使用二（结构体的最后一个元素允许是未知大小的数组，这叫“柔性数组”成员，结构体中的一个成员是指针，该指针指向一块动态内存空间，
//实现柔性数组的功能）

struct S{
	int n;
	int* arr;
};

int main()
{
	//使用malloc函数开辟一块动态内存空间，是结构体struct S的大小
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	//使用成员int* arr来指向一块动态内存空间
	ps->arr = (int*)(malloc(5 * sizeof(int)));
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	//通过realloc函数将指针arr指向的那块动态内存空间的大小重新设置为44个字节
	int* ptr = (int*)realloc(ps->arr, 44);
	//realloc函数有可能返回NULL，为了避免对空指针解引用，要先检测一下；
	if (ptr != NULL)
	{
		ps->arr = ptr;
		for (i = 5; i < 10; i++)
		{
			ps->arr[i] = i;
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);

	}
	//对开辟的动态内存空间进行释放，因为ps->arr指向的是大小为10*sizeof(int)的内存空间，不能够先删除结构体指针ps所在的动态内存空间
	//否则就会找不到大小为10*sizeof(int)的内存空间
	//删除之后，为了避免非法访问，将ps->arr设置为NULL
	free(ps->arr);
	ps->arr = NULL; 
	free(ps);
	ps = NULL;
	return 0;
}