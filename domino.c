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
	int i, j;
	for(i = 0; i <= 6; i++){
		for(j = 0; j <= i; j++){
			insertPiece(parts, i, j);
			giveRandomPiece(parts, parts);
		};
	};
};

void showParts(dominoParts *parts){
    dominoPiece *showParts = parts->startPiece;

	printf("---------- VEZ DE: %s [%i pecas] ----------\n\n", parts->name, parts->total);

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
        printf("Peca nao encontrada! Pressione qualquer tecla para continuar...");
        if(parts->type == 1){
			getchar();
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
		printf("Sem pecas para pescar. Pressione qualquer tecla para continuar...\n");
		if(receiveParts->type == 1){
			getchar();
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

int play(char board[39][164], dominoParts *player, dominoParts *table, dominoParts *allParts){
	int playChoose = 0;
	while((playChoose < 1 || playChoose > player->total)){
		drawnTable(board, table);
		drawnPlayerParts(player, board);

		if(verifyParts(player, table) == 1){
			if(player->type == 1){
				int i;
				char aux[2];
				sprintf(aux, "%i", player->total);
				char menu0[] = "Escolha uma peca de 1 a ";
				strcat(menu0, aux);
				for(i = 0; i < sizeof(menu0); i++){board[26][i+1] = menu0[i];};
				showTable(board);
				printf("----- Vez de %s\n -->\t:", player->name);
				scanf("%i%*c", &playChoose);
			}else{
				showTable(board);
				playAuto(player, table, &playChoose);
			};
		}else{
			giveRandomPiece(allParts, player);
			if(player->type == 1){
				char menu0[] = "Pescando peca. Pressione qualquer tecla para continuar...";
				int i;
				for(i = 0; i < sizeof(menu0); i++){board[26][i+1] = menu0[i];};
				showTable(board);
				printf("----- Vez de %s\n -->\t:", player->name);
				getchar();
			};
			if(verifyParts(player, table) == 1){
				if(player->type == 1){
					int i;
					char aux[2];
					sprintf(aux, "%i", player->total);
					char menu0[] = "Escolha uma peca de 1 a ";
					strcat(menu0, aux);
					for(i = 0; i < sizeof(menu0); i++){board[26][i+1] = menu0[i];};
					showTable(board);
					printf("----- Vez de %s\n -->\t:", player->name);
					scanf("%i%*c", &playChoose);
				}else{
					showTable(board);
					playAuto(player, table, &playChoose);
				};
			}else{
				if(player->type == 1){
					int i;
					char menu0[] = "Passou a vez, ja pescou e nao tem pecas. Pressione qualquer tecla para continuar...";
					for(i = 0; i < sizeof(menu0); i++){board[26][i+1] = menu0[i];};
					showTable(board);
					printf("----- Vez de %s\n -->\t:", player->name);
					getchar();
				}else{
					showTable(board);
				};
				return 0;
			};
		};

		if(verifyPiece(player, table, playChoose) == 1){
			playPiece(player, table, playChoose);
		}else{
			int i;
			char menu0[] = "Peca Invalidade, tente outra...";
			for(i = 0; i < sizeof(menu0); i++){board[26][i+1] = menu0[i];};
			showTable(board);
			playChoose = 0;
		};

		if(player->startPiece == NULL){
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
			insertPiece(table, left, right);
			removePiece(player, left, right);
		}else{
			if((left == first || right == first) && (left == last || right == last)){
				int chooseSide = 0;
				if(player->type == 1){
					printf("Aonde inserir a peca?\n");
					printf("-> 1 : Inicio\n");
					printf("-> 2 : Fim\n");
					scanf("%i%*c", &chooseSide);
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
		printf("\n----- GANHADOR: %s\n", player1->name);
		return 1;
	};
	if(player2->startPiece == NULL){
		printf("\n----- GANHADOR: %s\n", player2->name);
		return 1;
	};
	if(allParts->startPiece != NULL){
		return 0;
	}else{
		if((verifyParts(player1, table) == 0) && (verifyParts(player2, table) == 0)){
			if(player1->total == player2->total){
				printf("\n----- EMPATE\n");
			};
			if(player1->total < player2->total){
				printf("\n----- GANHADOR: %s\n", player1->name);
			};
			if(player2->total < player1->total){
				printf("\n----- GANHADOR: %s\n", player2->name);
			};
			return 1;
		}else{
			return 0;
		};
		return 0;
	};
	return 0;
};

void drawnH(char board[39][164], int *nextY, int *nextX, int left, int right){
	int i, j;
	for(i = *nextX; i < (*nextX+5); i++){
		for(j = *nextY; j < (*nextY+17); j++){
			if((i == *nextX && j != *nextY && j != (*nextY+16)) || (i == *nextX+4 && j != *nextY && j != (*nextY+16))){
				board[i][j] = '-';
			};
			if((j == *nextY && i != *nextX && i != (*nextX+4)) || (j == *nextY+16 && i != *nextX && i != (*nextX+4)) || (j == (*nextY+8) && i != *nextX && i != (*nextX+4))){
				board[i][j] = '|';
			};
		};
	};
	if(left == 1){
		board[*nextX+2][*nextY+4] = '0';
	};
	if(left == 2){
		board[*nextX+1][*nextY+4] = '0';
		board[*nextX+3][*nextY+4] = '0';
	};
	if(left == 3){
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+2][*nextY+4] = '0';
		board[*nextX+3][*nextY+6] = '0';
	};
	if(left == 4){
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
	};
	if(left == 5){
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
		board[*nextX+2][*nextY+4] = '0';
	};
	if(left == 6){
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+1][*nextY+4] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+3][*nextY+4] = '0';
		board[*nextX+3][*nextY+6] = '0';
	};
	if(right == 1){
		board[*nextX+2][*nextY+12] = '0';
	};
	if(right == 2){
		board[*nextX+1][*nextY+12] = '0';
		board[*nextX+3][*nextY+12] = '0';
	};
	if(right == 3){
		board[*nextX+1][*nextY+10] = '0';
		board[*nextX+2][*nextY+12] = '0';
		board[*nextX+3][*nextY+14] = '0';
	};
	if(right == 4){
		board[*nextX+1][*nextY+10] = '0';
		board[*nextX+1][*nextY+14] = '0';
		board[*nextX+3][*nextY+10] = '0';
		board[*nextX+3][*nextY+14] = '0';
	};
	if(right == 5){
		board[*nextX+1][*nextY+10] = '0';
		board[*nextX+1][*nextY+14] = '0';
		board[*nextX+3][*nextY+10] = '0';
		board[*nextX+3][*nextY+14] = '0';
		board[*nextX+2][*nextY+12] = '0';
	};
	if(right == 6){
		board[*nextX+1][*nextY+10] = '0';
		board[*nextX+1][*nextY+12] = '0';
		board[*nextX+1][*nextY+14] = '0';
		board[*nextX+3][*nextY+10] = '0';
		board[*nextX+3][*nextY+12] = '0';
		board[*nextX+3][*nextY+14] = '0';
	};
};

void drawnV(char board[39][164], int *nextY, int *nextX, int left, int right){
	int i, j;
	for(i = *nextX; i < (*nextX+9); i++){
		for(j = *nextY; j < (*nextY+9); j++){
			if((i == *nextX && j != *nextY && j != (*nextY+8)) || (i == *nextX+4 && j != *nextY && j != (*nextY+8)) || (i == *nextX+8 && j != *nextY && j != (*nextY+8))){
				board[i][j] = '-';
			};
			if((j == *nextY && i != *nextX && i != (*nextX+8)) || (j == *nextY+8 && i != *nextX && i != (*nextX+8))){
				board[i][j] = '|';
			};
		};
	};
	if(left == 1){
		board[*nextX+2][*nextY+4] = '0';
	};
	if(left == 2){
		board[*nextX+2][*nextY+2] = '0';
		board[*nextX+2][*nextY+6] = '0';
	};
	if(left == 3){
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+2][*nextY+4] = '0';
		board[*nextX+1][*nextY+6] = '0';
	};
	if(left == 4){
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
	};
	if(left == 5){
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
		board[*nextX+2][*nextY+4] = '0';
	};
	if(left == 6){
		board[*nextX+3][*nextY+2] = '0';
		board[*nextX+1][*nextY+6] = '0';
		board[*nextX+1][*nextY+2] = '0';
		board[*nextX+3][*nextY+6] = '0';
		board[*nextX+2][*nextY+2] = '0';
		board[*nextX+2][*nextY+6] = '0';
	};
	if(right == 1){
		board[*nextX+6][*nextY+4] = '0';
	};
	if(right == 2){
		board[*nextX+6][*nextY+2] = '0';
		board[*nextX+6][*nextY+6] = '0';
	};
	if(right == 3){
		board[*nextX+7][*nextY+2] = '0';
		board[*nextX+6][*nextY+4] = '0';
		board[*nextX+5][*nextY+6] = '0';
	};
	if(right == 4){
		board[*nextX+7][*nextY+2] = '0';
		board[*nextX+5][*nextY+6] = '0';
		board[*nextX+5][*nextY+2] = '0';
		board[*nextX+7][*nextY+6] = '0';
	};
	if(right == 5){
		board[*nextX+7][*nextY+2] = '0';
		board[*nextX+5][*nextY+6] = '0';
		board[*nextX+5][*nextY+2] = '0';
		board[*nextX+7][*nextY+6] = '0';
		board[*nextX+6][*nextY+4] = '0';
	};
	if(right == 6){
		board[*nextX+7][*nextY+2] = '0';
		board[*nextX+5][*nextY+6] = '0';
		board[*nextX+5][*nextY+2] = '0';
		board[*nextX+7][*nextY+6] = '0';
		board[*nextX+6][*nextY+2] = '0';
		board[*nextX+6][*nextY+6] = '0';
	};
};

void drawnPiece(char board[39][164], int *nextX, int *nextY, int left, int right){
	if(
		((*nextX == 1) && ( *nextY == 10)) ||
		((*nextX == 1) && ( *nextY == 28))
	){
		drawnV(board, nextX, nextY, left, right);
		*nextY = *nextY + 9;
		return;
	};
	if(
		((*nextX == 154) && ( *nextY == 1)) ||
		((*nextX == 154) && ( *nextY == 19))
	){
		drawnV(board, nextX, nextY, left, right);
		*nextX = *nextX - 8;
		*nextY = *nextY + 9;
		return;
	};
	if(
		((*nextX == 10) && ( *nextY == 28))
	){
		drawnH(board, nextX, nextY, right, left);
		*nextX = *nextX - 9;
		return;
	};
	if(
		((*nextX == 10) && ( *nextY == 10))
	){
		drawnH(board, nextX, nextY, right, left);
		*nextX = *nextX - 9;
		return;
	};
	if(
		((*nextX == 146) && ( *nextY == 10)) ||
		((*nextX == 129) && ( *nextY == 10)) ||
		((*nextX == 112) && ( *nextY == 10)) ||
		((*nextX == 95) && ( *nextY == 10)) ||
		((*nextX == 78) && ( *nextY == 10)) ||
		((*nextX == 61) && ( *nextY == 10)) ||
		((*nextX == 44) && ( *nextY == 10)) ||
		((*nextX == 27) && ( *nextY == 10)) ||
		((*nextX == 146) && ( *nextY == 28)) ||
		((*nextX == 129) && ( *nextY == 28)) ||
		((*nextX == 112) && ( *nextY == 28)) ||
		((*nextX == 95) && ( *nextY == 28)) ||
		((*nextX == 78) && ( *nextY == 28)) ||
		((*nextX == 61) && ( *nextY == 28)) ||
		((*nextX == 44) && ( *nextY == 28)) ||
		((*nextX == 27) && ( *nextY == 28))
	){
		drawnH(board, nextX, nextY, right, left);
		*nextX = *nextX - 17;
		return;
	};
	if(
		((*nextX == 1) && ( *nextY == 1)) ||
		((*nextX == 18) && ( *nextY == 1)) ||
		((*nextX == 35) && ( *nextY == 1)) ||
		((*nextX == 52) && ( *nextY == 1)) ||
		((*nextX == 69) && ( *nextY == 1)) ||
		((*nextX == 86) && ( *nextY == 1)) ||
		((*nextX == 103) && ( *nextY == 1)) ||
		((*nextX == 120) && ( *nextY == 1)) ||
		((*nextX == 137) && ( *nextY == 1)) ||
		((*nextX == 1) && ( *nextY == 19)) ||
		((*nextX == 18) && ( *nextY == 19)) ||
		((*nextX == 52) && ( *nextY == 19)) ||
		((*nextX == 35) && ( *nextY == 19)) ||
		((*nextX == 69) && ( *nextY == 19)) ||
		((*nextX == 86) && ( *nextY == 19)) ||
		((*nextX == 103) && ( *nextY == 19)) ||
		((*nextX == 120) && ( *nextY == 19)) ||
		((*nextX == 137) && ( *nextY == 19))
	){
		drawnH(board, nextX, nextY, left, right);
		*nextX = *nextX + 17;
		return;
	};
};

void startTable(char board[39][164]){
	int i, j;
	for(i = 0; i < 39; i++){
		for(j = 0; j < 164; j++){
			if((i == 0 && j == 0) || (i == 0 && j == 163) || (i == 38 && j == 0) || (i == 38 && j == 163)){
				board[i][j] = '+';
			}else if((i == 0 && j != 0 && j != 163) || (i == 38 && j != 0 && j != 163)){
				board[i][j] = '=';
			}else if((i == 24 && j != 0 && j != 163)){
				board[i][j] = '-';
			}else if((j == 0 && i != 0 && i != 38) || (j == 163 && i != 0 && i != 38)){
				board[i][j] = '|';
			}else{
				board[i][j] = ' ';
			};
		};
	};
	board[0][77] = ' ';
	board[0][78] = 'D';
	board[0][79] = 'O';
	board[0][80] = 'M';
	board[0][81] = 'I';
	board[0][82] = 'N';
	board[0][83] = 'O';
	board[0][84] = ' ';
};

void clearTopTable(char board[39][164]){
	int i, j;
	for(i = 1; i < 24; i++){
		for(j = 1; j < 163; j++){
			board[i][j] = ' ';
		};
	};
};

void clearBottomTable(char board[39][164]){
	int i, j;
	for(i = 25; i < 38; i++){
		for(j = 1; j < 163; j++){
			board[i][j] = ' ';
		};
	};
};

void drawnTable(char board[39][164], dominoParts *table){
	clearTopTable(board);
	int nextX = 1;
	int nextY = 1;
	dominoPiece *auxPiece = table->startPiece;
	while(auxPiece != NULL){
		drawnPiece(board, &nextX, &nextY, auxPiece->values[0], auxPiece->values[1]);
		auxPiece = auxPiece->next;
	};
};

void showTable(char board[39][164]){
	printf("\e[H\e[2J");
	int i, j;
	for(i = 0; i < 39; i++){
		for(j = 0; j < 164; j++){
			printf("%c", board[i][j]);
		};
		printf("\n");
	};
};

void drawnPlayerParts(dominoParts *player, char board[39][164]){

	clearBottomTable(board);

	int nextX = 1;
	int nextY = 29;
	dominoPiece *auxPiece = player->startPiece;
	int counter = 1;
	while(auxPiece != NULL){
		drawnV(board, &nextX, &nextY, auxPiece->values[0], auxPiece->values[1]);

		if(counter == 1){board[nextY-1][nextX+4] = '1';};
		if(counter == 2){board[nextY-1][nextX+4] = '2';};
		if(counter == 3){board[nextY-1][nextX+4] = '3';};
		if(counter == 4){board[nextY-1][nextX+4] = '4';};
		if(counter == 5){board[nextY-1][nextX+4] = '5';};
		if(counter == 6){board[nextY-1][nextX+4] = '6';};
		if(counter == 7){board[nextY-1][nextX+4] = '7';};
		if(counter == 8){board[nextY-1][nextX+4] = '8';};
		if(counter == 9){board[nextY-1][nextX+4] = '9';};
		if(counter == 10){board[nextY-1][nextX+4] = '1';board[nextY-1][nextX+5] = '0';};
		if(counter == 11){board[nextY-1][nextX+4] = '1';board[nextY-1][nextX+5] = '1';};
		if(counter == 12){board[nextY-1][nextX+4] = '1';board[nextY-1][nextX+5] = '2';};
		if(counter == 13){board[nextY-1][nextX+4] = '1';board[nextY-1][nextX+5] = '3';};
		if(counter == 14){board[nextY-1][nextX+4] = '1';board[nextY-1][nextX+5] = '4';};
		if(counter == 15){board[nextY-1][nextX+4] = '1';board[nextY-1][nextX+5] = '5';};
		if(counter == 16){board[nextY-1][nextX+4] = '1';board[nextY-1][nextX+5] = '6';};
		if(counter == 17){board[nextY-1][nextX+4] = '1';board[nextY-1][nextX+5] = '7';};
		if(counter == 18){board[nextY-1][nextX+4] = '1';board[nextY-1][nextX+5] = '8';};

		nextX = nextX + 9;
		counter++;
		auxPiece = auxPiece->next;
	};
};

void startOptions(char board[39][164]){
	clearBottomTable(board);
	char menu0[] = "--------- Modo de Jogo ---------";
	char menu1[] = " ->  1 :   Um jogador";
	char menu2[] = " ->  2 :   Dois jogadores";
	char menu3[] = " ->  3 :   Jogadores Autonomos";
	int i;
	for(i = 0; i < sizeof(menu0); i++){board[25][i+1] = menu0[i];};
	for(i = 0; i < sizeof(menu1); i++){board[27][i+1] = menu1[i];};
	for(i = 0; i < sizeof(menu2); i++){board[28][i+1] = menu2[i];};
	for(i = 0; i < sizeof(menu3); i++){board[29][i+1] = menu3[i];};
};

void endOptions(char board[39][164]){
	clearBottomTable(board);
	char menu0[] = "--------- Fim de Jogo ---------";
	char menu1[] = " ->  1 :   Jogar Novamente";
	char menu2[] = " ->  2 :   Sair do Jogo";
	int i;
	for(i = 0; i < sizeof(menu0); i++){board[25][i+1] = menu0[i];};
	for(i = 0; i < sizeof(menu1); i++){board[27][i+1] = menu1[i];};
	for(i = 0; i < sizeof(menu2); i++){board[28][i+1] = menu2[i];};
};
