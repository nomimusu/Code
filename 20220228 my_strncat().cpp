#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

//自定义函数strncat，将strSrc的前count个字符追加到srtDest后面
//因为是拷贝，所以不希望改变strSrc的值，在*的左边加了const
char* my_strncat(char* front, const char*back, int count)
{
	//形参包含指针，涉及解引用，所以不能是空指针
	assert(front && back);

	//将strDest的首元素地址进行保存
	char*start = front;

	//找到strDest的终止空字符
	while (*front++)
	{
		;
	}
	//因为判断条件是*front++，所以指针需要自减1，从而使指针指回终止空字符
	front--;

	//将strSrc的前count个字符追加到srcDest后面，并且以终止空字符结尾
	//存在两种情况，第一种情况，count小于或者等于strSrc的长度，这个时候需要另外添加'\0'
	//第二种情况，count大于strSrc的长度，不需要另外添加'\0'
	while (count--)
	{
		if (!(*front++ = *back++))
			return start;
	};

	*front = '\0';
	return start;

}


int main()
{
	char arr1[20] = "hello\0*************";
	char arr2[] = "world";
	int count = 7;
	//char* ret = my_strncat(arr1, arr2, count);
	char* ret = strncat(arr1, arr2, count);
	printf("%s\n", ret);
	return 0;
}