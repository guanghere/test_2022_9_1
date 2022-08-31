#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//	初始化棋盘

void Initboard(char board[ROW][COL], int row, int col)
{
	//	初始化九宫格中间的元素为 ' '（空格）

	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//	打印棋盘

void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");

		}
	}
}

//	玩家下棋

void Player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋!\n");

	while (1)
	{
		printf("请输入坐标!\n");
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//		如果输入的是一个空格，那么就说明这个位置没有被占用
			if (board[x - 1][y - 1] == ' ')		//	玩家输入的要减1，因为数组的下标是从0开始的	
			{
				board[x - 1][y - 1] = '*';		//	那么就把空格替换成 * 来当作玩家下的棋
				break;
			}
			else
			{
				printf("该坐标被占用，请重新输入!\n");
			}
		}

		else
		{
			printf("坐标输入错误，请重新输入!\n");
		}

	}

}

//	电脑下棋

void Computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋!\n");
	while (1)
	{
		x = rand() % row;	//	值为0到2	
		y = rand() % col;	//	值为0到2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

//	判断平局

//只能在本文件下使用

static int is_full(char board[ROW][COL], int row, int col)
{
	//	遍历数组的每一个元素

	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;		//		棋盘还没被下满
			}
		}
	}

	return 1;		//		棋盘被下满了
}

//	判断输赢

char is_win(char board[ROW][COL], int row, int col)
{
	//		用来判断行是否相等
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][2];
		}
	}

	//		用来判断列是否相等
	int j = 0;
	for (j = 0; j< col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[2][j];
		}
	}

	//		用来判断对角线是否相等
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//		用来判断平局
	if (is_full(board, row, col) == 1)
	{
		return 'Q';
	}

	//		游戏继续
	return 'C';
}