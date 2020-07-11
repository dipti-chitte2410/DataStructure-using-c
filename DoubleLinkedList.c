#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
int len;
void append(void);
void length(void);
void addafter(void);
void display(void);
void addbegin(void);
void delete (void);

void main()
{
    int ch;
    while (1)
    {
        printf("1:Append Node\n");
        printf("2:Length of node\n");
        printf("3:Add After specified node\n");
        printf("4:Display elemnt\n");
        printf("5:Add element at begin\n");
        printf("6:Delete a specific node\n");
        printf("7::Exit\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;

        case 2:
            length();
            break;

        case 3:
            addafter();
            break;
        case 4:
            display();
            break;

        case 5:
            addbegin();
            break;
        case 6:
            delete ();
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }
}

void delete ()
{
    struct node *p;
    int loc, i = 0;
    printf("Which node you want to delete");
    scanf("%d", &loc);
    p = root;
    while (i < loc - 1)
    {
        p = p->right;
        i++;
    }

    p->right->left = p->left;
    p->left->right = p->right;
    p->left = NULL;
    p->right = NULL;
    free(p);
}

void addbegin()
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &temp->data);
    temp->right = NULL;
    temp->left = NULL;
    p = root;

    temp->right = p;
    p->left = temp;

    root = temp;
}

void addafter()
{
    struct node *temp, *p;
    int i = 0, loc;
    printf("After what location:");
    scanf("%d", &loc);
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    p = root;
    while (loc - 1 > i)
    {
        p = p->right;
        i++;
    }
    temp->right = p->right;
    p->right->left = temp;
    temp->left = p;
    p->right = temp;
}

void length()
{
    struct node *temp;
    int count = 0;
    temp = root;
    while (temp != NULL)
    {
        temp = temp->right;
        count++;
    }
    len = count;
    printf("Length of node is:%d\n", len);
}

void display()
{
    struct node *temp;
    temp = root;
    while (temp != NULL)
    {
        printf("%d<- %d ->%d\n", temp->left, temp->data, temp->right);
        temp = temp->right;
    }
}

void append()
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;

    p = root;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        while (p->right != NULL)
        {
            p = p->right;
        }
        temp->left = p;
        p->right = temp;
    }

    temp = root;
}
