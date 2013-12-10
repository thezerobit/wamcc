# /*-----------------------------------------------------------------------*/
# /* WAMCC                               INRIA Rocquencourt - CLoE Project */
# /*                                                           Daniel Diaz */
# /*                                                                       */
# /* Makefile                                                              */
# /*-----------------------------------------------------------------------*/

# you can change the following paths

ROOTPATH= $(HOME)/$(COMPILER)
INCPATH = $(ROOTPATH)/include
LIBPATH = $(ROOTPATH)/lib
BINPATH = $(ROOTPATH)/bin

# do not change anything else

COMPILER= wamcc
WGCC    = w_gcc

BMF     = bmf_$(COMPILER)

EXECS   = $(WGCC) $(COMPILER) $(BMF) hex2pl pl2hex

install:
	cd src; echo $(ROOTPATH);\
	make $(WGCC) COMPILER=$(COMPILER) INCPATH=$(INCPATH) \
                     LIBPATH=$(LIBPATH) WGCC=$(WGCC)
	cd Builtin; \
	make COMPILER=$(COMPILER) WGCC=../src/$(WGCC)
	cd src; \
	make COMPILER=$(COMPILER) INCPATH=$(INCPATH) \
             LIBPATH=$(LIBPATH) WGCC=$(WGCC)
	-mkdir -p $(INCPATH)
	-mkdir -p $(LIBPATH)
	-mkdir -p $(BINPATH)
	cp src/*.h $(INCPATH)
	rm $(INCPATH)/wamcc*.h
	cp src/*.a $(LIBPATH)
	ranlib $(LIBPATH)/*.a
	cp src/$(WGCC) src/$(COMPILER) src/$(BMF) src/hex2pl src/pl2hex $(BINPATH)


clean:
	cd src;     make clean
	cd Builtin; make clean
