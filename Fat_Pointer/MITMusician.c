#include <stdio.h>

#include "MITStudent.h"
#include "Musician.h"
#include "People.h"
#include "MITMusician.h"

// implement all the functions
static int MITMusicianGetAge(void *mm) {
    return ((struct MITMusician *)mm)->age;
}

static void MITMusicianPrintName(void *mm) {
    printf("%s\n", ((struct MITMusician *)mm)->name);
}

static void MITMusicianPrintMajor(void *mm) {
    printf("%s\n", ((struct MITMusician *)mm)->major);
}

static void MITMusicianPrintId(void *mm) {
    printf("%d\n", ((struct MITMusician *)mm)->id);
}

static void MITMusicianPrintInstrument(void *mm) {
    printf("%s\n", ((struct MITMusician *)mm)->instruments);
}

const static struct PeopleVtableStruct peopleVtable = {
    .getAge = MITMusicianGetAge,
    .printName = MITMusicianPrintName
};

const static struct MusicianVtableStruct musicianVtable = {
    .people = {
        .getAge = MITMusicianGetAge,
        .printName = MITMusicianPrintName
    },
    .printInstrument = MITMusicianPrintInstrument
};

const static struct MITStudentVtableStruct mitStudentVtable = {
    .people = {
        .getAge = MITMusicianGetAge,
        .printName = MITMusicianPrintName
    },
    .printMajor = MITMusicianPrintMajor,
    .printSchoolId = MITMusicianPrintId
};

struct MITStudent toMITStudent(struct MITMusician *mm) {
    return (struct MITStudent){
        .obj = mm,
        .vptr = &mitStudentVtable
    };
}

struct Musician toMusician(struct MITMusician *mm) {
    return (struct Musician) {
        .object = mm,
        .vptr = &musicianVtable
    };
}

struct People toPeople(struct MITMusician *mm) {
    return (struct People) {
        .object = mm,
        .vptr = &peopleVtable
    };
}
