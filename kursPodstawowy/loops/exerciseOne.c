#include <stdio.h>

int main() 
{
    int userNumber;
    printf("Podaj liczbę: ");
    scanf("%d",&userNumber);

    while (userNumber > 1)
    {
        printf("%d, ", userNumber);
        userNumber -=2;
    }
    printf("1");
    return 0;
} 