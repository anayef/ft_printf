/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:51:20 by anayef            #+#    #+#             */
/*   Updated: 2022/12/08 21:51:21 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uint_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uinttoa(unsigned int n)
{
	int		len;
	char	*s;

	len = ft_uint_len(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = '\0';
	len --;
	while (n > 0)
	{
		s[len] = (n % 10) + '0';
		n = n / 10;
		len --;
	}
	return (s);
}

int	ft_print_uint(unsigned int n)
{
	int		p_len;
	char	*s;

	p_len = 0;
	if (n == 0)
		p_len += write(1, "0", 1);
	else
	{
		s = ft_uinttoa(n);
		p_len += ft_print_s(s);
		free (s);
	}
	return (p_len);
}
