#include <stdio.h>

void selectionSort(int A[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        int small = A[i];
        int pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (small > A[j])
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

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    selectionSort(A,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}