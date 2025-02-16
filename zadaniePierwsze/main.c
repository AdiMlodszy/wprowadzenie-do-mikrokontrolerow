#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "utils.h"

/**
 * @brief Główna funkcja programu, w której:
 *  1) Odczytywane jest wyrażenie od użytkownika (lub ustawiane na sztywno).
 *  2) Walidowane są nawiasy.
 *  3) Obliczana jest wartość wyrażenia.
 *  4) Wypisywany jest wynik lub błąd.
 */
int main()
{
    char input[100];
    printf("Podaj wyrazenie: ");
    if (!fgets(input, sizeof(input), stdin))
    {
        printf("Blad odczytu wyrazenia.\n");
        return 1;
    }
    // usuwamy znak nowej linii, jeśli jest
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    // Sprawdzamy poprawność nawiasów
    if (!validateBrackets(input))
    {
        printf("Blad: Niepoprawne nawiasy w wyrazeniu.\n");
        return 1;
    }

    // Obliczamy wyrażenie
    int errorFlag = 0;
    double result = evaluateExpression(input, &errorFlag);

    if (errorFlag)
    {
        // Komunikat o błędzie może być już wypisany wewnątrz evaluateExpression
        printf("Wystapil bład w obliczeniach.\n");
    }
    else
    {
        printf("Wynik: %g\n", result);
    }
    return 0;
}
