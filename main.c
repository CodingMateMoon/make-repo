// main source of EM
// created by Moon Jang-Hyun, Jo Duck-Hyun, Choi Ji-Hun.

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int n;
	extern char* optarg;
	extern int optind;

	// Get Options And Switch Process
	while((n = getopt(argc, argv, "pa:d:o:l:f:cv")) != -1) {
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
