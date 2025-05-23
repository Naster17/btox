#ifndef MCORE_H
#define MCORE_H

#include <stdbool.h>
#include <tox/tox.h>

struct Args
{
    char flag[32];                                   // main flag
    char s_flag[16];                                 // if hase short version arg
    char desc[128];                                  // description
    int n_args;                                      // number of required arguments
    void (*func)(int pos, int n_args, char *argv[]); // function
};

typedef struct DHT_node
{
    const char *ip;
    uint16_t port;
    const char key_hex[TOX_PUBLIC_KEY_SIZE * 2 + 1];
} DHT_node;

void argparse(int argc, char *argv[]);

// tox
void bootstrap(Tox *tox);

#endif // !MCORE_H
