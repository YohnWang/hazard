#ifndef ID_H
#define ID_H

#include<cpu.h>

extern int get_op(inst_bits_t i);
extern int get_rd(inst_bits_t i);
extern int get_rs1(inst_bits_t i);
extern int get_rs2(inst_bits_t i);
extern int get_funct3(inst_bits_t i);
extern int get_funct7(inst_bits_t i);
extern int get_immi(inst_bits_t i);
extern int get_imms(inst_bits_t i);
extern int get_immb(inst_bits_t i);
extern int get_immu(inst_bits_t i);
extern int get_immj(inst_bits_t i);


#endif
