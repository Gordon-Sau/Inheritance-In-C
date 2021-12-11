#include "Musician.h"
#include <stdio.h>

void printInstrument(struct Musician *musician) {
    printf("%s\n", musician->instrument);
}
void MusicianInit(struct Musician *musician, char *instrument) {
    musician->instrument = instrument;
}
