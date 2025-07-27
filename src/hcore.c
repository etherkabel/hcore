#include <stdio.h>
#include "../include/hcore.h"

int16_t mem[512];

int16_t* getRegisterPtr(REGISTER* reg, int16_t index)
{
    switch(index)
    {
        case 0: return &reg->AX;
        case 1: return &reg->BX;
        case 2: return &reg->CX;
        case 3: return &reg->DX;
        case 4: return &reg->PC;
        case 5: return &reg->IP;
    }
}

void initreg(REGISTER* reg)
{
    reg->AX = 0;
    reg->BX = 0;
    reg->CX = 0;
    reg->DX = 0;
    reg->IP = 0;
}

int main() {
    REGISTER reg;
    int16_t* opcode;

    clsmem(mem);
    initreg(&reg);

    mem[0] = MOV;
    mem[1] = 0;
    mem[2] = 2;
    mem[3] = NOP;
    mem[4] = MOV;
    mem[5] = 1;
    mem[6] = 2;
    mem[7] = ADD;
    mem[8] = 0;
    mem[9] = 1;
    mem[10] = MOV;
    mem[11] = 1;
    mem[12] = 3;
    mem[13] = SUB;
    mem[14] = 0;
    mem[15] = 1;

    while (reg.IP < 512 && mem[reg.IP] != 0)
    {
        opcode = &mem[reg.IP];
        switch (*opcode)
        {
            case MOV:
            {
                int16_t reg_index = mem[reg.IP+1];
                int16_t value = mem[reg.IP+2];

                int16_t* reg_ptr = getRegisterPtr(&reg, reg_index);

                if (reg_ptr != NULL) *reg_ptr = value;

                reg.IP += 3;
                break;
            }
            case NOP:
            {
                reg.IP += 1;
                break;
            }
            case ADD:
            {
                int16_t reg_index1 = mem[reg.IP+1];
                int16_t reg_index2 = mem[reg.IP+2];

                int16_t* reg_ptr1 = getRegisterPtr(&reg, 0);
                int16_t* reg_ptr2 = getRegisterPtr(&reg, 1);

                *reg_ptr1 = *reg_ptr1 + *reg_ptr2;

                reg.IP += 3;
                break;
            }
            case SUB:
            {
                int16_t reg_index1 = mem[reg.IP+1];
                int16_t reg_index2 = mem[reg.IP+2];

                int16_t* reg_ptr1 = getRegisterPtr(&reg, 0);
                int16_t* reg_ptr2 = getRegisterPtr(&reg, 1);

                *reg_ptr1 = *reg_ptr1 - *reg_ptr2;

                reg.IP += 3;
                break;
            }
            default:
                printf("Incorrect opcode - %d at IP=%d\n",*opcode,reg.IP);
                return 2;
        }
    }

    logging(&reg);

    return 0;

}
