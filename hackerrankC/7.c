#include <stdio.h>

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);

    char *digits[] = { "zero", "one", "two", 
                        "three", "four","five", 
                        "six", "seven", "eight", "nine"};
    for (int i = a; i <= b; i++)
    {
        if (i <= 9) {
            printf("%s\n", digits[i]);
        }
        else if (i > 9) {
            if (i%2 == 0) {
                printf("even\n");
            }
            else if (i%2 != 0) {
                printf("odd\n");
            }
        } 
    }
    return 0;
}

