#include "I5.h"
#include "ClassBase.h"
#include "InterafaceId.h"

void I5SetY(void *obj, int y) {
    struct I5TableStruct *i5Table = getITable(obj, I5);
    return i5Table->setY(obj, y);
}