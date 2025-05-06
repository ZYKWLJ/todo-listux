#include "../include/include.h"
void *checked_malloc(int len)
{
    void *p = malloc(len);
    if (!p)
    {
        fprintf(stderr, "\nRan out of memory!\n");
        exit(1);
    }
    return p;
}