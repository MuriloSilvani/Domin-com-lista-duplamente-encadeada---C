#ifndef domino_c
#define domino_c

typedef struct dominoPiece{
	int values[2];
	struct dominoPiece *next, *prev;
}dominoPiece;

typedef struct dominoParts{
	int total;
	struct dominoPiece *startPiece;
	char name[50];
	int type;
}dominoParts;

void init(dominoParts *parts, char name[50], int type);
void insertPiece(dominoParts *parts, int left, int right);
void removePiece(dominoParts *parts, int left, int right);
void showParts(dominoParts *parts);
void generateAllParts(dominoParts *parts);
void giveRandomPiece(dominoParts *giveParts, dominoParts *receiveParts);
void giveStartParts(dominoParts *giveParts, dominoParts *receiveParts);
void insertPieceStart(dominoParts *parts, int left, int right);
void searchFirstLast(dominoParts *table, int *first, int *last);
int verifyPiece(dominoParts *player, dominoParts *table, int playChoose);
int verifyParts(dominoParts *player, dominoParts *table);
void playAuto(dominoParts *player, dominoParts *table, int *playChoose);
int play(dominoParts *player, dominoParts *table, dominoParts *allParts, char board[43][163]);
void playPiece(dominoParts *player, dominoParts *table, int playChoose);
int verifyWinner(dominoParts *player1, dominoParts *player2, dominoParts *table, dominoParts *allParts, char board[43][163]);

void drawnV(char board[43][163], int nextY, int nextX, int left, int right);
void drawnH(char board[43][163], int nextY, int nextX, int left, int right);
void drawnPiece(char board[43][163], int *nextX, int *nextY, int left, int right);
void drawnPlayerParts(char board[43][163], dominoParts *player);
void showTable(char board[43][163]);
void generateTable(char board[43][163]);


#endif
