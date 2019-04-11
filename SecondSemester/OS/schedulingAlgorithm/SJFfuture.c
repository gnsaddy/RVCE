#include<stdio.h>
#include<stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


int main(){
    int num,pid[20],at[20],atWithIdle[10],i,j,temp;
    int exeTime[20],ct=0,wt=0,tat=0,sumWT=0,sumTAT=0;
    int idle,temp1;
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
     for (i = 0; i < num; i++)
    {
        if (at[i] < idle)
        {
            atWithIdle[i] = idle;
        }
    }

for(int i=0;i<num;i++){
    for(int j=0;j<num;j++){
        if(exeTime[i]<exeTime[j]){
            // swap burst time
            swap(&exeTime[i],&exeTime[j]);            
            // swap arrival time
            swap(&at[i],&at[j]);
            // swap position
            swap(&pid[i],&pid[j]);
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
    printf("\np%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n",pid[i],at[i],exeTime[i],ct,wt,tat);

}

awt = sumWT/num;
atat= sumTAT/num;
printf("AWT %f ",awt);
printf("ATAT %f ",atat);

}
    
