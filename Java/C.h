/*
public class C extends P implements I4, I5 {
    private int y, int z;
    pubic int myhash() {
        return y ^ z;
    }

    public int getPriority() {
        return 1;
    }

    public void printInt(int x) {
        I4.super.printInt(x);
    }

    public int getNum() {
        return myhash() + y + z;
    }

    void setY(int y) {
        this.y = y;
    }

    @override
    void update() {
        a++;
        b--;
        c++;
        d--;
        y += 2;
        z -= 2;
    }
}
*/
#pragma once
#include "P.h"

struct CData {
    struct PData base;
    int y, z;
};


struct CTableStruct {
    struct PTableStruct base;
    int (*getNum)(void *);
    void (*setY)(void *, int);
};

struct CClass {
    const struct ClassBase classBase;
    const struct CTableStruct vtable;
    const void *itables[5];
};

struct C {
    const struct CClass *klass;
    struct CData data;
};

int CDefaultMyHash(void *);
int CDefaultGetPriority(void *);
int CDefaultGetNum(void *);
void CDefaultSetY(void *, int);
void CDefaultUpdate(void *);

int CComputeX(void *);
void CUpdate(void *);
int CUpdateAndComputeX(void *);
void CPrintInt(void *, int);
int CGetToken(void *);
int CGetPriority(void *);
int CMyHash(void *);
int CGetNum(void *);
void CSetY(void *, int);

void CInit(struct C *c);
extern const struct CClass * cClassPtr;
