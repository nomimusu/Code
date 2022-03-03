#include <stdio.h>
#include <memory.h>
#include <assert.h>

//ͨ���Զ��庯��my_memcpy()��src�ļ����ֽڿ�����dest,��Ϊsrc��ֵ��ϣ�����ı䣬������*����߼���const
//��Ϊ��ȷ��dest��src���������ͣ�����ʹ��ͨ����ָ��void*
//num��ʾҪ�������ֽ���

void* my_memcpy(void*dest, const void*src, size_t num)
{
	//��ָ֤�����Ч��
	assert(dest&&src);
	void* ret = dest;

	//�޷�ȷ��dest��src���������ͣ���ͬʱ��Ҫ������н����ò���
	//��dest��src����������ǿ��ת��Ϊchar*������Ϊ1���ֽڣ����ٸ���Ҫ�������ֽ���num,һ���ֽ�һ���ֽڵĸ���
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
