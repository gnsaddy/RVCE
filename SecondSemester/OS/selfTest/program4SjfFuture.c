#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void sjf(){
	int n,p[10]={1,2,3,4,5,6,7,8,9,10},bt[10],at[10],tat[10],wt[10],ct=0;
	int i,j,k=1,btime=0,min;
	float awt=0,atat=0,wsum=0,tsum=0;

	printf("\nEnter the number of process : ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("\nEnter bt for process %d: ",i+1);
		scanf("%d",&bt[i]);
		printf("\nEnter at for process %d: ",i+1);
		scanf("%d",&at[i]);
	}

	for(i=1;i<n-1;i++){
		for(j=1;j<n-1;j++){
			if(bt[j]>bt[j+1]){
				swap(&bt[j],&bt[j+1]);
				swap(&at[j],&at[j+1]);
				swap(&p[j],&p[j+1]);
			}
		}
	}

	btime=at[0];
	for(j=0;j<n;j++){
		btime=btime+bt[i];
		min=bt[k];
		for(i=k;i<n;i++){
			if(btime>=at[i] && bt[i]<min){
				swap(&bt[j],&bt[j+1]);
                                swap(&at[j],&at[j+1]);
                                swap(&p[j],&p[j+1]);
			}
		}
		k++;
	}

	ct=at[0];
	wt[0]=0;

	printf("\npid \t at \t bt \t ct \t tat \t wt\n");
	for(i=0;i<n;i++){
		ct=ct+bt[i];
		tat[i]=ct-at[i];
		wt[i]=tat[i]-bt[i];
		tsum += tat[i];
		wsum += wt[i];
		printf("\np[%d] \t %d \t %d \t %d \t %d \t %d \n",p[i],at[i],bt[i],ct,tat[i],wt[i]);
	}
	atat=tsum/n;
	awt=wsum/n;
	printf("\n atat %f ",atat);
	printf("\n awt %f ",awt);
}


void future(){
	int n,p[10]={1,2,3,4,5,6,7,8,9,10},bt[10],at[10],tat[10],wt[10],ct=0,idle[10];
        int i,j,k=1,btime=0,min,idleTime;
        float awt=0,atat=0,wsum=0,tsum=0;

        printf("\nEnter the number of process : ");
        scanf("%d",&n);

        for(i=0;i<n;i++){
                printf("\nEnter bt for process %d: ",i+1);
                scanf("%d",&bt[i]);
                printf("\nEnter at for process %d: ",i+1);
                scanf("%d",&at[i]);
		idle[i]=at[i];
        }
	printf("\nEnter idle time : ");
	scanf("%d",&idleTime);

	for(i=0;i<n;i++){
		if(at[i]<idleTime){
			idle[i]=idleTime;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(idle[i]<idle[j]){
				swap(&p[i],&p[j]);
				swap(&at[i],&at[j]);
				swap(&bt[i],&bt[j]);
				swap(&idle[i],&idle[j]);
			}
			else if(idle[i]==idle[j] && bt[i]<bt[j]){
				swap(&p[i],&p[j]);
                                swap(&at[i],&at[j]);
                                swap(&bt[i],&bt[j]);
                                swap(&idle[i],&idle[j]);
			}
		}
	}

	btime=at[0];
	for(j=0;j<n;j++){
		btime= btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++){
			if(btime>=idle[i] && bt[i]< min){
				swap(&bt[i],&bt[k]);
                                swap(&at[i],&at[k]);
                                swap(&p[i],&p[k]);
                                swap(&idle[i],&idle[k]);
			}
		}
		k++;
	}
	ct=idle[0];
        wt[0]=0;

        printf("\npid \t at \t bt \t ct \t tat \t wt\n");
        for(i=0;i<n;i++){
                ct=ct+bt[i];
                tat[i]=ct-at[i];
                wt[i]=tat[i]-bt[i];
                tsum += tat[i];
                wsum += wt[i];
                printf("\np[%d] \t %d \t %d \t %d \t %d \t %d \n",p[i],at[i],bt[i],ct,tat[i],wt[i]);
        }
        atat=tsum/n;
        awt=wsum/n;
        printf("\n atat %f ",atat);
        printf("\n awt %f ",awt);
}




int main(){
	int ch;
	while(1){
		printf("\n1-sjf\n2-future\n");
		printf("\nEnter choice : ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				sjf();
				break;
			case 2:
				future();
				break;
			}
		}
	}
