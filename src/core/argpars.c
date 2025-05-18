#include "core.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// short version for if
#define sc strcmp

bool notarg(const char *s)
{
    if (strstr("-", s) == NULL)
        return true;

    return false;
}

void help()
{
    printf("Args:\n"
           "  --help\tTo see this message\n"
           "  --save\tUse save file\n");
}

void argsparse(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        // printf("%s\n", argv[i]);
        if (!sc(argv[i], "--help") || !sc(argv[i], "-h"))
        {
            help();
        }
        else if (!sc(argv[i], "--save"))
        {
            printf("Save\n");
        }
    }
}
