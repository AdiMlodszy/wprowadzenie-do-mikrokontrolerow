#include <stdio.h>
#include "parser.h"
#include "utils.h"

/**
 * @brief Dodaj element na stos
 * 
 * @param stack Wskaźnik na stos
 * @param item Element do dodania
 */

void push(Stack *stack, char item)
{
    stack -> data[++stack -> top] = item;
}

/**
 * @brief Wypchnij element ze stosu
 * 
 * @param stack Wskaźnik na stos
 * @return Element zdjęty ze stosu
 */

char pop(Stack *stack)
{
    return stack -> data[stack -> top--];
}

/**
 * @brief Zwróć element ze stosu
 * 
 * @param stack Wskaźnik na stos
 * @return Element na szczycie stosu
 */

char peek(Stack *stack)
{
    return stack -> data[stack -> top];
}

/**
 * @brief Sprawdź czy stos jest pusty
 * 
 * @param stack Wskaźnik na stos
 * @return 1 jeśli stos jest pusty, 0 w przeciwnym wypadku
 */

int isEmpty(Stack *stack)
{
    return stack -> top == -1;
}

/**
 * @brief Walidacja nawiasów
 * 
 * @param expression Wskaźnik na wyrażenie
 * @return 1 jeśli nawiasy są poprawne, 0 w przeciwnym wypadku
 */

int validateBrackets(const char *expression)
{
    Stack stack = {.top = -1};

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
            push(&stack, expression[i]);
        
        else if (expression[i] == ')')
        {
            if (isEmpty(&stack)) 
                return 0;
            
            pop(&stack);
        }
    }
    return isEmpty(&stack);

}