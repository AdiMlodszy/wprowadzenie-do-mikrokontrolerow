#include <stdio.h>

int main () 
{
    
    int x;
    printf("Wartość przed przypisaniem: %d\n", x);
    
    x = 15;
    printf("Wartość x to: %d\n", x);
    
    x /= 2; 
    printf("Wynik dzielenia to: %d\n", x);

    x *= 2;
    printf("Wynik mnożenia to: %d\n", x);

    x +=1;
    printf("Wynik dodawania to: %d\n", x);

    x -=1;
    printf("Wynik odejmowania to: %d\n", x);

    return 0;
}