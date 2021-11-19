#include <stdio.h>

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

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    insertionSort(A,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}