#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "domino.h"

void init(dominoParts *parts){
	parts->startPiece = NULL;
	parts->total = 0;
};

void generateAllParts(dominoParts *parts){
	for(int i = 0; i <= 6; i++){
		for(int j = 0; j <= i; j++){
			insertPiece(parts, i, j);
		};
	};
};

void showParts(dominoParts *parts){
    dominoPiece *showParts = parts->startPiece;
    if(showParts == NULL){
		printf("Sem pecas!\n");
	}else{
	    while(showParts != NULL){
		   printf("[%i|%i] ", showParts->values[0], showParts->values[1]);
	       showParts = showParts->next;
	    };
	    printf("\nTotal: %i\n", parts->total);
	};
};

void insertPiece(dominoParts *parts, int left, int right){
    dominoPiece *novo;
    novo = (dominoPiece*)malloc(sizeof(dominoPiece)); //aloca um espaco do tamanho de node
    novo->values[0] = left;
    novo->values[1] = right;
    novo->prev  = NULL;
    novo->next  = NULL;
    if(parts->startPiece == NULL){
        parts->startPiece = novo;
    }else{
        dominoPiece *last = parts->startPiece;
        while(last->next != NULL){
            last = last->next;
        };
        last->next = novo;
        novo->prev = last;
    };
    parts->total += 1;
};

void removePiece(dominoParts *parts, int left, int right){
    dominoPiece *last = parts->startPiece;
    while((last != NULL) && (last->values[0] != left || last->values[1] != right)){
        last = last->next;
    };
    if(last == NULL) {
        printf("Peça não encontrada!");
        system("PAUSE");
    }else{
        if(last->prev == NULL && last->next == NULL){
            parts->startPiece = NULL;
        }else{
            if(last->prev == NULL){
                parts->startPiece = last->next;
                last->next->prev = NULL;   
            }else{
                if(last->next == NULL){
                    last->prev->next = NULL;
                }else{
                    last->prev->next = last->next;
                };
            };
        };
        parts->total -= 1;
        free(last);
    };
};

void giveStartParts(dominoParts *giveParts, dominoParts *receiveParts){
	while(receiveParts->total < 7){
		giveRandomPiece(giveParts, receiveParts);
	};
};

void giveRandomPiece(dominoParts *giveParts, dominoParts *receiveParts){
	dominoPiece *auxList = giveParts->startPiece;	
	srand((unsigned)time(NULL));
	int randomValue = (rand() % giveParts->total);
	int left = auxList->values[0], right = auxList->values[1];
	int i = 0;
	while(i <= randomValue){
		left = auxList->values[0];
		right = auxList->values[1];
		auxList = auxList->next;
		i++;
	};
	insertPiece(receiveParts, left, right);
	removePiece(giveParts, left, right);
};