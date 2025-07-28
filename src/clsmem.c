#include "../include/hcore.h"
#include <stddef.h>

void clsmem(int16_t* mem)
{
    for (size_t i=0;i<MEMSIZE;++i)
        mem[i] = 0;
}
