FLEX_COMPILER=flex
INCLUDES=-I./include -g
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

build: ast parser lex driver

lex: ${SRCDIR}/${FLEXSRC}
	@mkdir -p ./lib
	${FLEX_COMPILER} ${SRCDIR}/${FLEXSRC}
	@mv ${FLEXSRC:.l=.h} ./include
	@mv ${FLEXSRC:.l=.cpp} ${SRCDIR}
	${COMPILER} ${INCLUDES} -shared -fPIC -o ${LIBDIR}/libscanner.so ${SRCDIR}/${FLEXSRC:.l=.cpp}

parser:
	@mkdir -p ./lib
	${BISON_COMPILER} -y -d -t -v ${SRCDIR}/${BISONSRC} -Wconflicts-sr
	@mv token.h ./include
	@mv ${BISONSRC:.y=.cpp} ${SRCDIR}
	${COMPILER} ${INCLUDES} -shared -fPIC -o ${LIBDIR}/libparser.so ${SRCDIR}/${BISONSRC:.y=.cpp}

driver:
	${COMPILER} ${INCLUDES} -o tcc ${SRCDIR}/driver.cpp -L${LIBDIR} -lscanner -lparser -last

ast:
	${COMPILER} ${INCLUDES} -shared -fPIC -o ${LIBDIR}/libast.so ${SRCDIR}/ast.cpp

run: 
	LD_LIBRARY_PATH=${LIBDIR} ./tcc
