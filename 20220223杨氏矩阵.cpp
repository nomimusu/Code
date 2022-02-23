#include <stdio.h>

//算法思想：如果要找的数字k大于右上角的数（本题中右上角的数最开始的坐标为[0][2]），那么也就是说右上角的数所在的行，肯定就没有要找的数,往下一行查找
//如果要找的数字k小于右上角的数（本题中右上角的数最开始的坐标为[0][2]），那么也就是说右上角的数所在的列，肯定就没有要找的数,往下一列查找
int FindNum(int arr[3][3], int* px, int* py, int k)
{
	//因为是跟右上角的数对比，从第一行开始
	int x = 0;
	//因为是跟右上角的数对比，所以从最后一列开始
	int y = *py - 1;

	//随着对比的进行，会从上到下或从右到左进行查找，所以x<=2, y>=0
	while (x <= 2 && y >= 0)
	{
		if (k < arr[x][y])
		{
			y--;
		}
		else if (k > arr[x][y])
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}

	return 0;

}

int main()
{
	int arr[3][3] = { { 1, 4, 5 }, { 3, 8, 11}, { 7, 9, 15} };
	int k = 4;
	int x = 3;
	int y = 3;
	int ret = FindNum(arr, &x, &y, k);
	if (1 == ret)
	{
		printf("找到了\n");
		printf("下标：%d %d\n", x, y);
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}