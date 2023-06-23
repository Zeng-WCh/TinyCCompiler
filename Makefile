FLEX_COMPILER=flex
INCLUDES=-I./include -g
SRCDIR=./src
LIBDIR=./lib
FLEXSRC=scanner.l
COMPILER=clang++
BISON_COMPILER=bison
BISONSRC=parser.y
LLVMFLAG=`llvm-config --cxxflags --ldflags --system-libs --libs core orcjit native`

.PHONY: all clean
all: build

clean:
	@rm ./lib/*
	@rm ./tcc

all: build

build: symtab ast parser lex driver

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
	${COMPILER} ${INCLUDES} ${LLVMFLAG} -o tcc ${SRCDIR}/driver.cpp -L${LIBDIR} -lscanner -lparser -last -ltable

ast:
	@mkdir -p ./lib
	${COMPILER} ${INCLUDES} ${LLVMFLAG} -shared -fPIC -o ${LIBDIR}/libast.so ${SRCDIR}/ast.cpp

symtab:
	@mkdir -p ./lib
	${COMPILER} ${INCLUDES} -shared -fPIC -o ${LIBDIR}/libtable.so ${SRCDIR}/SymbolTable.cpp

run: 
	LD_LIBRARY_PATH=${LIBDIR} ./tcc
