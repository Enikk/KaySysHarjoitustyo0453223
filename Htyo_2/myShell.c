#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void prompt(){
	printf("%s", "wish >");

}

void read(char cmd[], char *par[]) {
	char line[1024];
	int count = 0, i = 0, j = 0;
	char *array[100], *pch;

	for( ;; ) {
		int c =fgetc (stdin);
		line[count++]=(char) c;
		if ( c== "\n")
			break;
	}
	if (count == 1) 
		return;
	pch = strtok (line, " \n");
	
	while(pch != NULL){
		array[i++] = strdup(pch);
		pch = strtok( NULL, " \n");
	}

	strcpy(cmd, array[0]);

	for (j ; j < i; j++)
		par[j] = array[j];
	par[i] = NULL;

}




int main(){
	char cmd[100], cmd2[100], *par[20];
	
	char *envp []  ={(char *) "PATH=/bin", 0};
	while (1) {
		prompt();
		read(cmd2, par);
		if(fork() != 0)
			wait(NULL);
		else{
			strcpy(cmd, "/bin/");		
			strcat(cmd, cmd2);
			execve(cmd, par, envp);		
		}
		if(strcmp(cmd2, "exit") == 0)
			break;
	}
	return 0;
}
