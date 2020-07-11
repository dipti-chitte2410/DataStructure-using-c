#include <stdio.h>
void main()
{
    int n, a[10], i, t, j;
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
    printf("Sorted element:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("array element at :%d is %d\n", i, a[i]);
    }
}