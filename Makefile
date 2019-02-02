
CC = gcc

INCLUDES = \
	-I./hazard \
	-I./riscv \
	-I./test
	
WARNINGS= -Wall

CFLAGS =  \
	$(WARNINGS) $(INCLUDES)\
	-DDEBUG
	

OBJ = ./hazard/hazard.o ./test/test.o ./hazard/mem.o

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(OBJ)
	$(CC) $(OBJ) -o hazard.exe 
	

clean:
	-find . -name "*.o" |xargs rm 
	-find . -name "*.exe" |xargs rm

run: all 
	./hazard.exe
