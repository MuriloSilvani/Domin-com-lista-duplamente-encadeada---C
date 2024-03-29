#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "domino.h"

#define LINE 45
#define COLUMN 113


void drawnH(char board[LINE][COLUMN], int *nextY, int *nextX, int left, int right){
	for(int i = *nextX; i < (*nextX+5); i++){
		for(int j = *nextY; j < (*nextY+17); j++){
			if((i == *nextX && j != *nextY && j != (*nextY+16)) || (i == *nextX+4 && j != *nextY && j != (*nextY+16))){
				board[i][j] = '-';	
			};
			if((j == *nextY && i != *nextX && i != (*nextX+4)) || (j == *nextY+16 && i != *nextX && i != (*nextX+4)) || (j == (*nextY+8) && i != *nextX && i != (*nextX+4))){
				board[i][j] = '|';	
			};
		};
	};
	if(left == 1){
		board[*nextX+2][*nextY+4] = '0';
	};
	if(left == 2){
		board[*nextX+1][*nextY+4] = '0';
		board[*nextX+3][*nextY+4] = '0';
	};
	if(left == 3){
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+2][*nextY+4] = '0';
		board[*nextX+3][*nextY+6] = '0';
	};
	if(left == 4){
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
	};
	if(left == 5){
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
		board[*nextX+2][*nextY+4] = '0';
	};
	if(left == 6){
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+1][*nextY+4] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+3][*nextY+4] = '0';
		board[*nextX+3][*nextY+6] = '0';
	};
	if(right == 1){
		board[*nextX+2][*nextY+12] = '0';
	};
	if(right == 2){
		board[*nextX+1][*nextY+12] = '0';
		board[*nextX+3][*nextY+12] = '0';
	};
	if(right == 3){
		board[*nextX+1][*nextY+10] = '0';
		board[*nextX+2][*nextY+12] = '0';
		board[*nextX+3][*nextY+14] = '0';
	};
	if(right == 4){
		board[*nextX+1][*nextY+10] = '0';
		board[*nextX+1][*nextY+14] = '0';
		board[*nextX+3][*nextY+10] = '0';
		board[*nextX+3][*nextY+14] = '0';
	};
	if(right == 5){
		board[*nextX+1][*nextY+10] = '0';
		board[*nextX+1][*nextY+14] = '0';
		board[*nextX+3][*nextY+10] = '0';
		board[*nextX+3][*nextY+14] = '0';
		board[*nextX+2][*nextY+12] = '0';
	};
	if(right == 6){
		board[*nextX+1][*nextY+10] = '0';
		board[*nextX+1][*nextY+12] = '0';
		board[*nextX+1][*nextY+14] = '0';
		board[*nextX+3][*nextY+10] = '0';
		board[*nextX+3][*nextY+12] = '0';
		board[*nextX+3][*nextY+14] = '0';
	};
};

void drawnV(char board[LINE][COLUMN], int *nextY, int *nextX, int left, int right){
	for(int i = *nextX; i < (*nextX+9); i++){
		for(int j = *nextY; j < (*nextY+9); j++){
			if((i == *nextX && j != *nextY && j != (*nextY+8)) || (i == *nextX+4 && j != *nextY && j != (*nextY+8)) || (i == *nextX+8 && j != *nextY && j != (*nextY+8))){
				board[i][j] = '-';	
			};
			if((j == *nextY && i != *nextX && i != (*nextX+8)) || (j == *nextY+8 && i != *nextX && i != (*nextX+8))){
				board[i][j] = '|';	
			};
		};
	};
	if(left == 1){
		board[*nextX+2][*nextY+4] = '0';
	};
	if(left == 2){
		board[*nextX+2][*nextY+2] = '0';
		board[*nextX+2][*nextY+6] = '0';
	};
	if(left == 3){
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+2][*nextY+4] = '0';
		board[*nextX+1][*nextY+6] = '0';
	};
	if(left == 4){
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
	};
	if(left == 5){
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
		board[*nextX+2][*nextY+4] = '0';
	};
	if(left == 6){
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
		board[*nextX+2][*nextY+2] = '0';
		board[*nextX+2][*nextY+6] = '0';
	};
	if(right == 1){
		board[*nextX+4][*nextY+4] = '0';
	};
	if(right == 2){
		board[*nextX+6][*nextY+2] = '0';
		board[*nextX+6][*nextY+6] = '0';
	};
	if(right == 3){
		board[*nextX+7][*nextY+2] = '0';
		board[*nextX+6][*nextY+4] = '0';
		board[*nextX+5][*nextY+6] = '0';
	};
	if(right == 4){
		board[*nextX+7][*nextY+2] = '0';
		board[*nextX+5][*nextY+6] = '0';
		board[*nextX+5][*nextY+2] = '0';
		board[*nextX+7][*nextY+6] = '0';
	};
	if(right == 5){
		board[*nextX+7][*nextY+2] = '0';
		board[*nextX+5][*nextY+6] = '0';
		board[*nextX+5][*nextY+2] = '0';
		board[*nextX+7][*nextY+6] = '0';
		board[*nextX+6][*nextY+4] = '0';
	};
	if(right == 6){
		board[*nextX+7][*nextY+2] = '0';
		board[*nextX+5][*nextY+6] = '0';
		board[*nextX+5][*nextY+2] = '0';
		board[*nextX+7][*nextY+6] = '0';
		board[*nextX+6][*nextY+2] = '0';
		board[*nextX+6][*nextY+6] = '0';
	};
};

