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

