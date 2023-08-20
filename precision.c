#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
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
while (format[curr_i] != '\0')
{
switch (format[curr_i])
{
case '*':
curr_i++;
precision = va_arg(list, int);
*i = curr_i - 1;
return (precision);
case '0': case '1': case '2': case '3': case '4':
case '5': case '6': case '7': case '8': case '9':
precision = precision * 10 + (format[curr_i] - '0');
break;
default:
*i = curr_i - 1;
return (precision);
}
curr_i++;
}
*i = curr_i - 1;
return (precision);
}
