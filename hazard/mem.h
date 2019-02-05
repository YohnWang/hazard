#ifndef MEM_H
#define MEM_H

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

extern void mem_lb(uint8_t *data,uintptr_t addr);
extern void mem_lh(uint16_t *data,uintptr_t addr);
extern void mem_lw(uint32_t *data,uintptr_t addr);
extern void mem_ld(uint64_t *data,uintptr_t addr);
extern void mem_sb(uint8_t data,uintptr_t addr);
extern void mem_sh(uint16_t data,uintptr_t addr);
extern void mem_sw(uint32_t data,uintptr_t addr);
extern void mem_sd(uint64_t data,uintptr_t addr);
extern void mem_init(FILE *elf);


#ifdef DUBUG
void test_mem_init(uintptr_t capacity);
void test_mem_del();
#endif // DUBUG

#endif
