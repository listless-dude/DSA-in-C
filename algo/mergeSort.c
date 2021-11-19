#include <stdio.h>
#define size 100 // define size of temporary array

// merge funtion combines the sub-arrays to form sorted array
void merge(int A[], int beg, int mid, int end) 
{
    int i = beg, j = mid + 1, index = beg, temp[size], k;

    while((i <= mid) && (j <= end))
    {
        // compare smaller of the two in ith and jth index of A
        if (A[i] < A[j])
        {
            temp[index] = A[i];
            i++;
        }
        else
        {
            temp[index] = A[j];
            j++;
        }
        index++;
    }
    // copy remaining elements of right sub-array if any
    if(i > mid)
    {
        while(j <= end)
        {
            temp[index] = A[j];
            j++;
            index++;
        }
    }
    // copy remaining elements of left sub-array if any
    else
    {
        while(i <= mid)
        {
            temp[index] = A[i];
            i++;
            index++;
        }
    }

    // copy the temp array to the main array A
    for(k = beg; k < index; k++)
        A[k] = temp[k];
}

// mergeSort funtion recursively sorts each sub-array
void mergeSort(int A[], int beg, int end) 
{
    int mid;
    if(beg < end)
    {
        mid = (beg + end) / 2;
        mergeSort(A, beg, mid);
        mergeSort(A, mid + 1, end);
        merge(A, beg, mid, end);
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

    mergeSort(A, 0, n-1); // beg = 0, end = n - 1 

    // printing sorted array
    printf("Sorted Array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    
    return 0;
}