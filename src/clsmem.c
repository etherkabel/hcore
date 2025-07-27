#include "../include/hcore.h"
#include <stddef.h>

void clsmem(int16_t* mem)
{
    for (size_t i=0;i<512;++i)
        mem[i] = 0;
}
