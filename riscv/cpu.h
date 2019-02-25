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
    struct reg_t reg;
    struct csr_t csr;
};

struct R_type
{
    uint32_t op:7;
    uint32_t rd:5;
    uint32_t funct3:3;
    uint32_t rs1:5;
    uint32_t rs2:5;
    uint32_t funct7:7;
};

struct I_type
{
    uint32_t op:7;
    uint32_t rd:5;
    uint32_t funct3:3;
    uint32_t rs1:5;
    int32_t imm:12;
};

struct S_type
{
    uint32_t op:7;
    uint32_t rd:5;
    uint32_t funct3:3;
    uint32_t rs1:5;
    int32_t imm:12;
};

struct J_type
{

};

union inst_t
{
    uint32_t row;
    struct R_type   R;

};

typedef uint32_t inst_bits_t;


#endif
