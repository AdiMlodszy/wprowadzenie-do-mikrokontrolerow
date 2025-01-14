#ifndef PARSER_H
#define PARSER_H

/**
 * @brief Struktura do przechowywania tokenów (liczb i operatorów).
 *
 */
typedef struct
{
    char data[100][20];  // np. "2", "7", "*", "(" itd.
    int count;           // liczba zebranych tokenów
} TokenList;

/**
 * @brief Funkcja dzieląca wyrażenie na tokeny (liczby, operatory, nawiasy).
 *
 * @param expression Wyrażenie do tokenizacji
 * @param tokenList Struktura, w której przechowywane są tokeny
 */
void tokenize(const char *expression, TokenList *tokenList);

/**
 * @brief Oblicza wartość wyrażenia w zapisie infiksowym (np. "2+7*3"),
 *        automatycznie zamieniając je na RPN i obliczając wynik.
 *
 * @param expression Wyrażenie tekstowe
 * @param errorFlag  Wskaźnik na flagę błędu (ustawiane na 1, gdy wystąpi błąd)
 * @return Zwraca wartość wyrażenia typu double.
 */
double evaluateExpression(const char *expression, int *errorFlag);

#endif // PARSER_H
