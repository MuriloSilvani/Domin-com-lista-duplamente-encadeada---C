#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "domino.h"

typedef struct DominoPiece{
    int side[2];
    // struct DominoPiece *right;
    // struct DominoPiece *left;
}DominoPiece;

// DominoPiece *init();
DominoPiece createPiece(int left, int right);

// DominoPiece *init(){
// 	return NULL;
// };

DominoPiece createPiece(int left, int right){
	
    DominoPiece *newPiece = (DominoPiece*) calloc(sizeof(DominoPiece),1);
    
    newPiece->side[0] = left;
    newPiece->side[1] = right;

    printf("criando [%i|%i]\n", newPiece->side[0], newPiece->side[1]);
    
    return newPiece;

};


int main(int argc, char const *argv[]) {

    DominoPiece *parts = NULL;
    
    // DominoPiece *tempPiece;

    int PieceCounter = 0;

    for(int left = 0; left <= 6; left++) {
        for (int right = 0; right <= 6; right++) {
            parts = (DominoPiece*) realloc( parts, (PieceCounter+1) * sizeof(DominoPiece));

            // tempPiece = createPiece( left, right);

            // memcpy( &parts[PieceCounter], tempPiece, sizeof(DominoPiece));

            // free(tempPiece);
            PieceCounter++;
        }
    }

    return 0;
}
