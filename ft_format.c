/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:53:48 by fcharbon          #+#    #+#             */
/*   Updated: 2023/12/01 17:20:39 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *a, va_list ap)
{
	size_t	i;

	i = 0;
	if (*a == 'c')
		i += ft_printchar(va_arg(ap, int));
	if (*a == 's')
		i += ft_printstr(va_arg(ap, char *));
//	if (*a == 'p')
//		i += ft_printptr((unsigned long)arg);
	if (*a == 'd' || *a == 'i')
		i += ft_printnbr_base(va_arg(ap, unsigned int), 10, "0123456789");
	if (*a == 'x')
		i += ft_printnbr_base(va_arg(ap, unsigned int), 16, "0123456789abcdef");
	if (*a == 'X')
		i += ft_printnbr_base(va_arg(ap, unsigned int), 16, "0123456789ABCDEF");
//	if (*a == '%') WE MIGHT NOT NEED TO INCLUDE THIS % CASE BECAUSE I CAN HAVE IT IN THE PRINTF
//		i += ft_printchar('%');
	return (i);
}
