#include <stdio.h>

int main()
{

    int a, b;
    char operator;


        printf("Podaj dwie liczby: ");
        scanf("%d %d", &a, &b); 
        printf("Podaj operator: ");

        scanf(" %c", &operator); 

        if (operator == '+')
        {
            printf("Wynik dodawania: %d\n", a + b);
        }
        else if (operator == '-')
        {
            printf("Wynik odejmowania: %d\n", a - b);
        }
        else if (operator == '*')
        {
            printf("Wynik mnożenia: %d\n", a * b);
        }
        else if (operator == '/')
        {
            if (b == 0)
            {
                printf("Nie można dzielić przez 0\n");
            }
            else
            {
                printf("Wynik dzielenia: %d\n", a / b);
            }
        }
        else
        {
            printf("Nieznany operator\n");
    }
}