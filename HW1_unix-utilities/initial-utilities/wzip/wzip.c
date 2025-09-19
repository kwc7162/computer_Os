#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	
	if(argc < 2) {
	        printf("wzip: file1 [file2 ...]\n");
		exit(1);
	}

	int count = 0;
	char data;
	char buffer;


	for(int i = 1; i < argc; i++){
		FILE *fp = fopen(argv[i], "r");

		if(fp == NULL){
			printf("wzip: cannot open file\n");
			exit(1);
		}
		while(fread(&buffer, 1, 1, fp) == 1){
			if(count == 0){
				data = buffer;
				count = 1;
			}
			else if(buffer == data){
				count++;
			}
			else{
				fwrite(&count, 4, 1, stdout);
				fwrite(&data, 1, 1, stdout);

				data = buffer;
				count = 1;
			}

		}
		fclose(fp);
	}

	if(count > 0){
		fwrite(&count, 4, 1, stdout);
		fwrite(&data, 1, 1, stdout);
	}

	return 0;

} 
