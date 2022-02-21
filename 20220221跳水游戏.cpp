//#跳水比赛猜名次
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;

	//对a,b,c,d,e五位选手的所有名词进行穷举，包括所有人或一部分人同名次的情况
	for (a = 1; a<= 5; a++)
	{
		for (b = 1; b<= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						//判断条件1：因为每位选手都说对了一半，所以每位选手所说的名次一个是真，为1；一个是假，为0；得分为1
						if ((a == 3) + (b == 2) == 1 &&
							(b == 2) + (e == 4) == 1 &&
							(c == 1) + (d == 2) == 1 &&
							(d == 3) + (c == 5) == 1 &&
							(e == 4) + (a == 1) == 1)
							//判断条件2:第1-5名分别只有1人，所以名次相乘的积为1*2*3*4*5 == 120
						if (a*b*c*d*e == 120)
							printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);

					}
				}
			}
		}
	}
	return 0;
}