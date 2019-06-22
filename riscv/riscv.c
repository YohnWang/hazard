#include<cpu.h>
struct sim_t
{

};


void sim(struct hart_t *v)
{

}

void step(struct hart_t *v)
{
    // fetch
    inst_bits_t i;
    mem_lw(&i,v->pc);

    //decode and execute
    launch(v,i);

    //exception and interrupt
    //trap(v);

    //
}
