#include<cpu.h>
struct sim_t
{

};


void sim(struct cpu_t *v)
{

}

void step(struct cpu_t *v)
{
    inst_bits_t i;
    mem_lw(&i,v->pc);
    //exec(v,i);
}
