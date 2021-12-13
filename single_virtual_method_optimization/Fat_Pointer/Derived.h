#pragma once
#include "Base.h"
/*
class Derived: Base {
    int z;

    void print() override {
        printf("%d %d\n", x, z);
    }

    void show() {
        printf("Derived\n");
    }

    virtual void hi() {
        printf("hi\n");
    }
}
*/
struct DerivedData {
    struct BaseData base;
    int z;
};

struct DerivedTable {
    void (*print)(void *);
    void (*hi)(void *);
};

struct Derived {
    const struct DerivedTable *vptr;
    void *obj;
};

void DerivedPrint(void *);
void DerivedShow(void *);
void DerivedInit(struct DerivedData *, int, int);
void DerivedHi(void *);

struct Base toBase(struct DerivedData* obj);
struct Derived toDerived(struct DerivedData *obj);
