#include <stdio.h>
void main()
{
    int a[] = {8, 3, 6, 2, 7, 5, 1};
    int i, j, key;
    for (i = 1; i < 7; i++)
    {

        key = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] < key)
            {
                a[j + 1] = a[j];
                key = a[j];
            }
        }
        a[j + 1] = key;
    }

    for (i = 0; i < 7; i++)
    {
        printf("%d\n", a[i]);
    }
}