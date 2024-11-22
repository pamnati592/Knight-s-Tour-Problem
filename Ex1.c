#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BOARD_SIZE 5



chessPosArray*** validKnightMoves() {
    chessPosArray*** finalArray = (chessPosArray***)malloc(sizeof(chessPosArray**) * BOARD_SIZE);
    if (finalArray == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    buildInsideArray(&finalArray);
    return finalArray;
}

// Function to build an array of valid knight moves from a given position
chessPos* buildKnightArrayPos(int row, int col, int* size) {
    int j = 0;
    chessPos* arr = (chessPos*)malloc(sizeof(chessPos) * 8);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Define all possible knight moves
    int possibleMoves[8][2] = {
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
        {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
    };

    // Check each possible move for validity
    for (int i = 0; i < 8; i++) {
        int newRow = row + possibleMoves[i][0];
        int newCol = col + possibleMoves[i][1];

        // If the new position is within the board limits, add it to the array
        if (newRow >= 0 && newRow <= 4 && newCol >= 0 && newCol <= 4) {
            arr[j][0] = 'A' + newRow ; // Convert row index to char
            arr[j][1] = '1' + newCol ; // Convert column index to char
            j++;
        }
    }

    *size = j; // Set the size of the valid moves array
    arr = (chessPos*)realloc(arr, j * sizeof(chessPos)); // Resize the array to the exact number of valid moves
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    return arr;
}


// Function to build the 3D array of knight moves
void buildInsideArray(chessPosArray**** arr) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        (*arr)[i] = (chessPosArray**)malloc(sizeof(chessPosArray*) * BOARD_SIZE);
        if ((*arr)[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        for (int j = 0; j < BOARD_SIZE; j++) {
            int size = 0;
            (*arr)[i][j] = (chessPosArray*)malloc(sizeof(chessPosArray));
            if ((*arr)[i][j] == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }
            // Build the array of valid moves for the position (i+1, j+1)
            (*arr)[i][j]->positions = buildKnightArrayPos(i , j, &size);
            (*arr)[i][j]->size = size; // Set the size of the valid moves array
        }
    }
}

