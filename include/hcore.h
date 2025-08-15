#ifndef _HCORE_H_INCLUDE_
#define _HCORE_H_INCLUDE_
#endif

#include <stdio.h>
#include <stdint.h>

#define ADD 0x1
#define SUB 0x2
#define MOV 0x3
#define NOP 0x4
#define PUSH 0x5
#define POP 0x6
#define EXIT 0x7

#define MEMSIZE 512

#define _LIM

typedef struct {
    int16_t AX;
    int16_t BX;
    int16_t CX;
    int16_t DX;
    int16_t PC;
    int16_t IP;
    int16_t SP;
    int16_t SS;
} REGISTER;

extern void clsmem(int16_t* mem);
extern void logging(REGISTER* reg);
extern int16_t* getRegisterPtr(REGISTER* reg, int16_t index);
extern void warexit(FILE** rom_file,REGISTER *reg,int error_code,int16_t logging_mode);

#ifdef _LIM
extern void loadinmemory(int16_t* mem);
#endif
