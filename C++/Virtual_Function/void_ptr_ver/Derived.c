#include "Derived.h"
#include <stdio.h>

const static void *derivedVtable[] = {
    Derivedprint,
    BaseHi
};

void Derivedprint(struct Derived *d) {
    printf("%d %d\n", d->base.x, d->z);
}

void DerivedShow(struct Derived *d) {
    printf("Derived\n");
}

void DerivedInit(struct Derived *d, int x, int z) {
    d->base.vptr = derivedVtable;
    d->base.x = x;
    d->z = z;
}
