#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

static int n = 0;

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}node;

void searchbst(node *root, int i)
{
    if(root != NULL)
    {
        if(i == root->data)
            printf("%d found ",  root->data);
        else if(i < root->data)
            searchbst(root->left, i);
        else if(i > root->data)
            searchbst(root->right, i);
    }
    else
        printf("%d not found", i);
}

node *create(node *, int);

void postorder(node *);

int main()
{
    node *root = NULL;
    setbuf(stdout, NULL);
    char ch;
    int item;
    // do
    // {
    //     printf("\nEnter data for node : ");
    //     scanf("%d", &item);
    //     root = create(root, item);
    //     printf("Do you warn to insert more elements? : ");
    //     scanf(" %c", &ch);
    // }while(ch == 'y' || ch == 'Y');
    root = create(root, 15);
    root = create(root, 11);
    root = create(root, 13);
    root = create(root, 8);
    root = create(root, 9);
    root = create(root, 17);
    root = create(root, 16);
    root = create(root, 18);
    printf("**** BST created ****\n");
    postorder(root);
    printf("\nno of nodes [%d] ",n);
    printf("\nEnter element to search : ");
    scanf("%d",&item);
    searchbst(root, item);

    printf("\nEnter element to search : ");
    scanf("%d",&item);
    searchbst(root, item);

}
node *create(node *root, int item)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->right = root->left = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if (item < root->data)
        {
            printf("%d inserted left of %d \n", item, root->data);
            root->left = create(root->left, item);
        }

        else if (item > root->data)
        {
            printf("%d inserted right of %d \n", item, root->data);
            root->right = create(root->right, item);
        }
        else
            printf("Duplicate Element is not allowed !!!");
        return root;
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
        n++;
    }
}
