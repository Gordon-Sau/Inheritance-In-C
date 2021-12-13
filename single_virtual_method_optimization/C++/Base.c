#include "Base.h"
#include <stdio.h>

// static void *baseVtable[] = {
//     BasePrint,
// };

const static struct Vtable baseVtable = {
    .print = BasePrint,
};

void virtualPrint(struct Base *base) {
    base->print(base);
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
    base->print = &BasePrint;
    base->x = x;
}
