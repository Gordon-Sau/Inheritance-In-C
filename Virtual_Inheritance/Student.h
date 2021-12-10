#pragma once
#include "People.h"
/*
class Student: People {
    char *major;
    void printMajor() {
        printf("%s\n", major);
    }
}
*/
struct Student {
    struct People people;
    char *major;
};

void printMajor(struct Student *);
void StudentInit(struct Student *,  char *);