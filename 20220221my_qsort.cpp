#include <stdio.h>
#include <string.h>

struct Stu{
	char name[20];
	int age;
};

void Swap(char* buf1, char*buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

int cmp_stu_name(void*a, void*b)
{
	return strcmp(((struct Stu*)a)->name,((struct Stu*)b)->name);
}

void my_qsort(void*base, int sz, int width, int(*cmp)(void*e1,void*e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

void test()
{
	struct Stu s[3] = { { "zhangsan", 18 }, { "lishi", 21 }, { "wangwu", 29 } };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp_stu_name);
}

int main()
{
	test();
	return 0;
}