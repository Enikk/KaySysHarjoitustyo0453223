#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*lähde: http://cprogrammingwithlinux.blogspot.com/2011/10/c-program-to-simulate-linux-cat-command.html */

int main(int argc, char *argv[]){
	
	FILE *file;
	char fname[350], ch;	
	int i;

	if(argc < 2){ //tarkistaa syntaxin
		printf("There is a syntax problem. 'Cat File File2 etc'\n");
		return 0;
	}
	
	for(i=1; i<argc; i++){	//käy läpi annetun tiedoston
		strncpy(fname, argv[i], 350);
		file=fopen(fname, "r");
		if(file == NULL){
			printf("No file found\n");	
			return 0;
		}
		while((ch=fgetc(file)) != EOF){
			putchar(ch);	//kirjoittaa tiedoston sisällön
		}
		fclose(file);
	}
	return 0;
}
