SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include

CC=gcc
CFLAGS=-Wall -pedantic -g -std=c99 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tetris:
	$(CC) $(CFLAGS) -o$(BINDIR)/tetris \
		$(SRCDIR)/main.c \
		$(SRCDIR)/qc_queue_char.c \
		-lpthread \
		-I$(INCLUDEDIR) 




# $@ : target
# $< : first dependancy
# $^ : dependancies
