#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// head pointer
struct node *head = NULL;

// function prototypes
void insertAtEnd();
void display();
void reverse(struct node *head);
void sort();

int main()
{
    int option;
    
    while (option != 5)
    {
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option)
        {
            case 1:
                insertAtEnd();
                break;
            case 2:
                display();
                break;
            case 3:
                reverse(head);
                printf("\n");
                break;
            case 4:
                sort();
                break;
            case 5:
                break;
        }
    }
    return 0;
}

void insertAtEnd()
{
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
    }
    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
            printf("Overflow");
            
        struct node *ptr = head;
    
        newnode->data = data;
        newnode->next = NULL;
        
        while (ptr->next != NULL)
            ptr = ptr->next;
        
        ptr->next = newnode;
    }
    return;
}

void display()
{
    struct node *ptr = head;
    
    if (head == NULL)
        printf("List is Empty");
    
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

void reverse(struct node *head)
{
    if (head == NULL)
        return;
    else
    {
        reverse(head->next);
        printf("%d ", head->data);
    }
}

//bubble sort
void sort()
{
    struct node *ptr = head, *index = NULL;
    int tmp;
    if (head == NULL)
        return;
    else
    {
        while (ptr != NULL)
        {
            index = ptr->next;
            
            while(index != NULL)
            {
                if (ptr->data > index->data)
                {
                    // swap
                    tmp = ptr->data;
                    ptr->data = index->data;
                    index->data = tmp;
                }
                index = index->next;
            }
            ptr = ptr->next;
        }
    }
}
