#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main() {
    chessPos pos;
    bool valid = false;
    char input[256] = "";// Buffer to store the input
    gets(input);
    if (strlen(input) == 2) {
        pos[0] = input[0];
        pos[1] = input[1];
        if (pos[0] >= 'A' && pos[0] <= 'E' && pos[1] >= '1' && pos[1] <= '5')
            valid = true;
    }
    if (valid)
    {
        pathTree paths = findAllPossibleKnightPaths(&pos);
        chessPosList* lst;
        lst = findKnightPathCoveringAllBoard(&paths);
        if (lst == NULL)
            printf("No knight's tour");
        else
            display(lst);

        return 0;
    }
    else
        printf("Invalid input.\n");
    return 0;
}