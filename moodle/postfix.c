#include <stdio.h>

#define MAX 50

int push(int);

int pop();

char postfix[MAX], c;
int stack[MAX];
int top = -1, i = 0;

int push(int data)
{
    stack[++top] = data;
    return 0;
}
int res;
int pop()
{
    return (stack[top--]);
}

int main()
{
    int x, y;
    scanf("%[^\n]s", postfix);
    while ((c = postfix[i++]) != '\0')
    {
        if (c == ' ')
            continue;
        
        if (c >= '0' && c <= '9')
            push(c - '0'); // ascii
        else
        {
            x = pop();
            y = pop();
            
            switch(c)
            {
                case '+':
                    push(x + y);
                    break;
                case '-':
                    push(y-x);
                    break;
                case '*':
                    push(x*y);
                    break;
                case '/':
                    push(x/y);
                    break;
            }
        }
    }
    printf("%d", stack[top]);
    return 0;
}