#include <stdio.h>
#include <assert.h>

//目的地字符串的内容需要改变，所以*左边不加const;src字符串不要改变，所以*左边加了const；最终需要的是目的地字符串，所以返回一个指向目的地字符串的指针
char* my_strcpy(char* dest, const char* src)
{
	//形参是指针，容易涉及指针的解引用，所以需要保证不是空指针
	assert(dest != NULL);
	assert(src != NULL);

	//创建一个指针指向dest指向的字符串
	char* ret = dest;

	//拷贝src指向的字符串到dest指向的空间，包括'\0'
	//后置++，所以先解引用赋值，然后再自增1；
	//src解引用得到的值，赋给dest指向的空间，那么*dest = *src的结果就是所赋的值，就可以把'\0'也拷贝到dest指向的空间
	while (*dest++ = *src++)
	{
		;
	}

	return ret;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "hig";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
