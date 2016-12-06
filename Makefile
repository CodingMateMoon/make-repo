# Makefile

CC=gcc
CFLAGS=
OBJS= main.o print.o sourceList.o outputFileName.o emk.o emkf.o emkfdel.o emkflib.o addflag.o help.o
LIBS=
all:	target_exe

target_exe:	$(OBJS)
		$(CC)	$(CFLAGS)		-o	em	$(OBJS)	$(LIBS)
main.o:	main.c
	$(CC) $(CFLAGS) -c main.c
print.o:	print.c
	$(CC) $(CFLAGS) -c print.c
sourceList.o:	sourceList.c
	$(CC) $(CFLAGS) -c sourceList.c
outputFileName.o:	outputFileName.c
	$(CC) $(CFLAGS) -c outputFileName.c
emk.o:	emk.c
	$(CC) $(CFLAGS) -c emk.c
emkf.o:	emkf.c
	$(CC) $(CFLAGS) -c emkf.c
emkfdel.o:	emkfdel.c
	$(CC) $(CFLAGS) -c emkfdel.c
emkflib.o:	emkflib.c
	$(CC) $(CFLAGS) -c emkflib.c
addflag.o:	addflag.c
	$(CC) $(CFLAGS) -c addflag.c
help.o:	help.c
	$(CC) $(CFLAGS) -c help.c
clean:
		rm -f $(OBJS) em core

ex1.o:	ex1.c
	$(CC) $(CFLAGS) -c ex1.c

clean:
	rm -f $(OBJS) target_exe core
