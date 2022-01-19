#include "game.h"

void InitBoard(char Board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Board[i][j] = set;
		}
	}
}

void DisplayBoard(char Board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char Mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = mine;

	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (Mine[x][y] == '0')
		{
			Mine[x][y] = '1';
			count--;
		}
	}
}

int CountMine(char Mine[ROWS][COLS], int x, int y)
{
	return Mine[x - 1][y - 1] +
		Mine[x - 1][y] +
		Mine[x - 1][y + 1] +
		Mine[x][y - 1] +
		Mine[x][y + 1] +
		Mine[x + 1][y - 1] +
		Mine[x + 1][y] +
		Mine[x + 1][y + 1] - 8 * '0';
}

void OpenBoard(char Mine[ROWS][COLS], char Show[ROWS][COLS], int x, int y)
{
	int ret = CountMine(Mine, x, y);
	if (ret == 0 )
	{
		Show[x][y] = ' ';
		if (x - 1 >= 1 && x - 1 <= ROW && y - 1 >= 1 && y - 1 <= COL && Show[x - 1][y - 1] == '*')
			OpenBoard(Mine, Show, x - 1, y - 1);
		if (x - 1 >= 1 && x - 1 <= ROW && y >= 1 && y <= COL && Show[x - 1][y] == '*')
			OpenBoard(Mine, Show, x - 1, y);
		if (x - 1 >= 1 && x - 1 <= ROW && y + 1 >= 2 && y + 1 <= COL && Show[x - 1][y + 1] == '*')
			OpenBoard(Mine, Show, x - 1, y + 1);
		if (x >= 1 && x <= ROW && y - 1 >= 1 && y - 1 <= COL && Show[x][y - 1] == '*')
			OpenBoard(Mine, Show, x, y - 1);
		if (x >= 1 && x <= ROW && y + 1 >= 1 && y + 1 <= COL && Show[x][y + 1] == '*')
			OpenBoard(Mine, Show, x, y + 1);
		if (x + 1 >= 1 && x + 1 <= ROW && y - 1 >= 1 && y - 1 <= COL && Show[x + 1][y - 1] == '*')
			OpenBoard(Mine, Show, x + 1, y - 1);
		if (x + 1 >= 1 && x + 1 <= ROW && y >= 1 && y <= COL && Show[x - 1][y] == '*')
			OpenBoard(Mine, Show, x - 1, y);
		if (x + 1 >= 1 && x + 1 <= ROW && y + 1 >= 1 && y + 1 <= COL && Show[x + 1][y + 1] == '*')
			OpenBoard(Mine, Show, x + 1, y + 1);
	}
	else
	{
		Show[x][y] = ret + '0';
	}

}

int CountStar(char Show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (Show[i][j] == '*')
				count++;
		}
	}

	return count;
}

void FindMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("请输入坐标:>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (Mine[x][y] == '1')
			{
				printf("踩到雷了，游戏结束！\n");
				DisplayBoard(Mine, ROW, COL);
				break;
			}
			else
			{
				int ret = CountMine(Mine, x, y);
				Show[x][y] = ret + '0';
				OpenBoard(Mine, Show, x, y);
				DisplayBoard(Show, ROW, COL);
				int star = CountStar(Show, ROW, COL);
				if (star == mine)
				{
					printf("恭喜您，扫雷成功！");
					break;
				}
			}

		}
		else
		{
			printf("输入值非法，请重新输入！\n");
		}
	}
}