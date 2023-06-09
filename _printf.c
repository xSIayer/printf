#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int _printf(const char *format, ...)
{
	int i, x, count = 0;
	int l;
	unsigned int o;
	char c, *s;
	int len;
	va_list args;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
	    return (-1);

	}

	for (i = 0; format[i] != '\0'; i++)
	{
		
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case 'c':
					c = va_arg(args, int);
					printchar(c);
					count++;
					break;

				case 's':
					s = va_arg(args, char*);
					len = strllen(s);
					printstring(s, len);
					count += len;
					break;

				case 'i':
				case 'd':
					x = va_arg(args, int);
					print_intt(x);
					if (x < 0)
						count++;
					for (l = 0; x != 0; l++)
						x /= 10;
					count += l;
					break;
				case 'b':
					o = va_arg(args, unsigned int);
				    	o = printbinary(o);
				    	count = count + o;
				    	break;
				case '%':
					printchar('%');
					count++;
					break;
				default:
					printchar(format[--i]);
					printchar(format[++i]);
					count = count + 2;

			
			}
			
		}
		else
		{
			printchar(format[i]);
			count++;
		}
	}

	va_end(args);
	return (count);
}
