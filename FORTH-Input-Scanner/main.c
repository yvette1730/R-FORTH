#include <stdio.h>
#include <string.h>
#include "token.h"

int main() {
    char input[1000];
    char choice[2];

    do {
        printf("Enter an argument: \n");
        scanf("%99s", input); 
        find_token(input); 

        printf("Would you like to continue? (Y/N): ");
        scanf("%1s", choice);

    } while (strcmp(choice, "N") != 0 && strcmp(choice, "n") != 0);

    return 0;
}
