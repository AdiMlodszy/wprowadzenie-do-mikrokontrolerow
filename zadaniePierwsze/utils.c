#include <stdio.h>
#include "parser.h"
#include "utils.h"

void push(Stack *stack, char item)
{
    stack -> data[++stack -> top] = item;
}

char pop(Stack *stack)
{
    return stack -> data[stack -> top--];
}

char peek(Stack *stack)
{
    return stack -> data[stack -> top];
}

int isEmpty(Stack *stack)
{
    return stack -> top == -1;
}

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