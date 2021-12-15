/*
Write a program to input an n digit number. Now, 
break this number into its individual digits and 
then store every single digit in a separate node 
thereby forming a linked list. For example, if 
you enter 12345, then there will 5 nodes in the 
list containing nodes with values 1, 2, 3, 4, 5.
*/

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtEnd(int data)
{    
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

int evaluate(int n)
{
    int digit;
    while(n)
    {
        digit = n % 10;
        insertAtEnd(digit);
        n /= 10;
    }
}

void reverse()
{
    struct node *ptr = head;
    struct node *prev = NULL, *next = NULL;

    while (ptr != NULL)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
}

int main()
{
    int n;
    scanf("%d", &n);
    evaluate(n);
    reverse();
    print();
    return 0;
}