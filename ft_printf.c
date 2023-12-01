/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:52:03 by fcharbon          #+#    #+#             */
/*   Updated: 2023/12/01 14:50:31 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <string.h>

int	ft_printf(const char *input, ...)
{
	va_list		args;
	size_t		i;
	const char *original_input;

	va_start(args, input);
	original_input = input;
	i = 0;

	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (strchr("cspdiuxX%", *input)) //WARNING HIGHLY ILLEGAL STRCHR
				i += ft_format(input, va_arg(args, void *));
			else
				i += ft_printstr((char *)original_input);
		}
		input++;
	}
	va_end(args);
	return (i);
}

int	main()
{
	//printf("wowcheck%d", 15);
	ft_printf("wowcheck%q", 15);
}
