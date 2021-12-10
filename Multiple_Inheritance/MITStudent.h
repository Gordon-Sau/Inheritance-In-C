#pragma once
#include "Student.h"
/*
class MITStudent: Student {
    int id;
    void printSchoolId() {
        printf("%d\n", id);
    }
}
*/
struct MITStudent {
    struct Student stu;
    int id;
};

void printSchoolId(struct MITStudent *);
void MITStudentInit(struct MITStudent *, int);
