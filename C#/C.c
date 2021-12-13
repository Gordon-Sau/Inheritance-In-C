#include "C.h"
#include "I1.h"
#include "I2.h"
#include "I3.h"
#include "I4.h"
#include "I5.h"
#include "InterafaceId.h"
#include <stddef.h>

int CDefaultMyHash(void *obj) {
    struct C *c = obj;
    return c->data.y ^ c->data.z;
}

int CDefaultGetPriority(void *obj) {
    return 1;
}

int CDefaultGetNum(void *obj) {
    struct C *c = obj;
    return CMyHash(obj) + c->data.y + c->data.z;
}

void CDefaultSetY(void *obj, int y) {
    struct C *c = obj;
    c->data.y = y;
}

void CDefaultUpdate(void *obj) {
    struct C *c = obj;
    c->data.base.base.a++;
    c->data.base.base.b--;
    c->data.base.base.c++;
    c->data.base.base.d--;
    c->data.y += 2;
    c->data.z -= 2;
}

int CComputeX(void *obj) {
    struct C *c = obj;
    return c->klass->vtable.base.base.computeX(obj);
}

void CUpdate(void *obj) {
    struct C *c = obj;
    c->klass->vtable.base.base.update(obj);
}

int CUpdateAndComputeX(void *obj) {
    struct C *c = obj;
    return c->klass->vtable.base.base.updateAndComputeX(obj);
}

void CPrintInt(void *obj, int x) {
    struct C *c = obj;
    c->klass->vtable.base.base.printInt(obj, x);
}

int CGetToken(void *obj) {
    struct C *c = obj;
    return c->klass->vtable.base.base.getToken(obj);
}

int CGetPriority(void *obj) {
    struct C *c = obj;
    return c->klass->vtable.base.getPriority(obj);
}

int CMyHash(void *obj) {
    struct C *c = obj;
    return c->klass->vtable.base.myHash(obj);
}

int CGetNum(void *obj) {
    struct C *c = obj;
    return c->klass->vtable.getNum(obj);
}

void CSetY(void * obj, int y) {
    struct C *c = obj;
    return c->klass->vtable.setY(obj, y);
}

const static struct I4Table {
    const enum InterfaceId id;
    const unsigned int table[N_I4_METHODS];
} i4Table = {
    .id = I4,
    .table = {
        (offsetof(struct CTableStruct, base) +
            offsetof(struct PTableStruct, base) +
            offsetof(struct GTableStruct, computeX)) / sizeof(void *),
        (offsetof(struct CTableStruct, base) + 
            offsetof(struct PTableStruct, base) +
            offsetof(struct GTableStruct, printInt)) / sizeof(void *),
        offsetof(struct CTableStruct, getNum) / sizeof(void *)
    }
};

const static struct I5Table {
    const enum InterfaceId id;
    const unsigned int table[N_I5_METHODS];
} i5Table = {
    .id = I5,
    .table = { offsetof(struct CTableStruct, setY) /sizeof(void *) }
};

const struct CClass cClass = {
    .classBase = {
        .parent = &pClass,
        .numI = 2,
        .numVMethod = 9,
    },
    .vtable = {
           .base = {
            .base = {
                .computeX = GDefaultComputeX,
                .getToken = PDefaultgetToken,
                .printInt = I4DefaultPrintInt,
                .update = CDefaultUpdate,
                .updateAndComputeX = PDefaultUpdateAndComputeX
            },
            .getPriority = CDefaultGetPriority,
            .myHash = CDefaultMyHash
        },
        .getNum = CDefaultGetNum,
        .setY = CDefaultSetY
    },
    .itables = {
        &i4Table,
        &i5Table
    }
};

void CInit(struct C *c) {
    c->klass = &cClass;
    c->data.base.base.a = 0;
    c->data.base.base.b = 0;
    c->data.base.base.c = 0;
    c->data.base.base.d = 0;
    c->data.y = 0;
    c->data.z = 0;
}
