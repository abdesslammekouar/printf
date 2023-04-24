#include "main.h"

/**
 * _printf - produces output according to a format
 * @format : string to print to stdout
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)

{
	int written;
	va_list args;

	if (format == NULL)
	return (-1);

	va_start(args, format);

	for (written = 0; *format; ++format)
	{
	if (*format == '%')
	{
	format++;
	switch (*format)
		{
		case 'c':
			written += putchar(va_arg(args, int));
			break;
		case 's':
			written += fputs(va_arg(args, const char*), stdout);
			break;
		case '%':
			written +=  putchar('%');
			break;
		default:
			written +=  putchar('%');
			written +=  putchar(*format);
			break;
		}
	}
	else
	{
		written += putchar(*format);
	}
	written++;
	}
	va_end(args);
	return (written);
}
