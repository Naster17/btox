#ifndef MCORE_H
#define MCORE_H

#include <stdbool.h>

struct Args
{
    char flag[32];                       // main flag
    char s_flag[16];                     // if hase short version arg
    char desc[128];                      // description
    int req_args;                        // number of required arguments
    void (*func)(int pos, char *argv[]); // function
};

void argsparse(int argc, char *argv[]);

#endif // !MCORE_H
