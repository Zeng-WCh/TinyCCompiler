FLEX_COMPILER=flex
TOKEN_INCLUDES=-I../
SRC=scanner.l
COMPILER=g++

.PHONY: all clean
all: build

clean:
	rm -f *.o
	rm -f *.yy.c

all: lex build

build: lex
	${COMPILER} ${TOKEN_INCLUDES} -o ${SRC:.l=.o} ${SRC:.l=.c}

lex: ${SRC}
	${FLEX_COMPILER} ${SRC}

run: all
	./scanner.o
