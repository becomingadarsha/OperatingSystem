#include<stdio.h>

long Factorial(int n) {
    if(n == 1) return 1;

    else return (n*Factorial(n-1));
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter desired number : ");
    scanf("%d", &n);
    printf("%ld",Factorial(n));
    return 0;
}
