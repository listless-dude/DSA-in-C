#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    int index = num;

    /* Write the logic to reverse the array. */
    int *rev = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++)
    {
        rev[i] = arr[num - i - 1];
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(rev + i));
        
    free(rev);
    free(arr);
    return 0;
}