#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	

	if(argc < 2){
		printf("wunzip: file1 [file2 ...]\n");
		exit(1);
	}

	int count;
	char data;
	
	for(int i = 1; i < argc; i++){
		FILE *fp = fopen(argv[i], "rb");
		if(fp == NULL){
			printf("wunzip: cannot open file\n");
			exit(1);
		}

		while(fread(&count, 4, 1, fp) == 1 && fread(&data, 1, 1, fp) == 1){
			for(int j = 0; j < count; j++){
				printf("%c",data);
			}
		}

		fclose(fp);
	}
				
	return 0;

}
