#include "Base.h"
#include <stdio.h>

static void *baseVtable[] = {
    BasePrint,
    BaseHi
};

void virtualPrint(struct Base *base) {
    void (*print)(struct Base *);
    print = ((void **)base->vptr)[0];
    print(base);
}

void virtualHi(struct Base *base) {
    void (*hi)(struct Base *);
    hi = ((void **)base->vptr)[1];
    hi(base);
}

static int __getX(struct Base *base) {
    return base->x;
}

void BasePrint(struct Base *base) {
    printf("%d\n", __getX(base));
}

int BaseSumX(struct Base *base, int y) {
    return __getX(base) + y;
}

void BaseShow(struct Base *base) {
    printf("Base\n");
}

void BaseHi(struct Base *base) {
    printf("hi\n");
}

void BaseInit(struct Base *base, int x) {
    base->vptr = baseVtable;
    base->x = x;
}
