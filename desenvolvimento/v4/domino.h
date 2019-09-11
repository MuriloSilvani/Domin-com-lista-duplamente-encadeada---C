#ifndef domino_c
#define domino_c

typedef struct dominoPiece{
	int values[2];
	dominoPiece *next, *prev;
}dominoPiece;

typedef struct dominoParts{
	int total;
	dominoPiece *startPiece;
}dominoParts;

void init(dominoParts *parts);
void generateAllParts(dominoParts *parts);
void showParts(dominoParts *parts);
void insertPiece(dominoParts *parts, int left, int right);
void removePiece(dominoParts *parts, int left, int right);
void giveRandomPiece(dominoParts *giveParts, dominoParts *receiveParts);
void giveStartParts(dominoParts *giveParts, dominoParts *receiveParts);

#endif