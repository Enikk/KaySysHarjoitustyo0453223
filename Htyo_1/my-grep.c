#include <stdio.h>
#include <string.h>

/*http://codetrays.blogspot.com/2015/09/implementation-of-grep-command-in-c.html
Need to change to getline()
*/

int main(int argc, char *argv[])
{
	FILE *fp;
	char fline[350];
	int i;
	
	if(argc<3){
		printf("Syntax error\n");
		return 0;
	} 
	
	for(i=2; i<argc;i++){
		fp=fopen(argv[i], "r");

		while(fscanf(fp, "%[^\n]\n", fline)!=EOF){
			if(strstr(fline, argv[1]) != NULL){
				printf("%s\n", fline);	
			}
			else{
				continue;		
			}

		}
		fclose(fp);
	}

}


