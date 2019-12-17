/*stackoverflow writing simpleshell in C using fork/execvp*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){

	int i=0;
	int argc;
	char line[1024];
	char* argv[100];
	char *token;
	char* bpath = "/bin/";
	char ppath[20];

	do{
		printf("wish> ");
		if(!fgets(line, 1024, stdin))
			break;		
	
		size_t lenght = strlen(line);
		if (line[lenght - 1]=='\n')
			line[lenght - 1] ='\0';
		if(strcmp(line, "exit")==0)
			break;
		
		token = strtok(line, " ");
		while (token!=NULL){
			argv[i]=token;
			token = strtok(NULL, " ");
			i++;
		}
		argv[i]=NULL;

		argc=i;
		for(i=0; i<argc; i++){
			printf("%s\n",argv[i]);		
		}
		strcpy(ppath, bpath);
		strcat(ppath, argv[0]);

		for(i=0; i < strlen(ppath); i++){
			if(ppath[i]=='\n')
				ppath[i]='\0';
		}

		int pid= fork();
		if(pid==0){
			execvp(ppath, argv);
			fprintf(stderr, "Could not do execvp\n");
			
		}else{
			wait(NULL);
			printf("exited child\n");		
		}		
		
	}while(1);


	return EXIT_SUCCESS;

}
