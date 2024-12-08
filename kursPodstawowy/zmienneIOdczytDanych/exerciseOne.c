#include <stdio.h>

int main()
{
int a;
int b;
int c;

printf("Enter number 1: ");
scanf("%d", &a);

printf("Enter number 2: ");
scanf("%d", &b);

c = a-b-b;

printf("Wynik końcowy: %d - 2 * %d = %d", a, b, c);
}
