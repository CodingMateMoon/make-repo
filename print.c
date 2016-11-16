// print.c
// create by Choi Ji-Hun. 2016.11.16
// It is a function for em's main.c
// print Makefile's context When call -p or --print option

#include <stdlib.h>
#include <stdio.h>

void printMakefile(void) {
	FILE* fp;
	char buf[BUFSIZ];

	if((fp=fopen("Makefile", "r")) == NULL) {
		perror("fopen : Makefile");
		exit(1);
	}

	while (fgets(buf, BUFSIZ, fp) != NULL) {
		fprintf(stdout, "%s", buf);
	}

	fclose(fp);
}

