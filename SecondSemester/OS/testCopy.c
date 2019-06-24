#include <stdio.h> 
#include <stdlib.h> // For exit() 

int main(int argc,char *argv[]){
    
    FILE *fs,*ft;
    int ch;
    if(argc!=3)
    {
        printf("Invalid numbers of arguments.");
        return 1;
        }

        fs=fopen(argv[1],"r");
        if(fs==NULL)
        {
            printf("Can't find the source file.");
            return 1;
            }

        ft=fopen(argv[2],"w");
        if(ft==NULL)
            {
                printf("Can't open target file.");
                fclose(fs);
                return 1;
                }
        while((ch = fgetc(fs)) != EOF)
        {
            fputc(ch,ft);
            }

            printf("File copied successufly\n");

            fclose(fs);
            fclose(ft);
            return 0;
}
