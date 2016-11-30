// outputFileName.c
// create by Choi Ji-Hun. 2016.11.30
// It is a function for em's main.c
// modify Makefile's output(target) file name

#include <stdlib.h>
#include <stdio.h>


void modifyOutputFileName(char *fileName) {
	FILE* fp, *cfp;
	char buf[BUFSIZ];


	// Makefile -> copymakefile(Modified Makefile)
	if((fp=fopen("Makefile", "r")) == NULL) {
		perror("fopen : Makefile");
		exit(1);
	}

	if((cfp = fopen("copymakefile","w")) == NULL){
		perror("fopen:copymakefile");
		exit(1);
	}

	while (fgets(buf, BUFSIZ, fp) != NULL) {
		// find : "gcc -o". -> apply new output file name 
		if(strstr(buf, "$(CC)	$(CFLAGS)		-o")) {
			fprintf(cfp, "		$(CC)	$(CFLAGS)		-o	%s	$(OBJS)	$(LIBS)\n", fileName);
		} else {
			fputs(buf, cfp);
		}
	}
	fclose(cfp);
	fclose(fp);



	// copymakefile -> Makefile(overwrite)
	if((fp=fopen("Makefile", "w")) == NULL) {
		perror("fopen : Makefile");
		exit(1);
	}

	if((cfp = fopen("copymakefile","r")) == NULL){
		perror("fopen:copymakefile");
		exit(1);
	}

	while (fgets(buf, BUFSIZ, cfp) != NULL) {
		fputs(buf, fp);
	}
	fclose(cfp);
	fclose(fp);



	// remove compymakefile
	remove("copymakefile");

}
