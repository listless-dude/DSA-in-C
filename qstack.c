#include <stdio.h>

// reverse a queue using stack
#define MAX 20

// stack
int top = -1;
int stack[MAX];

// queue
int front = -1, rear = -1;
int queue[MAX];

void push(int val)
{
    if (top == MAX-1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

void enqueue(int num)
{
    if (rear == MAX - 1)
        printf("Overflow\n");
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = num;
}

int dequeue()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        val = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return val;
    }
}

int pop()
{
    int val;
    if(top == -1)
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    else
    {
        val = stack[top];
        top--;
        return val;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Empty");
    }
    else
    {
        for(i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

void displayQ()
{
    int i;
    if (front == -1 || front > rear)
        printf("EMpty");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");

}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    while (!(front == -1 && rear == -1))
    {
        push(dequeue());
    }
    while (top != -1)
    {
        enqueue(pop());
    }
    displayQ();

    return 0;
}