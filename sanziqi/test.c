
#include "game.h"

void game()
{
	char ret = 0;
	//����һ��������������������
	char board[ROW][COL];
	//��ʼ�����̣���ʼ��Ϊ�ո�
	Initboard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//��ʼ����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		Computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret  = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	if (ret == 'Q')
	{
		printf("ƽ��\n");
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
		printf("��ѡ���Ƿ������Ϸ\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
				break;
		default:
			printf("������������������\n");

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