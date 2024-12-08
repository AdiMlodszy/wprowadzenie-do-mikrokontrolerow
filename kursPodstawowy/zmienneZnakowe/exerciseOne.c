#include <stdio.h>

int main () 
{
    int a = '1';
    int b = '2';

    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("%d\n", a- '0' + b - '0');
    printf("%d\n", b - 'O');

    return 0;
}