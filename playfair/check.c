#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "make_message.h"
#include "check.h"

void checkKeyfile(char *alfa, char *missing, char *special, char *key) {
    removeDoubles(alfa);
    checkAlfa(alfa);
    convertSingleChar(missing);
    convertSingleChar(special);
    checKey(key);
}

void checkMsg(char *str) {
    if (strlen(str) == 0) {
        printf("Il messaggio  deve avere almeno 1 carattere!\n");
        exit(-1);
    }
    upperCase(str);
}

void checkAlfa(char *str) {
    int i = strlen(str);
    if (i != 25) {
        printf("L'alfabete deve essere di 25 caratteri diversi, ne hai inseriti: %d", i);
        exit(-1);
    }
    checkAlfaChars(str);
    upperCase(str);
}

void convertSingleChar(char *str) {
    if (strlen(str) != 1) {
        printf("%s 1 carettere ", str);
        exit(-1);
    }
    upperCase(str);
}

void upperCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
}


void checkAlfaChars(char *str) {
    for (int i = 0; i < 25; i++) {
        if ((char_index(str[i]) < 0) || (char_index(str[i]) > 25)) {
            printf("Carattere non valido (%c) nell'alfabeto alla posizione %d!\n", str[i], i);
            exit(-1);
        }
    }
}

int char_index(char c) {
    return toupper(c) - 'A';
}

void checKey(char *str) {
    if (str == NULL) {
        printf("Almeno un carattere richiesto per la chiave\n"
               "Keyfile not valid\n");
        exit(-1);
    }
    upperCase(str);
}

void checkDecodeMsg(char *str) {
    if (strlen(str) % 2 != 0) {
        printf("Messaggio impossibile da decifrare\n");
        exit(-1);
    }
}