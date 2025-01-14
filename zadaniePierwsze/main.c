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
    // Przykład: wczytanie z stdin
    char input[100];
    printf("Podaj wyrażenie (np. (2+7)*3): ");
    if(!fgets(input, sizeof(input), stdin))
    {
        printf("Błąd odczytu wyrażenia.\n");
        return 1;
    }
    // usuwamy znak nowej linii, jeśli jest
    size_t len = strlen(input);
    if (len > 0 && input[len-1] == '\n')
        input[len-1] = '\0';

    // Sprawdzamy poprawność nawiasów
    if (!validateBrackets(input))
    {
        printf("Błąd: Niepoprawne nawiasy w wyrażeniu.\n");
        return 1;
    }

    // Obliczamy wyrażenie
    int errorFlag = 0;
    double result = evaluateExpression(input, &errorFlag);

    if (errorFlag)
    {
        // Komunikat o błędzie może być już wypisany wewnątrz evaluateExpression
        printf("Wystąpił błąd w obliczeniach.\n");
    }
    else
    {
        printf("Wynik: %g\n", result);
    }

    return 0;
}
