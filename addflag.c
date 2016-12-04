#include <stdlib.h>
#include <stdio.h>

void addflag(char *option){
	FILE *fp, *cfp;
	char buf[BUFSIZ],buffer[BUFSIZ];
	int i=0;
	if((fp=fopen("Makefile","r"))==NULL){
		perror("fopen : Makefile");
		exit(1);
	}
	
	if((cfp = fopen("copymakefile","w")) == NULL){
		perror("fopen:copymakefile");
		exit(1);
	}
	
	while(fgets(buf,BUFSIZ,fp)!=NULL){
		
		if(strstr(buf,"CFLAGS=")){
			while(1){
				if(buf[i]=='\n'){
					buffer[i]=NULL;
					break;
				}
				buffer[i]=buf[i];
				i++;
			}
			strcat(buffer," ");
			strcat(buffer,option);
			strcat(buffer,"\n");
			fputs(buffer,cfp);
	    }
		else{
			fputs(buf,cfp);
		}
	}

	fclose(cfp);
	fclose(fp);
	// copymakefile -> Makefile(overwrite)
	if(remove("Makefile")) {
		perror("remove: previous Makefile");
		exit(1);
	}

	if(rename("copymakefile", "Makefile")) {
		perror("rename: copymakefile -> Makefile");
		exit(1);
	}

}

