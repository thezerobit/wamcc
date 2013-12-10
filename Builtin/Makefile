# /*-----------------------------------------------------------------------*/
# /* WAMCC                               INRIA Rocquencourt - CLoE Project */
# /*                                                           Daniel Diaz */
# /*                                                                       */
# /* Makefile (local compilation)                                          */
# /*-----------------------------------------------------------------------*/

# the following variables are given by ../Makefile at installation time

COMPILER= wamcc
WGCC    = ../src/w_gcc


# other local variables

PFLAGS    = -v
CFLAGS    = -O2 -I../src
LFLAGS    =

BIPS    = inline.o read.o write.o format.o dec10io.o const.o term.o \
          misc.o call.o oper.o list.o trace.o assert.o setof.o
OTHERS  = lib_inline.o

.SUFFIXES:
.SUFFIXES: .o .usr .c .pl $(SUFFIXES)

.pl.c:
	$(COMPILER) $(PFLAGS) -c $*.pl

.pl.usr:
	if [ -f $*.usr ]; then \
	touch $*.usr; \
	else \
	$(COMPILER) $(PFLAGS) -c $*.pl; \
	fi

.usr.o:
	$(WGCC) $(CFLAGS) -c $*.c

.c.o:
	$(WGCC) $(CFLAGS) -c $*.c



all: ../src/builtin.o

../src/builtin.o: build_starter starter.o $(BIPS) $(OTHERS)
	ld -r -o ../src/builtin.o starter.o $(BIPS) $(OTHERS)


starter.c: build_starter Makefile
	build_starter $(BIPS) >starter.c

build_starter: build_starter.c
	$(WGCC) $(CFLAGS) $(LFLAGS) -o build_starter build_starter.c


# bips


inline.o : inline.c inline.usr

read.o   : read.c read.usr

write.o  : write.c write.usr

format.o : format.c format.usr

dec10io.o: dec10io.c dec10io.usr

const.o  : const.c const.usr

term.o   : term.c term.usr

misc.o   : misc.c misc.usr

call.o   : call.c call.usr

oper.o   : oper.c oper.usr

list.o   : list.c list.usr

trace.o  : trace.c trace.usr

assert.o : assert.c assert.usr

setof.o  : setof.c setof.usr






# others







# clean

clean:
	-rm *.o build_starter
