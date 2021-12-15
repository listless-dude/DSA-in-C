#include <stdio.h>

int main()
{
    int n, count;
    scanf("%d", &n);
    
    int a[n], fre[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        fre[i] = -1; //initiall frequency is -1
    }
    
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int j = i+1; j < n; j++) //each sub array
        {
            if (a[i] == a[j]) // if same count increment
            {
                count++;
                fre[j] = 0; // dont add to fre
            }
        }
        
        if (fre[i] != 0)
            fre[i] = count;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (fre[i] != 0)
        {
            printf("%d - %d times \n", a[i], fre[i]);
        }
    }
    return 0;
}