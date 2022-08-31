#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*********************\n");
	printf("****** 1.play  ******\n");
	printf("****** 0.over  ******\n");
	printf("*********************\n");
}
void game()		//	因为是传参，所以要带上ROW和COL
{
	//	接收is_win的返回类型

	char ret = 0;

	//	存放下棋的数据
	char board[ROW][COL] = { 0 };

	//	初始化棋盘为全空格

	Initboard(board, ROW, COL);

	//	打印棋盘

	Displayboard(board, ROW, COL);

	while (1)
	{
		//	玩家下棋

		Player_move(board, ROW, COL);

		//	下完棋打印一下
		Displayboard(board, ROW, COL);

		//	再判断一下输赢
		ret = is_win(board, ROW, COL);
		if (ret != 'C')			//	等于'C'继续，不等于'C'就是有胜利的一方或者平局
		{
			break;
		}

		//	电脑下棋
		Computer_move(board, ROW, COL);

		//	下完棋打印一下
		Displayboard(board, ROW, COL);

		//	再判断一下输赢
		ret = is_win(board, ROW, COL);
		if (ret != 'C')			//	等于'C'继续，不等于'C'就是有胜利的一方或者平局
		{
			break;
		}
	}
	//		break结束跳到这里

	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}

}

//		游戏结束
//
//		玩家赢---'*'
// 
//		电脑赢---'#'
// 
//		平局---'Q'
// 
//		继续---'C'
//




void test()
{
	int input = 0;	//	初始化
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);	//	输入
		switch (input)		//	这里使用input的原因是根据输入的值进入对应的case语句
		{
		case 1:
			//		假设这里有三子棋游戏
			game();
			printf("玩游戏!\n");
			break;
		case 0:
			printf("选择退出,游戏结束!\n");
			break;
		default:
			printf("选择错误,请重新输入!\n");
			break;
		}
	} while (input);	//		这里使用input的原因是根据input判断是否继续,如果输入的是1 为真（继续）,否则 0为假（结束）

}

int main()
{
	test();

	return 0;
}