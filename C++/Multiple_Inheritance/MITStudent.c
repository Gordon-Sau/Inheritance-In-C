#include "MITStudent.h"
#include <stdio.h>

void printSchoolId(struct MITStudent * mitSTu) {
    printf("%d\n", mitSTu->id);
}

void MITStudentInit(struct MITStudent *mitStu, int id) {
    mitStu->id = id;
}
