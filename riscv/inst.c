#include<cpu.h>
#include<id.h>
#include<mem.h>
#include<stdint.h>

void lb(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int rs1=get_rs1(i);
    int imm=get_immi(i);
    uint8_t data;
    mem_lb(&data,v->x[rs1]+imm);
    v->x[rd]=(int8_t)data;
}

void lh(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int rs1=get_rs1(i);
    int imm=get_immi(i);
    uint16_t data;
    mem_lh(&data,v->x[rs1]+imm);
    v->x[rd]=(int16_t)data;
}

void lw(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int rs1=get_rs1(i);
    int imm=get_immi(i);
    uint32_t data;
    mem_lw(&data,v->x[rs1]+imm);
    v->x[rd]=(int32_t)data;
}

void ld(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int rs1=get_rs1(i);
    int imm=get_immi(i);
    uint64_t data;
    mem_ld(&data,v->x[rs1]+imm);
    v->x[rd]=(int64_t)data;
}

void lbu(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int rs1=get_rs1(i);
    int imm=get_immi(i);
    uint8_t data;
    mem_lb(&data,v->x[rs1]+imm);
    v->x[rd]=data;
}

void lhu(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int rs1=get_rs1(i);
    int imm=get_immi(i);
    uint16_t data;
    mem_lh(&data,v->x[rs1]+imm);
    v->x[rd]=data;
}

void lwu(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int rs1=get_rs1(i);
    int imm=get_immi(i);
    uint32_t data;
    mem_lw(&data,v->x[rs1]+imm);
    v->x[rd]=data;
}

void sb(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_imms(i);
    mem_sb(v->x[rs2],v->x[rs1]+imm);
}

void sh(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_imms(i);
    mem_sh(v->x[rs2],v->x[rs1]+imm);
}

void sw(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_imms(i);
    mem_sw(v->x[rs2],v->x[rs1]+imm);
}

void sd(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_imms(i);
    mem_sd(v->x[rs2],v->x[rs1]+imm);
}

void beq(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_immb(i);
    if(v->x[rs1]==v->x[rs2])
    {
        v->ctrl.pcsel=PCJUMP;
        v->ctrl.pcnext=v->pc+imm;
    }
}

void bne(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_immb(i);
    if(v->x[rs1]!=v->x[rs2])
    {
        v->ctrl.pcsel=PCJUMP;
        v->ctrl.pcnext=v->pc+imm;
    }
}

void blt(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_immb(i);
    if(v->x[rs1]<v->x[rs2])
    {
        v->ctrl.pcsel=PCJUMP;
        v->ctrl.pcnext=v->pc+imm;
    }
}

void bge(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_immb(i);
    if(v->x[rs1]>=v->x[rs2])
    {
        v->ctrl.pcsel=PCJUMP;
        v->ctrl.pcnext=v->pc+imm;
    }
}

void bltu(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_immb(i);
    if((uint64_t)v->x[rs1]<(uint64_t)v->x[rs2])
    {
        v->ctrl.pcsel=PCJUMP;
        v->ctrl.pcnext=v->pc+imm;
    }
}

void bgeu(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int imm=get_immb(i);
    if((uint64_t)v->x[rs1]>=(uint64_t)v->x[rs2])
    {
        v->ctrl.pcsel=PCJUMP;
        v->ctrl.pcnext=v->pc+imm;
    }
}

void jalr(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int rs1=get_rs1(i);
    int imm=get_immi(i);
    v->x[rd]=v->pc+4;
    v->ctrl.pcsel=PCJUMP;
    v->ctrl.pcnext=v->x[rs1]+imm;
}

void jal(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int imm=get_immj(i);
    v->x[rd]=v->pc+4;
    v->ctrl.pcsel=PCJUMP;
    v->ctrl.pcnext=v->pc+imm;
}

void add(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=v->x[rs1]+v->x[rs2];
}

void sub(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=v->x[rs1]-v->x[rs2];
}

void sll(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=v->x[rs1]<<(v->x[rs2]&0x3f);
}

void slt(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=v->x[rs1] < v->x[rs2]? 1:0;
}

void sltu(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=(ureg_t)v->x[rs1] < (ureg_t)v->x[rs2]? 1:0;
}

void xor(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=v->x[rs1] ^ v->x[rs2];
}

void srl(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=(ureg_t)v->x[rs1]>>(v->x[rs2]&0x3f);
}

void sra(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=v->x[rs1]>>(v->x[rs2]&0x3f);
}

void or(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=v->x[rs1] | v->x[rs2];
}

void and(struct hart_t *v,inst_bits_t i)
{
    int rs1=get_rs1(i);
    int rs2=get_rs2(i);
    int rd=get_rd(i);
    v->x[rd]=v->x[rs1] & v->x[rs2];
}

void auipc(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int32_t imm=get_immu(i);
    //the type of v->pc is int64_t,type of imm is int32_t,imm will be expended to int64_t
    v->x[rd]=v->pc+(imm<<12);
}

void lui(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int32_t imm=get_immu(i);
    //the type of v->pc is int64_t,type of imm is int32_t,imm will be expended to int64_t
    v->x[rd]=(imm<<12);
}

