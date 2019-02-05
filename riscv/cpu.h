#ifndef CPU_H
#define CPU_H
#include<stdint.h>

struct reg_t
{
    intptr_t x[32];
};

struct csr_t
{

};

struct cpu_t
{
    reg_t reg;
    csr_t csr;
};

#endif
