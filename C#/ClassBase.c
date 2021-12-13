#include "ClassBase.h"
#include "InterafaceId.h"
#include <stdio.h>
#include <stddef.h>

struct ITable {
    enum InterfaceId id;
    unsigned int slot;
};

inline static unsigned int getSlot(const struct ClassBase *base, enum InterfaceId id, unsigned int index) {
    for (; base != NULL; base = base->parent) {
        unsigned int offset = base->numVMethod * sizeof(void *) + sizeof(struct ClassBase);
        void *address = (char *)base + offset;
        for (unsigned int i = 0; i < base->numI; i++) {
            struct ITable *table = *(struct ITable**)address;
            if (table->id == id) {
                unsigned int *slotArray = (unsigned int *)((char *)table + offsetof(struct ITable, slot));
                return slotArray[index];
            } else {
                address = (char *)address + sizeof(void *);
            }
        }
    }
    exit(1);
}

void *getMethod(void *obj, enum InterfaceId id, unsigned int index) {
    const struct ClassBase *base = *(struct ClassBase **)obj;
    unsigned int slot = getSlot(base, id, index);
    void **vtable = (void **)((char *)base + sizeof(struct ClassBase));
    return vtable[slot];
}