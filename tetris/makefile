SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include

CC=gcc
CFLAGS=-Wall -pedantic -g -std=c89 -ansi
DEPS=my_lib.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o$(BINDIR)/$(EXEC) $(SRCDIR)/*.c

# $@ : target
# $< : first dependancy
# $^ : dependancies
