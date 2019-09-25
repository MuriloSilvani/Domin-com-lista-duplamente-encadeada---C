#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "domino.h"

int main(){
	system("title Domino - Estrura de Dados");
	system("MODE con cols=164 lines=45");
	int whileGame = 0;
	while(whileGame != 2){
		whileGame = 0;
		printf("\e[H\e[2J");

		char board[39][164];
		startTable(board);

		int players = 0;
		char name1[50], name2[50], auxName[6];

		while(players < 1 || players > 3){
			startOptions(board);
			showTable(board);
			scanf("%i%*c", &players);
		};
		if(players == 3){
			strcpy(name1,"Bot 1");
			strcpy(name2,"Bot 2");
		}else{
			int i;
			clearBottomTable(board);
			char menu0[] = "--------- Jogador 1 ---------";
			char menu1[] = " ->  Nome :   ";
			for(i = 0; i < sizeof(menu0); i++){board[25][i+1] = menu0[i];};
			for(i = 0; i < sizeof(menu1); i++){board[27][i+1] = menu1[i];};
			showTable(board);
			fflush(stdin);
			fgets(name1,255,stdin);
			if(players == 1){
				strcpy(name2,"Bot 1");
			}else{
				clearBottomTable(board);
				char menu0[] = "--------- Jogador 2 ---------";
				char menu1[] = " ->  Nome :   ";
				for(i = 0; i < sizeof(menu0); i++){board[25][i+1] = menu0[i];};
				for(i = 0; i < sizeof(menu1); i++){board[27][i+1] = menu1[i];};
				showTable(board);
				fflush(stdin);
				fgets(name2,255,stdin);
			};
		};
		printf("\e[H\e[2J");

		dominoParts *allParts = (dominoParts*) malloc(sizeof (dominoParts));
		dominoParts *table = (dominoParts*) malloc(sizeof (dominoParts));
		dominoParts *player1 = (dominoParts*) malloc(sizeof (dominoParts));
		dominoParts *player2 = (dominoParts*) malloc(sizeof (dominoParts));


		if(players == 3){
			init(player1,name1,0);
			init(player2,name2,0);
		}else{
			init(player1,name1,1);
			if(players == 1){
				init(player2,name2,0);
			}else{
				init(player2,name2,1);
			};
		};

		strcpy(auxName,"Monte");init(allParts,auxName,0);
		strcpy(auxName,"Mesa");init(table,auxName,0);
		generateAllParts(allParts);
		giveStartParts(allParts, player1);
		giveStartParts(allParts, player2);

		int gameStatus = 0;
		while(gameStatus != 1){
			if(gameStatus != 1){
				gameStatus = play(board, player1, table, allParts);
			};
			if(gameStatus != 1){
				gameStatus = play(board, player2, table, allParts);
			};
			gameStatus = verifyWinner(player1, player2, table, allParts);
		};

		while(whileGame < 1 || whileGame > 2){
			endOptions(board);
			showTable(board);
			verifyWinner(player1, player2, table, allParts);
			scanf("%i%*c", &whileGame);
		};
	};
	return 0;
};
