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

void insertAfterNode(int pos, int x)
{
    struct node *temp;
    
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = NULL;

    temp = head;

    for (int i = 1; i < pos; i++)
    {
        if (temp != NULL)
        {
            temp=temp->next;
        }
    }

    if (temp != NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return;
}

int getPos(int val)
{
    int pos = 0;
    struct node *ptr = head;
    
    while(ptr != NULL)
    {
                pos++;

        if (ptr->data == 50)
            break;
        ptr = ptr->next;
    }
    return pos;
}

void deleteAt(int pos)
{
    if (head == NULL)
    {
        return;
    }
    struct node *pre, *temp, *ptr;
    ptr = head;
    pre = ptr;

    for (int i = 1; i < pos; i++)
    {
        pre = ptr;
        ptr = ptr->next;
    }

    temp = ptr;
    pre->next = ptr->next;
    free(temp);
}

int main()
{
    printf("Enter the no. of nodes: ");
    int n;
    scanf("%d", &n);
    createList(n);
    printf("Printing the list: \n");
    print();
    printf("Inserting a node after the node 50: \n");
    insertAfterNode(getPos(50), 65);
    print();
    printf("List after deleting the node with value 10: \n");
    deleteAt(getPos(10));
    print();
    printf("\nPosition or index of deleted element: %d\n", getPos(10));
    return 0;
}