/*
type Musician interface {
    printName()
    getAge() int
    printInstrument()
}
*/

#pragma once
#include "People.h"

struct MusicianVtableStruct {
    struct PeopleVtableStruct people;
    void (*printInstrument)(void *);
};

struct Musician {
    void *object;
    const struct MusicianVtableStruct *vptr;
};

void musicianPrintInstrument(struct Musician musician);
void musicianPrintName(struct Musician musician);
int musicianGetAge(struct Musician musician);
