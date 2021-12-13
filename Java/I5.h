/*
public interface I5 {
    void setY(int y);
}
*/

#pragma once

struct I5TableStruct {
    void (*setY)(void *, int);
};

void I5SetY(void *, int);
