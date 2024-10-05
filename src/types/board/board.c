#include "board.h"

struct _board { 
    char grid[HEIGHT][WIDTH];
};

Board* createBoard() {
    Board* board = (Board*)malloc(sizeof(Board));
    if (board) {
        initializeBoard(board);
    }
    return board;
}

void initializeBoard(Board *board) {
    for(int i=0; i< HEIGHT; i++) {
        for(int j=0;j<WIDTH;j++) {
            if(i==0 || i == HEIGHT-1) {
                board->grid[i][j] = '-';
            } else if (j==0 || j == WIDTH - 1) {
                board->grid[i][j] = '|';
            } else {
                board->grid[i][j] = ' ';
            }
        }
    }
}

int fitsOnBoardPosition(Board * board, int row, int col, int size) {
    for( int i = 0; i < size; i++ ) {
        for(int j = 0; j < size; j++) {
            if(board->grid[row + i] [col + j] != ' ') {
                return 0;
            }
        }
    }

    return 1;
}

void placeFigureOnBoard(Board *board, char **figure, int size) {
    int row, col;

    do {
        row = generateRandomNumber() % (WIDTH - 5) + 2;
        col = generateRandomNumber() % (WIDTH - 5) + 2;
    } while(!fitsOnBoardPosition(board, row, col, size));

    insertOnBoard(board, figure, row, col, size);
}

void insertOnBoard(Board* board, char **figure, int row, int col, int size) {
    for(int i=0; i < size; i++) {
        for(int j = 0; j< size; j++) {
            board->grid[row + i][col + j] = figure[i][j];
        }
    }
}


void generateWithSingleAsterisk(Board* board, int numberOfFigures) {
    char *figure[1] = { "*" }; 
    int size = 1;

    for (int i = 0; i < numberOfFigures; i++) {
        placeFigureOnBoard(board, figure, size);
    }
}

void generateWithSumSymbol(Board* board, int numberOfFigures) {
    char *figure[3] = { " * ", "***", " * " };
    int size = 3;

    for (int i = 0; i < numberOfFigures; i++) {
        placeFigureOnBoard(board, figure, size);
    }
}

void generateWithXSymbol(Board* board, int numberOfFigures) {
    char *figure[3] = { "* *", " * ", "* *" };
    int size = 3;

    for (int i = 0; i < numberOfFigures; i++) {
        placeFigureOnBoard(board, figure, size);
    }
}

void generateWithRandomSymbols(Board* board, int numberOfFigures) {
    for (int i = 0; i < numberOfFigures; i++) {
        int randomChoice = generateRandomNumber() % 3;

        if (randomChoice == 0) {
            char *asterisk[1] = { "*" };
            placeFigureOnBoard(board, asterisk, 1);
        } else if (randomChoice == 1) {
            char *sumSymbol[3] = { " * ", "***", " * " };
            placeFigureOnBoard(board, sumSymbol, 3);
        } else if (randomChoice == 2) {
            char *xSymbol[3] = { "* *", " * ", "* *" };
            placeFigureOnBoard(board, xSymbol, 3);
        }
    }
}

void printBoard(Board* board) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board->grid[i][j]);
        }
        printf("\n");
    }
}


void freeBoard(Board* board) {
    free(board);
}

