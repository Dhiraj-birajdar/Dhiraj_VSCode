#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int visited[10];
struct n
{
    int data;
    struct n *link;
};

typedef struct n NODE;
struct stack
{
    int top;
    int item[MAX];
};
typedef struct stack STACK;
STACK *s;
NODE *h[20];
void initstack()
{
    s->top = -1;
}

void push(int data)
{
    ++s->top;
    s->item[s->top] = data;
}

int pop()
{
    return (s->item[s->top--]);
}

void accept(int n, int a[MAX][MAX])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\n Enter a[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int n, int a[MAX][MAX])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t %d ", a[i][j]);
        }
        printf("\n");
    }
}

void DFS(int n, int G, int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    for (j = 0; j < n; j++)
        if (!visited[j] && G[i][j] == 1)
            DFS(n, G, j);
}

NODE *getnode(int j)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = j;
    temp->link = NULL;
    return (temp);
}

NODE *findlast(NODE *h)
{
    NODE *ptr;
    for (ptr = h; ptr->link != NULL; ptr = ptr->link)
        ;
    return (ptr);
}

void displaylist(NODE *h[10], int n)
{
    NODE *ptr;
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n V%d ", i + 1);
        ptr = h[i];
        if (ptr == NULL)
            printf(" NULL");
        while (ptr != NULL)
        {
            printf(" -> %d", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}
void adjmat(int n, int a[MAX][MAX])
{
    NODE *ptr, *temp;
    int i, j;
    for (i = 0; i < n; i++)
        h[i] = NULL;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                temp = getnode(j + 1);
                if (h[i] == NULL)
                    h[i] = temp;
                else
                {
                    ptr = findlast(h[i]);
                    ptr->link = temp;
                }
            }
        }
    }
    printf("\n The Adjacency list looks like ... \n");
    displaylist(h, n);
}

void main()
{
    int i, ver, matric[MAX][MAX];
    printf("\n\t\t\t Enter the no. of vertex ");
    scanf("%d", &ver);
    accept(ver, matric);
    printf("\nAdjacency matrix:- \n");
    display(ver, matric);
    adjmat(ver, matric);
    for (i = 0; i < ver; i++)
        visited[i] = 0;
    dfs(ver, matric, 0);
    //	bfs(ver,matric);
}
