#include "Base.h"
#include <stdio.h>

void virtualPrint(struct Base base) {
    base.print(base.obj);
}

static int __getX(void *obj) {
    struct BaseData *base = obj;
    return base->x;
}

void BasePrint(void *base) {
    printf("%d\n", __getX(base));
}

int BaseSumX(void *base, int y) {
    return __getX(base) + y;
}

void BaseShow(void *base) {
    printf("Base\n");
}

void BaseHi(void *base) {
    printf("hi\n");
}

void BaseInit(struct BaseData *base, int x) {
    base->x = x;
}

struct Base BaseDataToBase(struct BaseData *obj) {
    return (struct Base){
        .obj = obj,
        .print = BasePrint
    };
}
