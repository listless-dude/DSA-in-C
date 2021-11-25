#include <stdio.h>

int max(int x, int y)
{
    if (x > y)
        return x;
    else 
        return y;
}

int max_of_four(int a, int b, int c, int d)
{
    int m = max(a, b);
    int n = max(c, d);
    int r = max(m, n);
    
    return printf("%d", r);
}

int main() {
    int a, b, c, d;
    scanf("%d\n", &a);
    scanf("%d\n", &b);
    scanf("%d\n", &c);
    scanf("%d\n", &d);
    max_of_four(a, b, c, d);
    return 0;
}
