#include <stdio.h>

int main() 
{
    int num1, num2;

    printf("Podaj dwie liczby całkowite: \n");
    scanf("%d \n %d", &num1, &num2);

    printf("%d XOR %d: %d\n", num1, num2, (num1 || num2) && !(num1 && num2));

    return 0;
}