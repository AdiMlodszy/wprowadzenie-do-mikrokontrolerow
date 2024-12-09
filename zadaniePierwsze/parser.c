#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "utils.h"

/**
 * @brief Tokenize the expression and store the tokens in the tokenList
 *
 * @param expression expression to tokenize
 * @param tokenList list to store the tokens
 */
void tokenize(const char *expression, TokenList *tokenList)
{

    tokenList->count = 0;
    int i = 0;

    while (expression[i] != '\0')
    {
        if (isspace(expression[i]))
        {
            i++;
            continue;
        }
        if (isdigit(expression[i]))
        {
            char number[50];
            int j = 0;

            while (isdigit(expression[i]) || expression[i] == '.')
            {
                number[j++] = expression[i++];
            }

            number[j] = '\0';
            strcpy(tokenList->data[tokenList->count++], number);
        }
        else
        {
            char operator[2] = { expression[i++],
                                 '\0' };
            strcpy(tokenList->data[tokenList->count++], operator);
        }
    }
}