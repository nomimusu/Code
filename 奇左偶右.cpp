#include <stdio.h>

void Move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left < right)
	{
		//����ҵ�һ��ż��
		//����while����������(left<right)���ж�������Ϊ�˱��⽻����ϵ�����£��ڱ����У�left == 5, right == 6��
		//leftֵ������1,rightֵ���Լ�1��Ȼ��arr[left]��arr[right]�ٽ���һ��
		//����while����������(left<right)��left���ǻ�����1�����6����right���䣬��������left == right
		//����д��(left<=right),��Ϊ���arr���Ԫ��ȫ�������Ļ�����ôleft���յ�ֵ���right��1��������arr[left]��ʱ�����ɷǷ�����
		//���arr���Ԫ��ȫ��ż������ôright���յ�ֵ���leftС1����-1��������arr[-1]��ʱ����ɷǷ�����
		while ((left<right)&&(arr[left] % 2 == 1))
		{
			left++;
		}
		//�ұ��ҵ�һ������
		while ((left<right)&&(arr[right] % 2 == 0))
		{
			right--;
		}
		//����λ��
		int tmp = 0;
		tmp = arr[right];
		arr[right] = arr[left];
		arr[left] = tmp;
	}
}

void Display(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{	
	int arr[] = { 1,2,3,4,5,6,7,23,56,34,23 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//Move����ʵ������ҵ�һ��ż�����ұ��ҵ�һ��������Ȼ�󽻻�δ֪
	Move(arr,sz);
	//��ʾ�����Ԫ��
	Display(arr,sz);
	
	return 0;
}