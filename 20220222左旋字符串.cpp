#include <stdio.h>
#include <assert.h>
#include <string.h>

////暴力求解
//void left_move(char*arr,int k)
//{
//	assert(arr != NULL);//指针作为形参，必然会做解引用，所以需要确保不是空指针
//  aseert(k<=len);
//	int len = strlen(arr);
//	int i = 0;//需要左旋k次
//	for (i = 0; i < k; i++)
//	{
//		//第一步：将需要旋转的字符复制到临时空间
//		char tmp = *arr;
//		//第二步：将其他的字符左移一个元素的空间
//		int j = 0;
//		for (j = 0; j < len-1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		//第三步：将临时空间存储的需要旋转的字符复制到字符串最后一个元素的空间
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

//三步法

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
//	//第一步：将左边需要旋转的字符逆序排列
//	reverse(arr, arr + k - 1);
//	//第二步：将右边不需要旋转的字符逆序排列
//	reverse(arr + k, arr + len - 1);
//	//第三步：将整个字符串逆序排列
//	reverse(arr, arr + len - 1);
//	printf("%s\n", arr);
//	return 0;
//}

//右旋2个字符

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
//	//第一步，将左边不需要旋转的字符逆序排列
//	reverse(arr, arr + len - 1 - k);
//	//第二步，将右边需要旋转的字符逆序排列
//	reverse(arr + len - k, arr + len - 1);
//	//第三步，将整个字符串逆序排列
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

//判断arr2是否是arr1左旋之后的结果

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
	//一共有左旋len次的可能，包括0次
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