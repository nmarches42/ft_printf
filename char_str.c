/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmarches <nmarches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:07:13 by nmarches          #+#    #+#             */
/*   Updated: 2024/12/03 12:11:23 by nmarches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	unsigned int		i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long n)
{
	char	hex_digits[16];
	char	buffer[16];
	int		i;
	int		count;

	ft_init_hex_digits(hex_digits);
	count = 0;
	i = 0;
	while (n > 0)
	{
		buffer[i] = hex_digits[n % 16];
		n = n / 16;
		i++;
	}
	while (i-- > 0)
		count += write(1, &buffer[i], 1);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;
	int				count;

	count = 0;
	addr = (unsigned long)ptr;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		count = 5;
		return (count);
	}
	write(1, "0x", 2);
	count = 2;
	count += ft_puthex(addr);
	return (count);
}

void	ft_init_hex_digits(char hex_digits[16])
{
	hex_digits[0] = '0';
	hex_digits[1] = '1';
	hex_digits[2] = '2';
	hex_digits[3] = '3';
	hex_digits[4] = '4';
	hex_digits[5] = '5';
	hex_digits[6] = '6';
	hex_digits[7] = '7';
	hex_digits[8] = '8';
	hex_digits[9] = '9';
	hex_digits[10] = 'a';
	hex_digits[11] = 'b';
	hex_digits[12] = 'c';
	hex_digits[13] = 'd';
	hex_digits[14] = 'e';
	hex_digits[15] = 'f';
}
