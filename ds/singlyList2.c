#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void createNode(int n);
void traverse();
void insertAfterNode(int pos, int x);
void insertBeforeNode(struct node *head);
void deleteAt(struct node *ref, int pos);
void reverse(struct node *head);
bool search(int x);
int node70 = 0;

int main(void)
{
    int n = 10;
    createNode(10);

    int option = 0;
    
    while (option != 4)
    {
        printf("Enter 1 for inserting after a node\n");
        printf("Enter 2 for inserting before a node\n");
        printf("Enter 3 for deleting at a given position of node\n");
        printf("Enter 4 for reversing a node\n");

        scanf("\n%d", &option);
        switch (option)
        {
        case 1:
            printf("Inserting after 5th node with value 404\n");
            insertAfterNode(5, 404);
            traverse();
            printf("\n");
            break;
        case 2:
            printf("Enter the data to be inserted in a node before the node with value 70\n");
            insertBeforeNode(head);
            traverse();
            printf("\n");
            break;
        case 3:
            printf("Deleting the 5th node\n");
            deleteAt(head, 5);
            traverse();
            printf("\n");
            break;
        case 4:
            printf("Reversing a node\n");
            reverse(head);
            printf("\n");
            break;
        default:
            printf("Enter a valid number\n");
            break;
        }
    }
    
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

    printf("Enter data for 10 Nodes : ");
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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    return;
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

void insertBeforeNode(struct node *head)
{
    struct node *newnode, *ptr, *pre;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (search(70))
    {
        scanf("%d", &newnode->data);
        ptr = head;

        for (int i = 1; i < node70; i++)
        {
            pre = ptr;
            ptr = ptr->next;
        }
        pre->next = newnode;
        newnode->next = ptr;
    }
    else
    {
        printf("The num 70 is not present in the list");
    }
}

void deleteAt(struct node *ref, int pos)
{
    if (ref == NULL)
    {
        return;
    }
    struct node *pre, *temp, *ptr;
    ptr = ref;
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

void reverse(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    reverse(head->next);
    printf("%d -> ", head->data);
}

bool search(int x)
{
    struct node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            node70 = i;
            return true;
        }
        temp = temp->next;
        i++;
    }
    return false;
}
