#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "domino.h"


int main(int argc, char** argv){
	
	// system("title Domino - Estrura de Dados");
	// system("MODE con cols=200 lines=50");
		
int x = 0;
while(x<1){
	x++;

	int haveWinner = 0, players = 0;
	char name1[50], name2[50];

	while(players < 1 || players > 2){
		printf("Numero de Jogadores [1 - 2]: ");
		// scanf("%i", &players);
		players = 1;
	};
	printf("Nome do jogador 1: ");
	// fgets(name1, 50, stdin);
	strcpy(name1,"Murilo");
	if(players == 2){
		printf("Nome do jogador 2: ");
		// fgets(name2, 50, stdin);
	}else{
		strcpy(name2,"Jordan");
	};
	
	printf("\n\njogador 1: %s\njogador 2: %s", name1, name2);
	
	printf("\n\n\n");
	// system("pause");
	
	
	dominoParts* allParts = (dominoParts*) malloc(sizeof (dominoParts));
	init(allParts,"Monte");
	generateAllParts(allParts);
	
	dominoParts* table = (dominoParts*) malloc(sizeof (dominoParts));
	init(table,"Mesa");
	
	dominoParts* player1 = (dominoParts*) malloc(sizeof (dominoParts));
	init(player1,name1);
	giveStartParts(allParts, player1);
	// giveRandomPiece(allParts, player1);
	
	dominoParts* player2 = (dominoParts*) malloc(sizeof (dominoParts));
	init(player2,name2);
	giveStartParts(allParts, player2);
	

	while((player1->startPiece != NULL || player2->startPiece != NULL) && haveWinner != 1){
		int checkPlay = 0;
		
		// startGame(allParts, player1, player2);
		
		// printf("----- Monte   [pecas: %i] ------\n", allParts->total);
		// showParts(allParts);
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
					};
					
					showParts(player1);
					
					checkPlay = play(player1, table);	
				
				haveWinner = checkWinner(player1, table);
			};
		};checkPlay = 0;
		
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
					};
					
					showParts(player2);
					
					checkPlay = play(player2, table);	
				
				haveWinner = checkWinner(player2, table);	
			};
		};checkPlay = 0;
	};
};
		
	printf("\n\n\n\nACABOU     \n\n\n\n");
	// system("pause");
	return 0;
};