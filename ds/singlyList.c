#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
}*head;
void createNode(int n);
void traverse();
int count();
bool search(int x);
void insertBegin(int x);
void insertEnd(int x);
void insertAtNode(struct node *prevnode, int x);
void deletefirst();
void deleteAt(struct node **ref, int key);
int main(void)  
{
    int n, searchVal, insert, delete;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createNode(n);
    traverse();
    count();
    printf("Enter a value to be searched: ");
    scanf("%d", &searchVal);
    search(searchVal) ? printf("Found") : printf("Not found");

    printf("\nEnter a value to inserted: ");
    scanf("%d", &insert);
    insertBegin(insert);
    insertEnd(insert);
    insertAtNode(head->next, insert);
    printf("\nAfter inserting elements at the beginning, end and after 2 places\n");
    traverse();
    deletefirst();
    printf("\nAfter deletion of the first node: \n");
    traverse();
    printf("Enter the value node to be deleted\n");
    scanf("%d", &delete);
    deleteAt(&head, delete);
    traverse();
    return 0;
}

void createNode(int n)
{
    struct node *newnode, *tmp;
    int data;

    head = (struct node *)malloc(sizeof(struct node));
    
    if (head == NULL)
    {
        printf("Unable to allocate memory. \n");
        return;
    }

    printf("Enter data for Node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    tmp = head;
    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Unable to allocate memory. \n");
            break;
        }

        printf("Enter data for Node %d: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        tmp->next = newnode;
        tmp = tmp->next;
    }
    return;
}

void traverse()
{
    struct node *temp;
    
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
    return;
}

int count()
{
    int count = 0;
    struct node *temp;

    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return printf("Total Number of nodes is %d\n", count);
}

bool search(int x)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void insertBegin(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Overflow");
        exit(0);
    }
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    return;
}

void insertEnd(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Overflow");
        exit(0);
    }

    struct node *temp = head;

    newnode->data = x;
    newnode->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    return;
}

void insertAtNode(struct node *prevnode, int x)
{
    if (prevnode == NULL)
    {
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = prevnode->next;
    prevnode->next = newnode;
    return;
}

void deletefirst()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
    return;
}

void deleteAt(struct node **ref, int key)
{
    struct node *temp = *ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}