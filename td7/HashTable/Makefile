MAKE = make
GCC = gcc
ECHO = echo
LIBFLAGS = 
CFLAGS = -Wall -g -ggdb -std=c2x
INCLUDE = include/
SRC = $(wildcard src/*.c)
MOVE = mv
EXC = ./bin/main
LIB = lib/
READ = @read -p
BIN = bin/*

all :
	$(MAKE) compile -s
	$(MAKE) run -s

compile :
	@$(GCC) $(CFLAGS) -I $(INCLUDE) -c $(SRC) $(LIBFLAGS)
	@$(MOVE) *.o $(LIB)
	@$(GCC) $(CFLAGS) -o $(EXC) $(LIB)*.o $(LIBFLAGS)

run :
	@$(EXC)

clean :
	rm $(BIN) $(LIB)*
