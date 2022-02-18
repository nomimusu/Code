#include <stdio.h>

void Move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left < right)
	{
		//左边找到一个偶数
		//两个while函数都加上(left<right)的判断条件是为了避免交换完毕的情况下（在本例中，left == 5, right == 6）
		//left值会自增1,right值会自减1，然后arr[left]和arr[right]再交换一次
		//两个while函数都加上(left<right)后，left还是会自增1，变成6，但right不变，所以最终left == right
		//不能写成(left<=right),因为如果arr里的元素全是奇数的话，那么left最终的值会比right大1，当访问arr[left]的时候会造成非法访问
		//如果arr里的元素全是偶数，那么right最终的值会比left小1，即-1，当访问arr[-1]的时候造成非法访问
		while ((left<right)&&(arr[left] % 2 == 1))
		{
			left++;
		}
		//右边找到一个奇数
		while ((left<right)&&(arr[right] % 2 == 0))
		{
			right--;
		}
		//交换位置
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
	//Move函数实现左边找到一个偶数，右边找到一个奇数，然后交换未知
	Move(arr,sz);
	//显示数组的元素
	Display(arr,sz);
	
	return 0;
}