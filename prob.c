#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int fr[N];
    int visited = -1;
    for (int i = 0; i < N; i++)
    {
        int count = 1;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                fr[j] = visited;
            }
        }
        if (fr[i] != visited)
            fr[i] = count;
    }
    for (int i = 0; i < N; i++)
    {
        if (fr[i] != visited)
        {
            printf("%d - %d times\n", arr[i], fr[i]);
        }
    }
    return 0;
}