#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

extern void createMakefile(void);

int lib_main(char *argv){
	FILE *fp, *cfp, *lfp;
	char buf[BUFSIZ],buffer[BUFSIZ];
	char filename[BUFSIZ];
	int n=0,i=0;


	if((fp = fopen("Makefile","r")) == NULL){
		createMakefile();
		fp = fopen("Makefile","r");
	}
	if((cfp = fopen("copymakefile","w")) == NULL){
		perror("fopen:copymakefile");
		exit(1);
	}
	while(fgets(buf, BUFSIZ, fp) !=	NULL){
		if(strstr(buf,"LIBS=")){
			if(strstr(buf,argv)){
				printf("already exists\n");
				exit(1);
			}
		}
	}
	rewind(fp);
	while(fgets(buf, BUFSIZ, fp) != NULL){

		if(strstr(buf,"LIBS=")){

			while(1){
				if(buf[i] =='\n'){
					buffer[i]=NULL;
					break;
				}
				buffer[i] = buf[i];
				i++;
			}


			strcat(buffer," ");
			strcat(buffer, argv );
			strcat(buffer,"\n");
			fputs(buffer,cfp);

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
