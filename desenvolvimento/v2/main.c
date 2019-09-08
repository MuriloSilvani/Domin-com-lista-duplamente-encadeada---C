#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "domino.h"

int main() {

	// printf("\n\nJogo de domino\n\n\n");
	
		
	int choose = 1;
			
	while(choose != 3){
		// system("cls");
		// 
		// printf("\t ------ Menu de Jogo ------\n");
		// printf("\t 1 - Jogar Domino\n");
		// printf("\t 2 - Historioco de Jogos\n");
		// printf("\t 3 - Sair do Jogo\n\n");
		// 
		// printf("\t Selecione uma Opcao:  ");
		// scanf("%d", &choose);
		// 
		// system("cls");

		
		
			
		int deckPieces = 0;
		int tablePieces = 0;
		DominoPiece *deckParts = NULL;
		deckParts = init(&deckPieces, deckParts);
		DominoPiece *tableParts = NULL;
		
		int player1Pieces = 0;
		DominoPiece *player1Parts = NULL;
		
		int player2Pieces = 0;
		DominoPiece *player2Parts = NULL;
		
		
		while(player1Pieces < 7){
			player1Parts = givePiece(&deckPieces, deckParts, &player1Pieces, player1Parts);
		};
		while(player2Pieces < 7){
			player2Parts = givePiece(&deckPieces, deckParts, &player2Pieces, player2Parts);
		};

		// 
		// int left;
		// int right;		
		// while(deckPieces > 0){
// 
			// printf("left ");
		// 	scanf("%d %d", &left, &right);
			// printf("right ");
			// scanf("%d", &right);
		// 	
		// 	
		// 	
		// 	player1Parts = insertPiece(&player1Pieces, player1Parts, left, right);
		// 	deckParts = removePiece(&deckPieces, deckParts, left, right);
		// 	
		// 	
		// 	system("cls");
		// 	printf("-------Baralho [Total: %i] -------\n\n", deckPieces);
		// 	showPieces(deckParts);
		// 	printf("\n\n");
		// 	printf("-------Jogador 1 [Total: %i] -------\n\n", player1Pieces);
		// 	showPieces(player1Parts);
		// 	printf("\n\n");
		// 	printf("-------Jogador 2 [Total: %i] -------\n\n", player2Pieces);
		// 	showPieces(player2Parts);
		// 	printf("\n\n");
		// 	printf("-------Mesa [Total: %i] -------\n\n", tablePieces);
		// 	showPieces(tableParts);
		// 	printf("\n\n");	
		// 	
		// 	
			// system("pause");
		// };

			
		int turnPlayer = 1;
		while(player1Pieces > 0 || player2Pieces > 0){
			int playOption = 0;
			
			system("cls");
			printf("-------Baralho [Total: %i] -------\n\n", deckPieces);
			showPieces(deckParts);
			printf("\n\n");
			printf("-------Jogador 1 [Total: %i] -------\n\n", player1Pieces);
			showPieces(player1Parts);
			printf("\n\n");
			printf("-------Jogador 2 [Total: %i] -------\n\n", player2Pieces);
			showPieces(player2Parts);
			printf("\n\n");
			printf("-------Mesa [Total: %i] -------\n\n", tablePieces);
			showPieces(tableParts);
			printf("\n\n");
			
			
			if(turnPlayer == 1){
				printf("---- Jogador 1 ----\nEscolha uma peca:   ");
				scanf("%i", &playOption);
				tableParts = setTable(playOption, &player1Pieces, player1Parts, &tablePieces, tableParts);				
				turnPlayer = 2;
			}else{
				printf("---- Jogador 2 ----\nEscolha uma peca:   ");
				scanf("%i", &playOption);
				tableParts = setTable(playOption, &player2Pieces, player2Parts, &tablePieces, tableParts);				
				turnPlayer = 1;
			};		
			
			
		};
		
		
		
		printf("\n\tFim de jogo\n\n\t");
		system("pause");
		
	};
	


	
		
	
	




	
	
    return 0;
};