/*
public abstract class P extends G implements I3 {
    @Override
    public int getToken() {
        return myhash() * computeX();
    }
    abstract public int myHash();
    public int getPriority() {
        return 0;
    }
    @override
    public int updateAndComputeX() {
        update();
        return super.updateAndComputeX();
    }
}
*/
#pragma once 
#include "G.h"

struct PData {
    struct GData base;
};

struct PTableStruct {
    struct GTableStruct base;
    int (*getPriority)(void *);
    int (*myHash)(void *);
};

struct PClass {
    const struct ClassBase classBase;
    const struct PTableStruct vtable;
    const void *itables[3];
};

struct P {
    const struct PClass *klass;
    struct PData data;
};

struct PAbstractClass {
    const struct ClassBase classBase;
    const int interfacesIds[3];
};

int PDefaultgetToken(void *);
int PDefaultGetPriority(void *);
int PDefaultUpdateAndComputeX(void *);

int PComputeX(void *);
void PUpdate(void *);
int PUpdateAndComputeX(void *);
void PPrintInt(void *, int);
int PGetToken(void *);
int PGetPriority(void *);
int PMyHash(void *);

extern const struct PAbstractClass pClass;
