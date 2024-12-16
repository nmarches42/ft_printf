/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmarches <nmarches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:02:41 by nmarches          #+#    #+#             */
/*   Updated: 2024/12/03 12:42:29 by nmarches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	printf_numbers(int count, const char *format, va_list args)
{
	int		n;

	count = 0;
	if (*format == 'd' || *format == 'i')
	{
		n = va_arg(args, int);
		count += ft_putnbr(n);
	}
	else if (*format == 'x')
	{
		n = va_arg(args, unsigned int);
		count += ft_putnbr_hex(n);
	}
	else if (*format == 'X')
	{
		n = va_arg(args, unsigned int);
		count += ft_putnbr_hex_upper(n);
	}
	else if (*format == 'u')
	{
		n = va_arg(args, unsigned);
		count += ft_unsputnbr(n);
	}
	return (count);
}

int	str_ptr(int count, const char *format, va_list args)
{
	char	*s;
	char	c;
	void	*p;

	count = 0;
	if (*format == 's')
	{
		s = va_arg(args, char *);
		count += ft_putstr(s);
	}
	else if (*format == 'p')
	{
		p = va_arg(args, void *);
		count += ft_print_pointer(p);
	}
	else if (*format == 'c')
	{
		c = va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (*format == '%')
	{
		count += write(1, "%", 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i' || *format == 'X'
				|| *format == 'x' || *format == 'u')
				count += printf_numbers(count, format, args);
			else if (*format == 's' || *format == 'p' || *format == 'c'
				|| *format == '%')
				count += str_ptr(count, format, args);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}

/*  	int main() {

    int count = ft_printf(" %u \n", 0);  // Stampa l'indirizzo di memoria
    int count2 = printf(" %u \n", 0);

	printf("%d\n%d\n", count, count2);
	//printf("%d\n", count2);
    //ft_printf(" %c %c %c\n", '0', 0, '1');
	//printf(" %c %c %c\n", '0', 0, '1');
    return (0);
}  */
