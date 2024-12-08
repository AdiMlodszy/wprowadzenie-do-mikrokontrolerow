#include <stdio.h>

int main()
{
    char c;

    while((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9') putchar('1');
        else putchar('0');
    }
    return 0;
}