#include<stdio.h>
#include<stdlib.h>
#define max 20
void main()
{
    int f[max], index[max],i, n, j, c, k, ind,count=0;
    for(i=0;i<max;i++){
        f[i]=0;
    }
    x:printf("Enter the starting block: ");
    scanf("%d",&ind);
    if(f[ind]!=1)
    {
        printf("Enter no of blocks needed ");
        printf("and also enter the files for the index %d on the disk : \n", ind);
        scanf("%d",&n);
        if(n>=max){
            printf("\n index is full \n");  
            exit(0);           
        }
    }
    else
    {
        printf("\n%d index is already allocated \n",ind);
        goto x;
    }
    y: count=0;
    for(i=0;i<n;i++)
    {   printf("Enter for block %d : ",i+1);
        scanf("%d", &index[i]);
        if(f[index[i]]==0)
        count++;
    }
    if(count==n)
    {
        for(j=0;j<n;j++)
            f[index[j]]=1;
        printf("Allocated\n");
        printf("File Indexed\n");
        printf("\nstart >> %d ",ind);
        for(k=0;k<n;k++)            
            printf("-->%d ",index[k]);
        printf(">>end");
    }
    else
    {
        printf("\nFile in the index is already allocated \n");                      
        printf("\nEnter another file indexed\n");
        goto y;
    }
    printf("\nDo you want to enter more file(Yes - 1/No - 0)");
    scanf("%d", &c);
    if(c==1)
        goto x;
    else
        exit(0);
}