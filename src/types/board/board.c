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

void generateCustomArt(Board *board, int numberOfFigures) {
    char *figures[4] = { "+_+", ">_<", "-_-", "0-0" };
    
    for(int i = 0; i < numberOfFigures; i++) {
        int randomChoice = rand() % 4;
        char* selectedFace = figures[randomChoice];

        insertTransformed(board, selectedFace);
    }
}

void insertTransformedOnBoard(Board* board, char* newFace, int row, int col) {
    for(int i = 0; i < 3; i++) {
        if (board->grid[row][col + i] == ' ') {
            board->grid[row][col + i] = newFace[i];
        }
    }
}


void insertTransformed(Board *board, char* face) {
    int transformation = rand() % 4;
    char newFace[4];

    switch (transformation) {
    case 0:
        strcpy(newFace, face);
        break;
    case 1:
        newFace[0] = face[2];
        newFace[1] = face[1];
        newFace[2] = face[0];
        newFace[3] = '\0';
        break;
    case 2:
        newFace[0] = face[0];
        newFace[1] = face[2];
        newFace[2] = face[1];
        newFace[3] = '\0';
        break;
    case 3:
        newFace[0] = face[0];
        newFace[1] = ',';
        newFace[2] = face[2];
        newFace[3] = '\0';
        break;
    default:
        strcpy(newFace, face);
        break;
    }

    int row, col;
    do {
        row = rand() % (HEIGHT - 1);
        col = rand() % (WIDTH - 3);
    } while (!fitsOnBoardPosition(board, row, col, 3));

    insertTransformedOnBoard(board, newFace, row, col);
}


void generateWithRandomSymbols(Board* board, int numberOfFigures) {
    for (int i = 0; i < numberOfFigures; i++) {
        int randomChoice = rand() % 3; 

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

