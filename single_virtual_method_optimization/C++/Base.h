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

struct Base;

struct Vtable {
    void (*print)(struct Base *);
};

struct Base {
    const void (*print)(struct Base *);
    int x;
};

void virtualPrint(struct Base *);
void BasePrint(struct Base *);
int BaseSumX(struct Base *, int);
void BaseShow(struct Base *);
void BaseInit(struct Base *, int);

// NOTE: To achieve pure virtual function, remove the vtable,
// and let the sub class to create its own vtable
