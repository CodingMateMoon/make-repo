// help.c
// created by Choi Ji-Hun. 2016.12.6
// It is a function for em's main.c
// print Usage for em.

#include <stdio.h>

void printHelp(void) {

	printf("usage : em [-p] [--print] [-s <file_name>] [--source <file_name>]\n");
	printf("           [-o <file_name>] [--output <file_name>]\n");
	printf("           [-a <file_name>] [--add <file_name>]\n");
	printf("           [-d <file_name>] [--delete <file_name>]\n");
	printf("           [-l <library>] [--lib <library>]\n");
	printf("           [-f <option>] [--flag <option>]\n");
	printf("           [-c] [--clean] [-v] [--version] [-h] [--help]\n\n");
	printf("Details about options\n");
	printf("\t-p, --print\t : print Makefile's context.\n");
	printf("\t-s, --source <file_name>\t : print Makefile's source files. --all is print all source files.\n");
	printf("\t-o, --output <file_name>\t : modify Makefile's output(target) file name\n");
	printf("\t-a, --add <file_name>\t : Add Makefile's source files\n");
	printf("\t-d, --delete <file_name>\t : Delete Makefile's source files\n");
	printf("\t-l, --lib <library>\t : Add Makefile's libraries\n");
	printf("\t-f, --flag <option>\t : Add Makefile's compile options\n");
	printf("\t-c, --clean\t : execute make's clean\n");
	printf("\t-v, --version\t : print version of em.\n");
	printf("\t-h, --help\t : print Usage for em. (This Page.)\n\n");

}
