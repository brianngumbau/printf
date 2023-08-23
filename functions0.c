#include "main.h"
/**
 * print_char - Prints a character
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_char(va_list types, char buffer[],
int flags, int width, int  precision, int size)
{
char c;
c = va_arg(types, int);
return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, i;
char *str;
str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "   ";
}
while (str[length] != '\0')
length++;
if (precision >= 0 && precision < length)
length = precision;
if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, &str[0], length);
return (width);
}
}
return (write(1, str, length));
}
/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/**
 * print_int - Print integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specification
 * Return: Number of characters printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);
if (n == 0)
buffer[i--] = '0';
else
{
if (n < 0)
{
num = (unsigned long int)(-n);
is_negative = 1;
}
else
{
num = (unsigned long int)n;
if (flags & F_PLUS)
buffer[i--] = '+';
else if (flags & F_SPACE)
buffer[i--] = ' ';
}
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
if (is_negative)
buffer[i--] = '-';
}
return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/**
 * print_binary - Prints an unsigned number in binary
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int n = va_arg(types, unsigned int);
unsigned int a[32];
int i, count = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
for (i = 0; i < 32; i++)
{
a[i] = n % 2;
n /= 2;
}
for (i = 31; i >= 0; i--)
{
char z;
z = '0' + a[i];
write(1, &z, 1);
count++;
}
return (count);
}
