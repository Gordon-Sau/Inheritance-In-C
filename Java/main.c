#include <stdio.h>

#include "G.h"
#include "P.h"
#include "C.h"
#include "I1.h"

int main(void) {
    struct C c;
    CInit(&c);
    printf("%d\n", I1UpdateAndCompute(&c));
    printf("%d\n", GComputeX(&c));
    printf("%d\n", PGetPriority(&c));
    return 0;
}
