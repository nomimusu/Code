#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	//将要交换width次
	for (i = 0; i < width; i++)
	{
		//对buf1，buf2进行解引用
		//将buf2地址保存的内容存到buf1地址
		//将buf1地址保存的内除保存到buf2地址
		//buf1和buf2指针指向下一个空间
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}


//第一个参数：待排序数组的首元素地址，因为不知道元素的类型，所以使用无类型指针
//第二个参数：待排序数组的元素个数
//第三个参数：待排序数组的每个元素所占空间大小，单位为字节
//第四个参数：函数指针，指向比较两个元素所用的函数的地址
//函数的两个参数：相比较的两个元素的地址，因为不知道元素的类型，所以使用无类型指针
void Bubble_Sort1(void*base, int sz, int width, int(*cmp)(void*e1, void*e2))
{
	int i = 0;
	//需要排序sz-1遍
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		//每一遍比较sz-1-i对
		for (j = 0; j < sz - 1 - i; j++)
		{
			//cmp的函数地址（指针）作为参数传参给Bubble_Sort1函数
			//Bubble_Sort1函数内使用cmp的函数地址（指针）来调用cmp函数
			//cmp函数的返回值为0，说明e1大于e2,需要进行交换
			//函数设计者无法了解使用函数者需要比较的元素类型
			//相邻两个元素的地址通过写成(char*)base + j*width 和 (char*)base + (j+1)width来确定第一个和第二个元素的地址，第二个和第三个元素的地址，第三个和第四个元素的地址，以此类推;
			//之所以选择（char*）类型，因为char类型只占1个字节
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width) > 0)
			{
				//通过交换函数，交换e1地址和e2地址上所保存的内容
				//将相邻两元素的地址传给交换函数
				//因为函数设计者无法了解使用函数者需要比较的元素类型,有些元素占1个字节，4个字节，8个字节
				//如果是仅占1个字节的元素，那么把相邻两元素的地址传给交换函数后，交换一次即可
				//如果是占4个字节的元素，那么把相邻两元素的地址传给交换函数后，需要交换四次，因为char*只能够访问1个字节
				//如果是占4个字节的元素，那么把相邻两元素的地址传给交换函数后，需要交换八次，因为char*只能够访问1个字节
				//所以交换函数还需要多一个参数，即元素所占空间大小
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

struct Stu{
	char name[20];
	int age;
};


int cmp_stu_age(void* a, void* b)
{
	return ((struct Stu*)a)->age - ((struct Stu*)b)->age;
}

int cmp_stu_name(void*a, void*b)
{
	return strcmp(((struct Stu*)a)->name, ((struct Stu*)b)->name);
}

void test4()
{
	struct Stu s[3] = { { "zhangsan", 12 }, { "lisi", 28 }, { "wangwu", 18 } };
	int sz = sizeof(s) / sizeof(s[0]);

	Bubble_Sort1(s, sz, sizeof(s[0]), cmp_stu_name);
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
