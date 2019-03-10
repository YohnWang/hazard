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


#endif
