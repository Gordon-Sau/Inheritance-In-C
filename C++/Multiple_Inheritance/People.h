#pragma once
/*
class People {
    char *name;
    int age;

    void printName() {
        printf("%s\n", name);
    }

    int getAge() {
        return age;
    }
};
*/
struct People {
    char *name;
    int age;
};

void printName(struct People* people);
int getAge(struct People* people);
void PeopleInit(struct People* people, char *, int);
