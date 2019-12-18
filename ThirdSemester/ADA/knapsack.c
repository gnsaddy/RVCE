#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w, x[n];
	int K[n + 1][W + 1];

	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	printf("\n============================================\n");
	printf("\tProfit matrix\n");
	for (i = 0; i <= n; i++)
	{
		printf("\n");
		for (w = 0; w <= W; w++)
			printf("%d\t", K[i][w]);
	}
	printf("\n===========================================\n");
	i = n;
	w = W;
	while (i != 0 && w != 0)
	{
		if (K[i][w] != K[i - 1][w])
		{
			x[i] = 1;
			w = w - wt[i - 1];
		}
		i--;
	}

	printf("\nSelected Objects:\n");
	for (i = 1; i <= n; i++)
		printf("%d\t", i);
	printf("\n");
	for (i = 1; i <= n; i++)
	{
		if (x[i] == 1)
			printf("1\t");
		else
			printf("0\t");
	}
	printf("\n");

	return K[n][W];
}

int main()
{
	int i, n, val[20], wt[20], W;

	printf("Enter number of items:");
	scanf("%d", &n);

	printf("Enter value and weight of items:\n");
	for (i = 0; i < n; ++i)
	{
		scanf("%d%d", &val[i], &wt[i]);
	}

	printf("Enter size of knapsack:");
	scanf("%d", &W);

	printf(" The total Profit => %d\n", knapSack(W, wt, val, n));
	return 0;
}
