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
}
*/

struct Derived {
    struct Base base;
    int z;
};

void Derivedprint(struct Derived *);
void DerivedShow(struct Derived *);
void DerivedInit(struct Derived *, int, int);
