#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

//�����Ƿ񿪱��ڴ�ռ�ɹ�
//int main()
//{
//	int* p = (int*)malloc(10*sizeof(int));
//	//��������ڴ�ռ�ʧ��
//	if (NULL == p)
//	{
//		printf("�����ڴ�ռ�ʧ��\n");
//		printf("%s\n", strerror(errno));
//	}
//	//������ٿռ�ɹ�
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	//p = NULL;
//
//	return 0;
//}

//int main()
//{
//	int* p = (int*)calloc(40,sizeof(int));
//	if (p == NULL)
//	{
//		printf("��̬�ڴ�ռ�δ���ٳɹ�\n");
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//
//	int*p2 = (int*)realloc(p, 500);
//	if (p2 != NULL)
//	{
//		int i = 0;
//		for (i = 10; i < 20; i++)
//		{
//			*(p2 + i) = i;
//		}
//		for (i = 10; i < 20; i++)
//		{
//			printf("%d ", *(p2 + i));
//		}
//	}
//
//	return 0;
//}

//����һ����

//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//}

//Bug 1 �� ���г��򣬳�������
//	GetMemory(str),���Ĳ���str�ĵ�ַ������str����NULL������ָ��p��ָ��str��һ����ʱ����
//  (char*)malloc(100)������100���ֽڵĶ�̬�ڴ�ռ䣬������ǿ��ת��Ϊ(char*),
//   p = (char*)malloc(100),��ָ��pָ��(char*)malloc(100)���ٵ�100���ֽڵĶ�̬�ڴ�ռ䣬��ʱp������ǿ��ٵĶ�̬�ڴ�ռ�ĵ�ַ
//  ����Ϊp��GetMemory�������βα��������������GetMemory�����ڲ�������GetMemory�����Ͳ����ˣ����Բ���Ӱ��ָ��strָ��Ŀռ�
//   strcpy�ǰ�hello world��������ָ����ָ����ǿ�ռ䣬����ָ��û��ָ��һ����Ч�ռ䣬strcpy�������޷���hello world������ȥ��
//   �൱���ǶԿ�ָ����н����ã����Գ������
//Bug 2 �� ��������ڴ�й©
//	GetMemory�����ڲ�ʹ����malloc()������������һ�鶯̬�ڴ�ռ䣬���ǲ�û�ж����ͷţ����ҳ���GetMemory������ָ��malloc()���ٵ�
//  ��̬�ڴ�ռ��ָ��pҲ��ʧЧ��Ҳ����˵�����Ǿ��Ҳ�����鿪�ٺõĶ�̬�ڴ�ռ�

//Debug ����1 : �����ٵĶ�̬�ڴ�ռ䱣�浽strָ��
//    �����Ҫ��GetMemory�������濪�ٵĶ�̬�ڴ�ռ�ĵ�ַ����strָ�룬��ôGetMemory�������βξ���Ҫ�ܹ�����strָ��ĵ�ַ
//    ����GetMemory�������²ξ���Ҫ�Ƕ���ָ��
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//}

// Debug ����2 : Ϊ�˱���ָ��p��GetMemory���������ý���֮����ʧ�����Կ��԰�GetMemory�����ķ���ֵ��Ϊָ��p��Ȼ��ָ��p��ֵ��strָ��

//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//}

//���������

//char* GetMemory(void)
//{
//	static char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//}

//ԭ��˼·	
//		p���ַ����飬return p ---> ����sizeof��& + ������������p����Ԫ�ص�ַ��GetMemory�����ķ���ֵ������Ԫ�ص�ַ
//      ���ַ�����p����Ԫ�ص�ַ����strָ�룬Ȼ���ӡ�����Ի��ӡ�ַ�'h'

