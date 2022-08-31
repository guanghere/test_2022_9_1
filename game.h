#pragma once

#include<stdio.h>
#include<stdlib.h>		//	srand
#include<time.h>		//	time

#define ROW 3
#define COL 3

//	��ʼ������		����			      ��   	   ��

void Initboard(char board[ROW][COL], int row, int col);


//		��ӡ����

void Displayboard(char board[ROW][COL], int row, int col);


//	�������

void Player_move(char board[ROW][COL], int row, int col);


//	��������

void Computer_move(char board[ROW][COL], int row, int col);


//	�ж���Ӯ

char is_win(char board[ROW][COL], int row, int col);