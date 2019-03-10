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
        v->pc=v->pc+imm;
}
