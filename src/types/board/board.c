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

void insertOnBoard(Board* board, char **figure, int row, int col, int size) {
    for(int i=0; i < size; i++) {
        for(int j = 0; j< size; j++) {
            board->grid[row + i][col + j] = figure[i][j];
        }
    }
}

void generateFigures(Board* board, char** figure, int size, int numberOfFigures) {
    for (int i = 0; i < numberOfFigures; i++) {
        int row, col;

        do {
            row = rand() % (HEIGHT - size + 1); 
            col = rand() % (WIDTH - size + 1);  
        } while(!fitsOnBoardPosition(board, row, col, size));

        insertOnBoard(board, figure, row, col, size);
    }
}


void generateWithSingleAsterisk(Board* board, int numberOfFigures) {
    char *figure[1] = { "*" }; 
    int size = 1;

    generateFigures(board, figure, size, numberOfFigures);

}

void generateWithSumSymbol(Board* board, int numberOfFigures) {
    char *figure[3] = { " * ", "***", " * " };
    int size = 3;

    generateFigures(board, figure, size, numberOfFigures);
}

void generateWithXSymbol(Board* board, int numberOfFigures) {
    char *figure[3] = { "* *", " * ", "* *" };
    int size = 3;
    
    generateFigures(board, figure, size, numberOfFigures);
}

void generateWithRandomSymbols(Board* board, int numberOfFigures) {
    for (int i = 0; i < numberOfFigures; i++) {
        int randomChoice = rand() % 2; 

        if (randomChoice == 0) {
            char *asterisk[1] = { "*" };
            generateFigures(board, asterisk, 1, 1);
        } else if (randomChoice == 1) {
            char *sumSymbol[3] = { " * ", "***", " * " };
            generateFigures(board, sumSymbol, 3, 1);
        } else if (randomChoice == 2) {
            char *xSymbol[3] = { "* *", " * ", "* *" };
            generateFigures(board, xSymbol, 3, 1);
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

