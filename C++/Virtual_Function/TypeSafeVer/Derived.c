#include "Derived.h"
#include <stdio.h>

// static void *derivedVtable[] = {
//     DerivedPrint,
//     BaseHi
// };

const static struct Vtable derivedVtable= {
    .print = DerivedPrint,
    .hi = BaseHi
};

void DerivedPrint(struct Base *b) {
    struct Derived *d = (struct Derived *)b;
    printf("%d %d\n", d->base.x, d->z);
}

void DerivedShow(struct Derived *d) {
    printf("Derived\n");
}

void DerivedInit(struct Derived *d, int x, int z) {
    d->base.vptr = &derivedVtable;
    d->base.x = x;
    d->z = z;
}
