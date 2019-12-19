#include <stdio.h>
#include <string.h>

/*
Tekijä Eetu nikkilä 0453223
lähdelistalta lähteenä: c program to conver text file to binary see-programming
*/
int main(int argc, char *argv[]){
	FILE *fin, *fout;

	fin=fopen(argv[1], "rb");	//tiedostot
	fout=fopen(argv[2], "w");

	char c;
	int count, i;

	while(!feof(fin)){	
		fread(&count, sizeof(int), 1, fin);	//koodin rle purkaminen
		fread(&c, sizeof(char), 1, fin);	
		for(i = 0; i < count; i++){
			fwrite(&c, sizeof(char), 1, fout);	//tiedostoon kirjoitus
		}		
	}
		

	fclose(fin);
	fclose(fout);
	return 0;
}
