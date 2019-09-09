#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domino.h"

int main() {
	int deckPieces = 0;
	int tablePieces = 0;
	int player1Pieces = 0;
	int player2Pieces = 0;

	DominoPiece *deckParts = NULL;
	DominoPiece *tableParts = NULL;
	DominoPiece *player1Parts = NULL;
	DominoPiece *player2Parts = NULL;
	
	deckParts = init(&deckPieces, deckParts);
	
	while(player1Pieces < 7){
		player1Parts = givePiece(&deckPieces, deckParts, &player1Pieces, player1Parts);
	};
	while(player2Pieces < 7){
		player2Parts = givePiece(&deckPieces, deckParts, &player2Pieces, player2Parts);
	};
	
	
	
	
	
	printf("-------Baralho [Total: %i] -------\n\n", deckPieces);
	showPieces(deckParts);
	printf("\n");
	printf("-------Mesa [Total: %i] -------\n\n", tablePieces);
	showPieces(tableParts);
	printf("\n");
	printf("-------Jogador 1 [Total: %i] -------\n\n", player1Pieces);
	showPieces(player1Parts);
	printf("\n");
	printf("-------Jogador 2 [Total: %i] -------\n\n", player2Pieces);
	showPieces(player2Parts);
	printf("\n");
	
    return 0;
};