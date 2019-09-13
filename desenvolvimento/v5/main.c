#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "domino.h"

#define LINE 10
#define COLUMN 10

int main(){
	system("title Domino - Estrura de Dados");
	system("MODE con cols=200 lines=50");

	int players = 0;
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
	printf("\e[H\e[2J");
	char auxName[6];

	dominoParts *allParts = (dominoParts*) malloc(sizeof (dominoParts));
	strcpy(auxName,"Monte");init(allParts,auxName);
	generateAllParts(allParts);
	
	dominoParts *table = (dominoParts*) malloc(sizeof (dominoParts));
	strcpy(auxName,"Mesa");init(table,auxName);
	
	dominoParts *player1 = (dominoParts*) malloc(sizeof (dominoParts));
	init(player1,name1);
	giveStartParts(allParts, player1);
	
	dominoParts *player2 = (dominoParts*) malloc(sizeof (dominoParts));
	init(player2,name2);
	giveStartParts(allParts, player2);
		
	int gameStatus = 0;
	while(gameStatus != 1){
		if(gameStatus != 1){
			gameStatus = play(player1, table, allParts);
		};
		if(gameStatus != 1){
			gameStatus = play(player2, table, allParts);
		};
	};
	
	

	
		
};