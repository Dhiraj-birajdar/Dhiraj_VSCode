#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left, *right;
} node;
node *createtree(int);
void inorder(node*);
char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0', '\0', 'h'};
int lc[] = {1, 3, 5, -1, 9, -1, -1, -1, -1, -1};  
int main()
{
    
    return 0;
}