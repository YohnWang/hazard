void lw(struct hart_t *v,inst_bits_t i)
{
    int rd=get_rd(i);
    int rs1=get_rs1(i);
    int imm=get_immi(i);
    uint32_t data;
    mem_lw(&data,v->x[rs1]+imm);
    v->x[rd]=(int32_t)data;
}
