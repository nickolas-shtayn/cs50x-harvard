// Practice the C language concepts and sytnax
#include <stdio.h>
#include <cs50.h>

int addition(int a, int b);
int subtract(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
int modulo(int a, int b);


int main(void)
{
    int x = get_int("What is x? ");
    int y = get_int("What is y? ");

    int add = addition(x, y);
    int sub = subtract(x, y);
    int multi = multiplication(x, y);
    int div = division(x, y);
    int mod = modulo(x, y);

    printf("%i, %i, %i, %i, %i", add, sub, multi, div, mod);
}

int addition(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiplication(int a, int b)
{
    return a * b;
}
int division(int a, int b)
{
    return a / b;
}
int modulo(int a, int b)
{
    return a % b;
}