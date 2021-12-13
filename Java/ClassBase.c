#include "ClassBase.h"
#include "InterafaceId.h"
#include <stdio.h>
#include <stddef.h>

struct ITable {
    enum InterfaceId id;
    void *function_ptr;
};

void *getITable(void *obj, enum InterfaceId id) {
    struct ClassBase *base = *(struct ClassBase **)obj;
    unsigned int numI = base->numI;
    unsigned int offset = base->numVMethod * sizeof(void *) + sizeof(struct ClassBase);
    void *address = (char *)base + offset;
    for (unsigned int i = 0; i < numI; i++) {
        if (**(enum InterfaceId **)address == id) {
            return *(char **)address + offsetof(struct ITable, function_ptr);
        } else {
            address = (char *)address + sizeof(void *);
        }
    }
    exit(1);
}
