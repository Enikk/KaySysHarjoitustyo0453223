#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* http://cprogrammingwithlinux.blogspot.com/2011/10/c-program-to-simulate-linux-cat-command.html */

int main(int argc, char *argv[]){
	
	FILE *fp;
	char fname[350], ch;	
	int i;

	if(argc < 2){
		printf("There is a syntax problem.\n");
		return 0;
	}
	
	for(i=1; i<argc; i++){
		strncpy(fname, argv[i], 350);
		fp=fopen(fname, "r");
		if(fp == NULL){
			printf("No file found\n");
			return 0;
		}
		while((ch=fgetc(fp)) != EOF){
			putchar(ch);
		}
		fclose(fp);
	}
	return 0;
}
