#include <stdio.h>
#include <assert.h>

//const放在*左边，表示无法通过指针src来修改指针所保存的地址里面存储的值
char* my_strcpy(char* dest, const char*src)
{
	assert(dest != NULL);
	assert(src != NULL);

	//将dest的首元素地址传给另一个指针，保证有一个指针一直保存dest的首元素地址
	char* ret = dest;

	while (*dest++ = *src++)
	{
		;
	}

	return ret;
}

int main()
{
	char arr1[] = "#####################";
	char arr2[] = "bits";
	printf("%s\n",my_strcpy(arr1, arr2));
	return 0;
}
