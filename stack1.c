#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 20

int top = -1, top2 = -1;
int stack[MAX], alpha[MAX];

void push(int val)
{
    if (top == MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

int pop()
{
    int val;
    if(top == -1)
    {
        printf(" UNDERFLOW");
        return -1;
    }
    else
    {
        val = stack[top];
        top--;
        return val;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Empty");
    }
    else
    {
        for(i = top; i >= 0; i--)
        {
            printf("%d", stack[i]);
        }
    }
    printf("\n");
}

void push2(int val)
{
    if (top2 == MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        top2++;
        alpha[top2] = val;
    }
}

void display2()
{
    int i;
    if (top2 == -1)
    {
        printf("Empty");
    }
    else
    {
        for(i = top2; i >= 0; i--)
        {
            printf("%d", alpha[i]);
        }
    }
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    while (top != -1)
    {
        push2(pop());
    }
    display();
    display2();
    return 0;
}