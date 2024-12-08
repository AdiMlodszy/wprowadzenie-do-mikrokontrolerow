#include <stdio.h>

int main()
{
    int args;
    int number;
    int sum = 0;

    printf("Podaj ilość liczb wejściowych: ");
    scanf("%d", &args);

    for(int i = 0; i < args; i++)
    {
        scanf("%d", &number);
        sum += number;
    }
    printf("%d", sum);
    return 0;
}