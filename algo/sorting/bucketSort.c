#include <stdio.h>
#include <stdlib.h>

void bucketSort(int A[], int n)
{
    
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    bucketSort(A, n);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}