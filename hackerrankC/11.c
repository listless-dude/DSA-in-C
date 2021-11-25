#include <stdio.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }
    for (int j = 0; j < n; j++)
    {
        sum += arr[j];
    }            
    printf("%d", sum);
    free(arr);
    
    return 0;
}
