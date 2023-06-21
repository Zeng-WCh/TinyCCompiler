FLEX_COMPILER=flex
INCLUDES=-I./include
SRCDIR=./src
LIBDIR=./lib
FLEXSRC=scanner.l
COMPILER=g++
BISON_COMPILER=bison
BISONSRC=parser.y

.PHONY: all clean
all: build

clean:
	rm -f *.o
	rm -f *.yy.c

all: build

build: parser lex driver

lex: ${SRCDIR}/${FLEXSRC}
	@mkdir -p ./lib
	${FLEX_COMPILER} ${SRCDIR}/${FLEXSRC}
	@mv ${FLEXSRC:.l=.h} ./include
	@mv ${FLEXSRC:.l=.c} ${SRCDIR}
	${COMPILER} ${INCLUDES} -shared -fPIC -o ${LIBDIR}/libscanner.so ${SRCDIR}/${FLEXSRC:.l=.c}

parser:
	@mkdir -p ./lib
	${BISON_COMPILER} -d ${SRCDIR}/${BISONSRC}
	@mv token.h ./include
	@mv ${BISONSRC:.y=.c} ${SRCDIR}
	${COMPILER} ${INCLUDES} -shared -fPIC -o ${LIBDIR}/libparser.so ${SRCDIR}/${BISONSRC:.y=.c}

driver:
	${COMPILER} ${INCLUDES} -o tcc ${SRCDIR}/driver.cpp -L${LIBDIR} -lscanner -lparser

run: 
	LD_LIBRARY_PATH=${LIBDIR} ./tcc