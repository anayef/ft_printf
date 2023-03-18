# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anayef <anayef@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 10:52:56 by anayef            #+#    #+#              #
#    Updated: 2022/12/11 12:02:11 by anayef           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_itoa.c \
		  ft_print_hex.c \
		  ft_print_num.c \
		  ft_print_perc.c \
		  ft_print_ptr.c \
		  ft_print_s.c \
		  ft_print_uint.c \
		  ft_printf.c \
		  ft_putchar.c \


CFLAGS		= -Wall -Werror -Wextra

OBJS		= $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
