#include "Derived.h"
#include <stdio.h>

void DerivedPrint(void *b) {
    struct DerivedData *d = b;
    printf("%d %d\n", d->base.x, d->z);
}

void DerivedShow(void *d) {
    printf("Derived\n");
}

void DerivedHi(void *d) {
    printf("hi\n");
}

void virtualDerivedPrint(struct Derived d) {
    d.vptr->print(d.obj);
}

void virtualDerivedHi(struct Derived d) {
    d.vptr->hi(d.obj);
}

struct Base toBase(struct DerivedData* obj) {
    return (struct Base) {
        .obj = obj,
        .print = DerivedPrint
    };
}

const static struct DerivedTable vtable = {
    .print = DerivedPrint,
    .hi = DerivedHi
};

struct Derived toDerived(struct DerivedData *obj) {
    return (struct Derived) {
        .obj = obj,
        .vptr = &vtable
    };
}

void DerivedInit(struct DerivedData *obj, int x, int z) {
    obj->base.x = x;
    obj->z = z;
}