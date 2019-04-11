#include<stdio.h>

void main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp,at[20];
    float avg_wt,avg_tat;
    int tot,min;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("\nEnter the Arrival Time and Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
		scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }

    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

	temp=at[i];
	at[i]=at[pos];
	at[pos]=temp;
    }

    wt[0]=0;


    for(i=1;i<n;i++)
    {
		int k=1;
		for(j=0;j<n;j++)
		{
		 if((at[j]>at[k]) && (bt[j]>bt[k]))
		 {

			 temp=bt[i];
			 bt[i]=bt[pos];
			 bt[pos]=temp;

			 temp=p[i];
			 p[i]=p[pos];
			 p[pos]=temp;

			 temp=at[j+1];
			 at[j+1]=at[j];
			 at[j]=temp;
		 }
		}k++;
    }
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		wt[i]=bt[i-1]+wt[i];
		wt[i]-=at[i];
		total+=wt[i];
	}

    avg_wt=(float)total/n;      //average waiting time
    total=0;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t %d\t\t    %d\t\t\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}