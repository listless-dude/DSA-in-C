/* Bucket Sort using Linked list and insertion sort */
#include <stdio.h>
#include <stdlib.h>

// more the number of buckets more costly to memory
#define NBUCKET 5 // no. of buckets
#define INTERVAL 10 // each bucket range

struct Node {
    int data;
    struct Node *next;
};

// get the index of elements to be inserted in bucket
int getBucketIndex(int val)
{
    return val / INTERVAL;
}

void printBuckets(struct Node *list)
{
    struct Node *ptr = list;
    while(ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// function to sort each elements of the bucket
struct Node *insertionSort(struct Node *list)
{
    struct Node *k, *nodeList;
    // atleast two items to sort, else return
    if(list == 0 || list->next == 0)
        return list;
    
    nodeList = list;
    // k is first node of new list
    k = list->next;
    nodeList->next = NULL;

    while(k != NULL)
    {
        struct Node *ptr;

        if(nodeList->data > k->data)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }

        // if [i] > [i+1]
        for(ptr = nodeList; ptr->next != NULL; ptr = ptr->next)
        {
            if(ptr->next->data > k->data)
                break;
        }

        if(ptr->next != NULL)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = NULL;
            continue;
        }
    }

    return nodeList;
}

void bucketSort(int A[], int NARRAY)
{
    int i, j;
    struct Node **buckets; 

    // allocate bucket size
    buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

    // initialize empty buckets
    for(i = 0; i < NBUCKET; i++)
        buckets[i] = NULL;
    
    // insert elements in the buckets
    for(i = 0; i < NARRAY; i++)
    {
        struct Node *ptr;
        int pos = getBucketIndex(A[i]);
        ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = A[i];
        ptr->next = buckets[pos];
        buckets[pos] = ptr;
    }

    // print each bucket before sorting
    for(i = 0; i < NBUCKET; i++)
    {
        printf("Bucket[%d]: ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }

    // sort elements of each bucket
    for(i = 0; i < NBUCKET; i++)
        buckets[i] = insertionSort(buckets[i]);
    
    // print each bucket after sorting
    for(i = 0; i < NBUCKET; i++)
    {
        printf("Bucket[%d]: ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }

    // insert sorted element to A[]
    for(j = 0, i = 0; i < NBUCKET; i++)
    {
        struct Node *node;
        node = buckets[i];
        while(node)
        {
            A[j++] = node->data;
            node = node->next;
        }
    }

    // free memory of each elements in buckets
    for(i = 0; i < NBUCKET; i++)
    {
        struct Node *node;
        node = buckets[i];
        while(node)
        {
            struct Node *tmp;
            tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(buckets); // free buckets
    return;
}

int main()
{
    int nArray;
    printf("Enter no. elements: ");
    scanf("%d", &nArray);

    int A[nArray];
    printf("Enter %d elements: ", nArray);
    for (int i = 0; i < nArray; i++)
        scanf("%d", &A[i]);
    
    bucketSort(A, nArray);

    // print sorted array
    for (int i = 0; i < nArray; i++)
        printf("%d ", A[i]);
    
    return 0;
}