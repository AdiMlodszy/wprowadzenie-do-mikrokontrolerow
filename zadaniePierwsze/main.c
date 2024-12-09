#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "utils.h"

int main()
{
    char input[100] = "(2+7)*3";

    if (validateBrackets(input))
        printf("Correct expression\n");

    else
        printf("Incorrect expression\n");
    return 0;
}