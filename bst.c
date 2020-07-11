#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

void insert(void);
void delete (void);
void traversal(struct node *);
void main()
{
    int ch;

    while (1)
    {
        printf("1:Insertion\n2:Deletion\4n3:Traversal\n4:Exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            delete ();
            break;

        case 3:
            traversal(root);
            break;

        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }
}

void insert()
{
    struct node *t, *curr, *parent;
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter elements to insert:");
    scanf("%d", &t->data);

    t->left = NULL;
    t->right = NULL;
    if (root == NULL)
    {
        root = t;
    }
    else
    {

        curr = root;
        while (curr != NULL)
        {
            parent = curr;
            if (curr->data > t->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if (parent->data > t->data)
        {
            parent->left = t;
        }
        else
        {
            parent->right = t;
        }
    }
}
void traversal(struct node *t)
{
    if (t->left != NULL)
    {
        traversal(t->left);
    }
    printf("%d <-  %d  ->%d\n", t->left, t->data, t->right);
    if (t->right != NULL)
    {
        traversal(t->right);
    }
}

void delete ()
{
    struct node *p, *curr;
    int data;
    printf("Enter the data you want to delete:");
    scanf("%d", &data);
    curr = root;
    while (curr)
    {
        p = curr;
        if (curr->data > data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (p->data < data)
    {
        printf("DeletedL:%d", data);
        p->right = NULL;
    }
    else if (p->data > data)
    {
        printf("DeletedL:%d", data);
        p->left = NULL;
    }
    else
    {
        printf("Cant delete any item");
    }
}
