#include<cpu.h>
#include<stdint.h>

/* 0000 msip hart 0
 * 0004 msip hart 1
 * 4000 mtimecmp hart 0 lo
 * 4004 mtimecmp hart 0 hi
 * 4008 mtimecmp hart 1 lo
 * 400c mtimecmp hart 1 hi
 * bff8 mtime lo
 * bffc mtime hi
 */

#define MSIP_BASE	0x0
#define MTIMECMP_BASE	0x4000
#define MTIME_BASE	0xbff8
