#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

//declare the token type 
typedef enum token_type_t token_type_t;

enum token_type_t {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    END_OF_FILE // Define END_OF_FILE token type
};

// Struct to represent a token
typedef struct {
    token_type_t type;
    char* text;
} token_t;

// Function to convert token type to string
//const char *token_type_to_string(enum token_type_t type);
//getting the next tokne needed 
token_t* get_next_token(char **input);
//classify the token 
void classify_token(token_t *token);

#endif // TOKEN_H
