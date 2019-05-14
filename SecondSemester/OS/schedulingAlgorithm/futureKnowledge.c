#include<stdio.h>
#include<stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main()
{
    int i, nProcesses, processes[10]={1,2,3,4,5,6,7,8,9,10},min, k = 1, btime = 0;
    int bt[10], temp, j, at[10], atWithIdle[10], wt[10], tt[10], ta = 0, sum = 0;
    int idleTime = 0;
    float wavg = 0, tavg = 0, tsum = 0, wsum = 0;
    printf(" -------Shortest Job First Scheduling ( NP )-------\n");
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
                swap(&processes[i],&processes[k]);
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
    ta = at[0];
    for (i = 0; i < nProcesses; i++)
    {
        ta = ta + bt[i];
        tt[i] = ta - at[i];
        tsum = tsum + tt[i];
    }
    tavg = (tsum / nProcesses);
    printf("************************");
    printf("\n RESULT:-");
    printf("\nProcess\t\t Burst\t\t Arrival\t\t Waiting\t\t Turn-around");
    for (i = 0; i < nProcesses; i++)
    {
        printf("\nProcess %d\t\t %d\t\t %d\t\t %d\t\t\t%d", processes[i], bt[i], at[i], wt[i], tt[i]);
    }
    printf("\n\nAVERAGE WAITING TIME : %f", wavg);
    printf("\nAVERAGE TURN AROUND TIME : %f", tavg);
    return 0;
}