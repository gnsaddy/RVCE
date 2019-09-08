// implement string pattern matching using brute force technique and find the complexity for different times

#include <stdio.h>
#include<windows.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

char t[100], p[50];

int brute_force()
{
    int n, j, m, i;
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
    int pos;
    FILE *out_file = fopen("stats.txt", "a"); // append only
    printf("Enter the Source String :-  ");
    gets(t);
    printf("Enter the pattern :-  ");
    gets(p);

    gettimeofday(&start, 0);
    pos = brute_force();
    gettimeofday(&end, 0);

    if (pos == -1)
        printf("%s pattern not found in text", p);
    else
        printf("%s pattern found at index %d", p, pos);

    unsigned long time_taken = end.tv_sec - start.tv_sec;

    if (out_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }

    // write to file vs write to screen
    fprintf(out_file, "Different timings %ld\n", time_taken); // write to file

    // fprintf(stdout, "this is a test %d\n", time_taken); // write to screen

    // cpu process time calculation
    printf("\nbrute_force() took %ld seconds to execute \n", time_taken);
}
