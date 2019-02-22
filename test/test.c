#include<stdio.h>
#include<mem.h>

static void test_mem()
{
    uint8_t test_v1;
    uint16_t test_v2;
    uint32_t test_v3;
    uint64_t test_v4;
    uint8_t test_add;
    test_mem_init(0x10000);
    mem_sb(2,8);
    mem_sh(5,64);
    mem_sw(2019,120);
    mem_sd(10000,256);
    mem_lb(&test_v1,8);
    mem_lh(&test_v2,64);
    mem_lw(&test_v3,120);
    mem_ld(&test_v4,256);
    fprintf(stderr,"%d/%hu/%u %llu\n", test_v1,test_v2,test_v3,test_v4);
    fprintf(stderr,"#Memory is [OK]#\n");
    test_mem_del();
}

void test_main()
{
    fprintf(stderr,"test begin...\n");
    test_mem();
    fprintf(stderr,"test end...\n");
}
