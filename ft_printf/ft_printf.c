/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:21:57 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/04 16:26:30 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int ft_putstr(char *s)
{
    int ret = 0;
    while (*s)
        ret += ft_putchar(*s++);
    return ret;
}

#define hex "0123456789abcdef"
int ft_putnbr(long long n, int base)
{
    int ret = 0;

    if (n < 0)
    {
        ret += write(1, "-", 1);
        n *= -1;
    }
    if (n >= base)
        ret += ft_putnbr(n/base, base);
    ret += ft_putchar(hex[n%base]);
    return ret;
}

int print(char *f, va_list ap)
{
    int ret = 0;
    char c;

    while (*f)
    {
        c = *f++;
        if (c != '%')
            ret += ft_putchar(c);
        else
        {
            c = *f++;
            if (c == 'c')
                ret += ft_putchar((char)va_arg(ap, int));
            if (c == 's')
                ret += ft_putstr(va_arg(ap, char *));
            if (c == 'd')
                ret += ft_putnbr((long long)va_arg(ap, int), 10);
            if (c == 'x')
                ret += ft_putnbr((long long)va_arg(ap, unsigned int), 16);
        }
    }
    return ret;
}

int ft_printf(char *f, ...)
{
    va_list ap;
    int ret = 0;

    va_start(ap, f);
    ret += print(f, ap);
    va_end(ap);
    return ret;
}


#include <limits.h>
#include <stdio.h>
int main()
{
    int f, s;
    f = ft_printf("%s %c %d %d %x\n", "hello", 'X', INT_MAX, INT_MIN, UINT_MAX);
    s =    printf("%s %c %d %d %x\n", "hello", 'X', INT_MAX, INT_MIN, UINT_MAX);
    printf("%d | %d\n", f, s);
}
