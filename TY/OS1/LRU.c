/*Program for lru*/
#include<stdio.h>
struct frmnode
{
int pno,counter;
}
frames[20];
int n;
int page_found(int pno)
{
int fno;
for(fno=0;fno<n;fno++)
{
if(frames[fno].pno==pno)
return fno;
}
return -1;
}
int get_free_frame()
{
int fno;
for (fno=0; fno<n; fno++)
{
if (frames[fno].pno==-1)
return(fno);
}
return(-1);
}
int get_lru_Frame()
{
int lrufno=0,fno;
for (fno=1; fno<n; fno++)
{
if(frames[fno].counter<frames[lrufno].counter)
lrufno=fno;
}
return lrufno;
}
void main()
{
int p_request[]={12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
int size=sizeof(p_request)/4,currtime;
int page_falts=0,i,j,fno;
//clrscr();
printf("\nHow many frames:");
scanf("%d",&n);
//initialize frames
for (i=0; i<n; i++)
{
frames[i].pno=-1;
}
printf("\nPageNo Page Frames Page Fault");
printf("\n---------------------------------------------------");
currtime=0;
for(i=0;i<size;i++)
{
j=page_found(p_request[i]);
if(j==-1) //page fault occurs
{
j=get_free_frame();
if (j==-1) //no free frame - do replacement
j=get_lru_Frame();
page_falts++;
frames[j].pno=p_request[i];
frames[j].counter=currtime;
printf("\n%4d\t ",p_request[i]);
for (fno=0; fno<n; fno++)
printf("%4d:%2d",frames[fno].pno,frames[fno].counter);
printf(" : YES");
}
else//page found
{
frames[j].counter=currtime;
printf("\n%4d\t ",p_request[i]);
for (fno=0; fno<n; fno++)
printf("%4d:%2d",frames[fno].pno,frames[fno].counter);
printf(" : NO");
}//else
currtime++;
}//for
printf("\n------------------------------------------");
printf("\n Number of Page_Falts=%d",page_falts);
//getch();
}