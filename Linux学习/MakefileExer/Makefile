GCC=gcc
OBJ=main.o
SRC=main.c
LIB_OBJ=str_len.o str_a2A.o str_A2a.o
LIB_SRC=str_len.c str_a2A.c str_A2a.c
CFLAGS=-Wall -g -O2
LIBNAME=my
LIBPATH=-L./ -l$(LIBNAME)
STATIC_LIB=lib$(LIBNAME).a
DYNAMIC_LIB=lib$(LIBNAME).so
main:$(OBJ) $(STATIC_LIB)
	$(GCC) -o $@ $^ $(LIBPATH) 
$(OBJ):$(SRC)
	$(GCC) -c  $^ $(CFLAGS)
$(DYNAMIC_LIB):$(LIB_SRC)
	$(GCC) -o $@ $^ -shared -fPIC
$(STATIC_LIB):$(LIB_OBJ)
	$(GCC) -c $(LIB_SRC)
	ar -rc $@ $^ 
clean:
	rm -rf *.o main
