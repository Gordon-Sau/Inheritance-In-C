/*
public interface I1 {
    default int computeX() {
        return 0;
    }
    void update();
    default int updateAndComputeX() {
        update()
        return computeX();
    }
}
*/
#pragma once
#include <stdbool.h>

struct I1TableStruct {
    int (*computeX)(void *);
    void (*update)(void *);
    int (*updateAndComputeX)(void *);
};

int I1DefaultComputeX(void *);
int I1DefaultUpdateAndComputeX(void *);

int I1ComputeX(void *);
void I1Update(void *);
int I1UpdateAndCompute(void *);
