#include <stdio.h>
#include <assert.h>

char* my_strlen(char* dest, const char* src)
{
	//��֤����ֵ�Ϸ������ǿ�ָ��
	assert(dest != NULL);
	assert(src != NULL);

	char* ret = dest;

	//const��srcd�洢�ռ����������Ϊ����
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