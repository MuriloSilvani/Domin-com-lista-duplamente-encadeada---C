#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "domino.h"

void init(dominoParts *parts, char name[50], int type){
	parts->startPiece = NULL;
	parts->total = 0;
	parts->type = type;
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
        printf("Peca nao encontrada!");
        if(parts->type == 1){
			system("pause");
		};
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
	if(giveParts->startPiece != NULL){
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
	}else{
		printf("Sem pecas para pescar\n");
		if(receiveParts->type == 1){
			system("pause");
		};
	};
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

int play(dominoParts *player, dominoParts *table, dominoParts *allParts){
	int playChoose = 0;
	while((playChoose < 1 || playChoose > player->total)){
		printf("\e[H\e[2J");
		// showParts(table);
		showParts(player);
		
		if(verifyParts(player, table) == 1){
			printf("Escolha uma peca [de 1 a %i]  ", player->total);
			if(player->type == 1){
				scanf("%i", &playChoose);
			}else{
				playAuto(player, table, &playChoose);
			};
		}else{
			printf("Pescando peca...\n");
			if(player->type == 1){
				system("pause");
			};
			giveRandomPiece(allParts, player);
			if(verifyParts(player, table) == 1){
				printf("Escolha uma peca [de 1 a %i]  ", player->total);
				if(player->type == 1){
					scanf("%i", &playChoose);
				}else{
					playAuto(player, table, &playChoose);
				};
			}else{
				printf("Passou a vez, ja pescou e nao tem pecas\n");
				if(player->type == 1){
					system("pause");
				};
				return 0;
			};
		};

		if(verifyPiece(player, table, playChoose) == 1){
			playPiece(player, table, playChoose);
		}else{
			printf("Peca Invalidade, tente outra...\n");
			if(player->type == 1){
				system("pause");
			};
			playChoose = 0;
		};
		
		if(player->startPiece == NULL){
			return 1;
		};
	};
	return 0;
};

void playPiece(dominoParts *player, dominoParts *table, int playChoose){
	system("pause");
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
			insertPiece(table, left, right);
			removePiece(player, left, right);
		}else{
			if((left == first || right == first) && (left == last || right == last)){
				int chooseSide = 0;
				if(player->type == 1){
					printf("Aonde inserir a peca?\n");
					printf("-> 1 : Inicio\n");
					printf("-> 2 : Fim\n");
					scanf("%i", &chooseSide);
				}else{
					chooseSide = 2;
				};
				
				if(chooseSide == 1){
					if(left == first){
						insertPieceStart(table, right, left);
						removePiece(player, left, right);
					}else if(right == first){
						insertPieceStart(table, left, right);
						removePiece(player, left, right);
					};
				};
				if(chooseSide == 2){
					if(left == last){
						insertPiece(table, left, right);
						removePiece(player, left, right);
					}else if(right == last){
						insertPiece(table, right, left);
						removePiece(player, left, right);
					};
				};
			}else{
				if(left == first){
					insertPieceStart(table, right, left);
					removePiece(player, left, right);
				}else if(right == first){
					insertPieceStart(table, left, right);
					removePiece(player, left, right);
				}else if(left == last){
					insertPiece(table, left, right);
					removePiece(player, left, right);
				}else if(right == last){
					insertPiece(table, right, left);
					removePiece(player, left, right);
				};
			};
		};	
	}else{
		insertPiece(table, left, right);
		removePiece(player, left, right);
	};
};

int verifyPiece(dominoParts *player, dominoParts *table, int playChoose){
	if(table->startPiece == NULL){
		return 1;
	}else{
		int first = 0, last = 0;
		searchFirstLast(table, &first, &last);
		
		dominoPiece *auxPiece = player->startPiece;
		int auxNum = 1;
		while(auxNum < playChoose){
			if(auxPiece->next != NULL){
				auxPiece = auxPiece->next;
			};
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

void playAuto(dominoParts *player, dominoParts *table, int *playChoose){
	dominoPiece *auxList = player->startPiece;
	int auxCount = 1;
	while(auxList->next != NULL){
		if(verifyPiece(player, table, auxCount) == 1){
			*playChoose = auxCount;
			return;
		};
		auxList = auxList->next;
		auxCount++;
	};
};

int verifyParts(dominoParts *player, dominoParts *table){
	if(table->startPiece == NULL){
		return 1;
	}else{
		int first, last;
		searchFirstLast(table, &first, &last);
		
		dominoPiece *auxList = player->startPiece;
		if(auxList->values[0] == first || auxList->values[1] == first || auxList->values[0] == last || auxList->values[1] == last){
			return 1;
		};
		while(auxList->next != NULL){
			if(auxList->values[0] == first || auxList->values[1] == first || auxList->values[0] == last || auxList->values[1] == last){
				return 1;
			};
			auxList = auxList->next;
		};
		return 0;
	};
	return 0;
};

int verifyWinner(dominoParts *player1, dominoParts *player2, dominoParts *table, dominoParts *allParts){
	if(player1->startPiece == NULL){
		printf("----- %s ganhou -----", player1->name);
		return 1;
	};
	if(player2->startPiece == NULL){
		printf("----- %s ganhou -----", player2->name);
		return 1;
	};
	if(allParts->startPiece != NULL){
		return 0;
	}else{
		if((verifyParts(player1, table) == 0) && (verifyParts(player2, table) == 0)){
			if(player1->total == player2->total){
				printf("----- Empate -----\n");
			};
			if(player1->total < player2->total){
				printf("----- %s ganhou -----", player1->name);
			};
			if(player2->total < player1->total){
				printf("----- %s ganhou -----", player2->name);
			};
			return 1;
		}else{
			return 0;
		};
		return 0;
	};
	return 0;
};








