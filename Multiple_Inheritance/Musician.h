#pragma once
#include "People.h"
/*
class Musician: People {
    char *instrument;
    void printInstrument() {
        printf("%s\n", instrument);
    }
}
*/
struct Musician {
    struct People people;
    char *instrument;
};
void printInstrument(struct Musician *); 
void MusicianInit(struct Musician *, char *);
