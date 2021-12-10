#include "Student.h"
#include <stdio.h>

void printMajor(struct Student * stu) {
    printf("%s\n", stu->major);
}

void StudentInit(struct Student *student,  char *major) {
    student->major = major;
}