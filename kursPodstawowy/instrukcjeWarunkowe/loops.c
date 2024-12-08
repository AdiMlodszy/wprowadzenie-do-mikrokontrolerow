#include <stdio.h>

int main()
{
    int x = 3;
    int silnia = 1;

    do
    {
        printf("%d ", x);
    } while ((x++) <= 3);

    // Calculate factorial of x-1 (since x is incremented after the loop)
    for (int i = 1; i < x; i++)
    {
        silnia *= i;
    }

    printf("\nSilnia: %d", silnia);

    return 0;
}