#include <stdio.h>
#include <assert.h>

//�ú���������ĸ˳��Ƚ�p1ָ����ַ�����p2ָ����ַ�����������һ����ʾ����֮���ϵ��ֵ

//��Ϊֻ�ǱȽϣ���ϣ���ı�ָ��ָ����ַ���������*���ʹ��const
int my_strcmy(const char* str1, const char* str2)
{
	//�β���ָ�룬�漰ָ��Ľ����ã����Բ����ǿ�ָ��
	assert(str1 && str2);

	//�ҵ�str1��str2�����Ӧ���ַ������Ұ�����ĸ˳����бȽ�
	while (*str1 == *str2)
	{
		//��������ַ�����ȣ���ôstr1��str2����ͬʱָ���ַ�'\0'
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	char* p1 = "aezdef";
	char* p2 = "aezdef";

	int ret = my_strcmy(p1, p2);
	printf("%d\n",ret);
	return 0;
}