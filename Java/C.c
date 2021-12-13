#include "C.h"
#include "I1.h"
#include "I2.h"
#include "I3.h"
#include "I4.h"
#include "I5.h"
#include "InterafaceId.h"

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

const static struct I1Table {
    const enum InterfaceId id;
    const struct I1TableStruct table;
} i1Table = {
    .id = I1,
    .table = {
        .computeX = GDefaultComputeX,
        .update = CDefaultUpdate,
        .updateAndComputeX = PDefaultUpdateAndComputeX
    },
};

const static struct I2Table {
    const enum InterfaceId id;
    const struct I2TableStruct table;
} i2Table = {
    .id = I2,
    .table = {
        .computeX = GDefaultComputeX,
        .printInt = GPrintInt
    }
};

const static struct I3Table {
    const enum InterfaceId id;
    const struct I3TableStruct table;
} i3Table = {
    .id = I3,
    .table = {
        .getPriority = CDefaultGetPriority
    }
};

const static struct I4Table {
    const enum InterfaceId id;
    const struct I4TableStruct table;
} i4Table = {
    .id = I4,
    .table = {
        .i2Table = {
            .computeX = GDefaultComputeX,
            .printInt = GPrintInt
        },
        .getNum = CDefaultGetNum
    }
};

const static struct I5Table {
    const enum InterfaceId id;
    const struct I5TableStruct table;
} i5Table = {
    .id = I5,
    .table = {
        .setY = CDefaultSetY
    }
};

const struct CClass cClass = {
    .classBase = {
        .parent = &pClass,
        .numI = 5,
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
        &i1Table,
        &i2Table,
        &i3Table,
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
