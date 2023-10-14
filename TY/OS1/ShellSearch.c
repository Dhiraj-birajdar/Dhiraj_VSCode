#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

char comm[100],*ptr;
char *args[10];
int tot_arg;
int search(char option,char *pattern,char *fname);
int main()
{
do
{
 printf("myshell$");
 getcomm();
 sep_arg();
 take_action();
}while(1);
}
sep_arg()
{
int i,j;
i=j=tot_arg=0;
args[tot_arg]=(char *)malloc(sizeof(char)*
20);
for(i=0;comm[i]!='\0';i++)
{
if(comm[i]==' ')
{
 args[tot_arg][j]='\0';
 tot_arg++;
 args[tot_arg]=(char 
*)malloc(sizeof(char)* 20);
 j=0;
}
else
{
 args[tot_arg][j]=comm[i];
 j++;
}
}
args[tot_arg][j]='\0';
return;
}
getcomm()
{
int len;
ptr=fgets(comm,80,stdin);
len=strlen(comm);
comm[len-1]='\0';
return;
}
take_action()
{
char str[100];
pid_t pid;
int status;
ptr=comm;
if(ptr==NULL)
 exit(0);
if(strlen(comm)<=1)
 return;
if(strcmp(args[0],"search")==0)
 search(* args[1],args[2],args[3]);
else
if((pid=fork())<0)
{
 printf("\n unable to create the process");
}
else
if(pid==0)//child
{
 execvp(args[0],args);
 strcpy(str,"./");
 strcat(str,args[0]);
 execvp(str,args);
 printf("\n %s:command not found",comm);
 exit(0);
}
else 
waitpid(pid,&status,0);
}
int search(char option,char *pattern,char *fname)
{
char buff[100],*ptr;
int cnt;
FILE *fp;
int i;
fp=fopen(fname,"r");
if(fp==NULL)
{
 printf("\n unable to open the file");
 exit(0);
}
switch(option)
{
case 'a':
 while(!feof(fp))
 {
 buff[0]='\0';
 fgets(buff,80,fp);
 ptr=strstr(buff,pattern);
 if(ptr!=NULL)
 printf("%s",buff);
 }
 fclose(fp);
 break;
case 'c':
 cnt=0;
 while(!feof(fp))
 {
 buff[0]='\0';
 fgets(buff,80,fp);
 ptr=strstr(buff,pattern);
 while(ptr!=NULL)
 {
 cnt++;
ptr=ptr+strlen(pattern);
 
ptr=strstr(ptr,pattern);
 }
 }
 fclose(fp);
printf("\n the search string %s occures %d times\n",pattern,cnt);
 break;
case 'f':
 while(!feof(fp))
 {
 buff[0]='\0';
 fgets(buff,80,fp);
 ptr=strstr(buff,pattern);
 if(ptr!=NULL)
 {
 printf("%s",buff);
break;
 }
 }
 fclose(fp);
 break;
}
return;
}
//end