#include<stdio.h>
#include<stdlib.h>

int num,bt[20],at[20],ct=0,wt[20],tat[20],rt[10];
int i,temp=0,j,time,remain,flag=0,time_quantum;
float awt=0,atat=0;
float sumWT,sumTAT;

void takeInput(){  // input taking
    printf("\nEnter the number of process : ");
    scanf("%d",&num);
    remain=num; 

    for(i=0;i<num;i++){
        printf("\nEnter execution time for process %d : ",i+1);
        scanf("%d",&bt[i]);
        printf("\nEnter arival time for process %d : ",i+1);
        scanf("%d",&at[i]);
        rt[i]=bt[i]; 
    }
}
int rrMethod(){
    printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,i=0;remain!=0;) 
  { 
    if(rt[i]<=time_quantum && rt[i]>0) 
    { 
      time+=rt[i]; 
      rt[i]=0; 
      flag=1; 
    } 
    else if(rt[i]>0) 
    { 
      rt[i]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[i]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
      awt+=time-at[i]-bt[i]; 
      atat+=time-at[i]; 
      flag=0; 
    } 
    if(i==num-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",awt*1.0/num); 
  printf("Avg Turnaround Time = %f",atat*1.0/num); 
  printf("\n");
  
  return 0;

}

int fcfsMethod(){
    wt[0]=0;  // take var tenp and assign the first index vale of arrival time,this helps to put process into ready queue
    temp = at[0];  // this code of section also remove the fcfs overhead or fcfs convey effect
    for(i=1;i<num;i++){
        temp=temp+bt[i-1];
        wt[i]=temp-at[i];
        sumWT=sumWT+wt[i];
    }
    ct=at[0];
    printf("\nPid \t\t AT \t\t BT \t\t CT \t\t WT \t\t TAT");
    for(i=0;i<num;i++){
        ct += bt[i];
        tat[i]=ct-at[i];
        sumTAT += tat[i];
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n",i+1,at[i],bt[i],ct,wt[i],tat[i]);
    }
    awt = sumWT/num;
    atat = sumTAT/num;
    printf("\nAverage turn around time : %f",atat);
    printf("\nAverage waiting time : %f",awt);
    printf("\n");
}
void main(){
    printf("Round Robin & FCFS scheduling algorithm \n");
    int ch;
    while(1){
        printf("1-RR\n2-FCFS\n");
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                 takeInput();
                 rrMethod();
                  break;
            case 2:
                 takeInput();
                 fcfsMethod();
                break;
        }
    }
}