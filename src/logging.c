#include "../include/hcore.h"
#include <stdio.h>

void logging(REGISTER* reg) {
    printf("--REGISTER DATA--\n");
    printf("AX:\t%d\n",reg->AX);
    printf("BX:\t%d\n",reg->BX);
    printf("CX:\t%d\n",reg->CX);
    printf("DX:\t%d\n",reg->DX);
    printf("IP:\t%d\n",reg->IP);
    printf("PC:\t%d\n",reg->PC);
    printf("SP:\t%d\n",reg->SP);
    printf("SS:\t%d\n",reg->SS);
}
