#include "I2.h"
#include "ClassBase.h"
#include "InterafaceId.h"

int I2ComputeX(void *obj) {
    int (*computeX)(void *);
    computeX = getMethod(obj, I2, 0);
    return computeX(obj);
}

void I2printInt(void *obj, int x) {
    void (*printInt)(void *, int);
    printInt = getMethod(obj, I2, 1);
    return printInt(obj, x);
}
