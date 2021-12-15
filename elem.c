#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
char number(char);
 
char operator(char);
 
int push(int);
 
int execute(char, int, int);
 
int pop();
 
char postfix[25], c;
 
int res, o1, o2, element;
 
int stack[40];
 
int top = -1, i=0;
 
int push(int element)
{
    stack[++top]=element;
 
    return 0;
}
 
int pop()
{
    return (stack[top--]);
}
 
char operator(char c)
{
    if(c == '+' || c == '-' || c == '*'|| c == '/')
    {
        return c;
    }
}
 
char number(char c)
{
    if(c >='0' && c <='9')
    {
        return c;
    }
}
 
int execute(char c, int o1, int o2)
{
    if(c == '+')
    {
        res = o1 + o2;
    }
 
    else if(c == '-')
    {
        res = o1 - o2;
    }
 
    else if(c == '*')
    {
        res = o1 * o2;
    }
 
    else if(c == '/')
    {
        res = o1 / o2;
    }
 
    return res;
}
 
void main()
{
    printf("enter postfix expression:");
 
    scanf("%[^\n]s", postfix);
    while((c = postfix[i++]) != '\0')
    {
        if(c == ',' || c == ' ')
        {
            continue;
        }
 
        if(c >= '0' && c <= '9')
        {
            push(c -'0');
        }
        else
        {
            o2 = pop();
 
            o1 = pop();
 
           switch(c)
           {
               case '+':push(o1+o2);break;
 
               case '-':push(o1-o2);break;
 
               case '*':push(o1*o2);break;
 
               case '/':push(o1/o2);break;
           }
        }
    }
 
    printf("result = %d\n", stack[top]);
}