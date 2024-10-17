/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:09:18 by vgaspari          #+#    #+#             */
/*   Updated: 2024/01/28 14:22:06 by vgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_ptr(unsigned long long ptr, int *length)
{
	char	str[25];
	int		i;
	char	*b_character;

	b_character = "0123456789abcdef";
	i = 0;
	if (ptr == 0)
		(*length) += write(1, "(nil)", 5);
	else
		(*length) += write(1, "0x", 2);
	while (ptr != 0)
	{
		str[i] = b_character[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		(*length) += write(1, &str[i], 1);
}

void	ft_hexa(unsigned int ptr, int *length, char hexa)
{
	char	str[25];
	int		i;
	char	*b_character;

	i = 0;
	if (ptr == 0)
		(*length) += write(1, "0", 1);
	if (hexa == 'x')
		b_character = "0123456789abcdef";
	else if (hexa == 'X')
		b_character = "0123456789ABCDEF";
	while (ptr)
	{
		str[i] = b_character[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		(*length) += write(1, &str[i], 1);
}

void	ft_putnbr(int num, int *length)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-');
		(*length) += 1;
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10, length);
		ft_putnbr(num % 10, length);
	}
	else
	{
		ft_putchar(num + '0');
		(*length) += 1;
	}
}

void	ft_putnbr_unsigned(unsigned int num, int *length)
{
	if (num >= 10)
	{
		ft_putnbr(num / 10, length);
		ft_putnbr(num % 10, length);
	}
	else
	{
		ft_putchar(num + '0');
		(*length) += 1;
	}
}
