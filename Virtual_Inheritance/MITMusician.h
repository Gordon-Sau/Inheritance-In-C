#pragma once
#include "MITStudent.h"
#include "Musician.h"
/*
class MITMusician: MITStudent, Musician {

}
*/

struct MITMusician {
    struct MITStudent mitStu;
    struct Musician musician;
    struct Student stu;
};

void MITMusicianInit(struct MITMusician *, char *name, int age,
    char *major, int id, char *instruments);
