#include <stdio.h>

#define MAX_LEN 100

int main() 
{
    char ch;
    char s[MAX_LEN];
    char sen[MAX_LEN];
    
    scanf("%c", &ch);
    scanf("%s\n", s);
    scanf("%[^\n]%*c", sen);
    
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
    

    return 0;
}
