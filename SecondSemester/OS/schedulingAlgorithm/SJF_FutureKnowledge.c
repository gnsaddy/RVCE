#include<stdio.h>
#include<stdlib.h>
int i, nProcesses, p[10]={1,2,3,4,5,6,7,8,9,10},min,k = 1, btime = 0;
int bt[10], temp, j, at[10], atWithIdle[10], wt[10], tt[10],ct = 0, sum = 0;
int idleTime = 0;
float wavg = 0, tavg = 0, tsum = 0, wsum = 0;

void swap(int *xp, int *yp)  // used for swapping 
{
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void take(){   // used to take input from user
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
void res(){   // result calculation
    wt[0] = 0;
    sum = at[0];  // take var sum and assign the first index vale of arrival time,this helps to put process into ready queue
    for (i = 1; i < nProcesses; i++)
    {
        sum=sum+bt[i-1];
        wt[i]=sum-at[i];  // calculating waiting time 
        wsum=wsum+wt[i];
    }
    ct = at[0];   // set completion time equals to first index vaue of arrival time
    printf("************************");
    printf("\n RESULT:-");
    printf("\nPID\t BT\t AT\t CT\t WT\t TAT" ); 
    for(i=0;i<nProcesses;i++)
    {
        ct=ct+bt[i];  // calculating completion time
        tt[i]=ct-at[i];  // calculating turn around time
        tsum=tsum+tt[i];
         printf("\n p%d\t %d\t %d\t %d\t %d\t %d",p[i],bt[i],at[i],ct,wt[i],tt[i]);
    }    
    tavg=(tsum/nProcesses); 
    wavg = (wsum / nProcesses); 
    
    printf("\n\nAVERAGE WAITING TIME : %f", wavg);
    printf("\nAVERAGE TURN AROUND TIME : %f", tavg);
}

int futureMethod(){
    printf("Input for Future knowledge\n");
    take();  // input method envoked
    printf("\nEnter idle time :");
    scanf("%d", &idleTime);
    /*Sort according to Arrival Time*/
    for (i = 0; i < nProcesses; i++)
    {
        if (at[i] < idleTime)  //check for arrival time is less than idle time if yes assign arrivalWithIdle time equals user idle time
        {
            atWithIdle[i] = idleTime;
        }
    }
    for (i = 0; i < nProcesses; i++)
    {
        for (j = 0; j < nProcesses; j++)
        {
            if (atWithIdle[i] < atWithIdle[j])  // comparing the arrivalWithIdle time
            {
                swap(&p[i],&p[j]);   // swap process id
                swap(&at[i],&at[j]); //swap arrival time
                swap(&bt[i],&bt[j]); // swap burst time
                swap(&atWithIdle[i],&atWithIdle[j]);  // also swap atWithIdle time if (atWithIdle[i] < atWithIdle[j]) true
            }
            else if ((atWithIdle[i] == atWithIdle[j]) && (bt[i] < bt[j])) // Sort based on burst time for processes with same arrival time
            {
                swap(&p[i],&p[j]);  // swap process id
                swap(&at[i],&at[j]); //swap arrival time
                swap(&bt[i],&bt[j]); // swap burst time
                swap(&atWithIdle[i],&atWithIdle[j]);  // swap atWithIdle time
            }
        }
    }
    // Loops below takes care of sorting the table according to Burst time, Execution time and Arrival Time
    // Arrival time <= Execution time
    // First process execution has to wait till the process arrives in ready queue.
    // This adds to time.
    btime = at[0];  // take var btime and assign the first index vale of arrival time
    for (j = 0; j < nProcesses; j++)
    {
        btime = btime + bt[j];
        min = bt[k];
        for (i = k; i < nProcesses; i++)
        {
            if (btime >= atWithIdle[i] && bt[i] < min)
            {
                swap(&p[i],&p[k]);  // swap process id
                swap(&at[i],&at[k]);  //swap arrival time
                swap(&bt[i],&bt[k]);  // swap burst time
                swap(&atWithIdle[i],&atWithIdle[k]);  // swap atWithIdle time
            }
        }
        k++;
    }    
    res();  // calling result function    
    return 0;
}
int sjf(){
    
    printf("Input for SJF\n");
    take();    // take method envoked
    /*Sorting According to Arrival Time*/    
    for(i=0;i<nProcesses;i++)
    {
        for(j=0;j<nProcesses;j++)
        {
            if(at[i]<at[j])
            {
                swap(&p[i],&p[j]);  // swap process id
                swap(&at[i],&at[j]); // swap arrival time
                swap(&bt[i],&bt[j]); // swap burst time
            }
        }
    }    
    /*Arranging the table according to Burst time,
    Execution time and Arrival Time
    Arrival time <= Execution time
    */    
    btime = at[0];  // take var btime and assign the first index vale of arrival time
    for(j=0;j<nProcesses;j++)
    {
        btime=btime+bt[j];
        min=bt[k];
        for(i=k;i<nProcesses;i++)
        {
            if (btime>=at[i] && bt[i]<min)
            {
                swap(&p[i],&p[k]);  // swap process id
                swap(&at[i],&at[k]); // swap arrival time
                swap(&bt[i],&bt[k]); // swap burst time
            }
        }
        k++;
    }
    res();  //calling result function
    return 0;  
}

void main(){
    printf("SJF & Future knowledge \n");
    int ch;
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
                futureMethod();
                break;                
        }
    }
}