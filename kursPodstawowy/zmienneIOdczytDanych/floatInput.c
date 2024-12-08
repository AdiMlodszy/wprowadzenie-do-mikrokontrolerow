#include <stdio.h>

float main()
{
    float num1;
    float num2;

    printf("Enter number 1: ");
    scanf("%f", &num1);

    printf("Enter number 2: ");
    scanf("%f", &num2);

    printf("%.2f + %.3f = %c", num1, num2, num1+num2);

    return 0;

}