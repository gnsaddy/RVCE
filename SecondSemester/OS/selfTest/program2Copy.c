#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	FILE *fs, *fd;
	int ch;

	if(argc != 3){
		printf("\nfew arguments\n");
		exit(0);
	}

	fs=fopen(argv[1],"r");
	if(fs==NULL){
		printf("\nSource file not found\n");
		return 0;
	}

	fd=fopen(argv[2],"w");
	if(fd==NULL){
		printf("\ndestination file not found\n");
		fclose(fs);
		return 0;
	}

	while((ch=fgetc(fs))!=EOF){
		fputc(ch,fd);
	}

	printf("\nDone\n");
	fclose(fs);
	fclose(fd);
	return 0;

}
