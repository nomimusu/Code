#include <stdio.h>
#include <assert.h>

//����һ��������

//int my_strlen(char* arr)
//{
//	assert(arr != NULL);
//
//	int count = 0;
//
//	while (*arr != '\0')
//	{		
//		arr++;
//		count++;
//	}
//
//	return count;
//}
//
//int main()
//{
//	char arr[] = "hello world";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//����2��ָ��

//int my_strlen2(char* arr2)
//{
//	char* start = arr2;
//	char* end = arr2;
//
//	while (*end != '\0')
//	{
//		end++;
//	}
//
//	return end - start;
//}
//
//int main()
//{
//	char arr2[] = "hello world";
//	int len = my_strlen2(arr2);
//	printf("%d\n", len);
//	return 0;
//}

//����3���ݹ�

int my_strlen3(char* arr3)
{
	if ('\0' == *arr3)
		return 0;
	else
		return 1 + my_strlen3(arr3 + 1);
}

int main()
{
	char arr3[] = "hello world";
	int len = my_strlen3(arr3);
	printf("%d\n", len);
	return 0;
}