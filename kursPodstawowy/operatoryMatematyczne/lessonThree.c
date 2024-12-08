#include <stdio.h>

// Różnica między post i preinkrementacją
int main ()
{
    int x = 15; 

    printf("Wartość x to: %d\n", x);
    printf("Wartość x po inkrementacji: %d\n", ++x);
    printf("Wartość x po inkrementacji: %d\n", x);

    return 0;
}