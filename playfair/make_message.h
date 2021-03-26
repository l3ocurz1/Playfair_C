//
// Created by leocu on 12/03/2021.
//

#ifndef PLAYFAIR_MAKE_MESSAGE_H
#define PLAYFAIR_MAKE_MESSAGE_H

#endif //PLAYFAIR_MAKE_MESSAGE_H

char *prepareMsg(char *mex, char *missing, char *special, char *alfa);

void removeDoubles(char *string);

void removeSpaces(char *string);

void checkMissing(char *alfa, char *mex, char *missing);

int countDoubles(char *string);

char *checkSpecial(char *mex, char *special);