#include<stdio.h>
#include<stdlib.h>

int main(){
    int num,pid[20],i,j,temp;
    float exeTime[20],ct=0,wt=0,tat=0,sumWT=0,sumTAT=0;
    float idle,temp1;
    float awt,atat,at[20];

    printf("\nEnter the number of process : ");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        printf("\nEnter execution time for process %d : ",i+1);
        scanf("%f",&exeTime[i]);
        pid[i]=i+1;
    }

    for(i=0;i<num;i++){
        printf("\nEnter arrival time for process %d : ",i+1);
        scanf("%f",&at[i]);
    }
    
    printf("\nEnter cpu idle time : ");
    scanf("%f",&idle);
    printf("\nCPU idle time is :%f \n ",idle);

for(int i=0;i<num;i++){
    for(int j=0;j<num;j++){
        if(exeTime[i]<exeTime[j]){

            // swap burst time
            temp1= exeTime[i];
            exeTime[i]=exeTime[j];
            exeTime[j]=temp1;
            // swap arrival time
            temp1=at[j];
            at[j]=at[i];
            at[i]=temp1;
            // swap position
            temp = pid[i];
            pid[i] = pid[j];
            pid[j] = temp;
        }
    }
}

printf("\nPid \t\tAT \t\t BT \t\tCT \t\t WT \t\t TAT");

for (int i=0;i<num;i++){
    ct += exeTime[i];
    tat=ct-at[i];
    wt=tat-exeTime[i];
    sumWT += wt;
    sumTAT += tat;
    printf("\np%d \t\t %f \t\t %f \t\t %f \t\t %f \t\t %f\n",pid[i],at[i],exeTime[i],ct,wt,tat);

}

awt = sumWT/num;
atat= sumTAT/num;
printf("AWT %f ",awt);
printf("ATAT %f ",atat);

}
    
