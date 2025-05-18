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
        for (int j = 0; j < sizeof(args) / sizeof(args[0]); j++)
        {
            printf("%s %s\n", args[j].flag, args[j].s_flag);
            args[j].func(0, argv);
        }
        // // printf("%s\n", argv[i]);
        // if (!sc(argv[i], "--help") || !sc(argv[i], "-h"))
        // {
        //     help();
        // }
        // else if (!sc(argv[i], "--save"))
        // {
        //     printf("Save\n");
        // }
    }
}
