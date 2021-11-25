#include <stdio.h>

int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int ones = n % 10;
    int tens = (n % 100);
    int real_tens = (tens - ones)/10;
    int hundreds = (n % 1000);
    int real_hundreds = (hundreds - tens)/100;
    int thou = (n % 10000);
    int real_thou = (thou - hundreds)/1000;
    int tenthou = n % 100000;
    int real_tenthou = (tenthou - thou)/10000;
    printf("%d", real_tenthou+real_thou+real_hundreds+real_tens+ones);
    return 0;
}