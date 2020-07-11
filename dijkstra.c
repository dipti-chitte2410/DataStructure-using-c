#include <stdio.h>
void main()
{
    int cost[5][5];
    int path[5][5], i, j, n, u, v, p, distance[] = {0}, row, column, min;
    printf("Enter number of element:");
    scanf("%d", &n);

    printf("Enter value in cost matrix");
    for (i = 0; i < n; i++)
    {
        printf("row=%d\n", i);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter number of element path matrix:");
    scanf("%d", &p);

    printf("Enter value in path matrix");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("element at [%d][%d]:", i, j);
            scanf("%d", &path[i][j]);
            printf("\n");
        }
    }

    v = 4;

    for (i = 0; i < p; i++)
    {
        distance[i] = 0;
        row = 0;
        for (j = 1; j <= n; j++)
        {
            if (row != v)
            {
                column = path[i][j + 1];
                distance[i] = cost[row][column] + distance[i];
                row = column;
            }
        }
    }

    min = distance[0];
    for (i = 0; i < p; i++)
    {
        if (min >= distance[i])
        {
            min = distance[i];
            u = i;
        }
    }
    printf("Minimum cost require from 1 to 5:%d", min);
    printf("Path is:");
    for (i = 0; i < n; i++)
    {
        printf("%d", path[u][i]);
        printf("->");
    }
}