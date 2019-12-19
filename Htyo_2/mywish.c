/*lähdelistalta How to write a tiny shell in C*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define EXITCMD "exit"

int main(void) {
	for (;;) {
	        char in[256] = { 0x0 };	//alustaa komentolistan
	        char *ptr = in;		//pointteri nykyiseen kohtaan
	        char *args[99] = { NULL };	//alustaa argumentti listan
	
	        printf("wish >");	//kirjoittaa promptin
	        fgets(in, 256, stdin);	//ootta inputin

        	
        	if (*ptr == '\n') 
			continue;	//ohittaa tyhjän inputin

        	//muuttaa inputin argumentti listaksi
        	for (int i = 0; i < sizeof(args) && *ptr; ptr++) {
        	    if (*ptr == ' ') continue;
        	    if (*ptr == '\n') break;//kunnes rivinvaihto katkaisee
        	    for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
        	    *ptr = '\0'; 
        	}

        	
        	if (strcmp(EXITCMD, args[0]) == 0) return 0;//jos input on exit sulkee shellin

        	if (fork() == 0) exit(execvp(args[0], args));	//ajaa annetun komennon ja varmistaa päättymisen
		wait(NULL);
	}
}
