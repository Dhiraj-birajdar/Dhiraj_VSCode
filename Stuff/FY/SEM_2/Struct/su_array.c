#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[20];
    float percentage;
};

int main()
{
    struct student fybcs[3]/*={{1,"absd",443},{2,"dsf",43},{3,"hh",53}}*/;
    struct student fy={1,"absd",443}/*={{1,"absd",443},{2,"dsf",43},{3,"hh",53}}*/;
    // fybcs[0]={1,"absd",443};
    fybcs[0].id=23;
    // fybcs[0]={1,"akash",56};
    // for (int i = 0; i < 20; i++)
    // {
    //     fybcs[i].id = i+101;
    //     strcpy(fybcs[i].name, "akash");
    //     fybcs[i].percentage = (rand()/(i+1)) ;
    // }

    // printf("enter name\n");
    // gets(record.name);
    int i=0;
    printf(" sid  name    \%\n");
while (i<3)
{
    printf("%5d  %s   %.2f\n",fybcs[i].id,fybcs[i].name,fybcs[i].percentage);
    i++;
}


    return 0;
}

// #include <stdio.h>
// #include <string.h>
// typedef struct student
// {
//     int id;
//     char name[20];
//     float percentage;
// } record;

// int main()
// {
//     // struct student record={0};
//     record fybcs[20];
//     fybcs[0]={3,"dhiraj",88.44};

//     // printf("enter name\n");
//     // gets(record.name);

//     printf("student id = %d\n",id.id);
//     printf("student name = %s\n",id.name);
//     printf("student \% = %.2f\n",id.percentage);
//     return 0;
// }