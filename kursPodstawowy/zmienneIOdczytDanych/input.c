#include <stdio.h>

int main() 
{
    int num1;
    int num2;

    printf("Enter number 1: ");
    scanf("%d", &num1);

    printf("Enter number 2: ");
    scanf("%d", &num2);

    printf("%02d + %02d = %04d\n", num1, num2, num1+num2);

    return 0;
}