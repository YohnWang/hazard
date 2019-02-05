#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

static void *mem; //alloc 4GiB memory

void mem_lb(uint8_t *data,uintptr_t addr)
{
    *data=((uint8_t*)mem)[addr];
}

void mem_lh(uint16_t *data,uintptr_t addr)
{
    *data=((uint16_t*)mem)[addr>>1];
}

void mem_lw(uint32_t *data,uintptr_t addr)
{
    *data=((uint32_t*)mem)[addr>>2];
}

void mem_ld(uint64_t *data,uintptr_t addr)
{
    *data=((uint64_t*)mem)[addr>>3];
}

void mem_sb(uint8_t data,uintptr_t addr)
{
    ((uint8_t*)mem)[addr]=data;
}

void mem_sh(uint16_t data,uintptr_t addr)
{
    ((uint16_t*)mem)[addr>>1]=data;
}

void mem_sw(uint32_t data,uintptr_t addr)
{
    ((uint32_t*)mem)[addr>>2]=data;
}

void mem_sd(uint64_t data,uintptr_t addr)
{
    ((uint64_t*)mem)[addr>>3]=data;
}

void init_mem(FILE *elf)
{
    mem=malloc(1024);
}
