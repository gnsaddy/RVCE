#include<stdio.h>
#include<stdlib.h>
int i, nProcesses, p[10]={1,2,3,4,5,6,7,8,9,10},min,k = 1, btime = 0;
int bt[10], temp, j, at[10], atWithIdle[10], wt[10], tt[10],ct = 0, sum = 0;
int idleTime = 0,p[10];
float wavg = 0, tavg = 0, tsum = 0, wsum = 0;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void take(){
    printf("\nEnter the No. of processes (less than 10) :");
    scanf("%d", &nProcesses);
    for (i = 0; i < nProcesses; i++)
    {
        printf("\tEnter the burst time of %d process :", i + 1);
        scanf(" %d", &bt[i]);
        printf("\tEnter the arrival time of %d process :", i + 1);
        scanf(" %d", &at[i]);
        atWithIdle[i] = at[i];
    }
}
int futureMethod(){
    printf("Input for Future knowledge\n");
    take();
   printf("\nEnter idle time :");
    scanf("%d", &idleTime);
    /*Sort according to Arrival Time*/
    for (i = 0; i < nProcesses; i++)
    {
        if (at[i] < idleTime)
        {
            atWithIdle[i] = idleTime;
        }
    }
    for (i = 0; i < nProcesses; i++)
    {
        for (j = 0; j < nProcesses; j++)
        {
            if (atWithIdle[i] < atWithIdle[j])
            {
                swap(&p[i],&p[j]);
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&atWithIdle[i],&atWithIdle[j]);
            }
            else if ((atWithIdle[i] == atWithIdle[j]) && (bt[i] < bt[j])) // Sort based on burst time for processes with same arrival time
            {
                 swap(&p[i],&p[j]);
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&atWithIdle[i],&atWithIdle[j]);
            }
        }
    }
    // Loops below takes care of sorting the table according to Burst time, Execution time and Arrival Time
    // Arrival time <= Execution time

    // First process execution has to wait till the process arrives in ready queue.
    // This adds to time.
    btime = at[0];
    for (j = 0; j < nProcesses; j++)
    {
        btime = btime + bt[j];
        min = bt[k];
        for (i = k; i < nProcesses; i++)
        {
            if (btime >= atWithIdle[i] && bt[i] < min)
            {
                swap(&p[i],&p[k]);
                swap(&at[i],&at[k]);
                swap(&bt[i],&bt[k]);
                swap(&atWithIdle[i],&atWithIdle[k]);
            }
        }
        k++;
    }
    wt[0] = 0;
    sum = at[0];
    for (i = 1; i < nProcesses; i++)
    {
        sum = sum + bt[i - 1];
        wt[i] = sum - at[i];

        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
        wsum = wsum + wt[i];
    }
    wavg = (wsum / nProcesses);
    ct = at[0];
    printf("************************");
    printf("\n RESULT:-");
    printf("\nPID\t BT\t AT\t CT\t WT\t TAT" ); 
    for(i=0;i<nProcesses;i++)
    {
        ct=ct+bt[i];
        tt[i]=ct-at[i];
        tsum=tsum+tt[i];
         printf("\n p%d\t %d\t %d\t %d\t %d\t %d",p[i],bt[i],at[i],ct,wt[i],tt[i]);
    }    
    tavg=(tsum/nProcesses);  
    
    printf("\n\nAVERAGE WAITING TIME : %f", wavg);
    printf("\nAVERAGE TURN AROUND TIME : %f", tavg);
    return 0;
}
int sjf(){
    
    printf("Input for SJF\n");
    take();    
    /*Sorting According to Arrival Time*/    
    for(i=0;i<nProcesses;i++)
    {
        for(j=0;j<nProcesses;j++)
        {
            if(at[i]<at[j])
            {
                swap(&p[i],&p[j]);
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
            }
        }
    }    
    /*Arranging the table according to Burst time,
    Execution time and Arrival Time
    Arrival time <= Execution time
    */    
    for(j=0;j<nProcesses;j++)
    {
        btime=btime+bt[j];
        min=bt[k];
        for(i=k;i<nProcesses;i++)
        {
            if (btime>=at[i] && bt[i]<min)
            {
                swap(&p[i],&p[k]);
                swap(&at[i],&at[k]);
                swap(&bt[i],&bt[k]);
            }
        }
        k++;
    }
    wt[0]=0;
    for(i=1;i<nProcesses;i++)
    {
        sum=sum+bt[i-1];
        wt[i]=sum-at[i];
        wsum=wsum+wt[i];
    }
    
    wavg=(wsum/nProcesses);
    printf("************************");
    printf("\n RESULT:-");
    printf("\nPID\t BT\t AT\t CT\t WT\t TAT" ); 
    for(i=0;i<nProcesses;i++)
    {
        ct=ct+bt[i];
        tt[i]=ct-at[i];
        tsum=tsum+tt[i];
         printf("\n p%d\t %d\t %d\t %d\t %d\t %d",p[i],bt[i],at[i],ct,wt[i],tt[i]);
    }    
    tavg=(tsum/nProcesses);   
    printf("\n\nAVERAGE WAITING TIME : %f",wavg);
    printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
    return 0;  
}
void main(){
    printf("SJF & Future knowledge \n");
    int ch;
    while(1){
        printf("1-SJF\n2-Future\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                 sjf();
                  break;
            case 2:
                futureMethod();
                break;                
        }
    }
}