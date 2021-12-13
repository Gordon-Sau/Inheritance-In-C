#include "G.h"
#include "I1.h"
#include "I2.h"
#include "InterafaceId.h"
#include <stdio.h>

static int token = 0;

int GDefaultComputeX(void *obj) {
    struct G * g = obj;
    return g->data.a * g->data.b + g->data.c * g->data.d;
}

void GDefaultUpdate(void *obj) {
    struct G *g = obj;
    g->data.a ++;
    g->data.b --;
    g->data.c += 2;
    g->data.d -= 3;
}

void GDefaultPrintInt(void *obj, int x) {
    printf("%d\n", x);
}

int GDefaultgetToken(void *obj) {
    token++;
    return token;
}

int GComputeX(void *obj) {
    struct G * g = obj;
    return g->klass->vtable.computeX(obj);
}

void GUpdate(void *obj) {
    struct G *g = obj;
    g->klass->vtable.update(obj);
}

int GUpdateAndComputeX(void *obj) {
    struct G *g = obj;
    return g->klass->vtable.updateAndComputeX(obj);
}

void GPrintInt(void *obj, int x) {
    struct G *g = obj;
    g->klass->vtable.printInt(obj, x);
}

int GGetToken(void *obj) {
    struct G *g = obj;
    return g->klass->vtable.getToken(obj);
}

const static struct I1Table {
    const enum InterfaceId id;
    const struct I1TableStruct table;
} i1Table = {
    .id = 1,
    .table = {
        .computeX = GDefaultComputeX,
        .update = GDefaultUpdate,
        .updateAndComputeX = I1DefaultUpdateAndComputeX
    }
};

const static struct I2Table {
    const enum InterfaceId id;
    const struct I2TableStruct table;
} i2Table = {
    .id = 1,
    .table = {
        .computeX = GDefaultComputeX,
        .printInt = GDefaultPrintInt
    }
};

const struct GClass gClass = {
    .classBase = {
        .numI = 2,
        .numVMethod = 5,
        .parent = NULL
    },
    .vtable = {
        .computeX = GDefaultComputeX,
        .getToken = GDefaultgetToken,
        .printInt = GDefaultPrintInt,
        .update = GDefaultUpdate,
        .updateAndComputeX = I1DefaultUpdateAndComputeX
    },
    .itable = {
        &i1Table,
        &i2Table
    }
};

void GInit(struct G *g) {
    g->klass = &gClass;
    g->data.a = 0;
    g->data.b = 0;
    g->data.c = 0;
    g->data.d = 0;
}
