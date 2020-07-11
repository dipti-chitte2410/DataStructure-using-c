#include <stdio.h>
#include <stdlib.h>
#define capacity 5

int queue[capacity];
int front = 0;
int rear = 0;

void insert(int);
void delete (void);
void display(void);
void main()
{
    int ch, ele;
    while (1)
    {
        printf("Enter choice 1:Insert \n2:Delete\n3:Display\n4:Exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert");
            scanf("%d", &ele);
            insert(ele);
            break;

        case 2:
            delete ();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            break;
        }
    }
}

void insert(int item)
{
    if (rear == capacity)
    {
        printf("Queue if FUll");
    }
    else
    {
        // printf("ENter element to insert");
        // scanf("%d", &ele);
        queue[rear] = item;
        rear++;
    }
}

void delete ()

{
    int i;

    if (rear == front)
    {
        printf("No element in the list");
    }
    printf("Element to be deleted is :%d", queue[front]);
    for (i = 0; i < rear; i++)
    {
        queue[i] = queue[i + 1];
    }
    rear--;
}

void display()
{
    int i;
    for (i = 0; i < rear; i++)
    {
        printf("Element at %d location:%d\n", i + 1, queue[i]);
    }
}