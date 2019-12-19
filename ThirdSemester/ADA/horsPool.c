#include <stdio.h>
#include <string.h>
#include <string.h>
#include <sys/time.h>

struct timeval st, en;

int table[127];
void shift_table(char p[])
{
    int i, j, m;
    m = strlen(p);
    for (i = 0; i < 127; i++)
        table[i] = m;
    for (j = 0; j < m - 1; j++)
    {
        table[p[j]] = m - 1 - j;
    }
}

int horspool(char text[], char p[])
{
    int i, j, k, m, n;
    n = strlen(text);
    m = strlen(p);
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == text[i - k]))
            k++;
        if (k == m)
            return (i - m + 1);
        else
            i += table[text[i]];
    }
    return -1;
}

void main()
{
    char text[100], pat[100];
    int pos, n, i;
    float ct,t1,t2;
    FILE *fp;
    fp = fopen("enhance.txt", "w");

    for (i = 1; i <= 3; i++)
    {
        printf("Enter the text in which pattern is to be searched:\n");
        gets(text);
        n = strlen(text);

        printf("Enter the pattern to be searched in best case :\n");
        gets(pat);
        gettimeofday(&st, 0);
        shift_table(pat);
        pos = horspool(text, pat);
        gettimeofday(&en, 0);
        t1 = en.tv_usec - st.tv_usec;
        if (pos >= 0)
            printf("\n The desired pattern was found starting from position %d", pos + 1);
        else
            printf("\n The pattern was not found in the given text!\n");

        printf("Enter the pattern to be searched in worst case :\n");
        gets(pat);
        gettimeofday(&st, 0);
        shift_table(pat);
        pos = horspool(text, pat);
        gettimeofday(&en, 0);
        t2 = en.tv_usec - st.tv_usec;
        if (pos >= 0)
            printf("\n The desired pattern was found starting from position %d", pos + 1);
        else
            printf("\n The pattern was not found in the given text!\n");
        fprintf(fp, "%d\t %.2f\t %.2f\n",n,t1,t2); // write to file
        printf("\nTime taken is %.2fms and %.2fms to execute \n", t1,t2);

    }
}
