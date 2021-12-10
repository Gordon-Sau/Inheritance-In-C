#pragma once
#include "People.h"
/*
class Musician: virtual People {
    char *instrument;
    void printInstrument() {
        printf("%s\n", instrument);
    }
}
*/
struct Musician {
    // struct People people;
    void *peoVptr;
    char *instrument;
};

void printInstrument(struct Musician *); 
void MusicianInit(struct Musician *, char *);
struct People *MusicianCast(struct Musician *);
