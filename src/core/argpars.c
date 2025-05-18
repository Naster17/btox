#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Args
{
    char flag[16];
    int req_args;
    void (*func)(void *data);
};

void help(void *data)
{
    printf("HELP MENU\n");
}

#define sc strcmp 

void argsparse(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        // printf("%s\n", argv[i]);
        if (!sc(argv[i], "--help") || !sc(argv[i], "-h"))
        {
            help(NULL);
        }
        else if (strcmp(argv[i], "--save") == 0) {
            printf("Save\n");
        }
    }
}
// struct Args *init_args(int argc)
// {
//     struct Args *args = calloc(argc, sizeof(struct Args));
//
//     args[0].flag = "--help";
//     args[0].req_args = 0;
//     args[0].func = help;
//
//     return args;
// }
