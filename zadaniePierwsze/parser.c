#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "parser.h"

/**
 * @brief Funkcja pomocnicza sprawdzająca, czy dany znak jest operatorem (+, -, *, /).
 *
 * @param c Znak do sprawdzenia
 * @return 1, jeśli jest operatorem; 0 w przeciwnym razie
 */
static int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

/**
 * @brief Zwraca priorytet operatora. Im większa liczba, tym wyższy priorytet.
 *
 * @param op Operator np. '+', '-', '*', '/'
 * @return int Priorytet operatora (większa liczba -> wyższy priorytet)
 */
static int precedence(char op)
{
    switch(op)
    {
        case '+': 
        case '-': return 1;
        case '*': 
        case '/': return 2;
    }
    return 0; // nieznany operator
}

/**
 * @brief Stos do przechowywania tokenów RPN w trakcie konwersji.
 */
typedef struct
{
    char rpnData[100][20];
    int top;
} RPNStack;

/**
 * @brief Dodaje token na stos RPN.
 *
 * @param stack Wskaźnik na stos RPN
 * @param token Token do dodania
 */
static void pushRPN(RPNStack *stack, const char *token)
{
    ++stack->top;
    strcpy(stack->rpnData[stack->top], token);
}

/**
 * @brief Zdejmuje token ze stosu RPN.
 *
 * @param stack Wskaźnik na stos
 * @param out Bufor do którego zostanie skopiowany zdjęty token
 */
static void popRPN(RPNStack *stack, char *out)
{
    strcpy(out, stack->rpnData[stack->top]);
    --stack->top;
}

/**
 * @brief Tokenizuje wyrażenie i zapisuje w strukturze TokenList (liczby, operatory, nawiasy).
 *
 * @param expression Wyrażenie infiksowe
 * @param tokenList Struktura na tokeny
 */
void tokenize(const char *expression, TokenList *tokenList)
{
    tokenList->count = 0;
    int i = 0;

    while (expression[i] != '\0')
    {
        if (isspace((unsigned char)expression[i]))
        {
            // Pomijamy białe znaki
            i++;
            continue;
        }
        else if (isdigit((unsigned char)expression[i]))
        {
            // Mamy liczbę (może być wielocyfrowa)
            char number[20];
            int j = 0;

            while (isdigit((unsigned char)expression[i]) || expression[i] == '.')
            {
                number[j++] = expression[i++];
            }
            number[j] = '\0';

            strcpy(tokenList->data[tokenList->count++], number);
        }
        else if (isOperator(expression[i]) || expression[i] == '(' || expression[i] == ')')
        {
            // Operator lub nawias
            char op[2];
            op[0] = expression[i];
            op[1] = '\0';

            strcpy(tokenList->data[tokenList->count++], op);
            i++;
        }
        else
        {
            // Inny znak -> błąd (np. litera)
            // Można tutaj ustawić flagę błędu lub przerwać.
            fprintf(stderr, "Nieznany znak w wyrazeniu: %c\n", expression[i]);
            break;
        }
    }
}

/**
 * @brief Konwertuje listę tokenów z formy infiksowej na notacje odwrotną polską (RPN) za pomocą algorytmu Shunting Yard.
 *
 * @param tokens Lista tokenów
 * @param rpnTokens Wyjściowa tablica tokenów w formacie RPN
 * @param rpnCount Liczba tokenów w RPN
 */
