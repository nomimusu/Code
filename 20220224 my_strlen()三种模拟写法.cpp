#include <stdio.h>
#include <string.h>
#include <assert.h>

//strlen()����������ģ��ʵ��

//������
//int my_strlen(const char* str) //������ַ������ݽ����޸ģ�����ǰ���һ��const
//{
//	assert(str != NULL); // ���⴫�������ǿ�ָ��
//	int count = 0;//����������
//
//	while (*str) // 0��'\0'�ǲ�һ���ģ�ǰ�������ͣ�ռ�ĸ��ֽڣ��������ַ����ͣ�ռһ���ֽڣ����ߵ�ֵ���
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//}
//
//int main()
//{
//	int len = my_strlen("ab0def");
//	int size = sizeof("ab0def"); //���յó����õĽ����7��Ҳ����˵�����0����Ϊһ���ַ����ͣ�ռ1���ֽڣ���������£�0��'\0'��ֵ�������ϲ����ǵȼ۵�������ǵȼ۵Ļ�����ôwhile(*str)������������ҵ�Ԫ��0��ʱ��ͻ�ֹͣ�����շ��صĽ����2����ʵ�ʷ��ؽ����6
//	printf("%d\n",len);
//	return 0;
//}

//�ݹ鷨

//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//	return 0;
//}

//ָ�������

int my_strlen(char* str)
{
	assert(str != NULL);
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}

	return end - start;
}

int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);
	return 0;
}