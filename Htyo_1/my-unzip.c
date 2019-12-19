#include <stdio.h>
#include <string.h>

/*c program to conver text file to binary see-programming*/
int main(int argc, char *argv[]){
	FILE *fin, *fout;

	fin=fopen(argv[1], "rb");
	fout=fopen(argv[2], "w");

	char c;
	int count, i;

	while(!feof(fin)){	
		fread(&count, sizeof(int), 1, fin);
		fread(&c, sizeof(char), 1, fin);	
		for(i = 0; i < count; i++){
			fwrite(&c, sizeof(char), 1, fout);	
		}		
	}
		

	fclose(fin);
	fclose(fout);
	return 0;
}
