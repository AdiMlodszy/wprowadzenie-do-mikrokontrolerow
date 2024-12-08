#include <stdio.h>

int main()
{
    int userNumber;
    
    printf("Podaj liczbę całkowitą: \n");
    scanf("%d", &userNumber);
    
    if (userNumber % 2 == 0) printf("1\n");
    else printf("0\n");
    return 0;
    
}