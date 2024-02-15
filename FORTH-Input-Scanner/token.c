#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include <ctype.h>
#include <string.h>

// Function to create a new token
token_t* create_token(token_type_t type, const char* text) 
{
    token_t* token = (token_t*)malloc(sizeof(token_t));
    if (token == NULL) 
    {
        return NULL; 
    }
}


// Function to convert token type to string
token_type_t get_token_type(const char *token_text) {
    if (isdigit((unsigned char)*token_text))
     {
        return NUMBER;
    } else if ((*token_text == '+' || *token_text == '-' || *token_text == '*' || *token_text== '/')) {
        return OPERATOR;
    } else if (*token_text == ';' || *token_text == ':') 
    {
        return SYMBOL;
    } 
    else 
    {
        return WORD;
    }
}

const char* token_string(token_type_t type)
{
    if(type == NUMBER)
    {
        return "Number"; 
    }
    else if(type == OPERATOR)
    {
        return "Operator"; 
    }
    else if(type == SYMBOL)
    {
        return "Symbol"; 
    }
    else 
    {
        return "Word";
    }
}

char* find_token(char* text)
{
    const char* blank = " "; 
    char* token; 
    char* curLine = text;


    while ((token = strtok_r(curLine, blank, &curLine)))
    {
        token_type_t type = get_token_type(token);
        printf("Token: %s, Type: %s\n", token, token_string(type));
    }

}