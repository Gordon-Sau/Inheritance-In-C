#include <stdio.h>
#include "MITStudent.h"

void MITStudentPrintSchoolId(struct MITStudent mitStu) {
    mitStu.vptr->printSchoolId(mitStu.obj);
}

void MITStudentPrintMajor(struct MITStudent mitStu) {
    mitStu.vptr->printMajor(mitStu.obj);
}

void MITStudentPrintName(struct MITStudent mitStu) {
    mitStu.vptr->people.printName(mitStu.obj);
}

int MITStudentGetAge(struct MITStudent mitStu) {
    return mitStu.vptr->people.getAge(mitStu.obj);
}
