#include <stdio.h>
#include <string.h>

#define BUFFER_MAX 5120
/*
Tekijä: Eetu Nikkilä 0453223
Lähteenä 
http://codetrays.blogspot.com/2015/09/implementation-of-grep-command-in-c.html

*/

int main(int argc, char *argv[])
{
	FILE *file;
	char fline[BUFFER_MAX];
	int i;
	
	if(argc<3){		//tarkistaa argumenttien määrä
		printf("Syntax error\n");
		return 0;
	} 
	
	for(i=2; i<argc;i++){	//tiedostot for loopissa mikäli enemmän kuin 1
		file=fopen(argv[i], "r");
		
		//hakee rivit tiedostosta
		while(fscanf(file, "%[^\n]\n", fline)!=EOF){
			
			//printtaa rivit joissa löytyy haku
			if(strstr(fline, argv[1]) != NULL){
				printf("%s\n", fline);	
			}

		}
		fclose(file);
	}

}


