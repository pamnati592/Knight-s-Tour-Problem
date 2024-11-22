#ifndef __HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 5

typedef char chessPos[2];

// Forward declarations
typedef struct _treeNode treeNode;
typedef struct _treeNodeList treeNodeList;
typedef struct _treeNodeListCell treeNodeListCell;
typedef struct _pathTree pathTree;
typedef struct _chessPosCell chessPosCell;
typedef struct _chessPosList chessPosList;
typedef struct chessPosArray chessPosArray;

// Structure definitions
struct _treeNodeList {
    treeNodeListCell* head;
    treeNodeListCell* tail;
};

struct _treeNode {
    chessPos position;
    treeNodeList next_possible_positions;
};

struct _treeNodeListCell {
    treeNode* node;
    treeNodeListCell* next;
};

struct _pathTree {
    treeNode* root;
    int count;
};

struct chessPosArray {
    unsigned int size;
    chessPos* positions;
};

struct _chessPosCell {
    chessPos position;
    chessPosCell* next;
};

struct _chessPosList {
    chessPosCell* head;
    chessPosCell* tail;
};

// Function prototypes
void checkMemory(void* ptr);
void display(chessPosList* lst);
chessPosArray*** validKnightMoves();
void buildInsideArray(chessPosArray**** array);
chessPos* buildKnightArrayPos(int row, int col, int* size);
int** BuildChessBoard();
void printChessBoard(int** board);
pathTree findAllPossibleKnightPaths(chessPos* startingPosition);
treeNode* findAllPossibleKnightPathsHelper(chessPos* startingPosition, bool** array,  chessPosArray*** validMoves ,int* count);
void createEmptyList(treeNodeList*);
chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);
chessPosList* findKnightPathCoveringAllBoardHelper(treeNode* root, chessPosList* lst, int level); 
void printTreeNodeList(chessPosList* lst);
treeNodeListCell* createNewTreeNodeListCell(chessPos cp, treeNodeListCell* next);
void inserttreeNodeListCellToEndList(treeNodeList* lst, treeNodeListCell* newTail);
chessPosCell* createNewchessPosCell(chessPos position, chessPosCell* next);
void insertchessPosCellToEndList(chessPosList* lst, chessPosCell* newcell);
#endif // __HEADER_H