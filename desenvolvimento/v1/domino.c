#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domino.h"

DominoPiece *init(int *numberPieces, DominoPiece *parts){
	for(int i = 0; i < 7; i++){
		for(int j = 0; j <= i; j++){
			parts = insertPiece(numberPieces, parts, i, j);
		};
	};
	return parts;
};

DominoPiece *createPiece(int leftValue, int rightValue){
	DominoPiece *novaPecaPiece = (DominoPiece*) calloc(sizeof(DominoPiece),1);
	novaPecaPiece->values[0] = leftValue;
	novaPecaPiece->values[1] = rightValue;
	printf("[%i|%i]\n", novaPecaPiece->values[0], novaPecaPiece->values[1]);
	return novaPecaPiece;
};

void showPieces(DominoPiece *parts){
	
	if(parts == NULL){
		printf("A lista nao contem itens\n");
		return;
	}
	
	DominoPiece *last = NULL;

	for(int i = 0; parts != NULL; parts = parts->next, i++){
		last = parts;
	};
	parts = last;
	for(int i = 0; parts != NULL; i++){
		printf("[%i|%i]", parts->values[0], parts->values[1]);
		parts = parts->prev;
	};
};

DominoPiece *givePiece(int *givePieces, DominoPiece *giveParts, int *receivePieces, DominoPiece *receiveParts){

	int randomValue = rand() % *givePieces;
	
	receiveParts = insertPiece(receivePieces, receiveParts, giveParts[randomValue].values[0], giveParts[randomValue].values[1]);
	
	// *givePieces = *givePieces-1;
			
			
	return receiveParts;
};

DominoPiece *insertPiece(int *receivePieces, DominoPiece *receiveList, int left, int right){
	DominoPiece *newPiece = (DominoPiece*) malloc(sizeof(DominoPiece));
	newPiece->values[0] = left;
	newPiece->values[1] = right;
	
	*receivePieces += 1;
	
	if(receiveList == NULL){
		newPiece->next = NULL;
		newPiece->prev = NULL;
		return newPiece;
	}else{
		newPiece->next = receiveList;
		newPiece->prev = NULL;
		receiveList->prev = newPiece;
		return newPiece;    
	}
	return receiveList;
};