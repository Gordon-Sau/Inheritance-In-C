#pragma once
#include <stdlib.h>
#include "InterafaceId.h"

struct ClassBase {
    const void *parent;
    const unsigned int numVMethod, numI;
};

void *getMethod(void *obj, enum InterfaceId id, unsigned int index);
