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

inline static struct I1TableStruct *getI1Table(void *obj) {
    return getITable(obj, I1);
}

int I1ComputeX(void *obj) {
    return getI1Table(obj)->computeX(obj);
}

void I1Update(void *obj) {
    return getI1Table(obj)->update(obj);
}

int I1UpdateAndCompute(void *obj) {
    return getI1Table(obj)->updateAndComputeX(obj);
}
