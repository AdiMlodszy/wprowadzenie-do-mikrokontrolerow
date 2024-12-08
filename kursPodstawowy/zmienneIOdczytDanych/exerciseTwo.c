// Napisz program, który wczyta od użytkownika trzy liczby zmiennoprzecinkowe a, b i c, a następnie zapisze wynik działania 2a+b-c z dokładnością do jednego miejsca po przecinku.

#include <stdio.h>

int main()
{
    float a;
    float b;
    float c;
    float sum;

    printf("Enter number 1: \n");
    scanf("%f", &a);
    
    printf("Enter number 2: \n");
    scanf("%f", &b);

    printf("Enter number 3: \n");
    scanf("%f", &c);

    sum = a+a+b-c;

    printf("Sum \n 2*%.1f + %.1f - %.1f = %.1f", a, b, c, sum);

    return 0;
}