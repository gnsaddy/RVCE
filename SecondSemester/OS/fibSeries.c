#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int n1=0,n2=1,sum,num,count=0;
    pid_t pid = fork();
    if(pid==0){
        printf("\n child create sucessfully\n");
        printf("\nchild will give fib series\n");
        printf("\nEnter number to find series\n");
        scanf("%d",&num);
        printf("%d\n",n1);
        printf("%d\n",n2);
        count=2;
        while(count < num){
            sum=n1+n2;
            count++;
            printf("%d\n",sum);
            n1=n2;
            n2=sum;
        }
        printf("\nchild ended\n");
        exit;
    }
    else
    {
        printf("\nparent is waiting for a child\n");
        waitpid(pid,NULL,0);
        printf("\nParent end\n");
    }
    return 0;
    
}