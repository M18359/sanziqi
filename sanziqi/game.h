#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Initboard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row,int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void Computermove(char board[ROW][COL], int row, int col);

//玩家赢返回*  电脑赢返回#  平局返回Q  继续游戏返回c
char IsWin(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);

