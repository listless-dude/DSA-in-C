/*
Write a programme to search an element in an array using the binary search technique.
*/

#include <stdio.h>

int binarySearch(int A[], int num, int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if(A[mid] == num)
            return mid;
        else if(A[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;    
    }
    return -1;
}

int main()
{
    int n, num;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("Num to be searched: ");
    scanf("%d", &num);

    int res = binarySearch(A, num, 0, n - 1);

    (res == -1) ? printf("Not found") : printf("Found at index %d \n", res);
    return 0;
}