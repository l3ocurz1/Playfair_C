
#ifndef PLAYFAIR_ENCODE_H
#define PLAYFAIR_ENCODE_H

#endif //PLAYFAIR_ENCODE_H
void encodePair(char mat[][5], char first, char second, char *out);

char *encodeMsg(char mat[][5], char *mex);

void decodePair(char mat[][5], char first, char second, char *out);

char *decodeMsg(char mat[][5], char *mex);