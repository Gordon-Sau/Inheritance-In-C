#include "P.h"
#include "I1.h"
#include "G.h"

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

const struct PAbstractClass pClass = {
    .classBase = {
        .parent = &gClass,
        .numI = 3,
        .numVMethod = -1
    },
    .interfacesIds = {
        1, 2, 3
    }
};
