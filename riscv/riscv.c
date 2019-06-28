#include<cpu.h>
#include<opcodemap.h>
struct sim_t
{

};


void sim(struct hart_t *v)
{

}

void step(struct hart_t *v)
{
    //prepare
    v->ctrl.pcsel=PCPLUS4;
    v->x[0]=0;

    // fetch
    inst_bits_t i;
    mem_lw(&i,v->pc);

    //decode and execute
    launch(v,i);

    //exception and interrupt
    //trap(v);

    //after
    switch(v->ctrl.pcsel)
    {
        case PCPLUS4: v->pc+=4;break;
        case PCPLUS2: v->pc+=2;break;
        case PCJUMP : v->pc=v->ctrl.pcnext;break;
        //case PC_MTVEC: v->pc=v->csr.mtvec;break;
        //case PC_MEPC : v->pc=v->csr.mepc;break;
    }
}
