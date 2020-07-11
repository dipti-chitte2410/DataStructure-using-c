#include <stdio.h>
#include <stdlib.h>
#define capacity 5
int cqueue[capacity];
int front = -1, rear = -1;

void insert();
void delete ();
void display();

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

void insert(int ele)
{
    if (front == rear + 1 || rear == capacity - 1)
    {
        printf("Queue is full");
    }

    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        cqueue[rear] = ele;
    }
    else if (rear == capacity - 1)
    {
        rear = 0;

        cqueue[rear] = ele;
    }

    else
    {
        rear++;
        cqueue[rear] = ele;
    }
}

void delete ()
{

    if (rear == -1 && front == -1)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        printf("Item deleted:%d", cqueue[front]);
        front = -1;
        rear = -1;
    }

    else if (front + 1 == capacity)
    {
        printf("Item deleted:%d", cqueue[front]);
        front = 0;
    }
    else
    {
        printf("Item deleted:%d", cqueue[front]);
        front++;
    }
}

void display()
{
    int i = 0;
    // if (rear == capacity)
    // {
    //     for (i = 0; i < rear; i++)
    //     {
    //         printf("Item at %d:%d", i + 1, cqueue[i]);
    //     }
    // }

    for (i = 0; i < rear; i++)
    {
        printf("Item at %d:%d", i + 1, cqueue[i]);
    }

    for (i = front; i < capacity - 1; i++)
    {
        printf("Item ar %d:%d", i + 1, cqueue[i]);
    }
}