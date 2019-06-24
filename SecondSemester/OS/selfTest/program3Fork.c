#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int n1=0,n2=1,sum,count=0,num;
	pid_t pid = fork();

	if(pid==0){
		printf("\nChild created \n");
		printf("\nEnter number to find fibonacci series : ");
		scanf("%d",&num);
		printf("\n%d",n1);
		printf("\n%d",n2);
		count = 2;
		while(count<num){
			sum=n1+n2;
			count++;
			printf("\n%d",sum);
			n1=n2;
			n2=sum;
		}
		printf("\nchild operation done\n child exit \n");
		exit;
	}
	else{
		printf("\nChild not created \n parent is waiting for child\n");
		waitpid(pid,NULL,0);
		printf("\nparent ends its proces\n");
	}
	return 0;
}


