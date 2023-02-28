#define MAX 100
struct stack
{
    int top;
    char item[MAX];
};
typedef struct stack STACK;
void initstack(STACK *s)
{
    s->top = -1;
}
int isempty(STACK *s)
{
    if (s->top == -1)
        return (1);
    else
        return (0);
}
int isfull(STACK *s)
{
    if (s->top == MAX - 1)
        return (1);
    else
        return (0);
}
void push(STACK *s, char data)
{
    ++s->top;
    s->item[s->top] = data;
}
char pop(STACK *s)
{
    return (s->item[s->top--]);
}