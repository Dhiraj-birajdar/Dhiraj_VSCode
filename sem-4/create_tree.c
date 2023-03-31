#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left, *right;
    int data;
}node;
node *root, *new, *temp;

node *newnode()
{
    node *t;
    t = (node *)malloc(sizeof(node *));
    t->left = t->right = 0;
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
    if (x == 1)
        temp = new;
    new->data = x;
    printf("Enter left child of %d : ",x);
    new->left = create_tree();
    printf("Enter right child of %d : ",x);
    new->right = create_tree();
    return new;
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
    root = temp;
    printf("\n======= %d",root->data);
    printf("\n ====== %d  %d  %d", root->data, root->left->data, root->right->data);
    // display_tree(root);
}