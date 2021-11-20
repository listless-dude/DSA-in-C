#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

#define MAX 30 //set the max value for stacks

int top = -1, top2 = -1; // for two different stacks 
int stack[MAX]; // the parenthesis stack
char alphastack[MAX]; // the alphabets stack

void push(int [], char); // push to stack
void push2(char [], char); // push to alphastack
char pop(); // pop from stack
int check(char []); // condition for balanced or unbalanced parenthesis
void reversePrint(char st[]); // reverse print the alphabet

int main()
{
        char s[MAX];
        printf("Input = ");
        gets(s);

        if(check(s))
        {
            printf("Output = Balanced\n");
            reversePrint(alphastack);
        }
        else
            printf("Output = Unbalanced\n");
        
        return 0;
}

int check(char s[] )
{
        for(int i = 0; i < strlen(s); i++)
        {
                if (isalpha(s[i]))
                {
                        push2(alphastack, s[i]);
                }
                
                if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                        push(stack, s[i]);
                
                if(s[i] == ')' || s[i] == '}' || s[i] == ']')
                {
                        if(top == -1) 
                        {
                                return 0;
                        }
                        else
                        {
                                pop();
                        }
                }
        }
        if(top == -1)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

void push(int st[], char val)
{
        if(top == (MAX - 1))
        {
                printf("Stack Overflow\n");
                return;
        }
        top++;
        st[top] = val;
}

void push2(char st[], char val)
{
        if(top2 == (MAX - 1))
        {
                printf("Stack Overflow\n");
                return;
        }
        top2++;
        st[top2] = val;
}

char pop()
{
        if(top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        return stack[top--];
}

char pop2()
{
        if(top2 == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        return alphastack[top2--];
}

void reversePrint(char st[])
{    
        char val;
        char arr[MAX];
        if(top2 == -1)
                printf("Empty Stack");
        else
        {
                for(int i = 0; i < strlen(st); i++)
                {
                        val = pop2();
                        arr[i] = val;
                }
                for (int i = 0; i < strlen(st); i++)
                {
                        printf("%c ", arr[i]);
                }
        }
}