#include <stdio.h>

void main()
{
    int n, a[10], i, min, j, t;
    printf("ENter number of elements you want to stored...");
    scanf("%d", &n);
    printf("Enter elements in array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("array element at :%d is %d\n", i, a[i]);
    }

    printf("Element in sorted order:\n");

    for (i = 0; i < n; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }

    for (i = 0; i < n; i++)
    {
        printf("array element at :%d is %d\n", i, a[i]);
    }
}