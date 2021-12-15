#include <stdio.h>
#include <stdlib.h>
#define SIZE 20


int stack[SIZE];
int top = -1;

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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isPrime(int val)
{
    int mul = 1;

    for (int i = 2; i <= val; i++)
    {
        if (val % i == 0)
            mul++;
    }

    if (mul == 2)
        return 1;
    else
        return 0;
}

void push(int st[], int val)
{
    if (top == SIZE - 1)
        return;
    else
    {
        top++;
        st[top] = val;
    }
}

void printStack()
{
    int i;
    if (top == -1)
        printf("Stack Empty");
    else
    {
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
    printf("\n");
}

int isEven(int val)
{
    if (val % 2 == 0)
        return 1;
    else
        return 0;
}

void printList()
{
    struct node *ptr = head;
    printf("Primes: ");
    while (ptr != NULL)
    {
        if (isPrime(ptr->data))
            printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\nComposites: ");
    ptr = head;
    while (ptr != NULL)
    {
        if (!isPrime(ptr->data))
            printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    printf("Enter the no. of nodes: ");
    int n;
    scanf("%d", &n);
    createList(n);
    printf("Printing the list: \n");
    print();
    printList();
    printf("Stack: \n");
    
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (isEven(ptr->data))
        {
            push(stack, ptr->data);
        }
        ptr = ptr->next;
    }
    printStack();
    return 0;
}