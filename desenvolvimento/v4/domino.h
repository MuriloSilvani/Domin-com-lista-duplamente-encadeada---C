#ifndef domino_c
#define domino_c

typedef struct dominoPiece{
	int values[2];
	dominoPiece *next, *prev;
}dominoPiece;

typedef struct dominoParts{
	int total;
	dominoPiece *startPiece;
	char name[50];
}dominoParts;

void init(dominoParts *parts, char name[50]);
void generateAllParts(dominoParts *parts);
void showParts(dominoParts *parts);
void insertPiece(dominoParts *parts, int left, int right);
dominoPiece *insertPieceStart(dominoParts *parts, int left, int right);
void removePiece(dominoParts *parts, int left, int right);
void giveRandomPiece(dominoParts *giveParts, dominoParts *receiveParts);
void giveStartParts(dominoParts *giveParts, dominoParts *receiveParts);
int play(dominoParts *player, dominoParts *table);
int checkWinner(dominoParts *player, dominoParts *table);
void pickFirstLast(int *firstTable, int *lastTable, dominoParts *table);

#endif