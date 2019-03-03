#include<cpu.h>


_Static_assert(sizeof(int)>=4,"data model is not ILP64 or LLP64 or ILP32");
_Static_assert(-1==~0,"it must be two's complement code");


typedef uint32_t inst_bits_t;

static inline int ubit(inst_bits_t b,int hi,int lo)
{
    return (b>>lo)&((1<<(hi+1-lo))-1);
}

static inline int bit(inst_bits_t b,int p)
{
    return (b>>p)&1;
}

int get_op(inst_bits_t i)
{
    return i&0x7f;
}


int get_rd(inst_bits_t i)
{
    return (i&0xf80)>>7;
}

int get_rs1(inst_bits_t i)
{
    return ubit(i,19,15);
}

int get_rs2(inst_bits_t i)
{
    return ubit(i,24,20);
}

int get_funct3(inst_bits_t i)
{
    return ubit(i,14,12);
}

int get_funct7(inst_bits_t i)
{
    return ubit(i,31,25);
}

int get_immi(inst_bits_t i)
{
    return (int)(i)>>20;
}

int get_imms(inst_bits_t i)
{
    return (((int)(i)>>25)<<5)+((i&0xf80)>>7);
}

int get_immb(inst_bits_t i)
{
    return (((int)i>>31)<<12)+(((i&0x7e000000)>>25)<<5)+(((i&0xf00)>>8)<<1)+(((i&0x80)>>7)<<11);
}

int get_immu(inst_bits_t i)
{
    return (int)i&0xfffff000;
}

int get_immj(inst_bits_t i)
{
    return ((int)i>>31<<20)+((i&0x7fe00000)>>21<<1)+((i&0x00100000)>>20<<11)+(i&0x000ff000);
}

int imm_gen(inst_bits_t i)
{

}
