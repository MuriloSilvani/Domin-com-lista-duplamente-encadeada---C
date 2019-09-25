#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "domino.h"

DominoPiece *init(int *numberPieces, DominoPiece *parts){
	// printf("Status: Inicia init\n");
	for(int i = 0; i < 7; i++){
		for(int j = 0; j <= i; j++){
			parts = insertPiece(numberPieces, parts, i, j);
		};
	};
	return parts;
};

DominoPiece *createPiece(int leftValue, int rightValue){
	// printf("Status: Inicia createPiece\n");
	DominoPiece *novaPecaPiece = (DominoPiece*) calloc(sizeof(DominoPiece),1);
	novaPecaPiece->values[0] = leftValue;
	novaPecaPiece->values[1] = rightValue;
	printf("[%i|%i]\n", novaPecaPiece->values[0], novaPecaPiece->values[1]);
	return novaPecaPiece;
};

void showPieces(DominoPiece *parts){
	// printf("Status: Inicia showPieces\n");
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
	// printf("Status: Inicia givePiece\n");
	DominoPiece *auxList = giveParts;

	int left, right;
	srand((unsigned)time(NULL));
	int randomValue = rand() % (*givePieces+1);
	printf("RANDOM: %i\n", randomValue);
	for(int i = 0; i <= randomValue; i++){
		left = auxList->values[0];
		right = auxList->values[1];
		if(auxList->next != NULL){
			auxList = auxList->next;
		}else{
			if(auxList->prev != NULL){
				auxList = auxList->prev;
			}else{
				auxList = NULL;
			};
		};
	};
	
	
	
	

	receiveParts = insertPiece(receivePieces, receiveParts, left, right);
	giveParts = removePiece(givePieces, giveParts, left, right);
	return receiveParts;
};

DominoPiece *insertPiece(int *receivePieces, DominoPiece *receiveList, int left, int right){
	// printf("Status: Inicia insertPiece\n");
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

	// Inser��o no in�cio
	if(al == receiveList){
		newPiece->next = receiveList;
		newPiece->prev = NULL;
		receiveList->prev = newPiece;
		return newPiece;
	};

	// Inser��o no final
	if(al == NULL){
		newPiece->next = NULL;
		newPiece->prev = last;
		last->next = newPiece;
		return receiveList;
	};

	//Inser��o no meio
	newPiece->next = al;
	newPiece->prev = last;
	al->prev = newPiece;
	last->next = newPiece;
	return receiveList;
};

// DominoPiece *deletePiece(DominoPiece *l, int left, int right){
DominoPiece *removePiece(int *givePieces, DominoPiece *giveList, int left, int right){
	printf("Status: Inicia removePiece\n");

	DominoPiece *al = NULL;
	al = giveList;

	*givePieces = *givePieces-1;
	
	showPieces(giveList);
	printf("\nStatus: DELETANDO [%i|%i]\n", left, right);
	

	// Lista vazia
	if(giveList == NULL){
		printf("Status: DELETA LISTA VAZIA\n");
		return NULL;
	};

	// while(al != NULL && al->value != value){
	while(left != al->values[0] || right != al->values[1]){
		al = al->next;
	};

	// Elemento n�o encontrado
	if(al == NULL){
		printf("Status: DELETA NAO ENCONTRADO\n");
		return giveList;
	};

	// Elemento �nico
	if(al->next == NULL && al->prev == NULL){
		printf("Status: DELETA ELEMENTO UNICO\n");
		free(al);
		return NULL;
	};

	DominoPiece *ret;

	// Exclus�o no in�cio
	if(al->prev == NULL){
		printf("Status: DELETA INICIO\n");
		ret = al->next;
		ret->prev = NULL;
		free(al);
		return ret;
	};

	// Exclus�o no final
	if(al->next == NULL){
		printf("Status: DELETA FINAL\n");
		al->prev->next = NULL;
		free(al);
		return giveList;
	};

	// Exclus�o no meio
	printf("Status: DELETA MEIO\n");
	al->prev->next = al->next;
	al->next->prev = al->prev;
	free(al);
	
	return giveList;
};

DominoPiece *setTable(int playOption, int *givePieces, DominoPiece *giveParts, int *receivePieces, DominoPiece *receiveParts){
	// printf("Status: Inicia setTable\n");
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
