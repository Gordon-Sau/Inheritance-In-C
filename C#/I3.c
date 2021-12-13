#include "I3.h"
#include "ClassBase.h"
#include "InterafaceId.h"

int I3GetPriority(void *obj) {
    void (*getPriority)(void *);
    getPriority = getMethod(obj, I3, 0);
    getPriority(obj);
}
