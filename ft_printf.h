/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:51:32 by anayef            #+#    #+#             */
/*   Updated: 2022/12/11 15:57:02 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_print_c(int c);
int		ft_print_form(va_list args, const char f);
int		ft_print_num(int n);
int		ft_hex_len(unsigned int n);
void	ft_put_hex(unsigned int n, const char f);
int		ft_print_hex(unsigned int n, const char f);
int		ft_print_perc(void);
int		ft_ptr_len(size_t n);
void	ft_put_ptr(size_t n);
int		ft_print_ptr(size_t n);
int		ft_print_s(char *s);
int		ft_uint_len(unsigned int n);
char	*ft_uinttoa(unsigned int n);
int		ft_print_uint(unsigned int n);
char	*ft_itoa(int n);
void	ft_putchar_fd(int n);

#endif
