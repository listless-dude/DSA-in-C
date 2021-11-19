#include <stdio.h>

/* partition function rearranges elements such that every element 
to the left of pivot element is less than the pivot element and 
all elements to the right are greater than the pivot element */

int partition(int A[], int beg, int end) 
{
    int left, right, temp, loc, flag;
    loc = left = beg;
    right = end;
    flag = 0;

    while(flag != 1)
    {
        while((A[loc] <= A[right]) && (loc != right))
            right--;
        
        if(loc == right)
            flag = 1;
        else if(A[loc] > A[right])
        {
            // swap
            temp = A[loc];
            A[loc] = A[right];
            A[right] = temp;
            loc = right;
        }

        if(flag != 1)
        {
            while((A[loc] >= A[left]) && (loc != left))
                left++;
            if(loc == left)
                flag = 1;
            else if(A[loc] < A[left])
            {
                // swap
                temp = A[loc];
                A[loc] = A[left];
                A[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}

// quickSort funtion recursively sorts
void quickSort(int A[], int beg, int end) 
{
    int loc;
    if(beg < end)
    {
        loc = partition(A, beg, end);
        quickSort(A, beg, loc - 1);
        quickSort(A, loc + 1, end);
    }
}

int main()
{
    int n;
    printf("No. of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter %d elements: \n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    quickSort(A, 0, n-1);

    // printing sorted array
    printf("Sorted Array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    
    return 0;
}