#include<stdio.h>
#include<mem.h>


static void test_mem()
{
    test_mem_init(0x10000);
    mem_sw(77777,100);
    int x;
    mem_lw(&x,100);
    fprintf(stderr,"%d\n",x);
    test_mem_del();
}

void test_main()
{
    fprintf(stderr,"test begin...\n");
    test_mem();
    fprintf(stderr,"test end...\n");
}
