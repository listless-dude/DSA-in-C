/*
Consider the problem of adding two n-bit binary integer, stored in two n-element arrays A
and B. The sum of the two integers should be stored in binary form in an (n + 1)-element
array C. Write a C program for the above problem. The input should be two integers in the
decimal form. 
*/

#include <stdio.h>
#include <math.h>
#define ll long long 
/* 
we can use int instead to save space but since the question said n-bit, so i've 
considered the 64-bit long long
*/

void print(ll arr[], ll n);
ll decimal_to_binary(ll n);
ll find_n(ll num1, ll num2);
ll count_bits(ll num);

int main()
{
    // take two decimals as input
    printf("Enter two decimal numbers: ");
    ll a, b;
    scanf("%lld %lld", &a, &b);
 
    // find the number of bits
    ll n = find_n(a, b);
    ll A[n], B[n], C[n+1];
 
    // convert decimal to binary
    ll x = decimal_to_binary(a);
    ll y = decimal_to_binary(b);
 
    // printf("%lld %lld ", x, y);
 
    // assigning each binary bit to corresponding array
    for (ll i = 0; i < n; i++)
    {
        A[i] = x % 10;
        x /= 10;
 
        B[i] = y % 10;
        y /= 10;
    }
    printf("Array A is: ");
    print(A, n); 
    printf("Array B is: ");
    print(B, n);
 
    // adding two arrays in binary
    ll rem = 0, i = 0;
    for (i = 0; i < n; i++)
    {
        ll s = A[i] + B[i] + rem;
        C[i] = s % 2;
        rem = s / 2;
    }
    C[i] = rem;
    
    printf("Array C is: ");
 
    print(C, n+1);
 
    return 0;
}
 
void print(ll arr[], ll n)
{
    printf("[ ");
    for (ll i = n-1; i >= 0; i--)
    {
        printf("%lld ", arr[i]);
    }
    printf("]\n");
}
 
ll decimal_to_binary(ll n)
{
    ll binary = 0;
    ll remainder, i = 1;
    while(n != 0)
    {
        remainder = n % 2;
        n /= 2;
        binary += remainder * i;
        i = i * 10;
    }
    return binary;
}
 
ll find_n(ll num1, ll num2)
{
    if (num1 >= num2)
        return count_bits(num1);
    else
        return count_bits(num2);
}
 
ll count_bits(ll num)
{
    return (ll) log2(num) + 1;
}