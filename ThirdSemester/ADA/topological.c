#include<stdio.h>
#include<stdlib.h>

void main(){
	int i,j,k,n,ar[20][20],indeg[20],flag[20],count=0;

	printf("\nEnter the number of vertices :- ");
	scanf("%d",&n);

	printf("Enter elements in adjacency matrix :- \n");
	for(i=0;i<n;i++){
		printf("\nEnter for %d row : ",i+1);
		for(j=0;j<n;j++){
			scanf("%d",&ar[i][j]);

			if(i==j){
				if(ar[i][j] != 0){
					printf("\nMatrix contain loop \n");
					exit(0);
				}
			}
		}
	}

	for(i=0;i<n;i++){
		indeg[i]=0;
		flag[i]=0;
		for(j=0;j<n;j++){
			if(i != j && ar[i][j]==ar[j][i] && ar[i][j] == 1){
				printf("\nMatrix contain loop \n");
				exit(0);
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			indeg[i] = indeg[i]+ar[j][i];
		}
	}

	while(count<n){
		for(k=0;k<n;k++){
			if(indeg[k]==0 && flag[k]==0){
				printf("%d ",k+1);
				flag[k]=1;
			}
			for(i=0;i<n;i++){
				if(ar[i][k] == 1)
					indeg[k]--;
			}
		}

		count++;
	}
}