//Faris Awad
//915779032
//Wgreb program
//A program that is passed a search term and one or more files then prints each line with the search term
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
	FILE *file;
	if (argc<2){//means no search term is passes
	printf("wgreb: searchterm file\n");
	exit(1);
	}
	for (int i=2;i<argc;i++){
		file = fopen(argv[i],"r");
		if (file == NULL){
			printf("cannot open file\n");
			exit(1);
		}
		char line[100];
		int found;//1 means found and 0 otherwise
		while (fgets(line, 100, file) != NULL){//line now contains the line string
		found = 0;
		for (int j=0;j<strlen(line);j++){
			if(line[j]==argv[1][0]){//if the first letter match we compare with the rest of the string
			found = 1;
			for (int k=1;k<strlen(argv[1]);k++){//to compare the rest of the string
			if(argv[1][k]!=line[j+k]){//if one letter doesn't match
				k=strlen(argv[1]);//to exit the loop
				found = 0;//if one letter doesn't match then it is not found
			}
			}
			}
		}
		if(found==1){//if search term is found
			printf("%s",line);
		}
		}
		fclose(file);
	}
	return 0;
}

