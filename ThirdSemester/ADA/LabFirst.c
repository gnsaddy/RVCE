// implement string pattern matching using brute force technique and find the complexity for different times

#include <stdio.h>
#include <string.h>
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
    printf("Enter the Source String :-  ");
    gets(t);
    printf("Enter the pattern :-  ");
    gets(p);

    gettimeofday(&start, NULL);
    pos = brute_force();
    gettimeofday(&end, NULL);

    if (pos == -1)
        printf("%s pattern not found in text", p);
    else
        printf("%s pattern found at index %d", p, pos);

    int time_taken = end.tv_usec - start.tv_usec;
    // cpu process time calculation
    printf("\nbrute_force() took %d seconds to execute \n", time_taken);
}
