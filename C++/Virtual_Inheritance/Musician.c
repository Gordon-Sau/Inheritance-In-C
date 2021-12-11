#include "Musician.h"
#include <stdio.h>
#include <stdint.h>

void printInstrument(struct Musician *musician) {
    printf("%s\n", musician->instrument);
}

void MusicianInit(struct Musician *musician, char *instrument) {
    musician->instrument = instrument;
}

struct People *MusicianCast(struct Musician *musician) {
    uint64_t offset = ((int *)musician->peoVptr)[0];
    return (struct People *) ((char *)musician + offset);
}
