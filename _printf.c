#include <stdarg.h>
#include <unistd.h>

/**
* print_number - Prints an integer to stdout
* @n: The integer to print
* Return: Number of characters printed
*/
int print_number(int n)
{
char buf[12];
int i = 0, count = 0;
unsigned int num;

if (n < 0)
{
write(1, "-", 1), count++;
num = -n;
}
else
num = n;
do {
buf[i++] = (num % 10) + '0';
num /= 10;
} while (num);
while (i--)
write(1, &buf[i], 1), count++;
return (count);
}

/**
* _printf - Produces output according to a format
* @format: Format string
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
char *str;

if (!format)
return (-1);
va_start(args, format);
while (format[i])
{
if (format[i] == '%')
{
if (!format[i + 1])
return (-1);
i++;
if (format[i] == 'c')
{
char c = va_arg(args, int);
write(1, &c, 1), count++;
}
else if (format[i] == 's')
{
str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
write(1, str++, 1), count++;
}
else if (format[i] == '%')
write(1, "%", 1), count++;
else if (format[i] == 'd' || format[i] == 'i')
count += print_number(va_arg(args, int));
else
write(1, "%", 1), write(1, &format[i], 1), count += 2;
}
else
write(1, &format[i], 1), count++;
i++;
}
va_end(args);
return (count);
}
