// int_stack.h - interface to the int_stack

#ifndef INT_STACK_H
#define INT_STACK_H

#include <stdio.h>
#include <sys/queue.h>

typedef struct int_entry {
    int value;
    SLIST_ENTRY(int_entry) entries;
} int_entry_t;

typedef struct int_stack {
    SLIST_HEAD(stackhead, int_entry) head;
    int size;
    int capacity;
} int_stack_t;

extern void int_stack_init(int_stack_t *stk, int capacity);
extern int int_stack_push(int_stack_t *stk, int value);
extern int int_stack_pop(int_stack_t *stk, int *top_value);
extern int int_stack_top(int_stack_t *stk, int *top_value);
extern int int_stack_dup(int_stack_t *stk);
extern int int_stack_swap(int_stack_t *stk);
extern int int_stack_add(int_stack_t *stk);
extern void int_stack_print(int_stack_t *stk, FILE *file);
extern int int_stack_size(int_stack_t* stk);
extern int int_stack_capacity(int_stack_t* stk);

//additional stack methods

extern int int_stack_over(int_stack_t *stk);
extern int int_stack_rot(int_stack_t *stk);
extern int int_stack_drop(int_stack_t *stk);
extern int int_stack_swap2(int_stack_t *stk);
extern int int_stack_dup2(int_stack_t *stk);
extern int int_stack_over2(int_stack_t *stk);
extern int int_stack_drop2(int_stack_t *stk);

//arithmetic operations 
extern int int_stack_subtract(int_stack_t *stk);
extern int int_stack_multiply(int_stack_t *stk);
extern int int_stack_divide(int_stack_t *stk);
extern void define_variable(int_stack_t *stk); 
#endif // INT_STACK_H