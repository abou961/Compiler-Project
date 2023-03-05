CC=g++

PROGS = prog

OBJ = automate.o state.o lexer.o symbol.o

all: ${PROGS}

prog: ${OBJ}
	${CC} -o $@ main.cpp $^

automate.o: automate.cpp
	${CC} -c $^

state.o: state.cpp
	${CC} -c $^

lexer.o: lexer.cpp
	${CC} -c $^

symbol.o: symbol.cpp
	${CC} -c $^

clean:
	rm *.o prog