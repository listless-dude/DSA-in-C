/*
Write a program to generate a two-dimensional array A and perform the following operations.
    Find whether a given element is in A.
    Store an element at a specified position in A.
    Extract an element at a specified position in A.
*/

/* 
So, I think we have to generate a random 2D array just like in MATLAB,
and then perform the operations, it is not mentioned to be square matrix, so 
we consider a rectangular matrix
*/

#include <stdio.h>
#include <stdlib.h>
int m, n; // to store the rows and cols

// we can further optimize the code using binary search which will be linear time complexity
int isPresent(int val, int A[][n])
{
    int flag = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == val)
                flag = 1;
        }
    }
    return flag;
}

void insert(int val, int posx, int posy, int A[][n])
{
    A[posx][posy] = val;
}

void print(int A[][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void printElement(int posx, int posy, int A[][n])
{
    printf("%d", A[posx][posy]);
}

void generateArray(int A[][n])
{
    // storing and generating 2d array using rand() from stdlib
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 100;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Rows: ");
    scanf("%d", &m);
    printf("Columns: ");
    scanf("%d", &n);
    int A[m][n];
    printf("Generated Array is: \n");
    generateArray(A);
    int val;
    printf("Enter the value to be checked if present: \n");
    scanf("%d", &val);
    isPresent(val, A) ? printf("Yes\n") : printf("No\n");
    
    int val2, posx, posy;
    printf("Enter the value and location to insert data: \n");
    scanf("%d %d %d", &val2, &posx, &posy);

    insert(val2, posx, posy, A);
    print(A);
    printElement(posx, posy, A);
    return 0;
}