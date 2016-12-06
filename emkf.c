#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>

extern void createMakefile(void);

int add_main(char *argv){
	FILE *fp, *cfp, *lfp;
	char buf[BUFSIZ],buffer[BUFSIZ];
	char filename[BUFSIZ], ofilename[BUFSIZ];
	int n=0,i=0;

	if((fp = fopen("Makefile","r")) == NULL){
		createMakefile();
		fp = fopen("Makefile","r");
	}
	if((cfp = fopen("copymakefile","w")) == NULL){
		perror("fopen:copymakefile");
		exit(1);
	}

	filename[n]=NULL;
	ofilename[n]=NULL;
	for(n=0;n<strlen(argv)-2;n++){
		filename[n] = argv[n];
		ofilename[n] = argv[n];
	}	
	filename[n]='\0';
	ofilename[n]='\0';

	strcat(ofilename,".o");

	while(fgets(buf, BUFSIZ, fp) != NULL){
		if(strstr(buf,"OBJS=")){
			if(strstr(buf,ofilename)){
				printf("already exists\n");
				exit(1);
			}
		}
	}
	rewind(fp);
	while(fgets(buf, BUFSIZ, fp) != NULL){

		if(strstr(buf,"OBJS=")){
			while(1){
				if(buf[i] =='\n'){
					buffer[i]=NULL;
					break;
				}
				buffer[i] = buf[i];
				i++;
			}

			strcat(buffer," ");
			strcat(buffer, filename );
			strcat(buffer,".o");
			strcat(buffer,"\n");

			fputs(buffer,cfp);
		}else if(strstr(buf,"clean:")){
			fprintf(cfp,"%s:\t%s\n",ofilename,argv);
			fprintf(cfp,"\t$(CC) $(CFLAGS) -c %s\n\n",argv);
			fputs(buf,cfp);
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
