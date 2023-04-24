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

	va_start(args, format);

	for (written = 0; *format; ++format)
	{
	if (*format == '%')
	{
	++format;
	switch (*format)
		{
		case 'c':
			putchar(va_arg(args, int));
			++written;
			break;
		case 's':
			written += fputs(va_arg(args, const char*), stdout);
			break;
		case '%':
			putchar('%');
			++written;
			break;
		default:
			putchar('%');
			putchar(*format);
			written += 2;
			break;
		}
	}
	else
	{
		putchar(*format);
		++written;
	}
	}
	va_end(args);
	return (written);
}
