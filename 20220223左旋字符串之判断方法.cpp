#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�㷨˼�룺��arr1���ַ�׷�ӵ�arr1��β����arr1���"abcdefabcdef\0",Ȼ���ж�arr2�ǲ���arr1���Ӵ�

int is_left_move(char*s1, char*s2)
{
	int len = strlen(s1);
	int len2 = strlen(s2);
	if (len2 != len)
	{
		return 0;
	}
	//ʹ��strncat()������s1���ַ�׷�ӵ�s1��β����
	strncat(s1, s1, len);
	//ʹ��strstr()�����ж�s2�ǲ���s1���ִ�
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