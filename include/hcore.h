#ifndef _HCORE_H_INCLUDE_
#define _HCORE_H_INCLUDE_
#endif

#include <stdint.h>

#define ADD 0x1
#define SUB 0x2
#define MOV 0x3
#define NOP 0x4

typedef struct {
    int16_t AX;
    int16_t BX;
    int16_t CX;
    int16_t DX;
    int16_t PC;
    int16_t IP;
} REGISTER;

extern void clsmem(int16_t* mem);
extern void logging(REGISTER* reg);
extern int16_t* getRegisterPtr(REGISTER* reg, int16_t index);
