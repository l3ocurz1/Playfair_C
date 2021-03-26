#include "playfair_procedure.h"
#include <string.h>
#include "matrix.h"

void encodeRules(char mat[][5], int *col, int *row, char *out) {
    if (col[0] == col[1]) {
        sameColEncode(mat, col, row, out);
    } else if (row[0] == row[1]) {
        sameRowEncode(mat, col, row, out);
    } else {
        differentRowCol(mat, col, row, out);
    }
}

void sameColEncode(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, col[0], matrix5(row[0] + 1));
    char b = getCharInMatrix(mat, col[1], matrix5(row[1] + 1));
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}

void sameRowEncode(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, matrix5(col[0] + 1), row[0]);
    char b = getCharInMatrix(mat, matrix5(col[1] + 1), row[1]);
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}

void decodeRules(char mat[][5], int *col, int *row, char *out) {
    if (col[0] == col[1]) {
        sameColDecode(mat, col, row, out);
    } else if (row[0] == row[1]) {
        sameRowDecode(mat, col, row, out);
    } else {
        differentRowCol(mat, col, row, out);
    }
}

void sameColDecode(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, col[0], matrix5(row[0] - 1));
    char b = getCharInMatrix(mat, col[1], matrix5(row[1] - 1));
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}

void sameRowDecode(char mat[][5], int *col, int *row, char *out) {
    char a = getCharInMatrix(mat, matrix5(col[0] - 1), row[0]);
    char b = getCharInMatrix(mat, matrix5(col[1] - 1), row[1]);
    strncat(out, &a, 1);
    strncat(out, &b, 1);
    strcat(out, " ");
}


