/* 
Write a programme to sort an array of integer in descending order using the following sorting 
techniques:
(a) Insertion sort (b) Selection sort (c) Bubble sort (d) Merge Sort (e) Quick sort
*/

// quicksort to be changed in descending order, will do it later
#include <stdio.h>
#define size 100 // for temp array in merge sort

void bubbleSort(int A[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] < A[j+1])
            {
                // swap
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void insertionSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = A[i];
        for (j = i - 1; temp > A[j] && j >= 0; j--)
        {
            A[j+1] = A[j];
        }
        A[j+1] = temp;
    }
}

void selectionSort(int A[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int small = A[i];
        int pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (small < A[j])
            {
                small = A[j];
                pos = j;
            }
        }
        int temp = A[i];
        A[i] = A[pos];
        A[pos] = temp;
    }
}

void merge(int A[], int beg, int mid, int end) 
{
    int i = beg, j = mid + 1, index = beg, temp[size], k;

    while((i <= mid) && (j <= end))
    {
        // compare smaller of the two in ith and jth index of A
        if (A[i] > A[j])
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
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    quickSort(A, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}