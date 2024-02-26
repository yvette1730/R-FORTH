// int_stack.c

#include "int_stack.h"
#include <stdlib.h>
#include <stdio.h>

void int_stack_init(int_stack_t *stk, int capacity) {
    SLIST_INIT(&stk->head);
    stk->size = 0;
    stk->capacity = capacity;
}

int int_stack_push(int_stack_t *stk, int value) {
    if (stk->size >= stk->capacity) {
        printf("Stack is at full capacity.\n");
        return 0; // fail
    }

    int_entry_t *newEntry = malloc(sizeof(int_entry_t));
    if (newEntry) {
        newEntry->value = value;
        SLIST_INSERT_HEAD(&stk->head, newEntry, entries);
        stk->size++;
        return 1; //success
    }
    return 0; // fail
}

int int_stack_pop(int_stack_t *stk, int *top_value) {
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry) {
        int value = entry->value;
        SLIST_REMOVE_HEAD(&stk->head, entries);
        free(entry);
        stk->size--;
        *top_value = value;
        return 1; // success
    }
    return 0; // fail
}

int int_stack_top(int_stack_t *stk, int *top_value) {
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry) {
        *top_value = entry->value;
        return 1; // success
    }
    return 0; // fail
}

/* Functions for FORTH langauge stack operators */

int int_stack_dup(int_stack_t *stk) {
    if (stk->size < 1)
        return 0;
    int top_value;
    int_stack_top(stk, &top_value);
    return int_stack_push(stk, top_value); // success only if last operation succeeds
}

int int_stack_swap(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, next_to_top_value); // success only if last operation succeeds
}

/* Example of how to create a binary operator that works o top two elements (if present) */

int int_stack_add(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value + next_to_top_value);
}

void int_stack_print(int_stack_t *stk, FILE *file) {
    int_entry_t *entry;
    int pos = 0;
    if (stk->size == 0) {
        fprintf(file, "empty stack\n");
    }

    SLIST_FOREACH(entry, &stk->head, entries) {
        fprintf(file, "%d: %d\n", pos, entry->value);
        pos++;
    }
    printf("\n");
}

int int_stack_size(int_stack_t* stk) {
    return stk->size;
}

int int_stack_capacity(int_stack_t* stk) {
    return stk->capacity;
}

int int_stack_over(int_stack_t* stk) {
    if (stk->size >= 2) {
        int top_value, next_to_top_value;
        int_stack_top(stk, &top_value);
        int_stack_pop(stk, &next_to_top_value);
        int_stack_push(stk, next_to_top_value);
        return int_stack_push(stk, top_value);
    } else {
        return 0;
    }
}

int int_stack_rot(int_stack_t *stk) {
    if (stk->size >= 3) {
        int a, b, c;
        int_stack_pop(stk, &a);
        int_stack_pop(stk, &b);
        int_stack_pop(stk, &c);
        int_stack_push(stk, b);
        int_stack_push(stk, a);
        return int_stack_push(stk, c);
    } else {
        return 0;
    }
}
int int_stack_drop(int_stack_t *stk)
{
    if(int_stack_pop(stk, NULL) == 1)
    {
       return int_stack_pop(stk, NULL); 
    }
    return 0; //if it will fail 
}
int int_stack_swap2(int_stack_t *stk) {
    if (stk->size >= 2) {
        int a, b;
        int_stack_pop(stk, &a);
        int_stack_pop(stk, &b);
        int_stack_push(stk, a);
        return int_stack_push(stk, b);
    } else {
        return 0;
    }
}

int int_stack_dup2(int_stack_t *stk) {
    if (stk->size >= 2) {
        int top_value;
        int_stack_top(stk, &top_value);
        return int_stack_push(stk, top_value);
    } else {
        return 0;
    }
}
int int_stack_over2(int_stack_t *stk)
{
    if (stk->size < 2)
    {
        return 0;
    }
    int s1, s2, s3, s4;
    int_stack_pop(stk, &s1);
    int_stack_pop(stk, &s2);
    int_stack_pop(stk, &s3);
    int_stack_pop(stk, &s4);
    int_stack_push(stk, s4);
    int_stack_push(stk, s3);
    int_stack_push(stk, s2);
    int_stack_push(stk, s1);
    int_stack_push(stk, s4);
    return int_stack_push(stk, s3);

}
int int_stack_drop2(int_stack_t *stk)
{
    //discards the top pair of numbers 
    if (stk->size > 2) {
        int_stack_pop(stk, NULL);
        int_stack_pop(stk, NULL);
        return 1;
    } else {
        return 0;
    }
}


//arithemtic operations 

int int_stack_subtract(int_stack_t* stk)
{
    if(stk->size >= 2)
    {
        int a = int_stack_pop(stk, NULL);
        int b = int_stack_pop(stk, NULL);
        int sub_num = a-b; 
        return int_stack_push(stk, sub_num);
    }
    else{
        return 0; 
    }
}

int int_stack_divide(int_stack_t* stk)
{
    if(stk->size >= 2)
    {
        int a = int_stack_pop(stk, NULL);
        int b = int_stack_pop(stk, NULL);
        int divide_num = a/b; 
        return int_stack_push(stk, divide_num);
    }
    else{
        return 0;
    }
}

int int_stack_multiply(int_stack_t* stk)
{
    if(stk->size >= 2)
    {
        int a = int_stack_pop(stk, NULL);
        int b = int_stack_pop(stk, NULL);
        int mult_num = a*b; 
        return int_stack_push(stk, mult_num); 
    }
    else{
        return 0; 
    }
}

