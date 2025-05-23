#include "core.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// short version for if
#define sc strcmp

void help(int pos, int n_args, char **argv);
void load(int pos, int n_args, char **argv);

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

bool isarg(const char *s)
{
    if (s && s[0] == '-')
        return false;

    return true;
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

extern char *data_file;

void load(int pos, int n_args, char **argv)
{
    if (isarg(argv[pos + n_args]))
    {
        data_file = strdup(argv[pos + n_args]);
        printf("Session file: %s\n", data_file);
    }
    else
    {
        printf("Specify tox save data file!\n");
        printf("Session file: %s\n", data_file);
    }
}
