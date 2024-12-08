#include <stdio.h> 

int main() {
    int num1, num2;

    printf("Podaj dwie liczby: ");
    scanf("%d \n %d", &num1, &num2);
    
    if(num2 == 0) {
        printf("Nie można dzielić przez 0\n");
    } else {
        printf("Wynik dzielenia: %d\n", num1 / num2);
    }

    return 0;
}