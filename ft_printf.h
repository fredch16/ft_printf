/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:42:39 by fcharbon          #+#    #+#             */
/*   Updated: 2023/12/01 17:22:03 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *input, ...);
//int ft_printptr(unsigned long value, int asc);
int ft_format(const char *a, va_list ap);
int ft_printnbr_base(unsigned long n, int base, char *symbols);
int	ft_printstr(char *s);
int	ft_printchar(char c);

#endif
