# /*-----------------------------------------------------------------------*/
# /* WAMCC                               INRIA Rocquencourt - CLoE Project */
# /*                                                           Daniel Diaz */
# /*                                                                       */
# /* Makefile (local compilation)                                          */
# /*-----------------------------------------------------------------------*/

# the following variables are given by ../Makefile at installation time

COMPILER= wamcc
INCPATH = `pwd`
LIBPATH = `pwd`
WGCC    = w_gcc


# other local variables

CC      = gcc
CFLAGS  = -O2
LFLAGS  =
BMF     = bmf_$(COMPILER)

OBJLIB  = machine.o wam_engine.o    atom_pred.o debugger.o hash.o builtin.o

OBJLIBPP= machine.o wam_engine_pp.o atom_pred.o debugger.o hash.o builtin.o

EXECS   = configure $(WGCC) $(COMPILER) $(BMF) hex2pl pl2hex

all: $(WGCC) lib$(COMPILER).a lib$(COMPILER)_pp.a $(BMF) hex2pl pl2hex $(COMPILER)


lib$(COMPILER).a: $(OBJLIB)
	-rm lib$(COMPILER).a 
	ar rc lib$(COMPILER).a $(OBJLIB)
	ranlib lib$(COMPILER).a

lib$(COMPILER)_pp.a: $(OBJLIBPP)
	-rm lib$(COMPILER)_pp.a 
	ar rc lib$(COMPILER)_pp.a $(OBJLIBPP)
	ranlib lib$(COMPILER)_pp.a



# objects


machine.o: machine.h archi.h wam_engine.h machine.c
	$(WGCC) $(CFLAGS) -c machine.c

wam_engine.o: machine.h archi.h wam_engine.h atom_pred.h wam_engine.c 
	$(WGCC) $(CFLAGS) -c wam_engine.c

wam_engine_pp.o: machine.h archi.h wam_engine.h atom_pred.h wam_engine.c
	$(WGCC) $(CFLAGS) -DWAM_PROFILE -c -o wam_engine_pp.o wam_engine.c

atom_pred.o: machine.h archi.h wam_engine.h atom_pred.h atom_pred.c
	$(WGCC) $(CFLAGS) -c atom_pred.c

debugger.o: machine.h archi.h wam_engine.h atom_pred.h debugger.c
	$(WGCC) $(CFLAGS) -c debugger.c

hash.o: machine.h hash.c
	$(WGCC) $(CFLAGS) -c hash.c




# execs

configure: configure.c machine.h ../Makefile
	$(CC) $(CFLAGS) $(LFLAGS) -DCOMPILER='"'$(COMPILER)'"' \
		-DWGCC='"'$(WGCC)'"' -DINCPATH='"'$(INCPATH)'"' \
		-DLIBPATH='"'$(LIBPATH)'"' $(LFLAGS) -o configure configure.c


$(WGCC): configure archi.def
	configure
	chmod a+x $(WGCC)

$(BMF): bmf.c
	$(WGCC) $(CFLAGS) $(LFLAGS) -DWGCC='"'$(WGCC)'"' -o $(BMF) bmf.c


hex2pl: hex2pl.c
	$(CC) $(CFLAGS) $(LFLAGS) -o hex2pl hex2pl.c

pl2hex: pl2hex.c
	$(CC) $(CFLAGS) $(LFLAGS) -o pl2hex pl2hex.c

$(COMPILER):
	$(WGCC) $(CFLAGS) -c wamcc*.c
	$(WGCC) $(CFLAGS) $(LFLAGS) -s -o $(COMPILER) wamcc*.o -l$(COMPILER)



sics_comp:
	{ echo "[b], c, asserta((compiler_name($(COMPILER)):-!)). "; \
	  echo "save('s_$(COMPILER)'), go. "; \
	}  | sicstus_native


# clean

clean:
	-rm *.o
	-rm *.a
	-rm $(EXECS)
