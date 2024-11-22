#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BOARD_SIZE 5

void createEmptyList(treeNodeList* list) {
	list->head = NULL;
	list->tail = NULL;
}
treeNodeListCell* createNewTreeNodeListCell(chessPos cp, treeNodeListCell* next)
{
	treeNodeListCell* TNLC = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	TNLC->node = (treeNode*)malloc(sizeof(treeNode));
	TNLC->node->position[0] = cp[0]; // Set position
	TNLC->node->position[1] = cp[1]; // Set position
	TNLC->next = next; // Set next cell
	return TNLC;
}
chessPosCell* createNewchessPosCell(chessPos position, chessPosCell* next)
{
	chessPosCell* res;
	res = (chessPosCell*)malloc(sizeof(chessPosCell));
	res->position[0] = position[0];
	res->position[1] = position[1];
	res->next = next;
	return res;
}

void insertchessPosCellToEndList(chessPosList* lst, chessPosCell* newcell)
{
	if (lst->tail == NULL)
	{
		lst->head = lst->tail = newcell;
	}
	else
	{
		lst->tail->next = newcell;
		lst->tail = newcell;
	}

}
void inserttreeNodeListCellToEndList(treeNodeList* lst, treeNodeListCell* newTail) {
	if (lst->tail == NULL) {
		// If list is empty, set head and tail to new node
		lst->head = lst->tail = newTail;
	}
	else {
		// Link current tail to new node and update tail to the new node
		lst->tail->next = newTail;
		lst->tail = newTail;
	}
}
void printTreeNodeList(chessPosList* lst) {
	if (lst == NULL || lst->head == NULL) {
		printf("List is empty.\n");
		return;
	}
	printf("Knight's Path:\n");
	chessPosCell* curr = lst->head;
	while (curr != NULL) {
		printf("%c%c -> ", curr->position[0], curr->position[1]);
		curr = curr->next;
	}
	printf("End\n");
}

void checkMemory(void* ptr)
{
	if (ptr == NULL) {
		printf("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
}

int** BuildChessBoard() {
	// Allocate memory for the board, which is an array of char* (pointers to char)
	int** board = (int**)malloc(BOARD_SIZE * sizeof(int*));
	if (board == NULL) {
		// If memory allocation fails, print an error message and exit
		printf("Memory allocation error\n");
		exit(1);
	}
	
	// Loop to allocate memory for each row of the board
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
		if (board[i] == NULL) {
			// If memory allocation fails, print an error message and exit
			printf("Memory allocation error\n");
			exit(1);
		}
		
		// Initialize each cell in the row to '.'
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = 0;
		}

	}
	return board; // Return the pointer to the board
}
void printChessBoard(int** board) {
	// Loop to print each row of the board
	for (int i = 0; i < BOARD_SIZE; i++)
		printf(" %2d ", i + 1);
	printf("\n");
	for (int i = 0; i < BOARD_SIZE; i++) {
		// Loop to print each column in the current row
		printf("%c" , 'A' + i);
		for (int j = 0; j < BOARD_SIZE; j++) {
			printf("%c", '|');
			printf("%d", board[i][j]);
			printf("%c", '|');
		}
		printf("\n"); // Print a newline after each row
	}
}