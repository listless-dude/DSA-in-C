/*
Let n be the size of the array and let the size of the subarray vary from 2 to (n−1)-elements.
*/

/*
Since the problem statement is not clear, I'm assuming they want us to print the all the sub-arrays
having more than 2 elements and not more than n-1 elements.
*/
#include <stdio.h>

// maybe we could've used recusion to reduce time complexity
void subArrays(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (j-i+1 > 1 && j-i+1 < n)
                printf("[ ");
            for (int k = i; k <= j; k++)
            {
                if (j-i+1 > 1 && j-i+1 < n) // j-i+1 is size of each sub-array
                    printf("%d ", A[k]);
            }
            if (j-i+1 > 1 && j-i+1 < n)
                printf("]\n");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    
    printf("All the sub-arrays having size between to 2 and n-1 are: \n");
    subArrays(A, n);
    return 0;
}