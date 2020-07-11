#include <stdio.h>
void mergesort(int[], int, int);
void merge(int[], int, int, int);
int a[10], temp[20];
void main()
{
    int n, i;
    printf("Enter number of element:");
    scanf("%d", &n);
    printf("Enter elements in array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("Sorted array is:");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void mergesort(int a[], int start, int end)
{
    int middle;
    if (start == end)
    {
        return;
    }

    printf("IN merge sort");
    middle = (start + end) / 2;
    mergesort(a, start, middle);
    mergesort(a, middle + 1, end);
    merge(a, start, middle, end);
}

void merge(int a[], int start, int middle, int end)
{
    int left[10], right[10], i, j, k, n1, n2;
    n1 = middle + 1;
    n2 = end - middle;
    printf("In merge function");
    for (i = 0; i < n1; i++)
    {
        left[i] = a[start + i];
    }
    printf("LEft array: n1=%d\n", n1);
    for (i = 0; i < n1; i++)
    {
        printf("%d\n", left[i]);
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = a[middle + 1 + j];
    }
    printf("right array:n2=%d\n", n2);
    for (i = 0; i < n2; i++)
    {
        printf("%d\n", right[i]);
    }
    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            temp[k] = left[i];
            i++;
        }
        else
        {
            temp[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        temp[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        temp[k] = right[j];
        j++;
        k++;
    }
    // printf("Sorted array is:");
    for (i = 0; i < 10; i++)
    {
        a[i] = temp[i];
    }
}