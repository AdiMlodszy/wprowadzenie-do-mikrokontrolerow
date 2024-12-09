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