#include <stdio.h>
#include <stdlib.h>
void display1(void);
void create(void);

void display2(void);
void create2(void);
void addition(void);
struct node
{
    int coef, expo;
    struct node *link;
} *root = NULL, *p1, *p2, *root2 = NULL, *new1, *new2;

void main()
{
    int ch;
    while (1)
    {
        printf("Enter operation to perform:EXPRESSION 1\n1:create1\n2display1()\n3:create 2\n4:display2()\n5:Addition\n6:Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display1();
            break;
        case 3:
            create2();
            break;
        case 4:
            display2();
            break;
        case 5:
            addition();
            break;
        case 6:
            exit(0);
            break;

        default:
            break;
        }
    }
}

void display1()
{
    p1 = root;
    while (p1 != NULL)
    {
        printf("%dx^%d", p1->coef, p1->expo);
        p1 = p1->link;
        printf("+");
    }
}
void display2()
{
    p2 = root2;
    while (p2 != NULL)
    {
        printf("%dx^%d", p2->coef, p2->expo);
        p2 = p2->link;
        printf("+");
    }
}

void create()
{
    new1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter coefficient:");
    scanf("%d", &new1->coef);
    printf("Enter Exponent:");
    scanf("%d", &new1->expo);
    new1->link = NULL;
    p1 = root;

    if (root == NULL)
    {
        root = new1;
    }
    else
    {
        while (p1->link != NULL)
        {
            p1 = p1->link;
        }
        p1->link = new1;
    }
}

void create2()
{
    new2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter coefficient:");
    scanf("%d", &new2->coef);
    printf("Enter Exponent:");
    scanf("%d", &new2->expo);
    new2->link = NULL;
    p2 = root2;

    if (root2 == NULL)
    {
        root2 = new2;
    }
    else
    {
        while (p2->link != NULL)
        {
            p2 = p2->link;
        }
        p2->link = new2;
    }
}

void addition()
{
    p1 = root;
    p2 = root2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo == p2->expo)
        {
            printf("%dx^%d", p1->coef + p2->coef, p1->expo);
            printf("+");
            p1 = p1->link;
            p2 = p2->link;
        }
        else if (p1->expo > p2->expo)
        {
            printf("%dx^%d", p1->coef, p1->expo);
            printf("+");
            p1 = p1->link;
        }
        else
        {
            printf("%dx^%d", p2->coef, p2->expo);
            p2 = p2->link;
            printf("+");
        }
    }
    while (p1 != NULL)
    {
        printf("%dx^%d", p1->coef, p1->expo);
        p1 = p1->link;
        printf("+");
    }

    while (p2 != NULL)
    {
        printf("%dx^%d", p2->coef, p2->expo);
        p2 = p2->link;
        printf("+");
    }
}