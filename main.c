// main source of EM
// created by Moon Jang-Hyun, Jo Duck-Hyun, Choi Ji-Hun.

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

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


	// Get Options And Switch Process
	while((n = getopt_long(argc, argv, "pa:d:o:l:f:cv", long_options, &optind)) != -1) {
		switch(n) {
			case 'p' : // print Makefile
				break;
			case 'a' : // add file in Makefile
				break;
			case 'd' : // delete file in Makefile
				break;
			case 'o' : // set ouput file name
				break;
			case 'l' : // add library in Makefile
				break;
			case 'f' : // add flag
				break;
			case 'c' : // execute clean
				break;
			case 'v' : // print version info
				break;
		}
	}

	return 0;
}
