#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "domino.h"

void init(dominoParts *parts, char name[50]){
	parts->startPiece = NULL;
	parts->total = 0;
	strcpy(parts->name,name);
};

void generateAllParts(dominoParts *parts){
	for(int i = 0; i <= 6; i++){
		for(int j = 0; j <= i; j++){
			insertPiece(parts, i, j);
			giveRandomPiece(parts, parts);
		};
	};
};

void showParts(dominoParts *parts){
    dominoPiece *showParts = parts->startPiece;
    if(showParts == NULL){
		printf("Sem pecas!\n\n");
	}else{
	    while(showParts != NULL){
		   printf("[%i|%i] ", showParts->values[0], showParts->values[1]);
	       showParts = showParts->next;
	    };
	    // printf("\nTotal: %i", parts->total);
	    printf("\n\n");
	};
};

void insertPiece(dominoParts *parts, int left, int right){
    dominoPiece *newPiece;
    newPiece = (dominoPiece*)malloc(sizeof(dominoPiece));
    newPiece->values[0] = left;
    newPiece->values[1] = right;
    newPiece->prev  = NULL;
    newPiece->next  = NULL;
    if(parts->startPiece == NULL){
        parts->startPiece = newPiece;
    }else{
        dominoPiece *last = parts->startPiece;
        while(last->next != NULL){
            last = last->next;
        };
        last->next = newPiece;
        newPiece->prev = last;
    };
    parts->total += 1;
};

void removePiece(dominoParts *parts, int left, int right){
    dominoPiece *last = parts->startPiece;
    while((last != NULL) && ((last->values[0] != left || last->values[1] != right) && (last->values[0] != right || last->values[1] != left))){
        last = last->next;
    };
    if(last == NULL){
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
            if(last->next == NULL){
                last->prev->next = NULL;   
            }else{
                if(last->prev == NULL){
                    last->next->prev = NULL;
                }else{
                    last->next->prev = last->prev;
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

int checkWinner(dominoParts *player, dominoParts *table){
	if(player->startPiece == NULL){
		system("cls");
		printf("----- Mesa    [pecas: %i] ------\n\n", table->total);
		showParts(table);
		printf("\n");
		
		printf("%s Foi o Vencedor!!!!!\n", player->name);
		return 1;
	};
	return 0;
};

void pickFirstLast(int *firstTable, int *lastTable, dominoParts *table){
	dominoPiece *auxPiece = table->startPiece;
	if(auxPiece != NULL){
		*firstTable = auxPiece->values[0];
		while(auxPiece->next != NULL){
			auxPiece = auxPiece->next;
		};
		*lastTable = auxPiece->values[1];
	};
};

int play(dominoParts *player, dominoParts *table){
	int choosePiece = 0;
	while(choosePiece < 1 || choosePiece > player->total){
		printf("Escolha uma peca [1 - %i]\n", player->total);
		scanf("%i", &choosePiece);
		if(choosePiece < 1 || choosePiece > player->total){
			printf("\nEscolha uma peca valida...\n");	
		};
	};
	dominoPiece *auxList = player->startPiece;	
	int left, right;
	int i = 1;
	while(i <= choosePiece){
		left = auxList->values[0];
		right = auxList->values[1];
		auxList = auxList->next;
		i++;
	};
	
	int firstTable, lastTable;
	pickFirstLast(&firstTable, &lastTable, table);
	
	if(table->startPiece != NULL){
		if((left == firstTable || right == firstTable) && (left == lastTable || right == lastTable)){
			int chooseSide = 0;
			printf("Aonde inserir a peca?\n");
			printf("\t1 - Inicio\n");
			printf("\t2 - Fim\n");
			scanf("%i", &chooseSide);
			
			if(chooseSide == 1){
				if(left == firstTable){
					table = insertPieceStart(table, left, right);
					removePiece(player, left, right);
					return 1;
				};	
				if(right == firstTable){
					table = insertPieceStart(table, right, left);
					removePiece(player, left, right);
					return 1;
				};
			};
			if(chooseSide == 2){
				if(left == lastTable){
					insertPiece(table, left, right);
					removePiece(player, left, right);
					return 1;
				};	
				if(right == lastTable){
					insertPiece(table, right, left);
					removePiece(player, left, right);
					return 1;
				};
			};
		}else{
			if(left == firstTable){
				table = insertPieceStart(table, right, left);
				removePiece(player, left, right);
				return 1;
			};
			if(right == firstTable){
				table = insertPieceStart(table, left, right);
				removePiece(player, left, right);
				return 1;
			};
			if(left == lastTable){
				insertPiece(table, left, right);
				removePiece(player, left, right);
				return 1;
			};	
			if(right == lastTable){
				insertPiece(table, right, left);
				removePiece(player, left, right);
				return 1;
			};
		};
	}else{
		insertPiece(table, left, right);
		removePiece(player, left, right);
		return 1;
	};
	return 2;
};

dominoPiece *insertPieceStart(dominoParts *parts, int left, int right){

	// dominoPiece *newPiece = (dominoPiece*) malloc(sizeof(dominoPiece));
	// newPiece->values[0] = left;
	// 
	// newPiece->next = parts->startPiece;
	// newPiece->prev = NULL;
	// parts->startPiece->prev = newPiece;
	// 	
	// 
 //    parts->total += 1;
 //    
 //    return newPiece;
    
    return parts->startPiece;
    
};




