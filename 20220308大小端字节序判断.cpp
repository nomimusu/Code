#include <stdio.h>

////����һ������ָ��
//int check_sys()
//{
//	int a = 1;
//	//�������ֵ��1����ʾС��
//	//�������ֵ��0����ʾ���
//	//&a��һ��int���͵�ָ�룬�����û����4���ֽڣ����Խ���ǿ������ת��Ϊchar���͵�ָ�룬�����þͻ����һ���ֽ�
//	
//	return *(char*)&a;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (1 == ret)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//
//	return 0;
//}

//������������������

int check_sys()
{
	union Un{
		char c;
		int i;
	}u;

	u.i = 1;

	//�������ֵ��1����ʾС���ֽ���洢
	//�������ֵ��0����ʾ����ֽ���洢
	return u.c;
}

int main()
{
	int ret = check_sys();
	if (1 == ret)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}