// Bug ������ջ�ռ��ַ����
//       �ַ�����p����GetMemory�����ڲ���Ч����GetMemory�������ý���֮�����洴�����ַ�����p���ڴ�ռ�ͻ᷵�ظ�����ϵͳ
//       ��Ȼ���ַ�����p�ĵ�ַ���ݸ���strָ�룬���ַ�����p���ڴ�ռ��Ѿ����ظ�����ϵͳ��
//		 ��ʱ�������ͨ��strָ��ȥ�����ַ�����p���ڴ�ռ䣬�ͻ���ɷǷ�����

// Debug��"p���ַ����飬return p ---> ����sizeof��& + ������������p����Ԫ�ص�ַ��GetMemory�����ķ���ֵ������Ԫ�ص�ַ" ----->
//         return p �е�p���ȿ���������p��Ҳ����������p����Ԫ�ص�ַ
//		   ��GeoMemory�����У�������p��߼��Ϲؼ���static����������p�Ŀռ�ʹ�ջ���Ƶ��˾�̬����
//		   ��������GeoMemory���ý����Ժ�����p�Ŀռ�Ҳ���ỹ������ϵͳ

// #���������ʹ��һ���ṹ������һ��Ԫ��������δ֪��С�����飬��С��������顱��Ա���ṹ���е�һ��Ԫ�������������Ա��

//struct S{
//	int n;
//	int arr[0];
//};
//
//int main()
//{
//	//struct S s;
//	//printf("%d\n", sizeof(s));

	//����һ�鶯̬�ڴ�ռ䣬����malloc�����ķ���ֵ������ת��Ϊstruct S*,�ýṹ��ָ��������
	//sizeof(struct S)��n���õĿռ䣬5*sizeof(int)����������int arr[0]���õĿռ�
//	struct S* ps = (struct S*)(malloc(sizeof(struct S) + 5 * sizeof(int)));
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//�Ҿ��ø�int arr[0]�����5*sizeof(int)�Ŀռ䲻���� ϣ�����10*sizeof(int)�Ŀռ�
//	struct S* ptr = (struct S*)(realloc(ps,44));
//	//��Ϊrealloc�����п��ܷ���NULL��δ�ر���Կ�ָ����н����ã�����Ҫ�ȼ��һ��
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	return 0;
//}

// #���������ʹ�ö����ṹ������һ��Ԫ��������δ֪��С�����飬��С��������顱��Ա���ṹ���е�һ����Ա��ָ�룬��ָ��ָ��һ�鶯̬�ڴ�ռ䣬
//ʵ����������Ĺ��ܣ�

struct S{
	int n;
	int* arr;
};

int main()
{
	//ʹ��malloc��������һ�鶯̬�ڴ�ռ䣬�ǽṹ��struct S�Ĵ�С
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	//ʹ�ó�Աint* arr��ָ��һ�鶯̬�ڴ�ռ�
	ps->arr = (int*)(malloc(5 * sizeof(int)));
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	//ͨ��realloc������ָ��arrָ����ǿ鶯̬�ڴ�ռ�Ĵ�С��������Ϊ44���ֽ�
	int* ptr = (int*)realloc(ps->arr, 44);
	//realloc�����п��ܷ���NULL��Ϊ�˱���Կ�ָ������ã�Ҫ�ȼ��һ�£�
	if (ptr != NULL)
	{
		ps->arr = ptr;
		for (i = 5; i < 10; i++)
		{
			ps->arr[i] = i;
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);

	}
	//�Կ��ٵĶ�̬�ڴ�ռ�����ͷţ���Ϊps->arrָ����Ǵ�СΪ10*sizeof(int)���ڴ�ռ䣬���ܹ���ɾ���ṹ��ָ��ps���ڵĶ�̬�ڴ�ռ�
	//����ͻ��Ҳ�����СΪ10*sizeof(int)���ڴ�ռ�
	//ɾ��֮��Ϊ�˱���Ƿ����ʣ���ps->arr����ΪNULL
	free(ps->arr);
	ps->arr = NULL; 
	free(ps);
	ps = NULL;
	return 0;
}