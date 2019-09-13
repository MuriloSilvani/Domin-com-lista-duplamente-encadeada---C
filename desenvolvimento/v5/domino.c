#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

	printf("---------- %s [%i pecas] ----------\n\n", parts->name, parts->total);
    if(showParts == NULL){
		printf("Sem pecas!");
	}else{
	    while(showParts != NULL){
		   printf("[%i|%i] ", showParts->values[0], showParts->values[1]);
	       showParts = showParts->next;
	    };
	};
	printf("\n\n");
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

void insertPiece(dominoParts *parts, int left, int right){
    dominoPiece *newPiece;
    newPiece = (dominoPiece*)malloc(sizeof(dominoPiece));
    newPiece->values[0] = left;
    newPiece->values[1] = right;
    newPiece->prev = NULL;
    newPiece->next = NULL;
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

void insertPieceStart(dominoParts *parts, int left, int right){
    dominoPiece *newPiece;
    newPiece = (dominoPiece*)malloc(sizeof(dominoPiece));
    newPiece->values[0] = left;
    newPiece->values[1] = right;
    newPiece->prev = NULL;
    newPiece->next = parts->startPiece;

    parts->startPiece = newPiece;

    parts->total += 1;
};

bool play(dominoParts *player, dominoParts *table, dominoParts *allParts){
	int playChoose = 0;
	while((playChoose < 1 || playChoose > player->total)){
		system("cls");
		
		showParts(table);
		showParts(player);
		
		printf("Escolha uma peca [de 1 a %i]  ", player->total);
		scanf("%i", &playChoose);			
		
		if(verifyPiece(player, table, playChoose) == 1){
			playPiece(player, table, playChoose);
			
			printf("ja devia ter jogado\n\n");
			system("pause");
		}else{
			printf("Tente outra peca...\n");
			system("pause");
			playChoose = 0;
		};
		
		

		
		// tiver ganharodr retorna 1
		if(player->startPiece == NULL){
			printf("\n\n\t %s Foi o Vencedor!!!!!!\n\n", player->name);
			return 1;
		};
	};
	return 0;
};

void playPiece(dominoParts *player, dominoParts *table, int playChoose){
	
	dominoPiece *auxPiece = player->startPiece;
	int left = auxPiece->values[0];
	int right = auxPiece->values[1];

	if(table->startPiece != NULL){
		int first, last;
		searchFirstLast(table, &first, &last);
		
		int auxNum = 1;
		while(auxNum <= playChoose){
			left = auxPiece->values[0];
			right = auxPiece->values[1];
			auxPiece = auxPiece->next;
			auxNum++;
		};
		
		if(table->startPiece == NULL){
					printf("1\n");
			insertPiece(table, left, right);
			removePiece(player, left, right);
		}else{
			if((left == first || right == first) && (left == last || right == last)){
				int chooseSide = 0;
				printf("Aonde inserir a peca?\n");
				printf("\t1 - Inicio\n");
				printf("\t2 - Fim\n");
				scanf("%i", &chooseSide);
				
				if(chooseSide == 1){
					if(left == first){
					printf("2\n");
						insertPieceStart(table, right, left);
						removePiece(player, left, right);
					}else if(right == first){
					printf("3\n");
						insertPieceStart(table, left, right);
						removePiece(player, left, right);
					};
				};
				if(chooseSide == 2){
					if(left == last){
					printf("4\n");
						insertPiece(table, left, right);
						removePiece(player, left, right);
					}else if(right == last){
					printf("5\n");
						insertPiece(table, right, left);
						removePiece(player, left, right);
					};
				};
			}else{
				if(left == first){
					printf("6\n");
					insertPieceStart(table, right, left);
					removePiece(player, left, right);
				}else if(right == first){
					printf("7\n");
					insertPieceStart(table, left, right);
					removePiece(player, left, right);
				}else if(left == last){
					printf("8\n");
					insertPiece(table, left, right);
					removePiece(player, left, right);
				}else if(right == last){
					printf("9\n");
					insertPiece(table, right, left);
					removePiece(player, left, right);
				};
			};
		};	
	}else{
		insertPiece(table, left, right);
		removePiece(player, left, right);
					printf("10\n");
	};
};

bool verifyPiece(dominoParts *player, dominoParts *table, int playChoose){
	if(table->startPiece == NULL){
		return 1;
	}else{
		int first = 0, last = 0;
		searchFirstLast(table, &first, &last);
		
		dominoPiece *auxPiece = player->startPiece;
		int auxNum = 0;
		while(auxNum <= playChoose && auxPiece->next != NULL){
			auxPiece = auxPiece->next;
			auxNum++;
		};
		if(auxPiece->values[0] == first || auxPiece->values[1] == first || auxPiece->values[0] == last || auxPiece->values[1] == last){
			return 1;
		}else{
			return 0;
		};
	};
	return 0;
};

void searchFirstLast(dominoParts *table, int *first, int *last){
	dominoPiece *auxPiece = table->startPiece;
	*first = auxPiece->values[0];
	while(auxPiece->next != NULL){
		auxPiece = auxPiece->next;
	};
	*last = auxPiece->values[1];
};
