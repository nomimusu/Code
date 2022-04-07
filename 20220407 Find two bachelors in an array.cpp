#include <stdio.h>

void Find_Bachlors(int arr[], int sz)
{
	int num = 0;
	int bachlor1 = 0;
	int bachlor2 = 0;
	int i = 0;

	//Xor all elments in array and return the result to varible num
	//The result is equivalent to bachlor1 xor bachlor2
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}

	//The result of bachlor1 xor bachlor2 must have at least one non-zero bit
	//Find the postion of one non-zero bit
	int j = 0;
	for (j = 0; j < 32; j++)
	{
		if (((num >> j) & 1) == 1)
			break;
	}

	//Divide all elements in an array into two groups based on the position of one non-zero bit of
	//Xor all elements in one group whose bit value is 1 on the position 
	//The result is bachlor 1
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> j) & 1) == 1)
			bachlor1 ^= arr[i];
	}

	bachlor2 = num^bachlor1;

	printf("%d %d", bachlor1, bachlor2);
}

int main()
{
	int arr[8] = { 1, 2, 3, 4, 1, 2, 3, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Find_Bachlors(arr, sz);
	return 0;
}