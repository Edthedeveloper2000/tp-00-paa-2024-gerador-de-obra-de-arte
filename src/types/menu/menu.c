#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void showMenu() {
    int option = -1;
    int figuresQuantity = 0;
    char createAgain;

    do {
        printf("\nEscolha o tipo de figura basica a ser usada para criar a obra (0 para sair):\n");
        printf("1 - asterisco simples.\n");
        printf("2 - simbolo de soma com asteriscos.\n");
        printf("3 - letra X com asteriscos.\n");
        printf("4 - figuras aleatorias.\n");
        printf("5 ou qualquer outro numero – opcao de obra de arte criada pelo aluno.\n");
        printf("Digite o tipo de figura basica desejada: ");
        scanf("%d", &option);

        if (option == 0) {
            printf("Programa finalizado.\n");
            break;
        }

        printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
        scanf("%d", &figuresQuantity);

        if (figuresQuantity > 100) {
            figuresQuantity = 100;
        } else if (figuresQuantity <= 0) {
            figuresQuantity = rand() % 100 + 1;
        }

        do {
            Board* board = createBoard();

            switch (option) {
                case 1:
                    generateWithSingleAsterisk(board, figuresQuantity);
                    break;
                case 2:
                    generateWithSumSymbol(board, figuresQuantity);
                    break;
                case 3:
                    generateWithXSymbol(board, figuresQuantity);
                    break;
                case 4:
                    generateWithRandomSymbols(board, figuresQuantity);
                    break;
                case 5:
                    generateCustomArt(board, figuresQuantity);
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
            }

            printBoard(board);
            freeBoard(board);

            printf("\nDeseja gerar outro tabuleiro com as mesmas configuracoes? (s/n): ");
            scanf(" %c", &createAgain);

        } while (createAgain == 's' || createAgain == 'S');

    } while (1);
}
