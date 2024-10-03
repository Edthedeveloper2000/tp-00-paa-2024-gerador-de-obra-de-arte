#ifndef BOARD_H
#define BOARD_H

#define WIDTH 80
#define HEIGHT 20

typedef struct _board Board;

Board* createBoard();
void initializeBoard(Board* board);
int fitsOnBoardPosition(Board * board, int row, int col, int size);
void insertOnBoard(Board* board, char **figure, int row, int col, int size);
void printBoard(Board* board);
void freeBoard(Board* board);

void generateWithSingleAsterisk(Board* board, int numberOfFigures);
void generateWithSumSymbol(Board* board, int numberOfFigures);
void generateWithXSymbol(Board* board, int numberOfFigures);
void generateWithRandomSymbols(Board* board, int numberOfFigures);
void generateCustomBoard(Board* board, int numberOfFigures);

#endif
