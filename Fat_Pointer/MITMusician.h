struct MITMusician {
    // the order does not matter
    int age;
    int id;
    char *name;
    char *major;
    char *instruments;
};

struct MITStudent toMITStudent(struct MITMusician *mm);
struct Musician toMusician(struct MITMusician *mm);
struct People toPeople(struct MITMusician *mm);

// NOTE: can expose the other functions (e.g. MITMusicianGetAge, MITMusicianPrintMajor) directly, but we don't do it here as we just want to test the fat pointer implementation of inheritance