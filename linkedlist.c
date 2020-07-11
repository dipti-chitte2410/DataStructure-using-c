#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *root;
int len;

void append(void);
void display(void);
int length(void);
void addatbegin(void);
void addafter(void);
void delete (void);
void swap(void);
void reverse(void);
void sort(void);

void main()
{
    int item, ch;
    while (1)
    {

        printf("Single linked list operations:\n");
        printf("1.Single linked list Append:\n");
        printf("2.Single linked list Addbeginning:\n");
        printf("3.Single linked list Addaftter:\n");
        printf("4.Single linked list length:\n");
        printf("5.Single linked list Display:\n");
        printf("6.Single linked list Delete:\n");
        printf("7.Swapping operation:\n");
        printf("8.Reverse the single linked list\n");
        printf("9.Sort the linked list:\n");
        printf("10.Single linked list Quit:\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            append();

            break;
        case 2:
            addatbegin();

            break;
        case 3:
            addafter();

            break;
        case 4:
            len = length();
            printf("Length is:%d", len);

            break;
        case 5:
            display();

            break;
        case 6:
            delete ();

            break;
        case 7:
            swap();
            break;
        case 8:
            reverse();
            break;

        case 9:
            sort();

            break;

        case 10:
            exit(0);

            break;

        default:
            printf("Invalid  choice");
            break;
        }
    }
}

void sort()
{
    int i, j, temp;
    int count = length() - 1;
    struct node *p, *q, *r;
    p = r = root;
    q = p->link;
    for (; p->link != NULL; p = p->link)
    {
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->link;
        }
        p = p->link;
        q = root;
    }
}

void reverse()
{
    int i = 0, j, k, temp;
    struct node *p, *q;
    p = q = root;
    j = length() - 1;
    printf("j=%d", j);
    while (i < j)
    {
        k = 0;
        while (k < j)
        {
            q = q->link;
            k++;
        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;

        p = p->link;
        q = root;
        i++;
        j--;
    }
}

void swap()
{
    struct node *p, *q, *r;
    int loc, i = 1;
    printf("Enter the location you want to swap:");
    scanf("%d", &loc);
    p = root;
    if (loc == 1)
    {
        q = p->link;
        r = q->link;

        p->link = r;
        q->link = p;
        root = q;
    }
    else
    {

        while (loc - 1 > i)
        {
            i++;
            p = p->link;
        }
        q = p->link;
        r = q->link;
        q->link = r->link;
        r->link = q;
        p->link = r;
    }
}

void addafter()
{
    struct node *temp;
    struct node *p;
    int loc, count;
    temp = (struct node *)malloc(sizeof(struct node));
    p = root;
    printf("Enter location after which you want to enter:");
    scanf("%d", &loc);

    printf("Enter Element :");
    scanf("%d", &temp->data);
    // count = length();
    if (loc > count - 1)
    {
        printf("Not possible");
    }
    else
    {
        count = length();
        while (loc - 1 > count)
        {
            p = p->link;
            count++;
        }
        temp->link = p->link;
        p->link = temp;
    }
}

void delete ()
{
    struct node *temp;
    struct node *p;
    int loc, count = 1;
    printf("Enter the location you want to delete:");
    scanf("%d", &loc);
    temp = root;

    if (loc == 1)
    {
        root = temp->link;
        temp->link = NULL;
        printf("First item deleted");
        free(temp);
    }
    else
    {

        while (count < loc - 1)
        {
            temp = temp->link;
            count++;
        }
        // printf("Item of location %d deleted", loc);
        p = temp->link;
        temp->link = p->link;
        p->link = NULL;
    }
}

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
    {
        printf("List is empty");
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

int length()
{
    struct node *p;
    int count = 0;
    p = root;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    return count;
}

void display()
{

    struct node *p;
    p = root;
    if (p == NULL)
    {

        printf("No elemnt to display");
    }
    else
    {

        while (p != NULL)
        {
            printf("%d->%d\n", p->data, p->link);
            p = p->link;
        }
    }
}

// void addafter()
// {
// }

void addatbegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to enter:");
    scanf("%d", &temp->data);

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->link = root;
        root = temp;
    }
}
