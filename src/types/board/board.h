#ifndef BOARD_H
#define BOARD_H

#define WIDTH 80   // The width of the board (number of columns)
#define HEIGHT 20  // The height of the board (number of rows)

#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "board.h"

// Struct representing the board with a 2D grid
typedef struct _board Board;

/**
 * @brief Creates and initializes a new board.
 * 
 * @return Board* A pointer to the newly created board.
 */
Board* createBoard();

/**
 * @brief Initializes the board by setting up its borders and empty spaces.
 * 
 * @param board A pointer to the board to be initialized.
 */
void initializeBoard(Board *board);

/**
 * @brief Checks if a figure of a given size can be placed on the board at a specified position.
 * 
 * @param board A pointer to the board.
 * @param row The starting row for the figure.
 * @param col The starting column for the figure.
 * @param size The size of the figure (assumed to be a square).
 * @return int Returns 1 if the figure fits, 0 if it does not.
 */
int fitsOnBoardPosition(Board *board, int row, int col, int size);

/**
 * @brief Inserts a figure onto the board at the specified position.
 * 
 * @param board A pointer to the board.
 * @param figure The figure (represented as a 2D character array) to be inserted.
 * @param row The starting row to insert the figure.
 * @param col The starting column to insert the figure.
 * @param size The size of the figure (assumed to be a square).
 */
void insertOnBoard(Board* board, char **figure, int row, int col, int size);

/**
 * @brief Randomly places a specified number of figures on the board.
 * 
 * @param board A pointer to the board.
 * @param figure The figure (represented as a 2D character array) to be placed.
 * @param size The size of the figure.
 * @param numberOfFigures The number of figures to place on the board.
 */
void generateFigures(Board* board, char** figure, int size, int numberOfFigures);

/**
 * @brief Places a specified number of single asterisks ('*') on the board.
 * 
 * @param board A pointer to the board.
 * @param numberOfFigures The number of asterisks to place on the board.
 */
void generateWithSingleAsterisk(Board* board, int numberOfFigures);

/**
 * @brief Places a specified number of sum symbols on the board.
 * 
 * @param board A pointer to the board.
 * @param numberOfFigures The number of sum symbols to place on the board.
 */
void generateWithSumSymbol(Board* board, int numberOfFigures);

/**
 * @brief Places a specified number of 'X' symbols on the board.
 * 
 * @param board A pointer to the board.
 * @param numberOfFigures The number of 'X' symbols to place on the board.
 */
void generateWithXSymbol(Board* board, int numberOfFigures);

/**
 * @brief Randomly generates and places a specified number of various figures on the board.
 * Figures include asterisks, sum symbols, and 'X' symbols.
 * 
 * @param board A pointer to the board.
 * @param numberOfFigures The number of random figures to place on the board.
 */
void generateWithRandomSymbols(Board* board, int numberOfFigures);

/**
 * @brief Generates custom art by placing random pre-defined "face" patterns on the board.
 * 
 * @param board A pointer to the board.
 * @param numberOfFigures The number of custom faces to place on the board.
 */
void generateCustomArt(Board* board, int numberOfFigures);

/**
 * @brief Transforms and inserts a face pattern onto the board with possible alterations.
 * 
 * @param board A pointer to the board.
 * @param face A character array representing the face pattern to be transformed and inserted.
 */
void insertTransformed(Board *board, char* face);

/**
 * @brief Inserts a transformed face pattern onto a specific location on the board.
 * 
 * @param board A pointer to the board.
 * @param newFace A character array representing the transformed face pattern.
 * @param row The starting row to insert the face.
 * @param col The starting column to insert the face.
 */
void insertTransformedOnBoard(Board* board, char* newFace, int row, int col);

/**
 * @brief Prints the current state of the board to the console.
 * 
 * @param board A pointer to the board.
 */
void printBoard(Board* board);

/**
 * @brief Frees the memory allocated for the board.
 * 
 * @param board A pointer to the board to be freed.
 */
void freeBoard(Board* board);

#endif
