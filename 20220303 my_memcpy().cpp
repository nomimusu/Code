#include <stdio.h>
#include <memory.h>
#include <assert.h>

//通过自定义函数my_memcpy()将src的计数字节拷贝到dest,因为src的值不希望被改变，所以在*的左边加上const
//因为不确定dest和src的数据类型，所以使用通用形指针void*
//num表示要拷贝的字节数

void* my_memcpy(void*dest, const void*src, size_t num)
{
	//验证指针的有效性
	assert(dest&&src);
	void* ret = dest;

	//无法确定dest和src的数据类型，但同时需要对其进行解引用操作
	//将dest和src的数据类型强制转换为char*（步长为1个字节），再根据要拷贝的字节数num,一个字节一个字节的复制
	while (num--)
	{
		*(char*)dest= *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
		//(char*)dest++;
		//(char*)src++;


	}

	return ret;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 0 };
	int arr3[] = { 1, 2, 3, 4, 5 };
	int arr4[5] = { 0 };
	int i = 0;

	memcpy(arr2, arr1, sizeof(arr1));
	my_memcpy(arr4, arr3, sizeof(arr3));

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr4[i]);
	}
	printf("\n");
	
}
