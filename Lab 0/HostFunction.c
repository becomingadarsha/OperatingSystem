/*

#include <stdio.h>

void print()  
{
    printf("Hello World!");
}

void helloworld(void (*f)())  
{
    f();
}

int main(void)  
{
    helloworld(print);
    return (0);
}

*/


// This states that a parameter f will be a pointer (*f) to the function myFunction, which has a void return type and which takes just a single int parameter. In laid man's terms, myFunction takes an argument of a function type void, that returns a type void, and takes an int as an argument; (void (*f)(int)).

#include <stdio.h>

void printNumber(int nbr)  
{
    printf("%d\n", nbr);
}

void myFunction(void (*f)(int))  
{
    for(int i = 0; i < 5; i++) 
    {
        (*f)(i);
    }
}

int main(void)  
{
    myFunction(printNumber);
    return (0);
}