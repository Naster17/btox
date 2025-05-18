#include "core.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// short version for if
#define sc strcmp

void help(int pos, int req_args, char **argv);
void load(int pos, int req_args, char **argv);
bool notarg(const char *s);

static struct Args args[] = {{"--help", "-h", "Show this message", 0, help},
                             {"--file", "-f", "Load session from file", 1, load}};

void argsparse(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; j < sizeof(args) / sizeof(args[0]); j++)
        {
            // if provided flag/arg in args
            if (!sc(argv[i], args[j].flag) || !sc(argv[i], args[j].s_flag))
            {
                args[j].func(j, args[j].req_args, argv); // execute function
            }
        }
    }
}

bool notarg(const char *s)
{
    if (s && strstr("-", s) == NULL)
        return true;

    return false;
}

void help(int pos, int req_args, char **argv)
{
    printf("\nArgs:\n");
    for (int j = 0; j < sizeof(args) / sizeof(args[0]); j++)
    {
        printf("  %s %s\t%s\n", args[j].flag, args[j].s_flag, args[j].desc);
    }
}

void load(int pos, int req_args, char **argv)
{
    printf("Loading from file...\n");
    printf("Args: %s\n", argv[pos + req_args]);
}
