#include <stdio.h>
void main()

{
    int a[20], i, j, n, big, noeb[20], bucket[20][20], count = 0, step, loc, div = 1, k;
    printf("Enter No of elements:");
    scanf("%d", &n);

    printf("Enter elements in array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    //find biggest number in the list
    big = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > big)
        {
            big = a[i];
        }
    }

    while (big > 0)
    {
        big = big / 10;
        count++;
    }

    for (step = 1; step <= count; step++)
    {
        for (i = 0; i < 10; i++)
        {
            noeb[i] = 0;
        }

        for (i = 0; i < n; i++)
        {
            loc = (a[i] / div) % 10;

            bucket[loc][noeb[loc]++] = a[i];
        }
        k = 0;
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < noeb[i]; j++)
            {
                a[k++] = bucket[i][j];
            }
        }
        div = div * 10;
    }

    printf("Sorted array using bucket sort:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}