#include <stdio.h>

int main() 
{
    float d;
    float pi = 3.141593;
    float pole;

    printf("Podaj średnicę koła: \n");
    scanf("%f", &d);

    pole = pi * (d/2) * (d/2);
    printf("Pole koła wynosi: %.4f\n", pole);

    return 0;
}