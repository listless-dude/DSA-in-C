/*
Write a C program to convert an infix string to postfix. Name the function for converting the 
infix string to postfix as postfix.
*/

#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>

// creating a stack to temporarily store operators
#define MAX 50
char stack[MAX];
int top = -1;

void push(char st[], char data);
char pop(char st[]);
void infixToPostfix(char x[], char y[]);
int priority(char s);

// pushes value to stack
void push(char st[], char data)
{
    if(top == MAX - 1)
        printf("Overflow");
    else
    {
        top++;
        stack[top] = data;
    }
}

// pops a char from stack
char pop(char st[])
{
    char data; // creating a empty char literal
    if(top == -1)
        printf("Underflow");
    else
    {
        data = stack[top];
        top--;
    }
    return data;
}

// checks the precedence order of the operators
int priority(char s)
{
    if (s == '^')
        return 3;
    else if(s == '/' || s == '*' || s == '%')
        return 2;
    else if(s == '+' || s == '-')
        return 1;
    else
        return 0; 
}

// performs conversion from infix to postfix
void postfix(char x[], char y[])
{
    int i = 0, j = 0;
    char temp; // to store pop value of '('

    // scan till the null character of input x
    while(x[i] != '\0')
    {
        if(x[i] == '(')
        {
            push(stack, x[i]);
            i++;
        }
        else if (x[i] == ')')
        {
            // pop from stack till '(' and push to y
            while((top != -1) && (stack[top] != '('))
            {
                y[j] = pop(stack);
                j++;
            }
            if (top == -1)
            {
                printf("Invalid Expression\n");
                exit(1);
            }
            temp = pop(stack); // remove '('
            i++;
        }
        else if(isalnum(x[i])) // checks if its alphanumeric
        {
            // push to y
            y[j] = x[i];
            j++;
            i++;
        }
        else if(x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/' || x[i] == '%' || x[i] == '^')
        {
            // pop till '(' and checking priority of operators
            while((top != -1) && (stack[top] != '(') && (priority(stack[top]) >= priority(x[i])))
            {
                y[j] = pop(stack);
                j++;
            }
            push(stack, x[i]);
            i++;
        }
        else
        {
            printf("Invalid Expression \n");
            exit(1);
        }
    }
    // push the remaining characters in stack to y
    while ((top != -1) && (stack[top] != '('))
    {
        y[j] = pop(stack);
        j++;
    }
    y[j] = '\0'; // adding null character
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Input: ");
    scanf("%s", &infix);

    postfix(infix, postfix);
    printf("Output: %s", postfix);
    return 0;
}