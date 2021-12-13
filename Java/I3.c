#include "I3.h"
#include "ClassBase.h"
#include "InterafaceId.h"

int I3GetPriority(void *obj) {
    struct I3TableStruct *i3Table = getITable(obj, I3);
    return i3Table->getPriority(obj);
}
