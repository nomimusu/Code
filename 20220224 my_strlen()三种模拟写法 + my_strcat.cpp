#include <stdio.h>
#include <string.h>
#include <assert.h>

//strlen()函数的三种模拟实现

//计数器
//int my_strlen(const char* str) //避免对字符串内容进行修改，所以前面加一个const
//{
//	assert(str != NULL); // 避免传进来的是空指针
//	int count = 0;//创建计数器
//
//	while (*str) // 0和'\0'是不一样的，前者是整型，占四个字节，后者是字符类型，占一个字节，两者的值相等
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//}
//
//int main()
//{
//	int len = my_strlen("ab0def");
//	int size = sizeof("ab0def"); //最终得出来得的结果是7，也就是说里面的0是作为一个字符类型，占1个字节，这种情况下，0和'\0'从值和类型上不都是等价的吗？如果是等价的话，那么while(*str)这个条件，当找到元素0的时候就会停止，最终返回的结果是2，但实际返回结果是6
//	printf("%d\n",len);
//	return 0;
//}

//递归法

//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//	return 0;
//}

//指针相减法

int my_strlen(char* str)
{
	assert(str != NULL);
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}

	return end - start;
}

int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);
	return 0;
}

//my_strcat

#include <stdio.h>
#include <assert.h>

//返回指向目的地空间的指针
char* my_strcat(char* dest, const char* src)
{
	//形参是指针，涉及指针的解引用，所以不能是空指针
	assert(dest && src);

	char* ret = dest;
	//找到目的字符串末尾的'\0'
	while (*dest != '\0')
	{
		dest++;
	}

	//追加
	while (*dest++ = *src++)
	{
		;
	}

	return ret;
}

int main()
{
	char arr1[30] = "hello";
	char arr2[] = " world";
	my_strcat(arr1, arr2);

	printf("%s\n", arr1);
	return 0;
}
