#include<stdio.h>
#include <stdlib.h>
#define LOW 0
#define HIGH 199

int fcfs(){
  int queue[100], q_size, head, seek =0, diff;
  float avg;
  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &q_size);
  printf("%s\n", "Enter queue elements");
  for(int i=1; i<=q_size; i++){
    scanf("%d",&queue[i]);
  }
  printf("%s\n","Enter initial head position");
  scanf("%d", &head);
  queue[0]=head;
  for(int j=0; j<=q_size-1; j++){
    diff = abs(queue[j]-queue[j+1]);
    seek += diff;
    printf("Move from %d to %d with Seek %d\n",queue[j],queue[j+1],diff);
  }
  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\t", avg);
  return 0;
}

int sstf(){
    int i,n,k,req[50],mov=0,cp,index[50],min,a[50],j=0,mini,cp1;
    printf("\nEnter the current position : ");
    scanf("%d",&cp);
    printf("\nEnter the number of requests : ");
    scanf("%d",&n);
    cp1=cp;
    printf("\nEnter the request order : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    for(k=0;k<n;k++){
    for(i=0;i<n;i++)
    {
        index[i]=abs(cp-req[i]); // calculate distance of each request from current position
                
    }
    // to find the nearest request
    min=index[0];
    mini=0;
    for(i=1;i<n;i++)
    {
        if(min>index[i])
        {
            min=index[i];
            mini=i;
        }
    }
    a[j]=req[mini];
    j++;
    cp=req[mini]; // change the current position value to next request
    req[mini]=199;
    } // the request that is processed its value is changed so that it is not processed again
    printf("Sequence is : ");
    printf("%d",cp1);    
    mov=mov+abs(cp1-a[0]);    // head movement
    printf("-->%d",a[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(a[i]-a[i-1]); ///head movement
        printf(" -> %d",a[i]);
    }
   
	printf("\nTotal head movement = %d\n",mov);
    printf("\nAverage seek time is %1.3f",mov/(float)n);
    return 0;
}

int scan(){
     int queue[20];
  int head, max, q_size, temp, sum;
  int dloc; //location of disk (head) arr
  printf("%s\t", "Input no of disk locations");
  scanf("%d", &q_size);
  printf("%s\t", "Enter head position");
  scanf("%d", &head);
  printf("%s\n", "Input elements into disk queue");
  for(int i=0; i<q_size; i++){
    scanf("%d", &queue[i]);
  }
  queue[q_size] = head; //add RW head into queue
  q_size++;
  //sort the array
  for(int i=0; i<q_size;i++){
    for(int j=i; j<q_size; j++){
      if(queue[i]>queue[j]){
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }
  max = queue[q_size-1];
  //locate head in the queue
  for(int i=0; i<q_size; i++){
    if(head == queue[i]){
      dloc = i;
      break;
    }
  }
  if(abs(head-LOW) <= abs(head-HIGH)){
      for(int j=dloc; j>=0; j--){
        printf("%d --> ",queue[j]);
      }
      printf("0 -->");
      for(int j=dloc+1; j<q_size; j++){
        printf("%d --> ",queue[j]);
      }
      }      
       else {
      for(int j=dloc+1; j<q_size; j++){
          printf("%d --> ",queue[j]);
      }
      printf("199 -->");     
      for(int j=dloc; j>=0; j--){
          printf("%d --> ",queue[j]);
      }
  }
  sum  = head + max;
  printf("\nmovement of total cylinders %d", sum);
  return 0;
}

int main(){
    int ch;
    while(1){
        printf("\n1-FCFS\n2-SSTF\n3-SCAN\n");
        printf("\nEnter choice\t");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            fcfs();
            break;
        case 2:
            sstf();
            break;
        case 3:
            scan();
            break;
        
        default:
            printf("\nInvalid choice");
            break;
        }
    }
}


