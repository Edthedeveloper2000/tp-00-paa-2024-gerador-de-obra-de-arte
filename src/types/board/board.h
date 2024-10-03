#ifndef BOARD_H
#define BOARD_H

#define WIDTH 80
#define HEIGHT 20

typedef struct _board Board;

Board* createBoard();
void initializeBoard(Board* board);
void insertOnBoard(Board* board, char figure[3][3], );
void printBoard(Board* board);
void freeBoard(Board* board);

void generateWithSingleAsterisk(Board* board, int numberOfFigures);
void generateWithSumSymbol(Board* board, int numberOfFigures);
void generateWithXSymbol(Board* board, int numberOfFigures);
void generateWithRandomSymbols(Board* board, int numberOfFigures);
void generateCustomBoard(Board* board, int numberOfFigures);

#endif
