#include <stdio.h>
#include <stdbool.h>

#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

bool isfull();
bool isempty();
int peek();
void enqueue();
void dequeue();
void display();

int main()
{
    int option;
    while (option != 4)
    {
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                if (!isfull())
                {
                    enqueue();
                }
                else
                    printf("overflow");
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                printf("%d\n", peek());
                display();
                break;
            case 4:
                break;
        }
    }
    return 0;
}

bool isempty()
{
    if (front == -1)
        return true;
    else
        return false;
}

bool isfull()
{
    if (rear == MAX - 1)
        return true;
    else
        return false;
}

int peek()
{
    if (isempty())
        printf("It is empty");
    else
        return queue[front];
}

void display()
{
    if (isempty())
    {
        printf("It is empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueue()
{
    int data;
    scanf("%d", &data);
    if (isfull())
        printf("It is full");
    else
    {
        if (isempty())
            front = 0;
        rear++;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (isempty())
    {
        printf("It is empty");
    }
    else
    {
        printf("%d\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}