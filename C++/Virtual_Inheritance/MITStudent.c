#include "MITStudent.h"
#include <stdio.h>
#include <stdint.h>

void printSchoolId(struct MITStudent * mitSTu) {
    printf("%d\n", mitSTu->id);
}

void MITStudentInit(struct MITStudent *mitStu, int id) {
    mitStu->id = id;
}

struct Student *MITStudentCast(struct MITStudent *mitStu) {
    uint64_t offset = ((int *)mitStu->stuVptr)[0];
    return (struct Student *) ((char *)mitStu + offset);
}
