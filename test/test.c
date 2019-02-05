#include<stdio.h>
#include<mem.h>


static void test_mem()
{
    int x,y,z;
    test_mem_init(0x10000);
    mem_sb(2,32);
    mem_sh(5,64);
    mem_sw(2019,100);
    mem_lb(&x,32);
    mem_lh(&y,64);
    mem_lw(&z,100);
    fprintf(stderr,"%d ",x);
    fprintf(stderr,"%d ",y);
    fprintf(stderr,"%d\n",z);
    test_mem_del();
}

void test_main()
{
    fprintf(stderr,"test begin...\n");
    test_mem();
    fprintf(stderr,"test end...\n");
}
