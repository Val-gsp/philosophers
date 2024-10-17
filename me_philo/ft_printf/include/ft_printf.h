/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:18:37 by vgaspari          #+#    #+#             */
/*   Updated: 2024/01/28 14:30:26 by vgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// src/ft_printf.c

int		ft_printf(const char *FORMAT, ...);
int		ft_sort(va_list args, char s);
int		ft_string(char *str);
void	ft_putchar(char c);

// src/ft_printf_utils.c

void	ft_ptr(unsigned long long ptr, int *length);
void	ft_hexa(unsigned int ptr, int *length, char hexa);
void	ft_putnbr(int num, int *length);
void	ft_putnbr_unsigned(unsigned int num, int *length);

//
// BONUS
//

#endif
