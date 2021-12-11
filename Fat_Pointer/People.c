#include <stdio.h>
#include "People.h"

void peoplePrintName(struct People people) {
    people.vptr->printName(people.object);
}

int peopleGetAge(struct People people) {
    people.vptr->getAge(people.object);
}
