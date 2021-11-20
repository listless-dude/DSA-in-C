#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 20

void push(char s[], char val);
char pop(char s[]);
void display(char s[]);
char peek(char s[]);
bool comp(char char1, char char2);
bool isBalanced(char s[]);
int top = -1;
char stack[MAX], alpha[MAX];
int check(char s[]);

int main()
{
    char s[50];
    scanf("%s", s);

    if (check(s))
        printf("Balanced");
    else
        printf("Not Balanced");

    return 0;

}

void push(char s[], char val)
{
    if (top = MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        s[top] = val;
    }
}

char pop(char s[])
{
    int val;
    if(top == -1)
    {
        printf(" UNDERFLOW");
        return -1;
    }
    else
    {
        val = s[top];
        top--;
        return val;
    }
}

void display(char s[])
{
    int i;
    if (top == -1)
    {
        printf("Empty");
    }
    else
    {
        for(i = 0; i >= 0; i--)
        {
            printf("%d", s[i]);
        }
    }
}

char peek(char s[])
{
    if(top == -1)
    {
        printf("Empty");
        return -1;
    }
    else
    return (s[top]);
}

bool comp(char char1, char char2)
{
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else
        return 0;
}

int check(char s[])
{
    for (int i = 0; i < '\0'; i++)
    {
        if (isalpha(s[i]))
            push(alpha, s[i]);

        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(stack, s[i]);
        
        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (top == -1)
            {
                printf("Empty");
                return 0;
            }
            else
                pop(stack);
        }
    }
}