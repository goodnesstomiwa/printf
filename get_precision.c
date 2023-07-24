#include "main.h"

/**
* get_precision - Calculates the precision for printing
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
* @list: list of arguments.
*
* Return: Precision.
*/
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;
if (format[curr_i] != '.')
return (precision);
precision = 0;
curr_i++;
if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
if (precision < 0)
precision = -1;
}
else
{
while (format[curr_i] != '\0')
{
if (is_digit(format[curr_i]))
{
if (precision == -1)
precision = 0;
precision *= 10;
precision += format[curr_i] - '0';
curr_i++;
}
else
break;
}
}
*i = curr_i - 1;
return (precision);
}
