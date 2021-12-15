#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *head2 = NULL, *merge = NULL;

void createList1(int n)
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

void createList2(int n)
{
    struct node *ptr, *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        return;
    
    int data;
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;

    head2 = newnode;
    ptr = head2;

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

void print(struct node *st)
{
    struct node *ptr = st;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertAtEnd(int data)
{
    if (merge == NULL)
    {
        merge = (struct node *)malloc(sizeof(struct node));
        merge->data = data;
        merge->next = NULL;
    }
    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
            printf("Overflow");
            
        struct node *ptr = merge;
    
        newnode->data = data;
        newnode->next = NULL;
        
        while (ptr->next != NULL)
            ptr = ptr->next;
        
        ptr->next = newnode;
    }
    return;
}

void mergeList()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head2;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    createList1(n);
    createList2(m);
    print(head);
    return 0;
}