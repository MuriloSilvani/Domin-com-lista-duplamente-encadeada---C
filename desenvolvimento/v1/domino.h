#ifndef domino_h
#define domino_h

typedef struct DominoPiece{
	int values[2];
	DominoPiece *next, *prev;
}DominoPiece;

DominoPiece *init(int *numberPieces, DominoPiece *parts);

DominoPiece *createPiece(int leftValue, int rightValue);

void showPieces(DominoPiece *parts);

DominoPiece *givePiece(int *givePieces, DominoPiece *giveParts, int *receivePieces, DominoPiece *receiveParts);

DominoPiece *insertPiece(int *receivePieces, DominoPiece *receiveList, int left, int right);

#endif
