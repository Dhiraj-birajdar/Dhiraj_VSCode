#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=NULL,*temp,*new;
int main()
{
    int n,i,nzero,odd,even;
    nzero=odd=even=0;
    printf("\nEnter no of nodes : ");
    scanf("%d",&n);
    printf("\nEnter %d elements : ",n);
    for(i=0;i<n;i++)
    {
        new=(node*)malloc(sizeof(node));
        scanf("%d",&new->data);
        new->next=NULL;
        if(!head)
            head=new;
        else
        {
            for(temp=head;temp->next;temp=temp->next);
            temp->next=new;
        }
    }
    for(temp=head;temp;temp=temp->next)
    {
        if(temp->data!=0)
            nzero++;
        if(temp->data%2==0)
            even++;
        if(temp->data%2!=0)
            odd++;
    }
    printf("\nNon zero elements = %d\nEven numbers = %d\nOdd numbers = %d",nzero,even,odd);
    return 0;
}