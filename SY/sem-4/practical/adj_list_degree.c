/* Write a C program that accepts the vertices and edges of a graph. Create adjacency list. Implement functions to print indegree, outdegree and total degree of all vertex of graph. */
#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE node;
node *list[10];
int nov;
node *getnodenum(int vno)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = vno;
    temp->next = NULL;
    return temp;
}
void display(node *list[10])
{
    int i;
    node *ptr;
    for (i = 0; i < nov; i++)
    {
        printf("V%d  ", i + 1);
        for (ptr = list[i]; ptr != NULL; ptr = ptr->next)
            printf("%d->", ptr->data);
        printf("NULL");
        printf("\n");
    }
}
void creatadjacencylist()
{
    int i, j;
    char ch;
    node *temp, *last;
    for (i = 0; i < nov; i++)
        list[i] = NULL;
    for (i = 0; i < nov; i++)
    {
        for (j = 0; j < nov; j++)
        {
            printf("\nIs there edge between V[%d] and V[%d] (choose : y/n): ", i + 1, j + 1);
            scanf(" %c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                temp = getnodenum(j + 1);
                if (list[i] == NULL)
                    list[i] = temp;
                else
                {
                    for (last = list[i]; last->next != NULL; last = last->next)
                        ;
                    last->next = temp;
                }
            }
        }
    }
}
void degree()
{
    int i, cnt, outcnt[10], incnt[10] = {0};
    node *ptr;
    for (i = 0; i < nov; i++)
    {
        for (ptr = list[i], cnt = 0; ptr != NULL; ptr = ptr->next, cnt++)
            incnt[ptr->data] += 1;
        outcnt[i + 1] = cnt;
    }
    printf("\nVertex\t   Indegree\t   Outdegree\t  Totaldegree");
    for (i = 1; i <= nov; i++)
        printf("\nV%d \t\t %d \t\t %d \t\t %d", i, incnt[i], outcnt[i], incnt[i] + outcnt[i]);
}
int main()
{
    int i, j, a[20][20];

    printf("\nEnter no. of vertices: ");
    scanf("%d", &nov);

    creatadjacencylist();
    printf("\n******Adjacency List*******\n");
    display(list);
    degree();
    return 0;
}
