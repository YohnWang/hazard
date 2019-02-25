#include<stdio.h>
#include<stdlib.h>
#include<test.h>
#include<cpu.h>
#include<id.h>

int main(int argc,char *argv[])
{
    printf("hazard is runing.\n");
    //test();
    printf("%x,%x\n",get_immj(0x572010ef),0x80001776-0x80000204);
}
