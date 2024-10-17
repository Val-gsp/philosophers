/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:09:02 by vgaspari          #+#    #+#             */
/*   Updated: 2024/01/25 16:09:07 by vgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *FORMAT, ...)
{
	int		length;
	int		i;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, FORMAT);
	while (FORMAT[i])
	{
		if (FORMAT[i] == '%')
		{
			length += ft_sort(args, FORMAT[i + 1]);
			i++;
		}
		else
		{
			length += write(1, &FORMAT[i], 1);
		}
		i++;
	}
	return (length);
}

int	ft_sort(va_list args, char s)
{
	int		length;
	char	str;

	length = 0;
	if (s == 'c')
	{
		str = va_arg(args, int);
		return (write(1, &str, 1));
	}
	else if (s == 's')
		return (ft_string(va_arg(args, char *)));
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), &length);
	else if (s == 'X')
		ft_hexa(va_arg(args, unsigned int), &length, 'X');
	else if (s == 'x')
		ft_hexa(va_arg(args, unsigned int), &length, 'x');
	else if (s == 'p')
		ft_ptr(va_arg(args, unsigned long long), &length);
	else if (s == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), &length);
	else if (s == '%')
		return (write(1, "%", 1));
	return (length);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
int	main(void)
{
	int ret;

	ret = ft_printf(" %s %% %% ", "nik");
	printf("\nValeur mon printf : %d\n", ret);
	ret = printf(" %s %% %% ", "nik");
	printf("\nValeur printf basique : %d\n", ret);
	return (0);
}*/
