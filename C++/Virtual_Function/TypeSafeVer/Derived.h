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
    virtual void bye() {
        printf("bye\n");
    }
}
*/

struct Derived {
    struct Base base;
    int z;
};

struct DerivedVtable {
    struct Vtable baseVtable;
    void (*bye)(struct Derived *);
};

void DerivedPrint(struct Base *);
void DerivedShow(struct Derived *);
void DerivedBye(struct Derived *);
void DerivedInit(struct Derived *, int, int);

void virtualDerivedHi(struct Derived *d);
void virtualDerivedPrint(struct Derived *d);
void virtualDerivedBye(struct Derived *d);
