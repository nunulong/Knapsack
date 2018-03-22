#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main(int argc, char **argv)
{
    FILE *fp;
    int *weights = NULL;
    int *values = NULL;
    int total_weight;
    int item_number = 0;

    if (argc == 2 || argc == 3)
    {
        fp = fopen(argv[1], "r");
        if (fp == 0)
        {
            printf("open file failed\n");
            exit(1);
        }

        while (!feof(fp))
        {
            int ch = fgetc(fp);
            if (ch == '\n')
            {
                item_number++;
            }
        }
        fclose(fp);

        fp = fopen(argv[1], "r");
        if (fp == 0)
        {
            printf("open file failed\n");
            exit(1);
        }

        weights = (int *)malloc(item_number * sizeof(int));
        values = (int *)malloc(item_number * sizeof(int));

        int number_read = 0; //bucket to store the last item read from file

        for (int i = 0; i < item_number; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int found = fscanf(fp, "%d", &number_read);
                if (found == 1)
                {
                    switch (j)
                    {
                    case 0:
                        break;
                    case 1:
                        weights[i] = number_read;
                        break;
                    case 2:
                        values[i] = number_read;
                        break;
                    }
                }
            }
        }
        fclose(fp);
    }
    else
    {
        printf("Usage of knapsack: ./knapsack [filename] [optional: threshold]\n");
        exit(1);
    }

    if (argv[2] != NULL)
    {
        total_weight = strtol(argv[2], NULL, 10);
    }
    else
    {
        total_weight = 100;
    }

    printf("%d", knapSack(total_weight, weights, values, item_number));

    return 0;
}