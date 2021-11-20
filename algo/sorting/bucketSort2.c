/* Bucket sort implementation using arrays */
#include <stdio.h>

int findMax(int A[], int n)
{
    int max = A[0];
    for(int i = 1; i < n; i++)
        max = A[i];

    return max;
}

void bucketSort(int A[], int n)
{
    int i, j, max = findMax(A, n);
    int bucket[max];

    // initialize empty bucket
    for(i = 0; i <= max; i++)
        bucket[i] = 0;

    // add count to the auxiliary array
    for(i = 0; i < n; i++)
        bucket[A[i]]++;
    
    // emptying auxiliary array
    for(i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            A[j++] = i;
            bucket[i]--;
        }
    }
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