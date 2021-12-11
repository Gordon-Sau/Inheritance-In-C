#include <stdio.h>
#include <stdlib.h>

#include "People.h"
#include "MITStudent.h"
#include "Musician.h"
#include "MITMusician.h"

int main(void) {
    struct MITMusician mm = {
        .name = "Tom",
        .age = 19,
        .major = "Music",
        .id = 234564,
        .instruments = "Guitar, Piano"
    };
    struct People p = toPeople(&mm);
    peoplePrintName(p);
    printf("%d\n", peopleGetAge(p));
    
    struct MITStudent mitSTu = toMITStudent(&mm);
    MITStudentPrintName(mitSTu);
    printf("%d\n", MITStudentGetAge(mitSTu));
    MITStudentPrintSchoolId(mitSTu);
    MITStudentPrintMajor(mitSTu);

    struct Musician musician = toMusician(&mm);
    musicianPrintName(musician);
    printf("%d\n", musicianGetAge(musician));
    musicianPrintInstrument(musician);

    // casting musician to people
    // method 1: we already have the vtable
    struct People musicianToPeople = toPeople((struct MITMusician*)musician.object);

    // method 2:
    // create a new method table dynamicly if we do not have the vtable yet. Once created we may cached it and reuse it.
    struct PeopleVtableStruct *newVptr = NULL;
    newVptr = malloc(sizeof(struct PeopleVtableStruct));
    newVptr->getAge = musician.vptr->people.getAge;
    newVptr->printName = musician.vptr->people.printName;
    
    musicianToPeople.object = musician.object;
    musicianToPeople.vptr = newVptr;

}