#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BOARD_SIZE 5



pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
    // Initialize a boolean array to track visited positions
    bool** array = (bool**)malloc(sizeof(bool*) * BOARD_SIZE);
    checkMemory(array);
    for (int i = 0; i < BOARD_SIZE; i++) {
        array[i] = (bool*)calloc(BOARD_SIZE, sizeof(bool));
        checkMemory(array[i]);
    }
    chessPosArray*** validMoves = validKnightMoves();

    // Initialize the pathTree and allocate memory for the root node
    pathTree tr;
    tr.root = (treeNode*)malloc(sizeof(treeNode));
    checkMemory(tr.root);
    tr.count = 0;
    // Recursively find all possible knight paths
    tr.root = findAllPossibleKnightPathsHelper(startingPosition, array, validMoves, &tr.count);

    // Free the memory used for validMoves
    free(validMoves);
    // Free the memory used for the visited array
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(array[i]);
    }
    free(array);

    // Return the pathTree
    return tr;
}

treeNode* findAllPossibleKnightPathsHelper(chessPos* startingPosition, bool** array, chessPosArray*** validMoves, int* count)
{
    bool stop = true;
    treeNode* res;
    res = (treeNode*)malloc(sizeof(treeNode));
    checkMemory(res);
    res->position[0] = startingPosition[0][0];
    res->position[1] = startingPosition[0][1];
    treeNodeList* saver = &(res->next_possible_positions);
    createEmptyList(saver);
    int row = res->position[0] - 'A';
    int col = res->position[1] - '1';
    array[row][col] = true;
    for (int i = 0; i < validMoves[row][col]->size; i++)
    {
        int NewRow = validMoves[row][col]->positions[i][0] - 'A';
        int NewCol = validMoves[row][col]->positions[i][1] - '1';
        // Check if the new position is not visited
        if (!array[NewRow][NewCol])
        {
            stop = false;
            // Add the new position to the list of next possible positions
            treeNodeListCell* Cell = createNewTreeNodeListCell(validMoves[row][col]->positions[i], NULL);
            inserttreeNodeListCellToEndList(saver, Cell);

            // Recursively find all possible paths from the new position
            Cell->node = findAllPossibleKnightPathsHelper(&(Cell->node->position), array, validMoves, count);
        }
    }
    if (stop)
    {
        res->next_possible_positions.head = res->next_possible_positions.tail = NULL;
        (*count)++;
    }
    // Reset the state when backtracking
    array[row][col] = false;

    return res;
}