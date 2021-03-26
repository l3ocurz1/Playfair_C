#include <string.h>
#include <stdlib.h>
#include "make_message.h"
#include "matrix.h"

void generaMat(char matrix[][5], char *key, char *alfa) {
    removeSpaces(key);
    removeDoubles(key);
    char *Alfabet = calloc(26 + strlen(key), sizeof(char));
    strcpy(Alfabet, key);
    removeDoubles(strcat(Alfabet, alfa));
    int z = 0;
    for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 5; j++) {
            matrix[k][j] = Alfabet[z];
            z++;
        }
    }

    free(Alfabet);
    Alfabet = NULL;
}

char getCharInMatrix(char mat[][5], int col, int row) {
    return mat[row][col];
}

void seachInMatrix(char mat[][5], char c, int *col, int *row) {
    for (*col = 0; *col < 5; (*col)++) {
        for (*row = 0; *row < 5; (*row)++) {
            if (getCharInMatrix(mat, *col, *row) == c) {
                return;
            }
        }
    }
}

int matrix5(int a) {
    if (a < 0)
        return 4;
    else
        return (a % 5);
}

void differentRowCol(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, col[1], row[0]);
    char b = getCharInMatrix(mat, col[0], row[1]);
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}



