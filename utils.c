#include "main.h"
/**
 * is_printable - evaluate if a char is printable
 * @c: char to be evaluated
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * append_hexa_code - append ascii in hexadecimal code
 * @buffer: array of chars
 * @i: index to start appending
 * @ascii_code: ascii code
 * Return: 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "012356789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}
/**
 * is_digit - verifies if a char is digit
 * @c: char to be evaluated
 * Return: 1 if c is digit, otherwise 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * convert_size_number - casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the size to be casted
 * Return: casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
