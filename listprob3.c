#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int even[MAX], odd[MAX], evenC = 0, oddC = 0;

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

void bubbleSort(int A[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j+1])
            {
                // swap
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
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

void oddEvenInsert()
{
    struct node *ptr = head;
    int j = 0, k = 0;
    for (int i = 0; i < 8; i++)
    {
        if (isEven(ptr->data))
        {
            even[j] = ptr->data;
            evenC++;
            j++;
        }
        else
        {
            odd[k] = ptr->data;
            oddC++;
            k++;
        }
        ptr = ptr->next;
    }
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter 8 elements: \n");
    createList(8);
    print();
    oddEvenInsert();
    bubbleSort(even, evenC);
    bubbleSort(odd, oddC);

    struct node *ptr = head;
    int j = 0;
    for (int i = 0; i < 8; i++)
    {
        if (i < oddC)
            ptr->data = odd[i];
        else
        {
            ptr->data = even[j];
            j++;
        }
        ptr = ptr->next;
    }
    print();
    return 0;
}