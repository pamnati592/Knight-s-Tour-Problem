#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BOARD_SIZE 5

void display(chessPosList* lst) {
    int counter = 1;
    int** board = BuildChessBoard();

    // Declare a 5x5 array of bool and initialize all elements to false
    bool array[BOARD_SIZE][BOARD_SIZE] = { false };

    // Initialize pointers to traverse the list
    chessPosCell* current = lst->head;
    chessPosCell* prev = NULL;

    // Traverse the list
    while (current != NULL) {
        // Convert chess position to array indices
        int row = current->position[0] - 'A';
        int col = current->position[1] - '1';

        // If the position has not been visited
        if (!array[row][col]) {
            array[row][col] = true; // Mark the position as visited
            board[row][col] = counter; // Place the counter on the board
            prev = current; // Update prev to current
        }
        else {
            // Duplicate found, remove it from the list
            if (prev != NULL) {
                prev->next = current->next; // Skip the current node
                free(current); // Free the memory allocated for the current node
                current = prev->next; // Move to the next node
                continue; // Skip the rest of the loop iteration
            }
        }

        // Move to the next node in the list
        current = current->next;
        counter++; // Increment the counter for the next position
    }

    // Print the board
    printChessBoard(board);

    // Free the allocated memory for the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
}