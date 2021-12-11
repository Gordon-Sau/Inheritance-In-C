#include "MITMusician.h"
#include <stddef.h>
#include <stdint.h>

struct mitStuVtable {
    uint64_t offset;
};

struct musicianVtable {
    uint64_t offset;
};

const static struct mitStuVtable mitStuVtable = {
    offsetof(struct MITMusician, stu)
};

const static struct musicianVtable musicianVtable = {
    offsetof(struct MITMusician, stu) + offsetof(struct Student, people)
};

void MITMusicianInit(struct MITMusician *mm, char *name, int age,
char *major, int id, char *instruments) {
    PeopleInit(&mm->stu.people, name, age);
    StudentInit(&mm->stu, major);
    MITStudentInit(&mm->mitStu, id);
    MusicianInit(&mm->musician, instruments);
    mm->mitStu.stuVptr = &mitStuVtable;
    mm->musician.peoVptr = &musicianVtable;
}
