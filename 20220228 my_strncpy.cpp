#include <stdio.h>
#include <assert.h>

//自定义strncpy函数，将src的初始计数字符复制到dest,并返回dest
//因为是拷贝，所以不希望改变src的值，所以*左边加const
char* my_strncpy(char* dest, const char* src, int count)
{
	//形参是指针，会涉及解引用，所以不能是空指针
	assert(dest && src);

	//设置一个指针变量，保存dest的首元素地址
	char* start = dest;

	//将src的初始count个字符拷贝到dest
	//存在三种情况，第一种情况，count小于src的长度，这种情况下，count和*dest++ = *src++，count先变0
	//第二种情况，count等于src的长度，这种情况下，count和*dest++ = *src++，同时变0，但src的'\0'不会拷贝给dest
	//第三种情况，count大于src的长度，这种情况下，count和*dest++ = *src++，*dest++ = *src++先变0
	while (count && (*dest++ = *src++))
	{
		count--;
	};
	//接着第三种情况，src被填充空字符，直到长度count
	if (count > 0)
	{
		*dest++ = '\0';
		count--;
	}

	return start;

}

int main()
{
	char arr1[30] = "abcdefg";
	char arr2[] = "jkl";
	int count = 2;
	char* start = my_strncpy(arr1, arr2, count);
	printf("%s\n", arr1);
 	return 0;
}