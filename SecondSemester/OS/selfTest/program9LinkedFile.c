#include<stdio.h>
#include<stdlib.h>
#define max 20

void main(){
	int file[max],index[max],count=0,i,j,k,ind,block,c;

	for(i=0;i<max;i++)
		file[i]=0;
	x:	printf("\nEnter starting index ");
		scanf("%d",&ind);

		if(file[ind] != 1){
			printf("\nEnter needed block and enter the file for index %d on disk ",ind);
			scanf("%d",&block);
			if(block>max){
				printf("\nIndex is full\n");
				exit(0);
			}
		}
		else{
			printf("\n%d index is already allocated ",ind);
			goto x;
		}

	y:	count=0;
		for(i=0;i<block;i++){
			printf("Enter for block %d ",i+1);
			scanf("%d",&index[i]);
			if(file[index[i]]==0)
				count++;
		}

		if(count==block){
			for(j=0;j<block;j++)
				file[index[j]]=1;
			printf("\nAllocated\n");
			printf("\nFile index start >> %d ",ind);
			for(k=0;k<block;k++)
				printf("-->%d ",index[k]);
			printf(">>end");
		}
		else{
			printf("\nfile in the index is already allocated\n");
			goto y;
		}
	printf("\nDo you want more file yes-1 ");
	scanf("%d",&c);
	if(c==1)
		goto x;
	else
		exit(0);
}
