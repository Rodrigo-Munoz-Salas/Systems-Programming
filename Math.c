#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define NOT_2_CLAS 1
#define DIV_BY_ZERO 1
#define SUM_OVERFLOW 2
#define error(code, message) do{ fprintf(stderr, "%s\n", message); return code;} while (0);

int arithmetic(int op1, int op2, int *sum, int *diff,
               int *prod, int *quo)
{
    if ((op1 ^ op2) >= 0 && (op1 ^ (op1 + op2)) < 0)
        return SUM_OVERFLOW; // error #2 occurred (sum overflow!)
    *sum = op1 + op2;
    *diff = op1 - op2;
    *prod = op1 * op2;
    if (op2 == 0)
        return DIV_BY_ZERO; // error #1 occurred
    *quo = op1 / op2;
    return 0; // no error...
}
int check_integer(char *str)
{
    if (strlen(str) == 0)
        return FALSE;
    if (str[0] == '-' || str[0] == '+') // explicit signal
        str++;                          // skip it
    while (*str)
        if (!isdigit(*(str++)))
            return FALSE;
    return TRUE;
}
// write a program that receives two integers
// as command-line arguments and prints out the
// sum, diff, prod, and quo of the two numbers...
int main(int argc, char *argv[])
{
    if (argc != 3)
        error(NOT_2_CLAS, "math: Fatal Error! Two command-line arguments are required!");
    if (!check_integer(argv[1]))
        error(2, "math: Fatal Error! first command-line argument must be an integer");
    if(!check_integer(argv[2]))
        error(3, "math: Fatal Error! second command-line argument must be an integer");
    int sum, diff, prod, quo;
    int result = arithmetic(atoi(argv[1]), atoi(argv[2]), &sum, &diff, &prod,
                            &quo);
    if (result == 0) // no error
        printf("sum = %d, diff = %d, prod = %d, quo = %d\n", sum, diff, prod,
               quo);
    else if (result == DIV_BY_ZERO)
    {
        printf("sum = %d, diff = %d, prod = %d, quo = not-defined\n", sum,
               diff, prod);
    }
    else if (result == SUM_OVERFLOW)
        error(4, "sum = Overflow!");
    return 0;
}