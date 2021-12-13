#include "I2.h"
#include "ClassBase.h"
#include "InterafaceId.h"

int I2ComputeX(void *obj) {
    struct I2TableStruct *i2Table = getITable(obj, I2);
    return i2Table->computeX(obj);
}

void I2printInt(void *obj, int x) {
    struct I2TableStruct *i2Table = getITable(obj, I2);
    return i2Table->printInt(obj, x);
}
