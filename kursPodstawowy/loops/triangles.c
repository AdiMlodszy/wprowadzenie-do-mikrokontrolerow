#include <stdio.h>

int main() 
{
    int triangleLevels;

    printf("Podaj liczbę poziomów trójkąta: ");
    scanf("%d", &triangleLevels);

    for (int i = 1; i <= triangleLevels; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}