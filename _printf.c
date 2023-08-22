#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - printf function
 * @format: format
 * by brian and michelle
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int c, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (c = 0; format && format[c] != '\0'; c++)
	{
		if (format[c] != '%')
		{
			buffer[buff_ind++] = format[c];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[c], 1); */
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &c);
			width = get_width(format, &c, list);
			size = get_size(format, &c);
			++c;
			printed = handle_print(format, &c, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
/**
 * print_buffer - prints contents of buffer
 * @buffer: array of chars
 * @buff_ind: index to add next char
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
