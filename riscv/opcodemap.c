#include<cpu.h>
#include<id.h>
#include<opcodemap.h>
#include<inst/lw.h>

typedef void (*exec_t)(struct hart_t *v,inst_bits_t i);

static exec_t opcode_map[8][4]=
{
    [0]={[0]=LOAD,[1]=STORE,[3]=BRANCH},
    [1]={[3]=JALR},
    [2]={},
    [3]={[3]=JAL},
    [4]={[1]=OP,[3]=SYSTEM},
    [5]={[0]=AUIPC,[1]=LUI},
    [6]={[0]=OP_IMM32,[1]=OP32},
    [7]={}
};


void LOAD(struct hart_t *v,inst_bits_t i)
{
    static exec_t tab[8]={[2]=lw};
    int funct3=get_funct3(i);
    tab[funct3](v,i);
}

void STORE(struct hart_t *v,inst_bits_t i)
{

}

void BRANCH(struct hart_t *v,inst_bits_t i)
{

}

void JALR(struct hart_t *v,inst_bits_t i)
{

}

void JAL(struct hart_t *v,inst_bits_t i)
{

}

void OP(struct hart_t *v,inst_bits_t i)
{

}

void SYSTEM(struct hart_t *v,inst_bits_t i)
{

}

void AUIPC(struct hart_t *v,inst_bits_t i)
{

}

void LUI(struct hart_t *v,inst_bits_t i)
{

}

void OP_IMM32(struct hart_t *v,inst_bits_t i)
{

}

void OP32(struct hart_t *v,inst_bits_t i)
{

}
