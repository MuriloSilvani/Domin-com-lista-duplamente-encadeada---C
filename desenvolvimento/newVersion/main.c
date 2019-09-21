#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "domino.h"

int main(){
	system("title Domino - Estrura de Dados");
	system("MODE con cols=164 lines=50");

	char board[43][163];
	generateTable(board);

	int whileGame = 0;

	while(whileGame != 2){
		printf("\e[H\e[2J");
		int players = 0;
		char name1[50], name2[50], auxName[6];

		while(players < 1 || players > 3){
			printf("--------- Modo de Jogo ---------\n\n");
			printf("-> 1 : Um jogador\n");
			printf("-> 2 : Dois jogadores\n");
			printf("-> 3 : Jogadores Autonomos\n\n-> Escolha uma opcao: ");
			scanf("%i%*c", &players);
		};
		if(players == 3){
			strcpy(name1,"Bot 1");
			strcpy(name2,"Bot 2");
		}else{
			printf("\e[H\e[2J");
			fflush(stdin);
			printf("---------- Jogador 1: ----------\n\n-> Nome: ");
			fgets(name1,255,stdin);
			if(players == 1){
				strcpy(name2,"Bot 1");
			}else{
				printf("\e[H\e[2J");
				fflush(stdin);
				printf("---------- Jogador 2: ----------\n\n-> Nome: ");
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
				gameStatus = play(player1, table, allParts, board);
			};
			printf("saiu montar tabela\n");getchar();
			if(gameStatus != 1){
				gameStatus = play(player2, table, allParts, board);
			};
			gameStatus = verifyWinner(player1, player2, table, allParts, board);
		};



		verifyWinner(player1, player2, table, allParts, board);
		printf("\n\n\n");

		while(whileGame < 1 || whileGame > 2){
			printf("--------- Fim de Jogo ---------\n\n");
			printf("-> 1 : Jogar novamente\n");
			printf("-> 2 : Sair do Jogo\n");
			scanf("%i%*c", &whileGame);
		};
	};
	return 0;
};
