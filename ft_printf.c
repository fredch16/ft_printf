/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:52:03 by fcharbon          #+#    #+#             */
/*   Updated: 2023/12/07 13:45:09 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	if (c < 0 || c > 255)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_format(const	char *str, va_list ap)
{
	size_t	i;

	i = 0;
	if (*str == 'c')
		i += ft_printchar(va_arg(ap, int));
	if (*str == 's')
		i += ft_printstr(va_arg(ap, char *));
	if (*str == 'p')
		i += ft_printptr(va_arg(ap, void *));
	if (*str == 'd' || *str == 'i')
		i += ft_printnbr_base(va_arg(ap, int), 10, "0123456789");
	if (*str == 'x')
		i += ft_printnbr_base_u(va_arg(ap, unsigned int),
				16, "0123456789abcdef");
	if (*str == 'X')
		i += ft_printnbr_base_u(va_arg(ap, unsigned int), 16,
				"0123456789ABCDEF");
	if (*str == '%')
		i += ft_printchar('%');
	return (i);
	// consider the %% case
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	size_t		i;

	va_start(args, input);
	i = 0;
	while (*input)
	{
		if (*input == '%')
		{
			if (ft_strchr("cspdiuxX%", *(input + 1))) //add % case
			{
				i += ft_format((input + 1), args);
				input += 2;
			}
		}
		if (*input == '\0')
			return (i);
		i += ft_printchar(*input);
		input++;
	}
	va_end(args);
	return (i);
}

int	main()
{
	int	value = 10;
	int	*pointer = &value;

	//printf("wowcheck%d", 15);
	//ft_printf("wowcheck%q", 15);
	//return (printf("%%\n"));
	return (ft_printf("%%\n"));
}
