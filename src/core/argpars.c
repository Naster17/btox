#include "core.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// short version for if
#define sc strcmp

void help(int pos, int n_args, char **argv);
void load(int pos, int n_args, char **argv);
bool notarg(const char *s);

static struct Args args[] = {{"--help", "-h", "Show this message", 0, help},
                             {"--file", "-f", "Path to file contain session", 1, load}};

void argparse(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; j < sizeof(args) / sizeof(args[0]); j++)
        {
            // if provided flag/arg in args
            if (!sc(argv[i], args[j].flag) || !sc(argv[i], args[j].s_flag))
            {
                args[j].func(i, args[j].n_args, argv); // execute function
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

void help(int pos, int n_args, char **argv)
{
    printf("\nArgs:\n");
    for (int j = 0; j < sizeof(args) / sizeof(args[0]); j++)
    {
        printf("  %s %-5s %-20s\n", args[j].flag, args[j].s_flag, args[j].desc);
    }
    printf("\n");
}

void load(int pos, int n_args, char **argv)
{
    printf("Loading from file...\n");
    printf("Args: %s\n", argv[pos + n_args]);
}
