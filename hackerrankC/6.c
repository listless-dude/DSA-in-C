#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    char *words[] = {"one", "two", "three", "four", "five",
                        "six", "seven", "eight", "nine"};
                        
    if (n >= 1 && n <=9)
        printf("%s\n", words[n-1]);
    else if (n > 9) {
        printf("Greater than 9");
    }
    
    return 0;
}