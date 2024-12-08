#include <stdio.h>

int main()

{

    int number;
    char result;

    printf("Podaj liczbę: ");
    scanf("%d",&number);

    result= (number > 0)? '+': '-';

    printf("%c",result);

    return 0;

}