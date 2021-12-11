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
};
