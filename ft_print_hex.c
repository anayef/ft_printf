/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:50:44 by anayef            #+#    #+#             */
/*   Updated: 2022/12/11 14:20:51 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(unsigned int n, const char f)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, f);
		ft_put_hex(n % 16, f);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0');
		else
		{
			if (f == 'x')
				ft_putchar_fd(n - 10 + 'a');
			if (f == 'X')
				ft_putchar_fd(n - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int n, const char f)
{
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
		ft_put_hex(n, f);
	return (ft_hex_len(n));
}
