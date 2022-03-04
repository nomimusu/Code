#include <stdio.h>
#include <assert.h>

//ͨ���Զ��庯��my_memmove,��srcָ��Ķ�����ַ������Ƶ�destָ��Ķ����У���������ص�
//���صĶ�����Ҫ��ָ��dest��ָ�룬��Ϊ�޷�ȷ�ϴ���Ķ�������ͣ�����ʹ��void*
//srcָ��Ķ���ϣ�����޸ģ�����*��߼�const
void* my_memmove(void*dest, const void*src, size_t num)
{
	//�β���ָ�룬�漰ָ��Ľ����ã�������Ҫȷ�����ǿ�ָ��
	assert(dest && src);

	void* ret = dest;

	//��Ϊ�ǰ���һ���ֽ�һ���ֽڽ��еĿ�������Ҫ����mum��
	while (num--)
	{
		//��srcָ��Ķ���ĵ�ַ��destָ��Ķ���ĵ�ַ�ߣ�srcָ��Ķ�����ַ���ǰ��󿽱�
		if (src > dest)
		{
			//��Ϊdest��src�����Ͷ���void*��ͬʱ��Ҫ����һ���ֽ�һ���ֽڽ��п�����������Ҫ����ǿ������ת��
			*(char*)dest = *(char*)src;
			src = (char*)src + 1;
			dest = (char*)dest + 1;
		}
		//srcָ��Ķ���ĵ�ַ��destָ��Ķ���ĵ�ַҪ�ͣ�srcָ��Ķ�����ַ�Ҫ�Ӻ���ǰ����
		else
		{
			//��Ҫ�ҵ�src��dest��ָ���������һ���ֽڵĵ�ַ��Ȼ��һ���ֽ�һ���ֽڵĴӺ���ǰ����
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