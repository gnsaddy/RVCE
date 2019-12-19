#include<stdio.h>
#include<sys/file.h>
#include<string.h>
#include<sys/time.h>
char str[500],pat[10];
FILE *f1;
int m,n;
int string_pattern()
{
        int i,j;

        m = strlen(pat);

        for(i=0;i<=(n-m);i++)
        {
                j=0;
                while(j<m && pat[j]==str[i+j])
                {
                        j++;
                        if(j==m)
                           return i;
                }
        }
        return -1;
}
void main()
{

        int pos,iter,k;
        float t1,t2;
        struct timeval begin,end;
        f1 = fopen("patternfile2.txt","w");
        printf("\nString pattern matching\n");
        printf("\nEnter string : \n");
        gets(str);
for(k=1;k<=5;k++){
        n = strlen(str);
        printf("\nEnter pattern for best case : ");
        gets(pat);

        gettimeofday(&begin,0);
        pos = string_pattern();
        gettimeofday(&end,0);
	t1 = (end.tv_usec-begin.tv_usec);

        printf("\nEnter pattern for worst case : ");
        gets(pat);

        gettimeofday(&begin,0);
        pos = string_pattern();
        gettimeofday(&end,0);

        t2 = (end.tv_usec-begin.tv_usec);
        printf("\nTime taken by the algorithm is %fms and %fms\n",t1,t2);
        fprintf(f1,"\n%d \t %1.2f \t %1.2f",n,t1,t2);

        }
        fclose(f1);
}
