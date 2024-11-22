#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BOARD_SIZE 5

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree)
{
    chessPosList* lst = (chessPosList*)malloc(sizeof(chessPosList));
    checkMemory(lst);
    lst->head = NULL;
    lst->tail = NULL;
    int level = 1;
    lst = findKnightPathCoveringAllBoardHelper(path_tree->root, lst, level);
    return lst;
}

chessPosList* findKnightPathCoveringAllBoardHelper(treeNode* root, chessPosList* lst, int level) {
    if (root == NULL) {
        return NULL;
    }
    insertchessPosCellToEndList(lst, createNewchessPosCell(root->position, NULL)); // Insert the current position into the list 
    if (level == BOARD_SIZE * BOARD_SIZE) {
        return lst;
    }
    treeNodeListCell* currCP = root->next_possible_positions.head; // Get the head of the list of next possible positions
    while (currCP != NULL) {
        chessPosList* result = findKnightPathCoveringAllBoardHelper(currCP->node, lst, level + 1); // Recursive call to explore the next position
        if (result != NULL) {
            return result; // If a valid path is found, return the result
        }
        currCP = currCP->next; // Move to the next position in the list
    }

    // Backtrack: remove the current position from the list
    chessPosCell* temp = lst->tail;
    if (lst->head == lst->tail) {
        lst->head = lst->tail = NULL;
    }
    else {
        chessPosCell* prev = lst->head;
        while (prev->next != lst->tail) {
            prev = prev->next;
        }
        prev->next = NULL;
        lst->tail = prev;
    }
    free(temp);

    return NULL;
}

void freeChessPosList(chessPosList* lst) {
    chessPosCell* current = lst->head;
    chessPosCell* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(lst);
}