#include "main.h"

/**
* is_digit - Checks if a character is a digit (0-9).
* @c: The character to check.
*
* Return: 1 if the character is a digit, 0 otherwise.
*/
static int is_digit(char c)
{
return (c >= '0' && c <= '9');
}

/**
* get_precision - Calculates the precision for printing.
* @format: Formatted string in which to print the arguments.
* @i: Pointer to the index in the format string.
* @list: List of arguments.
*
* Return: Precision.
*/
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;

if (format[curr_i] != '.')
return (precision);

curr_i++;

if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
return ((precision < 0) ? 0 : precision);
}

if (!is_digit(format[curr_i]))
return (precision);

precision = 0;
while (is_digit(format[curr_i]))
{
precision = precision * 10 + (format[curr_i] - '0');
curr_i++;
}

if (format[curr_i] == '*')
{
curr_i++;
int dynamic_precision = va_arg(list, int);
return ((dynamic_precision < 0) ? 0 : precision);
}

*i = curr_i - 1;
return (precision);
}

