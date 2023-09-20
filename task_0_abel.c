#include "main.h"


/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int index = 0;
	va_list array;

	if (format == NULL)
		return (0);
	va_start(array, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			index++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				index++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(array, int);

				write(1, &c, 1);
				index++;
			}
			else if (*format == 's')
				{
					char *ptr = va_arg(array, char*);
					int len = strlen(ptr);

					write(1, ptr, len);
					index += len;
				}
		}
	format++;
	}
	va_end(array);
	return (index);
}
