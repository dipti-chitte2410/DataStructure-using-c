#include <stdio.h>
void main()
{
    int array[10], i, n = 11, search, mid, high = 10, low = 0;
    printf("Enter element in array ascending order:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter elemnent to search:");
    scanf("%d", &search);

    mid = (low + high) / 2;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (search < array[mid])
        {
            high = mid - 1;
        }
        else if (search > array[mid])
        {
            low = mid + 1;
        }
        else if (search == array[mid])
        {
            printf("Element %d found at %d", search, mid);
            break;
        }
        else
        {
            printf("Element couldn't found");
        }
    }
}