#include<stdlib.h>
#include<stdio.h>

void createMakefile(void) {

	FILE *rfp, *wfp;
	char buf[BUFSIZ];
	int n;

	if((wfp = fopen("Makefile","w")) == NULL){
		perror("fopen: Makefile");
		exit(1);
	}

	fprintf(wfp, "# Makefile\n\n");
	fprintf(wfp,"CC=gcc\n");
	fprintf(wfp,"CFLAGS=\n");
	fprintf(wfp,"OBJS=\n");
	fprintf(wfp,"LIBS=\n");
	fprintf(wfp,"all:\tadd\n\n");
	fprintf(wfp,"add:\t$(OBJS)\n");
	fprintf(wfp,"\t$(CC) $(CFLAGS) -o add $(OBJS) $(LIBS)\n");
	fprintf(wfp,"clean:\n");
	fprintf(wfp,"\trm -f $(OBJS) add core");
			
	

	fclose(wfp);
}
