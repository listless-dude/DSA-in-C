#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    char *s;
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *createNode(char *s, int data); 
void display();
void insertAt(int pos);
void insertEnd();
void deleteLast();
void reverse(); 
void deleteAt(int pos);
void insertAtBegin();
int count();
int nodecount = 0;

int main()
{

    head = createNode("abc", 200);
    createNode("def", 300);
    createNode("ghij", 250);
    display();

    printf("\nEnter 1: Insertion of a node at the last\n");
    printf("Enter 2: Deletion of last node\n");
    printf("Enter 3: Insertion at a specific position\n");
    printf("Enter 4: Deletion from a specific position\n");
    printf("Enter 5: Print the list in reverse direction\n");

    int choice, pos, pos1;
    
    while(choice != 0) {
        nodecount = 0;
        count();
        printf("Input: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insertEnd();
                display();
                printf("\n");
                break;
            case 2:
                deleteLast();
                display();
                printf("\n");
                break;
            case 3:
                scanf("%d", &pos);
                if (pos == 1)
                    insertAtBegin(); 
                else 
                    insertAt(pos);
                display();
                printf("\n");
                break;
            case 4:
                scanf("%d", &pos1);
                if (pos1 == nodecount)
                    deleteLast();
                else
                    deleteAt(pos1);
                display();
                printf("\n");
                break;
            case 5:
                reverse();
                printf("\n");
                break;
            case 0:
                break;
            default:
                printf("Invalid input. No function with this serial.\n");
        }
    }
    return 0;
}

struct node *createNode(char *s, int data)
{
    struct node *newnode, *ptr;
    newnode = (struct node *) malloc(sizeof(struct node));

    newnode->data = data;
    newnode->s = malloc(strlen(s) + 1);
    strcpy(newnode->s, s);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        newnode->prev = NULL;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
    return head;
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("(%s, %d) ", ptr->s, ptr->data);
            ptr = ptr->next;
        }
    }
}

void insertAt(int pos)
{
    int data;
    char *s;
    s = malloc(sizeof(s));
    scanf("%s", s);
    scanf("%d",&data);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->s = malloc(strlen(s) + 1);
    strcpy(newnode->s, s);

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        printf("NULL\n");
    }

    struct node *ptr = head;

    for (int i = 1; i < pos; i++)
    {
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
    }

    newnode->prev = ptr->prev;
    newnode->next = ptr;
    ptr->prev->next = newnode;
    ptr->prev = newnode;
}

void insertAtBegin()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    int data;
    char *s;
    s = malloc(sizeof(s));
    scanf("%s", s);
    scanf("%d",&data);
    
    newnode->s = malloc(strlen(s) + 1);
    strcpy(newnode->s, s);
    newnode->data = data;

    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}

void insertEnd()
{
    int data;
    char *s;
    s = malloc(sizeof(s));
    scanf("%s", s);
    scanf("%d", &data);

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->s = malloc(strlen(s) + 1);
    strcpy(newnode->s, s);

    newnode->next = NULL;
    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->prev = ptr;
}

void deleteLast()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("Underflow");
    }

    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;
    free(ptr);
}

void reverse()
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    struct node* ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while(ptr != head){
    
        printf("(%s, %d) ", ptr->s, ptr->data);
        ptr = ptr->prev;
    }
    printf("(%s,%d) ", ptr->s, ptr->data);
}

void deleteAt(int pos)
{
    struct node *ptr = head;
    
    for (int i = 1; i < pos; i++)
    {
        if(ptr != NULL)
            ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
}

int count()
{
    struct node *ptr;

    ptr = head;

    while (ptr != NULL)
    {
        nodecount++;
        ptr = ptr->next;
    }
}