/*
Let n be the size of the array and let the size of the subarray vary from 2 to (n−1)-elements.
*/

/*
Since the problem statement is not clear, I'm assuming they want us to print the all the sub-arrays
having more than 2 elements and not more than n-1 elements.
*/
#include <stdio.h>

int findSize(int A[])
{
    return sizeof(A) / sizeof(A[0]);
}

// idea: first calculate all the sub-arrays, store all of it in 2d array of size n*(n+1)/2 by n
// i think we will need some dynamic allocation
// print all the arrays that have size 2 to n-1

// void subArrays(int A[], int start, int end, int size)
// {
//     // base case
//     if (end == size)
//         return;
//     else if (start > end)
//         subArrays(A, 0, end + 1, size);
//     else 
//     {
//         printf("[ ");
//         for (int i = start; i < end; i++)
//         {
//             printf("%d ", A[i]);
//         }
//         printf("%d ]", A[end]);
//         subArrays(A, start + 1, end, size);
//     }
//     return;
// }

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    
    subArrays(A, 0, 0, n);
    return 0;
}