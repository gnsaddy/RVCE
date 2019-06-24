#include<stdio.h>
#include<stdlib.h>

#define low 0
#define high 199
/*
void main(){
	int size,queue[20],head,diff=0,seek=0,i,j;
	float avg;

	printf("\nEnter queue size ");
	scanf("%d",&size);
	printf("\nEnter elements in queue ");
	for(i=0;i<size;i++)
		scanf("%d",&queue[i]);
	printf("\nEnter head position ");
	scanf("%d",&head);
	queue[0]=head;

	for(j=0;j<size-1;j++){
		diff = abs(queue[j]-queue[j+1]);
		seek += diff;
		printf("\nMove from %d to %d with seek time of %d ",queue[j],queue[j+1],diff);
	}

	printf("\nTotal seek time is : %d ",seek);
	avg = seek/(float)size;
	printf("\nAVG seek time is : %f",avg);
}


void main(){
	int size,queue[20],head,headt,a[20],index[20],min,mini,i,j=0,k,mov=0;
	printf("\nEnter queue size ");
        scanf("%d",&size);
        printf("\nEnter elements in queue ");
        for(i=0;i<size;i++)
                scanf("%d",&queue[i]);
        printf("\nEnter head position ");
        scanf("%d",&head);
	headt=head;

	for(k=0;k<size;k++){
		for(i=0;i<size;i++){
			index[i]= abs(head-queue[i]);
		}
		min=index[0];
		mini=0;
		for(i=1;i<size;i++){
			if(min>index[i]){
				min=index[i];
				mini=i;
			}
		}

		a[j]=queue[mini];
		j++;

		head=queue[mini];
		queue[mini]=999;

	}

	printf("\nSequence is : ");
	printf("\n%d-->",headt);
	mov = mov + abs(headt-a[0]);
	printf("-->%d",a[0]);

	for(i=1;i<size;i++){
		mov = mov + abs(a[i]-a[i-1]);
		printf("-->%d",a[i]);
	}
	printf("\nTotal head movement %d",mov);
}
*/

void main(){
	int size,queue[20],head,temp,sum,max,dloc,i,j,k;
	printf("\nEnter queue size ");
        scanf("%d",&size);
        printf("\nEnter elements in queue ");
        for(i=0;i<size;i++)
                scanf("%d",&queue[i]);
        printf("\nEnter head position ");
        scanf("%d",&head);
	queue[size]=head;
	size++;

	for(i=0;i<size;i++){
		for(j=i;j<size;j++){
			if(queue[i]>queue[j]){
				temp=queue[i];
				queue[i]=queue[j];
				queue[j]=temp;
			}
		}
	}

	max = queue[size-1];

	for(i=0;i<size;i++){
		if(head==queue[i]){
			dloc=i;
			break;
		}
	}

	if((abs(head-low)) <= (abs(head-high))){
		for(j=dloc;j>=0;j--)
			printf("%d-->",queue[j]);
		printf("0-->");
		for(j=dloc+1;j<size;j++)
			printf("%d-->",queue[j]);
	}
	else{
		for(j=dloc+1;j<size;j++)
                        printf("%d-->",queue[j]);
		printf("199-->");
		for(j=dloc;j>=0;j--)
                        printf("%d-->",queue[j]);
	}
	sum = head + max;
	printf("\nTotal head movement %d :",sum);
}



