#ifndef domino_h
#define domino_h

typedef struct DominoPiece{
	int values[2];
	DominoPiece *next;
	DominoPiece *prev;
}DominoPiece;

DominoPiece *init(int *numberPieces, DominoPiece *parts);

DominoPiece *createPiece(int leftValue, int rightValue);

void showPieces(DominoPiece *parts);

DominoPiece *givePiece(int *givePieces, DominoPiece *giveParts, int *receivePieces, DominoPiece *receiveParts);

DominoPiece *insertPiece(int *receivePieces, DominoPiece *receiveList, int left, int right);

DominoPiece *removePiece(int *givePieces, DominoPiece *giveList, int left, int right);

DominoPiece *setTable(int playOption, int *givePieces, DominoPiece *giveParts, int *receivePieces, DominoPiece *receiveParts);

#endif
