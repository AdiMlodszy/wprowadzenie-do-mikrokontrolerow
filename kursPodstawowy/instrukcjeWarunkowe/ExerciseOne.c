#include <stdio.h>

int main() 
{
int a, b, c;

printf("Podaj trzy liczby: ");

scanf("%d\n%d\n%d", &a, &b, &c);

if((a+b)>c && (a+c)>b && (b+c)>a) 
    printf("TAK\n");

else printf("NIE\n");

return 0;
}