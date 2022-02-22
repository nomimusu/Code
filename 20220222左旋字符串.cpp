#include <stdio.h>
#include <assert.h>
#include <string.h>

////�������
//void left_move(char*arr,int k)
//{
//	assert(arr != NULL);//ָ����Ϊ�βΣ���Ȼ���������ã�������Ҫȷ�����ǿ�ָ��
//  aseert(k<=len);
//	int len = strlen(arr);
//	int i = 0;//��Ҫ����k��
//	for (i = 0; i < k; i++)
//	{
//		//��һ��������Ҫ��ת���ַ����Ƶ���ʱ�ռ�
//		char tmp = *arr;
//		//�ڶ��������������ַ�����һ��Ԫ�صĿռ�
//		int j = 0;
//		for (j = 0; j < len-1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		//������������ʱ�ռ�洢����Ҫ��ת���ַ����Ƶ��ַ������һ��Ԫ�صĿռ�
//		*(arr + len - 1) = tmp;
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr,2);
//	printf("%s\n", arr);
//	return 0;
//}

//������

//void reverse(char*left, char*right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int len = strlen(arr);
//	int k = 10;
//	assert(k <= len);
//	//��һ�����������Ҫ��ת���ַ���������
//	reverse(arr, arr + k - 1);
//	//�ڶ��������ұ߲���Ҫ��ת���ַ���������
//	reverse(arr + k, arr + len - 1);
//	//���������������ַ�����������
//	reverse(arr, arr + len - 1);
//	printf("%s\n", arr);
//	return 0;
//}

//����2���ַ�

//void reverse(char*left, char*right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void right_move(char* arr, int k)
//{
//	assert(arr != NULL);
//	int len = strlen(arr);
//	assert(k <= len);
//	//��һ��������߲���Ҫ��ת���ַ���������
//	reverse(arr, arr + len - 1 - k);
//	//�ڶ��������ұ���Ҫ��ת���ַ���������
//	reverse(arr + len - k, arr + len - 1);
//	//���������������ַ�����������
//	reverse(arr, arr + len - 1);
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	right_move(arr, 3);
//	printf("%s\n", arr);
//	return 0;
//}

//�ж�arr2�Ƿ���arr1����֮��Ľ��

void reverse(char*left, char*right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* arr1, int k)
{
	int len = strlen(arr1);
	reverse(arr1, arr1+k-1);
	reverse(arr1 + k, arr1 + len - 1);
	reverse(arr1, arr1 + len - 1);
}

int is_left_move(char* arr1, char* arr2)
{
	int len = strlen(arr1);
	int i = 0;
	//һ��������len�εĿ��ܣ�����0��
	for (i = 0; i < len; i++)
	{
		left_move(arr1, 1);
		if (strcmp(arr1, arr2) == 0)
			return 1;
	}

	return 0;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "aefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}