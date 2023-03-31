#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left, *right, *parent;
    int data;
}node;
node *root, *new, *temp;

node *newnode()
{
    node *t;
    t = (node *)malloc(sizeof(node *));
    t->left = t->right = t->parent = 0;
    return t;
}

node *create_tree()
{
    int x;
    printf("Enter data (-1 for no data) : ");
    scanf("%d", &x);
    if (x == -1)
        return 0;
    new = newnode();
    new->data = x;
    printf("Enter left child of %d : ",x);
    new->left = create_tree();
    printf("Enter right child of %d : ",x);
    new->right = create_tree();
    printf("---  %p\n",new);
    return new;
    printf("%d, root->left");
}

// void display_tree(node * t)
// {
//     // temp = root;
//     if(t->data == -1)
//         return;
//     printf("%d   ",temp->data);
//     t = t->left;
//     display_tree(t);
//     t = t->right;
//     display_tree(t);
// }

int main()
{
    root = create_tree();
    printf("---  %d\n",root->data);
    // printf("%d  %d  %d", root->data, root->left->data, root->right->data);
    return 0;
    // display_tree(root);
}