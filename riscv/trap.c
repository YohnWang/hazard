#include<cpu.h>
#include<stdint.h>
#include<trap.h>

void trap(struct hart_t *v,inst_bits_t i)
{
    if(v->ctrl.trap==EXCEPTION)
    {

    }
}
