typedef struct stack
{
	int data[200];
	int top;
}stack;
void push(stack *ps,int num)
{
	ps->data[++ps->top]=num;
}
int pop(stack *ps)
{
	int num;
	num=ps->data[ps->top--];
	return num;
}
int isempty(stack *ps)
{
	if(ps->top==-1)
	return 1;
	return 0;
}
int isfull(stack *ps)
{
	if(ps->top==20-1)
	return 1;
	return 0;
}
int peek(stack *ps)
{
	return ps->data[ps->top];
}
void init(stack *ps)
{
	ps->top=-1;
}
