#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*********************\n");
	printf("****** 1.play  ******\n");
	printf("****** 0.over  ******\n");
	printf("*********************\n");
}
void game()		//	��Ϊ�Ǵ��Σ�����Ҫ����ROW��COL
{
	//	����is_win�ķ�������

	char ret = 0;

	//	������������
	char board[ROW][COL] = { 0 };

	//	��ʼ������Ϊȫ�ո�

	Initboard(board, ROW, COL);

	//	��ӡ����

	Displayboard(board, ROW, COL);

	while (1)
	{
		//	�������

		Player_move(board, ROW, COL);

		//	�������ӡһ��
		Displayboard(board, ROW, COL);

		//	���ж�һ����Ӯ
		ret = is_win(board, ROW, COL);
		if (ret != 'C')			//	����'C'������������'C'������ʤ����һ������ƽ��
		{
			break;
		}

		//	��������
		Computer_move(board, ROW, COL);

		//	�������ӡһ��
		Displayboard(board, ROW, COL);

		//	���ж�һ����Ӯ
		ret = is_win(board, ROW, COL);
		if (ret != 'C')			//	����'C'������������'C'������ʤ����һ������ƽ��
		{
			break;
		}
	}
	//		break������������

	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}

//		��Ϸ����
//
//		���Ӯ---'*'
// 
//		����Ӯ---'#'
// 
//		ƽ��---'Q'
// 
//		����---'C'
//




void test()
{
	int input = 0;	//	��ʼ��
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);	//	����
		switch (input)		//	����ʹ��input��ԭ���Ǹ��������ֵ�����Ӧ��case���
		{
		case 1:
			//		������������������Ϸ
			game();
			printf("����Ϸ!\n");
			break;
		case 0:
			printf("ѡ���˳�,��Ϸ����!\n");
			break;
		default:
			printf("ѡ�����,����������!\n");
			break;
		}
	} while (input);	//		����ʹ��input��ԭ���Ǹ���input�ж��Ƿ����,����������1 Ϊ�棨������,���� 0Ϊ�٣�������

}

int main()
{
	test();

	return 0;
}