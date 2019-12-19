
// implement string pattern matching using brute force technique and find the complexity for different times
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

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

    mingw_gettimeofday(&start, NULL);
    pos = brute_force();
    // sleep(1);
    mingw_gettimeofday(&end, NULL);

    if (pos == -1) 
        printf("%s pattern not found in text", p);
    else
        printf("%s pattern found at index %d", p, pos);

    
    long seconds = (end.tv_sec - start.tv_sec);
    long micros = (end.tv_usec - start.tv_usec);

    printf("\nTime elapsed is %d seconds and %d micros\n", seconds, micros);


    if (out_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }

    // write to file vs write to screen
    fprintf(out_file, "\nTime elapsed is %d seconds and %d micros\n", seconds, micros); // write to file

    // fprintf(stdout, "this is a test %d\n", time_taken); // write to screen

}
