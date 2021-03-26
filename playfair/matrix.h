#ifndef PLAYFAIR_MATRIX_H
#define PLAYFAIR_MATRIX_H


void generaMat(char matrix[][5], char *key, char *alfa);

char getCharInMatrix(char mat[][5], int col, int row);

void seachInMatrix(char mat[][5], char c, int *col, int *row);

int matrix5(int a);

void differentRowCol(char mat[][5], int *col, int *row, char *out);

#endif //PLAYFAIR_MATRIX_H