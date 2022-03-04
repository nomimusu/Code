#include <stdio.h>
#include <assert.h>

//通过自定义函数my_memmove,将src指向的对象的字符数复制到dest指向的对象中，对象可以重叠
//返回的对象需要是指向dest的指针，因为无法确认传入的对象的类型，所以使用void*
//src指向的对象不希望被修改，所以*左边加const
void* my_memmove(void*dest, const void*src, size_t num)
{
	//形参是指针，涉及指针的解引用，所以需要确保不是空指针
	assert(dest && src);

	void* ret = dest;

	//因为是按照一个字节一个字节进行的拷贝，需要拷贝mum次
	while (num--)
	{
		//当src指向的对象的地址比dest指向的对象的地址高，src指向的对象的字符由前向后拷贝
		if (src > dest)
		{
			//因为dest和src的类型都是void*，同时需要按照一个字节一个字节进行拷贝，所以需要进行强制类型转换
			*(char*)dest = *(char*)src;
			src = (char*)src + 1;
			dest = (char*)dest + 1;
		}
		//src指向的对象的地址比dest指向的对象的地址要低，src指向的对象的字符要从后向前拷贝
		else
		{
			//需要找到src和dest所指向对象的最后一个字节的地址，然后一个字节一个字节的从后往前拷贝
			*((char*)dest + num) = *((char*)src + num);

		}
	}

	return ret;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memmove(arr+3, arr, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}