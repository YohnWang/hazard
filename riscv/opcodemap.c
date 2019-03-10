#include<cpu.h>
#include<id.h>
#include<opcodemap.h>
#include<inst.h>

typedef void (*exec_t)(struct hart_t *v,inst_bits_t i);

static void LOAD(struct hart_t *v,inst_bits_t i);
static void STORE(struct hart_t *v,inst_bits_t i);
static void BRANCH(struct hart_t *v,inst_bits_t i);
static void JALR(struct hart_t *v,inst_bits_t i);
static void JAL(struct hart_t *v,inst_bits_t i);
static void OP(struct hart_t *v,inst_bits_t i);
static void SYSTEM(struct hart_t *v,inst_bits_t i);
static void AUIPC(struct hart_t *v,inst_bits_t i);
static void LUI(struct hart_t *v,inst_bits_t i);
static void OP_IMM32(struct hart_t *v,inst_bits_t i);
static void OP32(struct hart_t *v,inst_bits_t i);


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

static inline int ubits(inst_bits_t b,int hi,int lo)
{
    return (b>>lo)&((1<<(hi+1-lo))-1);
}

void launch(struct hart_t *v,inst_bits_t i)
{
    opcode_map[ubits(i,4,2)][ubits(i,6,5)](v,i);
}

static void LOAD(struct hart_t *v,inst_bits_t i)
{
    static exec_t tab[8]=
    {
        [0]=lb,[1]=lh,[2]=lw,[3]=ld,
        [4]=lbu,[5]=lhu,[6]=lwu
    };
    int funct3=get_funct3(i);
    tab[funct3](v,i);
}

static void STORE(struct hart_t *v,inst_bits_t i)
{
    static exec_t tab[8]=
    {
        [0]=sb,[1]=sh,[2]=sw,[3]=sd,
    };
    int funct3=get_funct3(i);
    tab[funct3](v,i);
}

static void BRANCH(struct hart_t *v,inst_bits_t i)
{

}

static void JALR(struct hart_t *v,inst_bits_t i)
{

}

static void JAL(struct hart_t *v,inst_bits_t i)
{

}

static void OP(struct hart_t *v,inst_bits_t i)
{

}

static void SYSTEM(struct hart_t *v,inst_bits_t i)
{

}

static void AUIPC(struct hart_t *v,inst_bits_t i)
{

}

static void LUI(struct hart_t *v,inst_bits_t i)
{

}

static void OP_IMM32(struct hart_t *v,inst_bits_t i)
{

}

static void OP32(struct hart_t *v,inst_bits_t i)
{

}
