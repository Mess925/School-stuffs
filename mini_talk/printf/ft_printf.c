/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:50:50 by hthant            #+#    #+#             */
/*   Updated: 2024/06/24 19:27:14 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int			ft_printf(const char *str, ...);

static int	ft_print_chars(va_list args, char identifier)
{
	if (identifier == 'd')
		return (ft_put_number(va_arg(args, int)));
	else if (identifier == 'i')
		return (ft_put_number(va_arg(args, int)));
	else if (identifier == 'c')
		return (ft_put_char(va_arg(args, int)));
	else if (identifier == 's')
		return (ft_put_str(va_arg(args, char *)));
	else if (identifier == 'x')
		return (ft_put_hexa(va_arg(args, unsigned int), 'x'));
	else if (identifier == 'X')
		return (ft_put_hexa(va_arg(args, unsigned int), 'X'));
	else if (identifier == 'u')
		return (ft_put_unumber(va_arg(args, unsigned int)));
	else if (identifier == '%')
		return (ft_put_char('%'));
	else if (identifier == 'p')
		return (ft_put_ptr(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		printed_char;
	va_list	args;

	va_start(args, str);
	printed_char = 0;
	while (*str)
	{
		if ((*str == '%') && *(str + 1))
			printed_char += ft_print_chars(args, *(++str));
		else
			printed_char += ft_put_char(*str);
		str++;
	}
	va_end(args);
	return (printed_char);
}
