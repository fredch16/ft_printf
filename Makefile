# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 13:34:33 by fcharbon          #+#    #+#              #
#    Updated: 2023/12/07 14:17:05 by fcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CCF = cc -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -f
SRCS = ft_printf.c \
	   ft_printchar.c \
	   ft_printnbr_base.c \
	   ft_printnbr_base_u.c \
	   ft_printstr.c \
	   ft_printptr.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CCF) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS)

fclean: 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
