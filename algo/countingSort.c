#include <stdio.h>

void countingSort(int A[], int n, int k)
{
    // output array B & auxiliary array C
    int i, B[n], C[k]; 

    // initialize all the elements of C to 0
    for(i = 0; i < k; i++)
        C[i] = 0;
    
    // set the count of the the elements of A
    for(i = 0; i < n; i++)
        C[A[i]]++;
    
    // cumulative count for indexing
    for(i = 1; i <= k; i++)
        C[i] += C[i - 1];
    
    for(i = n - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    // copy to original array
    for(i = 0; i < n; i++)
        A[i] = B[i];
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
    /* we can save more space by finding the max element in A
       and then pass k = max + 1 to the countingSort, here k = 10 */
    
    countingSort(A, n, 10);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}