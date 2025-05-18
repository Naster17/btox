#include "core/core.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    argsparse(argc, argv);

    // to trace if program crash
    printf("\n### END ###\n");

    return EXIT_SUCCESS;
}
