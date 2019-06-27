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
static void OP_IMM(struct hart_t *v,inst_bits_t i);
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
    [4]={[0]=OP_IMM,[1]=OP,[3]=SYSTEM},
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
    static exec_t tab[8]=
    {
        [0]=beq,[1]=bne,
        [4]=blt,[5]=bge,
        [6]=bltu,[7]=bgeu
    };
    int funct3=get_funct3(i);
    tab[funct3](v,i);
}

static void JALR(struct hart_t *v,inst_bits_t i)
{
    static exec_t tab[8]=
    {
        [0]=jalr
    };
    int funct3=get_funct3(i);
    tab[funct3](v,i);
}

static void JAL(struct hart_t *v,inst_bits_t i)
{
    jal(v,i);
}

static void OP_IMM(struct hart_t *v,inst_bits_t i)
{
    static exec_t tab[16]=
    {
        [0]=addi,[2]=slti,[3]=sltiu,
        [4]=xori,[6]=ori ,[7]=andi,
        [1]=slli,[5]=srli,[13]=srai
    };
    int funct3=get_funct3(i);
    int bit30=ubits(i,30,30);
    tab[funct3==5?(funct3|(bit30<<3)):funct3](v,i);
}

static void OP(struct hart_t *v,inst_bits_t i)
{
    static exec_t tab[16]=
    {
        [0]=add,[1]=sll,[2]=slt,[3]=sltu,
        [4]=xor,[5]=srl,[6]=or,[7]=and,
        [8]=sub,[13]=sra
    };
    int funct3=get_funct3(i);
    int bit30=ubits(i,30,30);
    tab[funct3|(bit30<<3)](v,i);
}


static void privilege(struct hart_t *v,inst_bits_t i)
{
    int which=ubits(i,31,20);
    int x=ubits(i,25,25);
    switch(which)
    {
        case 0x000: ecall(v,i); break;
        case 0x001: ebreak(v,i);break;
        case 0x002: uret(v,i);  break;
        case 0x102: sret(v,i);  break;
        case 0x302: mret(v,i);  break;
        case 0x105: wfi(v,i);   break;
        default: break;
    }
}

static void SYSTEM(struct hart_t *v,inst_bits_t i)
{
    static exec_t tab[16]=
    {
        [0]=privilege,
        [1]=csrrw,[2]=csrrs,[3]=csrrc,
        [5]=csrrwi,[6]=csrrsi,[7]=csrrci,
    };
    int funct3=get_funct3(i);
    tab[funct3](v,i);
}

static void AUIPC(struct hart_t *v,inst_bits_t i)
{
    auipc(v,i);
}

static void LUI(struct hart_t *v,inst_bits_t i)
{
    lui(v,i);
}

static void OP_IMM32(struct hart_t *v,inst_bits_t i)
{
    static exec_t tab[16]=
    {
        [0]=addiw,

        [1]=slliw,[5]=srliw,[13]=sraiw
    };
    int funct3=get_funct3(i);
    int bit30=ubits(i,30,30);
    tab[funct3==5?(funct3|(bit30<<3)):funct3](v,i);
}

static void OP32(struct hart_t *v,inst_bits_t i)
{
    static exec_t tab[16]=
    {
        [0]=addw,[1]=sllw,
        [5]=srlw,
        [8]=subw,[13]=sraw
    };
    int funct3=get_funct3(i);
    int bit30=ubits(i,30,30);
    tab[funct3|(bit30<<3)](v,i);
}
