#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

//declare the token type 
typedef enum token_type_t token_type_t;

typedef enum token_type_t {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    VARIABLE, 
    CONSTANT, 
    CONDITION,
    NOT_DEFINED,
    END_OF_FILE // Define END_OF_FILE token type
}token_type_t;

// Struct to represent a token
typedef struct token_t{
    token_type_t type;
    char* text;
} token_t;

extern char* find_token(char* text);
extern token_type_t get_token_type(const char* token);
extern token_t* create_token(token_type_t type, const char* text);

#endif // TOKEN_H
