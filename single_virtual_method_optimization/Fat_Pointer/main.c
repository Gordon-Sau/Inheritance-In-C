#include "Derived.h"
#include <stdio.h>

int main(void) {
    struct DerivedData d;
    DerivedInit(&d, 4, 5);
    virtualPrint(toBase(&d));
    DerivedShow(&d);
    printf("%d\n", BaseSumX(&d, 3));

   return 0;
}