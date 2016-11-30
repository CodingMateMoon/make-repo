# Makefile

CC=gcc
CFLAGS=
OBJS= emk.o emkf.o
LIBS=
all:	add

add:	$(OBJS)
	$(CC) $(CFLAGS) -o add $(OBJS) $(LIBS)
emk:	emk.c
	$(CC) $(CFLAGS) -c emk.c
emkf:	emkf.c
	$(CC) $(CFLAGS) -c emkf.c
clean:
	rm -f $(OBJS) add core