#include<stdlib.h>
#include<stdio.h>
int n,temp,ct[50],at[50],bt[50],tat[50],wt[50],awt,atat,p[50],it,ch,it2;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert()
{
	int i;
	printf("Enter the Total Number of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
        printf("Enter the Burst time for the process %d  : ",i+1);
		scanf("%d",&bt[i]);
		printf("Enter the Arrival time for the process %d  : ",i+1);
		scanf("%d",&at[i]);		
		p[i]=i+1;
	}
	if(ch==2)
	{
		printf("Enter the idle Time  :  ");
		scanf("%d",&it);
	}
}

void sorting()
{
	int i,j;
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
}

void sjf()
{
	int i,j;
	printf("Process\t\tArrival Time\tBurst Time\t\tTAT\t\tWT\n");
	for(i=0;i<n;i++)
	{
		ct[i]=at[0];
		for(j=0;j<=i;j++)
			ct[i]+=bt[j];
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		if(wt[i]<0)
			wt[i]*=-1;
		atat+=tat[i];
		awt+=wt[i];
		printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],tat[i],wt[i]);
	}
	awt/=n;
	atat/=n;
	printf("Average Waiting time is : %d\n",awt);
	printf("Average Turn Around time is : %d\n",atat);
	
}

void processSort(int r)
{
	int i,j;
	for(i=r;i<n-1;i++)
	{
		for(j=r;j<n-1;j++)
		{
			if((bt[j]>bt[j+1]) && at[j]<=it2)
			{
				swap(&bt[j],&bt[j+1]);
                swap(&at[j],&at[j+1]);
                swap(&p[j],&p[j+1]);
			}
		}
	}
	return;
}

void futurek()
{
	int i,j;
	it2=it;
	printf("Process\t\tArrival Time\tBurst Time\t\tTAT\t\tWT\n");
	for(i=0;i<n;i++)
	{
		processSort(i);
		ct[i]=at[0];
		for(j=0;j<=i;j++)
			ct[i]+=bt[j];
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		it2+=bt[i];
		if(wt[i]<0)
			wt[i]*=-1;
		atat+=tat[i];
		awt+=wt[i];
		printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],tat[i],wt[i]);
		
	}
	awt/=n;
	atat/=n;
	printf("Average Waiting time is : %d\n",awt);
	printf("Average Turn Around time is : %d\n",atat);
}

void main()
{
	while(1)
	{
		printf("\n\nEnter Your Choice...\n1. Shortest Job First\n2. Future Knowledge Algorithm\n3. Exit\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				sorting();
				sjf();
				break;
			case 2:
				insert();
				futurek();
				break;
			case 3:
				exit(0);
			default:
				printf("Enter Correct Choice....\n\n\n");
		}
	}
}