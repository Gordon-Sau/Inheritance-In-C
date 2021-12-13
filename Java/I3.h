/*
public interface I3 {
    int getPriority();
}
*/

struct I3TableStruct {
    int (*getPriority)(void *);
};

int I3GetPriority(void *);
