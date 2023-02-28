#include <stdio.h>
#define sqr(n) n*n
#define cube(n) n*n*n
typedef struct employee
{   
    // char f;
    // char ds;
    int eid;
    char ename[20];
}emp;

int main()
{
    emp e1={121,"sundar"}/*,*p=&e1*/,*p,e2={323,"satya"},*p2=&e2;
    // e2={212,"dskfsd"};
    p=&e1;
    // e2={1,"fgh"};
    printf("empid = %d\nempname = %s\n",p->eid,p->ename);
    printf("empid = %d\nempname = %s\n",(*p).eid,(*p).ename);
    printf("sqr = %d\n",sqr(5));
    printf("sqr = %d\n",cube(5));
    printf("size of e1 = %d",sizeof(e1));    // structure padding
    return 0;
}