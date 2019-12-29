#include<stdio.h>
#include<stdlib.h>

void main(){
	int i,j,k,n,ar[10][10],indeg[10],flag[10];
	int count=0;
	printf("\nEnter the number of vertices :- ");
	scanf("%d",&n);
	
	printf("\nEnter the elements in adjacency matrix :-\n");
	for(i=0;i<n;i++){
		printf("\nEnter for row %d : ",i+1);
		for(j=0;j<n;j++){
			scanf("%d",&ar[i][j]);
			
			if(i == j){
				if(ar[i][j] != 0){
					printf("\nMatrix has loop!");
					exit(0);
				}
			}
		}
	}
	
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i != j && ar[i][j]==ar[j][i] && ar[i][j] == 1){
				printf("\nMatrix has loop!");
				exit(0);
			}
		}
	}
	
	for(i=0;i<n;i++){
		indeg[i]=0;
		flag[i]=0;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			indeg[i]=indeg[i]+ar[j][i];
		}
	}
	
	while (count < n)
        {

                for (i = 0; i < n; i++)
                {
                        if (indeg[i] == 0 && flag[i] == 0)
                        {
                                printf("%d -> ", i + 1);
                                flag[i] = 1;
                                for (j = 0; j < n; j++)
                                        if (ar[i][j] == 1)
                                        {
                                                indeg[j]--;
                                        }
                        }
                }
                count++;
        }
        printf("\n");
	
}
	
	