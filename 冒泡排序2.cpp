#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	//��Ҫ����width��
	for (i = 0; i < width; i++)
	{
		//��buf1��buf2���н�����
		//��buf2��ַ��������ݴ浽buf1��ַ
		//��buf1��ַ������ڳ����浽buf2��ַ
		//buf1��buf2ָ��ָ����һ���ռ�
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}


//��һ���������������������Ԫ�ص�ַ����Ϊ��֪��Ԫ�ص����ͣ�����ʹ��������ָ��
//�ڶ��������������������Ԫ�ظ���
//�����������������������ÿ��Ԫ����ռ�ռ��С����λΪ�ֽ�
//���ĸ�����������ָ�룬ָ��Ƚ�����Ԫ�����õĺ����ĵ�ַ
//������������������Ƚϵ�����Ԫ�صĵ�ַ����Ϊ��֪��Ԫ�ص����ͣ�����ʹ��������ָ��
void Bubble_Sort1(void*base, int sz, int width, int(*cmp)(void*e1, void*e2))
{
	int i = 0;
	//��Ҫ����sz-1��
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		//ÿһ��Ƚ�sz-1-i��
		for (j = 0; j < sz - 1 - i; j++)
		{
			//cmp�ĺ�����ַ��ָ�룩��Ϊ�������θ�Bubble_Sort1����
			//Bubble_Sort1������ʹ��cmp�ĺ�����ַ��ָ�룩������cmp����
			//cmp�����ķ���ֵΪ0��˵��e1����e2,��Ҫ���н���
			//����������޷��˽�ʹ�ú�������Ҫ�Ƚϵ�Ԫ������
			//��������Ԫ�صĵ�ַͨ��д��(char*)base + j*width �� (char*)base + (j+1)width��ȷ����һ���͵ڶ���Ԫ�صĵ�ַ���ڶ����͵�����Ԫ�صĵ�ַ���������͵��ĸ�Ԫ�صĵ�ַ���Դ�����
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width) > 0)
			{
				//ͨ����������������e1��ַ��e2��ַ�������������
				//��������Ԫ�صĵ�ַ������������
				//��Ϊ����������޷��˽�ʹ�ú�������Ҫ�Ƚϵ�Ԫ������,��ЩԪ��ռ1���ֽڣ�4���ֽڣ�8���ֽ�
				//����ǽ�ռ1���ֽڵ�Ԫ�أ���ô��������Ԫ�صĵ�ַ�������������󣬽���һ�μ���
				//�����ռ4���ֽڵ�Ԫ�أ���ô��������Ԫ�صĵ�ַ����������������Ҫ�����ĴΣ���Ϊchar*ֻ�ܹ�����1���ֽ�
				//�����ռ4���ֽڵ�Ԫ�أ���ô��������Ԫ�صĵ�ַ����������������Ҫ�����˴Σ���Ϊchar*ֻ�ܹ�����1���ֽ�
				//���Խ�����������Ҫ��һ����������Ԫ����ռ�ռ��С
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

struct Stu{
	char name[20];
	int age;
};


int cmp_stu_age(void* a, void* b)
{
	return ((struct Stu*)a)->age - ((struct Stu*)b)->age;
}

int cmp_stu_name(void*a, void*b)
{
	return strcmp(((struct Stu*)a)->name, ((struct Stu*)b)->name);
}

void test4()
{
	struct Stu s[3] = { { "zhangsan", 12 }, { "lisi", 28 }, { "wangwu", 18 } };
	int sz = sizeof(s) / sizeof(s[0]);

	Bubble_Sort1(s, sz, sizeof(s[0]), cmp_stu_name);
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}