#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <stdio.h>
#include "file.h"

char *readFiles(char *fname) {
    long nbytes;
    FILE *fin;
    fin = fopen(fname, "r");
    if (fin == NULL) {
        printf("Il seguente file è impossibile da aprire: %s\n", fname);
        exit(-1);
    }

    fseek(fin, 0L, SEEK_END);
    nbytes = ftell(fin);
    fseek(fin, 0L, SEEK_SET);
    char *buffer = calloc(nbytes + 1, sizeof(char));
    if (buffer == NULL) {
        printf("Errore nella lettura del file: %s\n", fname);
        exit(-1);
    }
    fread(buffer, sizeof(char), nbytes, fin);
    fclose(fin);

    buffer[nbytes] = '\0';

    return buffer;
}
void removeExtension(char *name) {
    char *end = name + strlen(name);
    while (end > name && *end != '.' && *end != '\\' && *end != '/') {
        --end;
    }
    if ((end > name && *end == '.') && (*(end - 1) != '\\' && *(end - 1) != '/')) {
        *end = '\0';
    }

}

char *createPfExtension(char *dirname, char *fname) {
    char *name = calloc(strlen(dirname) + strlen(basename(fname)) + 4, sizeof(char));
    strcpy(name, dirname);
    strcat(name, "/");
    strcat(name, basename(fname));
    removeExtension(name);
    strcat(name, ".pf");
    return name;
}

char *createDecExtension(char *dirname, char *fname) {
    char *name = calloc(strlen(dirname) + strlen(basename(fname)) + 4, sizeof(char));
    strcpy(name, dirname);
    strcat(name, "/");
    strcat(name, basename(fname));
    removeExtension(name);
    strcat(name, ".dec");
    return name;
}



void saveFile(char *mex, char *dirname, char *fname, _Bool coding) {
    char *dirpath;
    if (coding) {
        dirpath = createPfExtension(dirname, fname);
    } else {
        dirpath = createDecExtension(dirname, fname);
    }

    FILE *file;
    file = fopen(dirpath, "w");
    if (file == NULL) {
        printf("File non salvato correttamente\n");
        exit(-1);
    }
    fputs(mex, file);
    fclose(file);
}




