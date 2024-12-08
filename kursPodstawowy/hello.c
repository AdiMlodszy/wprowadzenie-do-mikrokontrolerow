#include <stdio.h>

int main() {
    int zmienna = 12; 
    int *wskaznik = &zmienna;

    printf("Wartość zmiennej to: %d\n ", wskaznik);
    return 0;
}