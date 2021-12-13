#include <stdio.h>

#include "I4.h"
#include "InterafaceId.h"
#include "ClassBase.h"

void I4DefaultPrintInt(void * obj, int x) {
    printf("%d\n", x * I4GetNum(obj) + I4ComputeX(obj));
}

int I4ComputeX(void *obj) {
    int (*computeX)(void *);
    computeX = getMethod(obj, I4, 0);
    return computeX(obj);
}

void I4printInt(void *obj, int x) {
    int (*printInt)(void *, int);
    printInt = getMethod(obj, I4, 1);
    printInt(obj, x);
}

int I4GetNum(void *obj) {
    int (*getNum)(void *);
    getNum = getMethod(obj, I4, 2);
    return getNum(obj);
}
