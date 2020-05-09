#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[30],count=0;

int place(int pos){
	int i;
	for(i=1;i<pos;i++){
		if((a[i]==a[pos]) || (abs(a[i]-a[pos]) == abs(i-pos)))
			return 0;
		}
	return 1;
}


void print(int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(a[i]==j)
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}printf("\n");
	if (n > 2)
		exit(0);
	
}


void queen(int n){
	int k=1;
	a[k]=0;

	while(k!=0){
		a[k] = a[k]+1;
		while((a[k]<=n) && !place(k))
			a[k]++;

		if(a[k]<=n){
			if(k==n)
				print(n);
			else{
				k++;
				a[k]=0;
			}
		}
		else
			k--;
	}
	if (n==1)
		printf("Trivial Solution");
	if(n==2 || n==3)
		printf("No solution");
	
}

void main(){
	int n;
	scanf("%d",&n);
	queen(n);
	
}



