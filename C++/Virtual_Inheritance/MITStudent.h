#pragma once
#include "Student.h"
/*
class MITStudent: virtual Student {
    int id;
    void printSchoolId() {
        printf("%d\n", id);
    }
}
*/

struct MITStudent {
    // struct Student stu;
    void *stuVptr;
    int id;
};

void printSchoolId(struct MITStudent *);
void MITStudentInit(struct MITStudent *, int);
struct Student *MITStudentCast(struct MITStudent *);
