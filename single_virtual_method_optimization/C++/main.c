#include "Derived.h"
#include <stdio.h>

int main(void) {
    struct Base b;
    BaseInit(&b, 10);
    virtualPrint(&b);
    printf("%d\n", BaseSumX(&b, -3));

    struct Derived d;
    DerivedInit(&d, 4, 5);
    virtualPrint(&d.base);
    BaseShow(&d.base);
    DerivedShow(&d);
    printf("%d\n", BaseSumX(&d.base, 3));

   return 0;
}