# Command 
CC = gcc
# For make static library
AR = ar 

# Flags setup

# Triggers many warnings for problems in the source code, helps identify possible errors
# and adds debug information when compiling, useful for running a debugger to find faults in the code.
 CFLAGS = -Wall -g
#defines to create a dynamic library (shared library) instead of an executable file.
LFLAGS = -shared
#definition of an archiver (archiver) for make a static library.
SFLAGS = rcs
#adds instructions to PIC, which allows the dynamic library to be loaded anywhere in memory regardless of position and avoid from used same memory in different librarys.
FP = -fPIC


# File names
MAIN = main.c
HEADER = NumClass.h
LIBBASIC = basicClassification.c
LIBLOOP = advancedClassificationLoop.c
LIBREC = advancedClassificationRecursion.c
# library names
LIBLOOPST = libclassloops.a
LIBRECST = libclassrec.a
LIBLOOPDY = libclassloops.so
LIBRECDY = libclassrec.so

# Phony tag for non-targeted commands
.PHONY: all clean loops recursives recursived loopd

# Build everything 
all: mains maindloop maindrec loops recursives recursived loopd

# Marcos to build libraries
loops: $(LIBLOOPST)

recursives: $(LIBRECST)

loopd: $(LIBLOOPDY)

recursived: $(LIBRECDY)


# Build main programs

# The main program with static library of recursive implametation
mains: $(MAIN:.c=.o) $(LIBRECST)
	$(CC) $(CFLAGS) $< ./$(LIBRECST) -o $@

# The main program with dynamic library of loops implametation 
maindloop: $(MAIN:.c=.o) $(LIBLOOPDY)
	$(CC) $(CFLAGS) $< ./$(LIBLOOPDY) -o $@

# The main program with dynamic library of recursive implametation
maindrec: $(MAIN:.c=.o) $(LIBRECDY)
	$(CC) $(CFLAGS) $< ./$(LIBRECDY) -o $@

# Compile the main program to an object file
$(MAIN:.c=.o): $(MAIN) $(HEADER)
	$(CC) $(CFLAGS) -c $^

# Building all necessary libraries
$(LIBRECDY): $(LIBREC:.c=.o) $(LIBBASIC:.c=.o)
	$(CC) $(LFLAGS) $(CFLAGS) $^ -o $@

$(LIBLOOPDY): $(LIBLOOP:.c=.o) $(LIBBASIC:.c=.o)
	$(CC) $(LFLAGS) $(CFLAGS) $^ -o $@

$(LIBLOOPST): $(LIBLOOP:.c=.o) $(LIBBASIC:.c=.o)
	$(AR) $(SFLAGS) $@ $^

$(LIBRECST): $(LIBREC:.c=.o) $(LIBBASIC:.c=.o)
	$(AR) $(SFLAGS) $@ $^

$(LIBLOOP:.c=.o): $(LIBLOOP) $(HEADER)
	$(CC) $(CFLAGS) -c $^ $(FP)

$(LIBREC:.c=.o): $(LIBREC) $(HEADER)
	$(CC) $(CFLAGS) -c $^ $(FP)

$(LIBBASIC:.c=.o): $(LIBBASIC) $(HEADER)
	$(CC) $(CFLAGS) -c $^ $(FP)

# Clean command to cleanup all the compiled files (*.o, *.a, *.so, *.gch, mains, maindloop and maindrec)
clean:
	rm -f mains maindloop maindrec *.o *.a *.so *.gch