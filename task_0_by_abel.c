#include "main.h"


/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
  */
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	int index = 0;
	va_list array;
	char *str, c;

	va_start(array, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			switch (*format)
			{
				case '%':
					c = '%';
					write(1, &c, 1);
					index++;
					break;
				case 'c':
					  c = (char)va_arg(array, int);
					  write(1, &c, 1);
					  index++;
						break;
				case 's':
					  str = va_arg(array, char*);
					  write(1, str, strlen(str));
					  index += strlen(str);
						break;
			}
		}
	else
	{
		write(1, format, 1);
		index++;
	}
	format++;
	}
	va_end(array);
	return (index);
}
