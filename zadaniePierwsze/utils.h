#ifndef UTILS_H
#define UTILS_H

/// @brief Struktura stosu

typedef struct Stack{

    char data[100];
    int top;
}Stack;
 
void push(Stack *stack, char item);
char pop(Stack *stack);
char peek(Stack *stack);
int isEmpty(Stack *stack);

int validateBrackets(const char *expression);

#endif // UTILS_H


