#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void ft_putstr(const char *str,int *count)
{
    if(!str)
        str = "(null)";
    while (*str)
    {
        write(1, str, 1);
        str++;
        (*count)++;
    }
}

void ft_putnbr(int n, int *count)
{
    char c;
    if(n == -2147483648)
    {
        ft_putstr("-2147483648",count);
        return;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        (*count)++;
        n = -1 * n;
    }
    if (n >= 10)
        ft_putnbr(n / 10, count);
    c = (n % 10 ) + '0';
    write(1, &c , 1);
    (*count)++;
}

void ft_hexa(unsigned int hex, int *count)
{
    char hex_digits[] = "0123456789abcdef";
    if (hex >= 16)
        ft_hexa(hex / 16 , count);
    write(1, &hex_digits[hex % 16], 1);
    (*count)++;
}

int ft_printf(const char *formet, ... )
{
    va_list args;
    int count = 0;

    va_start(args, formet);
    while (*formet)
    {
        if(*formet == '%' && *(formet + 1))
        {
            formet++;
            if (*formet == 's')
            ft_putstr(va_arg(args, const char *), &count);
            else if (*formet == 'd')
            ft_putnbr(va_arg(args,int), &count);
            else if (*formet == 'x')
            ft_hexa(va_arg(args, unsigned int), &count);
            else
            {
                write(1,formet,1);
                count++;
            }
        }
        else
        {
            write(1, formet, 1);
            count++;
        }
        formet++;
    }
    va_end(args);
    return(count);
}

int main(void)
{
    char *str = "heehee";
    int i = 42;
    ft_printf("The string is %s.\n",str);
    ft_printf("The number is %d.\n",i);
    ft_printf("The hex for 42 is %x.\n",i);
    ft_printf("%s\n", "heehee");
    ft_printf("Magic %s is %d", "number", 42);
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    return 0;
}