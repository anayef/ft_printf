/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:51:15 by anayef            #+#    #+#             */
/*   Updated: 2022/12/11 20:45:03 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		len = 6;
	}
	else
	{
		while (s[len])
		{
			write(1, &s[len], 1);
			len++;
		}
	}
	return (len);
}
