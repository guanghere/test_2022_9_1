#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//	��ʼ������

void Initboard(char board[ROW][COL], int row, int col)
{
	//	��ʼ���Ź����м��Ԫ��Ϊ ' '���ո�

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

//	��ӡ����

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

//	�������

void Player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�������!\n");

	while (1)
	{
		printf("����������!\n");
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//		����������һ���ո���ô��˵�����λ��û�б�ռ��
			if (board[x - 1][y - 1] == ' ')		//	��������Ҫ��1����Ϊ������±��Ǵ�0��ʼ��	
			{
				board[x - 1][y - 1] = '*';		//	��ô�Ͱѿո��滻�� * ����������µ���
				break;
			}
			else
			{
				printf("�����걻ռ�ã�����������!\n");
			}
		}

		else
		{
			printf("���������������������!\n");
		}

	}

}

//	��������

void Computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��������!\n");
	while (1)
	{
		x = rand() % row;	//	ֵΪ0��2	
		y = rand() % col;	//	ֵΪ0��2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

//	�ж�ƽ��

//ֻ���ڱ��ļ���ʹ��

static int is_full(char board[ROW][COL], int row, int col)
{
	//	���������ÿһ��Ԫ��

	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;		//		���̻�û������
			}
		}
	}

	return 1;		//		���̱�������
}

//	�ж���Ӯ

char is_win(char board[ROW][COL], int row, int col)
{
	//		�����ж����Ƿ����
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][2];
		}
	}

	//		�����ж����Ƿ����
	int j = 0;
	for (j = 0; j< col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[2][j];
		}
	}

	//		�����ж϶Խ����Ƿ����
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//		�����ж�ƽ��
	if (is_full(board, row, col) == 1)
	{
		return 'Q';
	}

	//		��Ϸ����
	return 'C';
}