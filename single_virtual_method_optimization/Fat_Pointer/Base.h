#pragma once
/*
class Base{
    int x;
    virtual void print() {
        printf("%d\n", x);
    }
    int sumX(int y) {
        return x + y;
    }
    void show() {
        printf("Base\n");
    }
}
*/

struct BaseData {
    int x;
};

struct Base {
    void (*print)(void *);
    void *obj;
};

void virtualPrint(struct Base);
void BasePrint(void *);
int BaseSumX(void *, int);
void BaseShow(void *);
void BaseInit(struct BaseData *, int);

struct Base BaseDataToBase(struct BaseData *);

// NOTE: To achieve pure virtual function, remove the vtable,
// and let the sub class to create its own vtable
