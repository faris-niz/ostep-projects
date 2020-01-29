//Faris Awad
//915779032
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {//argc is the number of args
//( for example wcat wcat.c: argc = 2)
//argv is the list of arguments starting with wcat
char c;
FILE* file;
for (int i=1;i<argc;i++){//to print all the files
	file = fopen(argv[i], "r");
	if (file == NULL){
		printf("cannot open file\n");
		exit(1);
	}
	c = fgetc(file);
	while (c != EOF){
		printf("%c",c);
		c = fgetc(file);
	}
	fclose(file);
	}
return 0;
}
