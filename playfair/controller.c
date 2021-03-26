#include <string.h>
#include "controller.h"
#include "encode_decode.h"
#include "file.h"
#include "matrix.h"
#include "make_message.h"
#include "check.h"

char mat[5][5];

void setUpData(int argc, char **argv, _Bool coding) {
    char *out = readFiles(argv[2]);
    char delim[] = "\r\n";
    char *alfa = strtok(out, delim);
    char *missing = strtok(NULL, delim);
    char *special = strtok(NULL, delim);
    char *key = strtok(NULL, delim);
    checkKeyfile(alfa, missing, special, key);
    generaMat(mat, key, alfa);


    for (int i = 4; i < argc; i++) {
        char *result = elaborateData(readFiles(argv[i]), missing, special, alfa, coding);
        saveFile(result, argv[3], argv[i], coding);
    }

}

char *elaborateData(char *mex, char *missing, char *special, char *alfa, _Bool coding) {
    checkMsg(mex);
    if (coding) {
        return encodeMsg(mat, prepareMsg(mex, missing, special, alfa));
    } else {
        removeSpaces(mex);
        checkDecodeMsg(mex);
        return decodeMsg(mat, mex);
    }
}



