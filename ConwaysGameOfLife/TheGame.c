#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep
#include "int_stack.h"

#define WIDTH 20
#define HEIGHT 20
#define ALIVE 1
#define DEAD 0

// Function to initialize the game board
void initialize_board(int_stack_t *stk) {
    int_stack_init(stk, WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int_stack_push(stk, DEAD);
    }
}

// Function to print the game board
void print_board(int_stack_t *stk) {
    printf("Game of Life:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int top_value;
            int_stack_top(stk, &top_value);
            if (top_value == ALIVE) {
                printf("X ");
            } else {
                printf(". ");
            }
            int_stack_pop(stk, NULL);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count live neighbors of a cell
int count_live_neighbors(int_stack_t *stk, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH && !(i == x && j == y)) {
                int_stack_t *temp = malloc(sizeof(int_stack_t));
                initialize_board(temp);
                int_stack_t *temp2 = malloc(sizeof(int_stack_t));
                initialize_board(temp2);
                for(int k = 0; k < WIDTH * HEIGHT; k++){
                    int top_value;
                    int_stack_top(stk, &top_value);
                    int_stack_push(temp, top_value);
                    int_stack_push(temp2, top_value);
                    int_stack_pop(stk, NULL);
                }
                int value;
                for (int k = 0; k < i*WIDTH + j; k++){
                    int_stack_pop(temp, &value);
                    int_stack_push(stk, value);
                }
                int_stack_pop(temp, &value);
                if (value == ALIVE){
                    count++;
                }
                for (int k = i*WIDTH + j+1; k < WIDTH*HEIGHT; k++){
                    int_stack_pop(temp, &value);
                    int_stack_push(stk, value);
                }
                for (int k = 0; k < WIDTH*HEIGHT; k++){
                    int_stack_pop(temp, &value);
                    int_stack_push(stk, value);
                }
                free(temp);
                free(temp2);
            }
        }
    }
    return count;
}

// Function to update the game board according to the rules of Conway's Game of Life
void update_board(int_stack_t *stk) {
    int_stack_t *temp = malloc(sizeof(int_stack_t));
    initialize_board(temp);
    for(int i = 0; i < WIDTH * HEIGHT; i++){
        int top_value;
        int_stack_top(stk, &top_value);
        int_stack_push(temp, top_value);
        int_stack_pop(stk, NULL);
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int value;
            int_stack_pop(temp, &value);
            int live_neighbors = count_live_neighbors(temp, i, j);
            if (value == ALIVE) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    int_stack_push(stk, DEAD);
                } else {
                    int_stack_push(stk, ALIVE);
                }
            } else {
                if (live_neighbors == 3) {
                    int_stack_push(stk, ALIVE);
                } else {
                    int_stack_push(stk, DEAD);
                }
            }
        }
    }
    free(temp);
}

int main() {
    int_stack_t *board = malloc(sizeof(int_stack_t));
    initialize_board(board);

    // Set initial configuration
    int_stack_t *temp = malloc(sizeof(int_stack_t));
    initialize_board(temp);
    for(int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if (i == 9 && (j == 10 || j == 11 || j == 12)){
                int_stack_push(temp, ALIVE);
            }
            else{
                int_stack_push(temp, DEAD);
            }
        }
    }
    for(int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            int value;
            int_stack_pop(temp, &value);
            int_stack_push(board, value);
        }
    }
    free(temp);

    // Run the game for 10 iterations
    for (int i = 0; i < 10; i++) {
        print_board(board);
        usleep(500000); // Sleep for 0.5 seconds
        update_board(board);
    }

    return 0;
}
