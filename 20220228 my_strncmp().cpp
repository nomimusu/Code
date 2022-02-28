#include <stdio.h>
#include <assert.h>
#include <string.h>

//ͨ���Զ���my_strncmp()���������մʻ�˳��Ƚ�p1��p2ָ����ַ�����ǰcount���ַ������ҷ���һ����ʾ����֮���С��ϵ��ֵ
//��Ϊp1��p2ָ����ǳ����ַ������ǲ��ܱ��޸ĵģ�������������������*��߼�const
int my_strncmp(const char*p1, const char* p2, int count)
{
	//�β���ָ�룬�漰�����ã����Բ����ǿ�ָ��
	assert(p1 && p2);

	//count��Ϊ���������ж�p1��p2ָ����ַ��Ƿ���ȣ������ȵĻ���p1��p2��ָ����һ���ַ����бȽ�
	//��β��ֹ��Ҳ��Ƚϣ��������p1����p2ָ��'/0'��ʱ������count��󣬲��ټ����Ƚ�
	while (count-- && *p1 == *p2)
	{
		p1++;
		p2++;
	}

	return *p1 - *p2;
}

int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "abcdefg";
	int count = 7;
	printf("%d\n", strncmp(p1, p2, count));
	int ret = my_strncmp(p1, p2, count);
	if (ret > 0)
		printf("p1 > p2\n");
	if (ret < 0)
		printf("p1 < p2\n");
	if (ret == 0)
		printf("p1 = p2\n");
	return 0;
}