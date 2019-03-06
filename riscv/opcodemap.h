#ifndef OPCODEMAP_H
#define OPCODEMAP_H

#include<cpu.h>

extern void LOAD(struct hart_t *v,inst_bits_t i);
extern void STORE(struct hart_t *v,inst_bits_t i);
extern void BRANCH(struct hart_t *v,inst_bits_t i);
extern void JALR(struct hart_t *v,inst_bits_t i);
extern void JAL(struct hart_t *v,inst_bits_t i);
extern void OP(struct hart_t *v,inst_bits_t i);
extern void SYSTEM(struct hart_t *v,inst_bits_t i);
extern void AUIPC(struct hart_t *v,inst_bits_t i);
extern void LUI(struct hart_t *v,inst_bits_t i);
extern void OP_IMM32(struct hart_t *v,inst_bits_t i);
extern void OP32(struct hart_t *v,inst_bits_t i);

#endif
