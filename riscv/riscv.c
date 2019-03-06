#include<cpu.h>
struct sim_t
{

};


void sim(struct hart_t *v)
{

}

void step(struct hart_t *v)
{
    inst_bits_t i;
    mem_lw(&i,v->pc);
    //exec(v,i);
}
