// main source of EM
// created by Moon Jang-Hyun, Jo Duck-Hyun, Choi Ji-Hun.

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

extern void printMakefile(void);
extern void printSourcefile(char *);
extern void modifyOutputFileName(char *fileName);
extern void addflag(char *option);

int main(int argc, char* argv[]) {
	int n;
	extern char* optarg;
	extern int optind;
	// long options 
	static struct option long_options[] = {
		{"print", no_argument, 0, 'p'},
		{"source", required_argument, 0, 's'},
		{"output", required_argument, 0, 'o'},
		{"add", required_argument, 0, 'a'},
		{"delete", required_argument, 0, 'd'},
		{"lib", required_argument, 0, 'l'},
		{"flag", required_argument, 0, 'f'},
		{"clean", no_argument, 0, 'c'},
		{"version", no_argument, 0, 'v'},
		{0, 0, 0, 0}
	};
	int long_opt_index = 0;

	// When no Options
	if( argc ==1 ) {
		if(access("./Makefile", 0) == 0) {
			if(execlp("make", "make", (char *)NULL) == -1) {
				perror("execlp");
			}
		} else {
			printf("\'Makefile\' does not exist!!\n");
		}
		exit(1);
	}


	// Get Options And Switch Process
	while((n = getopt_long(argc, argv, "ps:o:a:d:l:f:cv", long_options, &long_opt_index)) != -1) {
		switch(n) {
			case 'p' : // print Makefile
				printMakefile();
				break;
			case 's' : // print source files
				printSourcefile(optarg);
				break;
			case 'o' : // set ouput file name
				modifyOutputFileName(optarg);
				break;
			case 'a' : // add file in Makefile
				break;
			case 'd' : // delete file in Makefile
				printf("selected %s\n", long_options[long_opt_index].name);
				break;
			case 'l' : // add library in Makefile
				printf("selected %s\n", long_options[long_opt_index].name);
				break;
			case 'f' : // add flag
				addflag(optarg);
				break;
			case 'c' : // execute clean
				if(execlp("make","make","clean",(char)NULL)==-1){
					perror("execlp");
				}
				break;
			case 'v' : // print version info
				printf("Easy Makefile version 1.0\n");
				printf("copyright 2016. JMC All rights reserved.\n");
				break;
		}
	}

	return 0;
}
