/*
type MITStudent interface {
    printName()
    getAge() int
    printSchoolId()
    printMajor()
}
*/
#pragma once
#include "People.h"

struct MITStudentVtableStruct {
    struct PeopleVtableStruct people;
    void (*printSchoolId)(void *);
    void (*printMajor)(void *);
};

struct MITStudent {
    void *obj;
    const struct MITStudentVtableStruct *vptr;
};

void MITStudentPrintSchoolId(struct MITStudent mitStu);
void MITStudentPrintMajor(struct MITStudent mitStu);
void MITStudentPrintName(struct MITStudent mitStu);
int MITStudentGetAge(struct MITStudent mitStu);
