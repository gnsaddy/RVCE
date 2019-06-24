#include<stdio.h>
#include<stdlib.h>
int i, nProcesses, p[10]={1,2,3,4,5,6,7,8,9,10},min,k = 1, btime = 0;
int bt[10], temp, j, at[10], atWithIdle[10], wt[10], tt[10], sum = 0;
int idleTime = 0,ch=0,ct=0;
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

void pSwap(){
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
                if(ch==2)
                swap(&atWithIdle[i],&atWithIdle[k]);  // swap atWithIdle time
            }
        }
        k++;
    }    
}
void result(){
    
    if (ch==1)
        ct = at[0];
    if (ch == 2)
        ct = atWithIdle[0];
    wt[0]=0;
    printf("\nPid \t AT \t BT \t CT \t WT \t TAT");
    for(i=0;i<nProcesses;i++)
    {
        ct=ct+bt[i];
        tt[i]=ct-at[i];
        wt[i] = tt[i]-bt[i];
        tsum=tsum+tt[i];
        wsum=wsum+wt[i];
        printf("\n p%d\t %d\t %d\t %d \t %d\t %d",p[i],at[i],bt[i],ct,wt[i],tt[i]);
    }    
    tavg=(tsum/nProcesses); 
    wavg = (wsum / nProcesses);     
    printf("\n\nAVERAGE WAITING TIME : %f", wavg);
    printf("\nAVERAGE TURN AROUND TIME : %f", tavg);
}
void futureMethod(){
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
   pSwap();
   result();
}
void sjf(){
    
    printf("Input for SJF\n");
    take();    // take method envoked
    /*Sorting According to Arrival Time*/    
     for(i=1;i<nProcesses-1;i++)
    {
        for(j=1;j<nProcesses-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                swap(&bt[j],&bt[j+1]);
                swap(&at[j],&at[j+1]);
                swap(&p[j],&p[j+1]);
            }
        }
    }
    pSwap();
    result();
    
}
void main(){
    printf("SJF & Future knowledge \n");
    while(1){
        printf("\n1-SJF\n2-Future\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                sjf();
                exit(0);
            case 2:
                futureMethod();
                exit(0);     
        }
    }
}