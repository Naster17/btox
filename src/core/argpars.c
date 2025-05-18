#include "core.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// short version for if
#define sc strcmp
void help(int pos, char **argv);
bool notarg(const char *s);

static struct Args args[2] = {{"--help", "-h", "Show this message", 0, help}};

void argsparse(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; j < (sizeof(args) / sizeof(args[0])) - 1; j++)
        {
            // if provided flag/arg in args
            if (!sc(argv[i], args[j].flag) || !sc(argv[i], args[j].s_flag))
            {
                args[j].func(0, argv); // execute function
            }
        }
    }
}

bool notarg(const char *s)
{
    if (strstr("-", s) == NULL)
        return true;

    return false;
}

void help(int pos, char **argv)
{

    printf("\nArgs:\n");
    for (int j = 0; j < (sizeof(args) / sizeof(args[0])) - 1; j++)
    {
        printf("  %s %s\t%s\n", args[j].flag, args[j].s_flag, args[j].desc);
    }
    //        "  --help\tTo see this message\n"
    //        "  --save\tUse save file\n");
}
