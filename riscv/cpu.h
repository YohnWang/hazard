#ifndef CPU_H
#define CPU_H
#include<stdint.h>

#include<mem.h>

typedef intptr_t reg_t;


struct csr_t
{

};

typedef reg_t regfile_t[32];

//hardware thread
struct hart_t
{
    reg_t  pc;
    regfile_t x;
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


typedef uint32_t inst_bits_t;


#endif
