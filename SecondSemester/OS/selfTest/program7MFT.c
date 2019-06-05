#include<stdio.h>
#include<stdlib.h>

void main(){
    int memorySize,blockSize,numberOfBlock,extFrag,tif=0,processMemory[10],processCount,i,p=0,osmemory;
    printf("\nEnter total memory size\t");
    scanf("%d",&memorySize);

    printf("\nEnter memory allocated by operating system\t");
    scanf("%d",&osmemory);

    memorySize = memorySize - osmemory;  // change the memory size

    printf("\nEnter the block size\t");
    scanf("%d",&blockSize);

    numberOfBlock = memorySize/blockSize;
    extFrag = memorySize - numberOfBlock*blockSize;

    printf("\nEnter number of processes\t");
    scanf("%d",&processCount);

    for ( i = 0; i < processCount; i++)
    {
        printf("\nEnter memory required for process %d : ",i+1);
        scanf("%d",&processMemory[i]);
    }

    printf("\nNumber of block available in memory %d\t",numberOfBlock);


    printf("\nProcess\tRequiredMemory\tAllocated\tInternal fragmentation\t");
    for(i=0;i<processCount && p<numberOfBlock;i++){
        printf("\n%d\t\t%d",i+1,processMemory[i]);

        if(processMemory[i]>blockSize){
            printf("\t\tNO\t\t");
        }
        else
        {
            printf("\t\tYes\t\t%d",blockSize-processMemory[i]);
            tif = tif + blockSize-processMemory[i];
            p++;
        }
    }
    if(i<processCount){
        printf("\nMemory is full, process can not be accomodated\n");
    }
    printf("\nTotal Internal fragmentation %d\t",tif);
    printf("\nTotal Externam fragmentation %d\t",extFrag);


}