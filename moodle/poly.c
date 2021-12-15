#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int coeff;
    int expo;
    struct node *next;
};

// head pointers of three lists
struct node *head1 = NULL, *head2 = NULL, *result = NULL;

// function prototypes
struct node *createPoly(struct node *head);
void addPoly(struct node *head1, struct node *head2, struct node **result);
void display(struct node *head);

int main()
{
    head1 = createPoly(head1);
    head2 = createPoly(head2);
    addPoly(head1, head2, &result);
    display(result);
    return 0;
}

struct node *createPoly(struct node *head)
{
    struct node *newnode, *ptr;
    int coeff, expo, n; // n is the degree
    scanf("%d", &n);
    
    while (n--)
    {
        scanf("%d %d", &coeff, &expo);
        
        // create newnodes
        if (head == NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->coeff = coeff;
            newnode->expo = expo;
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->coeff = coeff;
            newnode->expo = expo;
            newnode->next = NULL;
            ptr->next = newnode;
        }
    }
    return head;
}

void addPoly(struct node *head1, struct node *head2, struct node **result)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = NULL;
    *result = tmp; // reference to the address of the tmp
    
    while (head1 && head2)
    {
        // since we need the result polynomial in order, so we compare the coefficients and add accordingly
        if (head1->expo > head2->expo)
        {
            tmp->coeff = head1->coeff;
            tmp->expo = head1->expo;
            head1 = head1->next;
        }
        else if (head1->expo < head2->expo)
        {
            tmp->coeff = head2->coeff;
            tmp->expo = head2->expo;
            head2 = head2->next;
        }
        else
        {
            tmp->coeff = head1->coeff + head2->coeff;
            tmp->expo = head1->expo;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        if (head1 && head2)
        {
            tmp->next = (struct node *)malloc(sizeof(struct node));
            tmp = tmp->next;
            tmp->next = NULL;
        }
    }
    
    while (head1 || head2)
    {
        tmp->next = (struct node *)malloc(sizeof(struct node));
        tmp = tmp->next;
        tmp->next = NULL;
        
        if (head1)
        {
            tmp->coeff = head1->coeff;
            tmp->expo = head1->expo;
            head1 = head1->next;
        }
        else if (head2)
        {
            tmp->coeff = head2->coeff;
            tmp->expo = head2->expo;
            head2 = head2->next;
        }
    }
    return;
}

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->expo == 1)
            printf("%dX", ptr->coeff);
        else if (ptr->expo == 0)
            printf("%d", ptr->coeff);
        else
            printf("%dX^%d", ptr->coeff, ptr->expo);
        ptr = ptr->next;
        if (ptr != NULL)
            printf("+");
    }
    printf("\n");
}