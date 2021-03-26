
#ifndef PLAYFAIR_FILE_H
#define PLAYFAIR_FILE_H

#endif //PLAYFAIR_FILE_H

char *readFiles(char *fname);

char *createPfExtension(char *dirname, char *fname);

char *createDecExtension(char *dirname, char *fname);

void removeExtension(char *name);

void saveFile(char *mex, char *dirname, char *fname, _Bool coding);

