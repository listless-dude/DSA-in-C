#include <stdio.h>

// finding max element of array
int findMax(int A[], int n)
{
    int max = A[0];

    for(int i = 1; i < n; i++)
        if(A[i] > max)
            max = A[i];
    
    return max;
}

// using stable countingSort as intermediate sorting
void countingSort(int A[], int n, int place)
{
    // output array B & auxiliary array C
    int i, B[n + 1], max = (A[0] / place) % 10;

    for(i = 1; i < n; i++)
        if(((A[i] / place) % 10) > max)
            max = A[i];

    int C[max + 1];

    // initialize all the elements of C to 0
    for(i = 0; i < max; i++)
        C[i] = 0;
    
    // set the count of the the elements of A
    for(i = 0; i < n; i++)
        C[(A[i] / place) % 10]++;
    
    // change count to store index of output array C
    for(i = 1; i < 10; i++)
        C[i] += C[i - 1];
    
    for(i = n - 1; i >= 0; i--)
    {
        B[C[(A[i] / place) % 10] - 1] = A[i];
        C[(A[i] / place) % 10]--;
    }

    // copy to original array
    for(i = 0; i < n; i++)
        A[i] = B[i];
}

void radixSort(int A[], int n)
{
    int max = findMax(A, n);

    for(int place = 1; max / place > 0; place *= 10)
        countingSort(A, n, place);
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    
    radixSort(A, n);

    // printing the output
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    
    return 0;
}