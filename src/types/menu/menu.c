#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void showMenu() {
    int option;
    int numberOfBoards;
    
    Board* board = createBoard();

    printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
    printf("1 - asterisco simples.\n");
    printf("2 - simbolo de soma com asteriscos.\n");
    printf("3 - letra X com asteriscos.\n");
    printf("4 - figuras aleatorias\n");
    printf("5 ou qualquer outro numero – opcao de obra de arte criada pelo aluno\n");
    printf("Digite o tipo de figura basica desejada: ");
    scanf("%d", &option);

    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
    scanf("%d", &numberOfBoards);

    if (numberOfBoards > 100) {
        numberOfBoards = 100;
    } else if (numberOfBoards <= 0) {
        numberOfBoards = generateRandomNumber();
    }

    switch (option) {
        case 1:
            generateWithSingleAsterisk(board, numberOfBoards);
            break;
        case 2:
            generateWithSumSymbol(board, numberOfBoards);
            break;
        case 3:
            generateWithXSymbol(board, numberOfBoards);
            break;
        case 4:
            generateWithRandomSymbols(board, numberOfBoards);
            break;
        case 5:
            generateCustomBoard(board, numberOfBoards);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
    printBoard(board);

    freeBoard(board);
}
