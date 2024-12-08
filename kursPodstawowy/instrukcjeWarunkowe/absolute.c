#include <stdio.h>

int main()
{
    float a;
    float absoluteValue;

    printf("Podaj liczbę: ");
    scanf("%f", &a);

    absoluteValue = (a < 0) ? -a : a;
    printf("|%.2f| = %.2f\n", a, absoluteValue);

    return 0;
}