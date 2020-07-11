#include <stdio.h>
void maxheap(int[], int, int);
void main()
{
    int n, a[10], i, t;
    printf("ENter number of elements yyou want to stored...");
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

    for (i = n / 2; i >= 0; i--)
    {
        maxheap(a, i, n);
    }

    for (i = n - 1; i > 0; i--)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;

        maxheap(a, 0, i);
    }

    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("array element at :%d is %d\n", i, a[i]);
    }
}

void maxheap(int a[], int i, int n)
{
    int child, t;
    while (2 * i + 1 < n)
    {
        child = 2 * i + 1;

        if (a[child] < a[child + 1] && child < n - 1)
        {
            child = child + 1;
        }

        if (a[i] < a[child])
        {
            t = a[child];
            a[child] = a[i];
            a[i] = t;
        }
        i = child;
    }
}