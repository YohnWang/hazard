#ifndef OPCODEMAP_H
#define OPCODEMAP_H

extern void LOAD(struct cpu_t *v,inst_bits_t i);
extern void STORE(struct cpu_t *v,inst_bits_t i);
extern void BRANCH(struct cpu_t *v,inst_bits_t i);
extern void JALR(struct cpu_t *v,inst_bits_t i);
extern void JAL(struct cpu_t *v,inst_bits_t i);
extern void OP(struct cpu_t *v,inst_bits_t i);
extern void SYSTEM(struct cpu_t *v,inst_bits_t i);
extern void AUIPC(struct cpu_t *v,inst_bits_t i);
extern void LUI(struct cpu_t *v,inst_bits_t i);
extern void OP_IMM32(struct cpu_t *v,inst_bits_t i);
extern void OP32(struct cpu_t *v,inst_bits_t i);

#endif
