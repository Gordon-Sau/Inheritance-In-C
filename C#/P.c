#include "P.h"
#include "I1.h"
#include "G.h"
#include "InterafaceId.h"
#include <stddef.h>

int PDefaultgetToken(void *obj) {
    struct P *p = obj;
    return PMyHash(obj) * PComputeX(p);
}

int PDefaultGetPriority(void *obj) {
    struct C *c = obj;
    return 0;
}

int PDefaultUpdateAndComputeX(void *obj) {
    PUpdate(obj);
    return I1DefaultUpdateAndComputeX(obj);
}

int PComputeX(void *obj) {
    struct P *p = obj;
    return p->klass->vtable.base.computeX(obj);
}

void PUpdate(void *obj) {
    struct P *p = obj;
    p->klass->vtable.base.update(obj);
}

int PUpdateAndComputeX(void *obj) {
    struct P *p = obj;
    return p->klass->vtable.base.updateAndComputeX(obj);
}

void PPrintInt(void *obj, int x) {
    struct P *p = obj;
    p->klass->vtable.base.printInt(obj, x);
}

int PGetToken(void *obj) {
    struct P *p = obj;
    return p->klass->vtable.base.getToken(obj);
}

int PGetPriority(void *obj) {
    struct P *p = obj;
    return p->klass->vtable.getPriority(obj);
}

int PMyHash(void *obj) {
    struct P *p = obj;
    return p->klass->vtable.myHash(obj);
}

const static struct I3Table {
    const enum InterfaceId id;
    const unsigned int table[1];
} i3Table = {
    .id = I3,
    .table = { offsetof(struct PTableStruct, getPriority) / sizeof(void *)}
};

const struct PAbstractClass pClass = {
    .classBase = {
        .parent = &gClass,
        .numI = 1,
        .numVMethod = 0
    },
    .itables = {
        &i3Table
    }
};
