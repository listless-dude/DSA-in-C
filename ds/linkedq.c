#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *q;
void create_queue(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete_element(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);

int main()
{
    create_queue(q);
    return 0;
}

void create_queue(struct queue *q)
{
    q->rear = NULL;
    q->front = NULL;
}

struct queue *insert(struct queue *q, int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;

    if (q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
        q->front->next = q->rear->next = NULL;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
        q->rear->next = NULL;
    }
    return q;
}

struct queue *display(struct queue *q)
{
    struct node *ptr;
    ptr = q->front;
    if (ptr == NULL)
        printf("Empty");
    else
    {
        while (ptr != q->rear)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ", ptr->data);
    }
    return q;
}

struct queue *delete_element(struct queue *q)
{
    struct node *ptr;
    ptr = q->front;
    if (q->front == NULL)
        printf("Underflow");
    else
    {
        q->front = q->front->next;
        printf("%d", ptr->data);
        free(ptr);
    }
    return q;
}

int peek(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("empty");
        return -1;
    }
    else
        return q->front->data;
}