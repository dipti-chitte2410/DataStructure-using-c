#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[20];
    int roll_no;
    float per;
    struct node *link;
};
struct node *root = NULL;

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
    printf("Enter name");
    scanf("%s", temp->name);
    printf("Enter rollNo");
    scanf("%d", &temp->roll_no);
    printf("Enter Percentage");
    scanf("%f", &temp->per);

    temp->link = NULL;
    if (root == NULL)
    {
        printf("list is empty here is the first record:\n");
        root = temp;
    }
    else
    {
        p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void display()
{
    struct node *temp;
    int n = 0;
    temp = root;
    while (temp != NULL)
    {
        printf("Name:%s,RollNo:%d,Percentage:%f\n", temp->name, temp->roll_no, temp->per);

        if (temp->per >= 60.0)
        {
            n++;
        }
        temp = temp->link;
    }
    printf("NO of student who got 60 and more are:%d", n);
}