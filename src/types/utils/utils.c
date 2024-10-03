#include "utils.h"

int generateRandomNumber() {
    srand(time(NULL));
    int random_number = (rand() % (100 - 50 + 1)) + 50;
    return random_number;
}