#include <stdio.h>
#include "Musician.h"

void musicianPrintInstrument(struct Musician musician) {
    musician.vptr->printInstrument(musician.object);
}

void musicianPrintName(struct Musician musician) {
    musician.vptr->people.printName(musician.object);
}

int musicianGetAge(struct Musician musician) {
    return musician.vptr->people.getAge(musician.object);
}
