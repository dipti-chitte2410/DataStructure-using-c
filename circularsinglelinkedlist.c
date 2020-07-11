#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;
struct node *rear;
void append(void);
void display(void);

void main()
{
    int ch;
    while (1)
    {
        printf("Enter element in the list:1\nExit:2\nDsplay:3");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            exit(0);

        case 3:
            display();
            break;
        default:
            break;
        }
    }

    printf("List element are:");
    display();
}

void append()
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (rear == NULL)
    {
        rear = temp;
    }
    else
    {
        p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
        temp->link = root;
    }
}

void display()
{
    struct node *p;
    p = root;
    while (p != NULL)
    {
        printf("%d->%d", p->data, p->link);
        p = p->link;
    }
}