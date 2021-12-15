#include <stdio.h>
#include <stdlib.h>

int size = 0; // size for the dynamic array
int arr[10];
void insert(int arr[], int num);
void del(int arr[]);
void display(int arr[], int size);
void swap(int *a, int *b);
void heap(int array[], int size, int i);

int main()
{
    int option = 0, val;
    
    while (option != 4)
    {
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("Enter your data: ");
                scanf("%d", &val);
                insert(arr, val);
                break;
            case 2:
                del(arr);
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                break;
        }
    }
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

// this function maintains heap property for the tree
void heap(int array[], int size, int i)
{
    // here parameter i is the index of the array
    if (size == 1)
        return;
    else
    {
        int smallest = i;
        int l = 2 * i + 1; // left child
        int r = 2 * i + 2; // right child
        
        // if the left child element is smaller than the smallest element
        // since its minheap
        if (l < size && array[l] < array[smallest])
            smallest = l;
        if (r < size && array[r] < array[smallest])
            smallest = r;
        
        if (smallest != i)
        {
            // swap the positions of the elements to form heap and calling it recursively
            swap(&array[i], &array[smallest]);
            heap(array, size, smallest);
        }
    }
}

void insert(int arr[], int num)
{
    // if the size of the array is zero, insert the num to the 0th index
    // and increase the size by one
    if (size == 0)
    {
        arr[0] = num;
        size++;
    }
    else
    {
        // insert the new number to the last index and increment the size
        arr[size] = num;
        size++;
        for (int i = size/2 - 1; i >= 0; i--)
        {
            // the first index of non-leaf node is n/2 - 1
            heap(arr, size, i);
        }
    }
}

void del(int arr[])
{
    int i = 0, num = arr[0]; // arr[0] represents the root element
    
    swap(&arr[i], &arr[size - 1]);
    size--;
    
    for (int i = size/2 - 1; i >= 0; i--)
    {
        heap(arr, size, i);
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}