#include <stdio.h>
#include "../include/hcore.h"

int16_t mem[MEMSIZE];

int16_t* getRegisterPtr(REGISTER* reg, int16_t index)
{
    switch(index)
    {
        case 1: return &reg->AX;
        case 2: return &reg->BX;
        case 3: return &reg->CX;
        case 4: return &reg->DX;
        case 5: return &reg->PC;
        case 6: return &reg->IP;
        case 7: return &reg->SP;
        case 8: return &reg->SS;
    }

    return NULL;
}

void initreg(REGISTER* reg)
{
    reg->AX = 0;
    reg->BX = 0;
    reg->CX = 0;
    reg->DX = 0;
    reg->IP = 0;
    reg->SS = 0;
    reg->SP = 0;
}

int main(int argc, char* argv[]) {
    REGISTER reg;
    int16_t* opcode;
    FILE *rom_file;

    if (!(argc < 2))
    {
        if ((rom_file = fopen(argv[2],"rb")) == NULL)
        {
            perror("Error open ROM file");
            return 1;
        } else
        {

        }
    }

    clsmem(mem);
    initreg(&reg);

    loadinmemory(mem);

    while (reg.IP < MEMSIZE && mem[reg.IP] != 0)
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
                else
                {
                    fprintf(stderr,"Inalid register index!\n");
                    warexit(&rom_file,&reg,3,0);
                }

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

                int16_t* reg_ptr1 = getRegisterPtr(&reg, reg_index1);
                int16_t* reg_ptr2 = getRegisterPtr(&reg, reg_index2);

                if (!reg_ptr1 || !reg_ptr2)
                {
                    fprintf(stderr,"Invalid register index!\n");
                    warexit(&rom_file,&reg,3,0);
                }

                *reg_ptr1 = *reg_ptr1 + *reg_ptr2;

                reg.IP += 3;
                break;
            }
            case SUB:
            {
                int16_t reg_index1 = mem[reg.IP+1];
                int16_t reg_index2 = mem[reg.IP+2];

                int16_t* reg_ptr1 = getRegisterPtr(&reg, reg_index1);
                int16_t* reg_ptr2 = getRegisterPtr(&reg, reg_index2);

                if (!reg_ptr1 || !reg_ptr2)
                {
                    fprintf(stderr,"Invalid register index!\n");
                    warexit(&rom_file,&reg,3,0);
                }

                *reg_ptr1 = *reg_ptr1 - *reg_ptr2;

                reg.IP += 3;
                break;
            }
            case PUSH:
            {
                int16_t reg_index = mem[reg.IP+1];
                int16_t* reg_ptr = getRegisterPtr(&reg, reg_index);
                mem[reg.SS+reg.SP] = *reg_ptr;

                if (!reg_ptr)
                {
                    fprintf(stderr,"Invalid register index!\n");
                    warexit(&rom_file,&reg,3,0);
                }

                reg.SP-=2;
                reg.IP+=2;

                break;
            }
            case POP:
            {
                int16_t reg_index = mem[reg.IP+1];
                int16_t* reg_ptr = getRegisterPtr(&reg, reg_index);

                if (!reg_ptr)
                {
                    fprintf(stderr,"Invalid register index!\n");
                    warexit(&rom_file,&reg,3,0);
                }

                reg.SP += 2;
                *reg_ptr = mem[reg.SS+reg.SP];
                mem[reg.SS+reg.SP] = 0;

                reg.IP+=2;

                break;
            }
            case EXIT:
            {
                warexit(&rom_file,&reg,reg.DX,1);
            }
            default:
                printf("Incorrect opcode - %d at IP=%d\n",*opcode,reg.IP);
                warexit(&rom_file,&reg,2,0);
        }
    }

    if (rom_file != NULL)
        warexit(&rom_file,&reg,0,1);
    else
        warexit(NULL,&reg,0,1);
}
