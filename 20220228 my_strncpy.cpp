#include <stdio.h>
#include <assert.h>

//�Զ���strncpy��������src�ĳ�ʼ�����ַ����Ƶ�dest,������dest
//��Ϊ�ǿ��������Բ�ϣ���ı�src��ֵ������*��߼�const
char* my_strncpy(char* dest, const char* src, int count)
{
	//�β���ָ�룬���漰�����ã����Բ����ǿ�ָ��
	assert(dest && src);

	//����һ��ָ�����������dest����Ԫ�ص�ַ
	char* start = dest;

	//��src�ĳ�ʼcount���ַ�������dest
	//���������������һ�������countС��src�ĳ��ȣ���������£�count��*dest++ = *src++��count�ȱ�0
	//�ڶ��������count����src�ĳ��ȣ���������£�count��*dest++ = *src++��ͬʱ��0����src��'\0'���´����dest
	//�����������count����src�ĳ��ȣ���������£�count��*dest++ = *src++��*dest++ = *src++�ȱ�0
	while (count && (*dest++ = *src++))
	{
		count--;
	};
	//���ŵ����������src�������ַ���ֱ������count
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