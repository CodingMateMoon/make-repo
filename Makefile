# Makefile
# This Makefile use not 'em'.
# It is temp Makefile until em is released

CC=gcc
CFLAGS=
OBJS=main.o print.o sourceList.o outputFileName.o
LIBS=
all: em

em:	$(OBJS)
		$(CC)	$(CFLAGS)		-o	em.out	$(OBJS)	$(LIBS)

main.o:	main.c
	$(CC)	$(CFLAGS)		-c	main.c

print.o: print.c
	$(CC)	$(CFLAGS)		-c	print.c

sourceList.o: sourceList.c
	$(CC)	$(CFLAGS)		-c	sourceList.c

outputFileName.o: outputFileName.c
	$(CC)	$(CFLAGS)		-c	outputFileName.c


clean:
		rm -f ${OBJS} eme.out core

