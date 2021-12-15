#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

int queue[MAX];

int front = -1, rear = -1;

bool isfull();
bool isempty();
int peek();
int enqueue();
int dequeue();
void display();

int main()
{
    int option, val;
    while (option != 4)
    {
        printf("Enter 1: Enqueue Operation\n");
        printf("Enter 2: Dequeue Operation\n");
        printf("Enter 3: Peek Operation\n");
        printf("Enter 4: Exit\n");
        printf("Input: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            if (!isfull())
            {   
                printf("Input: ");
                enqueue();
            }
            else
                printf("Overflow");
            display();
            break;
        case 2:
            val = dequeue();
            printf("Output: % \n", val);
            display();
            break;
        case 3:
            printf("Output: %d \n", peek());
            display();
            break;
        case 4:
            break;
        }
    }
    
    return 0;
}

bool isfull()
{
    if (front == 0 && rear == MAX - 1)
        return true;
    else 
        return false;
}

bool isempty()
{
    if (front == -1 && rear == -1)
        return true;
    else 
        return false;
}

int enqueue()
{
    int data;
    scanf("%d", &data);
    if (isfull())
    {
        printf("Overflow\n");
    }
    else if (isempty())
    {
        front = 0;
        rear = 0;
        queue[rear] = data;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

int dequeue()
{
    if (isempty())
    {
        printf("Underflow\n");
        return -1;
    }

    int data = queue[front];
    
    if (front == rear)
    {
        front = -1; 
        rear = - 1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
    
    return data;
}

int peek()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
        return queue[front];
}

void display()
{
    int i;
    printf("\n");
    if (isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        if (front < rear)
        {
            for (i = front; i <= rear ; i++)
                printf("%d ", queue[i]);
        }
        else
        {
            for(i = front; i < MAX; i++)
                printf("%d ", queue[i]);
            for(i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }
    }
    printf("\n");
}