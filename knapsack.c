#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int MAX_SIZE = 1000;
    int total_cost = 100;
    FILE *fp;
    int cost[MAX_SIZE];
    int value[MAX_SIZE];
    int line[64];

    if (argc == 1)
    {
        printf("Usage of knapsack: ./knapsack [filename] [optional: threshold]\n");
        exit(1);
    }

    if (argc == 2)
    {
        total_cost = 100;
        fp = fopen(argv[1], "r");
        if (fp == 0)
        {
            printf("open file failed\n");
            exit(1);
        }
        int line_count = 0;
        while (fgets(line, 64, fp) != NULL)
        {
            sscanf(line, "%*d %d %d", &cost[line_count], &value[line_count]);
            line_count++;
        }
        fclose(fp);
    }

    return 0;
}