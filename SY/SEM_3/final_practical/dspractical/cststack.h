void reversestack(char *s)
{
	char stack[100];
	int top=-1,i;
	for(i=0;s[i]!='\0';i++,top++)
		stack[i]=s[i];
	for(i=0;top!=-1;i++,top--)
		s[i]=stack[top];
}