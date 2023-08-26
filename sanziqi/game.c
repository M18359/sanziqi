
#include "game.h"

void Initboard(char board[ROW][COL], int row, int col)//ROW\COL是数，row\col是形参
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//打印数据
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
			/*if (j < col - 1)
			{
				printf(" %c |", board[j][i]);
			}
			if (j == col - 1)
			{
				printf("%c\n", board[j][i]);
			}*/
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			int j = 0;
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

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋：>\n");
	while (1)
	{
		printf("玩家请输入坐标：");
		scanf("%d %d", &x, &y);
		//坐标合法性判断
		if (x>=1&&x <= row &&y>=1&& y <= col)//x,y从1开始
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';

				break;
			}
			else
			{
				printf("此位置已被占有，请重新输入\n");
			}
		}
		else
		{
			printf("坐标超出棋盘范围，请重新输入！\n");
		}
	}
}

void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋:>\n");
	while (1)
	{
		x = rand() % row;//0-2
		y = rand() % col;//0-2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//玩家赢返回*  电脑赢返回#  平局返回Q  继续游戏返回c
char IsWin(char board[ROW][COL], int row, int col)
{
	//行赢
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0]!=' ')
		{
			return board[i][0];
		}
	}
	//列赢
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//对角赢
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//平局--棋盘已满且行列对角都未赢
	//判断棋盘是否满--满返回1，未满返回0
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	//继续
	return 'C';
}


int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}