#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "domino.h"


int main(int argc, char** argv){
int x = 0;
while(x<1){	
	x++;

	dominoParts* allParts = (dominoParts*) malloc(sizeof (dominoParts)); //aloca espaco para lista
	init(allParts);
	
	generateAllParts(allParts);
	
	dominoParts* player1 = (dominoParts*) malloc(sizeof (dominoParts)); //aloca espaco para lista
	init(player1);
	giveStartParts(allParts, player1);
	
	dominoParts* player2 = (dominoParts*) malloc(sizeof (dominoParts)); //aloca espaco para lista
	init(player2);
	giveStartParts(allParts, player2);
		
		
	system("cls");		
	printf("----- Monte   [pecas: %i] ------\n", allParts->total);
	showParts(allParts);
	
	printf("----- Player1 [pecas: %i] -----\n");
	showParts(player1);
	printf("----- Player2 [pecas: %i] -----\n");
	showParts(player2);

	
};
		
	printf("\n\n\n\nACABOU     \n\n\n\n");
	// system("pause");
	return 0;
};