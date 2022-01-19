#include <stdio.h>
#include <assert.h>

char* my_strlen(char* dest, const char* src)
{
	//保证输入值合法，不是空指针
	assert(dest != NULL);
	assert(src != NULL);

	char* ret = dest;

	//const将srcd存储空间的数据设置为常量
	while (*dest++ = *src++)
	{
		;
	}


	return ret;


}

int main()
{
	char arr1[] = "################";
	char arr2[] = "bit";
	my_strlen(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}