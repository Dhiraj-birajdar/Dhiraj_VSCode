#include <stdio.h>
#include<stdlib.h>
/*
int main()
{
    int i,j,k;
    for(i=1;i<4;i++)
        if(i<4)
            for(j=1;j<4;j++)
                if(i<4)
                    for(j=1;j<4;j++)
                        printf("1  %d\n",i);
}
*/

/* selection sort */
// void display(int *a,int n){int i;for(i=0;i<n;i++)printf("%d  ",a[i]);}void selection(int *a,int n){int i,j,t,m;printf("Before selection sort : ");display(a,n);for(i=0;i<n;i++){m=i;for(j=i+1;j<n;j++)if(a[j]<a[m])m=j;if(m!=i){t=a[i];a[i]=a[m];a[m]=t; }}printf("\nAfter selection sort : ");display(a,n);}void main(){int a[]={5,4,3,2,1},n=5;selection(a,n);}

/* bubble sort from file */
//typedef struct emp{char ename[20];int age;int sal;}emp;emp e[100];int readfile();void bubblesort(int);void display(int);void writefile(int);void main(){int n;n=readfile();bubblesort(n);printf("\n *************** After sort *************** \n");display(n);writefile(n);}int readfile(){char fname[20]="t.txt";int i=0;FILE *fp;/* printf("Enter file name : ");scanf("%s",fname);*/fp=fopen(fname,"r");if(fp==NULL){printf("error"); exit(0);}while (!feof(fp)){fscanf(fp,"%s%d%d",e[i].ename,&e[i].age,&e[i].sal);printf("\n%-5s  %d  %d   i= %d",e[i].ename,e[i].age,e[i].sal,i);++i;}return i;}void bubblesort(int n){int p,j;emp t;for(p=1;p<n;p++){for(j=0;j<n-p;j++){if(e[j].sal>e[j+1].sal){t=e[j];e[j]=e[j+1];e[j+1]=t;}}}}void display(int n){int i;for(i=0;i<n;i++)printf("\n%-5s  %d  %d",e[i].ename,e[i].age,e[i].sal);}void writefile(int n){char fname[20]="st.txt";int i=0;FILE *fp;/* printf("Enter file name : ");scanf("%s",fname);*/fp=fopen(fname,"w");if(fp==NULL){printf("error");exit(0);}for(i=0;i<n;i++){fprintf(fp,"%-10s  %d  %d\n",e[i].ename,e[i].age,e[i].sal);}}
