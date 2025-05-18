#include "core.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// short version for if
#define sc strcmp

struct Args
{
    char flag[32];                       // main flag
    char s_flag[16];                     // if hase short version arg
    char desc[128];                      // description
    int req_args;                        // number of required arguments
    void (*func)(int pos, char *argv[]); // function
};

bool notarg(const char *s)
{
    if (strstr("-", s) == NULL)
        return true;

    return false;
}

void help(int pos, char **argv)
{
    printf("Args:\n"
           "  --help\tTo see this message\n"
           "  --save\tUse save file\n");
}

struct Args args[2] = {{"--help", "-h", "Help menu", 0, help}};

void argsparse(int argc, char *argv[])
{

    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; j < (sizeof(args) / sizeof(args[0])) - 1; j++)
        {
            if (!sc(argv[i], args[j].flag) || !sc(argv[i], args[j].s_flag))
            {
                args[j].func(0, argv);
            }
        }
    }
}
