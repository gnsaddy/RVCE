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