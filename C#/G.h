/*
public class G implements I1, I2 {
    static private int token = 0;
    private int a, b, c, d;

    public int computeX() {
        return a * b + c * d;
    }

    public void update() {
        a++;
        b--;
        c += 2;
        d -= 3;
    }

    public void printInt(int x) {
        printf("%d\n", x);
    }

    public int getToken() {
        token++;
        return token;
    }
}
*/
#pragma once

#include "ClassBase.h"

struct GData {
    int a, b, c, d;
};

struct GTableStruct {
    int (*computeX)(void *);
    void (*update)(void *);
    int (*updateAndComputeX)(void *);
    void (*printInt)(void *, int);
    int (*getToken)(void *);
};

struct GClass {
    const struct ClassBase classBase;
    const struct GTableStruct vtable;
    const void *itable[2];
};

struct G {
    const struct GClass *klass;
    struct GData data;
};

int GDefaultComputeX(void *);
void GDefaultUpdate(void *);
void GDefaultPrintInt(void *, int);
int GDefaultgetToken(void *);

int GComputeX(void *);
void GUpdate(void *);
int GUpdateAndComputeX(void *);
void GPrintInt(void *, int);
int GGetToken(void *);

void GInit(struct G *g);
extern const struct GClass gClass;