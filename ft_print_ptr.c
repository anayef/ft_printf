/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:51:07 by anayef            #+#    #+#             */
/*   Updated: 2022/12/11 15:59:19 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(size_t n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_put_ptr(size_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0');
		else
			ft_putchar_fd(n - 10 + 'a');
	}
}

int	ft_print_ptr(size_t n)
{
	int	p_len;

	p_len = 0;
	p_len += write(1, "0x", 2);
	if (n == 0)
		p_len += write(1, "0", 1);
	else
	{
		ft_put_ptr(n);
		p_len += ft_ptr_len(n);
	}
	return (p_len);
}
