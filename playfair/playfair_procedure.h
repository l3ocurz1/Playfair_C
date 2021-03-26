//
// Created by leocu on 12/03/2021.
//

#ifndef PLAYFAIR_PLAYFAIR_PROCEDURE_H
#define PLAYFAIR_PLAYFAIR_PROCEDURE_H

#endif //PLAYFAIR_PLAYFAIR_PROCEDURE_H
void encodeRules(char mat[][5], int *col, int *row, char *out);

void sameColEncode(char mat[][5], int *col, int *row, char *out);

void sameRowEncode(char mat[][5], int *col, int *row, char *out);

void decodeRules(char mat[][5], int *col, int *row, char *out);

void sameColDecode(char mat[][5], int *col, int *row, char *out);

void sameRowDecode(char mat[][5], int *col, int *row, char *out);