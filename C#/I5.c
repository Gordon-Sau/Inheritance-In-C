#include "I5.h"
#include "ClassBase.h"
#include "InterafaceId.h"
#include <stddef.h>

void I5SetY(void *obj, int y) {
    void (*setY)(void *, int);
    setY = getMethod(obj, I5, 0);
    setY(obj, y);
}
