#include <stdio.h>
#include <stdlib.h>

typedef struct DominoPiece {
	int esq, dir;
	struct DominoPiece *prev, *next;
} DominoPiece;

DominoPiece *init(){
	return NULL;
}

DominoPiece *insertPiece(DominoPiece *l, int left, int right){
	DominoPiece *newPiece = malloc(sizeof(DominoPiece));
	newPiece->esq = left;
	newPiece->dir = right;
	
	// Lista vazia
	if(l == NULL){
		newPiece->next = NULL;
		newPiece->prev = NULL;
		return newPiece;
	}

	DominoPiece *last, *al = l;

	
	//while(al != NULL && al->value >= value){
	while(al != NULL){
		last = al;
		al = al->next;
	}

	// Inserção no início
	if(al == l){
		newPiece->next = l;
		newPiece->prev = NULL;
		l->prev = newPiece;
		return newPiece;
	}

	// Inserção no final
	if(al == NULL){
		newPiece->next = NULL;
		newPiece->prev = last;
		last->next = newPiece;
		return l;
	}

	//Inserção no meio
	newPiece->next = al;
	newPiece->prev = last;
	al->prev = newPiece;
	last->next = newPiece;

	return l;
}

DominoPiece *deletePiece(DominoPiece *l, int left, int right){
	DominoPiece *al = l;

	// Lista vazia
	if(l == NULL){
		printf("deleta lista vazia");
		return NULL;
	};
	printf("vai delatar [%i|%i]\n\n", left, right);
	//while(al != NULL && al->value != value){
	while(al != NULL && (al->esq != left && al->dir != right)){
		
		printf("nao deletou [%i|%i]\n", al->esq, al->dir);
		al = al->next;	
	};

	// Elemento não encontrado
	if(al == NULL){
		printf("deleta nao encontrado");
		return l;
	};
		
	// Elemento único
	if(al->next == NULL && al->prev == NULL){
		printf("deleta elemento unico");
		printf("\n\ndeletado [%i|%i]", al->esq, al->dir);
		free(al);
		return NULL;
	};

	DominoPiece *ret;

	// Exclusão no início
	if(al->prev == NULL){
		printf("deleta no inicio");
		printf("\n\ndeletado [%i|%i]", al->esq, al->dir);
		ret = al->next;
		ret->prev = NULL;
		free(al);
		return ret;
	};

	// Exclusão no final
	if(al->next == NULL){
		printf("deleta no final");
		printf("\n\ndeletado [%i|%i]", al->esq, al->dir);
		al->prev->next = NULL;
		free(al);
		return l;
	};

	// Exclusão no meio
	printf("deleta no meio");
	printf("\n\ndeletado [%i|%i]", al->esq, al->dir);
	al->prev->next = al->next;
	al->next->prev = al->prev;
	free(al);

	return l;
}

void print_list(DominoPiece *l){
	if(l == NULL){
		printf("A lista nao contem itens.\n");
		return;
	};

	int i;
	DominoPiece *last;

	for(i = 0; l != NULL; l = l->next, i++){
		last = l;
		printf("[%i|%i]", l->esq, l->dir);
	};
	printf("\n");

}

int main(){
	DominoPiece *l = init();

	int i, j;
	for(i = 0; i < 7; i++){
		for(j = 0; j <= i; j++){
			l = insertPiece(l, i, j);
		};
	};

	printf("\n");
	print_list(l);
	printf("\n");
	
	l = deletePiece(l, 6, 6);

	printf("\n");
	printf("\n");
	print_list(l);

	return 0;
}