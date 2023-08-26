
#include "game.h"

void game()
{
	char ret = 0;
	//创建一个数组来储存棋盘内容
	char board[ROW][COL];
	//初始化棋盘，初始化为空格
	Initboard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//开始下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		Computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret  = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	if (ret == 'Q')
	{
		printf("平局\n");
	}
}
void menu()
{
	printf("**************************\n");
	printf("**** 1. play  0. exit ****\n");
	printf("**************************\n");
}
void test()
{
	int input = 0;
	do 
	{
		menu();
		printf("请选择是否进入游戏\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
				break;
		default:
			printf("输入有误，请重新输入\n");

			break;
		}
	} while (input);
}
int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}