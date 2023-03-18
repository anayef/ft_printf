/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:51:26 by anayef            #+#    #+#             */
/*   Updated: 2022/12/11 15:59:33 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_form(va_list args, const char f)
{
	int	p_len;

	p_len = 0;
	if (f == 'c')
		p_len += ft_print_c(va_arg(args, int));
	else if (f == 's')
		p_len += ft_print_s(va_arg(args, char *));
	else if (f == 'i' || f == 'd')
		p_len += ft_print_num(va_arg(args, int));
	else if (f == 'u')
		p_len += ft_print_uint(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		p_len += ft_print_hex((va_arg(args, unsigned int)), f);
	else if (f == 'p')
		p_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (f == '%')
		p_len += ft_print_perc();
	return (p_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		p_len;
	int		i;

	va_start(args, s);
	p_len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			p_len += ft_print_form(args, s[i + 1]);
			i++;
		}
		else
			p_len += ft_print_c(s[i]);
		i++;
	}
	va_end(args);
	return (p_len);
}

/* int main()

{
	char *a = "15654568";
	int b = printf("%p\n", a);
	printf("%d\n", b);
	int c =ft_printf("%p\n", a);
	printf("%d\n", c);
} */
