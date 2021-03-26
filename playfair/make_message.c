#include <string.h>
#include <stdlib.h>
#include "make_message.h"

char *prepareMsg(char *mex, char *missing, char *special, char *alfa) {
    removeSpaces(mex);
    checkMissing(alfa, mex, missing);
    return checkSpecial(mex, special);
}

void removeDoubles(char *string) {
    int n = strlen(string);
    int k;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; string[j] != '\0'; j++) {
            if (string[j] == string[i]) {
                for (k = j; string[k] != '\0'; k++) {
                    string[k] = string[k + 1];
                }
            }
        }
    }
}

void removeSpaces(char *string) {
    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != ' ') {
            string[count++] = string[i];
        }
    }
    string[count] = '\0';
}



void checkMissing(char *alfa, char *mex, char *missing) {
    int n = strlen(mex);
    for (int i = 0; i < n; i++) {
        if (strchr(alfa, mex[i]) == NULL) {
            mex[i] = *missing;
        }
    }
}

int countDoubles(char *string) {
    int n = strlen(string);
    int count = 0;
    for (int i = 1; i < n; i += 2) {
        if (string[i] == string[i - 1]) {
            count++;
        }
    }
    return count;
}

char *checkSpecial(char *mex, char *special) {
    int n = strlen(mex);
    int resultLen = n + countDoubles(mex) + 2;
    char *out = calloc(resultLen, sizeof(char));


    if (countDoubles(mex) == 0 && (n % 2) != 0) {
        strcpy(out, mex);
        strncat(out, special, 1);
        return out;
    }

    for (int i = 1; i < n + 1; i += 2) {
        if (mex[i] == mex[i - 1]) {
            strncat(out, &mex[i - 1], 1);
            strncat(out, special, 1);
            strncat(out, &mex[i], 1);
        } else {
            strncat(out, &mex[i - 1], 1);
            strncat(out, &mex[i], 1);
        }
    }

    if (strlen(out) % 2 != 0) {
        strcat(out, special);
    }
    return out;
}



