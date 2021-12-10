#include "MITMusician.h"

int main(void) {
    struct MITMusician mm;
    PeopleInit(&mm.mitStu.stu.people, "Tom", 19);
    StudentInit(&mm.mitStu.stu, "Music");
    MITStudentInit(&mm.mitStu, 234564);

    PeopleInit(&mm.musician.people, "Jerry", 20); // NOTE: there are two People in a MITMusician
    MusicianInit(&mm.musician, "Guitar, Piano");
    
    printName(&mm.mitStu.stu.people);
    printMajor(&mm.mitStu.stu);
    printSchoolId(&mm.mitStu);

    printName(&mm.musician.people);
    printInstrument(&mm.musician);
    return 0;
}
