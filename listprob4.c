#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int evenStack[MAX], oddStack[MAX];
int top1 = -1, top2 = -1;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int n)
{
    struct node *ptr, *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        return;
    
    int data;
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;

    head = newnode;
    ptr = head;

    for (int i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
            break;

        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        ptr->next = newnode;
        ptr = ptr->next;
    }

    return;
}

void print()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int isEven(int val)
{
    if (val % 2 == 0)
        return 1;
    else 
        return 0;
}

int isOdd(int val)
{
    if (val % 2 != 0)
        return 1;
    else 
        return 0;
}

void pushEven(int st[], int val)
{
    if (top1 == MAX - 1)
        return;
    else
    {
        top1++;
        st[top1] = val;
    }
}

void pushOdd(int st[], int val)
{
    if (top2 == MAX - 1)
        return;
    else
    {
        top2++;
        st[top2] = val;
    }
}

int popEven(int st[])
{
    int val;
    if(top1 == -1)
        return -1;
    else
    {
        val = st[top1];
        top1--;
        return val;
    }
}

int popOdd(int st[])
{
    int val;
    if(top2 == -1)
        return -1;
    else
    {
        val = st[top2];
        top2--;
        return val;
    }
}

void evaluate()
{
    struct node *ptr = head;

    for (int i = 1; i <= 8; i++)
    {
        if (isEven(ptr->data))
        {
            pushEven(evenStack, ptr->data);
        }
        else
        {
            pushOdd(oddStack, ptr->data);
        }
        ptr = ptr->next;
    }
}

void finalList()
{
    struct node *ptr = head;

    for (int i = 1; i <= 8; i++)
    {
        if (isEven(i))
            ptr->data = popEven(evenStack);
        else
            ptr->data = popOdd(oddStack);
        
        ptr = ptr->next;
    }
}

void getnLast(int pos)
{
    struct node *ptr = head;

    for (int i = 0; i < pos-1; i++)
    {
        ptr = ptr->next;
    }

    printf("The %dth last element: %d\n", pos, ptr->data);
}

void display()
{
    int i;
    if (top1 == -1)
    {
        printf("Empty");
        return;
    }
    else
    {
        for(i = top1; i >= 0; i--)
        {
            printf("%d", evenStack[i]);
        }
    }
}

void display2()
{
    int i;
    if (top2 == -1)
    {
        printf("Empty");
        return;
    }
    else
    {
        for(i = top2; i >= 0; i--)
        {
            printf("%d", oddStack[i]);
        }
    }
}

int main()
{
    printf("Enter 8 elements: \n");
    createList(8);
    print();
    evaluate();
    finalList();
    print();
    // display();
    // printf("\n");
    // display2();
    return 0;
}