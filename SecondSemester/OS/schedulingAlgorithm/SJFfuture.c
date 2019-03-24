#include<stdio.h>
#include<stdlib.h>

int main(){
    int num,pid[20],exeTime[20],at[20],ct=0,wt=0,tat=0,sumWT=0,sumTAT=0;
    int i,j,temp,idle;
    float awt,atat;

    printf("\nEnter the number of process : ");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        printf("\nEnter execution time for process %d : ",i+1);
        scanf("%d",&exeTime[i]);
        pid[i]=i+1;
    }

    for(i=0;i<num;i++){
        printf("\nEnter arrival time for process %d : ",i+1);
        scanf("%d",&at[i]);
    }
    idle = at[0];

    for (i=1;i<num;i++){
        if(at[i]>idle)
            idle = at[i];
    }
    printf("\nCPU idle time is :%d \n ",idle);

for(int i=0;i<num;i++){
    for(int j=0;j<num;j++){
        if(exeTime[i]<exeTime[j]){

            // swap burst time
            int temp = exeTime[i];
            exeTime[i]=exeTime[j];
            exeTime[j]=temp;
            // swap arrival time
            temp=at[j];
            at[j]=at[i];
            at[i]=temp;
            // swap position
            temp = pid[i];
            pid[i] = pid[j];
            pid[j] = temp;
        }
    }
}

printf("\nPid \t\tAT \t\t BT \t\tCT \t\t WT \t\t TAT");

for (int i=0;i<num;i++){
    ct += exeTime[i]+idle;
    tat=ct-at[i];
    wt=tat-exeTime[i];
    sumWT += wt;
    sumTAT += tat;
    printf("\np%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n",pid[i],at[i],exeTime[i],ct,wt,tat);

}

awt = sumWT/num;
atat= sumTAT/num;
printf("AWT %f ",awt);
printf("ATAT %f ",atat);

}
    
