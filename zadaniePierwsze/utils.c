#include <stdio.h>
#include "parser.h"
#include "utils.h"

/**
 * @brief Dodaje element (nawias) na szczyt stosu.
 *
 * @param stack Wskaźnik na stos
 * @param item Znak do dodania
 */
void push(Stack *stack, char item)
{
    stack->data[++stack->top] = item;
}

/**
 * @brief Usuwa element ze szczytu stosu (nawias).
 *
 * @param stack Wskaźnik na stos
 * @return Zwraca zdjęty znak
 */
char pop(Stack *stack)
{
    return stack->data[stack->top--];
}

/**
 * @brief Zwraca element ze szczytu stosu bez usuwania go (podgląd).
 *
 * @param stack Wskaźnik na stos
 * @return Znak ze szczytu stosu
 */
char peek(Stack *stack)
{
    return stack->data[stack->top];
}

/**
 * @brief Sprawdza, czy stos jest pusty.
 *
 * @param stack Wskaźnik na stos
 * @return 1 jeśli pusty, w przeciwnym razie 0
 */
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

/**
 * @brief Waliduje nawiasy w wyrażeniu. Zwraca 1, jeśli nawiasy są poprawne.
 *
 * @param expression Wyrażenie do sprawdzenia
 * @return 1, jeśli wyrażenie ma poprawnie zamknięte nawiasy, 0 w przeciwnym razie
 */
int validateBrackets(const char *expression)
{
    Stack stack = {.top = -1};

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            push(&stack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (isEmpty(&stack))
            {
                // Brak pasującego nawiasu otwierającego
                return 0;
            }
            pop(&stack);
        }
    }

    // Jeśli po przejściu przez wyrażenie stos nie jest pusty,
    // to znaczy, że jakiś nawias '(' nie został zamknięty.
    return isEmpty(&stack);
}
