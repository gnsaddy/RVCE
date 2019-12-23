#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,j,k,n,a[20][20],indeg[20],flag[20],count=0;

	printf("\nEnter the number of vertices : ");
	scanf("%d",&n);

	printf("\nEnter value for adjacency matrix \n");
	for(i=0;i<n;i++){
		printf("\nValue for row %d : ",i+1);
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);

			//diagonals should be 0 always to ensure there are no loops
			if(i==j)
			{
				if(a[i][j]!=0)
				{
					printf("\nThe matrix as loops! Enter acylic graph matrix\n");
					exit(0);
				}
			}
		}
	}


	//check if cyclic graph
 	for(i=0;i<n;i++)
	{
 		for(j=0;j<n;j++)
		{
			if(a[i][j]==a[j][i])
			{
				printf("\nThe graph has loops! Enter acylic graph matrix\n");
				exit(0);
			}
		}
	}


	for(i=0;i<n;i++){
		indeg[i]=0;
		flag[i]=0;
	}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			indeg[i]=indeg[i]+a[j][i];


	while(count<n){
		for(k=0;k<n;k++){
			if((indeg[k]==0) && flag[k]==0){
				k=k+1;
				printf("%d - ",k+1);
				flag[k]=1;
			}

			for(i=0;i<n;i++){
				if(a[i][k]==1)
					indeg[k]--;
			}
		}
		count++;
	}

return 0;
}