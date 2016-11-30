#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

extern void createMakefile(void);

int main(int argc, char *argv[]){
	FILE *fp, *cfp, *lfp;
	char buf[BUFSIZ],buffer[BUFSIZ];
	char filename[BUFSIZ], a;
	int n=0,i=0;

	if(argv[1]==NULL){
		exit(1);
	}
	if(!strcmp(argv[1],"-a") || !strcmp(argv[1],"-add")){
		
		if(argv[2]==NULL){
			exit(1);
		}else{
			filename[n]=NULL;
			for(n=0;n<strlen(argv[2])-2;n++){
				filename[n] = argv[2][n];
			}
			filename[n]='\0';
		}

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
				fprintf(cfp,"%s:\t%s\n",filename,argv[2]);
				fprintf(cfp,"\t$(CC) $(CFLAGS) -c %s\n",argv[2]);
				fputs(buf,cfp);
			}else{
				fputs(buf,cfp);
				
			}
		}
		fclose(fp);
		fclose(cfp);

	}

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
