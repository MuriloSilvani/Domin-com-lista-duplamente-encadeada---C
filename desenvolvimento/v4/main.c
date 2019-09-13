#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "domino.h"

#define LINE 10
#define COLUMN 10

int main(int argc, char** argv){
	system("title Domino - Estrura de Dados");
	system("MODE con cols=200 lines=50");

	int haveWinner = 0, players = 0;
	char name1[50], name2[50];

	while(players < 1 || players > 2){
		printf("Numero de Jogadores [1 - 2]: ");
		// scanf("%i", &players);
		players = 1;
	};
	// fflush(stdin);
	printf("Nome do jogador 1: ");
	// fgets(name1,255,stdin);
	strcpy(name1,"Jogador 1");
	if(players == 2){
		// fflush(stdin);
		printf("Nome do jogador 2: ");
		// fgets(name2,255,stdin);
		strcpy(name2,"Jogador 2");
	}else{
		strcpy(name2,"Computador");
	};
	
	char auxName[6];
	
	dominoParts* allParts = (dominoParts*) malloc(sizeof (dominoParts));
	strcpy(auxName,"Monte");init(allParts,auxName);
	generateAllParts(allParts);
	
	dominoParts* table = (dominoParts*) malloc(sizeof (dominoParts));
	strcpy(auxName,"Mesa");init(table,auxName);
	
	dominoParts* player1 = (dominoParts*) malloc(sizeof (dominoParts));
	init(player1,name1);
	giveStartParts(allParts, player1);
	
	dominoParts* player2 = (dominoParts*) malloc(sizeof (dominoParts));
	init(player2,name2);
	giveStartParts(allParts, player2);
	

	while((player1->startPiece != NULL && player2->startPiece != NULL)){
	
		system("pause");
		
		int checkPlay = 0;
		while(checkPlay == 0){
			if(haveWinner != 1){
				system("cls");
				printf("----- Mesa    [pecas: %i] ------\n\n", table->total);
				showParts(table);
				printf("\n");
					printf("----- Vez de %s -----\n\n", player1->name);
					if(checkPlay == 2){
						printf("Esta peca nao pode ser usada!!!\n");
						checkPlay = 0;
						system("pause");
					};
					checkPlay = play(player1, table, allParts);
				haveWinner = checkWinner(player1, table);
			}else{
				checkPlay = 1;
			};
		};checkPlay = 0;
		system("pause");
		while(checkPlay == 0){
			if(haveWinner != 1){
				system("cls");
				printf("----- Mesa    [pecas: %i] ------\n\n", table->total);
				showParts(table);
				printf("\n");
					printf("----- Vez de %s -----\n\n", player2->name);
					if(checkPlay == 2){
						printf("Esta peca nao pode ser usada!!!\n");
						checkPlay = 0;
						system("pause");
					};
					checkPlay = play(player2, table, allParts);	
				haveWinner = checkWinner(player2, table);	
			}else{
				checkPlay = 1;
			};
		};checkPlay = 0;
	};
		
	printf("\n\n\n\n  ACABOU  \n\n\n\n");
	return 0;
};