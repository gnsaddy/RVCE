#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

char t[100], p[50];
int n,m;

int brute_force()
{
    int  j, i;
    n = strlen(t);
    m = strlen(p);

    for (i = 0; i < n; i++)
    {
        j = 0;
        while (j < m && t[i + j] == p[j])
        {
            j++;
            if (j == m)
                return i + 1; //pattern found
        }
    }
    return -1; //pattern not found
}

void main()
{
    struct timeval start, end;
    float t1,t2;
    int pos,i;
    FILE *out_file = fopen("stats.txt", "w");
for(i=1;i<=6;i++){
    printf("Enter the Source String :-  \n");
    gets(t);

    printf("Enter the pattern for best case:-  \n");
    gets(p);

    gettimeofday(&start, 0);
    pos = brute_force();
    gettimeofday(&end, 0);

    t1 = end.tv_usec - start.tv_usec;
    if (pos == -1)
        printf("%s pattern not found in text", p);
    else
        printf("%s pattern found at index %d", p, pos);

    printf("Enter the pattern for worst case:- \n");
    gets(p);

    gettimeofday(&start,0);
    pos=brute_force();
    gettimeofday(&end,0);

    t2=end.tv_usec - start.tv_usec;
    if (pos == -1)
        printf("%s pattern not found in text", p);
    else
        printf("%s pattern found at index %d", p, pos);
    fprintf(out_file, "%d\t %.2f\t %.2f\n",n,t1,t2); // write to file

    printf("\nTime taken is %.2fms and %.2fms to execute \n", t1,t2);
  }
  fclose(out_file);
}