void drawnPiece(char board[LINE][COLUMN], int *nextX, int *nextY, int left, int right){
	
	
	if(
		((*nextX == 1) && ( *nextY == 10)) ||
		((*nextX == 1) && ( *nextY == 28))
	){
		drawnV(board, nextX, nextY, left, right);
		*nextY = *nextY + 9;
		return;
	};
	if(
		((*nextX == 103) && ( *nextY == 1)) ||
		((*nextX == 103) && ( *nextY == 19))
	){
		drawnV(board, nextX, nextY, left, right);
		*nextX = *nextX - 8;
		*nextY = *nextY + 9;
		return;
	};
	if(
		((*nextX == 10) && ( *nextY == 28))
	){
		drawnH(board, nextX, nextY, right, left);
		*nextX = *nextX - 9;
		return;
	};
	if(
		((*nextX == 10) && ( *nextY == 10))
	){
		drawnH(board, nextX, nextY, left, right);
		*nextX = *nextX - 9;
		return;
	};
	
	if(
		((*nextX == 95) && ( *nextY == 10)) ||
		((*nextX == 78) && ( *nextY == 10)) ||
		((*nextX == 61) && ( *nextY == 10)) ||
		((*nextX == 44) && ( *nextY == 10)) ||
		((*nextX == 27) && ( *nextY == 10)) ||
		((*nextX == 95) && ( *nextY == 28)) ||
		((*nextX == 78) && ( *nextY == 28)) ||
		((*nextX == 61) && ( *nextY == 28)) ||
		((*nextX == 44) && ( *nextY == 28)) ||
		((*nextX == 27) && ( *nextY == 28))
	){
		drawnH(board, nextX, nextY, right, left);
		*nextX = *nextX - 17;
		return;
	};
	
	if(
		((*nextX == 1) && ( *nextY == 1)) ||
		((*nextX == 18) && ( *nextY == 1)) ||
		((*nextX == 35) && ( *nextY == 1)) ||
		((*nextX == 52) && ( *nextY == 1)) ||
		((*nextX == 69) && ( *nextY == 1)) ||
		((*nextX == 86) && ( *nextY == 1)) ||
		((*nextX == 1) && ( *nextY == 19)) ||
		((*nextX == 18) && ( *nextY == 19)) ||
		((*nextX == 52) && ( *nextY == 19)) ||
		((*nextX == 35) && ( *nextY == 19)) ||
		((*nextX == 69) && ( *nextY == 19)) ||
		((*nextX == 86) && ( *nextY == 19))
	){
		drawnH(board, nextX, nextY, left, right);
		*nextX = *nextX + 17;
		return;
	};
};

int main(){
	system("title Domino - Estrura de Dados");
	system("MODE con cols=200 lines=50");

	
	int total = 1;
	while(total != 0){
	
	char board[LINE][COLUMN];
	for(int i = 0; i < LINE; i++){
		for(int j = 0; j < COLUMN; j++){
			if((i == 0 && j != 0 && j != COLUMN-1) || (i == LINE-1 && j != 0 && j != COLUMN-1)){
				board[i][j] = '-';
			}else if((j == 0 && i != 0 && i != LINE-1) || (j == COLUMN-1 && i != 0 && i != LINE-1)){
				board[i][j] = '|';
			}else{
				board[i][j] = ' ';
			};
		};		
	};
	///////////////////////////////////////////////////////////////////////////
	
	int nextX = 1;
	int nextY = 1;
	int pecas = 0;
	
	
	// printf("quantas pecas: \n");
	// scanf("%d", &total);
	// total=14;
	
	for(int i = 0; i < 7; i++){
		for(int j = 0; j <= i; j++){
			// if(pecas < total){
				printf("vai desenhar em %i %i\n", nextX, nextY);
				drawnPiece(board, &nextX, &nextY, i, j);
				// pecas = pecas+1;
			// };
		};
	};

	
	
	
	
	
	
	///////////////////////////////////////////////////////////////////////////
	for(int i = 0; i < LINE; i++){
		for(int j = 0; j < COLUMN; j++){
			printf("%c", board[i][j]);
		};		
		printf("\n");
	};
	
	
	system("pause");
	system("cls");
	
	};
	
	return 0;
};