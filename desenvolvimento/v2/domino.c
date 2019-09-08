#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
	};
	for(int i = 0; parts != NULL; i++){
		printf("[%i|%i]", parts->values[0], parts->values[1]);
		parts = parts->next;
	};
};

DominoPiece *givePiece(int *givePieces, DominoPiece *giveParts, int *receivePieces, DominoPiece *receiveParts){
	DominoPiece *auxList = giveParts;
	
	int left, right;
	srand((unsigned)time(NULL));
	int randomValue = rand() % *givePieces;
	
	for(int i = 0; i < randomValue; i++){
		left = auxList->values[0];
		right = auxList->values[1];
		if(auxList->next != NULL){
			auxList = auxList->next;

		};
	};
	
	receiveParts = insertPiece(receivePieces, receiveParts, left, right);
	giveParts = removePiece(givePieces, giveParts, left, right);
	return receiveParts;
};

DominoPiece *insertPiece(int *receivePieces, DominoPiece *receiveList, int left, int right){
	DominoPiece *newPiece = (DominoPiece*) malloc(sizeof(DominoPiece));
	newPiece->values[0] = left;
	newPiece->values[1] = right;
	
	*receivePieces += 1;
	
	// Lista vazia
	if(receiveList == NULL){
		newPiece->next = NULL;
		newPiece->prev = NULL;
		return newPiece;
	};

	DominoPiece *last, *al = receiveList;

	//while(al != NULL && al->value >= value){
	while(al != NULL){
		last = al;
		al = al->next;
	};

	// Inserção no início
	if(al == receiveList){
		newPiece->next = receiveList;
		newPiece->prev = NULL;
		receiveList->prev = newPiece;
		return newPiece;
	};

	// Inserção no final
	if(al == NULL){
		newPiece->next = NULL;
		newPiece->prev = last;
		last->next = newPiece;
		return receiveList;
	};

	//Inserção no meio
	newPiece->next = al;
	newPiece->prev = last;
	al->prev = newPiece;
	last->next = newPiece;
	return receiveList;
};

// DominoPiece *deletePiece(DominoPiece *l, int left, int right){
DominoPiece *removePiece(int *givePieces, DominoPiece *giveList, int left, int right){
	
	DominoPiece *al = giveList;

	*givePieces = *givePieces-1;
	
	// Lista vazia
	if(giveList == NULL){
		return NULL;
	};
	
	// while(al != NULL && al->value != value){
	while(left != al->values[0] || right != al->values[1]){
		al = al->next;
	};

	// Elemento não encontrado
	if(al == NULL){
		return giveList;
	};
		
	// Elemento único
	if(al->next == NULL && al->prev == NULL){
		free(al);
		return NULL;
	};

	DominoPiece *ret;

	// Exclusão no início
	if(al->prev == NULL){
		ret = al->next;
		ret->prev = NULL;
		free(al);
		return ret;
	};

	// Exclusão no final
	if(al->next == NULL){
		al->prev->next = NULL;
		free(al);
		return giveList;
	};

	// Exclusão no meio
	al->prev->next = al->next;
	al->next->prev = al->prev;
	free(al);
	return giveList;
};

DominoPiece *setTable(int playOption, int *givePieces, DominoPiece *giveParts, int *receivePieces, DominoPiece *receiveParts){
	DominoPiece *auxList = giveParts;
	
	int left, right;
	
	for(int i = 1; i <= playOption; i++){
		left = auxList->values[0];
		right = auxList->values[1];
		if(auxList->next != NULL){
			auxList = auxList->next;
		};
	};
	
	receiveParts = insertPiece(receivePieces, receiveParts, left, right);
	giveParts = removePiece(givePieces, giveParts, left, right);
	
	return receiveParts;
};
