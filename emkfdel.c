#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int del_main(char *argv){
	FILE *fp, *cfp, *lfp;
	char buf[BUFSIZ],buffer[BUFSIZ];
	char filename[BUFSIZ], ofilename[BUFSIZ];
	char *index = NULL;
	int n=0,i=0,j=0,k=0;


	memset(filename, 0, sizeof(filename));
	memset(ofilename, 0, sizeof(ofilename));
	memset(buf, 0, sizeof(buf));
	memset(buffer, 0, sizeof(buffer));

	for(n=0;n<strlen(argv)-2;n++){
		filename[n] = argv[n];
	}
	filename[n]='\0';
	strcpy(ofilename,filename);
	strcat(filename,".c");


	if((fp = fopen("Makefile","r")) == NULL){
		perror("fopen:Makefile");
		exit(1);
	}

	if((cfp = fopen("copymakefile","w")) == NULL){
		perror("fopen:copymakefile");
		exit(1);
	}
	while(fgets(buf, BUFSIZ, fp) != NULL){

		if(strstr(buf,"OBJS=")){
			strcat(ofilename,".o");
			index = strstr(buf,ofilename);
			while(1){
				buffer[j] = buf[j];
				if(j==((int)(index-buf)-2)){
					j++;
					k=j;
					break;
				}
				j++;
			}
			j=j+(strlen(ofilename)+1);

			while(1){
				buffer[k] = buf[j];
				if(buf[j] == '\n'){
					buf[j] = '\0';
					break;
				}
				j++;
				k++;
			}

			fputs(buffer,cfp);
		}else if(strstr(buf,filename)){
		}else{
			fputs(buf,cfp);
		}
	}
	fclose(fp);
	fclose(cfp);

	if((fp = fopen("Makefile","w")) == NULL){
		perror("fopen:Makefile");
		exit(1);
	}

	if((lfp = fopen("copymakefile","r")) == NULL){
		perror("fopen:copymakefile");
		exit(1);
	}
	while(fgets(buf, BUFSIZ, lfp) != NULL){
		fputs(buf,fp);
	}

	fclose(fp);
	fclose(lfp);

	remove("copymakefile");


	return 0;
}
