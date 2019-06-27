#ifndef INST_H
#define INST_H

#include<cpu.h>

extern void lb(struct hart_t *v,inst_bits_t i);
extern void lh(struct hart_t *v,inst_bits_t i);
extern void lw(struct hart_t *v,inst_bits_t i);
extern void ld(struct hart_t *v,inst_bits_t i);
extern void lbu(struct hart_t *v,inst_bits_t i);
extern void lhu(struct hart_t *v,inst_bits_t i);
extern void lwu(struct hart_t *v,inst_bits_t i);
extern void sb(struct hart_t *v,inst_bits_t i);
extern void sh(struct hart_t *v,inst_bits_t i);
extern void sw(struct hart_t *v,inst_bits_t i);
extern void sd(struct hart_t *v,inst_bits_t i);
extern void beq(struct hart_t *v,inst_bits_t i);
extern void bne(struct hart_t *v,inst_bits_t i);
extern void blt(struct hart_t *v,inst_bits_t i);
extern void bge(struct hart_t *v,inst_bits_t i);
extern void bltu(struct hart_t *v,inst_bits_t i);
extern void bgeu(struct hart_t *v,inst_bits_t i);
extern void jalr(struct hart_t *v,inst_bits_t i);
extern void jal(struct hart_t *v,inst_bits_t i);
extern void add(struct hart_t *v,inst_bits_t i);
extern void sub(struct hart_t *v,inst_bits_t i);
extern void sll(struct hart_t *v,inst_bits_t i);
extern void slt(struct hart_t *v,inst_bits_t i);
extern void sltu(struct hart_t *v,inst_bits_t i);
extern void xor(struct hart_t *v,inst_bits_t i);
extern void srl(struct hart_t *v,inst_bits_t i);
extern void sra(struct hart_t *v,inst_bits_t i);
extern void or(struct hart_t *v,inst_bits_t i);
extern void and(struct hart_t *v,inst_bits_t i);
extern void auipc(struct hart_t *v,inst_bits_t i);
extern void lui(struct hart_t *v,inst_bits_t i);
extern void addi(struct hart_t *v,inst_bits_t i);
extern void slti(struct hart_t *v,inst_bits_t i);
extern void sltiu(struct hart_t *v,inst_bits_t i);
extern void xori(struct hart_t *v,inst_bits_t i);
extern void ori(struct hart_t *v,inst_bits_t i);
extern void andi(struct hart_t *v,inst_bits_t i);
extern void slli(struct hart_t *v,inst_bits_t i);
extern void srli(struct hart_t *v,inst_bits_t i);
extern void srai(struct hart_t *v,inst_bits_t i);
extern void ecall(struct hart_t *v,inst_bits_t i);
extern void ebreak(struct hart_t *v,inst_bits_t i);
extern void uret(struct hart_t *v,inst_bits_t i);
extern void sret(struct hart_t *v,inst_bits_t i);
extern void mret(struct hart_t *v,inst_bits_t i);
extern void wfi(struct hart_t *v,inst_bits_t i);
extern void addiw(struct hart_t *v,inst_bits_t i);
extern void slliw(struct hart_t *v,inst_bits_t i);
extern void srliw(struct hart_t *v,inst_bits_t i);
extern void sraiw(struct hart_t *v,inst_bits_t i);
extern void addw(struct hart_t *v,inst_bits_t i);
extern void subw(struct hart_t *v,inst_bits_t i);
extern void sllw(struct hart_t *v,inst_bits_t i);
extern void srlw(struct hart_t *v,inst_bits_t i);
extern void sraw(struct hart_t *v,inst_bits_t i);
extern void csrrw(struct hart_t *v,inst_bits_t i);
extern void csrrs(struct hart_t *v,inst_bits_t i);
extern void csrrc(struct hart_t *v,inst_bits_t i);
extern void csrrwi(struct hart_t *v,inst_bits_t i);
extern void csrrsi(struct hart_t *v,inst_bits_t i);
extern void csrrci(struct hart_t *v,inst_bits_t i);

#endif
