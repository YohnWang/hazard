#ifndef TEST_H
#define TEST_H

extern void test_main();

#ifdef DEBUG
#define test() test_main()
#else
#define test() (void)0
#endif

#endif
