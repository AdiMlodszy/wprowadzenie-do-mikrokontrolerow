#include <stdio.h>

int main()
{
    int userNumber;
    int factorial = 1;

    printf("Podaj liczbę: ");
    scanf("%d", &userNumber);

    for (int i = 1; i <= userNumber; i++)
        factorial *= i;
    printf("Factorial: %d", factorial);
    return 0;
}