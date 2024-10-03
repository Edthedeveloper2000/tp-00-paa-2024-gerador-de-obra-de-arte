#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void showMenu() {
    int option;
    int numberOfFigures;

    printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
    printf("1 - asterisco simples.\n");
    printf("2 - simbolo de soma com asteriscos.\n");
    printf("3 - letra X com asteriscos.\n");
    printf("4 - figuras aleatorias\n");
    printf("5 ou qualquer outro numero – opcao de obra de arte criada pelo aluno\n");
    printf("Digite o tipo de figura basica desejada: ");
    scanf("%d", &option);

    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio)");
    scanf("%d", &numberOfFigures);

    if(numberOfFigures >100) {
        numberOfFigures = 100;
    } else if(numberOfFigures <=0) {
        numberOfFigures = generateRandomNumber();
    }

    switch (option)
    {
    case 1:
        generateWithSingleAsteristic(numberOfFigures);
        break;
    case 2:
        generateWithSumSimbol(numberOfFigures);
        break;
    case 3:
        generateWithXSimbol(numberOfFigures);
        break;
    case 4:
        generateWithRandomSimbols(numberOfFigures);
        break;
    case 5:
        generateCustomFigure(numberOfFigures);
        break;
    default:
        break;
    }
}