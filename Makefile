# Makefile

CC=gcc
CFLAGS=
OBJS= emkf.o emk.o main.o sourceList.o print.o outputFileName.o emkfdel.o emkflib.o addflag.o ex1.o
LIBS=
all:	target_exe

target_exe:	$(OBJS)
	$(CC) $(CFLAGS) -o target_exe $(OBJS) $(LIBS)
emkf.o:	emkf.c
	$(CC) $(CFLAGS) -c emkf.c

emk.o:	emk.c
	$(CC) $(CFLAGS) -c emk.c

main.o:	main.c
	$(CC) $(CFLAGS) -c main.c

sourceList.o:	sourceList.c
	$(CC) $(CFLAGS) -c sourceList.c


print.o:	print.c
	$(CC) $(CFLAGS) -c print.c

outputFileName.o:	outputFileName.c
	$(CC) $(CFLAGS) -c outputFileName.c

emkfdel.o:	emkfdel.c
	$(CC) $(CFLAGS) -c emkfdel.c

emkflib.o:	emkflib.c
	$(CC) $(CFLAGS) -c emkflib.c

addflag.o:	addflag.c
	$(CC) $(CFLAGS) -c addflag.c

ex1.o:	ex1.c
	$(CC) $(CFLAGS) -c ex1.c

clean:
	rm -f $(OBJS) target_exe core