static void infixToRPN(const TokenList *tokens, char rpnTokens[100][20], int *rpnCount)
{
    RPNStack opStack;
    opStack.top = -1;
    *rpnCount = 0;

    for(int i = 0; i < tokens->count; i++)
    {
        char *t = (char *)tokens->data[i];

        // Jeśli token to liczba, od razu wrzucamy do wyjścia
        if (isdigit((unsigned char)t[0]))
        {
            strcpy(rpnTokens[(*rpnCount)++], t);
        }
        else if (isOperator(t[0]) && strlen(t) == 1)
        {
            // operator -> obsługa priorytetu
            while (opStack.top != -1)
            {
                char topOp[20];
                strcpy(topOp, opStack.rpnData[opStack.top]);

                if (isOperator(topOp[0]) && 
                    precedence(topOp[0]) >= precedence(t[0]))
                {
                    // Zdejmujemy operator ze stosu do wyjścia
                    popRPN(&opStack, rpnTokens[(*rpnCount)++]);
                }
                else break;
            }
            // Wrzucamy bieżący operator na stos
            pushRPN(&opStack, t);
        }
        else if (t[0] == '(')
        {
            pushRPN(&opStack, t);
        }
        else if (t[0] == ')')
        {
            // Zdejmuj operator ze stosu, aż natrafimy na '('
            while (opStack.top != -1)
            {
                char topOp[20];
                popRPN(&opStack, topOp);
                if (topOp[0] == '(')
                    break;
                strcpy(rpnTokens[(*rpnCount)++], topOp);
            }
        }
    }

    // Zdejmujemy pozostałe operatory ze stosu
    while (opStack.top != -1)
    {
        popRPN(&opStack, rpnTokens[(*rpnCount)++]);
    }
}

/**
 * @brief Funkcja stosowana do obliczania wyniku działania na dwóch liczbach.
 *
 * @param a Pierwsza liczba
 * @param b Druga liczba
 * @param op Operator: '+', '-', '*', '/'
 * @param errorFlag Flaga błędu (np. dzielenie przez zero)
 * @return Wynik operacji, jeśli nie wystąpi błąd
 */
static double applyOperator(double a, double b, char op, int *errorFlag)
{
    switch(op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
            {
                fprintf(stderr, "Blad: Dzielenie przez zero!\n");
                *errorFlag = 1;
                return 0;
            }
            return a / b;
        default:
            fprintf(stderr, "Blad: Nieznany operator %c\n", op);
            *errorFlag = 1;
            return 0;
    }
}

/**
 * @brief Oblicza wartość wyrażenia w notacji infiksowej  ((2+7)*3), zwracając
 *        wynik typu double. W razie błędu ustawia errorFlag na 1.
 *
 * @param expression Wyrażenie tekstowe
 * @param errorFlag Wskaźnik na flagę błędu
 * @return Obliczona wartość wyrażenia (double)
 */
double evaluateExpression(const char *expression, int *errorFlag)
{
    *errorFlag = 0;

    // 1. Tokenizujemy wyrażenie
    TokenList tokenList;
    tokenize(expression, &tokenList);

    // 2. Zamieniamy na RPN
    char rpnTokens[100][20];
    int rpnCount;
    infixToRPN(&tokenList, rpnTokens, &rpnCount);

    // 3. Obliczamy RPN
    double stack[100];
    int top = -1;

    for (int i = 0; i < rpnCount; i++)
    {
        // Jeśli token to liczba, wrzucamy ją na stos
        if (isdigit((unsigned char)rpnTokens[i][0]))
        {
            stack[++top] = atof(rpnTokens[i]);
        }
        else if (isOperator(rpnTokens[i][0]) && strlen(rpnTokens[i]) == 1)
        {
            if (top < 1) 
            {
                // Za mało argumentów na stosie
                fprintf(stderr, "Blad: Niewystarczajaca liczba argumentow do operatora.\n");
                *errorFlag = 1;
                return 0;
            }
            double b = stack[top--];
            double a = stack[top--];
            double result = applyOperator(a, b, rpnTokens[i][0], errorFlag);
            if (*errorFlag)
            {
                return 0; // błąd np. dzielenia przez zero
            }
            stack[++top] = result;
        }
        else
        {
            // Nieznany token (np. litera albo inny błąd)
            fprintf(stderr, "Blad: Nieznany token %s\n", rpnTokens[i]);
            *errorFlag = 1;
            return 0;
        }
    }

    // Na końcu na stosie powinna być dokładnie jedna wartość (wynik)
    if (top != 0)
    {
        fprintf(stderr, "Blad: Niezgodna liczba wartosci na stosie.\n");
        *errorFlag = 1;
        return 0;
    }

    return stack[top];
}
