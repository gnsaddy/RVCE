#include<stdio.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int sjf()
{
    int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
    int bt[10],temp,j,at[10],wt[10],tt[10],ct=0;
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
                swap(&p[i],&p[k]);  // swap process id
                swap(&at[i],&at[k]);  //swap arrival time
                swap(&bt[i],&bt[k]);  // swap burst time
            }
        }
        k++;
    }
    wt[0]=0;
    ct=at[0];
    printf("\nPID\t AT\t BT\t CT \t WT\t TAT" );
    for(i=0;i<n;i++)
    {
        ct=ct+bt[i];
        tt[i]=ct-at[i];
        wt[i]=tt[i]-bt[i];
        tsum=tsum+tt[i];
        wsum=wsum+wt[i];
        printf("\n p%d\t %d\t %d\t %d\t %d\t %d",p[i],at[i],bt[i],ct,wt[i],tt[i]);
    }    
    tavg=(tsum/n);  
    wavg=(wsum/n);
    printf("\n\nAVERAGE WAITING TIME : %f",wavg);
    printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
    return 0;
}

int future()
{
    int i, nProcesses, processes[10]={1,2,3,4,5,6,7,8,9,10},min, k = 1, btime = 0;
    int bt[10], temp, j, at[10], atWithIdle[10], wt[10], tt[10], ta = 0, sum = 0;
    int ct=0;
    int idleTime = 0;
    float wavg = 0, tavg = 0, tsum = 0, wsum = 0;
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
                swap(&processes[i],&processes[j]);
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&atWithIdle[i],&atWithIdle[j]);
            }
            else if ((atWithIdle[i] == atWithIdle[j]) && (bt[i] < bt[j])) // Sort based on burst time for processes with same arrival time
            {
                swap(&processes[i],&processes[j]);
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&atWithIdle[i],&atWithIdle[j]);
            }
        }
    }
    btime = at[0];
    for (j = 0; j < nProcesses; j++)
    {
        btime = btime + bt[j];
        min = bt[k];
        for (i = k; i < nProcesses; i++)
        {
            if (btime >= atWithIdle[i] && bt[i] < min)
            {
                swap(&processes[i],&processes[k]);
                swap(&at[i],&at[k]);
                swap(&bt[i],&bt[k]);
                swap(&atWithIdle[i],&atWithIdle[k]);
            }
        }
        k++;
    }   
    wt[0]=0;
    ct = atWithIdle[0];    
     printf("\nPid \t AT \t BT \t CT \t WT \t TAT");
    for(i=0;i<nProcesses;i++)
    {
        ct=ct+bt[i];
        tt[i]=ct-at[i];
        wt[i] = tt[i]-bt[i];
        tsum=tsum+tt[i];
        wsum=wsum+wt[i];
        printf("\n p%d\t %d\t %d\t %d \t %d\t %d",processes[i],at[i],bt[i],ct,wt[i],tt[i]);
    }    
    tavg=(tsum/nProcesses); 
    wavg = (wsum / nProcesses);     
    printf("\n\nAVERAGE WAITING TIME : %f", wavg);
    printf("\nAVERAGE TURN AROUND TIME : %f", tavg);
    return 0;
}

void main(){
    int ch;
    printf("SJF & Future knowledge \n");
    while(1){
        printf("\n1-SJF\n2-Future\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                 sjf();
                  break;
            case 2:
                future();
                break;                
        }
    }
}