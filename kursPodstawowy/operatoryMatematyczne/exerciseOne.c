#include <stdio.h> 

int main()
{
    int num1;
    int resoult; 
     
    printf("Podaj pierwszą liczbę: ");
    scanf("%d", &num1);
    resoult = num1 * num1 * num1;
    printf("Trzecia potęga: %d, wynosi: %d\n", num1, resoult);

    return 0;
}