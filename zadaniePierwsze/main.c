#include <stdio.h>
#include "parser.h"
#include "utils.h"

int main() {
    Stack stack = {.top = -1};
    push(&stack, '*');
    push(&stack, 'd');

    printf("Pierwszy elemenent na stosie to: %c", peek(&stack));

    return 0;
}