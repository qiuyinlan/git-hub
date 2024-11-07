#include <stdio.h>

int main() {
    int low = 1, high = 100;
    int guess, response;

    printf("Think of a number between 1 and 100 and I'll try to guess it.\n");

    while (1) {
        guess = (low + high) / 2;
        printf("Is your number %d? (1 for yes, 0 for too low, 2 for too high): ", guess);
        scanf("%d", &response);

        if (response == 1) {
            printf("I guessed it! Your number was %d.\n", guess);
            break;
        } else if (response == 0) {
            low = guess + 1;  // 增大下限
        } else if (response == 2) {
            high = guess - 1; // 减小上限
        } else {
            printf("Invalid input, please enter 0, 1, or 2.\n");
        }
    }

    return 0;
}
