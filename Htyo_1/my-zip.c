#include <stdio.h>
#include <string.h>

/*
Tekijä Eetu Nikkilä 0453223
Lähde: c program to conver text file to binary see-programming lähdelistalta

*/
int main(int argc, char *argv[]){
	
	FILE *fin, *fout;
	int count;
	char c1, c2;
	fin=fopen(argv[1], "r");			//tiedostot
	fout=fopen(argv[2], "wb");
	fread(&c1, sizeof(char), 1, fin);	
	
	while(!feof(fin)){
		count=0;		
		do{			
			fread(&c2, sizeof(char), 1, fin);	//rle pyöritys
			count++;
		}while(c1 == c2 && c2 != EOF && count < 255);
	
		fwrite(&count, sizeof(int), 1, fout);		//tiedostoon kirjoitus
		fwrite(&c1, sizeof(char), 1, fout);
		c1 = c2; 
	}	

	fclose(fin);
	fclose(fout);
	return 0;
}
