#include "I1.h"
#include "ClassBase.h"
#include "InterafaceId.h"
#include <stdio.h>

int I1DefaultComputeX(void *object) {
    return 0;
}

int I1DefaultUpdateAndComputeX(void *object) {
    I1Update(object);
    return I1ComputeX(object);
}

int I1ComputeX(void *obj) {
    int (*computeX)(void *);
    computeX = getMethod(obj, I1, 0);
    return computeX(obj);
}

void I1Update(void *obj) {
    void (*update)(void *);
    update = getMethod(obj, I1, 1);
    update(obj);
}

int I1UpdateAndCompute(void *obj) {
    int (*updateAndCompute)(void *);
    updateAndCompute = getMethod(obj, I1, 2);
    return updateAndCompute(obj);
}
