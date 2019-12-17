/*How to write a tiny shell in C*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define EXITCMD "exit"

int main(void) {
	for (;;) {
	        char input[256] = { 0x0 };
	        char *ptr = input;
	        char *args[60] = { NULL };
	
	        printf("wish >");
	        fgets(input, 256, stdin);

        	// ignore empty input
        	if (*ptr == '\n') continue;

        	// convert input line to list of arguments
        	for (int i = 0; i < sizeof(args) && *ptr; ptr++) {
        	    if (*ptr == ' ') continue;
        	    if (*ptr == '\n') break;
        	    for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
        	    *ptr = '\0';
        	}

        	// built-in: exit
        	if (strcmp(EXITCMD, args[0]) == 0) return 0;

        	if (fork() == 0) exit(execvp(args[0], args));
		wait(NULL);
	}
}
