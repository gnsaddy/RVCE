#include<stdio.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
    int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0,test[10];
    float wavg=0,tavg=0,tsum=0,wsum=0;
    printf(" -------Shortest Job First Scheduling ( NP )-------\n");
    printf("\nEnter the No. of processes :");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("\tEnter the burst time of %d process :",i+1);
        scanf(" %d",&bt[i]);
        printf("\tEnter the arrival time of %d process :",i+1);
        scanf(" %d",&at[i]);
    }    
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                swap(&bt[j],&bt[j+1]);
                swap(&at[j],&at[j+1]);
                swap(&p[j],&p[j+1]);
            }
        }
    }
    btime=at[0];
    for(j=0;j<n;j++)
    {
        btime=btime+bt[j];
        min=bt[k];
        for(i=k;i<n;i++)
        {
            if (btime>=at[i] && bt[i]<min)
            {
                swap(&bt[j],&bt[j+1]);
                swap(&at[j],&at[j+1]);
                swap(&p[j],&p[j+1]);
            }
        }
        k++;
    }
    wt[0]=0;
    ta=at[0];   
  
     printf("************************");
    printf("\n RESULT:-");
    printf("\nPID\t BT\t AT\t CT \t WT\t TAT" );
    for(i=0;i<n;i++)
    {
        ta=ta+bt[i];
        tt[i]=ta-at[i];
        wt[i]=tt[i]-bt[i];
        tsum=tsum+tt[i];
        wsum=wsum+wt[i];
        printf("\n p%d\t %d\t %d\t %d\t %d\t %d",p[i],bt[i],at[i],ta,wt[i],tt[i]);
    }    
    tavg=(tsum/n);  
    wavg=(wsum/n);
    printf("\n\nAVERAGE WAITING TIME : %f",wavg);
    printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
    return 0;
}