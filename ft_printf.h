/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmarches <nmarches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:51:48 by gnicolo           #+#    #+#             */
/*   Updated: 2024/12/02 19:24:46 by nmarches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_putstr(char *s);
int		ft_unsputnbr(unsigned int n);
int		ft_print_pointer(void *ptr);
int		ft_putnbr(int n);
int		printf_numbers(int count, const char *format, va_list args);
int		ft_print_pointer(void *ptr);
int		ft_printf(const char *format, ...);
int		ft_putnbr_hex(unsigned int n);
int		ft_putnbr_hex_upper(unsigned int n);
int		ft_puthex(unsigned long n);
int		str_ptr(int count, const char *format, va_list args);
void	ft_init_hex_digits(char hex_digits[16]);

#endif
