#include<cpu.h>
#include<id.h>
#include<inst/lw.h>

typedef void (*exec_t)(struct cpu_t *v,inst_bits_t i);

void LOAD(struct cpu_t *v,inst_bits_t i)
{
    static exec_t tab[8]={[2]=lw};
    int funct3=get_funct3(i);
    tab[funct3](v,i);
}

void STORE(struct cpu_t *v,inst_bits_t i)
{

}

void BRANCH(struct cpu_t *v,inst_bits_t i)
{

}

void JALR(struct cpu_t *v,inst_bits_t i)
{

}

void JAL(struct cpu_t *v,inst_bits_t i)
{

}

void OP(struct cpu_t *v,inst_bits_t i)
{

}

void SYSTEM(struct cpu_t *v,inst_bits_t i)
{

}

void AUIPC(struct cpu_t *v,inst_bits_t i)
{

}

void LUI(struct cpu_t *v,inst_bits_t i)
{

}

void OP_IMM32(struct cpu_t *v,inst_bits_t i)
{

}

void OP32(struct cpu_t *v,inst_bits_t i)
{

}
