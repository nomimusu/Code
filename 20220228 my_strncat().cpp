#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

//�Զ��庯��strncat����strSrc��ǰcount���ַ�׷�ӵ�srtDest����
//��Ϊ�ǿ��������Բ�ϣ���ı�strSrc��ֵ����*����߼���const
char* my_strncat(char* front, const char*back, int count)
{
	//�βΰ���ָ�룬�漰�����ã����Բ����ǿ�ָ��
	assert(front && back);

	//��strDest����Ԫ�ص�ַ���б���
	char*start = front;

	//�ҵ�strDest����ֹ���ַ�
	while (*front++)
	{
		;
	}
	//��Ϊ�ж�������*front++������ָ����Ҫ�Լ�1���Ӷ�ʹָ��ָ����ֹ���ַ�
	front--;

	//��strSrc��ǰcount���ַ�׷�ӵ�srcDest���棬��������ֹ���ַ���β
	//���������������һ�������countС�ڻ��ߵ���strSrc�ĳ��ȣ����ʱ����Ҫ�������'\0'
	//�ڶ��������count����strSrc�ĳ��ȣ�����Ҫ�������'\0'
	while (count--)
	{
		if (!(*front++ = *back++))
			return start;
	};

	*front = '\0';
	return start;

}


int main()
{
	char arr1[20] = "hello\0*************";
	char arr2[] = "world";
	int count = 7;
	//char* ret = my_strncat(arr1, arr2, count);
	char* ret = strncat(arr1, arr2, count);
	printf("%s\n", ret);
	return 0;
}