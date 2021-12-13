#include <stdio.h>

#include "I4.h"
#include "InterafaceId.h"
#include "ClassBase.h"

void I4DefaultPrintInt(void * obj, int x) {
    printf("%d\n", x * I4GetNum(obj) + I4ComputeX(obj));
}

inline static struct I4TableStruct *getI4Table(void *obj) {
    return getITable(obj, I4);
}

int I4ComputeX(void *obj) {
    return getI4Table(obj)->i2Table.computeX(obj);
}

void I4printInt(void *obj, int x) {
    getI4Table(obj)->i2Table.printInt(obj, x);
}

int I4GetNum(void *obj) {
    return getI4Table(obj)->getNum(obj);
}
