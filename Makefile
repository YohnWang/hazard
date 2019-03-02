
CC = gcc

INCLUDES = \
	-I./hazard \
	-I./riscv \
	-I./test
	
WARNINGS= -Wall

CFLAGS =  \
	$(WARNINGS) $(INCLUDES)\
	-DDEBUG -g
	

SRC =  $(wildcard ./hazard/*.c ./riscv/*.c ./test./*.c)


OBJ = $(SRC:%.c=%.o)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o hazard.exe 
	

clean:
	-find . -name "*.o" |xargs rm 
	-find . -name "*.exe" |xargs rm

run: all 
	./hazard.exe
