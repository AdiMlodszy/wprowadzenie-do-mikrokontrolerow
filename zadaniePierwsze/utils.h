#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Struktura stosu dla znaków (np. nawiasów), używana do walidacji nawiasów.
 */
typedef struct Stack
{
    char data[100];
    int top;
} Stack;

/**
 * @brief Dodaje element na szczyt stosu (dotyczy nawiasów).
 *
 * @param stack Wskaźnik na stos
 * @param item Znak do dodania
 */
void push(Stack *stack, char item);

/**
 * @brief Usuwa element ze szczytu stosu (dotyczy nawiasów).
 *
 * @param stack Wskaźnik na stos
 * @return Zwraca zdjęty znak
 */
char pop(Stack *stack);

/**
 * @brief Zwraca element ze szczytu stosu bez jego usuwania (dotyczy nawiasów).
 *
 * @param stack Wskaźnik na stos
 * @return Znak ze szczytu stosu
 */
char peek(Stack *stack);

/**
 * @brief Sprawdza, czy stos jest pusty.
 *
 * @param stack Wskaźnik na stos
 * @return 1, jeśli pusty; 0 w przeciwnym razie
 */
int isEmpty(Stack *stack);

/**
 * @brief Funkcja sprawdzająca poprawność nawiasów w wyrażeniu.
 *
 * @param expression Wyrażenie do walidacji
 * @return 1, jeśli wszystkie nawiasy są poprawnie zamknięte; 0 w przeciwnym razie
 */
int validateBrackets(const char *expression);

#endif // UTILS_H
