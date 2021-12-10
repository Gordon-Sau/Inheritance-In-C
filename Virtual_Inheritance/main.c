#include "MITMusician.h"

int main(void) {
    struct MITMusician mm;
    MITMusicianInit(&mm, "Tom", 19, "Music", 234564, "Guitar, Piano");

    printName(&(MITStudentCast(&mm.mitStu)->people));
    printMajor(MITStudentCast(&mm.mitStu));
    printSchoolId(&mm.mitStu);

    printName(MusicianCast(&mm.musician));
    printInstrument(&mm.musician);
    return 0;
}
