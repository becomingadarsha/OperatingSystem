#include<stdio.h>


void swap(int *x , int *y) 
{
    int temp = *x;
    *x = *y ;
    *y = temp;
}


int main(int argc, char const *argv[])
{
    int n1,n2;
    printf("Enter two numbers : ");
    scanf("%d%d",&n1,&n2);
    swap(&n1, &n2);
    printf("After swap %d %d\n",n1,n2);

    return 0;
}
