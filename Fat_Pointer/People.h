/*
type People interface {
    printName()
    getAge() int
}
*/
#pragma once

struct PeopleVtableStruct {
    void (*printName)(void *);
    int (*getAge)(void *);
};

struct People {
    void *object;
    const struct PeopleVtableStruct *vptr;
};

void peoplePrintName(struct People people);
int peopleGetAge(struct People people);
