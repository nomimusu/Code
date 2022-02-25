#include <stdio.h>
#include <assert.h>

//该函数按照字母顺序比较p1指向的字符串和p2指向的字符串，并返回一个表示他们之间关系的值

//因为只是比较，不希望改变指针指向的字符串，所以*左边使用const
int my_strcmy(const char* str1, const char* str2)
{
	//形参是指针，涉及指针的解引用，所以不能是空指针
	assert(str1 && str2);

	//找到str1和str2互相对应的字符，并且按照字母顺序进行比较
	while (*str1 == *str2)
	{
		//如果两个字符串相等，那么str1和str2都会同时指向字符'\0'
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	char* p1 = "aezdef";
	char* p2 = "aezdef";

	int ret = my_strcmy(p1, p2);
	printf("%d\n",ret);
	return 0;
}