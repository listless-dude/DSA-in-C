/* 
Write a C program to find the sum of contiguous subarray in an array which has the largest sum.
*/

#include <stdio.h>

// function to find maximum sub-array sum
int maxSubArraySum(int arr[], int n)
{
    int i = 0;
    int maxS = 0;
    int maxEnd = 0;
    for (i = 0; i < n; i++)
    {
        maxEnd = maxEnd + arr[i];
        if (maxEnd < 0)
        {
            maxEnd = 0; 
        }
        if (maxS < maxEnd)
        {
            maxS = maxEnd;
        }
    }
    return maxS;
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the %d array elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    const int maxSum = maxSubArraySum(arr, n);
    printf("Max sum is: %d ", maxSum);
    return 0;
}
