#include<stdio.h>
#include<stdlib.h>

int bt[10],at[10],wt[10],tat[10],rt[10],ct=0;
int i,n,time,remain,flag=0,temp=0,tq;

void take(){
	printf("\nEnter the number of process\n");
	scanf("%d",&n);
	remain=n;
	for(i=0;i<n;i++){
		printf("\nEnter bt for process %d : ",i+1);
		scanf("%d",&bt[i]);
		printf("\nEnter at for process %d : ",i+1);
		scanf("%d",&at[i]);
		rt[i]=bt[i];
	}
}

void rr(){
	float awt=0,atat=0;
	take();
	printf("\nEnter time quantum : ");
	scanf("%d",&tq);

	printf("\npid \t AT \t BT \t TAT \t WT \n");
	for(time=0,i=0;remain!=0;){
		if(rt[i]<=tq && rt[i]>0){
			time += rt[i];
			rt[i]=0;
			flag=1;
		}
		else if(rt[i]>0){
			rt[i] -= tq;
			time += tq;
		}

		if(rt[i]==0 && flag==1){
			remain--;
			printf("\np[%d] \t %d \t %d \t %d \t %d \n",i+1,at[i],bt[i],time-at[i],time-at[i]-bt[i]);
			awt += time-at[i]-bt[i];
			atat += time-at[i];
			flag=0;
		}

		if(i==(n-1))
			i=0;
		else if(at[i+1]<=time)
			i++;
		else
			i=0;

	}
	printf("\n AWT : %f ", (awt/n));
	printf("\n ATAT : %f ", (atat/n));
}


void fcfs(){
	float awt=0,atat=0;
	take();
	wt[0]=0;
	temp=at[0];
	for(i=1;i<n;i++){
		temp=temp+bt[i-1];
		wt[i]=temp-at[i];
		awt += wt[i];
	}
	ct=at[0];
	printf("\npid \t AT \t BT \t CT \t TAT \t WT \n");
	for(i=0;i<n;i++){
		ct +=  bt[i];
		tat[i]= ct-at[i];
		atat += tat[i];
		printf("\np[%d] \t %d \t %d \t %d \t %d \t %d \n",(i+1),at[i],bt[i],ct,tat[i],wt[i]);
	}

	printf("\n AWT : %f ", awt/n);
	printf("\n ATAT : %f ",atat/n);
}

void main(){
	int ch;
	while(1){
		printf("\n1-FCFS\n2-RR\n");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: fcfs(); break;
			case 2: rr(); break;
		}
	}
}
