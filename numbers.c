/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmarches <nmarches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:04:30 by nmarches          #+#    #+#             */
/*   Updated: 2024/12/03 12:39:13 by nmarches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_unsputnbr(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == 0)
	{
		count += write(1, "0", 1);
		return (1);
	}
	if (n >= 10)
	{
		count += ft_unsputnbr(n / 10);
	}
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr_hex(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_putnbr_hex(n / 16);
	}
	if (n % 16 < 10)
		c = (n % 16) + '0';
	else
		c = (n % 16 - 10) + 'a';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr_hex_upper(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_putnbr_hex_upper(n / 16);
	}
	if (n % 16 < 10)
		c = (n % 16) + '0';
	else
		c = (n % 16 - 10) + 'A';
	write(1, &c, 1);
	count++;
	return (count);
}
