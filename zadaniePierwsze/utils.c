#include <stdio.h>
#include "parser.h"
#include "utils.h"

/**
 * @brief Add element to the stack
 *
 * @param stack Pointer to the stack
 * @param item Item to add
 */

void push(Stack *stack, char item)
{
    stack->data[++stack->top] = item;
}

/**
 * @brief Remove element from the stack
 *
 * @param stack Pointer to the stack
 * @return Removed element
 */

char pop(Stack *stack)
{
    return stack->data[stack->top--];
}

/**
 * @brief Get the top element of the stack
 *
 * @param stack Pointer to the stack
 * @return Top element
 */

char peek(Stack *stack)
{
    return stack->data[stack->top];
}

/**
 * @brief Check if the stack is empty
 *
 * @param stack Pointer to the stack
 * @return 1 if the stack is empty, 0 otherwise
 */

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

/**
 * @brief Validate the brackets in the expression
 *
 * @param expression Expression to validate
 * @return 1 if the expression is correct, 0 otherwise
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