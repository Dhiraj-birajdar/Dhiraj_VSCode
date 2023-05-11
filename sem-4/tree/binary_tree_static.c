#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data;
    struct node *left, *right;
} node;

node *insert(char c[], int n)
{
    node *tree = NULL;
    if (c[n] != '\0')
    {
        tree = (node *)malloc(sizeof(node));
        tree->left = insert(c, 2 * n + 1);
        tree->data = c[n];
        tree->right = insert(c, 2 * n + 2);
    }
    return tree;
}

void inorder(node *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%c\t", tree->data);
        inorder(tree->right);
    }
}

int main()
{
    node *tree = NULL;
    char c[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0', 'g', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    tree = insert(c, 0);
    inorder(tree);
    return 0;
}