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
void insertPiece(dominoParts *parts, int left, int right);
void removePiece(dominoParts *parts, int left, int right);
void showParts(dominoParts *parts);
void generateAllParts(dominoParts *parts); 
void giveRandomPiece(dominoParts *giveParts, dominoParts *receiveParts);
void giveStartParts(dominoParts *giveParts, dominoParts *receiveParts);
void insertPieceStart(dominoParts *parts, int left, int right);

void searchFirstLast(dominoParts *table, int *first, int *last);
bool verifyPiece(dominoParts *player, dominoParts *table, int playChoose);


// jogar
// versetempeca
// pescar
// verificarpeca
// versetemganhador


bool play(dominoParts *player, dominoParts *table, dominoParts *allParts);
void playPiece(dominoParts *player, dominoParts *table, int playChoose);


#endif