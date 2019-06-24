#include<stdio.h>
#include<stdlib.h>

int main(){
	int msize,osmemory,blocksize,block,pm[10],pcount,p=0,tif=0,extf,i;
	printf("\nEnter the memory size : ");
	scanf("%d",&msize);
	printf("\nEnter os memeory : ");
	scanf("%d",&osmemory);
	msize -= osmemory;
	printf("\nEnter block size : ");
	scanf("%d",&blocksize);

	block = msize/blocksize;
	extf = msize-(block*blocksize);

	printf("\nEnter number of process : ");
	scanf("%d",&pcount);

	for(i=0;i<pcount;i++){
		printf("\nenter process memory for process %d :",i+1);
		scanf("%d",&pm[i]);
	}

	printf("\nNumber of blocks are %d ", block);
	printf("\nProcess\t\tMemory\t\tAllocated\t\tInternal Fragmentation \n");
	for(i=0;i<pcount;i++){
		printf("\np[%d]\t\t%d",i+1,pm[i]);

		if(pm[i]>blocksize){
			printf("\t\tNO\t\t---------");
		}
		else{
			printf("\t\tYes\t\t%d\n",blocksize-pm[i]);
			tif += blocksize-pm[i];
			p++;
		}
	}
	if(i<pcount){
		printf("\nMemory full\n");
	}
	printf("\nTIF %d ",tif);
	printf("\nExternal frag %d ",extf);
}

