#include <stdio.h>
#include <stdlib.h>

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

void occurences(int val)
{
    struct node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        if (ptr->data == val)
            count++;
    }

    printf("there are %d occurences of %d\n", count, val);
}

void removeLastOccurence()
{
    struct node *ptr = head;
    struct node *next = NULL, *prev = NULL;

    while (ptr != NULL)
    {
        prev = ptr;
        next = ptr->next;

        while (next != NULL)
        {
            if (ptr->data == next->data)
            {
                prev->next = next->next;
            }
            else
            {
                prev = next;
            }
            next = next->next;
        }
        ptr = ptr->next;
    }
}

void removeAllOccurences()
{
    struct node *dummy = (struct node *)malloc(sizeof(struct node));
    dummy->next = head;

    struct node *prev = dummy;
    struct node *ptr = head;

    while (ptr != NULL)
    {
        while (ptr->next != NULL && prev->next->data == ptr->next->data)
            ptr = ptr->next;

        if (prev->next == ptr)
            prev = prev->next;
        else
            prev->next = ptr->next;
        ptr = ptr->next;
    }

    head = dummy->next;
}

int main()
{
    createList(5);
    removeAllOccurences();
    print();
    return 0;
}