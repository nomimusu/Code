#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//算法思想：将arr1的字符追加到arr1的尾部，arr1变成"abcdefabcdef\0",然后判断arr2是不是arr1的子串

int is_left_move(char*s1, char*s2)
{
	int len = strlen(s1);
	int len2 = strlen(s2);
	if (len2 != len)
	{
		return 0;
	}
	//使用strncat()函数将s1的字符追加到s1的尾部；
	strncat(s1, s1, len);
	//使用strstr()函数判断s2是不是s1的字串
	char* ret = strstr(s1, s2);
	if (NULL == ret)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdef";
	int ret = is_left_move(arr1, arr2);
	if (1 == ret)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}