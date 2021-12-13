/*
public interface I2 {
    int computeX();
    void printInt(int);
}
*/
#pragma once

struct I2TableStruct {
    int (*computeX)(void *);
    void (*printInt)(void *, int);
};

int I2ComputeX(void *);
void I2printInt(void *, int);
