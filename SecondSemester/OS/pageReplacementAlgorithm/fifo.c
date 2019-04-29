#include<stdio.h>
void main()
{
    int i, j, k, frame, pageFault=0, count=0, refStr[25], m[10], strLength;
    printf("\n Enter the length of reference string -- ");
    scanf("%d",&strLength);
    printf("\n Enter the reference string \n ");
    for(i=0;i<strLength;i++){
        printf("%d -->",i+1);
        scanf("%d",&refStr[i]);
    }
    printf("\n Enter no. of frames -- ");
    scanf("%d",&frame);
    for(i=0;i<frame;i++)
        m[i]=-1;
    printf("\n The Page Replacement Process is -- \n");
    for(i=0;i<strLength;i++){
        for(k=0;k<frame;k++){
            if(m[k]==refStr[i])
                break;
        }
        if(k==frame){
            m[count++]=refStr[i];
            pageFault++;
        }
        for(j=0;j<frame;j++)
            printf("\t%d",m[j]);
        if(k==frame)
        printf("\tPF No. %d",pageFault);
        printf("\n");
        if(count==frame)
            count=0;
    }
    printf("\n The number of Page Faults using FIFO are %d",pageFault);
}