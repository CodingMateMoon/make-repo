#include<stdlib.h>
#include<stdio.h>

void createMakefile(void) {

	FILE *mfp;
	char buf[BUFSIZ];
	int n;

	if((mfp = fopen("Makefile","w")) == NULL){
		perror("fopen: Makefile");
		exit(1);
	}

	fprintf(mfp, "# Makefile\n\n");
	fprintf(mfp,"CC=gcc\n");
	fprintf(mfp,"CFLAGS=\n");
	fprintf(mfp,"OBJS=\n");
	fprintf(mfp,"LIBS=\n");
	fprintf(mfp,"all:\ttarget_exe\n\n");
	fprintf(mfp,"target_exe:\t$(OBJS)\n");
	fprintf(mfp,"\t$(CC) $(CFLAGS) -o target_exe $(OBJS) $(LIBS)\n");
	fprintf(mfp,"clean:\n");
	fprintf(mfp,"\trm -f $(OBJS) target_exe core\n");



	fclose(mfp);

}
