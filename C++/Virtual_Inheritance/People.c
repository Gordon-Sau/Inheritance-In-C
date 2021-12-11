#include "People.h"
#include <stdio.h>

void printName(struct People* people) {
    printf("%s\n", people->name);
}

int getAge(struct People* people) {
    return people->age;
}

void PeopleInit(struct People *people, char *name, int age) {
    people->name = name;
    people->age = age;
}