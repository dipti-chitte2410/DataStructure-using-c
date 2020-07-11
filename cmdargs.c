#include <stdio.h>
int main(int argc, char *argv[])
{
    int i;
    printf("No of argument is:%d\n", argc);
    for (i = 1; i < argc; i++)
    {
        printf("element at:%d is %s\n", i, argv[i]);
    }
    return 0;
}
