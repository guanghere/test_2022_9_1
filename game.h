#pragma once

#include<stdio.h>
#include<stdlib.h>		//	srand
#include<time.h>		//	time

#define ROW 3
#define COL 3

//	初始化棋盘		棋盘			      行   	   列

void Initboard(char board[ROW][COL], int row, int col);


//		打印棋盘

void Displayboard(char board[ROW][COL], int row, int col);


//	玩家下棋

void Player_move(char board[ROW][COL], int row, int col);


//	电脑下棋

void Computer_move(char board[ROW][COL], int row, int col);


//	判断输赢

char is_win(char board[ROW][COL], int row, int col);