#include <stdio.h>
#include "token.h"
#include <string.h>
#include <stdlib.h>

int main() {
    char token_text[100];
    printf("Enter a token: ");
    fgets(token_text, sizeof(token_text), stdin);
    token_text[strcspn(token_text, "\n")] = '\0'; // Remove newline character if present
    
    // Create a token_t object
    token_t my_token;
    my_token.type; // Set the appropriate type
    my_token.text = strdup(token_text);

    // Pass the token to the classify_token function
    get_token_class(&my_token);


    printf("The token class for '%s' is '%d'.\n", token_text, str(my_token.type));


    // Free the allocated memory for the token text
    free(my_token.text);

    return 0;
}
