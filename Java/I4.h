/*
public interface I4 extends I2 {
    int getNum();

    default void printInt(int x) {
        printf("%d\n", x * getNum() + computeX());
    }
}
*/

#pragma once
#include "I2.h"

struct I4TableStruct {
    struct I2TableStruct i2Table;
    int (*getNum)(void *);
};

void I4DefaultPrintInt(void *, int x);

int I4ComputeX(void *);
void I4printInt(void *, int);
int I4GetNum(void *);
